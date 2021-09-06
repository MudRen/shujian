// quanjiannan.c Ȫ����

inherit NPC;

void create()
{
	set_name("Ȫ����", ({ "quan jiannan","quan","nan" }));
	set("long", "һ����ʮ��������ߣ���Ŀ��������ʿ���в��졣\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen", -4800);

	set("str", 38);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 2000);
	set("eff_jingli", 1000);
	set("max_neili", 2000);
        set("jiali", 80);
	set("combat_exp", 480000);
	set("score", 10000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 80);
        set_skill("cuff", 100);
        set_skill("murong-jianfa", 100);
	set_skill("literate", 80);
        set_skill("finger",100);
        set_skill("yinyun-ziqi",100);
        set_skill("canhe-zhi",100);
        set_skill("shuishangpiao",80);

        map_skill("dodge", "shuishangpiao");
        map_skill("force", "yinyun-ziqi");
        map_skill("parry", "murong-jianfa");
	map_skill("sword", "murong-jianfa");
        map_skill("finger", "canhe-zhi");
        prepare_skill("finger", "canhe-zhi");

        create_family("������", 2, "����");

	setup();
	carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
