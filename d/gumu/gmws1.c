// gmws1.c By River 98/08/30
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"����"NOR);
	set("long", @LONG
������С��Ů��ǰ��ס�����ң����пտն���������������ǰ��ģ����һ
�鳤����ʯ������bed)�����������Ų�ϯ��һ���ײ������������������һ��
�˸ߵ�����������У��������
LONG        );
          
	set("item_desc", ([
		"bed" : HIC"һ������ͨ��ʯ�̳ɵĴ��������䴦����һ��ͻ���ʯ�塣\n"NOR, 
	]));

	set("exits", ([
		"south" : __DIR__"gmht",
	]));
                    
	setup();
}

void init()
{
	add_action("do_tang", "tang");
	add_action("do_ban", "ban");
	add_action("do_ban","move");
}

int do_tang(string arg)
{
	object me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg == "bed"){
		message_vision(HIC"$N����������ʯ�Ƴɵ�ʯ�����档\n"NOR,me);
		me->set_temp("marks/��", 1);
		return 1;
	}
	return notify_fail("��Ҫ���ڵ��ϣ�С������Ŷ��\n");
}  

int do_ban(string arg)
{  
	object me, *inv;
	me = this_player();

	if (!me->query_temp("marks/��")) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");          
	if ( arg == "shiban" ){
		if (me->query("neili") < 500)
			return notify_fail("��ʹ�����̵ľ�������ʯ��ȴ��˿������\n");
		if( me->query("combat_exp", 1) < 100000 && ! me->query("gmpass"))
			return notify_fail("�㷢��ʲô�ط�����ס�ˣ���ôҲ�ⲻ��ʯ�塣\n");

		inv = filter_array(deep_inventory(me), (: userp :));
		if (sizeof(inv)) 
			return notify_fail(HIR"�����ϱ���һ�ˣ�ֻ�����ڴ�����Ų��ʮ�����ѡ�\n"NOR);

		message_vision(HIY"$N�����⶯ͻ���ʯ�壬ֻ�����������죬ʯ���������²�ʯ�ҡ�\n"NOR,me);
		me->receive_damage("neili",200);
		me->delete_temp("marks/��");
		me->move(__DIR__"ss0");
		if( ! me->query("gmpass")) me->set("gmpass", 1);
		tell_object(me,HIY"�Ҷ�ʯ�����������������ˡ�\n"NOR);
		tell_room(environment(me), me->name() + "�����淭�����������\n", ({ me }));
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}
