// Room : houyuan.c ��Ժ
// Lklv 2001.5.27
// 2001.9.26 update

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����������ĺ�Ժ�������Ǹ߸ߵ͵͵Ļ���ǽ��Ժ�м���һ�ڴ��������
����������ʲô��������Զ���м���������ؤ��Χ����һ����ĸߴ������ؤ
��Χ���ڸ�̸������ʲô�������ܺ�����
LONG
	);
	set("outdoors","����");
	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"pomiao",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/h7g" : 1,
	]));
	create_door("south", "����", "north", DOOR_CLOSED);
	setup();
}