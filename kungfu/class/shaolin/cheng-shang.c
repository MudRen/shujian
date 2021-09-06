// Npc: /kungfu/class/shaolin/cheng-shang.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("����", ({
		"chengshang luohan",
		"chengshang",
		"guangli",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
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
	set("combat_exp", 650000);
    set("unique", 1);

	set_skill("force", 85);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 85);
	set_skill("sword", 90);
        set_skill("damo-jian", 95);
	set_skill("parry", 85);
        set_skill("cuff", 100);
        set_skill("jingang-quan", 100);
	set_skill("buddhism", 85);
	set_skill("literate", 85);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
        map_skill("sword", "damo-jian");
        map_skill("parry", "damo-jian");
        map_skill("cuff", "jingang-quan");
        prepare_skill("cuff", "jingang-quan");
        
	create_family("������", 37, "����");

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

