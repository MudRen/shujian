// /d/fuzhou/rock.c ��ʯ(С��)
// Lklv MOdify 2001.9.27

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",YEL"����"NOR);
        set("long", @LONG
һ���ͺͺ�Ĵ���ʯ�����ܳ�������̦��ֻ�����д�������ȥ���ƺ���ʲ
ô�ù������߹�ȥ��ϸһ������������ӡ�Ų�����ӡ�Ƶġ�վ����ʯ�ϣ���Ŀ
������Զ�����ƻ𣬺�һ�����ҹ�ơ�
LONG
        );
        set("outdoors","����");

        set("exits",([
		"south" : __DIR__"island3",
		"enter" : __DIR__"mupeng",
        ]) );
        setup();
}

void init()
{
        add_action("do_strike","strike");
        add_action("do_za","za");
}

int do_strike(string arg)
{
	object me = this_player();
	int skl_impv,jingli_damage;

	if ( !(arg) || ((arg != "rock") && (arg != "yan")) )
		return 0;
	if ( me->is_busy() )
		return notify_fail("��������æ���أ�");
	if ( me->query("max_neili") <= 300 ) {
		message_vision("$N����ʯ��һ�ģ�˭֪���������ƺ���һ���������������ˡ�\n", me);
		me->receive_wound("qi", 100);
		return 1;
	}
	else {
		if ( me->query("jingli") < 150 ) {
			tell_object(me,"��̫���ˡ�\n");
			return 1;
		}
		message_vision("$N���һ����������һ����ֻ��������...������ʯҡ�˼��¡�\n",me);
		if ( me->query_skill("strike", 1) <= 101 ) {
			skl_impv = (me->query_str(1) / 2)+ me->query_con(1) / 2 + (me->query_condition("drunk") / 2) ;
			me->improve_skill("strike", skl_impv);
			jingli_damage = 80 - random(me->query_str())-random(me->query_int());
			if ( jingli_damage < 0 ) jingli_damage = 0;
			me->receive_damage("jingli", jingli_damage);
			return 1;
		}
		return 1;
	}
}

int do_za(string arg)
{
	object me=this_player();
	object weapon = me->query_temp("weapon");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");

	if (!weapon || weapon->query("skill_type") != "stick" )
		return notify_fail("��Ҫ��ʲô���ң�\n");

	if( !arg || arg!="yan" )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query_skill("stick",1) > 100 ) {
		tell_object(me,"�㷢�������ûʲô�á�\n");
		return 1;
	}
	if ( me->query("jingli") < 150 ) {
		tell_object(me,"��̫���ˡ�\n");
		return 1;
	}

	me->receive_damage("jingli",20 +random(20));
	write("��������б�������������ʯ��ȥ��\n");
	me->improve_skill("stick", 15+me->query("str"));
	return 1;
}
