#include <weapon.h>
#include <ansi.h>

inherit STAFF;

#include <combat_msg.h>
void create()
{
	set_name("������" NOR, ({ "guaishe zhang", "shezhang", "zhang"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������������ߵ����ȣ���ͷ���л��أ�ҧ�����������ޱȣ�\n");
		set("value", 500);
		set("material", "steel");
                set("poisoned", "bt_poison");
                set("poison_number", 290);
	}
	init_staff(75);
	setup();
}

void init()
{
        add_action("do_zhua","yao");
        add_action("do_zhua","ҧ");
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

int do_zhua(string str)
{
	object me, target;
        string msg, *limbs, limb;
	int j, damage;
	
        me = this_player();

        if (str && !objectp(target = present(str, environment(me)))) 
                  return notify_fail("����û������ˡ�\n");
        
        if( !target ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !living(target)
         || !me->is_fighting(target) )
                return notify_fail("��ֻ����ս����ʹ�á�\n");

        if (me->is_busy()) 
                return notify_fail("��������æ���ء�\n");
	
        if( !this_object()->query("equipped") )
		return notify_fail("������ҧ�ˣ�����������\n");
		
        if (me->query_skill_prepared("strike") != "hamagong" ||
            me->query_skill_mapped("strike") != "hamagong" ||
            me->query_skill_mapped("force") != "hamagong")
                return notify_fail("û��������󡹦��������޷�ʹ�ù����ȣ�\n"); 
       
        if( (int)me->query_skill("hamagong",1) < 150 )
                return notify_fail("��ĸ�󡹦����������ʹ�ò��˹����ȣ�\n");
        if( (int)me->query_skill("poison",1) < 150 )
                return notify_fail("��Ķ���������ʹ�ò��˹����ȣ�\n");

	if( (int)me->query_skill("lingshe-zhangfa",1) < 150 )
                return notify_fail("����ȼ�������ʹ�ò��˹����ȣ�\n");

        if( (int)me->query("jingli") < 500 )
                return notify_fail("��Ŀǰ������ɢ��������ע��ע���Լ��ɣ�\n");
       
        if( (int)me->query("neili") < 800 )
                return notify_fail("��Ŀǰ����������������ע��ע���Լ��ɣ�\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("���ϣ��Է����������֪�����أ�����������\n"); 

	target->add_temp("hmg_bite", 1);
        message_vision(HIB "\n$N"HIB"ͻȻ���ϣ�˫��һš������β��������צ����$nһ���һӣ�\n" NOR, me, target);

        if(random(me->query("combat_exp")) < (int)target->query("combat_exp")/2 ||
                random(target->query_temp("hmg_bite")) > 2){
                msg = "$n���һ����֪����������æ���˿�ȥ����ڴ�ڴ�������\n\n" NOR;
                me->start_busy(1);
                if(!target->is_busy())
                        target->start_busy(1);
                } 
        else {
                me->start_busy(2);
                if(!target->is_busy())
                        target->start_busy(2);
                msg = "$p���뵽$N�������Ǭ����ֻ����ͷ����ͷ��Ȼһ����һ��ҧ����$p���ϣ�";
                if( query("poison_number") > 0 ){
                	msg += "ֻ���˿����������˺�ɫ�Ķ�Ѫ��";
                	add("poison_number", -10);
                	target->apply_condition("bt_poison", target->query_condition("bt_poison") + random(20));
                }
                limbs = target->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                damage = me->query_skill("hamagong", 1) + me->query_skill("lingshe-zhangfa", 1);
                if( target->query("neili") > me->query("neili")/3*2){
                	msg += "\n$n���������͵�һ���ѳ��߿ڣ������˼�����\n";
                	damage += random(damage);
                	target->receive_damage("qi", damage, me);
        		target->receive_wound("qi", damage/4, me);
        		j = (int)target->query("qi")*100/(int)target->query("max_qi");
        		msg += damage_msg(damage, "ץ��")+"( $n"+eff_status_msg(j)+" )\n"; 
        		msg = replace_string( msg, "$l", limb );
                } 
                else {
                	msg += HIR"\n$n�˱ܲ�����"+ limb + "����ҧ����һ���Ѫ�⣡\n"NOR;
                	damage *= 2;
                	damage += me->query_str() * 10;
                	
                	target->receive_damage("qi", damage, me);
        		target->receive_wound("qi", damage/2, me);
        		j = (int)target->query("qi")*100/(int)target->query("max_qi");
        		msg += "( $n"+eff_status_msg(j)+" )\n"; 
                } 
        }
        message_vision(msg, me, target);
        me->add("neili", -200);
        return 1;
}

