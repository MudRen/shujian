// Created by LSXK@hsbbs 2007/5/10
// ci.c ��ҽ���֮�������̡�.

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
string perform_name() {return HBBLU"������"NOR;}
int perform(object me, object target)
{
        object weapon;
        int damage,p,j;
        string msg,dodge_skill;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("�������̡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("miaojia-jianfa", 1) < 150 )
                return notify_fail("�����ҽ�������̫ǳ��ʹ������ҽ���֮�������̡��Ĺ���!\n");

        if( (int)me->query_skill("sword", 1) < 150 )
                return notify_fail("��Ļ�������̫��,ʹ�����������̡��Ĺ���!\n");

        if( (int)me->query("max_neili") < 800 )
               return notify_fail("���������Ϊ̫ǳ��ʹ�����������̡���\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������ʹ�����������̡�����\n");

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
            || me->query_skill_mapped("sword") != "miaojia-jianfa")
                return notify_fail("�㲻ʹ����ҽ���,���ʹ���ˡ������̡�?\n");
                 
       if(me->query_temp("mjjf/lianhuan")
         &&!me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach"))
           return notify_fail("������ʹ�á���������������\n");

        me->set_temp("mjjf/ci", 1); 

        message_vision(HBBLU +HIW "\n$NͻȻ����������ֻ�����е�"+weapon->name()+HBBLU+HIW"���ˡ���һ�����죬�����������֮�ƴ���$n��\n"NOR,me,target);

        if( random(target->query_skill("dodge"))<me->query_skill("dodge")/2
           || random(me->query("combat_exp"))>target->query("combat_exp")/3
           || random(me->query_skill("miaojia-jianfa")+me->query_skill("sword")) > target->query_skill("parry") ){
           damage = 3 * (int)me->query_skill("miaojia-jianfa", 1) + (int)me->query_skill("sword",1);
           damage = damage + random(damage) + 10 * (me->query("jiali")+(int)me->query_skill("miaojia-jianfa",1));
           if ( me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
           && me->query_temp("lqsg/lq") ) {
               damage = damage*2;
               message_vision(HIW "$N������"HIB"��Ȫ"HIW"���ھ����㸽��"+weapon->name()+HIW"�ϣ���ʱ��"+weapon->name()+HIW"��������֮����ֻ��$n��\n"NOR,me,target);
           }
           if (wizardp(me))
               write(HIR"damage is; "+damage+" !\n"NOR);
           me->add("neili", -damage/10);
           me->add("jingli",-500);
           if(damage>5000) damage=4500+random(500);
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage*2/3);
           if ( me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
           && me->query_temp("lqsg/lq") ) 
               msg = HIB"����$Nһ����ȣ����ţ�����"+weapon->name()+HIB"�Ѿ���$n�ؿڶԴ�������������Ѫ˲���$n�ؿ����˳������ۼ��ǻ���ˡ�\n"NOR;
           else msg = HIR"����$Nһ����ȣ����ţ�����"+weapon->name()+HIR"�Ѿ���$n�ؿڶԴ�������������Ѫ˲���$n�ؿ����˳������ۼ��ǻ���ˡ�\n"NOR;
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           target->set_temp("last_damage_from", me);
           msg += damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           msg = replace_string( msg, "$l", "�ؿ�" );
           msg = replace_string( msg, "$w", weapon->name());
		message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+ damage+ WHT"���˺���\n"NOR); ;
           //by spiderii@ty ����ж�̫...�ֲ��ˡ�.auto call->die()...admire lsxk 

j = target->query("str");
if (j < 50) j =  target->query("con");
if (j < 50) j =  target->query("dex");
if (j < 50) j =  target->query("int");

        if(j<50)  if (random(target->query("kar")) < 2){

                 message_vision(RED"$n���������˺�����������˫�۾��ֵؿ���$N,����֧�ֲ�ס�������ˡ�"NOR, me, target);
                 target->die();
           }
        } 
        else {
		string tmp;
              msg = HIG"$n����һ���������֮�ͣ��ĸ�������У���æ�����Ṧ�����Ա�һԾ��ԶԶ�Ķ��˿�ȥ��\n"NOR;
              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              if (stringp(tmp = SKILL_D(dodge_skill)->query_dodge_msg(target, 1)))
		      msg += tmp;
              me->add("neili", -100);
              me->start_busy(1); 
              target->add_busy(random(2)+1); 
                
		message_vision(msg, me, target);
        }
        me->delete_temp("mjjf/ci"); 

        me->start_perform(3, "�������̡�");
        return 1;
}

int help(object me)
{
   write(WHT"\n��ҽ�����"HBBLU+HIW"������"NOR+WHT"����"NOR"\n");
   write(@HELP
   �������̡��������������֣������˸е��ľ���ս�������쳣��ʵ����
   �������Ǳ����л��У����±�Ҫ���Ӧ�����е����֣�������ʹ���߻�
   ���־�ѧ��Ȫ��֮����Ȫ�����������ศ��ɣ�������ʢ��

   Ҫ��  ���� 400 ���ϣ�
           ������� 800 ���ϣ� 
           ��ҽ��� 150 ���ϣ�
           �������� 150 ���ϣ�

HELP
   );
   return 1;
}
