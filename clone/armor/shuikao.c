#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("ҹ����", ({ "ye xingyi" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������ϸ��ҹ���¡�\n");
                set("material", "cloth");
		set("value", 2000);
                set("armor_prop/armor", 60);
        }
        setup();
}

