// /d/miaojiang/slu1.c

#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������ɽ���µ�һ��յأ��Ա�������һ������(paizi)���������嶾�̵Ľ�
�������￴�ء�����ĸ��¾����嶾�̵Ľ��أ��κ��˶����ҽ�ȥ��
LONG
        );
	set("exits", ([
		"northup" : __DIR__"slu2",
		"east" : __DIR__"jiedao4",
		"northwest" : __DIR__"shanlu",
	]));
	set("item_desc", ([
		"paizi" : HIR "�嶾�̽��أ��ô��ߣ�����\n"NOR,
	]));
	set("objects",([
		__DIR__"npc/jiaozhong1" : 2,
		__DIR__"npc/qiyunao" : 1,
	]));
	set("outdoors", "�置");
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
	if (me->query("family/family_name") != "�嶾��"
	&& present("wudujiao dizi", environment(me))
	&& dir =="northup")
		return notify_fail("�嶾���������ȵ����嶾���أ��ô�������\n");
	return ::valid_leave(me, dir);
}
