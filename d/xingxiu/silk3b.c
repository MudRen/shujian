// /d/xingxiu/silk3.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ������Ķ�Ѩ����������ʯѤ�����ˣ��������档��Ϭţ���¡���
�����졢����ƺ��������������������ݡ���ľ�ŵȣ�������ǧ������Ѱζ��
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk3a",
                "northwest" : __DIR__"silk3c",
        ]));

        set("coor/x",-260);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-260);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

#include "/d/xingxiu/job2.h";