// tougu.c ͸����
// by snowman

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int exert(object me, object target)
{        
        object weapon;
        int damage,p;
        string msg, *limbs;
        weapon = me->query_temp("weapon");

        if( !target) target = offensive_target(me);
        if( !target || !me->is_fighting(target) || !living(target)
            || environment(target)!=environment(me))
                return notify_fail("͸����ֻ����ս���жԶ���ʹ�á�\n");
        if(!weapon)
                return notify_fail("�����ʹ������������͸�����ھ���\n");        
        if( (int)me->query_skill("shenghuo-shengong",1) < 100 )
                return notify_fail("���ʥ���񹦵ȼ�����������ʩչ͸�����ھ���\n");
        if( (int)me->query_skill("force", 1) < 100 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʩչ͸�����ھ���\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬����ʩչ͸�����ھ���\n");
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("����������㣬����ʩչ͸�����ھ���\n");
        if( (int)me->query("jingli") < 300 )
                return notify_fail("��ľ������㣬����ʩչ͸�����ھ���\n");
        if( target->is_busy()) 
                 return notify_fail("�Է����Թ˲�Ͼ�أ��㲻æʩչ͸�����ھ���\n");
                 
        tell_object(me, HIW"����������"HIB"͸����"HIW"����һ�ɼ�����������������һ�㣬��"+weapon->name()+"�ϴ�����ֱ��"+target->name()+"��\n"NOR);       
        if( random(me->query_skill("force")) > target->query_skill("force")/4
           || (!userp(target) && !me->query_skill("jiuyang-shengong"))){           
           
damage = me->query_skill("force");
if(me->query_skill("jiuyang-shengong")<=220) damage = damage *3;

           damage = damage/2 + random(damage);

           if(target->query_skill("force")-50 > me->query_skill("force"))
             damage = damage/2;            
           if(target->query_skill("force") > me->query_skill("force")*2)
             damage =1+ random(10);
           if(me->query_skill("force") > target->query_skill("force")*2)
             damage = damage*2 +random(damage);
           if(damage > 300)
              tell_object(target, HIB"\nͻȻ֮�䣬���ؿ�һʹ���ƺ���һö��ϸ�ļ������һ�¡���һ�´�ʹ
ͻ�������������Σ�ʵ���ʣ�һ�ɺ���ͻ����Ļ����񹦣�ֱ�����ķΣ�\n"NOR);
           else if(damage <= 10){
              damage = 10;
              tell_object(target, HIY"\nͻȻ֮�䣬���ؿ�һʹ���ƺ���һö��ϸ�ļ������һ�¡��Һ��㻤���񹦱�
��ȫ������������������˿��֮ϸ��ٿ�궸�����ѷ��ѵ���ȴҲ���㲻�ã�\n"NOR);
              tell_object(me, HIY"�����ˡ�͸���롱���ھ��������Է����Ǻ��������ĵֵ���������\n"NOR);
              }
           else tell_object(target, HIB"\nͻȻ֮�䣬���ؿڱ��������һ�¡���ʹ�����Σ�ʵ���ʣ�һ�ɺ���ͻ�����
�����񹦣�ֱ�����࣡�������壬������ʧ������һ�̿ɵ�����ʹ��ǣ�\n"NOR);

if( damage>= target->query("qi"))
damage = target->query("qi")-1;

           target->receive_damage("qi", damage, me);
           target->receive_wound("qi", damage/3, me);
           target->receive_damage("neili", damage/2, me); 
           limbs = target->query("limbs");
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"ͻȻȫ��һ������ͬ���������һ�£�\n" NOR, ({ target }));  
           msg = damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n";
           message_vision(msg, me, target);
if(userp(me) && me->query("env/damage"))             tell_object(me,WHT"���"+ target->query("name") +"�����"HIR+damage+ WHT"�㹥���˺���\n"NOR); 
if(userp(target)&& target->query("env/damage"))      tell_object(target,WHT""+ me->query("name") +"�Ĺ������������"RED+damage+ WHT"���˺���\n"NOR); ;
        //   me->start_busy(1);
           me->add("neili", -150);
           me->add("jingli", -20);
           target->start_busy(2+random(4));
           return 1;
           }
         
     else {
          me->add("neili", -50);
          me->add("jingli", -5);
          tell_object(me, HIY"���͸�����ھ���û����"+target->name()+"���Ѿ�ɢ�ˡ�\n"NOR);
          me->start_busy(1);         
          }
        return 1;
        
    me->start_exert(2,"͸����");

}
