// Room: /d/tianshan/shanjian.c
// By Ciwei@SJ

#include <ansi.h>
inherit ROOM;

string long();

mapping dirs = ([
	"west":"����",
	"westdown":"���·�",
	"westup":"���Ϸ�",
	"east":"����",
	"eastdown":"���·�",
	"eastup":"���Ϸ�",
	"south":"�Ϸ�",
	"southdown":"���·�",
	"southup":"���Ϸ�",
	"north":"����",
	"northdown":"���·�",
	"northup":"���Ϸ�",
	"northeast":"������",
	"northwest":"������",
	"southeast":"���Ϸ�",
	"southwest":"���Ϸ�",
]);

void create()
{
        set("short", "ɽ��");
        set("long", (:long:) );
         foreach (string dir in keys(dirs))
         	set("exits/"+dir,__DIR__"shanjian");

        set("outdoors", "��ɽ");
        setup();
}

void init()
{
	object me = this_player();
	if(!me->query_temp("shanjian_dir"))
		me->set_temp("shanjian_dir",keys(dirs)[random(sizeof(keys(dirs)))]);
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("shanjian_dir")==dir)
	{
		tell_object(me,"��첽�߳���ɽ����\n");
		me->move(__DIR__"longtan");
		tell_room(environment(me),me->name()+"�첽���˹�����\n",({me}) );
		me->delete_temp("shanjian_dir");
		return notify_fail("����ǰͻȻһ�������־�Ȼ����һ����Ϊ�޴��ˮ̶�ߡ�\n");
	}
	return ::valid_leave(me,dir);
}

string long()
{
	object me = this_player();
	string str ="������ɽ���һ��ɽ�����Ա������������ɽȪ�������³���γɵ�һ��\n�����ˮ̶��������Χ�����˹�ľ";
	if(me && me->query_temp("shanjian_dir"))
		return str+"��"+dirs[me->query_temp("shanjian_dir")]+"�ƺ����߹�ȥ���㲻�ɵļӿ��˲�����\n";
	return str+"��\n";
}
