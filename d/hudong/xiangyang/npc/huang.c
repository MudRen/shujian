#include <ansi.h>
inherit NPC;
#include "boss.h"

void create()
{
        set_name("��ҩʦ", ({ "huang yaoshi", "huang", "yaoshi" }) );
	set("nickname", "�һ�����");
	set("long",
		"�������һ����ĵ���������������������ɫ�Ķ�а��ҩʦ��\n"
		"����һ����ɫ���ۣ�������б����һֻ���\n"
		"��������񳣬������ˬ���������٣�տȻ����\n");
	set("gender", "����" );
	set("rank_info/rude", "����а");
	set("age", 50);
	set("attitude", "peaceful");
	set("apprentice",1);
	set("str", 30);
	set("int", 50);
	set("con", 35);
	set("dex", 40);
	set("per", 30);
	


        set("unique", 1);  //Ψһ��
   

        set("max_qi", 200000);
        set("max_jing", 20000);
        set("neili", 300000);
        set("max_neili", 300000);
        set("jiali", 200);
        set("eff_jingli",20000);
        set("combat_exp", 10000000);
        set("unique", 1);

       set_skill("force", 500);
	set_skill("bihai-chaosheng", 500);
	set_skill("dodge", 500);
	set_skill("suibo-zhuliu", 500);
	set_skill("parry", 500);
	set_skill("strike", 500);
	set_skill("luoying-zhang", 500);
	set_skill("leg", 500);
	set_skill("xuanfeng-tui", 400);
	set_skill("hand", 500);
	set_skill("lanhua-shou", 500);
	set_skill("finger", 500);
	set_skill("taoism", 200);
	set_skill("throwing", 390);
	set_skill("qimen-baguazhen", 200);
	set_skill("tanzhi-shentong", 500);
	set_skill("sword", 500);
	set_skill("yuxiao-jian", 500);
	set_skill("literate", 300);
	set_skill("qimen-bagua", 200);
	
	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("throwing", "tanzhi-shentong");
	map_skill("leg", "xuanfeng-tui");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-tui");
	

 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "maze" :),
		(: perform_action, "sword.qimen":),
		(: perform_action, "leg.kuangfeng":),
		
  }));


	create_family("�һ���", 1, "����");


	
	
        	
	
        
	

        set("max_cure",5);
        set_temp("��������/������ս/��Ӫ",1);

        set_temp("apply/damage",500);
        set_temp("apply/damage_force",500);
        set_temp("apply/armor",500);
        set_temp("apply/armor_force",500);
        set_temp("double_attack",1);
    

        
        setup();
if(clonep())
	{
		object ob = unew(ARMOR_D("rwj"));
		if(!ob) ob=new("/d/thd/obj/grn-cloth");
		ob->move(this_object());
		ob->wear();
	}
	
	if (clonep(this_object()))
	{
		object ob;
		if (ob = carry_object(BINGQI_D("sword/dongxiao")))
			ob->wield();
	}


}
