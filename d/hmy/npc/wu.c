// wu.c

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("吴柏英", ({ "wu baiying", "wu", "baiying"}));
        set("long", "这女子肌肤微黑，双眼极小，黑如点漆。\n");
        set("nickname","桐柏双奇");
        set("title",HIY"日月神教  "HIW"白虎堂舵主"NOR);
        set("gender", "女性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);

        set("max_qi", 2800);
        set("max_jing", 1300);
        set("eff_jingli", 1500);
        set("jiali", 50);
        set("combat_exp", 900000);
       
        set_skill("force",160);
        set_skill("dodge",160);
        set_skill("ding-dodge",160);   
        set_skill("tianmo-gong",160);
        set_skill("literate", 120);
        set_skill("parry",160);
	set_skill("tianmo-dao", 160);
	set_skill("blade", 160);
	set_skill("hand", 160);
	set_skill("tianmo-shou", 160);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
	map_skill("blade", "tianmo-dao");
	map_skill("parry", "tianmo-dao");
	map_skill("hand", "tianmo-shou");
	prepare_skill("hand", "tianmo-shou");
	create_family("日月神教",9,"弟子");


        setup();

	carry_object(BINGQI_D("blade"))->wield();
	carry_object(MISC_D("cloth"))->wear();        
}
