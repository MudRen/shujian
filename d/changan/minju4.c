// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/minju4.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ��������������ͨͨ����լ�������˳��꾭�����⣬�����ڼ�����
�������в�û��ʲô�õİ��裬ľ���ϵĲ���ƿ�в��˼���Ұ������ͬ����
�Ǵ�����˼�һ�������﹩���Ϻ������͹���ү������
LONG
        );

        set("exits", ([
                "south" : __DIR__"neijie2",
        ]));
        set("incity",1);
	setup();
}