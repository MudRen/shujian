//�ⷿ

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIB"�ⷿ"NOR);
      set("long", @LONG
�����Ǻڷ�կ�Ŀⷿ����������������ƽ����ɽ�����������ʺ�
�����Ȼ�������ر����ء�
LONG);
      set("outdoors","");
      set("exits", ([
            "south" : "/quest/hfz/qianzhai",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }