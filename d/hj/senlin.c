// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","��Ҷ��");
        set("long", @LONG
���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ����
�롣��������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ����������
�������߱��Ǵ��ԭ�������ڵĹ��������������������
LONG
       );

        set("exits", ([
                "northwest" : "/d/xingxiu/tianshan",
                "northeast" : "/d/xingxiu/shanjiao",
                "southeast" : __DIR__"shanqiu",
                "southwest" : "d/xiaoyao/xiaodao4",
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "��ɽ");

        set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
