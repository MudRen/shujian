// Room: /d/fuzhou/shiqiao.c
// Lklv modify 2001.9.6
inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ʯ�����ɵ�С�ţ���������һ���������ˮ�����������ű���
���ߣ����ž��Ƕ�����ˡ�վ����ͷ���ϱ���������ԶԶ����һ��С����
����һ��ʯ������д�š����������С�֡�
LONG
	);

	set("exits", ([
        	"south" : __DIR__"xyxiang",
                "north" : __DIR__"dongjie",
	]));

	set("objects", ([
                NPC_D("boy"):1,
                NPC_D("girl"):2,
	]));

	set("outdoors", "����");
	setup();
}
