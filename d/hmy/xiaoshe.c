// /d/hmy/xiaoshe.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С��");
	set("long", @LONG
һ���ţ����ŵ�һ��Ũ�һ��㣬ֻ�����й���һ����Ůͼ��ͼ�л�������
��Ů������һ����ױ̨��̨��һ�������������廨���档�������ڻ��Ž��أ�
֬��Ũ���˱ǣ�Ӧ���Ǽ�Ů�ӵĹ뷿��
LONG
	);
	set("exits", ([
		"east" : __DIR__"xhuayuan",
	]));
	set("objects", ([ 
		__DIR__"npc/dongfang" : 1,
	]));
	setup();
}
