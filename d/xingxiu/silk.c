// /d/xingxiu/silk.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�����������������һ����ΰ�Ĺذ�������
��ͨ������
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"jygw",
                "northwest" : __DIR__"silk1",
                "southwest" : __DIR__"silk1b",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        set("coor/x",-230);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-230);
  set("coor/y",70);
   set("coor/z",-10);
   set("coor/x",-230);
 set("coor/y",70);
   set("coor/z",-10);
   setup();
}

#include "/d/xingxiu/job2.h";