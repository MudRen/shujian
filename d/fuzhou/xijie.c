// Room: /d/fuzhou/xijie.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǹ��ݵ�����֣������������Ϻ����֣��ֵ�������������ɫɫ��
��Ů���٣����в����������Ľ������͡����濴��������һ�����̣����治
�Ǻܴ󣬽����������ȸ߸ߵĴ��ţ�������һ���ܴ��լԺ��̧ͷ���Կ�����
�ϵ��ĸ����֣��������ھ֡���
LONG
	);

	set("exits", ([
                "east" : __DIR__"zhongxin",
                "west" : __DIR__"xijie2",
                "north" : __DIR__"dangpu",
                "south" : __DIR__"biaoju",
	]));

	set("objects", ([
		__DIR__"npc/tangzi" : 2,
		__DIR__"npc/shi_bt" : 1,
		__DIR__"npc/zheng_bt" : 1,
	]));

	set("outdoors", "����");
	setup();
}
