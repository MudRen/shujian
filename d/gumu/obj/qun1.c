// qun1.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"��ɴ��ȹ"NOR, ({ "baisha changqun","qun","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һϮ��ɴ��İ��£����������������\n");
                set("unit", "��");
                set("material", "cloth");                
                set("armor_prop/armor", 40);
        }
        setup();
}
