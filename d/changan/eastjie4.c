// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/eastjie4.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣�����Ƕ�����ͨ����⡣��
�����ǳ����ĵ���¥���ϱ��ǳ����ǵı�Ӫ���ſ��йٱ���վ�ڷ��ڡ�������
һ���ڽ֣�ƽ�����ռҶ�ס�����档
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"eastmen",
                "south"  : __DIR__"bingying",
                "west"   : __DIR__"eastjie3",
                "north"  : __DIR__"neijie7",
        ]));

        set("incity",1);
	setup();
}