// /d/xingxiu/silk1.c
// June 97
// by pishou

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺��������������Ϲ����ɽͨ�������أ���
��������Ħ�¡�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "westup" : __DIR__"silk3",
                "south" : __DIR__"silk1",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        set("coor/x",-240);
  set("coor/y",90);
   set("coor/z",-10);
   set("coor/x",-240);
  set("coor/y",90);
   set("coor/z",-10);
   set("coor/x",-240);
 set("coor/y",90);
   set("coor/z",-10);
   setup();
}

#include "/d/xingxiu/job2.h";