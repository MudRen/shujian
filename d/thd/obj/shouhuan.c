#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
        set_name(HIW"���ֻ�"NOR, ({"yin shouhuan", "yin", "shouhuan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ֵ��ֻ����ƺ�û��������\n");
                set("value", 1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("material", "silver");
                set("armor_prop/dodge",5);
                set("armor_prop/hand",5);
                set("wear_msg", HIW "$N����һ�����ֻ���\n" NOR);
                set("remove_msg", HIW "ֻ��$N�����ֻ�����������\n" NOR);
        }
        setup();
}

