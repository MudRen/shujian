// OBJECT:  ice.c ����
// Created by Numa 1999-12-09

#include <ansi.h>
inherit ITEM;

string do_long();

void create()
{
	set_name(HIW"����"NOR,({"ice"}));
	set_weight(2000000);
//        if (clonep())
/*
        	set_default_object(__FILE__);
     	else
     	{
*/
        	set("unit", "��");
        	set("long", (: do_long :));
        	set("value", 500000);
        	set("no_get", 1); 
        	set("unique",1);
        	set("location",1);
        	set_temp("no_return",1);
//        }
     	setup();
}

string do_long()
{
	object me = this_player();
	object ob = this_object();
	
	if (!me->query_temp("ss/zsb_get"))
		return "����һ�麮��ɭɭ�����������о�Ө͸������˸�������Ĺ�â��\n";
	
    if (me->query("id") == ob->query_temp("find_by"))
	{
		me->delete_temp("ss/zsb_get");
		me->set_temp("ss/zsb_done",1);
		return "����һ�麮��ɭɭ�����������о�����һ�����ޣ��ƺ�������(po)��ȡ֮��\n";
	}

	me->delete_temp("ss/zsb_get");
	return "����һ�麮��ɭɭ�����������о���һ��������Ķ������ƺ�ȡ��������\n";	
}

void init()
{
	add_action("do_po","po");
}

int do_po(string arg)
{
	object me = this_player();
	object obj = this_object();
	object ob, *clone;
	int i, j;


	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (!me->query_temp("ss/zsb_done"))
		return notify_fail("��Ҫ��ʲô��\n");
		
	if (arg == "ice" || arg == "bing")
	{
		if (me->is_busy() || me->is_fighting())
			return notify_fail("����æ���أ�\n");
        if (me->query_temp("weapon"))
                return notify_fail("Ҫ�ƿ����������ƾ������������������������Ч�ɣ�\n");
		if (me->query_skill("hanbing-zhenqi",1) < 150)
		{
			tell_object(me,HIC"��������ƣ�������������նȥ������ȴ���������ƣ�һʱ��������ʹ��"NOR);
			me->apply_condition("cold_poison",50-random(me->query("kar")));
			me->unconcious();
			return 1;
		}
		message_vision(HIC"$N������ƣ�������������նȥ��ֻ����ž����һ����������ʱ�濪�����г���Ҳ���˳�����\n"NOR,me);
        call_out("dest",1,obj);
		me->delete_temp("ss");
        ob = unew(BINGQI_D("zisong-bian"));
       		if(!clonep(ob))
       		{
       			ob = new(BINGQI_D("whip"));
       			tell_object(me,HIR"����𳤱ޣ����־�Ȼֻ��һ����ͨ�ĳ��ޣ���ʧ�����ˡ�\n"NOR);
       			ob->move(me);
       			return 1;
       		}
	       	i = ob->query("unique");
       		clone = filter_array(children(base_name(ob)), (: clonep :));
        	j = sizeof(clone);
        	while (j--)
        		if (!clone[j]->query("clone_by_wizard"))
        			i--; 
       		if(clonep(ob) && i < 0)
       		{
        		destruct(ob);
       			ob = new(BINGQI_D("whip"));
       			tell_object(me,HIR"����𳤱ޣ����־�Ȼֻ��һ����ͨ�ĳ��ޣ���ʧ�����ˡ�\n"NOR);
       			ob->move(me);
       			return 1;
       		}

		tell_object(me,HIR"����𳤱ޣ����־�Ȼ�ǵ˰˹�������ʹ���������ɱޣ���ʱ��ϲ����\n"NOR);		
		ob->move(me);
		return 1;
	}
	else
		return notify_fail("��Ҫ��ʲô��\n");
}

void dest(object ob)
{
        destruct(ob);
}
