// Room: /d/emei/lingyunti.c ������ ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "������" NOR);
	set("long", @LONG
���������ݣ�������һλ�а��Ŷ����������ڴ˸�ľ��ʯ���Զ����ˣ�
�ֽС���ɮ�ݡ���·����÷���£��ɼ�������÷�綹������֦��Ҷ�ж������ˣ�
���С���÷ֹ�ʡ�֮���á����ݱ�ͨϴ��أ������׶�ƺ��
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
		"northdown" : __DIR__"xixiangchi",
		"southup" : __DIR__"leidongping",
	]));

	set("valid_startroom",1);

	setup();

}
int valid_leave(object me, string dir)
{
 if (dir == "southup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/5);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 