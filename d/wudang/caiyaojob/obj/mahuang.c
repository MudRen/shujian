#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"���"NOR, ({"ma huang", "yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", YEL"����һ��ǳ���ͨ�����Ż�ɫҶ�ӵ�Сֲ�\n"NOR);
            set("value", 100);
        }
        setup();
}
#include "medicine.h";
