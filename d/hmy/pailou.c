// /d/hmy/pailou.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"��¥"NOR);
	set("long", @LONG
��ǰһ��������ľ޴���¥����¥���ĸ����ɫ�֡��󱻲�������������
����⣬���ɵ�������Ȼ�𾴡�
LONG
	);
	set("exits", ([ 
	  "east" : __DIR__"xiangfang",
	  "north" : __DIR__"shibanlu",
	  "west" : __DIR__"yading",
	]));
	setup();
}
