// Room: /d/village/shilu4.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ���������һ�����������ʯ·�������Ǽ��ӻ��̣�
��Ҫ����һЩ�ο���ɽ�õĶ�����
LONG
        );
        set("exits", ([
		"east"  : __DIR__"shilu6",
		"west"  : __DIR__"zhongxin",
		"north" : __DIR__"zahuopu",
	]));
	set("outdoors", "��ɽ");

	setup();
}
