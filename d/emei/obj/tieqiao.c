// tieqiao.c

inherit ITEM;

void create()
{
	set_name("����", ({ "tie qiao", "qiao" }) );
	set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("long", "����һ�����¡�\n");
	}
	setup();
}
