// Room: /d/jiaxing/hubian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǽ����Ϻ����ϡ��ڽ�������ߵ�����Ҳ��������������ĺɻ���
Щ�Ѿ���л��һȺ�����������������ڵؿ��ź�Ҷ�·�������ź��Զ����ʱ
����һ���������ת�ĸ�����Ʈ����ˮ���ɵĺ����ϡ�
LONG
	);

	set("exits", ([
                "west" : __DIR__"nanhu",
	]));
        set("objects", ([
                 "/d/hz/npc/you" : 2,
        ]));
	set("outdoors", "����");
	setup();
}
