// /d/dzd/obj/xsycw.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("�쾦���",({"zhujing bingchan","bingchan"}));
	set_weight(100);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","���ǲ�������ѩɽ������ҩ�ģ�ͨ��ѩ�ף���ֻ����ȴѪҲ��졣
�����ܳԣ���������(xidu)Ŷ��\n");
		set("value",10000);
		set("unit","ֻ");
		//set("no_drop",1);
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_eat","eat");
	add_action("do_eat","fu");
	add_action("do_eat","chi");
	add_action("do_xidu","xidu");
}

int do_eat(string arg)
{
	object me = this_player();	
	if(!arg || arg != "bingchan")
		return notify_fail("��Ҫ��ʲô��\n");
	if(me->query("qi")==me->query("max_qi") && me->query("jing")==me->query("max_jing"))
		return notify_fail("��û�³������ʲô��\n");		
	message_vision("$N����һֻ" + name() + ",���ƶ�ʱȫ�ã�\n",me);
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	destruct(this_object());
	return 1;
}	

int do_xidu(string arg)
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
		return notify_fail("���޷���ս�����˹�������\n");
		
	if( !mapp(ob->query_conditions_by_type("poison"))  )
	  return notify_fail(ob->query("name")+"��û���ж���\n");
	if(me==ob)
		message_vision(HIW"$N���������˿��ϣ����������˿ڣ���һ�ᣬͨ��ѩ�׵ı�󸽥����ûҺ�,$N���ڵĶ��ѱ������\n"NOR,me);
	else
		message_vision(HIW"$N��������$n�˿��ϣ����������˿ڣ���һ�ᣬͨ��ѩ�׵ı���������ûҺ�,$n���ڵĶ��ѱ������\n"NOR,me,ob);
		ob->clear_conditions_by_type("poison");
		me->start_busy(1);
		ob->start_busy(2);
		return 1;
}