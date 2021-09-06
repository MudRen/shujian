// houshansl.c
// ��ɽ����
inherit ROOM;
#include <ansi.h>

int do_famu();
int do_duoshan();

void create()
{
	set("short", HIG "��ɽ����" NOR);
	set("long", @long
�����Ƕ��Һ�ɽ�ϵ�һƬ�ɲĵ����֣��������ľï�ܣ��кܶ���ľ����
����̿�ġ�������һ��յأ�������һ��ͨ��ɽ�µ�һ��С·��
long);
	set("outdoors", "��üɽ");
	set("exits",([
             "west":__DIR__"houshan",
             "northdown":__DIR__"houshanxl3",
	]));
	setup();
}

void init()
{
	add_action("do_famu", ({"famu", "kanshu"}));
	add_action("do_duoshan", "duoshan");
}


int do_famu()
{
	int count;
	object weapon, me=this_player();
	if( !me->query_temp("emjob2/��ľ") || me->is_busy() || me->is_fighting() ) 
		return 0;
	if (!objectp(weapon = me->query_temp("weapon")) 
	 || weapon->query("id")!= "axe")
		return 0;
	count = (int)me->query_temp("emjob2/��ľ");
	if ( count == random(40) && !me->query_temp("emjob2/����")){
		message_vision("$N��ר�ĵؿ�����ľ��ͻȻһ�ô������ˣ���$N������������\n", me);
		me->set_temp("emjob2/����", environment(me));
		remove_call_out("get_beat");
		call_out("get_beat", 10, me);
	}
	message_vision("$N�������еĸ�ͷ����һ��ѡ�õĴ�����ȥ��\n", me);
	me->receive_damage("jingli", 15 + random(20) );
	me->set_temp("last_damage_from", "��ľ��");
	if (me->query("potential") && random(10) > 5){
		me->improve_skill("linji-zhuang", me->query_int());
		me->add("potential", - random(2));
	}
	if ( count == 1 ) {
		message_vision("$N�ѿ��õ�̿ľ���������պá�\n", me);
		return 1;
	}
	me->set_temp("emjob2/��ľ", count - 1);
	return 1;
}

void get_beat(object me)
{
	if( me->query_temp("emjob2/����") == environment(me) ) {
		message_vision("$Nһ��û���񣬱����µĴ����ҵ����ϡ�\n", me);        
		me->delete_temp("emjob2/����");
		me->unconcious();
	}
	else message_vision("һ�ô�����Ȼ���ء�\n", me);
}

int do_duoshan()
{
	object me = this_player();
	if(!me->query_temp("emjob2/����")) return 0;
	remove_call_out("get_beat");
	me->delete_temp("emjob2/����");
	message_vision("$Nһ����㿪�������Լ��Ĵ�����\n", me);        
	return 1;
}
