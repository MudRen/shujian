// heipao.c ����

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����", ({ "hei pao", "pao" ,"cloth" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("armor_prop/armor", 50);
        }
        setup();
}

