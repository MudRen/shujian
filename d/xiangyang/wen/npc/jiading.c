// jiading

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "jia" }));
	set("long", 
		"һ����ʮ����ļҶ�����ò����ʮ�����͡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen", -100);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 100);
	set("max_neili", 100);
         set("jiali", 20);
	set("combat_exp", 75000);
	 

	set_skill("force", 70);
       set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
        set_skill("cuff", 80);
 
       setup();
	carry_object("/clone/weapon/changjian")->wield();
}
