//cool 98.2.17

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������ʦ", ({	"liaoming chanshi", "liaoming", "chanshi"}));
	set("long",
		"����һλ������ݵ�����ɮ�ˣ����۲�����׳���� \n"
              "һϮ�Ҳ�������ģ�����տտ�����ƺ���һ�����ա�\n"
	);

	set("nickname", "��������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 45);
	set("str", 23);
	set("int", 23);
	set("con", 23);
	set("dex", 25);

	set("max_qi", 1400);
	set("max_jing", 1300);
	set("neili", 1800);
	set("max_neili", 1800);
	set("eff_jingli", 1000);
	set("jiali", 70);
	set("combat_exp", 800000);
	set("shen", 8000);

	set_skill("force", 100);
	set_skill("qiantian-yiyang", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("tianlong-xiang", 100);
	set_skill("finger", 100);
	set_skill("sword", 100);
	set_skill("strike", 100);
	set_skill("qingyan-zhang", 100);
	set_skill("yiyang-zhi", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 90);
	map_skill("strike", "qingyan-zhang");
	map_skill("force", "qiantian-yiyang");
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger",  "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");
	create_family("������", 14, "����");    

	set("inquiry", ([
		"ҩ" :  "�����鵤��ҩ���٣��������ľ�����������ѩ¶��",
	]));
	setup();
        carry_object("/d/tls/obj/jiasha1")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}

#include "liao.h";
