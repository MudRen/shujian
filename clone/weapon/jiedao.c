// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�̵�", ({ "duan dao","dao" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ���䵶�������ɵĳ���������\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(20);
	setup();
}
