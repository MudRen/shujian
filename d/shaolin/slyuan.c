//slyuan.c

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIY"����Ժ"NOR);
	set("long", @LONG
����һ���ž���СԺ��Ժ�ж��������õ�ľ�񣬼������ײ�ɮ�µ�ɮ
����������æµ�š�����������ɮ��Բ�ź󣬷ٻ������ĳ�����Ժ�������
��һ��С�š�
LONG
	);
        set("no_fight",1);
       	
	set("exits", ([
		 "east" : __DIR__ "huaishu4",
                 "west" : __DIR__ "talin1",
        ]));

        create_door("west", "ľ��", "east", DOOR_CLOSED);
	
	set("coor/x",20);
  set("coor/y",310);
   set("coor/z",120);
   setup();
}



