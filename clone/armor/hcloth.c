// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�Ƹ���", ({ "gebu shan", "shan"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ƺ�ɫ�𲼳���\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("value", 0);
        }
        setup();
}

