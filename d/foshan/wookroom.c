// Room: /d/fuoshan/zhongjia.c 
 
#include <room.h>
inherit ROOM; 
 
void create() 
{ 
	set("short", "�Ӽ�");
	set("long", @LONG
����һ����������ɵķ��ݣ�����ֻ�м������ƵļҾ㡣ǽ�Ϲ���һ
Щũ�ߣ����ϻ�����һЩ�������ո�����մ����͵�ũ�ߡ�������һ��ľ
��(door)��������Դ򿪡�
LONG
	);
	set("exits", ([
        "north" : __DIR__"alleyway",
        "east" : __DIR__"caidi",
        ]));

        set("item_desc", ([
                "door" : "����һ���ƾɵ�ľ�š�\n",
        ]));


        set("objects", ([
                __DIR__"npc/zhong-asi" : 1,
                __DIR__"npc/zhong-sisao" : 1,
                __DIR__"npc/zhong-xiaoer" : 1,
        ]));

        create_door("east", "ľ��", "west", DOOR_CLOSED);
       	setup();
}
