// Room: /d/dali/ydxxx.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�۾�¥");
	set("long", @LONG
�۾�¥��ʯ�ڶ��죬������ջ�������ɡ����ա��۾�¥�����������ݡ���
�޺�Ĺ۾�¥�������ߣ������������������Զ��ﻨ���Լ���ʷ����Ϊ��壬
����д��ʷ����������ʣ��͹��ճ�һ����������������¥̨֮�����в��ҡ�
С���������˿�һ���ڴ˾�����Ϣ��һ�������Χ��⡣
LONG
	);
        set("outdoors", "����");

	set("objects", ([
		NPC_D("tiao-fu") : 1,
	]));

	set("exits", ([
		"west" : __DIR__"ydxx",
		"east" : __DIR__"ydxxxx",
	]));

	setup();
}
