// Room: /d/nanyang/yidao3.c

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�������һ��С·
ͨ���������
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"nanyang",
		"north" : "/d/shaolin/ruzhou",
                "east" : __DIR__"yidao4",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && me->query_temp("sljob"))
		return notify_fail("�Ǵ�ǿ����û���Ƚ�Σ�գ������ߴ���ɡ�\n");
	return ::valid_leave(me, dir);
}
