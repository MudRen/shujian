// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19

inherit NPC;
string ask_me();

void create()
{
       set_name("���ɴ�ʦ", ({
		"xuandu dashi",
		"xuandu",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ�\n"
		"�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
	);


	set("nickname", "�黨����");
	set("gender", "����");
	set("class", "bonze");
        set_max_encumbrance(1000000);
     	set("age", 90);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1800);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1400000);
	set("score", 0);

	set_skill("force", 150);
	set_skill("yijin-jing", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
	set_skill("parry", 150);
	set_skill("finger", 180);
//	set_skill("staff", 150);
//	set_skill("blade", 150);
//	set_skill("sword", 150);
	set_skill("nianhua-zhi", 180);
	set_skill("weituo-gun", 150);
	set_skill("xiuluo-dao", 150);
//	set_skill("fumo-jian", 150);
	set_skill("buddhism", 160);
	set_skill("literate", 150);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "nianhua-zhi");
	map_skill("finger", "nianhua-zhi");
//	map_skill("staff", "weituo-gun");
//	map_skill("blade", "xiuluo-dao");
//	map_skill("sword", "fumo-jian");

	prepare_skill("finger", "nianhua-zhi");

	create_family("������", 36, "����");

	set("inquiry", ([
		"�𷨽�ħ"       : (: ask_me :),
		"��������"	   : (: ask_me :)
	]));

	setup();
   //        carry_object("/clone/weapon/jinnao2")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

#include "/kungfu/class/shaolin/xuan-du.h"




