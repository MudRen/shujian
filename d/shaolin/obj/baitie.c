#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"����"NOR, ({ "baitie" }));
        set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
		set("long",
                        "�������书��������ԭ�������꣬ʮ��֮��������ʥǰ��һ����̡�\n");
                set("treasure", 1);
                set("value", 0);
                set("material", "paper");
         }
}
