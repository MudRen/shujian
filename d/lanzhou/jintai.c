//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��̩");
	set("long", @LONG
��̩�����Ĺ�������פ���ر�����¥�ߴ����ɣ��ſ������Źٱ�������
����̲�������ˣ����ſڵĸ�ʾ�ϻ������ͨ���Ľ�������ͼ�Σ�����ͷ
����ȥ��ͦ���֡����Ϸ�����˻ƺӾ������ɽ�ˡ�
LONG );

	set("exits", ([
		"northwest" : __DIR__"hongsx",
		"southeast" : __DIR__"huanghe_2",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
	]));

	set("outdoors", "����");
	setup();
}
