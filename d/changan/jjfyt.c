// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/jjfyt.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ������ķ��������úܴ���������ݵ�����ʮ���ˡ�����������
�ź�ľ������������һ���ò裬���ż��̵��ġ��ݽ���¯�ﴫ��һ����������
�޵İ��㡣
LONG
        );
        set("exits", ([
                "west"  : __DIR__"jjfzht",
        ]));

        set("incity",1);
	setup();
}
