// r_jiasha.c ��ɫ����

#include <armor.h>
 

inherit CLOTH;

void create()
{
        set_name("��ɫ����",({"jiasha", "jia sha","cloth"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("value",100);
        }
        setup();
}

