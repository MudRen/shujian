// sword.c ��

#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
	set_name(HIW"��"NOR, ({ "ruan jian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����������ľ��ֽ������õ�ʱ����԰����������䡣\n");
		set("value", 500);
		set("material", "softsteel");
		set("wield_msg", "$N��ৡ���һ�������г��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�̻����䡣\n");
	}
	init_sword(30);
	setup();
}
