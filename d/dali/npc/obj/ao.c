// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����Ƥ��", ({ "jinxiu piao", "piao"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ɵĽ���Ƥ��������������\n");
                set("material", "cloth");
                set("value",2500);
                set("armor_prop/armor", 10); 
        }
        setup();
}
