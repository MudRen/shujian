// /d/city/jiashan.c
// update 1997.7.4
// this is made by beyond

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIY"��ɽ"NOR);
	set("long",@long
�ɸ��Ⱥ�С���͵��������ɫ��ɽ�εض���ɽ�忡�Σ�ɽ��Űأ�ɽ
��Сͤ��ɽ�л���СԺ��ʯ�š�ʯ�ҵȣ����ư��硣Ϊ����ɽʯ�����ټ���
long);
	set("exits",([
		"east" : __DIR__"geyuan",
	]));

	set("objects",([
		__DIR__"npc/binv" : 1,
	]));

	set("incity",1);
	setup();
}
