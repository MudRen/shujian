// Write By Yanyang@SJ 2001.9.27
// F_shuimitao.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
 
void create()
{
        set_name(HIM"ˮ����"NOR, ({"shuimi tao", "shuimitao", "tao"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ˮ���ҡ�\n");
                set("unit", "��");
                set("value", 40);
                set("food_remaining", 2);
                set("food_supply", 25);
          }
        setup();
}
