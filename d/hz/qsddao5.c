// /u/beyond/hz/qsddao4.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡���Ҳ���²����ؼ����ں��ݹ��������ķ羰������������ӻ��̣�
������Ǻ��ݳ����һ��ҩ�̡�
LONG
        );
set("outdoors","hz");
        set("exits", ([
"south" : __DIR__"qsddao4",
            "west" : __DIR__"zahuopu",
            "east" : __DIR__"yaopu",
            "north" : __DIR__"qsddao6",
            
]));
        set("coor/x",100);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}
