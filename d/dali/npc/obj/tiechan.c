// tiechan.c

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "tiechan" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻ������������\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ���ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");
        }
        init_staff(25);
        setup();
}
