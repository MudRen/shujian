// guifei С�����
// created by olives@SJ
// Update By lsxk@hsbbs 2007/6/6
/*
     ��������Դ��������Լ��ؿ����䣬���˼ܾ��е�һ����Ȼ��գ���˳����
����һ����ڽ����������������ذ�׵����ֳ�ȭ������һȭ���ڽ������ģ�
ֻ�ǽ������ϡ���������ԵУ���һ����Ȼ�����˵��˱��ġ�ΤС���ִ��һ��
�����ã���

*/
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include <combat_msg.h>

string perform_name() {return HIR"С�����"NOR;}

int perform(object me, object target)
{
        object weapon;
        string msg;
        int lvl,i;

        if(!target) target = offensive_target(me);

         if( !objectp(target)
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("��С����¡�ֻ����ս��ʱʹ�ã�\n");

        if(me->query("family/master_id")!="hong antong")
                return notify_fail("��С����¡�ֻ�а��˽���������ã�\n");

        if(!objectp(weapon=me->query_temp("weapon"))
        || weapon->query("skill_type") != "dagger")
             return notify_fail("������û��ذ�ף����ʹ�á�С����¡���\n");
        
        if((int)(me->query("dex")+me->query_skill("dodge",1)/10) < 30 )
                return notify_fail("����������ʹ�á�С����¡������»��˵��Լ���\n");

        if((int)me->query_skill("tenglong-bifa", 1) < 250 )
                return notify_fail("�������ذ������������������ʹ�á�С����¡���\n");

        if((int)me->query_skill("dagger",1) < 250)
                return notify_fail("��Ļ���ذ����������������ʹ�á�С����¡���\n");
/*
        if(me->query_skill_mapped("strike") != "huagu-mianzhang"
        || me->query_skill_prepared("strike") != "huagu-mianzhang")
                return notify_fail("������û������׼�����޷�ʹ�á�С����¡���\n");
*/
        
        if(me->query_skill_mapped("dagger") != "tenglong-bifa")
                return notify_fail("ֻ��ʹ������ذ��ʱ����ʹ�á�С����¡���\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 250 )
                return notify_fail("��Ķ����󷨹������㣬�����á�С����¡���\n");

        if( (int)me->query_skill("force", 1) < 250 )
                return notify_fail("��Ļ����ڹ��������㣬�����á�С����¡���\n");

        if((int)me->query("max_neili", 1) < 4000)
                return notify_fail("���ֵ�������Ϊ���㣬����ʹ�á�С����¡���\n");

        if((int)me->query("eff_jingli", 1) < 2500)
                return notify_fail("���ֵľ�����Ϊ���㣬����ʹ�á�С����¡���\n");

        if((int)me->query("jingli", 1) < 800)
                return notify_fail("�����ھ������㣬����ʹ�á�С����¡���\n");

        if((int)me->query("neili", 1) < 1500)
                return notify_fail("�������������㣬����ʹ�á�С����¡���\n");
/*
        if(me->query("gender") == "����" )
                return notify_fail("����Ů����ô��ʹ�á�С����¡��أ�\n");
*/
        if( me->query_skill_mapped("force") != "dulong-dafa")
                return notify_fail("��������ʹ�õ��ڹ�ͬ�������໥�ִ�������ʹ�á�С����¡���\n");

        msg = HIR"$N��$n��������֮����ƴ��ȫ��ʹ���շ��˲���֮����������С����¡�"NOR;
        msg +=MAG "\n$Nʹ��һ�С�С����¡����Դ�������Լ��ؿ����䣬˳���ڵ���һ��������\n��$n������������ű��������ֳ�ȭ��$n�����������¡�\n"NOR;
        lvl = ((int)me->query_skill("tenglong-bifa",1)+(int)me->query_skill("huagu-mianzhang",1)+(int)me->query_skill("dagger",1))/3;
        message_vision(msg,me,target);
        me->receive_damage("jingli",100);
        me->receive_damage("neili",300);
        me->add_temp("apply/strength",lvl/8);
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/damage",lvl/3);
        me->set_temp("sld/pfm/xiaolian",1);
             i=3;
if(!userp(target) || lvl>=450 ) target->add_busy(2);
        COMBAT_D->do_attack(me,target,weapon,i);
        if(objectp(target) && me->is_fighting(target))
        {
//                weapon->unequip();
                COMBAT_D->do_attack(me,target,weapon,i);
//                weapon->wield();
        }
        if(objectp(target) && me->is_fighting(target))
                COMBAT_D->do_attack(me,target,weapon,i);
        if(objectp(target) && me->is_fighting(target))
        {
                if(random(me->query("combat_exp"))>target->query("combat_exp")/3)
                        COMBAT_D->do_attack(me,target,weapon,i);
                else
                        COMBAT_D->do_attack(me,target,weapon,TYPE_RIPOSTE);
        }
        me->delete_temp("sld/pfm/xiaolian");
        me->add_temp("apply/strength",-lvl/8);
        me->add_temp("apply/attack",-lvl/2);
        me->add_temp("apply/damage",-lvl/3);

        me->start_busy(1);
        me->start_perform(3+random(2),"��С����¡�");
        return 1;
}

int help(object me)
{
   write(WHT"\n����ذ����"HIR"С�����"WHT"����"NOR"\n");
   write(@HELP

    Ҫ��������� 4000 ���ϣ�
          ����� 2500 ���ϣ�
          ��ǰ���� 1500 ���ϣ�
          ��ǰ���� 800 ���ϣ�
          ����ذ���ȼ� 250 ���ϣ�
          ����ذ���ȼ� 250 ���ϣ�
          �����󷨵ȼ� 250 ���ϣ�
          �����ڹ��ȼ� 250 ���ϣ�
          ������ 30 ���ϣ�
          �Ա����� Ů�ԡ�
HELP
   );
   return 1;
}
