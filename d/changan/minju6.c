// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/minju6.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ�����ס������̨�Ϸ��Ŵ��С��С����ɹޣ��������Ż���֮
��Ķ��������ȴ��Ӵ󿪣�Ʈ��һ�ɻ��ݵ�����ζ�������ʮ�����֣�һ�Ŵ�
ľ���ӣ���Χ���ż������ӣ������������һ�𣬲�֪��̸ʲô��
LONG
        );

        set("exits", ([
                "south" : __DIR__"neijie4",
        ]));
        set("incity",1);
	setup();
}