// slp.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"������"NOR, ({"shenlong pao", "pao"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������Ƥ֯�ɵĳ��ۡ�\n");
                set("value", 10000);
                set("material", "fur");
                set("armor_prop/armor", 50);
        }
        setup();
}

