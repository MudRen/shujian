// bian.c

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("׷���", ({ "zhuihun bian", "bian","whip" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ţ���ɵĵ���ޡ�\n");
                set("value", 900);
                set("material", "leather");
                set("wield_msg", "$N��ৡ���һ�������г��һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������ϡ�\n");
        }
        init_whip(25);
        setup();
}
