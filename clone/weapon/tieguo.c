#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "tie guo", "guo" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���շ��õĴ��������Ѿ���Щ�����ˡ�\n");
                set("value", 30);
                set("material", "iron");
                set("wield_msg", "$N�ӱ���ȡ��һ��$n���������С�\n");
                set("unwield_msg", "$N�����е�$n���ڱ���\n");
        }

        init_hammer(7);
        setup();
}

