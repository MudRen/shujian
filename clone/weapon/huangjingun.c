// huangjingun.c �ƽ��

#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
	set_name(HIY "�ƽ��" NOR, ({ "huangjin gun","gun" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("unique", 1);
		set("treasure", 1);
		set("long", "���������߳ߣ���һ���а룬ͨ��ƽ����ɡ�\n");
		set("value", 50000);
		set("material", "steel");
		set("wield_msg", "$N��$nһ�����������У�˳�ֶ�������𻨣�ֻ�����ҫ�ۡ�\n");
		set("unwield_msg", "$N�������е�$n������Ȼ��ʧ������\n");
	}
	init_club(80);
	setup();
}
