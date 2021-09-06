// zhangquan.c

inherit NPC;

void create()
{
	set_name("��Ȫ", ({ "zhang quan", "zhang" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("title", "������佫"); 
        set("str", 25);
	set("dex", 16);
        set("unique" , 1);
	set("long", "���Ǹ�������佫����վ�������ȷ��˵���������硣\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 80);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("max_qi", 450); 
        set("qi", 450); 
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/armor/armor")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
