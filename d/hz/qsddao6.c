// /u/beyond/hz/qsddao4.c ��ʯ���
 
inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡���Ҳ���²����ؼ����ں��ݹ��������ķ羰���������������¥��
������һ�����á�
LONG
        );
set("outdoors","hz");
        set("exits", ([
            "south" : __DIR__"qsddao5",
            "west" : __DIR__"jiulou",
            "east" : __DIR__"shuyuan",
"north" : __DIR__"beimen",
            
]));
        set("coor/x",100);
  set("coor/y",-320);
   set("coor/z",0);
   setup();
}
