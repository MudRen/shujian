// /d/plummanor/hubian.c ������
// By Jpei

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", GRN"������"NOR);
	set("long", @LONG
����������ɽ��һ�����ڣ�һ������Сɽ������ߺ�ˮ���һ�����̣���
���ľ��������м��괹������Ӱӳ�ڱ��̵ĺ�ˮ�΢�紵����������������
������ˮ�棬����һ����������������һ���������۵�ʯ������֪��ͨ����
�
LONG
);
/*	set("objects",([
		__DIR__"npc/you" : 2,
	]));*/
	set("outdoors","÷ׯ");
	set("exits", ([
                "west" : "/d/hz/gushan",
		"east" : __DIR__"shiji",
	]));
	setup();
}
