// Npc: /kungfu/class/shaolin/qing-guan.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("��۱���", ({
		"qingguan biqiu",
		"qingguan",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺�\n"
		"���������������һϮ�ײ��ڱ����ģ��ƺ��������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("yijin-jing", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("finger", 30);
	set_skill("mohe-zhi", 30);
        set_skill("claw", 30);
	set_skill("jimie-zhua", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "mohe-zhi");
        map_skill("claw", "jimie-zhua");
	map_skill("parry", "jimie-zhua");

	prepare_skill("claw", "jimie-zhua");
        prepare_skill("finger", "mohe-zhi");

	create_family("������", 40, "����");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


