// Room: /d/village/shilu2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·�������Ǽ������̣�
���˷���������Ϊ����
LONG
        );
        set("exits", ([
		"east"  : __DIR__"tiejiangpu",
		"north" : __DIR__"zhongxin",
		"south" : __DIR__"shilu1",
	]));
        set("outdoors", "��ɽ");

	setup();
}
