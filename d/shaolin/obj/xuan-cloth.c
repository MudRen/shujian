// xuan-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR "��������" NOR, ({ "jia sha", "cloth" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ı�֯�ĺ�ɫ�������ġ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("wear_msg","$N�ó�һ��$n�������ϡ�\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup();
}

