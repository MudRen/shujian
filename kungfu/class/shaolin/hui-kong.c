// Npc: /kungfu/class/shaolin/hui-kong.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

mixed carry_water();

void create()
{
	set_name("�ۿ�����", ({
		"huikong zunzhe",
		"huikong",
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
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("yijin-jing", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("staff", 70);
	set_skill("wuchang-zhang", 70);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	set("inquiry", ([
		"��ˮ":	(: carry_water :)
	]));

	create_family("������", 38, "����");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

mixed carry_water()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query("carry_count"))
    if (present("liao kao", me)) {
        destruct(present("liao kao", me));
        return "��Ļ��Ѿ������ˣ��Ұ���⿪����";
    } else
		return RANK_D->query_respect(me) + "���ǿ���Ц�ɣ�";
	if (present("tie tong", me))
		return "�㲻��������Ͱ�𣿿�ȥ�ɻ�ɡ�";
	if (present("tie tong", environment()))
		return "��Ͱ�����ڵ��Ϸ�������ȥ�ɻ�ɡ�";
	command("buddhi");
	new("/d/shaolin/obj/tie-tong")->move(environment());
	command("say ���Ǹɻ�ļ�ʲ����ȥ�ðɡ�");
	message_vision("$N������ó�һ�Դ���Ͱ���ڵ��ϡ�\n", ob);
	return 1;
}
