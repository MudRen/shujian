// fish2.c ����

inherit ITEM;

void create()
{
	set_name("����", ({ "hai gui", "gui", "haigui", "yu", "fish" }) );
	set_weight(2000+random(2000));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("value", 50000);
		set("long", "һֻգ���۾��ĺ��꣬Ī������ؿ����㡣\n");
	}
	setup();
}
