// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie2.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
�����ǳ����ĵ���¥���ϱ���һ������ܴ���������������顰��ء����֡�
������������������һ�Ҳ�ݣ����治ʱ�����к�֮����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"eastjie3",
                "south"  : __DIR__"qingchi",
                "west"   : __DIR__"eastjie1",
                "north"  : __DIR__"chaguan",
        ]));

        set("incity",1);
	setup();
}