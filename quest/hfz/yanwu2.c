//�ڷ�կ���䳡
#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", "���䳡"NOR);
      set("long", @LONG
�����Ǻڷ�կ�����䳡��ƽ�����м���ɽկ��СͷĿ������ָ��ආ��ǲ�����
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "east" : "/quest/hfz/guangchang",
      ]));

      setup();
//  replace_program(ROOM);
}
int is_mirror() { return 1; }