// Room: /d/village/shilu5.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ����������Ǽ�С��ÿ�귢���ֺ���ʱ������Ŷ�
���������������챣�ӡ�
LONG
        );
	set("exits", ([
		"east"  : __DIR__"shilu3",
		"south" : __DIR__"miaoyu",
		"northwest" : "/d/group/entry/caeroad3",
	]));
        set("outdoors", "��ɽ");

	setup();
}
