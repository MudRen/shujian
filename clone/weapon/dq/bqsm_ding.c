// sanmending.c ɥ�Ŷ�
// cck 17/6/97

#include <weapon.h>
inherit THROWING;
inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
	set_name(GRN"ɥ�Ŷ�"NOR, ({ "sangmen ding", "ding" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ɥ�Ŷ����ƺ�ι���ǡ������޻����Ķ�֭��\n");
		set("value", 50000);
		set("no_sell", 1);
		set("material", "steel");
		set("wield_msg", "$Nץ��һ��ɥ�Ŷ��������ġ�\n");
		set("unwield_msg", "$N�����е�ɥ�Ŷ��Ż�װ������Ƥ���\n");
		set("base_unit", "ö");
		set("damage", 50);
		set("embed", 1);
		set("base_weight", 50);
		set("poison", "qtlh_poi");
		set("poison_number", 6);
	}
	set_amount(10);
	init_throwing(50);
	setup();
}
