// da-shitou.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("������"NOR,({ "da tiechui", "tiechui" }) );
         set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                 set("value", 1000);
                set("material", "steel");
                set("long", "����һ�����صĴ�������\n");
                set("wield_msg", "$N�ó�һ��$n���������������������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_hammer(10);
        setup();
}
