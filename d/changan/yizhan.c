// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/yizhan.c

inherit ROOM;

void create()
{
        set("short", "��վ");
        set("long", @LONG
�����ǳ�����վ�������ͺ;��������Ĺ��ĺ;�����ż���ÿ�������
ƥ��������������������Ρ������������Ҫ�ĵ����ֻҪ�ŵ����һ��
֮�ھ��Կ����͵���
LONG
        );
        set("exits", ([
                "south" : __DIR__"westjie3",
        ]));

        set("incity",1);
	setup();
}
