//�ڷ�կ������

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", WHT"������"NOR);
      set("long", @LONG
������һ��С�͵Ĳ�������ƽ�����м���ɽկ��СͷĿ������ָ��ආ��ǲ�����
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "west" : "/quest/hfz/panshan3",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }