// Room: /d/changle/road1.c

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
		"northwest" : "/d/city/eroad2",
		"southeast" : __DIR__"road2",
		"northeast" : __DIR__"road3",
	]));

	set("outdoors", "���ְ�");
	setup();
}
