inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
set("short", "���ŷ�");
set("long", @LONG
�����Ǵ���ʹ������ŷ���ֻ�����Ϸ���ʮ�������ĸ�������ĺ͸����
��ȥ���ܾ��£���Ȼ����Ѱ���˼ҵ�ʳƷ��
LONG
);

set("exits", ([
"east" : __DIR__"huating",
]));
set("objects", ([
            __DIR__"obj/mixian" : 1
]) );
set("coor/x",-320);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}


