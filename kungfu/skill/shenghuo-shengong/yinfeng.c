// yinfeng.c ���絶
// by snowman
// Modify By River@SJ ������9�����Ч�� 2000.2.22
// Update By Lsxk@hsbbs ����10lvlʹ��Ҫ�� 2007/6/11
#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string exert_name() {return HIW"���絶"NOR;}

int exert(object me, object target)
{        
        object weapon;
            int damage, p, force, lvl;
        string msg;
        weapon = me->query_temp("weapon");

        if( !objectp(target)) target = offensive_target(me);
        if( !target || !me->is_fighting(target) || !living(target)
            || environment(target)!=environment(me))
                return notify_fail("���絶ֻ����ս���жԶ���ʹ�á�\n");   
       
        if (me->query_skill_mapped("dagger") != "shenghuo-lingfa")
                return notify_fail("������Ƚ�ʥ�������ʥ�����໥��ϡ�\n");

        if(!weapon)
                return notify_fail("�����ʹ���������������絶�ھ���\n");   

        if( weapon->query("skill_type") != "dagger" )
                return notify_fail("�����ʹ��ذ���������絶�ھ���\n");     

        if( (int)me->query_skill("shenghuo-shengong",1) < 120 )
                return notify_fail("���ʥ���񹦵ȼ�����������ʩչ���絶�ھ���\n");

        if( (int)me->query_skill("shenghuo-lingfa",1) < 120 )
                return notify_fail("���ʥ����ȼ�����������ʩչ���絶�ھ���\n");

        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʩչ���絶�ھ���\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬����ʩչ���絶�ھ���\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("����������㣬����ʩչ���絶�ھ���\n");

        if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ������㣬����ʩչ���絶�ھ���\n");

        me->start_exert(4, "���絶");
//        me->start_perform(4, "���絶"); 

        force = me->query_skill("force") + me->query_skill("jiuyang-shengong", 1)/2 + me->query_skill("shenghuo-shengong", 1)/5;
        lvl = me->query_skill("jiuyang-shengong", 1) + me->query_skill("jiuyang-shengong", 1);

        tell_object(me, HIW"\n������ʹ��"BLU"���絶"HIW"������һ���������ʵ�����֮����ֱ��"+target->name()+"�ؿ�����ҪѨ��\n"NOR); 

   if( random(force)*(me->query_temp("yinfeng/time")+1) > target->query_skill("force")/3
         && me->query("combat_exp")/2 *(me->query_temp("yinfeng/time")+1) > random(target->query("combat_exp")/3)){

                me->delete_temp("yinfeng/time");
                damage = force;
                damage += random(damage);                
               
                if(target->query_skill("force")-100 > force)
                           damage /= 2;                  
                if(target->query_skill("force") > force * 2)
                           damage = random(50);
                if( force > target->query_skill("force")*2)
                           damage *= 2;
                if(me->query("neili")+ lvl*2 > target->query("neili")*2)
                           damage *= 2;
                else
                 if(me->query("neili")+ lvl*2 > target->query("neili"))
                           damage += random(damage/2);
                else
                 if(target->query("neili") > me->query("neili")*2 + lvl*4)
                           damage /= 2;
                               
                if(target->query("combat_exp") > me->query("combat_exp")*2 + lvl* 2000 )
                           damage /=2;
                   
                else
                 if(me->query("combat_exp")+ lvl* 1000 > target->query("combat_exp")*2)
                           damage *= 2; 
                          
                else
                 if((me->query("combat_exp")+ lvl)/3*2 > target->query("combat_exp"))
                           damage += random(damage/2); 
                damage += (me->query_skill("jiuyang-shengong")+random(me->query_skill("jiuyang-shengong",1)));

                if (damage > 2000) damage = 2000 +(damage - 2000)/100;

                if (damage > 1500){
                           tell_object(target, HIB"\nͻȻ֮�䣬һ���������ʡ�������е�����֮��ֱ�������ؿڵġ�����Ѩ���У�\n"+
                                               HIR"����ʱ֮�������Ϣ��ȫ�������ã�\n"NOR);
                           target->start_busy(3+random(2));
                }
                else if(damage <= 50){
                           damage = 10;
                           tell_object(target, HIY"\nͻȻ֮�䣬һ��������а������֮��ֱ�����ؿڵ�����Ѩ��\n"+
                                                  "�Һ��㻤���񹦱黤ȫ��������絶������ȴҲ���㲻�ã�\n"NOR);
                           tell_object(me, HIY"���������絶���ھ��������Է����Ǻ��������ĵֵ���������\n"NOR);
                }
                else{
                           tell_object(target, HIB"\nͻȻ֮�䣬һ�������絶���罣����ذ�����䣬ֱ�������ؿڵġ�����Ѩ���У�\n"+
                                               HIR"����ʱ֮�������Ϣ��ȫ����䣡\n"NOR);
                           target->receive_wound("qi", damage/2, me);
                           target->start_busy(1+random(2));
                }
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                target->receive_damage("neili", damage, me); 
           
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                tell_room(environment(target), HIR + target->name()+"ͻȻȫ���͵�һ�������ֽ���������������ݷ�ʲô�����ؿڴ��ͻ���һ���Ƶģ�\n" NOR, ({ target })); 
                msg = damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n"; 
                message_vision(msg, me, target);          
                target->start_busy(2+random(4));
                me->start_busy(1);
                me->receive_damage("neili", -damage/3);
                me->receive_damage("jingli", 70);
                }
         
        else {       
                me->add_temp("yinfeng/time",1);
                if(me->query_temp("yinfeng/time")>3) me->set_temp("yinfeng/time",3);
                me->receive_damage("neili", 100);
                me->receive_damage("jingli", 15);
                tell_object(me, HIY"������絶�ھ���û����"+target->name()+"��������Ѿ�ɢ�ˡ�\n"NOR);
                me->start_busy(2); 
        }
        return 1;
}
