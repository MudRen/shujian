// Room: /d/tianshan/ytbu.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ�����Ϊ���첿�����ڵأ�����ǽ���ϻ�����
�����춥����һֻ���룬���������צ��أ�˫ĿԲ������Ҫ���˶�ʳ��
�����Գ�ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ������Ľǵ�����յ���ƣ�������
�����������������Ǵӵ��﷢����
LONG);
	set("exits", ([
                "northwest" : __DIR__"dadao4",
        ]));       
        set("objects", ([
                __DIR__"npc/fumy" : 1,
		__DIR__"npc/f-dizi" :1,
        ]));    

	setup();
}
