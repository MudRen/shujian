// qingcai.c ���

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("���", ({ "qingcai" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ˡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 20);
        }
    setup();
}
