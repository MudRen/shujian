// Room: /u/xdd/gumu/gmlg1.c
// by shang and xdd  97/6
// Modify By River 98/08/29
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIC"ʯ��"NOR);
	set("long", @LONG
����һ���ܱյ�ʯ�ң����е��ŵƻ�ʯ����С������һ����ת���˴���
��Ĺ�������������书�����޵����ơ���������ֻ��ȸ��
LONG        );

	set("exits", ([
		"north" : __DIR__"gmzt",
		"enter" : __DIR__"gmlg4",
	]));

	create_door("north", "ʯ��", "south", DOOR_CLOSED);
       
	setup();
}

void init()
{
	add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
	mapping fam;
	object me = this_player();
	int i;
	
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg == "maque") {
		if((int)me->query_skill("dodge", 1) > 50 
		 && (int)me->query_skill("hand", 1) > 50)
			return notify_fail("�㲻���������˷�ʱ�侫���ˡ�\n");
		if((int)me->query("jingli") < 15 || me->query("jing") < 15)
			return notify_fail("��̫����, ����Ϣһ�¡�\n");
		i = me->query_skill("dodge", 1) / 3;
		me->receive_damage("jing", 5 + random(10));
		me->receive_damage("jingli", 5 + random(10));
		if ( i * 3 > 20 && random(i) < 2 ) {
			write("�������������۵���ͷ�󺹣���˵׽��������ëҲ������һ����\n");
		}
		else {
			tell_object(me,"���۵���ͷ�󺹣����ץ������ȸ��\n");
			if( me->query_skill("hand", 1) <= 51 )
				me->improve_skill("hand", me->query_int()* 3/2 );
			if( me->query_skill("dodge", 1) <= 51 )
				me->improve_skill("dodge", me->query_int()* 3/2 );
		}
		return 1;
	}
	return notify_fail("��Ҫ׽ʲô��\n");
}
