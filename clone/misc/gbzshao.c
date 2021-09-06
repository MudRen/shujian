//���� /clone/misc/gbzshao.c
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;

void create()
{
        seteuid(getuid());
	set_name(HIM"����"NOR, ({ "di zi"}) );
	set("long", HIM"����һ��ѵ���ߵĵ��ӡ�\n"NOR);
        set("unit","��");
        set("no_get", 1);
        set("no_drop", 1);
        set("material", "steel");
        set_weight(1);
        setup();
}

void init()
{
	object me=this_player();
	
	if (environment() != me) return;
	add_action("do_tame","tame");  //ѱ���Լ�����
	add_action("do_play","play");  //�����ߵ�����
	add_action("do_aggress","aggress"); //�����ߵ��ײ�
	add_action("do_ambush","fuji"); //�����߷���id
}

int query_autoload()
{
	return 1;
}

int do_tame(string arg)
{
	object me,snake;
	string msg;

	if (arg!="snake" && arg!="she")
		return notify_fail("��Ҫѱ��˭��\n");
		
	me = this_player();

	snake = present("snake",environment(me));

	if (!snake) return notify_fail("���������������������ܲ�û��ʲô�ߣ�\n");
	
	if (snake->query_temp("owner")==me->query("id")) return notify_fail("������Ѿ�ѱ���ˡ�\n");

	if (!me->query_temp("tame"))
	{
		switch (random(5))
		{
			case 0 : msg=HIY"$N����ǰȥ��С�����������һ��$n�����塣\n"NOR;break;
			case 1 : msg=HIR"$Nת��$n�ĺ��棬����������$n��β�͡�\n"NOR;break;
			case 2 : msg=HIG"$N���һֻ�֣��ƺ����$n�����֡�\n"NOR;break;
			case 3 : msg=HIM"$N���˫�֣���ס�Լ��ı��Ӻ��°ͣ�����$n����һ��������\n"NOR;break;
			case 4 : msg=HIB"$N����ǰȥ��������ס$n��β�͡�\n"NOR;break;
		}
		message_vision(msg,me,snake);
		if (random(20)==18)
		{
			me->set_temp("tame",1);
			message_vision("$N�������鲻���ˣ�$N����ͻȻ���˰�β�ͣ�Ȼ�����$N������������\n",me);
			snake->kill_ob(me);
			message_vision(HIR"������$N������ɱ��$N"NOR,me);
			return 0;
		}	
		else 
		{
			message_vision(BLU"$n����$Nһ�ۣ�ת��ͷȥ����$N��\n"NOR,me,snake);
			return 0;
		}
	}
	else
	{
		if (snake->is_fighting(me))
		{
			me->add_temp("tame",1);
			if (random(me->query_temp("tame",1))>=5 )
			{
				snake->remove_killer(me);
				me->remove_killer(snake);
				snake->set_leader(me);
				snake->set_temp("owner",me->query("id"));
				message_vision(HIY"ͻȻ$n���һ��������$N���ˣ�\n"NOR,me,snake);
				message_vision(HIM"$n����$N���£���β��������˲�$P�Ľţ�\n"NOR,me,snake);
				me->delete_temp("tame");
				me->set("snake/friendly",50);
				me->set("snake/aggress",50);
	                        return 1;
			}
			else 
			{
				message_vision(HIW"$N���һԾ����ͼ����սȦ������$n�ƺ���û�������˼����������$P��\n"NOR,me,snake);
				me->add("jingli",-10);
				me->add("qi",-10);
				me->start_busy(random(4));
				return 0;
			}
		}
		else return 0;
	}
}	

int do_play(string arg)
{
	object me,snake;
	
	if (!arg || arg!="snake" && arg!="diao")
		return notify_fail("��Ҫ��˭�棿\n");
	
	me = this_player();
	snake = present("snake",environment(me));
	
	if (!snake) return notify_fail("������������أ�\n");
	
	if (me->query("snake/aggress")>2) me->add("snake/aggress",-2);
	if (me->query("snake/friendly")<100) me->add("snake/friendly",1);
	
	message_vision(HIB"$N�ͳ����ӣ����ᴵ��������$N�����������������徹Ȼ���Ž���Ť��������\n"NOR,me);
	me->add("jingli",-50);
	me->start_busy(2);
	return 1;
}

int do_aggress(string arg)
{
	object me,snake,ji;
	
	if (!arg || arg!="snake" && arg!="diao")
		return notify_fail("��Ҫ��ʲô��\n");

	me = this_player();

	ji = present("gong ji",me);
	snake = present("snake",environment(me));
	
	if (!snake) return notify_fail("������أ�\n");
	if (!ji) return notify_fail("���ѵ���������񲻵�Ҫ�죡\n");

	if (random(10)>6 )
	{
		if (me->query("snake/aggress")>100) me->add("snake/aggress",1);
		if (me->query("snake/friendly")<2) me->add("snake/friendly",-2);
	
		message_vision(HIR"������$N���ϵ�$n���������¾ͳ��˸��ɸɾ�����\n"NOR,me,ji);
		destruct(snake);
		me->add("jingli",-50);
		me->start_busy(2);
	}
	else
		message_vision(HIR"������$N���߶�$n��̫����Ȥ��\n"NOR,me,ji);
	return 1;
}

int do_ambush(string arg)
{
	object ob,me,snake;
	
	if (!arg)
		return notify_fail("��Ҫ�߹���˭��\n");

	me = this_player();
	
	snake = present("snake",environment(me));
	
	if ( !snake || !snake && snake->query_temp("owner")!=me->query("id") ) return notify_fail("������أ�\n");
	
	if (arg==me->query("id")) return notify_fail("�㷢����ô�����Լ����߹����Լ���\n");
	
        ob =find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�������˺�����!\n");
	
	tell_object(me,HIR"��Ҫ����������׼��������Ϊ"+ob->query("name")+"���ˡ�\n"NOR);
	snake->set_temp("ambush",ob->query("id"));
	snake->set_leader(0);	
	return 1;
}
