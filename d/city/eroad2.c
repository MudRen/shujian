// Room: /d/city/eroad2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
������������������ǳ����֡���ʱ����������������߷ɳ۶���������
һ·���������ϵ��˸������ž�װ���¼��������еĻ���������ŵ���������
����Щϰ��Ľ����ˡ���·��������������������֡�
LONG
	);

	set("exits", ([
		"west" : "/d/group/entry/yzeroad1",
		"southeast" : "/d/changle/road1",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 2,
                __DIR__"npc/wang" : 1,
                __DIR__"npc/mmr" : 1,
	]));

	set("outdoors", "����");
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "caikuang shifu" &&  dir != "west" ) return 0;
	return ::valid_leave(me, dir);
}
