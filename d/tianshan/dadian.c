// Room: /d/tianshan/shanjin1.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����������չ��Ĵ���ˣ����øߴ����ƷǷ���������ȥ��ֻ������һ
����ң�д�š����չ����������֡���������������ֻ�����һʱҲ��������
�࣬���Һö������������ʶ���м���������������ľ�Ƴɵ�̫ʦ�Σ�����
һ�Ŵ���ʯ��İ����������������ǰ������ӡ�����Ѿ��������������������
ѻȸ������
LONG);
	 set("exits", ([
		"east" : __DIR__"zoulang2",
		"west" : __DIR__"zoulang4",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"zoulang6",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 2,
		__DIR__"npc/shinv" : 2,
			__DIR__"npc/xuzhu" : 1,
			
        ]));    
	setup();
}
