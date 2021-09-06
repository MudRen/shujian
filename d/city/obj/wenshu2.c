#include <ansi.h>;

inherit ITEM;

string wanted();
int do_arrest(string);

void create()
{
        set_name(HIY"�ٸ�����"NOR, ({ "guanfu wenshu", "wenshu", }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_drop", 1);
                set("material", "paper");
        }
        set("long", wanted());
        setup();
}

void init()
{
        add_action("do_arrest","arrest");
        add_action("do_arrest","jubu");
}

int sort_killer(object obj)
{
	if ( SECURITY_D->get_status(obj) != "(player)" ) return 0;
        if ( (int)obj->query("PKS") < 50 ) return 0;
        if ( obj->query("combat_exp") / obj->query("PKS") > 350000 ) return 0;
        if ( base_name(environment(obj)) == "/d/city/dalao") return 0;
	return 1;
}

int sort_pks(object ob, object obj)
{
	if ( ob->query("PKS") < obj->query("PKS") ) return 0;
        return 1;
}

string wanted()
{
        int i, age;
        string msg;
        object *ob = users();

        msg = "";
        ob  = filter_array( users(), (: sort_killer :) );
        ob  = sort_array(ob, (: sort_pks :));
        
        for (i = 0; i < sizeof(ob); i++){
        	msg += "\n��"+chinese_number(i+1)+"��"+ob[i]->short(1)+"\n";
                msg += HIR"\t���ӷ�";
                age = ob[i]->query("age");
                if (ob[i]->query_skill("beauty") > 30) age -= (ob[i]->query_skill("beauty")-30)/5;
                if (age < 10)
                	msg += "����������ʮ�꣬";
                else	msg += "������Լ"+chinese_number(age / 10 * 10)+"���꣬";
                msg += "������"+chinese_number(ob[i]->query("PKS"))+"׮������\n"NOR;
		msg += "\t���ӷ����տ���ȥ�ƺ�"+"/cmds/std/look"->gettof(ob[i], age)+"��ҪС�����⣡\n";
                msg += "������������������������������������������������������������\n";
        }
        if (msg == "")
                return "���ձ����ΰ����ã��޿���������롣\n";
        else
                return HIY"���ڱ����������ͼ���(arrest)����Ҫ����\n"NOR + msg;
}

int do_arrest(string arg)
{
        object me=this_player(), victim;

        if (!me->query_temp("mark/Ѳ��"))
        	return notify_fail("СС����Ҳ��в����ˣ�\n");

        if (!arg)
        	return notify_fail("��Ҫ�в�˭��\n");

        victim = present(arg,environment(me));

        if (!victim)
        	return notify_fail("���ﲢ�޴��ˣ�\n");

        if (victim == me) 
                return notify_fail("��ץ�Լ����αض��һ�٣�\n");

        if (!living(victim))
                return notify_fail("���۾�Ϲ�ˣ��ǿɲ��ǻ��\n");

        if (!(userp(victim)
                && victim->query("PKS")>50
                && victim->query("combat_exp")/victim->query("PKS") < 350000))
                return notify_fail("���˲����׷���\n");

        message_vision(HIC"$N��$n�ߺ�һ����"+RANK_D->query_rude(victim)+"�����ˣ��ҷ֮͢�������㣡�������־��ܣ���\n"NOR, me, victim);

        if (victim->is_fighting()) 
                victim->remove_all_killer();

        victim->kill_ob(me);
        me->fight_ob(victim);
        return 1;
}
