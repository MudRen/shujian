inherit NPC;
#include <ansi.h>
#include "/d/suzhou/npc/lchj.h";

void create()
{
	set_name("������", ({ "hua tiegan", "hua"}));
	set("title", HIY"��ƽǹ"NOR);
	set("long", "�˳ơ���ƽ�޵С����ԡ���ƽǹ���������֡�\n");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen", -100);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

        set("max_qi", 30000);
        set("qi", 30000);
        set("eff_qi", 30000);
	set("max_jing", 6000);
	set("eff_jingli",6000);
	set("neili", 20000);
	set("max_neili", 10000);
	set("jiali", 200);
	set("combat_exp", 600000+random(600000));
	set_skill("cuff", 220);
	set_skill("dodge", 320);
	set_skill("parry", 230);
	set_skill("force", 300);
	set_skill("longxiang-boruo", 250);
	set_skill("yuxue-dunxing", 250);
	set_skill("taizu-quan", 200);
	set_skill("spear", 250);
        set_skill("yangjia-qiang", 300);
	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
        map_skill("parry", "yangjia-qiang");
        map_skill("spear", "yangjia-qiangfa");
	map_skill("cuff","taizu-quan");
	prepare_skill("cuff","taizu-quan");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "spear.lianhuan" :),
		(: perform_action, "spear.huimaqiang" :),
	}));
	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("ycloth"))->wear();
	carry_object(BINGQI_D("spear"))->wield();
}
void init()
{
	if(query("set_ok")) return;
	set("set_ok",1);
	remove_call_out("dest");
	call_out("dest",120);
}
void die()
{
	object me,ob=this_object();
	me=ob->query("quest_object");
	if(me 
	 	&& present(me,environment(ob))
		&& me->query_temp(QUESTDIR1+"trust"))
		{
			if(present("di yun",environment(ob)))
		       me->set_temp(QUESTDIR1+"kill_hua",1);
		  else 
		  {
		  	tell_object(me,HIY"ֻ��ϧ���ƾ�Ȼ���ұ���������Ҳ�����ζ��䶡������"NOR);
		  	me->delete_temp(QUESTDIR);
		  }
		}
	  message_vision(HIR"\n$N�ٺٽ��˼������µ��������뿪�ˡ�\n"NOR,ob);
	  destruct(ob);
}
void dest()
{
	message_vision(HIR"\n$N�ٺٽ��˼������µ��������뿪�ˡ�\n"NOR,this_object());
	destruct(this_object());
}
void unconcious()
{
  die();
}
