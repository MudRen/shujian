// ҩ��
// yaopu1.c
// augx@sj 2/28/2002

// Modified by mxzhao 2004/03/06 
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",GRN"ҩ��"NOR);
	set("long",
"���Ǽҹ�ɫ�����ҩ�꣬�Ǹ����������������ֺš�ǰ����ҩ����������
�ﲻ����Ӧ�Ӳ�Ͼ�����в����η����о��ڴ����������ҩ���ò����֡���
�ݽǻ�����һ������ͭ¯������¯��Ϣ�����Ǹ�������Ƶ�ҩ��׼���ġ�
");

	set("objects",([
		__DIR__"npc/yaodian-zhanggui" : 1,
//		__DIR__"obj/yaolu" : 1,
	]));

	set("exits",([
		"east" : "/d/chengdu/beidajie2",
	]));

	set("indoors", "�ɶ���");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
