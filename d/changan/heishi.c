// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/heishi.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������һ����լ���������˾�ס�����ʧ�޵����ˣ����ڳ���һƬ
���棬�������˵������������Ǿͳ���һЩ�˷����Ŷ���˽�εĽ��׳�������
���ٸ�ץ�úܽ�����Щ�ڷ���ԶԶ��Χ����һ��������ߣ�С��������ʲô��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : __DIR__"shiji",
                ]));

        set("incity",1);
	setup();
}

