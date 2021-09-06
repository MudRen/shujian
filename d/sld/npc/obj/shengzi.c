
#include <ansi.h>

inherit ITEM;

 void create()
{
	set_name("������",({"cu shengzi","shengzi"}));
	set_weight(500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",1000);
		set("long","һ�����鲼��ɵ����ӡ�\n");
	}
	setup();
}

void init()
{
	add_action("do_bang","bang");
}

int do_bang(string arg)
{
	object wood,raft;

	if( !arg || arg=="" ) return 0;
	if( arg=="mu" || arg== "mu tou") {
		if(wood=present("mu tou", environment(this_player()))) {
			if (! environment(this_player())->query("sld_boat"))
				return notify_fail("����Ͱ�Ļ������̫Զ�˰ɣ�\n");
			if(raft=present("mufa", environment(this_player())))
				tell_object(this_player(),"�������ô����ӽ�������ľͷ����һ��...\n");
			else {
				message_vision("ֻ��$N�ô����ӽ�������ľͷ����һ��...\n" NOR,this_player());
				message_vision("��һ���һ��Сľ����$N�����ˡ�\n" NOR,this_player());
				message_vision("$N��ʣ�µ����ӷŽ��˻��\n" NOR,this_player());
				raft = new(__DIR__"mufa");
				raft->move(environment(this_player()));
				destruct(wood);
			}
			return 1;
		}
		return notify_fail("��Ҫ��ʲô��\n");
	}
	return 0;
}
