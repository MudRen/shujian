inherit NPC;
mixed ask_me();
void create()
{
	set_name("Բ�ۺ���", ({
		"yuanhui heshang",
		"yuanhui",
		"monk",
	}));
	set("long",
		"����һλ��Ŀ������ɮ����һϮ�Ʋ����ġ�\n"
		"�ƺ��书������ʵ��\n"
	);
	set("nickname", "�޺��û�����ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("unique", 1);
	set("place","/d/shaolin/wstang5");
	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 250000);
	set_skill("force", 100);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	set("inquiry", ([
		"�似"     : (: ask_me :)
	]));

	create_family("������", 41, "����");
	setup();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

#include "/kungfu/class/shaolin/wuseng.h"
