// /u/beyond/hz/qsddao4.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡���Ҳ���²����ؼ����ں��ݹ��������ķ羰�����������һ��Ǯׯ��
������Ǻ��ݳ�������ֺŵ��̡�
LONG
        );
set("outdoors","hz");
        set("exits", ([
            "south" : __DIR__"tianxiang",
            "west" : __DIR__"jinhuazhai",
            "east" : __DIR__"cuihezhai",
            "north" : __DIR__"qsddao5",
            
]));
        set("coor/x",100);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}
