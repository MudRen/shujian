// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/southjie2.c

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�ϱ����ϳ���ͨ����⡣��
�����ǳ����ĵ���¥������һ�ұ����̣�������������˸�����������һ
�ǵ��⽣Ӱ���������ľ����������ߵĵ�������ͬ��������ȥ�Ķ��ǳ�����
�еķ������ӡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"bingqipu",
                "south"  : __DIR__"southjie3",
                "west"   : __DIR__"dewentang",
                "north"  : __DIR__"southjie1",
        ]));

        set("incity",1);
	setup();
}