// bainayi.c ���Ľ���
// login cloth
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"���Ľ���"NOR, ({ "baina jieyi", "cloth" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
		set("armor_prop/armor", 20);
        }
        setup();
}