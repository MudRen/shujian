// sanmending.c ɥ�Ŷ�
// cck 17/6/97

#include <weapon.h>
inherit THROWING;
inherit COMBINED_ITEM;
#include "/inherit/item/embed.h"

void create()
{
	set_name("ɥ�Ŷ�", ({ "sangmen ding", "ding" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һöɥ�Ŷ����ƺ�ι���ǡ������޻����Ķ�֭��\n");
		set("value", 1);
		set("no_sell", 1);
		set("material", "steel");
		set("wield_msg", "$Nץ��һ��ɥ�Ŷ��������ġ�\n");
		set("unwield_msg", "$N�����е�ɥ�Ŷ��Ż�װ������Ƥ���\n");
		set("base_unit", "ö");
		set("damage", 5);
		set("embed", 1);
		set("base_weight", 50);
		set("poison", "qtlh_poi");
		set("poison_number", 6);
	}
	set_amount(2);
	init_throwing(10);
	setup();
}
