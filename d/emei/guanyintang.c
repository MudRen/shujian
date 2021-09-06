// Room: /d/emei/guanyintang.c
// ��ʱ�� player �ر� fen ��

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long", @LONG
�����ø߾��¸ڣ�����Σ�£������ľ���������ľ��������Ŀ���ġ���˵
��ɽ�ڴˣ����ѳ�������ɽ�ڴˣ��������裬�ֹ��������֡���ɽ�����ڴ˷�
��ϴ�ģ���ɽ���ɻ���Ϊ�ģ�����ƽ�������ﶫ�¿ɴ�����£�������Լ����
�ɵ����Ƹ�
LONG
	);
	set("outdoors", "��üɽ");
	set("objects",([
		__DIR__"npc/xiangke" : 2,
	]));
	set("exits", ([ 
		"east" : __DIR__"guanyinqiao",
		"westup" : __DIR__"guiyunge",
	]));
	set("coor/x",-250);
	set("coor/y",-130);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_fen", "fen");
	add_action("do_fen", "��");
}

int do_fen(string arg)
{
	object me = this_player();
	int nv, nh, improve1;

	if( !wizardp(me) ) return 0;

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ģ�\n");

	if( !arg || arg == "" || arg != "��" )
		return notify_fail("��Ҫ����ʲô��\n");

	if( !present("xiang", me) )
		return notify_fail("��Ҫ����ʲô��\n");
	
	if( arg == "��" ) {
		if( (int)me->query_temp("fen_xiang", 1) >= 1 ) {
			message_vision("$N����ڹ�����ǰ����ȼһ������ϵĿ�ͷ��\n", me);
			me->add_temp("fen_xiang", 1);
			destruct(present("xiang", me));
			return 1;
		}
		if( !(int)me->query_temp("fen_xiang", 1) ) {
			nv = (int)me->query("kar", 1);
			nh = nv * 250;
			improve1 = 1;
			message_vision("$N����ڹ�����ǰ����ȼһ������ϵĿ�ͷ��\n", me);
			me->add_temp("fen_xiang", 1);
			destruct(present("xiang",me));
			me->add("kar", improve1);
			me->start_call_out( (: call_other, this_object(), "remove_effect", me, improve1 :), nh );
			return 1;
		}
	}
}

void remove_effect(object me)
{
	if( (int)me->query_temp("fen_xiang",1) >= 1 ) {
		me->add("kar", -1);
		me->delete_temp("fen_xiang");
	}
}
