// Room: /d/nanyang/xujiaji.c
// Lklv Modify 2001.10.11

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"��Ҽ�"NOR);
	set("long", @LONG
����������������Ҽ����м��Ϻ����֣�������ũ�񾭳���������������
�������Ͷ��ĳɹ��������Ա���Ƭ�յأ�ͣ�ż������������мҿ�ջ���ſ�
���������
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"qslu",
		"southwest" : __DIR__"xiaolu2",
		"east" : __DIR__"kedian1",
		"south" : __DIR__"qslu2",
	]));
	set("objects",([
		NPC_D("kid") : 1,
	]));

	setup();
}
