// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
    	set_name("�ձ���", ({ "riben dao", "dao", "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ѩ�����ձ����������쳣��\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ��γ������$n�������С�\n");
		set("unwield_msg", "$N�����������$n��ص��ʡ�\n");
	}
	init_blade(40);
	setup();
}
