//  /d/dali/npc/dasao.c

inherit NPC;

void create()
{
	set_name("��÷�", ({ "li caifeng", "li","caifeng" }));
	set("title", "�÷���ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long", "��λ�ϰ���æ����ͷ�󺹡�\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/damage", 25);

	set("combat_exp", 8000);
	set("attitude", "friendly");

	setup();
}
