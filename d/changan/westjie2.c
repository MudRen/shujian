// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/westjie2.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ����⡣��
�����ǳ����ĵ���¥��������ǳ������������ˣ���Ϊ�����������������
����ΰ��ܺá����������سǽ����ǳ����ɵĸ�լ��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"westjie1",
                "south"  : __DIR__"jiangjunfu",
                "west"   : __DIR__"westjie3",
                "north"  : __DIR__"yamen",
        ]));

        set("incity",1);
	setup();
}