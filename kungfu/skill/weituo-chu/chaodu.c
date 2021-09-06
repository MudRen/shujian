

#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, club, i,ap,pp;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("�����ȼ��֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "club" )
                return notify_fail("�������޹����������á����ȼ��֡�����\n");

/*
        if( me->query_temp("sl_chaodu") )
               return notify_fail("�����ȼ��֡��������ܼ���̫��������Υ��ͣ����ɶ��ã�\n");
*/
        if(me->query("menggu"))
                return notify_fail("�����ַ��Ű��࣬����ܹ����÷����񹦡�\n");

        if(me->query_temp("sl_leidong"))
               return notify_fail("������ʹ��Τ���Ƶġ��׶����졹��ȫ�������Ѿ���ע�����б����У���Ͼ�����ˡ�\n");

        if((int)me->query_skill("weituo-chu", 1) < 300 )
               return notify_fail("�㡸Τ���ơ���Ϊ����������δ�����򡸳��ȼ��֡���\n");

        if((int)me->query_str()-(int)me->query_temp("apply/strength")<50)
               return notify_fail("��������������޷��ó������ȼ��֡�\n");

        if((int)me->query("con")+(int)me->query_skill("force",1)/10<50)
               return notify_fail("��ĸ��ǲ������޷����ܡ����ȼ��֡��Ľ�մ�����\n");

        if((int)me->query_skill("buddhism",1) < 150)
               return notify_fail("��������Ϊ����������δ�����򡸳��ȼ��֡���\n");

        if((int)me->query_skill("jingang-quan",1) < 300)
               return notify_fail("�����ȼ��֡����Խ�մ����������޼᲻�ݣ�����ȭ��Ϊ��ǳ��?\n");

        if( me->query_skill("yijin-jing", 1) < 300 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("�����õ��ڹ��롸���ȼ��֡��ķ���㣣�\n");

        if (me->query_skill_mapped("club") != "weituo-chu"
         || me->query_skill_mapped("parry") != "weituo-chu")
                return notify_fail("�������޷�ʹ�á����ȼ��֡����й�����\n");

        if( me->query("max_neili") < 5000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ�����ȼ��֡���\n");

        if( me->query("neili") <= 2000 )
                return notify_fail("�����������������������ʩչ�����ȼ��֡���\n");

        if( me->query("jingli") <= 1500 )
                return notify_fail("��ľ������ޣ�������ʩչ�����ȼ��֡���\n");

        message_vision(HIR"\nͻȻ$N��¶��⣺�����ȼ��֡������α��ǣ���ͬΤ����������һ�㣬��ȭͻ������"+weapon->name()+HIR"���У�"+weapon->name()+HIR"�����������һ������$n��\n" NOR, me,target);
       
/*
        weapon->move(environment(me));
        weapon->set("name", weapon->query("name")+"����Ƭ");
        weapon->unequip();
        weapon->set("value", 0);
        weapon->set("weapon_prop", 0);
*/
        damage = (int)me->query_skill("club") + (int)me->query_skill("buddhism",1);
        club = me->query_skill("club")/3;
        i = 10+random(me->query_skill("buddhism",1)/20);
        damage = damage*i;
        if(me->is_killer(target->query("id")))
                damage = damage *2/3;
        if(!target->is_killer(me->query("id")))
                damage = damage *2/3;
        if (wizardp(me))
                write(sprintf("damage = %d\n",damage));
        ap = COMBAT_D->skill_power(me,"club",SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target,"parry",SKILL_USAGE_DEFENSE);
        if(target->is_busy())
                pp /= 2;
        if(me->query("real_yjj"))
                {
                        damage *=2;
                        ap *= 2;
                        pp /= 2;
                }
//      me->set_temp("sl_chaodu",1);
        if(random(ap+pp)>pp)
        {
                me->add("neili", -1000);
                me->add("jingli", -800);
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                message_vision(HIY"\n$n���������ô���ͰԵ�����ʽ,�мܲ�������"+weapon->name()+HIY"���У��߹ǵ����������ѣ�\n" NOR, me,target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); ;
                COMBAT_D->report_status(target);
                target->start_busy(2+random(1));
                
      //        call_out("remove_effect2", club*/3, me);
       }
       else {
                message_vision(HIY"\n$n�ۼ�$N�����׺ݣ������мܣ��������ػ��У����������ɣ������������һ����\n" NOR, me,target);
                me->add("neili", -1500);
                me->add("jingli", -800);
                
       //       call_out("remove_effect2", club*/3, me);
       }
    message_vision(HIY"\n$N������𣬷��ֽ�"+weapon->name()+HIY"�������У�˳���ֻӳ�������\n" NOR, me,target);
        if(!userp(me)) club = club / 2;
        me->add_temp("apply/attack", club);
        me->add_temp("apply/damage", club);

if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
if(me->is_fighting(target))
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

        me->add_temp("apply/attack", -club);
        me->add_temp("apply/damage", -club);
                me->start_perform(4+random(2),"�����ȼ��֡�");

       return 1;
}

/*
void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("sl_chaodu");
        tell_object(me, HIG"\n�㾭��һ��ʱ���������ԣ��ֿ�����ʹ�á����ȼ��֡��ˡ�\n"NOR);
}
*/
 string perform_name(){ return HIY"���ȼ���"NOR; }
int help(object me)
{
        write(
@HELP
���ȼ���
       �Ƿ����񹦣�����Τ���ơ������⹥���������б�������������֡�
       ���ǡ�Τ���ơ����ռ���ʽ��
       ��ҪΤ����350��
           �׽350��
           ��ϴ���ȭʹ��
HELP
        );
        return 1;
}

