// ysroad2.c ��ʯ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��ʯ·"NOR);
	set("long", @LONG
��ʯ·���ɻ�ɽ�Ҷѳɣ���ʱ�ã�����ʮ�ּ�Ӳ���������ѿ��Կ�������
����֮�о��к��ⲻ�ϵ������ԭ������֮����һ�����ɽ���ߵ������Ѹ�
��һ˿�������������������ʮ����·�͵����ɽ�����ˡ�
LONG);
	set("exits",([
		"west" : __DIR__"hsjiao",
		"east" : __DIR__"ysroad1",
	]));
	set("outdoors","����");
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west"){ 
	   me->set_leader(0);
           me->receive_damage("jing", 100);
           me->receive_damage("qi", 100);
         }
         return ::valid_leave(me, dir); 
}
