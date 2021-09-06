// houshanty.c
// ��ɽ̿Ҥ
inherit ROOM;
#include <ansi.h>

int do_shaotan();
int do_puhuo(string arg);

void create()
{
	set("short", HIR "̿Ҥ" NOR);
	set("long", @long
������һ��������̿��̿Ҥ�������ڶ��ҵ��ӳԿ����ͣ�����û������
̿Ҥ����һƬ���ҡ��ڵ�һ����Ϳ������һ�ж��������������������׼ҵ���
������ææµµ��
long);
	set("outdoors", "��üɽ");
	set("exits",([
		"southwest":__DIR__"houshan",
	]));
	set("objects",([
		__DIR__"npc/kydizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_shaotan", "shaotan");
	add_action("do_puhuo", "pu");
}

int do_shaotan()
{
	int count;
	object me=this_player();
	if( !me->query_temp("emjob2/��̿") || me->is_busy() || me->is_fighting() ) 
		return 0;
	if( (int)me->query_temp("emjob2/��ľ") != 1) 
		return 0;
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	count = (int)me->query_temp("emjob2/��̿");
	if ( count == random(40) && !me->query_temp("emjob2/����")){
		message_vision("$N��ר�ĵ���̿��ͻȻһ��"HIR"����"NOR"�ŵ�$N�����ϡ�\n", me);
		me->set_temp("emjob2/����", 1);
		remove_call_out("get_fire");
		call_out("get_fire", 10, me);
	}
	message_vision("$N��ѡ�õ�ľ�Ϸ���Ҥ��,��ϸ�ع۲���\n", me);
	me->receive_damage("jing", 10 + random(20) );
	me->set_temp("last_damage_from", "��̿��");
	if ( count == 1 ) {
		me->delete_temp("emjob2/��ľ");
		me->delete_temp("emjob2/��̿");
		message_vision("$N���պõ�ľ̿��Ҥ��ȡ����������Ҥ���ӡ�\n", me);
		tell_object(me,"������һ���������˸���������Ȼ��Щƣ�룬������ȴ��һ��ů�⡣\n");
		if(me->query_skill("linji-zhuang",1)) {
			count = 10 + random( uptime() - me->delete_temp("emjob2/uptime") ) / 2;
			if (count > 40) count = random((int)me->query_skill("force") ) + (int)me->query_int();
			me->add("combat_exp",5+random(10));
			me->add("potential",1+random(2));
			me->improve_skill("linji-zhuang", 200+random(50));
			if( me->query("potential")>me->query("max_pot"))
				me->set("potential",me->query("max_pot"));
			me->delete_temp("emjob2/uptime");
			me->start_busy(1);
		}
		return 1;
	}
	me->set_temp("emjob2/��̿", count - 1);
	return 1;
}

void get_fire(object me)
{
	if( me->query_temp("emjob2/����") ) {
		message_vision("$Nһ��û���񣬱ŵ����ϻ�������������\n", me);        
		tell_object(me,"��Ͻ��������˻𣬻���Ȼ���ˣ�����Ҳ���յù�Ǻ��\n");
		me->delete_temp("emjob2/����");
		me->unconcious();
	}
}

int do_puhuo(string arg)
{
	object me = this_player();
	if(!me->query_temp("emjob2/����")) return 0;
	if(!arg) return 0;
	if(arg == "huo" || arg == "huoxing" || arg == "fire" || arg == "fire" || arg == "����" || arg == "��" ) {
		me->delete_temp("emjob2/����");
		remove_call_out("get_fire");
		message_vision("$N�Ͻ������ϵĻ������ˡ�\n", me);        
	}
	return 1;
}
