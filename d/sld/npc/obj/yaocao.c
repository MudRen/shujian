// yaomiao.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "ҩ��" NOR, ({"yao cao","cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������������ҩ��ҩ�ݣ�");
		set("unit", "��");
		set("5type","��");
		set("8type","Ǭ");
		set("stime",0);
		set("times",0);
		set("bad",0);
		set("no_clean_up",1);
	}
}

