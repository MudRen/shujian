// houshanxl3.c
// ��ɽС·
inherit ROOM;
#include <ansi.h>

int do_kan(string arg);

void create()
{
        set("short", HIG "��ɽС·" NOR);
        set("long", @long
������˵��С·������Χ���˲��ߵ�С�������ǰ�ŵĹ�ľ���������ҵ�
��ɽ��·�ˡ�
long);
	set("outdoors", "��üɽ");
	set("exits",([
		"southup":__DIR__"houshansl",
		"northdown":__DIR__"houshanxl4",
	]));
	set("objects",([
		__DIR__"obj/axe" : 1,
	]));
        setup();
}

void init()
{
	add_action("do_kan", ({"kan", "cut"}));
}

int do_kan(string arg)
{
	object weapon, me=this_player();
	if (!arg && arg != "��ľ��" && arg != "��ľ" && arg != "guanmu" && arg != "cong")
		return notify_fail("��Ҫ��ʲô��\n");
	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("flag") != 4 )
		return notify_fail("����ʲô����\n");
	message_vision("$N����"+weapon->name()+"���Ź�ľ�Կ���������һת�۾����˽�ȥ��\n", me);
	me->receive_damage("jingli", random(200) );
	me->set_temp("last_damage_from", "�ڹ�ľ�����ƣ������");
	me->move(__DIR__"houshangm");
	return 1;
}
