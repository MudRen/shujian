// ҩ��
// yaochang1.c
// augx@sj 2/28/2002

// Modified by mxzhao 2004/03/06 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIG"��ҩ����"NOR);
	set("long",
"���Ǽ��ª��С���ӣ���������������עĿ�����ǿ����ղ�Ϣ�İ�ҩ��
���������һ�㲻������ҩ����ֻ���չ���ҩ�˲ɻ�����ҩ��ԭ�ϣ��ӹ���
����������ҩ��ҩ��ԭ�ϡ�
"); 

/*
	set("objects",([
		__DIR__"npc/yaochang-zhu" : 1,
		__DIR__"obj/yaoguo" : 1,
	]));
*/	
	set("exits",([
		"west" : "/d/chengdu/beidajie2",
	]));
	
	set("indoors", "�ɶ���");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
