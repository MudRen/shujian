// gold.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIY "�ƽ�" NOR, ({"gold", "gold_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "gold");
                set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
                set("unit", "Щ");
                set("base_value", 10000 );
		set("base_unit", "��");
		set("base_weight", 250);
        }
	set_amount(1);
}

int check_gold()
{
	object me = environment();
	object* inv;
	int limit;

	if (!me || !interactive(me) || !living(me))
		return 0;
	
	if(environment(me) && inv = all_inventory(environment(me)) )
	{
		for(limit=0;limit<sizeof(inv);limit++)
			if(objectp(inv[limit]) && inherits(F_BANKER,inv[limit])!=0) return 0;
	}
	
	if (!stringp(me->query_temp("user_type")))
		me->query_user_type();

	if (me->query("combat_exp") < 100000)
		limit = 100;
	else if (me->query_temp("user_type")=="worker")
		limit = 50 + me->query("combat_exp") / 666;
	else
		limit = 50 + me->query("combat_exp") / 1333;

	if( query_amount() > limit ) {
		set_amount(limit);
		return 1;
	}
	return 0;
}

void autoload(string param)
{
	int amt = atoi(param);

	set_amount(amt);
	check_gold();
}
