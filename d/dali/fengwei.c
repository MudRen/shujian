// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"��ζС�Ե�"NOR);
        set("long", @LONG
����һ�������ķ�ζС�Ե꣬ר�����ֵط���С�ԣ���Ȼ�Ϳ�������¥��
�ߣ���������һ������¡�����ﵽ���������ˣ���Щ���˾�վ��һ�Զ˸����
�Ľ����ζ��
LONG
);
        set("exits", ([ 
            "west" : __DIR__"xijie1",
            "north" : __DIR__"beijie2",
            "east" : __DIR__"dalics",
	]));

        set("objects", ([
                        __DIR__"npc/zhangqian" : 1 
        ]));
        set("coor/x",-320);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
