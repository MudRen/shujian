// Room: /u/beyond/ningbo/shilu.c ʯ·
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ʯ·");
	set("long", @LONG
������һ����ʯ·�ϣ�������һƬï�ܵ������֣�ͷ��Сϲȵ����������
�и���ͣ��һ��΢�紵����ʹ��о���һ�ɳ�ʪ�Ŀ������������Ҳ������Ϊ
�������Ǹ��ۿڰɡ���Զ����ɽ�Ͼ��Ƕ��������ı������ˡ����ϱ����������
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"tianyige",
		"northwest" : "/d/group/entry/nbqsddao",
		"south" : __DIR__"tianfengta",
		"southup" : __DIR__"baoguosi",
	]));
	setup();
}
