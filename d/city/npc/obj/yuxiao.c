// yuxiao.c ����

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({"yu xiao", "xiao"}));
	set_weight(250);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit", "֧");
		set("value", 2000);
		set("material", "gem");
                set("rigidity", 1);
                set("sharpness", 1);
		set("long","����һ֧����������������������������࣬���˰������֡�\n");
		set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
		set("unwield_msg","$Nһ����Х����$n������䡣\n");
	}
	init_sword(25);
	setup();
}
