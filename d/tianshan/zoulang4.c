// Room: /d/tianshan/zoulang4.c
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
		"north" : __DIR__"kefang",
		"east" : __DIR__"dadian",
		"south" : __DIR__"lxzai",
		"west" : __DIR__"zoulang5",
        ]));       
        set("objects", ([
                __DIR__"npc/lanjian" : 1,
        ]));    
	setup();
}
