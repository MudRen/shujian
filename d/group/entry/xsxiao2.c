// xsxiao2.c

inherit ROOM;

#include <ansi.h>
#include "/d/group/entry.h"

void create()
{
	set("short", "����С·");
	
	set("long", "������ߵ�һ��С·����ǰ��������ͷ����֪��ͨ�����·��Ұ���ҷ���\n"
		"�������裬�������Լ��ĽŲ�����������ֻ����һ����һ���͵�������\n");

	set("exits", ([
		"east":"/d/xueshan/xiaolu3",
		"northwest":"/d/xueshan/xiaolu1",
		]));

	set("outdoors","��ѩɽ");
	
	set("group",1);
	
	setup();
}
