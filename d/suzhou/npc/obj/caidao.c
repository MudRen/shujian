// caidao.c �˵�

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�˵�", ({ "cai dao", "dao" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�������õĲ˵���\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������С�\n");
	}
	init_blade(15);
	setup();
}
