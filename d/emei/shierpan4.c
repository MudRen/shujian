// Room: /d/emei/shierpan4.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "ʮ����" NOR);
	set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡����ɴ����Ͽɴﻪ�϶�����������
���֡�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
  "up" : __DIR__"huayanding",
  "northeast" : __DIR__"shierpan3",
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "up" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/10);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
