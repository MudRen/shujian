// Room: /dali/chahuayuan4.c
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
		"southeast" : __DIR__"chyuan3",
        ]));
        set("outdoors","����");
        set("objects", ([
             __DIR__"obj/chahua4" : 1,
        ]));
	setup();
}
