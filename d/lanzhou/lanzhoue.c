// Room: /d/xingxiu/jyge.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǿ������ݵĶ����š��������ͽ����ˣ�����о���פ������ʱ������
�����ˡ���С�����������뿪���Ƿ�֮�ء������򶫣���ͨ������ɽ�������
���ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG);

	set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"road5",
		"west" : __DIR__"lanzhou",
	]));

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("objects", ([
		__DIR__"npc/bing1" : 2,
		__DIR__"npc/wujiang1" : 1,               
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\nȫ��ͨ����\n";
}
/*
void init()
{
	object me = this_player();

	if (!userp(me)) return;
	me->set_temp("check", 1);
	call_out((: call_other :), 1, me, "delete_temp", "check");
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i, flag = 0;
	object bing = present("guan bing", this_object());

	if (me->query_temp("check") && bing && living(bing)) {
		ob = deep_inventory(me);
		i = sizeof(ob);
		while (i--)
		if (ob[i]->id("gold_money") && ob[i]->move(bing)) flag = 1;
		tell_object(me, bing->name()+"�ȵ���"+RANK_D->query_rude(me)+"����վס������ô���ʲô��\n");
		if (flag)
		if( flag && me->query("combat_exp")>100000)
		message_vision(HIY "$N��$n���ϵĻƽ����˸����⡣\n" NOR, bing, me);
		return notify_fail(bing->name()+"��ס���㡣\n");
	}
	me->delete_temp("check");
	return ::valid_leave(me, dir);
}
*/