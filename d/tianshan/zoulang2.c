// Room: /d/tianshan/zoulang2.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������չ���һ�����ȣ�ֻ��ÿ�����������о����Ĳʻ����羰�����
ɽˮ������Ӧ�о��С�
LONG);
	 set("exits", ([
		"north" : __DIR__"fjshi",
		"south" : __DIR__"bqshi",
		"west" : __DIR__"dadian",
                "east" : __DIR__"zoulang3",
        ]));       
        set("objects", ([
                __DIR__"npc/zhujian" : 1,
        ]));    
	setup();
}
