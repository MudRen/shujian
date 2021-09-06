// Room: /d/shaolin/fumoquan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��շ�ħȦ");
	set("long", @LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и�����¶����ɫɮ
��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ�����Ĵ���ͺͺ�ģ��ƺ�������
�����������´�ݲ�����
LONG
	);

	set("exits", ([
		"out" : __DIR__"qyping",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/du-nan" : 1,
		CLASS_D("shaolin") + "/du-e" : 1,
		CLASS_D("shaolin") + "/du-jie" : 1,
	]));
	set("outdoors", "������");
	setup();
}

void init()
{
	mapping mine;
        object ob = this_player();
	mine = ob->query("family");

	if( !userp(ob) || wizardp(ob) ) return;
	if (ob->query("family/family_name") == "������" && (ob->query("passdu") || ob->query("pass_xin")))
		return;
	message_vision(HIR "ͻȻ�侢���ݺᣬ��������������������͵ع�����˲�����
����һ����ֱ�ı��У��糤ì����˰������������ֱ���$N��ͷ��
�أ�������Ҫ�����̶�����$NһƳ�䣬����������ɮ�־�������
��֮�У���ȫ���ֱ���$N������$N��������������֮�̺����Ͻ�
ħ�󷨵Ľ�շ�ħȦ��\n\n" NOR, ob);

	if ( mapp(mine)
	&& mine["generation"] > 36
	&& mine["family_name"] == "������"
	&& ob->query("qi") < 200 ){
		message_vision(HIR "$N��һ����ɽ������ľ������У���ʱ���˳�ȥ��\n" NOR, ob);
		ob->move("/d/shaolin/qyping", 1);
		tell_room(environment(ob), ob->name()+"�ӷ�ħȦ���˳�����\n", ob);
	}
}

int valid_leave(object me, string dir)
{

	if( dir == "out" && member_array("puti zi", deep_inventory(me)->query("id")) != -1 ) {
		return notify_fail("�и�����˵�������ܴ����������뿪��ħȦ !\n");
	}
	me->delete_temp("fighter");
	return ::valid_leave(me, dir);
}
