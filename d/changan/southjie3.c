// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/southjie3.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ����ϳ���ͨ����⡣��
�����ǳ����ĵ���¥�������ǳ��еľ�������ɫʮ��������������һ��������
�֣�һ��������ͷ����֪��ͨ�����
LONG
        );
	set("outdoors", "����");
	set("exits", ([
		"east"   : __DIR__"changjie1",
		"south"  : __DIR__"southmen",
		"west"   : __DIR__"jinghu",
		"north"  : __DIR__"southjie2",
	]));
        set("objects", ([
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest") &&  dir == "east"){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
