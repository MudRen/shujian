// NPC: /d/huashan/npc/haoke.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("��������", ({ "hao ke", "ke",}));
	set("long","һ�����������ĺ��ӡ�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 600);
	set("neili", 1000);
	set("max_neili", 1000);
	set("eff_jingli", 600);

	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 500);

	set_skill("unarmed", 50);

	setup();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
