// Room: /d/city/beidajie1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣��
���Եúܷ�æ��������һ��С�Ե꣬����խС������ֻ��Ӧ���������߾��ǳ�
����
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"xiaochidian",
		"south" : __DIR__"beidajie2",
                "west" : __DIR__"chmiao",
		"north" : __DIR__"beimen",
	]));

	set("objects", ([
		CLASS_D("shaolin") + "/xingzhe" : 1
	]));
	set("incity",1);
	setup();
}


