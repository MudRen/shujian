// Room: /u/zqb/tiezhang/xzfeng.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", RED"Сָ��"NOR);
	set("long", @LONG
���ѵ�����Сָ��ķ嶥����ĿԶ��������Զ���ķ�����û��ŨŨ������
֮�С�����ĸ߶�ǡ������֮�У���ֻ�ܿ�����ǰ���׵ľ�������ģ����
�·��ѱ�ˮ����ʪ������Ϯ����������ɪɪ������
LONG
	);

	set("exits", ([
"southdown" : __DIR__"pubu",
]));

	set("no_clean_up", 0);

	set("coor/x",-360);
  set("coor/y",-190);
   set("coor/z",70);
   setup();
}
