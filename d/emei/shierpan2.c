// Room: /d/emei/shierpan2.c

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
  "westup" : __DIR__"shierpan3",
  "northeast" : __DIR__"shierpan",
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/10);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
