// /d/mr/kongfang.c
// by leontt 2000/10/18

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW"�շ���"NOR);
	set("long", @LONG
��������ߵ���һ���շ��������ʲô��û�У���ʱ��������������
�����㲻�ɵĴ���һ�������
LONG);
	set("exits", ([             
		"west" : __DIR__"migong2",
	]));
	setup();
} 

