// snakewhip.c ���߱�

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("����", ({ "jin she", "snake","she","bian", "whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���������������С�ߡ�\n");
                set("value", 30);
                set("material", "fur");
                set("wield_msg", "$N��ৡ���һ���ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�Ż������䡣\n");
                set("no_sell",1);
	        set("no_get",1);
	        set("no_steal",1);
                set("no_give",1);
                set("no_drop",1);
		set("no_return",1);
        }
        init_whip(30);
        setup();
}

