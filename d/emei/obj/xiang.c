// xiang.c

inherit ITEM;

void create()
{
	set_name("��", ({ "xiang" }) );
	set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
	else {

		set("unit", "��");
		set("value", 0);
		set("long", 
"���ǽ�����϶�üɽ�����õ��㡣\n");
	}
	setup();
}
