// /d/hmy/changlang4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧���λ�
�ľ���
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"shifang",
		"south" : __DIR__"changlang6",
		"west" : __DIR__"changlang3",
		"north" : __DIR__"xiuxishi",
	]));
	setup();
	
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && this_player()->query("gender") != "Ů��" )
		return notify_fail("�����������Ů������Ϣ�ң�����Ҫ˯���᷿ȥ��\n");
	return ::valid_leave(me, dir);
}
