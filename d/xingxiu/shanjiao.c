// /d/xingxiu/shanjiao.c
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
��������ɽ���£��������Ǹ������Ƶ���ɽ��̧ͷ�������Կ���ɽ���ϵ�
�����ѩ��һ����ɽ�������Ϊ���룬�������������ľ۾������Ͻ��ǹ���
�ޱߵĴ��ԭ��������������������ǣ���Ϊ���ǽ�ͨҪ��ʱ���������ɵ�
�Ӱѹ����١�
LONG);
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"xxh",
		"east" : __DIR__"yili/yili",
		"southeast" : __DIR__"silk9",
		"southwest" : "/d/hj/senlin1",
	]));
	set("objects", ([
		__DIR__"npc/xxdizi3" : 1,
		__DIR__"npc/boshou"  : 1,
	]));
	setup();
}

#include "/d/xingxiu/job2.h";
