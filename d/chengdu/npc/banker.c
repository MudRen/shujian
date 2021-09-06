// banker.c
// Looklove y2k/4/10

inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("Õı’∆πÒ", ({"wang zhanggui", "wang", "zhanggui"}));
        set("title", "«Æ◊Ø’∆πÒ");
        set("gender", "ƒ––‘");
        set("age", 49);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("qi", 500); 
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100); 
        set("shen", 10);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_check", ({"check", "chazhang", "≤È’ "}));
	add_action("do_convert", ({"convert", "duihuan", "∂“ªª"}));
	add_action("do_deposit", ({"deposit", "cun", "¥Ê"})); 
	add_action("do_withdraw", ({"withdraw", "qu", "»°"}));
}
