// /d/xiangyang/outwroad1.c

inherit ROOM;
void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ż����������������
����Ĳ��ɵı����ˡ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"outwroad1",
		"southup" : __DIR__"shanlu2",
	]));

	setup();
}
