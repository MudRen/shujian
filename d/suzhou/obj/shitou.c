#include <weapon.h>

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
          set_name(HIY"ʯͷ"NOR,({ "shitou"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ��ʯͷ��\n");
                set("wield_msg", "$N�ó�һ��$n���������������������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_hammer(5);
        setup();
}
