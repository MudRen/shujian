// wbian.c

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("������", ({ "bian", "wulongbian","whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������͵���ޡ�\n");
                set("value", 50);
                set("material", "leather");
                set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������\n");
        }
        init_whip(5);
        setup();
}
