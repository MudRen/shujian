// eatroom.c ���� 
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"����"NOR);
       set("long", @long
�����ǳ��ְ�ĳ�����λ������֮���һ��ܴ�ķ��䡣��������һֻС
̿¯��Ҳ��֪��������ʲô��������������ֱ�졣�����Ϸ���һЩ��õ�ʳ�
��ζ�˱ǡ�
long);
	set("exits", ([		
		"north" : __DIR__"zoulang2",
	]));             
	set("objects",([
             FOOD_D("rice") : 1,
             FOOD_D("cha") : 2,
             __DIR__"npc/tong" : 1,
	]));
	set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "north" ){
		while (i--)
		if(ob[i]->id("xiang cha") || ob[i]->id("rice"))
			return notify_fail(CYN"С�׺���һ�����Ա������˻�Ҫ����ѽ��\n"NOR);
	}
	return ::valid_leave(me, dir);
}
