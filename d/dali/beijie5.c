// Room: �����/dali/beijie5.c
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣���������������������С������Ҳ�������������ϵ���
Ҫ���С����ﱱ����һ���ĳ������������ϴ��������潨���ߴ��ǹٸ�����
�֡�������Ǳ���֣������߾͵��˴�����֡�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"beijie4",
		"south" : __DIR__"dongjie1",
		"east" : __DIR__"yanju",
		"north" : __DIR__"duchang",
	]));

	set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/yanxiao" : 1,
		__DIR__"npc/yanxiao2" : 1,
	]));
	set("incity", 1);
	setup();
}
