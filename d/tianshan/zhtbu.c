// Room: /d/tianshan/zhutbu.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ����������첿�����ڵأ�����ǽ���ϻ�����
�����춥����һ��������û�ڻ�������֮�С���֪����λ�����ֱʣ�ֻ��
���������һ�㣬ֱҪ�ƶ���ȥ����������ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ�
�����Ľǵ�����յ���ƣ������ڴ����������������Ǵӵ��﷢����
LONG);
	 set("exits", ([
                "northeast" : __DIR__"dadao10",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
		__DIR__"npc/shishao" : 1,
        ]));    

	setup();
}
