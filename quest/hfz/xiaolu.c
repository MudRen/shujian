//�ڷ�կС·

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "С·"NOR);
      set("long", @LONG
�������ǰկͨ����կ��С·��һ�Ӷӵ�Ѳɽආ������߹�������Ĵ�������Χ��
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "westdown" : "/quest/hfz/qianzhai",
            "east" : "/quest/hfz/xiaolu2",
"north" : "/quest/hfz/chaifang",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }