// Room: jieyuantang.c

inherit ROOM;

void create()
{
	set("short", "��Ե��");
	set("long", @LONG
�����Ǽ���ͨ���䷿���ǹ���ͨ�����Ϣ�ĵط������Ϲ��ź���������
��������һ��̿�𡣿�ǽ�ڷ���һ���ľ�ʣ��м�������ľ�������Ϸ���һ
�Ѳ���ͼ����豭��ǽ�Ϲ��ż������²���
LONG
	);

        set("exits", ([
		"east" : __DIR__"huilang3",
	]));
        set("objects", ([__DIR__"npc/xiangke" : 1,
	]));
	setup();
	setup();
}
