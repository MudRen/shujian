//Yanqi 08/11/2k
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"�ΰ�"NOR, ({ "yan ba", "yan", "ba" }) );
        set_weight(10000);
        set("unit", "��");
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long", "����һ���Ӻ�·���������ΰ͡�\n");
        set("no_give",1);
	}
	setup();
}
