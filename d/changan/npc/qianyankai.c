// Write By Yanyang@SJ 2001.9.29
// NPC : /d/changan/npc/qianyankai.c

inherit NPC;
inherit F_BANKER;

void create()
{
	set_name("Ǯ�ۿ�", ({"qian yankai", "qian"}));
	set("title", "Ǯׯ�ƹ�");
	set("gender", "����");
	set("age", 45);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 800);
	set("max_jing", 800);
	set("eff_jingli", 600);
	set("shen", 10);

        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "friendly");

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 40);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	::init();
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
