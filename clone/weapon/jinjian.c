// ��ذ��.c
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name(HIY"��ذ��"NOR, ({ "jin bishou", "dagger", "bishou" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����������ذ�ף�����ȥ���������\n");
		set("value", 10000);
		set("material", "gold");
		set("wield_msg", "$N������Ϣ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Ż����䡣\n");
	}
	init_dagger(40);
	setup();
}
