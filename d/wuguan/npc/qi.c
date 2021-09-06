//qi.c �ݷ� by river

inherit NPC;

#include <ansi.h>
int ask_xuexi4();
string ask_diyun();
string ask_tangshi();
string ask_xieyang();
void outwuguan(object me);
#include "/d/suzhou/npc/lchj.h";

void create()
{
	set_name("�ݷ�", ({ "qi fang","qi","fang", "woman" }));        
	set("gender", "Ů��");
	set("age", 21); 
	set("long", "ԲԲ��������һ˫���ۺ�����ġ�\n");
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "friendly");        

	set_skill("force", 30);
	set_skill("strike", 30);
	set_skill("sword", 30);
	set_skill("shenzhao-jing",30);
	map_skill("force", "shenzhao-jing");         
 
	set("inquiry", ([
		"���" : "�����ҵķ������",
		"ѧϰ" : (: ask_xuexi4 :),
		"����" : (: ask_diyun:),	
		"��ʫѡ��" : (: ask_tangshi:),	
		"Ь��" : (: ask_xieyang:),	

		"���Ǿ�" : "���Ǿ���......��û��˵����",
		"���ǽ���" : "ʲô���ǽ�������ֻѧ����ʬ������",
		"����ɽ" : "������ʦ����",
		"�Դ�ƽ" : "������ʦ����",
		"�ݳ���" : "�����ҵ�����",
		"÷����" : "����ī��÷��������������",
		"�仨��ˮ":"��˵�Ŀ��������棡",
		"������":"����ƽǹ�����ɡ���",
		"���˷�":"�����ƽ����˷硱��",
		"½����":"������½�󵶡���",
		"ˮ�":"�����½�ˮᷡ���",
	]));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 3);
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( ob ->query_temp("jobask") == 4) {
		command("wanfu "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob) +",����� "HIY HBCYN"ask qi about ѧϰ"CYN" �������˽�����������"NOR);
	}
}                               

int ask_xuexi4()
{
	object ob = this_player();
	if(ob->query_temp("jobask") == 4) {
		command("say  ��λ" + RANK_D->query_respect(ob) +"����ݶ���������������֮��ɺͱ������� "HIY HBCYN"chat"CYN"\n"+
			"�������������顣������ɢ��Щҥ�� "HIY HBCYN" rumor"CYN" ,ͬһ���ɵĻ������� "HIY HBCYN" party"CYN"��\n"+
			"���ĺ�ɢ��ҥ��ʱ����Щ�Ѿ��еĶ�������������� "HIY HBCYN"chat* hi"CYN" ���� "HIY HBCYN"semote"CYN"\n"+
			"���Բ����Щ�������˵Ķ��������㻰̫��������ͻᱻ��ͶƱ�رս�̸Ƶ\n"+
			"�� "HIY HBCYN"vote chblk xxx"CYN" ��Ƶ�������˺�ֻ�еȱ���ͶƱ�� "HIY HBCYN"vote unchblk\n"+
			"xxx"CYN" ����������������������������������������Ը��� "HIY HBCYN"tell"CYN" ��(��)����\n"+
			"�˸�����ʲô�£�������� "HIY HBCYN"reply"CYN" ���ش������������㻹���Ը�ĳһλ����\n"+
			"��ͬһ������˽����Ļ� "HIY HBCYN"whisper"CYN" �������ϲ����˳������书֮�У�ϲ����\n"+
			"��ɱɱ�ģ�Ȼ���Ҿ��û������Ľ��Ѹ���Ȥ�������Ϊ֮�ɡ�"NOR);
		ob->delete_temp("jobask");
		if(ob->query_temp("jobover") != 4) {
			ob->set_temp("jobover", 4);
			command("say ��˵��ʦ�ֻ��е��������㣬�����ȥ��һ�¡�"NOR);
			if ( ob->query("combat_exp") < 400 ) {
				ob->add("potential", 20);
				ob->add("combat_exp", 100);
				tell_object(ob,HIW"�������ݷ��Ľ��⣬������һ�ٵ�ʵս����Ͷ�ʮ��Ǳ�ܣ��Խ����ֶ���һ���˽⡣\n"NOR);
			}
		}
		return 1;
	}
	if ( ob->query_temp("jobover") == 4) {
		command("say �Ҳ��Ƕ�����˵��ô����ʦ���������㣬��ȥ���°ɡ�");
		return 1;
	}
}
string ask_diyun()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(!me->query_temp(QUESTDIR2+"waqiang" ))
	   return "Ҳ��֪������������ô������";
	if(me->query_temp(QUESTDIR2+"askqi" ))
	{
	   command("sigh");
	   command("say");
	   return "Ҳ��֪������������ô������";
	}
	command("say");
	message_vision(HIY"$N����¶���������ɫ��\n", ob);
	command("look "+me->query("id"));
	command("say ������������鷢����ȷ̫ͻȻ�ˣ���ʵ��Ҳ���õ��Ʋ��������ˡ�");
	command("sigh");
	command("say Ҳ��֪�����ڵ�����ô���ˡ�");
	me->set_temp(QUESTDIR2+"askqi_diyun",1);
	return "";
}
string ask_tangshi()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(!me->query_temp(QUESTDIR2+"askqi_diyun" ))
	{
	   command("doubt");
	   return "��˵ʲô��ʫѡ����";
	}
	if(me->query_temp(QUESTDIR2+"asktangshi" ))
	{
	   command("say");
	   return "������.....����������ˣ�";
	}
	if(me->query_temp(QUESTDIR2+"askxieyang" ))
	{
	   command("say");
	   return "�������鷿��";
	}
	command("consider");
	message_vision(HIY"$N��ϸ���Ժ�����������ʫѡ������\n", ob);
	command("look "+me->query("id"));
	command("say ������������ô�����֡��������е������������ˡ�");
	me->set_temp(QUESTDIR2+"asktangshi",1);
	return "";
}

string ask_xieyang()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(!me->query_temp(QUESTDIR2+"asktangshi" ))
	{
	   command("doubt");
	   return "��˵ʲôЬ����";
	}
	if(me->query_temp(QUESTDIR2+"askxieyang" ))
	{
	   command("say");
	   return "�������鷿��";
	}
	command("en");
	message_vision(HIY"$N�������Ժ�����������ʫѡ��������Ь������ͻȻ�ƺ�����������\n", ob);
	command("look "+me->query("id"));
	command("say ������������ô�����֡��Ҽǵø�������������Ь���ġ�");
	command("say �Һ���˳�ָ����鷿�ֻ��Ҳ��֪�����ڵ�����ô���ˡ�");
	me->set_temp(QUESTDIR2+"askxieyang",1);
	return "";
}
void outwuguan(object me)
{
	object ob=this_object();
	object *inv;
	if(!me) return;
	command("?");
	message_vision(HIY"$N����¶���ɻ����ɫ��\n", ob);
	command("say ����ô��������ģ�");
	message_vision(HIR"ֻ����һ�����˰���$N��һ������������ˡ�\n"NOR, me);
	me->delete("enter_wuguan");
	inv = filter_array(deep_inventory(me), (: userp :));
	if( sizeof(inv))
		inv->move(environment(ob));
	me->unconcious();
	me->move("/d/xiangyang/damen");
	me->delete_temp("quest/busy");//
	me->delete_temp("quest/���Ǿ�");
}
