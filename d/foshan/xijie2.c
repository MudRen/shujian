// Room: /d/fuoshan/xijie2.c 
 
inherit ROOM; 
#include <wanted.h>
 
void create() 
{ 
	set("short", "��ɽ����");
	set("long", @LONG
��������ʯ��Ľֵ��ϣ������ԵñȽϰ�����������Լ������������
��������������Ƿ�ɽ�������ˡ�������һ��������ΰ�Ĵ����������Ϸ�
����һ���ƾɵ�ľ�ƣ����顰��������
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([
  "east" : __DIR__"xijie",
  "west" : __DIR__"ximen",
  "north" : __DIR__"beidimiao",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
