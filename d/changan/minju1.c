// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/minju1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���������ǿ�������������ض���Ȼ�������һ����ɫ��ɫ�ľ�����ױ
̨��ǰ��������ź�ľԲ�Ρ��Ҳ�ǽ���Ϲ���һ����Ů����ͼ���������м���
�ʼ����������С�֣��ڲ�����һ�ź�ɫ��ᣴ��ҵĵͰ�ľ齡�
LONG
        );

        set("exits", ([
                "south" : __DIR__"shiji",
        ]));
        set("incity",1);
	setup();
}