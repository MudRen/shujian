#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIG "����" NOR, ({ "biyu jian", "sword", "jian" }) );
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("treasure",1);
		set("rigidity", 4);
		set("sharpness", 6);
		set("unique", 1);
		set("weapon_prop/parry", 2);
		set("wield_neili", 500);
		set("wield_maxneili", 900);
		set("wield_str", 23);
		set("material", "jade");
		set("long", "���ǰ�ǰ�������������������͸������֮�⣬��������ޱȡ�\n");
		set("wield_msg", HIC "ֻ�������ˡ���һ�����̹����֣�$N��������µ�$n" HIC "���ñ�ֱ��\n" NOR);
		set("unwield_msg", HIC "$n" HIC "����һ������֮�⣬��ৡ��ط��뽣�ʡ�\n" NOR);
	}
	init_sword(50);
	setup();
}
