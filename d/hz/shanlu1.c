 // /u/beyond/hz/shanlu1.c ɽ·
 
inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long", @LONG
������ɽ·�ϣ�ɽ·������ľ���̣����ﻰ�㣬ɽ·������һ��Ƭ����
�де����֡�
LONG
        );
set("outdoors","hz");
        set("exits", ([
        "east" : __DIR__"liulin",
        "west" : __DIR__"liulin",
        "northeast" : "/d/suzhou/qsgdao2",
        "south" : __DIR__"shanlu3",
        ]));
        set("coor/x",100);
  set("coor/y",-280);
   set("coor/z",0);
   setup();
}
