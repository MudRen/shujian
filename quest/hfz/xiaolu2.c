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
            "west" : "/quest/hfz/xiaolu",
            "south" : "/quest/hfz/chufang",
"east" : "/quest/hfz/juyi",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }