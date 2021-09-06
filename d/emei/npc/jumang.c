// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
	set_name("����", ({ "ju mang", "mang" }));
	set("race", "Ұ��");
	set("age", 200);
	set("long", "һ���Ӵ��ޱ�, ɫ�ʰ�쵵ľ����� ����������ǿ�ҵ��ȳ�ζ��\n");
	set("attitude", "aggressive");
	set("str", 70);
	set("con", 50);
	set("max_qi", 800);
	set("no_get","�����������̫���������޷��ö�");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 200000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	setup();
    if (clonep() && !random(2)) carry_object(MEDICINE_D("renshen-guo"));
}

void die()
{
	object ob;
	message_vision("$N�鴤�˼��£���������һ�����ˡ�\n", this_object());
	ob = new(__DIR__"msdan");
	ob->move(environment(this_object()));
	destruct(this_object());
}
