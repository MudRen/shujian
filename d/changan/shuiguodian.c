// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/shuiguodian.c

inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long", @LONG
���ǳ�������Ψһ��һ��ˮ���ꡣ�����������һ���ŵ���𣬿����и�
ʽ������ˮ���������ˮ��Ϊ�˱������ʣ�����ÿ���峿�ӳ���Ĺ�԰�ÿ쳵
�����ġ�ˮ�����Ů������ɩ��������к��ſ��ˡ�
LONG
        );

        set("exits", ([
                "south"   : __DIR__"eastjie3",
        ]));
        set("objects", ([
                __DIR__"npc/pangsao" : 1,
        ]));
        set("incity",1);
	setup();
}
