// /d/xingxiu/silk1.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", GRN"���ɽ"NOR);
        set("long", @LONG
����������ţ������Ƹߣ�ɽ��εض���ֱ�����졣ɽ��ƽ��ǧĶ����
��������������ģ������ºͣ�Ȫˮ�࣬ʤ����ɽ�����ʯɫ���죬��ˮ����
ǿ����������С�����ܡ�ԶԶ���Կ������ϱ���һ����ΰ�Ĺذ���
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk",
                "north" : __DIR__"silk2",
                "southwest" : __DIR__"silk1a",
        ]));

        set("coor/x",-240);
  set("coor/y",80);
   set("coor/z",-10);
   set("coor/x",-240);
  set("coor/y",80);
   set("coor/z",-10);
   set("coor/x",-240);
 set("coor/y",80);
   set("coor/z",-10);
   setup();
}

#include "/d/xingxiu/job2.h";