// /d/xiangyang/outwroad1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ǰ�治Զ������
һЩС���֣���������С·ͨ���������
LONG
	);
        set("outdoors", "����");
        set("xyjob", 1);
	set("exits", ([
		"northdown" : __DIR__"shanlu1",
		"southwest" : __DIR__"shanlu3",
	]));

	setup();
}

