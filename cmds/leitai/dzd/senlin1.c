//ROOM: /d/dzd/senlin1.c

#include <ansi.h>

inherit __DIR__"dzd_room";

void create()
{
	set("short","��ɭ��");
	set("long",@LONG
����һƬһ���޼ʡ���������ԭʼɭ�֣����˺ϱ��Ĵ������滨��ݾ�Ŀ���ǡ�
��ľ���Ӵ���һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ���һ
�߽�������������ɭ�ֵģ��ƺ�˭���۾���ע�����㣬��ĸо������㣬�øϿ��뿪��
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"senlin2",
		"west" : __DIR__"xiliu2",
		"south" : __DIR__"shulin1",
		"northeast" : __DIR__"senlin4",
		"southeast" : __DIR__"shulin2",		
	]));
	set("objects",([
		__DIR__"npc/tiger" : 1,
	]));
	setup();
}
















	