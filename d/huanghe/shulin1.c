// by XiaoYao

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ
��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ��
������ԥ��ǰ���ĽŲ�����������һ������(paizi)��
LONG );
	set("outdoors", "�ƺ�");
	set("exits", ([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("item_desc", ([
		"paizi" : HIR"\n�ǻƺӰ�����    �����ɱ����\n\n"NOR,
	]));

	set("objects", ([
		NPC_D("dushe") : 1,
                __DIR__"npc/obj/shikuai" : 1,
	]));

	setup();
}
