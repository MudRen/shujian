// /u/beyond/mr/jiabi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"�б�"NOR);
	set("long",@long
������ܺ����һ���бڣ�Ҫ�����ƿ���ܵĺ��档���п��ܳ�ȥ��
long);
	set("exits",([
             "north" : __DIR__"hssg",
	]));
	setup();
}

void init()
{
	add_action("do_push", "push");

}

int do_push(string arg)
{
	object me;
	me = this_player();

	if (arg !="shujia") 
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg=="shujia"){
		write("������һ����ܣ����������һ�ơ�\n");
		message("vision", me->name() + "����һ��ͻȻ�����ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"shufang");
		message("vision", me->name() + "���˹�����\n", environment(me), ({me}) );
	}
	return 1;
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	object *obj;
     
	myfam = (mapping)me->query("family");
     
	if ( myfam && myfam["family_name"] != "����Ľ��" &&dir=="north") {
		return notify_fail("һλĽ�ݼҶ���Ȼ�����������˳�������ס����˵�����ô���ʩˮ����������\n˵�꣬��λ�Ҷ�����һ�Σ����˻ذ�����\n");
	}
     
	obj = filter_array(deep_inventory(me),(:get_object:));
	if( sizeof(obj) && dir=="north" ){
		tell_object(me,"��һ��С�ģ����ż����ˡ�\n");
		obj[0]->move(environment(me));
		me->unconcious();
		return 0;
	}
	return ::valid_leave(me, dir);
}
