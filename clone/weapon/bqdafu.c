
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
	set_name(YEL"������"NOR, ({ "dafu","fu" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�˸��в�����������������΢���̣������������ƣ����ƾ����������п�ѩ�������ź��⣬���˲���������\n");
		set("no_sell", 1);
                set("value", 45000);
              set("rigidity",3);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
 init_axe(75);
	setup();
}
