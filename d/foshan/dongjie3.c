// Room: /d/fuoshan/dongjie3.c
// Lklv modify 2001.9.27

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
�����ڽ��ϣ�����ϡ��������������һ�¸�ǽ��ǽ��д��һ�����
�ġ������֣���ϸ��������������ѹ�͵��ּۻ��۵������������Ƿ�ɽ��
�ţ�ͨ����⡣
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([
		"south" : __DIR__"dangpu",
		"east" : __DIR__"dongmen",
		"west" : __DIR__"dongjie2",
	]));

	set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));

	setup();
}