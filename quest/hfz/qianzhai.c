//�ڷ�կǰկ

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIC"ǰկ"NOR);
      set("long", @LONG
�����Ǻڷ�կ��ǰկ���ǰ�ɽ��һ��ƽ̹�����ڡ�կ���е�С
ͷĿ���������ǰͷ�㳡������ѵ��ආ��������Լ�������ط����š�
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
"southdown" : "/quest/hfz/panshan3",
            "eastup" : "/quest/hfz/xiaolu",
"north" : "/quest/hfz/kufang",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }