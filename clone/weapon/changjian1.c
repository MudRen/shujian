// longsword.c ����
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("����", ({ "changjian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�ľ��ֽ������ǽ��Ϸ������׵����⡣\n");
		set("value", 1500);
                set("rigidity", 1);
                set("material", "steel");
                set("poisoned", "man_poison");
                set("poison_number", 300);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(30);
	setup();
}

 