//����

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "����"NOR);
      set("long", @LONG
�����Ǻڷ�կ�ĳ�����ƽʱɱ����ţ������ϲ˶������ż��Ҳɱ������Ʊ�����Ѿ�����
LONG);
      set("outdoors","");
      set("exits", ([
            "north" : "/quest/hfz/xiaolu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }