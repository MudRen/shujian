// dizi6.c �⿲ ������Ʒ
// Modify By River@SJ
// Modified by snowman@SJ 22/11/2000
// ����flood

#include <ansi.h>
inherit NPC;
int give_tools();
int give_gaotou();
void create()
{
	set_name("�⿲",({ "wu kan", "wu","kan" }) );
	set("title","�������������");
	set("gender", "����" );
	set("age", 25);
	set("long"," ��������ɽ�������ӣ�����ǿ�ɣ���ݵ���Ʒ�����������ܡ�\n");
	set("combat_exp", 4000);
	set("attitude", "friendly");

	set_skill("force", 40);
	set_skill("strike", 40);
	set_skill("sword", 40);
	set_skill("shenzhao-jing",40);
	map_skill("force", "shenzhao-jing");

	set("inquiry", ([
		"����" : (: give_tools :),
		"��ͷ" : (: give_gaotou :),
		"tools" : (: give_tools :),
	]) );
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();
	if(ob->query_temp("mark/����")){
		command("say ���Ѿ����˹����ˣ���û���أ���ô�������ˣ�");
		return 1;
	}
	if(ob->query_temp("mark/����")){
		command("say �㻹û�������»�ɣ�����Ҫʲô���ߡ�");
		return 1;
	}
	if(!ob->query_temp("job_name")){
		command("say ��û����ʦ�����ɣ�����Ҫʲô���ߡ�");
		return 1;
	}
	switch( ob->query_temp("job_name") ){
		case "����":	tools = new(__DIR__"obj/chutou"); break;
		case "��Ȳ˵�":tools = new(__DIR__"obj/piao"); break;
		case "��ľͷ":	tools = new(__DIR__"obj/juzi"); break;
		case "����":	tools = new(__DIR__"obj/chaidao"); break;
		case "��ˮ":	tools = new(__DIR__"obj/shuitong"); break;
		case "��ɨ��":tools = new(__DIR__"obj/saozhou"); break;
		default:  return notify_fail(CYN+me->name()+"˵�����������ʦ�����ʲô�������û���ֹ��ߡ���\n"NOR);
	}
	tools->set_temp("mark/name", ob->query("id"));
	tools->move(ob);
	ob->set_temp("tools_name", tools->query("id"));
	tell_object(ob, CYN+me->name()+"˵��������Ȼ���Ѿ����˻�Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ���\n"NOR);
	message_vision("$N����$nһ"+tools->query("unit") + tools->query("name")+"��\n", me, ob);
	ob->set_temp("mark/����",1);
	return 1;
}
int give_gaotou()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();
	if(present("gao tou",ob))
		return notify_fail("���Ѿ����˰���");
	tools = new(__DIR__"obj/chutou");
	tools->set("no_drop",1);
	tools->set("no_get",1);
	tools->set("no_give",1);
	tools->set_name("��ͷ", ({ "gao tou", "tou", "staff" }));
	tools->move(ob);
	tell_object(ob, CYN+me->name()+"˵�������Ҿ͸�����ѹ��ߣ�С�ı��ܣ���Ū���ˡ���\n"NOR);
	message_vision("$N����$nһ"+tools->query("unit") + tools->query("name")+"��\n", me, ob);
	return 1;
}

int accept_object(object me, object obj)
{
       	object ob;
       	me = this_object();
       	ob = this_player();
       	if(!ob->query_temp("mark/����")){
           	command("shake");
           	tell_object(ob, CYN+me->name()+"˵��������û�з���������������ǲ��ǻ����ˣ���\n"NOR);
           	return 0;
       	}
       	if(!(ob->query_temp("mark/����"))){
           	tell_object(ob, CYN+me->name()+"˵�������㻹û��ɹ�������ô�ͻ����������ˣ�͵���𣿡�\n"NOR);
           	return 0;
       	}
       	if( obj->query_temp("mark/name") != ob->query("id")){
           	command("? "+ob->query("id") );
           	tell_object(ob, CYN+me->name()+"˵�������Ҹ���ĺ��������������ɣ���\n"NOR);
           	return 0;
       	}
       	if((obj->query("id")!= "ju zi")
        &&(obj->query("id")!="chu tou")
        &&(obj->query("id")!="piao")
        &&(obj->query("id")!="sao zhou")
        &&(obj->query("id") != "shui tong")
        &&(obj->query("id") != "chai dao")){
           	tell_object(ob, CYN+me->name()+"˵�������㻹�����˰ɣ��Ҵ�û�з����������ߡ���\n"NOR);
           	return 0;
       	}
       	else {
           	command("nod");
           	tell_object(ob, CYN+me->name()+"˵���������ͣ����ͣ��´��ٺúøɰ�����\n"NOR);
           	ob->set_temp("mark/����",1);
           	call_out("destroying", 1, me, obj);
           	return 1;
       }
}

void destroying(object me, object obj)
{
       destruct(obj);
       return;
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if( ob->query_temp("mark/����")){
		command("smile "+ob->query("id"));
		tell_object(ob, CYN+this_object()->name()+"˵���������������ˣ����Ի����� "HIY HBCYN"give wu "+ ob->query_temp("tools_name")+CYN" �����ˣ���\n"NOR);
		return;
	}
	if( ob->query_temp("mark/����")) return 0;
	if( ob->query_temp("job_name")){
		command("bow "+ob->query("id"));
		tell_object(ob, CYN+this_object()->name()+"˵��������λ"+RANK_D->query_respect(ob)+ "���������칤�� "HIY HBCYN"ask wu about ����"CYN" �ɡ���\n"NOR);
	}
}
