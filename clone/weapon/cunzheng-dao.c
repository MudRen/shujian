// gangdao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    	set_name(WHT"��������"NOR, ({ "cunzheng yaodao", "yaodao", "blade", "cunzheng", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����ձ����е����������Է�ɣ��ʦ����֮�֡�\n");
		set("value", 1000);
		set("rigidity", 5);
                set("sharpness", 5);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 3);
                set("treasure",1);       
		set("material", "steel");
		set("wield_msg", "$N�����س�$n��������һ�������Ĺ⻪��\n");
		set("unwield_msg", "$N�����������$n��ص��ʡ�\n");
	}
	init_blade(60);
	setup();
}
