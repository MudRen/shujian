// songguo.c
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ұ�ɹ�", ({ "song guo", "guo" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ӱ�����Ұ�ɹ�ʵ��\n");
                set("unit", "ö");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}

