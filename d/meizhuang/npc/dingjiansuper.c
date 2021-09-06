// NPC: /d/meizhuang/npc/dingjian.c
// By action 2009/1/11

inherit NPC;

int do_flatter(string arg);

void create()
{
	set_name("丁坚", ({ "ding jian", "ding" }));
	set("nickname", "一字电剑");

	set("gender", "男性");
	set("age", 48);
	set("long", "他目光炯炯，步履稳重，显是武功不低。\n");
	set_skill("dodge", 120);
	set_temp("apply/damage", 40);
	set("per", 20);
	set("attitude", "heroism");
	set("class", "songshan");
	set("shen_type", -1);
	set("str", 29);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("unique", 1);
	set("no_bark",1);

	set("max_qi", 100000);
	set("max_jing", 5800);
	set("eff_jingli", 8000);
	set("jiali", 100);
	set("combat_exp", 4200000);
	set("shen", -18000);
	set("max_neili", 16000);
	set("neili", 30000);

	set_skill("literate", 220);
	set_skill("force", 380);
	set_skill("dodge", 350);
	set_skill("hand", 350);
	set_skill("strike", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("songshan-jian", 400);
	set_skill("songyang-shou", 400);
	set_skill("zhongyuefeng", 350);
	set_skill("hanbing-shenzhang", 400);
	set_skill("hanbing-zhenqi", 400);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	map_skill("strike", "hanbing-shenzhang");
	prepare_skill("hand", "songyang-shou");
	

	set("combat_exp", 7000000);
	set("attitude", "peaceful");

  set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.longfeng" :),
		(: perform_action, "sword.leiting" :),
		(: exert_function, "juhan" :),
		(: exert_function, "hanbing" :),
	}));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object("clone/weapon/sword")->wield();
	
}

