// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(HIM"������"NOR, ({ "tulong dao","tulong","dao", "blade" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("rigidity", 10);
		set("sharpness", 9);
		set("long", "����һ�ѻ����ڵ������������м�������Ѫ��������������ƥ��\n"+
			    "���꽭������Ϊ�˵���ƴ�������һ�ǵ���֮����\n");
		set("value", 1);
		set("unique", 1);
		set("weapon_prop/parry", 9);
		set("material", "steel"); 
		set("wield_neili", 1500);
		set("wield_maxneili", 2000);
		set("wield_str", 30);
		set("wield_msg", HIM"ֻ���ڹ�һ����$N����������һ�Ѻڳ����Ĵ󵶣����Ǻųơ��������𡱵ı���������\n"NOR);
		set("unwield_msg", HIM"�ڹ����$nԾ��$N���С�\n"NOR);
		set("treasure",1);
	}
	init_blade(200);
	setup();
	use_flag = 16;
}
