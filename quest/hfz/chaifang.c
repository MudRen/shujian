//��

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "��"NOR);
      set("long", @LONG
�����Ǻڷ�կ�Ĳ񷿣�ƽʱҲ������ѺһЩ�����ġ���Ʊ����
LONG);
      set("outdoors","");
      set("exits", ([
            "south" : "/quest/hfz/xiaolu",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }