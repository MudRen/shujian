// Room: /city/bingqiku.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�Ĵ��ջ");
	set("long", @LONG
	������һ�������˵Ŀ�ջ�������˴�����������Ұ��������Ϣ֮����

LONG
	);
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }
