// Room: /d/fuzhou/beijie.c
// lklv modify 2001.9.10

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݵı��֣������˲��Ǻܶ࣬ż���м������󽭺����ʹ�����
��������򱱼��۶�ȥ��
LONG

	);

	set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"zhongxin",
	]));

	set("outdoors", "����");
	setup();
}


