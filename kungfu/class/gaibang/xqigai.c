// xqigai.c

inherit NPC;
#include "begger.h";

void create()
{
	set_name("С��ؤ", ({ "xiao qigai", "xiao", "qigai" }));
	set("gb/bags", 1);
	set("title","ؤ�����");
	set("long","����һ��С��ؤ�������в����ࡣ\n");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", 0);

	set("str", 20);
	set("int", 16);
	set("con", 22);
	set("dex", 24);

	set("max_qi", 300);
	set("max_jing", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("combat_exp", 3000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("begging", 50);

	create_family("ؤ��", 20, "����");
	setup();

	carry_object(ARMOR_D("bainayi"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}
