// dongsun-tang ��Ҷ������
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"��Ҷ������"NOR, ({"dongsun-tang", "tang"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ��õ�壬���ۿɿڵĺ�Ҷ��������\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
