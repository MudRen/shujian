// coin.c
#include <ansi.h>
#include <weapon.h>

inherit MONEY;
inherit THROWING;

void create()
{
	set_name(YEL "ͭǮ" NOR, ({"coin", "coins", "coin_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����ͭǮ��ֵ��һ��������\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 5);
	}
	set_amount(1);
	init_throwing(1);
}

void autoload(string param)
{
	int amt = atoi(param);

	set_amount(amt);
}
