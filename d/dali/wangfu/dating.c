// Room: /dali/dating.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�������������ֻ������һ����ң�д�š������ʯ���ĸ����֣�������
�š���î���ʡ��ĸ�С�֣�����������������ֻ���һʱҲ��������ô��ࡣ
������������Ӵ��������ѵĵط�!
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"lang1",
	    "north" : __DIR__"damen",
	     "east" : __DIR__"lang2",
	]));
	set("objects", ([
	    __DIR__"npc/fusigui" : 1,
	    "/d/dali/npc/bing" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mixed *local;

	local = localtime(time() * 60);

	if (me->query("family/family_name") != "������"
	&& (dir == "west" || dir == "east")
	&& (local[2] < 5 || local[2] >= 20)) {
		//if (objectp(present("fu sigui", environment(me))))
			//return notify_fail("��˼����ס�㣬˵�������������ڲ������������\n");
		if (objectp(present("dali guanbing", environment(me))))
			return notify_fail("����ٱ���ס�㣬˵�������������ڲ������������\n");
	}
	return ::valid_leave(me, dir);
}
