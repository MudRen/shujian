// xzhang.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"xiong zhang", "xiong"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�ַ��ִ�Ĵ����ơ�\n");
                set("unit", "��");
                set("value", 10000);
                set("food_remaining", 6);
                set("food_supply", 60);
        }
}
