// longsword.c ����

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
	set_name( MAG"��������"NOR, ({ "youlong bian", "bian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ǧ�����Ƥ����ڽ�˿���ƶ��ɵĳ����ĳ��ޣ�͸����������ɫ���⣬�����ޱȡ�\n");
		set("value", 80000);
		set("no_sell", 1);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(100);
	setup();
}
