// Room: /d/tianshan/ctbu.c
// By Linux

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"���첿"NOR);
	set("long", @LONG
��ǰ��һ�������������˵Ĵ������ǳ��첿�����ڵأ�����ǽ���ϻ�����
�����춥����һƬ����һ�����������У���Ŀ��������̬���ţ��ƺ�����
�����޹�ʹ�������²������ġ������Ի�ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ�
�����Ľǵ�����յ���ƣ������ڴ����������������Ǵӵ��﷢����
LONG);
	 set("exits", ([
                "southdown" : __DIR__"dadao2",
		"northdown" : __DIR__"dadao3",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    
	setup();
}
