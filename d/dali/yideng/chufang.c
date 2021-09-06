// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����й�ȫ����ʳ�Ĳ�ˮ�͸�����ʳ����������Ʈ������ζ��һЩ������
��ͣ��æ�ţ�����һ�Ƿ��źö��ժ��������ˡ�
LONG
	);
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/shami1" : 1,
		FOOD_D("rice"): 2,
		FOOD_D("cha") : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "east" ){
		while (i--)
		if(ob[i]->id("mi fan") || ob[i]->id("xiang cha"))
			return notify_fail(CYN"Сɳ�ְ����ӷ�һ��������λʩ����������ի�����Űɡ���\n"NOR);
	}
	return ::valid_leave(me, dir);
}
