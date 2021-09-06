// banker.c
// Looklove y2k/4/9

inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("�����", ({"long juanfeng", "long", "juanfeng"}));
        set("title", "Ǯׯ�ƹ�");
        set("gender", "����");
        set("age", 40);

        set("str", 30);
        set("int", 26);
        set("dex", 28);
        set("con", 28);

        set("qi", 5000); 
        set("max_qi", 5000);
        set("jing", 1000);
        set("max_jing", 1000); 
        set("shen", 0);

        set("combat_exp",400000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 80);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_check", ({"check", "chazhang", "����"}));
        add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
        add_action("do_deposit", ({"deposit", "cun", "��"})); 
        add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
