// Room: /d/emei/basipan3.c ������ ��ʮ����3

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
		"northdown" : __DIR__"basipan2",
		"northwest" : __DIR__"lengshanlin2",
		"southeast" : __DIR__"jieyindian",
	]));
	setup();

}
int valid_leave(object me, string dir)
{
 if (dir == "southeast" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/2);
      me->receive_damage("jingli", (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 


