// ���� caotang.c
 
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() 
{ 
        set("short", "����");
        set("long", @LONG
����һ�����ã����ڹ��߳��㣬�Եú�����������������һ��̴ľ������
��������ذڷ����ĸ����ӡ��������Ե�ǽ�Ϲ���һ������������һ�������
��������ˣ�������һ���������������·��и��㰸���������¯�в��ż���
̴�㣬��ȽȽ��ȼ�š����Բ�����һ������(door)�����š�
LONG
        );

        set("no_clean_up", 0);

        set("exits", ([ 
            "enter" : __DIR__"xfang4",
            "west" : __DIR__"chufang",
            "south" : __DIR__"maowu",
            "east" : __DIR__"xfang3",
        ]));

        set("objects",([
            __DIR__"npc/xtong1" : 1,
        ]));

        create_door("enter", "����", "out", DOOR_CLOSED);
        setup();
}
