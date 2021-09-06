// �׽�˿����
// by snowman@SJ 13/06/99

#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
        set_name(HIW"�׽�˿����"NOR, ({"baijin shoutao", "shoutao", "gloves"}));
        set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("unique", 1);
                set("long", "����һ˫�Լ�ϸ�İ׽�˿֯�ɵ����ף���ǹ���룬�ǹ�Ĺ���ľ�֮һ��\n");
                set("value", 2000000);
                set("material", "gold");
                set("armor_prop/parry", 5);
                set("treasure", 1);
                set("female_only", 1);
                set("wear_msg", HIW "$N���׽�˿�����ó������ᶶ�����������ϡ�\n" NOR);
		set("remove_msg", HIW "ֻ��$N��˫����ָ���������������׽�˿��������������\n" NOR);
        }
        setup();
}

void init()
{
        add_action("do_zhua","zhua");
        add_action("do_zhua","ץ");
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
	object me, target, weapon;
        string msg;

        me = this_player();

        if (str && !objectp(target = present(str, environment(me)))) 
                  return notify_fail("����û������ˡ�\n");
        
        if( !target ) target = offensive_target(me);
        
        if( !target
         || !target->is_character()
         || !living(target)
         || !me->is_fighting(target) )
                return notify_fail("��ֻ����ս���е�ץ���ֵı����á�\n");

        if (me->is_busy()) 
                return notify_fail("��������æ���ء�\n");

        if( me->query_temp("weapon") )
		return notify_fail("��������������У������ȷ������е�������\n");
	
        if( !this_object()->query("equipped") )
		return notify_fail("������š�Ű׽�˿����Ȼ����Ŀ�������У�����������\n");
		
        if (me->query_skill_prepared("cuff") != "meinu-quanfa" ||
            me->query_skill_mapped("cuff") != "meinu-quanfa" ||
            me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("û����������Ů�ľ�����Ůȭ�����໥��ϣ�������޷�ʹ�ð׽�˿���ף�\n"); 
       
        if( (int)me->query_skill("yunu-xinjing",1) < 150 )
                return notify_fail("�����Ů�ľ�����������ʹ�ò��˰׽�˿���ף�\n");
        if( (int)me->query_skill("meinu-quanfa",1) < 150 )
                return notify_fail("�����Ůȭ������������ʹ�ò��˰׽�˿���ף�\n");

        if( (int)me->query_dex() < 32 )
                return notify_fail("����Ȼ���Ű׽�˿���ף������������еĹ���ȴ����Ҫ���ߵ����ģ�\n");

        if( (int)me->query("jingli") < 500 )
                return notify_fail("��Ŀǰ������ɢ��������ע��ע���Լ��ɣ�\n");
       
        if( (int)me->query("neili") < 800 )
                return notify_fail("��Ŀǰ����������������ע��ע���Լ��ɣ�\n");

        if(me->query("combat_exp") < (int)target->query("combat_exp")/2 )
                return notify_fail("���ϣ��Է����������֪�����أ�����������\n"); 

        if(!objectp(weapon = target->query_temp("weapon")))
                return notify_fail("��...�Է�˫�ֿտգ���ץʲô�أ�\n"); 

        target->add_temp("ynxj_shoutao", 1);
        
        message_vision(HIW "\n$N"HIW"ͻ��Ʈ����ϣ���������˫�ֵİ׽�˿���ף�ץ�õ��ģ�������$n"HIW"����������\n" NOR, me, target);
        if( (int)me->query("combat_exp") < (int)target->query("combat_exp")/2 ){
        	msg = "����$n���г��񣬹���һЦ������"+weapon->name()+"���ģ����ô���$N�����Ѩ֮�ϣ��۵�$P����̧�����ֱ�����\n\n";
        	me->start_busy(3);
        	}
        else if(random(me->query("combat_exp")) < (int)target->query("combat_exp")/2 ||
                random(target->query_temp("ynxj_shoutao")) > 2){
                msg = "$n��гԾ�����æ������ˣ��ѿ���$N�����������۵ɵر�ͭ�廹��\n\n" NOR;
                me->start_busy(1);
                if(!target->is_busy())
                        target->start_busy(1);
                } 
        else {
                me->start_busy(2);
                if(!target->is_busy())
                        target->start_busy(2);
                msg = "$p���뵽$N��������Ȼ��������ȴ�ǵ�ǹ���룬"+weapon->name()+"��$N���ץס��";
                if( target->query("neili") > me->query("neili")/3*2){
                	msg += "\n$n���������͵�һ�飬����û��$Pץȥ����ȴ�����⵹����������\n\n";
                	target->receive_damage("jingli", me->query_skill("yunu-xinjing",1)*2, me);
                	} 
                else if( weapon->query("rigidity") <= 1 
                        && target->query("neili") < me->query("neili")/2){
                	msg += "�漴���ɾ��۶ϣ�\n\n";
                	weapon->broken("�۶ϵ�");
	        }
		else {
			msg += "һ�Ѷ��˹�����\n\n";
			weapon->unequip();
		        weapon->move(me);
		        target->reset_action();
                        }
                }
        message_vision(msg, me, target);
        me->add("neili", -200);
        return 1;
}
