// /u/beyond/hz/npc/yplaoban.c
inherit NPC;

void create()
{
	set_name("�ϰ�", ({ "lao ban", "ban" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "�����Ǻ��ݳ���������ҩ���ϰ塣\n");
	set("age", 65);
	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);

	setup();
	add_money("gold", 1);
	carry_object(ARMOR_D("cloth"))->wear();
}
