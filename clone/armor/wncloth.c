// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("ά�����Ů��", ({ "weiwuer nupao", "nupao"}) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɫ�����޵�ά�����Ů��\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 50);
        }
        setup();
}

