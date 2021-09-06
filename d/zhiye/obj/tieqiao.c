// tieqiao.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void set_status(int i);
int query_status();

void create()
{
	set_name("����", ({ "tieqiao", "tie qiao", "qiao" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����¡�\n");
		set("olong", "����һ�����¡����������ɿ�(caikuang)��\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N����һ��$n��\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
		set("worker_tool",1);
	}
	set("used",75);
	set("oused",75);
	init_staff(20);
	set_status(75);
	set("stime",time());
	setup();
}

void init()
{
	add_action("do_find","xunzhao");
	add_action("do_find","find");
	add_action("do_find","caikuang");
}

void set_status(int i)
{
	int j;
	j = (int)(i*100/query("oused"));
	if(j>90) set("long",query("olong")+"������������õġ�\n");
	else if(j>50) set("long",query("olong")+"�������Ѿ��ù�һ��ʱ���ˡ�\n");
	else if(j>20) set("long",query("olong")+"�������Ѿ���Щ�����ˡ�\n");
	else if(j>0) set("long",query("olong")+"��������Ҫ���ˡ�\n");
	else set("long",query("olong")+"�������Ѿ������ˡ�\n");
	set("used",i);
}

int query_status()
{
	return query("used");
}

void use()
{
	object me = environment(this_object());
	if( query_status()<=0 ) return;
	if( query_status()>2 && (time()-query("stime"))>7200 ) {
		tell_object(me,"���"+query("name")+"�ƺ���Щ�����ˣ�\n");
		set_status(2);
	}
	set_status(query_status()-1);
	if( query_status()<=0 ) {
		if( objectp(me) && userp(me) )
			tell_object(me,"���"+query("name")+"�����ˣ�\n");
		broken("������");
	}
}

int do_find(string arg)
{
	object me = this_player() , room , weapon;
	int delay;

	if(arg!="kuangshi") return 0;
	if( !(int)me->query("worker/job1") ) return 0;
	if( !objectp(weapon=me->query_temp("weapon")) || weapon!=this_object() ) return 0;
	if( me->is_busy() ) return notify_fail("����æ���أ�\n");

	message_vision(HIY"$N��ϸ��������ʯ���ټ�......\n\n"NOR, me);

	room = environment(me);
	if( me->query("worker/job1_room") != base_name(room) ) {
		message_vision(HIY"��ϧʲô��û���ҵ���\n"NOR, me);
		me->start_busy(1+random(3));
	}
	else {
		message_vision(HIY"�ƺ���������.....\n"NOR, me);
		delay = 10+random(20);
		if(wizardp(me) && me->query("env/test")) delay=3;
		me->start_busy(delay);
		call_out("find_finish",delay,me);
	}

	return 1;
}

void find_finish(object me)
{
	object obj;

	if( !objectp(me) || !userp(me) ) return;

	message_vision(MAG"$N�������ڳ�һ�����û�м����Ŀ�ʯ��\n"NOR, me);

	me->set("worker/job1_room","");
	obj = new(__DIR__"kuangshi");
	if(!obj) return;
	obj->set_level(11);
	obj->set("findby",me->query("id"));
	if( !obj->move(me) ) destruct(obj);
	use();
}
