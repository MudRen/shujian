// gangzhang.c

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("������", ({ "tianshe zhang", "zhang", "staff", "tianshe" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�������Ͼ������������ȣ���Լ���ߣ��������ߣ���̶���죬��ͷ������ͷ������ȥ������졣\n");
                set("value", 75000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
        init_staff(60);
	setup();
}
