//  /d/hmy/qinglongtang.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"������"NOR);
	set("long", @LONG
����������ʽ���̾ߣ���΢�������֮�£�ɢ���ű���ĺ��⣬����Խ
��Խ�����з�ë����������֮�����ֲ�״������ҵĽ��������и��е�һ��
����
LONG
	);
	set("exits", ([ 
	  "east" : __DIR__"changlang2",
	]));
        set("objects", ([ 
          __DIR__"npc/shang" : 1,
	]));
	setup();
}
