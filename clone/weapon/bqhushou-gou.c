// hook.c

#include <ansi.h>
#include <weapon.h>
inherit HOOK;

void create()
{
    set_name(WHT"����"NOR, ({ "hanyu gou", "gou", "hook" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "\n����һ�Ծ������ƵĻ��ֹ����пڷ���������⣬�����ޱȣ�\n\n");
                set("value", 65000);
		set("material", "steel");
		set("no_sell", 1);
                set("rigidity", 3);
                set("weapon_prop/parry", 20);
                set("wield_neili", 50);
                set("wield_maxneili", 500);
                set("wield_str", 22);
	}
        init_hook(75);
	setup();
}

