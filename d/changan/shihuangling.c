// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/shihuangling.c

inherit ROOM;

void create()
{
        set("short", "ʼ����");
        set("long", @LONG
���������ڰ������е�һ�������꣬�ʸ����͡�վ�������ϼ�ĿԶ������
���Ŀ��������Ա���һ���ߴ��ʯ��������ʼ���ꡱ����ǰ��ͤ���Ľ�΢�̣�
���ܺ���������������������ΰ׳����ׯ�����£�çç��ɽ�Űز��졣
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "east" : __DIR__"yongkeng2",
           "southwest" : __DIR__"baishulin2",
                "west" : __DIR__"baishulin1",
               "north" : __DIR__"yongkeng1",
        ]));

        setup();
}
