// /d/city/geyuan.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY"��԰"NOR);
	set("long", @long
�ݴ����������̻�Ӧ̩�޽���԰������ǧ�ˣ�����Ҷ���硰�����֣�����
��������԰����ת�������ȣ�ӭ�滨̳���������ʯ�񡣱���԰�����С���
԰������ʯ�԰����Ϊ������ǰֲ����������ˮ�أ������ܼ�ʽСͤ��
ˮ�������ӱ�ǽ�Ǻ�ʯ��ɽ��ɽ�Ϲ��ɣ�ɽ��������ˮ���������꣬ˮ�е�Ӱ
��䣬����ɽ֮�ơ�
long);
	set("exits",([
		"west" : __DIR__"jiashan",
		"east" : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"obj/flower" : 1,
	]));
	set("incity",1);
	setup();
}
