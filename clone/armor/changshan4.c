// changshan4.c
// Lklv 2001.9.25

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIB"��ɫ����"NOR, ({ "changshan", "cloth" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", HIB"һ�����Ӵ�����ɫ������\n"NOR);
                set("value", 3500);
                set("armor_prop/armor", 2);
        }
        setup();
}