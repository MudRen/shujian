// Room: /d/huashan/jinshe/obj/shuteng.c
// Date: Look 99/03/25

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����",({ "teng", "shuteng" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ�����١�\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(3);
        setup();
}
