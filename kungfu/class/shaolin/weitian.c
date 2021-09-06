
inherit NPC;

void create()
{
	set_name("������", ({ "wei tianwang","wei" }) );
	set("gender", "����" );
	set("age", 58);
	set("long", " \n");
	set("attitude", "peaceful");
	set("nickname", "�������ֳ���");
	set("unique", 1);
	set("str", 20);
	set("con", 35);
	set("int", 25);
	set("dex", 35);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 300);
	set("max_neili", 3000);
	set("jiali", 100);
	set("shen_type", 1);
	set("combat_exp", 800000);

	set_skill("force", 120);
	set_skill("cuff", 120);
	set_skill("sword", 120);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("literate", 100);
	set_skill("jingang-quan", 120);
	set_skill("yijin-jing", 150);
	set_skill("buddhism", 150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	prepare_skill("cuff", "jingang-quan");

	create_family("��������", 19, "����");
	setup();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void kill_ob(object me)
{
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.fumo" :)
	}));
	::kill_ob(me);
}
