// Room: /d/tianshan/jtbu.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ�����Ϊ���첿�����ڵأ�����ǽ���ϻ�����
�����춥����һֻ�������̾����ϣ�˫��Բ����Ѫ�����к������¡�����
�Գ�ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ������Ľǵ�����յ���ƣ������ڴ���
�������������Ǵӵ��﷢����
LONG);
	 set("exits", ([
                "eastdown" : __DIR__"dadao5",
		"westdown" : __DIR__"dadao9",
		"northdown" : __DIR__"dadao7",
		"southdown" : __DIR__"dadao3",
		"enter" : __DIR__"ljgong",
        ]));       
        set("objects", ([
		__DIR__"npc/chengqs":1,
                __DIR__"npc/f-dizi" : 1,
        ]));    
	setup();
}
