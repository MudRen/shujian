// hongying-qiang.c ��ӧǹ

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(RED"��ӧǹ"NOR , ({ "hongying qiang", "qiang", "spear","hongying" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ǹͷ�к�ӧ�ĳ�ǹ����ʱ�����ҵ��˵Ĺ��ܡ�\n");
                set("value", 1000);
                set("material", "steel");
        }
        init_spear(30);
        setup();
}
