// xdong.c ʯ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"ʯ��"NOR);
        set("long", @LONG
�˴�ΪһСɽ�����м�͸��һ����⣬�����촰һ�㡣�������롢���
ʯ�������ߵ�һӦ��ȫ��
LONG);
	set("exits",([
		"out" : __DIR__"shishan1",
	]));
        set("objects",([
                CLASS_D("mingjiao") + "/xie" : 1,
               // "clone/npc/newshizhe.c" : 1,
	]));
	setup();
}
