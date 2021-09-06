// dujing.c ����

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����",({"wangnangu dujing","dujing","jing"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
        	set("unit", "��");
        	set("long","����һ����д�ĳ�������ǩ��д�š����ѹö��������֡���������,��ҳ������ӬͷС�������������д��
��㶾��Ķ��ԡ�ʹ�úͻ���֮����������������(qudu)���¶�(xiadu)���£����ż��˰�?\n");
        	set("value", 10000);
        	set("material", "paper");
       //	set("unique", 1);
        	//set("treasure",1);
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_qudu","qudu");
	add_action("do_xiadu","xiadu");
}

int do_qudu(string arg)
{
	object ob;
	object me = this_player();
	if(!arg) ob = this_player();
	else 
		{
			if(!objectp(ob = present(arg, environment(me))))
				return notify_fail("��Ҫ��˭������\n");
			if (!ob->is_character() || ob->is_corpse())
				return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
		}
	if( ob->is_fighting() )
		return notify_fail("���޷���ս�����˹��ƶ���\n");
		
	if( !mapp(ob->query_conditions_by_type("poison"))  )
	  return notify_fail(ob->query("name")+"��û���ж���\n");
	if(me==ob) 
		message_vision(HIW"$N�����ڵأ����վ����еķ����������Ľ����ڵĶ��������⡣\n"NOR,me);
	else
		message_vision(HIW"$N�����ڵأ����վ����еķ����������Ľ�$n���ڵĶ��������⡣\n"NOR,me,ob);
		//nomask mapping query_conditions_by_type(string required_type)
		//nomask void clear_conditions_by_type(string required_type)
		ob->clear_conditions_by_type("poison");		
		me->start_busy(1);
		ob->start_busy(2);
		return 1;			
}

int do_xiadu(string arg)
{
	object ob;
	object me = this_player();
	
	if( me->is_busy()) return notify_fail("��������æ���ء�\n");	
	if(me->query_temp("dzd_quest/used_dujing"))	
		return notify_fail("���Ѿ��¶��ˡ�\n");	
	if(!arg)
		return notify_fail("��Ҫ��˭�¶���\n");
	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("��Ҫ��˭�¶���\n");	
	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
				
	me->set_temp("dzd_quest/used_dujing",1);
	remove_call_out("out_xiadu");
	call_out("out_xiadu",10,me);
	message_vision(HIB"$N�ٺ�һЦ������������˵���Ƴ����Ķ���͵͵��$n��ȥ��\n"NOR,me,ob);
	if(random(4)) {
		message_vision(HIY"$Nһʱ���죬�Ѿ����о綾��\n"NOR,ob);
		ob->add_condition("snake_poison",20);		
	}
	else 
		message_vision(HIY"˭֪$N����׼�����������˰��㣡\n"NOR,ob);
	me->start_busy(1);
	return 1;
}

void out_xiadu(object me)
{
	if(!me) return;
	me->delete_temp("dzd_quest/used_dujing");
}