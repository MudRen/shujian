// By River@SJ

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ĺ�����������פ���ر�����¥�ߴ����ɣ��ſ������Źٱ���
��������̲�������ˣ����ſڵĸ�ʾ�ϻ������ͨ���Ľ�������ͼ�Σ���
��ͷ����ȥ��ͦ���֡����Ͼ���ȥ���ǵķ����ˣ��������������ɽ����
LONG );
	set("exits", ([
		"southeast" : __DIR__"wuqiao",
		"east"     : __DIR__"tumenzi",
		"northwest" : "/d/xingxiu/road4",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 3,
	]));

	set("outdoors", "����");
	setup();
}
