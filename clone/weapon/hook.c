// hook.c

#include <weapon.h>
inherit HOOK;

void create()
{
    set_name("����", ({ "hook", "gou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������еĵ������ǿ��µ�����������\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n����������С�\n");
	}
	init_hook(30);
	setup();
}
