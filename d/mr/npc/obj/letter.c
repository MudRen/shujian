#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"�ױ��ź�"NOR, ({ "xuanci letter","letter" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ�⵱�������·��ɵ��ױ��ź���\n");
                set("value", 0);
                set("no_get", 0);
                set("no_drop", 0);
         }
}

