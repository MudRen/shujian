// Room: /d/chengdu/chenggenlu3.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǳɶ�������ǽ����һ��С·��С·�������߲�Զ���۶��������ڶ���
�߲�Զ���۶����ϡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"northwest" : __DIR__"cgenlu2",
		"southeast" : __DIR__"cgenlu4",
	]));
	set("incity",1);
	setup();
}
