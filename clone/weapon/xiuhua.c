// ��
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("�廨��", ({ "xiuhua zhen", "zhen", "needle" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö�廨�õ�ϸ�롣\n");
		set("value", 200);
                set("needle", 1);
		set("material", "steel");
		set("wield_msg", "$N�����ִ�Ĵָ��ʳָ����һö�廨�롣\n");
		set("unwield_msg", "$N���廨�����廨���ܡ�\n");
	}
	init_sword(10);
	setup();
}