// Room: /d/tianshan/zoulang5.c
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
		"north" : __DIR__"fqzong",
		"east" : __DIR__"zoulang4",
		"south" : __DIR__"qinshi",
        ]));       
        set("objects", ([
                __DIR__"npc/meijian" : 1,
        ]));    
	setup();
}
