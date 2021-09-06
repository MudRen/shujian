//shao.c ����
//6/12/97 -qingyun
inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("����",({"shao gong","shao","gong"}));
	set("long",  "����һ����ˮ���ˡ�\n");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("combat_exp", 1000);
	set_skill("cuff",20);
	set_skill("dodge",20);
	set_skill("force", 20);
	set_skill("parry", 20);	
	set("inquiry", ([
		"����" : (: ask_me :),
		"here" : "���������������ڣ�λ���ǻƵ�������ʮ�塢����ʮ������룬���Ҫ�����Ŷ��\n",
		"rumors" : "���ﾭ�����������Է籩����Ҫ���ע�⡣\n",	 
	]));
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"��������˵������������һֻ��������û�й黹���Һ���ǰ׬��һЩ�ϱ����¹�һֻ������\n"NOR,		
		CYN"����˵��������������˵���м�ֻ�洬�ڻƵ������ĸ��������˴�籩�������ǻز����ˡ���\n"NOR,
		CYN"����˵���������˳�������˵���������м����ɵ�������ס�����ˣ���֪�����Ǽ١���\n"NOR,
	}));
	setup();
	add_money("silver", 1);
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object("/d/mingjiao/obj/luopan");
}

string ask_me()
{
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	ob->set_temp("marks/��1",1);
	return "�ɴ˳�����Ϊ���գ��ҿɲ�ȥ�����ҵĴ����Խ���㣬�����Ժ������.....";
}	

int accept_object(object me, object ob)
{
	me=this_player();
	if (ob->query("money_id") && ob->value() >= 5000
		&&me->query_temp("marks/��1")){
		command("whisper "+me->query("id")+" ��Ҫȥ����ͽ�(yell)�ҵĺ���(chuan)�ɡ�\n");
		me->set_temp("haichuan_paid",1);
		me->delete_temp("marks/��1");
		return 1;
	}
	return 0;
}
