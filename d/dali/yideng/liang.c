// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ʯ����ͷ");
	set("long", @LONG
ʯ����͹��ƽ���ּ������ѩ���ﻬ�쳣������ʯ���ϣ�Լ���߰˳߳���
һ��ȱ�ڣ���һ�Σ�Ծ��һ��ȱ�ڣ����������߸����£��ۼ�����ɽ����һ��
Ƭƽ�ء�ʯ���ѵ���ͷ�����Ǿ�ͷ��ȴ��һ������ȱ�ڣ���������һ�ɿ��⣬
ȱ�ڱ˶���ϥ����һ����������������һ���飬�������С��������������һ
���̶̵�ȱ�ڡ�
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"north" : __DIR__"hetang",
	]));

	set("objects", ([
		__DIR__"npc/duzi" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "north"
	&& !me->query_temp("yideng/shusheng_pass")){
		if ( present("shu sheng", environment(me)))
			return notify_fail("������������ǰ������������֮��������޿����㡣\n");
		else 
			return notify_fail("ʯ����ͷ�̶̵�ȱ�ڣ�ʹ��о��޷����㡣\n");
	}
	return ::valid_leave(me, dir);
}
