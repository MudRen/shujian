// Room: /d/huashan/yaofang.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
�����ǻ�ɽ�ɵ���������ҩ�ĵط����������ӵ�ͷæµ�ţ����л�ɽ���
����ҩ�Գ��ڴ˴���
LONG
        );
        set("exits",([
        	"north" : __DIR__"lianwu1",
        	"south" : __DIR__"fanting",
	]));

        set("indoors", "��ɽ" );
        set("coor/x",60);
  set("coor/y",-20);
   set("coor/z",80);
   setup();
}
