// /d/xingxiu/silk4.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�������������������Ħ�£����������߱�
��
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "eastup" : __DIR__"silk3",
                "west" : __DIR__"silk5",
                "northwest" : __DIR__"silk5a",
        ]));

        set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));

        set("coor/x",-260);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-260);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-260);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";