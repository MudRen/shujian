// Room: /d/tianshan/lgfang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������չ������������ԡ��������ĵط���Ϊ�˷������������ζ�û
�аڷţ������ڵ��¶��˼���С���š�
LONG);
	 set("exits", ([
		"north" : __DIR__"zoulang3",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
