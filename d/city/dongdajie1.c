// Room: /d/city/dongdajie1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ǵ����̺������꣬��ʱ
�������ô��Ľ���ײ���������������ʵĶ�����������һ�𡣱�����һ����
�ֺŵ�ҩ�̣��ϱ��ǼҼ����ꡣ
LONG
	);
        set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/suanming": 1,
	]) );

	set("exits", ([
		"east" : __DIR__"dongdajie0",
		"south" : "/d/zhiye/jimaidian1",
		"west" : __DIR__"dongdajie2",
		"north" : __DIR__"yaopu",
        	"southeast" : __DIR__"yltw",
	]));

	set("incity",1);
	setup();
}

