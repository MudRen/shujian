// zhike.c ֪��

inherit NPC;

void create()
{
	set_name("֪�͵���", ({ "zhike daozhang", "zhike", "daozhang" }));
	set("long", "�����䵱ɽ��֪�͵�����\n");
	set("gender", "����");
	set("age", 38);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 1300);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
        set("jiali", 40);
        set("eff_jingli", 1000);
	set("combat_exp", 175000);
	set("score", 1000);

	set_skill("force", 70);
        set_skill("tiyunzong", 60);
        set_skill("yinyun-ziqi", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
        set_skill("cuff", 80);
        set_skill("taiji-quan", 70);
	set_skill("taiji-jian", 50);
	set_skill("taoism", 20);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 4, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/d/wudang/obj/daolv")->wear();
}
