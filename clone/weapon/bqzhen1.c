// ��

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIB "������" NOR, ({ "lanyu duzhen", "zhen", "needle", "duzhen" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö��ӨӨ��ϸ�룬ͨ�徧Ө��ż����һ˿�����ζ����ƺ�ι�о綾��\n");
                set("value", 80000);
//                 set("unique", 2);
                set("needle", 1);
		  set("no_sell", 1);
		  set("material", "steel");
                set("weapon_prop/dodge", 2);
		  set("wield_msg", "$N��ɳֽ����������һö$n��\n");
		  set("unwield_msg", "$N��$n��ɰֽ���������ػػ��С�\n");
                set("poisoned", "xx_poison");
                set("poison_number", 300);
 //               set("treasure", 1);
	}
        init_sword(50);
	setup();
}
