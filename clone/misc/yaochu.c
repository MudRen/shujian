// OBJ : /d/wudang/yaochu.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(YEL"ҩ��"NOR, ({ "yao chu", "chu" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ��ҩ�õĳ�ͷ��\n");
		set("value", 30);
		set("wudang", 1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(4);
	setup();
}
