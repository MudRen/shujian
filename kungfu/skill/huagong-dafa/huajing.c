// huagong.c ����
// by snowman@SJ
// modify by snowman@SJ 25/02/2000
// Modified by darken@SJ

#include <ansi.h>

inherit F_SSERVER;

string exert_name(){ return HBRED"����"NOR; }
void huagong(object me, object target);

int exert(object me, object target)
{        
        object room,ob;
        
        if( !target) target = offensive_target(me);
        if( !target || !objectp(target) || !me->is_fighting(target) || !living(target))
                return notify_fail("����ֻ����ս���жԶ���ʹ�á�\n");
                   
        if( !objectp(target) || target->query("id") == "mu ren" )
                return notify_fail("�û�����ձȽϿ졣\n");
        
        if( !userp(target))
                return notify_fail("�㲻�ܶ���ʹ�û�����\n");

        if(!( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");
        if( objectp(ob = present("zhong shentong", room)) ) {
                if(target->query("id") == ob->query("winner"))
                        return notify_fail("�󵨣����Ҷ�����ͨ���û����󷨣�\n");
        }

        if( !living(target) || ! target->query("can_speak"))
                return notify_fail("�����ǻ��\n");

        if( me->query_temp("weapon"))
                return notify_fail("�����ʹ���������ץ������ץס���֡�\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua")
                return notify_fail("�����ʹ���������ץ������ץס���֡�\n");

        if( (int)me->query_skill("huagong-dafa",1) < 250 )
                return notify_fail("��Ĺ�������������ʩչ������\n");

        if( (int)me->query_skill("poison",1) < 200 )
                return notify_fail("�����ڵĶ��ز���������ʩչ������\n");

        if((int)target->query("max_jingli") <= 0 || target->query("combat_exp") < me->query("combat_exp")/2)
                return notify_fail( target->name() +"û���κξ����ɻ���\n");

        message_vision(BLU"ͻȻ$N��������һ����Ц����������������������͵���$n��ȥ��\n\n" NOR, me, target );

        if( random(me->query_int()) > target->query_int()/2) {
            message_vision(HBRED"$nҲ��һ����������˫��һ�ӣ�$n�ƺ�������ʲô������һ�����ã�\n\n" NOR, me, target );
            me->start_busy(2);
            target->start_busy(2);
            call_out("huagong", 2, me, target, 1);
        }

        if( !target->is_killing(me->query("id")) ){ 
                me->kill_ob(target);
                target->kill_ob(me);              
        }

        me->start_exert(3);

        return 1;
}

void huagong(object me, object target)
{
        object victim, *people;
        int i;

        if (!me || !target) return;
        me->start_busy(2);
        target->start_busy(2);
        if (target->query("max_jingli") < 1 || target->query_temp("huagong/count") > 10) {
            message_vision(RED"$n��$N�����˵�Ԫ�������̯�ڵ��ϡ�\n"NOR, me, target);
            message_vision(RED"$N����һЦ���ɿ����֡�\n"NOR, me, target);
            i = 50 + random(31);
            target->add("max_jingli", -i);
            target->add("eff_jingli", -i);
            target->add("jingli", -i);
            if (target->query("max_jingli") < 0) target->set("max_jingli",0);
            target->unconcious();
            target->delete_temp("huagong/count");
            me->remove_all_enemy();
            target->remove_all_enemy();
            return;
        }
        if (target->query_skill("douzhuan-xingyi") > 100 || 
            target->qyery_skill("qiankun-danuoyi") > 100){
             people = all_inventory(environment(me));
             i = random(sizeof(people));
             victim = people[i];
             if (victim != me && victim != target && victim->is_character() && living(victim) && !wizardp(victim)) {
                message_vision(HBRED"$N���һ����һǣһ������$nת����ǰ���ӹ��˶��ֵ�ħ�ƣ�\n"NOR, target, victim);
                target->remove_all_enemy();
                me->remove_all_enemy();
                huagong(me, victim);
                return;
             }
        }
        if (random(target->query("neili")) > me->query("neili")/2) {
            message_vision(RED"$nƴ�������Ԫ����ȫ������������$Nһ�ͣ�������$N�����ա�\n"NOR, me, target);
            target->add("max_neili",-5-random(5));
            return;
        }
        message_vision(RED"$nʹ�������������޷��ѳ�$N���գ�ֻ���þ���������ʧ��\n"NOR, me, target);
        me->add("potential", (me->query_skill("force") + random(me->query_skill("poison")))/20);
        i = 20 + random(11);
        target->add("max_jingli", -i);
        target->add("eff_jingli", -i);
        target->add("jingli", -i);
        target->add_temp("huagong/count", 1);
        call_out("huagong", 2, me, target);
}

