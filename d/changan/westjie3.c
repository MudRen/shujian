// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie3.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ����⡣��
�����ǳ����ĵ���¥��������ǳ�������վ����������ľ���������Ƕ����
����������������������Ǻ������ŵĻ����ھ֡�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"westjie2",
                "south"  : __DIR__"biaoju",
                "west"   : __DIR__"westjie4",
                "north"  : __DIR__"yizhan",
        ]));

        set("incity",1);
	setup();
}