// /dali/chufang.c
// bbb 1997/06/11
// Modify By River 98/12
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ү�����ŷ�����������Ʈ������ζ���ö������ڲ�ͣ��æ�ţ�����
һ�Ƿ��źö�մ������Ұζ���㲻�ɵ�������ͣ�����������Ķ��ӡ�����
�����Ľ���������
LONG
        );

        set("exits", ([
              "west"  : __DIR__"lang4",
        ]));
        
        set("objects",([
          __DIR__"obj/zhashanji" : 1,
          __DIR__"obj/jiuping" : 1,
        ]));
        set("coor/x",-260);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}

