// Room: /d/songshan/damen.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "����������");
	set("long", @LONG
����������ǰ����̴��£���������ȴ�ѳ�Ϊ��ɽ�ɵ�ס��������
�����������޴��ʯʨ����һ������Ʈ���Ӱӿ����������Ҳ����
�����ˡ���ɽ���ɡ��ĸ����֡�
LONG);
	set("exits", ([ 
            "north" : __DIR__"chanyuan",
            "south" : __DIR__"kuangdi",
        ]));
	set("objects", ([ 
            CLASS_D("songshan") + "/shi" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("no_fight",1);
        set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",270);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
