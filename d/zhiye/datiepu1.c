// ������
// datiepu1.c
// augx@sj 9/4/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",RED"������"NOR);
	set("long",
"����һ�����ʵ�����ӣ�����ֻ����һ�����Ӻͼ������ӣ����о�����
��¯��Ϩ�Ĵ���¯�ˣ��ͺ�������ķ��䡣�����������������ʯ��Ҳ��
���Լ�����һ�´�������Ȥ��
"); 

	set("objects",([
		__DIR__"npc/tiejiang" : 1,
		//__DIR__"obj/datielu" : 1,
	]));
	
	set("exits",([
		"south" : "/d/city/dongdajie0",
	]));
	
	set("indoors", "���ݳ�");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
