// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_jhg();
void create()
{
	set_name("����", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "����һ����ʮ�������������, Ũü����,\n"+
	    "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
	    "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
	    "��������ɽͯ�ѵľ�������.\n");
	set("title", "���չ�������");
	set("gender", "����");
	set("age", 26);
	set("nickname", HIR "����" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);
	set("per", 1);

	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 12000);
	set("max_jing", 12000);
	set("neili", 38000);
	set("max_neili", 38000);
	set("jiali", 100);

	set("combat_exp", 5500000);
	set("score", 20000);
	set_skill("force", 450);
	set_skill("yangyanshu", 180);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("finger", 200);
	set_skill("claw", 200);
	set_skill("cuff", 200);
	set_skill("leg", 200);
	set_skill("sword", 300);
	set_skill("hand",350);
	set_skill("medicine",200);
	set_skill("longzhua-gong",200);
	set_skill("yizhi-chan",200);
	set_skill("buddhism",200);
	set_skill("literate",50);
	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 400);
  set_skill("tianyu-qijian",300);
	map_skill("force", "bahuang-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("claw", "longzhua-gong");
	map_skill("sword", "tianyu-qijian");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	create_family("���չ�",2, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.shandian" :),
                (: perform_action, "strike.baihong" :),
               
        }));

	set("inquiry", ([

		"������" : (: ask_jhg :),
			
	]));






        	setup();
	carry_object("/clone/armor/changpao1")->wear();
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
	 object me = this_player();
   if ((int)ob->query_skill("bahuang-gong", 1) < 100) 
           {
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
		return;
	   }  
   if ((string)ob->query("gender")=="Ů��")
   {
		message_vision("����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
			me->set("title",HIM "���չ���������" NOR);
       return;}
   else
      {
		message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
       return;}
}


string ask_jhg()
{
	object ob = this_player();
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "���չ�" )
		return RANK_D->query_respect(ob)+"��������ǰ�����н���ȥ��������һλŮ��ѧ����ֻ���������߲�����";
        if (ob->query_skill("bahuang-gong", 1) < 300 )
	return "��λ"+ RANK_D->query_respect(ob) +"��������ǰ�����н���ȥ��������һλŮ��ѧ����ֻ���������߲�����";


if(  ob->query("marks/xiaoyao") || ob->query("quest/xiaoyao/pass") || ob->query_temp("marks/ljg/gotolqs"))
      return "��λ"+ RANK_D->query_respect(ob) +"���Ҳ����Ѿ�����ȥ��������̽�������";
	
       ob->set_temp("marks/ljg/gotolqs", 1);
	command("nod " + ob->query("id"));
	return "������ǰ�����н���ȥ��������һλŮ��ѧ������λŮ���ƺ��������չ�ԨԴ�������ʱ��Ļ�����ȥ����������";       
}




