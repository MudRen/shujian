#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"�ٻ�"NOR, ({"teng huang", "yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", YEL"����һ�λ�ɫ�����٣�ɢ����ŨŨ��ҩζ��\n"NOR);
            set("value", 100);
        }
        setup();
}
#include "medicine.h";
