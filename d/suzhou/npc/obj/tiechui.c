// tiechui.c ����

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("����", ({ "tie chui", "chui" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ľ��ִ�������� \n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����������һ��$n��������������������\n");
		set("unwield_msg", "$N�����е�$n�������С�\n");
	}
	init_hammer(30);
	setup();
}
