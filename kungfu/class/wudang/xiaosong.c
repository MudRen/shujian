// xiaosong.c ������

inherit NPC;

void create()
{
	set_name("������", ({ "song qingshu", "song" }));
	set("long", 
		"��������Զ�ŵĶ��������顣\n"
		"�������ʮ�꣬�����䵱�������г�����͵����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 60);
        set_skill("yinyun-ziqi", 40);
	set_skill("dodge", 70);
	set_skill("tiyunzong", 40);
	set_skill("cuff", 70);
	set_skill("taiji-quan", 50);
	set_skill("parry", 70);
	set_skill("sword", 70);
	set_skill("taiji-jian", 50);
	set_skill("taoism", 30);
	set_skill("literate", 40);

        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 3, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
