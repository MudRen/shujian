#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;
void create()
{
     set_name(HIR"ƻ��"NOR, ({
              "pingguo",
              "guo"
             }));
     set_weight(25);
     if (clonep())
     set_default_object(__FILE__);
     else {
     set("unit", "ֻ");
     set("long", 
     "����һֻ��ƻ������ͮͮ�ģ������������˵ķ��㡣\n");
     set("food_remaining", 4);
    set("food_supply", 40); 
    setup();
}
}
