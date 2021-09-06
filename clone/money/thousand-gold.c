// thousand.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY "ҼǪ����Ʊ" NOR, ({"thousand-gold", "thousand-gold_money", "cash"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "thousand-cash");
                set("long", "һ�����ֵһǧ���ƽ�Ľ�Ʊ��һƱ���֣��ԺȲ��\n");
                set("unit", "��");
                set("base_value", 10000000);
                set("base_unit", "��");
                set("base_weight", 5);
//                set("no_get", 1);
//                set("no_drop", 1);
        }
        set_amount(1);
}

int check_cash()
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
                limit = 10;
        else if (me->query_temp("user_type")=="worker")
                limit = 5 + me->query("combat_exp") / 6666;
        else
                limit = 5 + me->query("combat_exp") / 13333;

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
        check_cash();
}
