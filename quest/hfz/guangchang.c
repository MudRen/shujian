//�ڷ�կ�㳡


#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", WHT"�㳡"NOR);
      set("long", @LONG
�㳡�����������ű����ܣ�����һ����˸������ƣ�����Ʈ����һ����죬
���顾�����е����������֡�
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "northup" : "/quest/hfz/panshan",
            "southdown" : "/quest/hfz/damen",
            "east" : "/quest/hfz/yanwu1",
            "west" : "/quest/hfz/yanwu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }