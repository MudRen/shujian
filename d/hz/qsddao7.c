// /u/beyond/hz/qsddao4.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡�Զ�����Ǻ��ݳ��ˣ���Ҳ�����ӿ�Ų������ݱ���չ���������ǰ��
LONG
        );
set("outdoors","hz");
        set("exits", ([
            "south" : __DIR__"beimen",
            "north" : __DIR__"shanlu3",
            
]));
        set("coor/x",100);
  set("coor/y",-300);
   set("coor/z",0);

   setup();
}
