// ��

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name(BLU "������" NOR, ({ "lanyu duzhen", "zhen", "needle", "duzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö��ͨ��ϸ�룬�����������ɫ�Ĺ�����ι�о綾��\n");
                set("value", 100000);
                set("unique", 2);
                set("needle", 1);
		set("material", "steel");
                set("weapon_prop/dodge", 2);
		set("wield_msg", "$N��ɳֽ����������һö$n��\n");
		set("unwield_msg", "$N��$n��ɰֽ���������ػػ��С�\n");
                set("poisoned", "xx_poison");
                set("poison_number", 300);
                set("treasure", 1);
	}
        init_sword(45);
	setup();
}
