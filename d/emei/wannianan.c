// Room: /d/emei/wannianan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "������" NOR);
	set("long", @LONG
�����ֽ���һ��ͻ���ɽ���ϣ���Χ��ľɭɭ����Ȫ���ȣ��в��޿�����
���޿�����ɫ�ǳ����ˡ��ɴ����Ϲ�ʮ���̿ɴﻪ�϶�����������������
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
  "westup" : __DIR__"shierpan",
  "enter" : __DIR__"wanniananzd",
  "southdown" : __DIR__"bailongdong",
]));
	setup();
}

int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge", (int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
