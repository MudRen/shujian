 // zhaitang.c ի��

#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIG"ի��"NOR);
        set("long",@LONG 
�����������������ż��ﳤ�����Ӻ͵��ӣ�һ����ʳ�������������ԭ
�������Ǵ����µ�ի�ã����ڲ��ǳԷ���ʱ�䣬������յ����ģ�ֻ�м�����
�������е�����ʰ���ӣ��е���ɨ�أ�һ�п�������������
LONG);
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("exits",([
                "northwest" : __DIR__"rimulundian",
                "north" : __DIR__"chufang"
        ]));
        set("objects", ([__DIR__"npc/zayilama1" : 1,]));
        setup(); 
}

int valid_leave(object me, string dir)
{
	if ((dir == "northwest")
	 && present("suyou cha", this_player())
	 && objectp(present("zayi lama", environment(me))) )
	switch ( random(2)) {
		case 0:
			message_vision("��������������ס��$N�������ż��������ȰѶ������������߰ɡ���", me);
			return notify_fail("\n");
			break;
		case 1:
			message_vision("����������ס$N��������׼���Դ��ã����б���û�Է��ء���", me);
			return notify_fail("\n");
			break;
	}
	return ::valid_leave(me, dir);
}
