// Room: /d/tianshan/gyting.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
���������չ���԰��Ĺ���ͤ��ֻ������ͤ����һˮ̶��ˮ̷����ϡ����
�������Ʊ������м���һ����ˮ�ţ�������һƬ��ɽ��
LONG);
	 set("exits", ([
                "north" : __DIR__"dsqiao",
	        "south" : __DIR__"houyuan",
        ]));       
        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("outdoors", "��ɽ");
	setup();
}
