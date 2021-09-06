// Npc: /kungfu/class/shaolin/hui-ming.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("��������", ({
		"huiming zunzhe",
		"huiming",
		"zunzhe",
	}));
	set("long",
		"����һλ���ް߰׵���ɮ������һϮ�಼������ġ��������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 27);
	set("dex", 22);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 70);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("yijin-jing", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("strike", 74);
	set_skill("weituo-zhang", 74);
	set_skill("blade", 70);
	set_skill("xiuluo-dao", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "weituo-zhang");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "weituo-zhang");

	prepare_skill("strike", "weituo-zhang");

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


#include "/kungfu/class/shaolin/hui.h"
