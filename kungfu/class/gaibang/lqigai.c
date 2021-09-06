// znqigai.c ������ؤ

inherit NPC;
#include "begger.h";

void create()
{
	set_name("����ؤ", ({ "qi gai", "di zi", "qigai" }));
	set("title","ؤ�����");
	set("gb/bags", 1);
	set("long","����һ������ؤ���������в������ơ�\n");
	set("gender", "����");
	set("age", 50+random(30));
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 20);
	set("int", 16);
	set("con", 22);
	set("dex", 24);

	set("max_qi", 300);
	set("max_jing", 300);
	set("eff_jingli", 500);
	set("max_neili", 300);
	set("jiali", 10);
	set("combat_exp", 3000);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("begging", 30);

	create_family("ؤ��", 20, "����");
	setup();
	carry_object(CLASS_D("gaibang/obj/gb_budai1"))->wear();
	carry_object(ARMOR_D("bainayi"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}
