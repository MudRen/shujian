// /d/xingxiu/silk5a.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", BRED"��֬ɽ"NOR);
        set("long", @LONG
��֬ɽ��ɽʯ��������֬������������ˮ�ݷ�����������������ѩ�ڻ���
�����������£��㼯������ɽ���̲��������Ӫ�ݳ�̲���Ǿø�ʢ����������
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "southdown" : __DIR__"silk5",
                "southeast" : __DIR__"silk4",
                "northwest" : __DIR__"silk7a",
        ]));

        set("coor/x",-270);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-270);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-270);
 set("coor/y",100);
   set("coor/z",0);
   setup();
        set("yushi_count", 1);
}
#include "/d/xingxiu/job2.h";
