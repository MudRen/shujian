// Room: /d/huashan/celang4.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǻ�ɽ�����õĲ���, ׯ�Ϲ���, ���Է����Ӱ��ɽ����������һ��
ɽ�ط�⡣������һ����ɫ����Ľ�������ϸһ�����ǻ�ɽ�ɵ���Ժ���ڣ���
���ǻ�ɽ���ӵ���Ϣ�ң���ϰ��ƣ��֮ʱ˯��֮�á�
LONG
        );
        set("exits", ([
		"west" : __DIR__"houtang",
		"east" : __DIR__"shuyuan",
		"south" : __DIR__"xiuxi2",
	]));

	set("no_clean_up", 0);
	set("indoors", "��ɽ" );

	setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "south" && me->query("gender") != "����" && !me->query_temp("hs/askzixia"))
        || (dir == "south" && !userp(me))) {
		return notify_fail("�����е�����Ϣ�ң���ɲ���ȥ�Ǹ��ط�!\n");
	}
	return ::valid_leave(me, dir);
}
