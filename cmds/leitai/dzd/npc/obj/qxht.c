// /d/dzd/obj/qxht.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("���ĺ��ķ�",({"haitang fen","fen"}));
	set_weight(50);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("long",HIB"����һ�������ĺ������ƶ��ɵķ�ĩ���綾�ޱȣ�
�¶���ʱ����Ե�(tan)Ŷ��\n"NOR);
		set("value",200000);
		set("unit","��");
	}
             set("dzd",1);

	setup();		
}
void init()
{
	add_action("do_tan","tan");
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int do_tan(string arg)
{
	object me =this_player();
	object target;
	
	if( environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ׼ս����\n");
	if( !arg ) 
		target = offensive_target(me);
	else {
		target = present(arg, environment(me));
	}
	if(!target)
		return notify_fail("�����˭ʹ�����ĺ��Ķ���\n");
	if(!target->is_character()) return notify_fail("���ϸ�Ц����\n");
	
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	//if(!target || !target->is_character() || !me->is_fighting(target))
		//return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�ã�\n");
	if(me->query_temp("dzd_quest/fen_used"))
		return notify_fail("���Ѿ��Զ���ʹ�����ĺ��Ķ��ˡ�\n");
	if(!living(target))
		return notify_fail("�����¶��˰ɣ�\n");
	me->set_temp("dzd_quest/fen_used",1);
	call_out("out_fen",10,me);
	tell_object(me,BLU"������һ�죬ָ�������������ĺ��ĵ�ҩ��,����ʳָ��ָ��һ����һ����ɫ��ζ�ı�����Է�Ʈȥ��\n"NOR);
	if(random(3)) {
		target->apply_condition("haitang_poison",4 + target->query_condition("haitang_poison"));
		message_vision(HIY"$Nһʱ���⣬�Ѿ�����$n�İ��㣡\n"NOR,target,me);
	}
	else 
		message_vision(HIY"$N���㶯�����죬��������׼�������������������ƣ��Ѷ�����ɢ��\n"NOR,target);
	me->start_busy(1);
	return 1;
}

void out_fen(object me)
{
	//remove_call_out("out_fen");
	if(!me) return;
	me->delete_temp("dzd_quest/fen_used");
}