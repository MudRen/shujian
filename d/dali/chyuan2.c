// Room: /dali/chahuayuan2.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"�軨԰"NOR);
      	set("long", @LONG
������һ��Сɽ���ϣ����ﵽ������ʢ�����ʻ������е��ۻ������ˣ���
�������⻨԰�У������泩��ࡣ 
LONG
       );
        set("exits", ([ 
              "northup" : __DIR__"chyuan3",
              "southdown" : __DIR__"chyuan",
	]));
        set("outdoors","����");
        set("objects", ([
             __DIR__"obj/chahua2" : 1,
        ]));
	setup(); 
}

int valid_leave(object me, string dir)
{
	if ( dir == "southdown" )
        me->delete_temp("flower_paid");
	return ::valid_leave(me, dir);
}
