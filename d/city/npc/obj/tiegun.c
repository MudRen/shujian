// weapon: tiegun.c
// Jay 3/18/96

#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("����", ({ "tiegun", "gun" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ƺ���������\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(10);
        setup();
}

