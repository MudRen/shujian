// Room: /d/emei/lianhuashi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "����ʯ" NOR);
	set("long", @LONG
��������ʯ���˴���ʯ�����ݺᣬ��������������ܽ�أ��·��������
ϸ������������һ�֣��С������硹���ɴ�������ֱ��ϴ��أ�������ͨ����
������ͨ���϶���
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
	  "eastdown" : __DIR__"huayanding",
	  "westup" : __DIR__"zuantianpo",
	  "southeast" : __DIR__"jiulaodong",
]));
        set("objects",([
		CLASS_D("emei") + "/zhao-lingzhu" : 1,
		CLASS_D("emei") + "/su-mengqing" : 1,
          ]));
	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "westup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 
