// ITEM: /d/huashan/obj/gangdao.c
// Date: Look 99/03/25

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("�ֵ�", ({ "blade", "dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������Ƴɵĸֵ������ֽ��ڽ���֮��ǳ����С�\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(30);
	setup();
}
