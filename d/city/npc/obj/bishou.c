// bishou.c ذ��
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("ذ��", ({ "bi shou", "shou" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������Сذ�ס�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������С�\n");
	}
	init_dagger(10);
	setup();
}
