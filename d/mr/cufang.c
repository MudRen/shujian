// /d/mr/cufang.c
// by leontt
// update 1/5/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"����"NOR);
	set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣
long);
	set("resource/water", 1);
         
	set("objects", ([
		FOOD_D("caiyeji") : 1,
		FOOD_D("yuyuan") : 1,
		FOOD_D("zaoya") : 1,
	]));
	set("exits",([
		"east" : __DIR__"didao1",
	])); 
	setup();
}
