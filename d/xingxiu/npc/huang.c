inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("????", ({"huang zhen", "huang", "zhen"}));
        set("title", "Ǯׯ?ϰ?");
        set("gender", "????");
        set("age", 34);
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);       
        set("combat_exp",300000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_check", ({"check", "chazhang", "????"}));
	add_action("do_convert", ({"convert", "duihuan", "?һ?"}));
	add_action("do_deposit", ({"deposit", "cun", "??"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
