// /d/xingxiu/silk5.c
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����������ţ������ţ������������л�����û���׳��Ի�̨��ɽ��
����ǧ�𣬲Դ����Ρ������ͱ��޾����м�һ��С·������һ�����ա�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk4",
                "northwest" : __DIR__"silk6",
                "northup" : __DIR__"silk5a",
                "south" : __DIR__"silk5b",
        ]));

        set("coor/x",-270);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-270);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-270);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";