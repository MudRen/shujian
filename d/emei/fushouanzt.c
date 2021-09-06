// Room: /d/emei/fushouanzt.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "������ի��");
	set("long", @LONG
������Ƕ��Ҹ����ֵ�ի�á������ֱ����󣬵����ھ����Ӵ������ֵĵ��ӣ�
ի�õ�Ҳ��С��ֻ�����ڰ����˳����Ĳ����ͳ��ʣ���λСʦ̫������æµ�Ų���
��ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��������һ����(door)��
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"lingwenge",
  "northup" : __DIR__"fushouanxxs",
]));
	set("objects",([
		"/d/emei/obj/mizhi-tianou" : 1,
        "/d/emei/obj/mala-doufu" : 1,
        "/d/huashan/obj/qingshui-hulu" : 1,
		"/d/emei/obj/liuli-qiezi" : 1,
]));
create_door("northup", "С��", "southdown", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && me->query("gender") != "Ů��" )
		return notify_fail("ֻ����һƬ�ž���������Ҳ������ȥ�������ͷ��\n");

	return ::valid_leave(me, dir);
} 
