// grn-cloth.c thd �������Ӵ�

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC"��ɫ����"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","����һ����ɫ�ĳ��ۡ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}
