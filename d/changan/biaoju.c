// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/biaoju.c

inherit ROOM;

void create()
{
        set("short", "�����ھ�");
        set("long", @LONG
����һ��������ΰ��լ�ڣ���������ʯ̳�и���һ���������ߵ���ˡ���
�ϻ�ɫ˿������һͷ������צ���ͻ������������չ���Ե��ͻ�������������
���������������ھ֡��ĸ����֣������������վ��Ƿ���������װ������Ժ��
���䣬�������������ͦ���Գ�һ��Ӣ��֮����
LONG
        );
        set("exits", ([
                "south" : __DIR__"biaoju2",
                "north" : __DIR__"westjie3",
        ]));

        set("objects", ([
                __DIR__"npc/tangzishou" : 4,
                __DIR__"npc/biaoshi" : 1,
        ]));

        set("incity",1);
	setup();
}