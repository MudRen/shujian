// Room: /d/emei/basipan2.c ������ ��ʮ����2

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "��ʮ����" NOR);
	set("long", @LONG
��ʮ���̣���·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·���Ǳ��������
��ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ���������������µ�ϴ��ء�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
		"northeast" : __DIR__"basipan1",
		"southeast" : __DIR__"lengshanlin1",
		"southup" : __DIR__"basipan3",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
 if (dir == "southup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/5);
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 