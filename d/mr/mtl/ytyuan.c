// /d/mr/ytyuan.c
// this is made by beyond
// update 1997.6.20
// rebuild by Lklv 2001.9.20

#include <ansi.h>
#include <room.h>
inherit ROOM;

int nokill()
{
	object ob = previous_object(1);

	if (ob == find_object("/cmds/skill/exercise")
	|| ob == find_object("/cmds/skill/respirate"))
		return 0;
	return 1;
}

void create()
{
	set("short",HIM"ӣ��԰"NOR);
	set("long",@long
������һ��ӣ��԰��԰�������˴�Ƭ��Ƭ��ӣ������ÿ�����죬�������
�϶������˷ۺ��ӣ�һ����ǳ�Ư����������������ȥ���Ǳ�Ҳ��һ��ӣ��԰��
long);
	set("outdoors","��٢��ɽׯ");

	set("exits",([
		"west" : __DIR__"ytyuan2",
		"north" : __DIR__"midao",
		"south" : __DIR__"huandong",
	]));
	set("no_fight", (: nokill :));
	setup();
}
