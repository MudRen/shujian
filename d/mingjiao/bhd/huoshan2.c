// huoshan2.c ��ɽ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"��ɽ��"NOR);
	set("long", @LONG
��������͵��ڵ��˵����ˡ�
LONG);
	set("exits",([
		"southdown" : __DIR__"huoshan1",
	]));
        set("outdoors","����");
	setup();
}

void init()
{
        object me =this_player();
        me->set_temp("last_damage_from", "�����ɽ����");
       	me->die();
}
