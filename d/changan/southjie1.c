// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southjie1.c

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ����ϳ���ͨ����⡣��
�����ǳ����ĵ���¥������һ�ҵ����ſڹ���һ�ܴ�ġ������֣������Ǽҵ�
�̣�����������һ�����ֺŵ�Ǯׯ�������������������Ľ���������
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"dangpu",
                "south"  : __DIR__"southjie2",
                "west"   : __DIR__"qianzhuang",
                "north"  : __DIR__"zhonglou",
        ]));

        set("incity",1);
	setup();
}