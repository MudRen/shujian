// By River@sj 2002.6.5

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(BLU"����"NOR, ({ "tie jiang", "jiang"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����������������\n");
		set("unit", "��");
		set("value", 2000);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("wield_msg", "$N������$n�������С�\n");
	}
	init_staff(20);
	setup();
}
