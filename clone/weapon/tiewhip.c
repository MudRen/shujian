// tiewhip ����

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("����", ({ "tie bian", "tiebian","bian","whip" }));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶĳ��ޣ��쳣���ء�\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_whip(30);
        setup();
}

