// Room: /d/village/shilu3.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ���������һ�������������ʯ·�������Ǽ�С�ƹݣ�
һ�����ӹ��ڷ����¡�
LONG
        );
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"north" : __DIR__"jiusi",
		"west" : __DIR__"shilu5",
	]));
	set("objects", ([
		NPC_D("poorman"): 1
	]) );

        set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	setup();
}
