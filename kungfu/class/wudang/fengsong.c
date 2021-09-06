// fengsong.c ���ɵ���

inherit NPC;

string ask_me();

void create()
{
	set_name("���ɵ���", ({ "fengsong daozhang", "daozhang" }));
	set("long", 
		"�����䵱ɽ�ķ��ɵ�����������ɽ���ճ���Ʒ�ı���\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 38);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 1000);
	set("max_jing", 400);
	set("neili", 1200);
	set("max_neili", 1200);
        set("jiali", 50);
	set("combat_exp", 180000);
	set("score", 1000);

	set_skill("force", 60);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
        set_skill("yinyun-ziqi", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 70);
        set_skill("taiji-quan", 70);
        set_skill("cuff", 80);
	set_skill("taoism", 40);
        set_skill("tiyunzong", 60);

        map_skill("dodge", "tiyunzong");
        map_skill("force", "yinyun-ziqi");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 4, "����");
       
        set("inquiry", ([
		"����" : (: ask_me :),
        ]));

        set("robe_count", 1);
     

	setup();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
        carry_object("/d/wudang/obj/daolv")->wear();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾������������Ҫ���ۺ��ã�";
	if (query("robe_count") < 1)
		return "�µĵ��ۻ�û��������������������ɡ�";
        add("robe_count", -1);
        ob = new("/d/wudang/obj/white-robe");
	ob->move(this_player());
	return "�ðɣ�������������ȥ�ɡ��䵱�������ڼ�����úð�������";
}