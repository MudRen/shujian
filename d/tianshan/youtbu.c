// Room: /d/tianshan/shanjin1.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ����������첿�����ڵأ�����ǽ���ϻ�����
�����춥����һ��˫���ˣ��������ԣ�һͷΪ�У�״����ª��һͷΪŮ��״
�������������Ժ�ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ������Ľǵ�����յ���ƣ�
�����ڴ����������������Ǵӵ��﷢����
LONG);
	 set("exits", ([
                "southeast" : __DIR__"dadao8",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	setup();
}
