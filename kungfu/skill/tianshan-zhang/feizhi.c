//by caiji@SJ
//�����������˲�����3�ᣬ975ҳ1996��11����ӡ��/�������������
// By Spiderii@ty ȡ��call die��Ч���ж�
#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
string perform_name(){ return HIC"����"NOR; }
int perform(object me, object target)
{
        object weapon;
        int damage,p;
        string msg,dodge_skill;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("tianshan-zhang", 1) < 100 )
                return notify_fail("�����ɽ�ȷ�����̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("staff", 1) < 100 )
                return notify_fail("��Ļ����ȷ�����̫ǳ���������ˡ�\n");

        if( (int)me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("����ڹ�����̫ǳ���������ˡ�\n");
                
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������̫ǳ���������ˡ�\n");
        if( (int)me->query("neili") < 200 )
                return notify_fail("��������������������ˡ�\n");
        if (me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("����ʲôΪ�ڹ�������ʹ��������?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff"
            || me->query_skill_mapped("staff") != "tianshan-zhang")
                return notify_fail("��ʹ���ˡ�������ô?\n");
                 
        me->set_temp("tsz/feizhi", 2); 

        message_vision(BLU "\n$N���һ���������š�������һ�����죬$N�����е�"+weapon->name()+"����$n"+BLU"��\n"NOR,me,target);

        if(   random(target->query_skill("dodge"))/2<me->query_skill("dodge")
           || random(me->query("combat_exp"))>target->query("combat_exp")/3){
           damage = 4 * (int)me->query_skill("tianshan-zhang", 1);
           damage = damage * 3 + random(damage)*2 + 5*me->query("jiali");
if(userp(target)) damage /=5;
           me->add("neili", -damage/10);
           me->add("jingli",-100);
           if(damage>5000) damage=5000+random(200);
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/4);
           msg = HIR"$n������������������"+weapon->name()+"���ػ��У�\n"NOR;
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"RED+ damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           target->set_temp("last_damage_from", me);
           msg += damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           msg = replace_string( msg, "$l", "�ؿ�" );
           msg = replace_string( msg, "$w", weapon->name());
		message_vision(msg, me, target);
if(weapon->query("imbued")<4)             weapon->move(environment(me));
        } 
        else {
		string tmp;

              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              if (stringp(tmp = SKILL_D(dodge_skill)->query_dodge_msg(target, 1)))
                      msg = tmp;
              me->add("neili", -100);
              me->start_busy(1); 
if(weapon->query("imbued")<4)
                if( weapon->unequip())
                if( random(target->query("kar"))<10
                &&(int)target->query_encumbrance() *100 / (int)target->query_max_encumbrance()<85) {
                	weapon->move(target);
                	msg = HIY"$n��������һ�ӣ���ѷ�����"+weapon->name()+"�������У�\n"NOR;
                }
                else if(random(target->query("kar"))<5 && weapon->query("imbued")<4 ){
                        weapon->move(environment(me));
                        msg = HIY"$n�����������ϣ����ŷ�����"+weapon->name()+"һ����"+weapon->name()+"��ʱ��Ϊ���ˣ�\n"NOR;
                        weapon->set("name", "�ϵ���" + weapon->name());
                        weapon->set("value", 0);
                        weapon->set("weapon_prop", 0);
                }
                else if(weapon->query("imbued")<4 ) weapon->move(environment(me));
                
		message_vision(msg, me, target);
        }
        me->delete_temp("tsz/feizhi"); 
        me->start_perform(1+random(2), "��������");
        return 1;
}
