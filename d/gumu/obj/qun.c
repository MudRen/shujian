// qun.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"��ɴ��ȹ"NOR, ({ "qingsha changqun","qun","cloth" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һϮ��ɴ������£����������������\n");
                set("unit", "��");
                set("material", "cloth");                
                set("armor_prop/armor", 20);
        }
        setup();
}

