// xiaolu1.c �ּ�С��

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"С��"NOR);
	set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ��
������������������Ķ������������������ȡ�
LONG
	);
	set("outdoors", "�䵱");

	set("exits", ([
		"east" : __DIR__"donglang2",
		"west" : __DIR__"donglang1",
		"south" : __DIR__"xiaolu2",
		"north" : __DIR__"sanqing",
	]));
 
	set("objects",([
		CLASS_D("wudang") + "/yu" : 1,
	]));

        setup();
}

int valid_leave(object me, string dir)
{
	mixed *local;

	local = localtime(time() * 60);
	
	if( me->query("family/family_name") != "�䵱��"
	 && present("yu lianzhou", environment(me))
	 && dir != "north"
	 && (local[2] < 5 || local[2] >= 20))
		return notify_fail(CYN"��������ס���ȥ·����ȭ��������ҹ���λ"+RANK_D->query_respect(me)+"�����䵱���Ӳ������ڡ�\n"NOR);
	return ::valid_leave(me, dir);
}
