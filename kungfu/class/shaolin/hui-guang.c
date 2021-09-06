// Npc: /kungfu/class/shaolin/hui-guang.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("�۹�����", ({
		"huiguang zunzhe",
		"huiguang",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ����һϮ�಼������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);

	set_skill("force", 90);
	set_skill("yijin-jing", 90);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 90);
	set_skill("blade", 90);
	set_skill("cibei-dao", 90);
	set_skill("club", 90);
	set_skill("weituo-gun", 90);
	set_skill("parry", 90);
	set_skill("buddhism", 90);
	set_skill("literate", 90);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


