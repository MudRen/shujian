// /u/beyond/mr/cangshuge.c
// this is made by beyond
// update 1997.6.20

#include <room.h>
inherit ROOM;
void create()
{
	set("short","�����");
	set ("long",@long
������������ɽׯ�Ĳ����, �����书���������, �������󣬿��롰��
���롱�Ĳ�����ٵС� ��������ȫ��һ���Ÿߴ����ܡ�
long);
	set("no_fight", 1);
	set("exits",([
		"down" : __DIR__"yunjinlou",
	]));
	setup();
}
