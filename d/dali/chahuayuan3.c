// Room: /dali/chahuayuan3.c
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
              "northwest" : __DIR__"chahuayuan4",
              "northeast" : __DIR__"chahuayuan5",
              "southdown" : __DIR__"chahuayuan2",
	]));
        set("outdoors","����");
        set("objects", ([
              __DIR__"obj/chahua3" : 1,
        ]));
        set("coor/x",-280);
  set("coor/y",-420);
   set("coor/z",0);
   setup();

}

