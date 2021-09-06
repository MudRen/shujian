// Npc: /kungfu/class/shaolin/cheng-yu.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengyu luohan",
		"chengyu",
		"xumi",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ������һϮ��ߺڲ����ġ��������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ����������书��\n"
	);

	set("nickname", "�����޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen", 5000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 600000);
    set("unique", 1);

	set_skill("force", 100);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("staff", 100);
	set_skill("pudu-zhang", 100);
	set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("banruo-zhang", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("staff", "pudu-zhang");
	map_skill("parry", "pudu-zhang");
        map_skill("strike","banruo-zhang");
        prepare_skill("strike", "banruo-zhang");        

	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"
