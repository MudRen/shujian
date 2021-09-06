// Npc: /kungfu/class/shaolin/dao-jue.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
	set_name("������ʦ", ({
		"daojue chanshi",
		"daojue",
		"chanshi",
	}));
	set("long",
		"����һλ��ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 21);
	set("dex", 22);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 450);
	set("max_neili", 450);
	set("jiali", 40);
	set("combat_exp",80000);
	set("score", 100);

	set_skill("force", 50);
	set_skill("yijin-jing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("hand", 53);
	set_skill("fengyun-shou", 53);
	set_skill("leg", 55);
	set_skill("shaolin-tantui", 55);
        set_skill("club", 55);
	set_skill("weituo-gun", 55);
	set_skill("parry", 50);
	set_skill("buddhism", 50);
	set_skill("literate", 50);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "fengyun-shou");
	map_skill("leg", "shaolin-tantui");
	map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");

	prepare_skill("hand", "fengyun-shou");
        prepare_skill("leg", "shaolin-tantui");

	create_family("������", 39, "����");

	setup();

        carry_object("/d/shaolin/obj/dao-cloth")->wear();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
}

#include "/kungfu/class/shaolin/dao.h"
