// ��
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name(HIW "��������" NOR, ({ "bingpo shenzhen", "zhen", "needle", "shenzhen" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö͸����ϸ�룬��ɢ������������һ����֪������ι�о綾��\n");
		set("value", 2000);
		set("rigidity", 1);
		set("material", "steel");
		set("unique", 2);
		set("needle", 1);
		set("weapon_prop/dodge", 2);
		set("wield_msg", "$N��ɳֽ����������һö$n��\n");
		set("unwield_msg", "$N��$n��ɰֽ���������ػػ��С�\n");		
		set("treasure", 1);
		set("poisoned", "bing_poison");
		set("poison_number", 300);
	}
	init_sword(45);
	setup();
}
