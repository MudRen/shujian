// /d/xiangyang/obj/mutou.c

inherit ITEM;

void create()
{
	set_name("ľͷ", ({ "mutou" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ľ�����ϵ�������ľͷ����ſ����ͻ���ľ���ɡ�\n");
		set("value", 1);
		set("material", "wood");
	}
	setup();
}
