// Room: /u/dubei/wudang/hsxl5
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "С·");
	set("long", @LONG
����һ���˼������ɽ´�����ܹ�ľïʢ����ʱ��Ұ�޵ĳ�û��ż����һ
Щ��ҩ��������Ѱ��һЩϡ�еĲ�ҩ��
LONG	);
	set("exits", ([ 
                 "southup" : __DIR__"hsxl4",
                 "northwest" : "/d/wudang/shanlu2",
])); 
        set("objects", ([
//   __DIR__"npc/she" : 1,
	]));
          set("outdoors", "�䵱");
	  set("coor/x",-20);
  set("coor/y",-60);
   set("coor/z",90);
   setup();

}
 
