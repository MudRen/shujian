// BY XIAOYAO

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ
��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ��
������ԥ��ǰ���ĽŲ���
LONG );
	set("exits", ([
		"east"  : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"southwest" : "/d/zhiye/caikuang-chang0",
	]));
	set("objects", ([
                __DIR__"npc/wolf" : 1,
	]));
	set("outdoors", "�ƺ�");
	
	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest") && dir == "southwest" ){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
