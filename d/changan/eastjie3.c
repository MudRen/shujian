// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie3.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
�����ǳ����ĵ���¥���ϱ���һ�һ��꣬�ſڰ��źܶ�����ͷ׵Ļ���������
��һ��ˮ���ꡣ�ߵ����������ŵ�һ�����㣬�������ֲ����ǹ��㻹�ǻ��㡣
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"eastjie4",
                "south"  : __DIR__"huadian",
                "west"   : __DIR__"eastjie2",
                "north"  : __DIR__"shuiguodian",
        ]));

        set("incity",1);
	setup();
}