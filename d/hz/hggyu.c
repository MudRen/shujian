// /u/beyond/hangzhou/hggyu.c ���۹���
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIR"���۹���"NOR);
        set("long", @LONG
��ǰ��������һ��СϪ�ӻ���ɽ�����������������ۡ�����ʱ��������
�˽�԰������㣬���ǳ�����ƾ�����㣬�˵ع������۹��㡣�����Ǻ���أ�
���š�������������ĵ��԰��������ǻ���Ȫ���������ң��������,�����
���յ��ˡ�
LONG
        );
        set("exits", ([
        "north" : __DIR__"sudi",
"south" : __DIR__"hubian2",
"southeast" : __DIR__"hubian1",
        "east" : __DIR__"hongyuchi",
        "west" : __DIR__"mudanyuan",
]));
        set("coor/x",90);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}
