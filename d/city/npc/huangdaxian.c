// huangdaxian.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW "黄大仙人" NOR, ({ "huang daxianren", "huang", "daxian", "daxianren" }) );
	set("nickname", HIR "通天知地" NOR);
	set("gender", "男性" );
        set("age", 190);
	set("long", "这位黄大仙人坐在那里，一副神秘莫测的样子。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
        set("no_get", 1);
	set("inquiry", ([
		"name" : "在下姓黄，因为算命算得准，所以大家都尊称我为黄大仙人。",
		"rumors" : "要想知道你今生的祸福荣辱，那就问我来算命吧。",
		"算命" : "我的价钱最公道，不多不少，只要两锭黄金。"
	]) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"黄大仙人吆喝道：铁嘴神算，价钱公道，相资两锭黄金。\n",
		"黄大仙人对你说道：客倌请留步，卜个吉凶如何？\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
	int per,kar,pur;
	if (ob->query("money_id") && ob->value() >= 20000) 
	{
		message_vision("黄大仙人对着$N端详了一阵。\n", who);
		who->set_temp("suanming_paid", 1);
		per = who->query("per");                
		kar = who->query("kar");
		pur = who->query("pur");
    command("say 你的容貌是"+per+"点,富源是"+kar+"点,纯朴是"+pur+"点");
    return 1;     
	}
	return 0;
}

