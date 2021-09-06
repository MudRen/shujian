// yaozhong.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "ҩ��" NOR, ({"yao zhong","zhong zi","zhong" })); 
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "����һö������(zhong)��ҩ�����ҩ�֣�");
		set("unit", "ö");
		set("no_sell",1);
		set("5type","��");
		set("location",1);
		//set("8type","Ǭ");
	}
}

void init()
{
	add_action("do_zhong","zhong");
}

int do_zhong(string arg)
{
	object ob,obj;
	object me=this_player();
	object room;

	if(!arg || !objectp(ob=present(arg, me)) || (ob!=this_object()))
		return notify_fail("��Ҫ��ʲô��\n");
	if(!objectp(room=environment(me)) || (room->query("can_zhong")!=1))
		return notify_fail("�㲻����������ҩ��\n");
	if(!objectp(obj=new(__DIR__"yaomiao")))
		return notify_fail("�����ڲ�����ҩ����һ�����ְɡ�\n");
	obj->set("5type",ob->query("5type"));
	obj->set("8type",room->query("8type"));
	obj->set("long",obj->query("long")+obj->query("8type")+obj->query("5type")+"�ԡ�\n");
	obj->set("stime",uptime());
	obj->set("jtime",uptime());
	obj->set("name","��С��ҩ��");
	obj->move(room);
	message_vision("$N��һöҩ�����������һưˮ�������أ������ﳤ����һ�����硣\n",me);
	call_out("destructing", 1, ob); 
	return 1;
}

void destructing(object ob)
{
	destruct(ob);
}