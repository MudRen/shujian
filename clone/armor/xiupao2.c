// xiupao2.c
// Lklv 2001.9.25

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIR"�������"NOR, ({ "hongxiu pao", "xiupao", "pao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("long", HIR"һ��ϲ������Ĵ��ɫ���ӳ��ۡ�\n"NOR);
                set("value", 12500);
                set("armor_prop/armor", 2);
        }
        setup();
}