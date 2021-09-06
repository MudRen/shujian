
inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("�츻", ({"zhu fu", "zhu", "fu"}));
        set("title", "Ǯׯ�ƹ�");
        set("gender", "����");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("qi", 500); 
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set_skill("cuff", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object(ARMOR_D("jinduan"))->wear();
}

void init()
{
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
