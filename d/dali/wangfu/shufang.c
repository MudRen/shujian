// /dali/shufang.c �鷿
// bbb 1997/06/11
// Modify By River 98/12 
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
�����鷿����������������ŨŨ��ī�㡣��������ȫ�������飬���в���
��������ܸ������үÿ�춼Ҫ�ڴ˴���͢Ҫ�£���Ͼʱ��ʫ�дʣ�������ʿ
�ȣ�������ɣ�������óȻ������
LONG
        );

        set("exits", ([
                "west" : __DIR__"lang5",
        ]));
        set("objects", ([
                __DIR__"obj/tl01" : 1,
        ]) );
        set("coor/x",-300);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();

}
