// ROOM: mushi.c
// Created by Numa 19990910

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"Ĺ������"NOR);
	set("long",@LONG
�������Ĺ�����ҡ������бڼ䰸ͷ���ǹ������桢�������飬û
һ�����Ǽ�ֵ���ǵľ�Ʒ��ǽͷ��һյ���ƣ�ֻ����Щ����������
�����֮���ڵƹ��·���������â��ǽ�Ϲ���һ�������ٸ��Ļ�����
����һ��ձᡣ�������һ����ס�
LONG);
	set("exits", ([
        "up" : __DIR__"mudao4",
	]));
	set("no_clean_up",0);
	setup();
}

void init()
{
      if (!this_player()->query_temp("thd/dojob") && userp(this_player()))
	{
		tell_object(this_player(),"ͻȻ�������һ����Ĺ���ӣ�������˳�ȥ��\n");
        this_player()->move(__DIR__"tomb");
	}
}
