// huqin.c
#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name( "����" , ({ "hu qin", "huqin"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɽ�ϱ������������������������������������ζ��\n");
                set("value", 100);
                set("material", "wood");
        }
        init_hammer(5);
        setup();
}
