// Room: /d/hengshan/xuankong1.c

inherit ROOM;

void create()
{
	set("short", "�����±�¥");
	set("long", @LONG
�����������µı���¥��Ҳ�Ǳ���ͤ����¥���ӣ�������Ԩ���ȵ�������
��ڼ䵤�����������ջ��ͨ����¥��
LONG
	);
	set("exits", ([
		"south"    : __DIR__"zhanqiao",
                "up"       : __DIR__"sjdian",
		"westdown" : __DIR__"cuiping2",
	]));
	set("objects", ([
		__DIR__"npc/yafu" : 1,
	]));
        setup();
}
