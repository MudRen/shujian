// Room: /u/qingyun/mingjiao/baota0.c
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"����һ¥"NOR);
	set("long", @LONG
�����ǹ���������һ¥���������Ĵ󣬵��ϵ��˴��Ѳ������ϣ���Ϊ�ɴ�
����ȥ��¥���Ͻ��Ծ�ľ��ɣ��ƺ�ֻ�Ǽ򵥵Ĵ������ܵ���ש�ϣ���������
�ߣ��˼򵥵Ĵ���������ֳ���ʱ�ĸ߳���������������վ��һ¥��������
�������Ƹߣ��ڴ����ѿ��Կ��������������ľ�ɫ��
LONG);
	set("exits", ([ 
             "out" : __DIR__"baota",
        ]));
	set("coor/x",-290);
  set("coor/y",240);
   set("coor/z",150);
   set("coor/x",-290);
 set("coor/y",240);
   set("coor/z",150);
   setup();
}
