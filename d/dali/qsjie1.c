// Room: /d/dali/qsjie1.c
// By River 98/12/01
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣�������������Ĵ�����
�����Ҽ������ַǳ���������һ���㳡��Ҳ���Ǵ���������ˡ��ϱ���һ����
�꣬ԶԶ�ؿ���������š�ӭ���ݡ������֡�
LONG
        );
        set("outdoors", "����");

        set("exits", ([ 
                "north" : __DIR__"dalics",
                "south" : __DIR__"kedian",
                "east" : __DIR__"doufufang",
        ]));
 
        set("coor/x",-310);
  set("coor/y",-400);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
