// Room: /d/fuzhou/nanjie.c

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
�����Ǹ��ݵ��Ͻ֣������˲��Ǻܶ࣬ż���м������󽭺����ʹ�����
����ӱ����ϼ��۶�ȥ���ɴ����о��Ǹ��ݳǵ����š�
LONG

	);

	set("exits", ([
                "north" : __DIR__"zhongxin",
                "south" : __DIR__"nanmen",
	]));

	set("outdoors", "����");
	setup();
}


