// ½����

inherit F_MASTER;
inherit NPC;
#define	SEAWAR_D	"/d/sld/seawar/seaward"
#include "ansi.h"

int ask_lingpai();
int ask_yaopu();
int ask_yaolu();
int ask_yaozhong();
int ask_makeyao();

string ask_seawar();

void create()
{
	set_name("½����", ({ "lu gaoxuan","lu" }));
	set("long", "����ʮ������ͣ���ʿ��磬����Ͱ����ף����������̵Ļ�����\n");
	set("gender", "����");
	set("title", "�����̻���");	
	set("age", 42);       

	set("str", 20);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	set("per", 22);
	
	set("no_ansuan",1);
	set("no_bark",1);
	set("no_quest",1);

	set("combat_exp", 600000);
	set("shen", -5000);
	set("attitude", "peaceful");
	set("max_qi",2500);
	set("max_jing",2500);
	set("neili",2000);
	set("max_neili",2000);
	set("jingli",2000);
	set("eff_jingli",2000);
	set("jiali",50);
	set("score", 2000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry",100);
	set_skill("strike",100);
	set_skill("throwing",100);
	set_skill("literate",100);
	set_skill("poison",100);
	set_skill("shenlong-yaoli",100);
	set_skill("huagu-mianzhang", 100);
	set_skill("youlong-shenfa",100);
	set_skill("dulong-dafa",100);
      
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry","huagu-mianzhang");
	map_skill("poison","shenlong-yaoli");
      
	create_family("������",2, "����");
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"½����˵�������ҩ���Ƶò��࣬����\n",NOR
		CYN"½����˵������������ǿ��׳��������ɲ�˰�æ��˭�����¡�\n"NOR,
		CYN"½����˵������ɲ�˵��ڴ�������������ս��ʤ���ɣ�\n"NOR,
		CYN"½����˵�����к�������ӣ���ս��ʤ��\n"NOR,
	}) );
	set("inquiry", ([
		"����" : (: ask_lingpai :),
		"ͨ������" : (: ask_lingpai :),
		"lingpai" : (: ask_lingpai :),
		"ling pai" : (: ask_lingpai :),
		
		"�������" :	(: ask_seawar() :),
		"job" :		(: ask_seawar() :),
		"����" :	(: ask_seawar() :),
		"���" :	"�������ں��峯ˮʦ����֮�У�������ս�ɣ��ô��ٲ�����ġ�",
		
//		"ҩ��": (: ask_yaopu :), 
//		"��ҩ": (: ask_makeyao :),
//		"��ҩ": (: ask_makeyao :),
//		"ҩ¯": (: ask_yaolu :),
//		"ҩ��": (: ask_yaozhong :),
	]));

	setup();
	carry_object(__DIR__"obj/changsan")->wear();     
}


void init()
{
	add_action("do_steal","steal");
}

int do_steal(string arg)
{
	object ob=this_object();
	object me=this_player();
	object lpai;

	if(arg!="����" && arg!="ͨ������" && arg!="lingpai" && arg!="ling pai")
		return 0;

	if(!living(ob))
		return notify_fail("½������������û�����ƿ���͵��\n");

	lpai = present("ling pai", me);
	if(objectp(lpai) &&  lpai->query("sld")) {
		write("���Ѿ��������ƣ���͵��������\n");
		return 1;
	}
	tell_object(me,"�㲻����ɫ�ؿ���½������͵͵�ذ�����½��������ȥ...\n");
	if(me->query("kar") > random(20)) {
		tell_object(me,"��ɹ���͵���˿�ͨ������!\n");
		lpai= new(__DIR__"obj/lingpai");
		lpai->move(me);
	}
	else {
		tell_room(environment(me),CYN"½���������е���"+me->name()+"�㾹��͵���ƣ�������ˣ�\n"NOR);
		tell_room(environment(me),CYN"½����һ�Ű�"+me->name()+"���˳�ȥ��\n"NOR);
		if (me->query("qi") > me->query_skill("force",1))
		me->receive_damage("qi",me->query_skill("force", 1));
		else me->set("qi", 1);
		me->move("/d/sld/kongdi");
	}
	return 1;       
}

int prevent_learn(object me, string skill)
{
	return 0;
}

int recognize_apprentice(object ob)
{
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if(!(myfam["family_name"] != "������")
	 && ob->query("shen",1) < -10000
	 && ob->query_skill("dulong-dafa",1) >= 100 
	 && ob->query_skill("huagu-mianzhang",1)>=100 ) {
		if(random(10) > 7)
		return 1;
	}
	return 0;
}

int ask_lingpai()
{
	object me,ob,zs;
	mapping myfam;
	object* inv;
	int i;

	me=this_player();
	ob=this_object();
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������") {
		return 0;
	}
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)       
	if(inv[i]->query("id")=="ling pai")
		break;
	if(i>=sizeof(inv)) {
		zs= new(__DIR__"obj/lingpai");
		if (!zs)  return notify_fail("�쳣����\n");
		tell_object(me,"��Ȼ��Ҫ�������Ҿ͸�������ưɡ�\n");
		tell_room(environment(me), "½������" + me->name() + "һ�����ơ�\n");
		zs->move(me);      
	}
	else {
		tell_object(me,"�㲻���Ѿ���������ô��\n");
	}
	return 1;
}

int ask_yaopu()
{
	object me=this_player();
	
	if(!me->query_temp("makeyao",1)) {
		return 0;
	}
	tell_object(me,"½��������˵�����Ҹ�����һ��ھ���������ԣ�˳ʱ���У�������Ϣ�������ѭ��Ǭ��Ϊ�ף��޶�Ϊβ��\n");
	return 1;
}

int ask_makeyao()
{
	object me=this_player();
	mapping myfam;

	myfam = (mapping)me->query("family");
   	if(!myfam || myfam["family_name"] != "������") {
		return 0;
   	}
	if(me->query_skill("shenlong-yaoli",1)<101 || me->query_skill("poison",1)<101)
		return 0;
	tell_object(me,"½��������˵��������������������ҩ����ҩ��֮�У�����ɲĺ�����ҩ¯֮�У��Ա����ܷ���֮���ɵ�ҩ��\n");
	me->set_temp("makeyao",1);
	return 1;
}

int ask_yaolu()
{
	object me=this_player();
	object yl;

	if(!me->query_temp("makeyao",1))
   	{
       		return 0;
   	}
	if(objectp(yl=me->query("myyaolu")))
	{
		if(random(10)>2)
			return notify_fail("�����Ѿ�������ҩ¯��ô��\n");
		else
			destruct(yl);
	}
	yl=new("/d/sld/npc/obj/yaolu");
	if(!yl)
		return notify_fail("����û��ҩ¯����Ȼ�����Ҫ�ɡ�\n");
	else if(!yl->move(me))
	{
		destruct(yl);
		return notify_fail("���Ȱ�����û�õĶ����������Ȼ������Ҫҩ¯�ɡ�\n");
	}
	else
	{
		yl->set("owner",me);
		tell_object(me,"½����������һֻҩ¯����������ֻҩ¯��ҩȥ�ɡ�\n");
		me->set("myyaolu",yl);
	}
	return 1;
}

int ask_yaozhong()
{
	object me=this_player();
	
	if(!me->query_temp("makeyao",1))
   	{
       		return 0;
   	}
	else if(me->query_temp("yaozhong",1))
	{
		return notify_fail("�Ҳ����Ѿ�����˵����ô������ô�����ˣ�\n");
	}
	tell_object(me,"½��������˵�������ϴβ�֪����ҩ����������ȥ�ˣ������ҵ����ٸ��㡣\n");
	me->set_temp("yaozhong",1);
	return 1;
}

void kill_ob(object ob)
{
	object me = this_object();
	command("say �Ϸ����ڳﻮ�Կ������û���������档");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say �Ϸ����ڳﻮ�Կ������û���������档");
	return 0;
}

string ask_seawar()
{
	object * team;
	object me;
	int i;
	
	me = this_player();
	team = me->query_team();
	
	if(wizardp(me) && me->query("env/test"))
		return SEAWAR_D->play(me,me,2);
	
	if( sizeof(team) != 2 )
		return "������ս����Ķ������Ҫ�������ˡ�";
	for (i=0;i<sizeof(team);i++) {
		if ( !team[i] || !userp(team[i]) || !present(team[i],environment(me)) )
			return "��Ҫ��˭һ���ս��";
		if( team[i]->query_condition("job_busy") || team[i]->query("job_name")=="��������ս" || team[i]->query_condition("killer") )
			return "���ǵĶ���̫æµ�ˣ���Ϣһ����ٲ�ս�ɡ�";
		if( team[i]->query("combat_exp")<100000 )
			return "���ǵĶ���ľ���̫���ˣ�������ȥ����һ�¶�������ս�ɡ�";
		if( team[i]->query("shen")>-30000 )
			return "�����ƺ������ҵ����ˣ��ҿɲ����������ǲ�ս��";
	}

	return SEAWAR_D->play(team[0],team[1],2);
}
