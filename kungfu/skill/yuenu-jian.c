// yuenu-jian.c

inherit SKILL;
#include <ansi.h>
#include <combat.h>

string *dodge_msg = ({
HIR"$n������ӣ��������������羪�裬�����������ܿ���$N���������ơ�\n"NOR,
HIC"$nƮ��������������������������磬ֱָ$N���������ڣ�$N���ò����л��ء�\n"NOR,
HIG"$n����ƮƮ���·�����֮���£�Ʈ�u�������ѩ������$N���ϲ���֮����\n"NOR,
HIM"$n����Ʈ�ɣ���ȹ���ƣ������ּ侫�����贩�У�˿������$N��Ӱ�죡\n"NOR,
HIW"$n��Ȼ΢Ц����ȹ���裬��Ų����������ˮ�����������$N�����Ҳ���˿��������\n"NOR,
});

string *msg = ({
HIW"$Nͦ��ֱ�̣�ٿ��ٿ����$w"+HIW"����һ�����磬���в���$n��$l��������ɣ�������磡"NOR,
HIC"$N����һ������$n������ƽƽ���棬ȥ��ȴ�Ǿ��죬ֱ�������ƿգ�������Ծ��"NOR,
HIM"$NԾ���գ��ؽ��»���$w"+HIM"�ó�������������������˸��������ӷ�к���չ�ɽ����"NOR,
HIB"$N����$w"+HIB"�����̳����������縡����Ӱ,��������,����������Ծ,���ݼ��ţ�"NOR,
HIY"$N���󽣾���$w"+HIY"������Ծ�裬�Ȼ����,һ��ƥ����Ľ�âѸ�����䣬����$n��$l�� "NOR,
HIG"$N������㣬$w"+HIG"����������ó���ǧ����Ӱ����$nȦ�����У�������磬���������� "NOR,
HIR"$N���������˽���һ��$w"+HIR"��â���ǣ��ݺ���裬��ը���꣡ "NOR,
HIB"$N����һ����$w"+HIB"��âһ�����գ�$nֻ���ǽ���Ѹ����磬����ü�ޣ�Ψ�м��ٷ��ˣ� "NOR,
});

string *feiyue_msg = ({
HIW"$Nͦ��ֱ�̣�ٿ��ٿ����$w����һ�����磬���в���$n��$l��������ɣ�������磡",
HIC"$N����һ������$n������ƽƽ���棬ȥ��ȴ�Ǿ��죬ֱ�������ƿգ�������Ծ��",
HIM"$NԾ���գ��ؽ��»���$w�ó�������������������˸��������ӷ�к���չ�ɽ����",
HIB"$N����$w�����̳����������縡����Ӱ,��������,����������Ծ,���ݼ��ţ�",
HIY"$N���󽣾���$w������Ծ�裬�Ȼ����,һ��ƥ����Ľ�âѸ�����䣬����$n��$l�� ",
HIG"$N������㣬$w����������ó���ǧ����Ӱ����$nȦ�����У�������磬���������� ",
HIR"$N���������˽���һ��$w��â���ǣ��ݺ���裬��ը���꣡ ",
HIB"$N$w����һ����$w��âһ�����գ�$nֻ���ǽ���Ѹ����磬����ü�ޣ�Ψ�м��ٷ��ˣ� ",
});


int valid_enable(string usage)
{
                return (usage == "sword") || (usage == "parry") || (usage =="dodge") || (usage == "dagger") || (usage == "stick");
}

int valid_learn(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
/*
        if(me->query("gender") != "Ů��" )
                return notify_fail("��ԽŮ������Ů��ʹ�ã���æ��ɶ����\n");
*/
        if ( me->query("max_neili") < 1000)
                return notify_fail("�������������\n");

        if ( me->query_skill("yuenu-jian",1) > 150 && me->query_skill("yuenu-jian", 1) < 220 )
                return notify_fail("ԽŮ������΢֮������ѧϰ��\n"); 

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, j, level, damage;

        level = me->query_skill("yuenu-jian", 1);
        i = random(me->query_skill("sword"))+50;
        if( i<100 ) i = 100;
        j = random(40)-5;
        damage = (random(6)+1)*35;
        if( damage < 150 ) damage =150;

                if( level > 450 ) {
                        return ([
                        "action": msg[random(sizeof(msg))],
                        "damage": 320 + random(280),
                        "damage_type": "����",
                        "dodge":  220+random(30),
                        "force":  250 + random(300),
                        "parry":  150 + random(150),

                        ]);
                }

                else return ([
                        "action": msg[random(sizeof(msg))],
                        "damage": 280 + random(180),
                        "damage_type": "����",
                        "dodge":  120+random(30),
                        "force":  250 + random(300),
                        "parry":  50 + random(50),
                ]);
        }


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me)
{
         if ( me->query_skill("yuenu-jian", 1 ) < 300)
                return notify_fail("ԽŮ��ֻ��ͨ����������ߡ�\n"); 
 
         if ( me->query("jingli") < 50)
                 return notify_fail("�������������ԽŮ����\n");
         if ( me->query("neili") < 20)
                 return notify_fail("�������������ϰԽŮ����\n");
        me->receive_damage("jingli", 40);
         me->add("neili", -15);
         return 1;
 }


string perform_action_file(string action)
{
        return __DIR__"yuenu-jian/" + action;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon, weapon1;
        int i;
        weapon = me->query_temp("weapon");
        weapon1= victim->query_temp("weapon");

        if( !objectp(weapon) ) return;

        i = me->query_skill("yuenu-jian", 1);

   if(i>=350){
       if(random(i)>(int)victim->query_skill("parry",1)*2/3
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIG"$N���д�����ɣ�������磬�����޷�����ܿ���\n"NOR,me,victim);
            victim->set_temp("must_be_hit",1);
            call_out("dgjj_must_be_hit",2,me,victim,random(i/50));
       }
   }

   if(i>=250){
       if(random(i)>(int)victim->query_skill("dodge",1)/2
        &&!victim->query_temp("must_be_hit")
        &&!victim->query_condition("no_fight")){
            message_vision(HIR"$nֻ��$N����Ѹ����磬����ü�ޣ�ֻ�������мܺ��޻���֮����\n"NOR,me,victim);
            victim->set_temp("no_fight",1);
            victim->apply_condition("no_fight",1);
       }
   }

        if( weapon1 && i > 200 && living(victim)
         && me->query_skill_mapped("parry") == "yuenu-jian"
         && random(me->query("combat_exp")) > victim->query("combat_exp")/2 ) {
                message_vision(HIM"$N������֮����һתһ�࣬��$n���������ܿ�������"+weapon->name()+HIM"�͵�һ��������$n����֮�ϣ�\n"NOR, 

me,victim);
                if( random(me->query("int")) > victim->query("int")/3 ) {
                        me->add("neili", -50);
                   victim->add_busy(1+random(2));
                        message_vision(HIR"$Nֻ������һ���ʹ��Ǻ�һ����"+weapon1->name()+HIR"���ֶ�����\n"NOR, victim);
                        weapon1->unequip();
                     victim->apply_condition("broken_arm",5); 
                        weapon1->move(environment(victim));
                }
                else {
                        message_vision(HIC"$n���´󺧣���æ���У������ܹ���\n"NOR, me,victim);
                    me->start_perform(1,"������");
                    victim->add_busy(1+random(2));
                       }
        }
     
}

void dgjj_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(CYN"$n���ڻ��������������ָ���������\n"NOR,target);
        return;
    }
    if(wizardp(me) && me->query("env/dgjj_test")) write("i is "+i+"\n"NOR);
    if(me->query_skill_mapped("sword")!="yuenu-jian"
     ||me->query_skill_mapped("parry")!="yuenu-jian"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n���ڻ��������������ָ���������\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("dgjj_must_be_hit",1,me,target,--i);
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1;
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("yuenu-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

        if( me->query("jiali") 
        && skill+50 > random(ob->query_skill("parry", 1)/3)
        && wp 
        && skill > 100
        && me->query_skill_mapped("parry") == "yuenu-jian"
        && living(ob)
        && !me->is_busy()){
                if(wp1){
                        msg = HIR"$N���⼲��$n��"+wp1->name()+HIR"֮����\n"NOR;
                        msg = replace_string(msg, "$w", wp1->name());
                        if(neili >= random(neili1+damage)){
                                if(random(me->query_dex(1)) > ob->query_str(1)/3 && skill > 120){
                                        msg += HIW"������õ���$n������$nֻ������һ���ʹ����ʽ��ʱ�޷����ᣡ\n"NOR;
                                        ob->add_busy(2+random(2));
                                        j = -(damage);
                                }
                                else{
                                        ob->receive_damage("qi", damage/10, me);
                                        ob->receive_wound("qi", damage/10, me);
                                        p = ob->query("qi")*100/ob->query("max_qi");
                                        msg += COMBAT_D->damage_msg(damage/20, "�˺�");
                                        msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                        j = -(damage/2+skill/2);
                                }
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += "$n�������裬�����Ǽ���\n";              
                                j = -(damage/2+skill/2);
                        }
                        else{
                                j = damage/2+random(damage/2);
                                if(j<damage/2) msg += "$n�������裬�����Ǽ���\n";
                                else msg += "$n�������裬�����Ǽ���\n";
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
                else{
                        msg = HIY"$N�������ã�"+wp->name()+HIY"�̳���������������$n˫Ŀ��\n"NOR;
                        if(neili >= neili1+random(neili1)+damage){
                                ob->receive_damage("qi", damage/10, me);
                                ob->receive_wound("qi", damage/10, me);
                                p = ob->query("qi")*100/ob->query("max_qi");
                                msg += COMBAT_D->damage_msg(damage, "����");
                                msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
                                j = -(damage*2+skill);
                        }
                        else if(neili >= random(neili1)+damage){
                                msg += "$n�������裬�����Ǽ���\n";              
                                j = -(damage+skill);
                        }
                        else{
                                j = damage/2+random(damage/2); 
                                if(j<damage/2) msg += "$n�������裬�����Ǽ���\n";
                                else msg += "$n�������裬�����Ǽ���\n";
                                j = -j;
                        }
                        message_vision(msg, me, ob);
                        return j;
                }
        }

   if ( random(me->query("kar")) >= 10 )
{
   message_vision(HIR"$N����ȻһЦ���������ӣ�������������ˮ���Եй��ƾ��ǲ��Ų��ʣ�\n" NOR, me);
  return -damage;      }
}
