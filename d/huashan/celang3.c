// Room: /d/huashan/celang3.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǻ�ɽ�����õĲ���, ׯ�Ϲ���, ���Է����Ӱ��ɽ����������һ��
ɽ�ط�⡣�����ǻ�ɽ���ӵķ�����δ���߽������Ѿ��ŵ������㡣������
��ɽ���ӵ���Ϣ�ң���ϰ��ƣ��֮ʱ˯��֮�á�
LONG
        );
        set("exits", ([
		"east" : __DIR__"houtang",
		"west" : __DIR__"fanting",
		"south" : __DIR__"xiuxi1",
	]));

	set("indoors", "��ɽ" );
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "south" && me->query("gender") != "Ů��") {
		return notify_fail("����Ů������Ϣ�ң���ɲ���ȥ�Ǹ��ط�!\n");
	}
	return ::valid_leave(me, dir);
}
