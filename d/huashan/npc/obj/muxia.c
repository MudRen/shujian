//by daidai
//ľϻ

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW "ľϻ" NOR, ({"muxia", "mu xia", "xie"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("long", HIG "����һ��̴ľ�Ƴɵ�С���ӣ�������������鼮��\n");
              set("value", 10000);
              set("unique", 1);
              set("treasure",1);
//              set("no_drop", 1);
              set("no_get", 1);
        }
        setup();
}


