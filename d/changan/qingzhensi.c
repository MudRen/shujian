// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/qingzhensi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǳ������ڵ������£�����λ�ڹ�¥�����Ļ������ڣ����ֳƻ�����
������£��ǳ�����ģ������˹������Ժ������һ�ǳ���Ŀ�Ĵ���¥������
ϸ�񣬷����̽ǣ����š�뷴�����¡�����Ϊ׳�ۡ�
LONG
        );
	set("exits", ([
		"south" : __DIR__"westjie4",
		"north" : __DIR__"dadian",
	]));
        set("objects", ([
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}