// item: denglong.c
// by snowman@SJ , 01/05/1999.
#include <ansi.h>
inherit FIRE_ITEM;
void create()
{
        set_name(HIR"�󻨵���"NOR, ({"dahua denglong", "dahua" "denglong", "light"}));
        set_weight(1400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һյֽ��Ĵ󻨵��������˺ڰ��ĵط�����(light)�����ˡ�\n");
                set("unit", "յ");
                set("value", 1500);
                set("light/time", 360);
        }
        setup();
}


