// �ط������
// Modified by Lane@SJ 2005/4/15
// By Spiderii�����Ծ

#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

string *msg = ({
"$Nһʽ�����Ϯ�¡�������ƽָ��������磬һ�ɽ���ֱ�ӳ���$n�����������͹�$n��$l",
"$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ��Ʈѩ���ơ���$w�Ľ������һƬѩ����ֱ��$n��$l",
"$N����$wбָ���죬һʽ��ǧ�徺�㡹���������������⣬��������������$N������$n��$l",
"$Nһʽ���������ڡ���$w���϶��»�������һ���󻡣���һ�п��ƻ�������ͻȻ������$n��$l�̳�",
"$N����š����һʽ��������������$w����ƽ�����������棬ʵ�����̲ؾ�������������������$n��$l",
"$Nһʽ��������ɳ����ȫ������ƽ�ɣ�����һ����ʱ�䱼��$n�����������ش���$n��$l",
"$Nʩ�����������Ρ���$w���ַɳ����������㰿������ƿ�֮��է�죬����$n��$l",
"$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų�������ѩ����â����ҫ��ʣ�ʹ��$n�޿��ʴ�",
});

string *feiyue_msg = ({
""HIC"$N$w"HIC"��ʽ���䣬�������ߣ������Ľ���ʽ�����н�����"WHT"��ͨ�˴�"HIC"�������ǵ�������������������"NOR"",
""HIC"$N��Ҳ����$n����ʽ������$w"HIC"��â���£������Ƿɣ�һ�С�"HIG"�����Ὥ"HIC"�����Ͷ��ϣ���������֮������˪�������Ǳ��޿ɱ�"NOR"",
""HIC"$N��ת�������Խ���ָ��һ�С�"HIR"һ��ָ"HIC"�����ɵ�$n�����ϡ���ǡ��������ȡ��������ϡ���Ѩ����һָ����Ѩ���ַ�������һ��ָ����ľ�Ҫ����"NOR"",
""HIC"$N$w"HIC"���Ʈ���������̬ƮƮ���ɣ�������$n�������������㣬ȴ���Թ�ĹС��Ů��ѧ����һ����Ů������"HIY"С԰�վ�"HIC"��"NOR"",
""HIC"$N����һ�Σ��������ɣ�����ˢˢˢ������һ����һ���죬һ����һ���ݣ����Ƕ����ɵմ��ġ�"HIY"�𶥾�ʽ"HIC"��"NOR"",
""HIC"$N$w"HIC"б�ߣ�ʹһ�С�"WHT"˳ˮ����"HIC"����б������$n��$l��϶�����о���ϸ�壬ʵ��Ҫ��$p�����·"NOR"",
""HIC"$N��$w"HIC"���˼��ϣ�ʹ�ľ��ǡ��򹷰������е�һ�С�"HIG"��Ȯ��·"HIC"�����������⡱�־��������׹��������������������޷�"NOR"",
""HIC"$N����š����$w"HIC"������ߣ���������һʽ��"HIW"������Ȫ"HIC"����ϼ��������������ˮֱ�䣬����$n��ҪѨ"NOR"",
""HIC"$Nʹ����"HIR"����ǧ��"HIC"�����͵�һ����$w"HIC"����ֱ�̹�ȥ�����ⲻס������ʹ$n�Ʋ������⵽�׹���δ�"NOR"",
""HIC"$N����һ�С�"HIR"������ɽ"HIC"����$w"HIC"ֱ��$n$l�����м򵥶���ϸ���Ѵﷵ豹��棡�����ɽ�������֮������Ȼ�����鴫"NOR"",
""HIC"$N��$w"HIC"��ת�����¶��ϵ��̣�ȴ��ȫ���ɽ�����һ�С�"HIW"������"HIC"��������������������ȥ�Ӵ澫�������Ѵ󳬴�ǰ"NOR"",
""HIC"$Nʹ���һ�����Ӣ�����е�һʽ��"HIY"��Ӣ�ͷ�"HIC"��,$n�����������ǽ�����䣬��⼤����������㣬������Ӣ�ͷף���ɢ����"NOR"",
""HIC"$N$w"HIC"�任�����������ޣ�����������ͯ�ܲ�ͨ���������ʮ��·����ȭ�е���ʮ��·��"HIW"���ֿտ�"HIC"���û�����"NOR"",
""HIC"$N����һ��������ϣ�����$w"HIC"�����ֱָ$n���,���������޺�ȭ��һʽ��"HIY"�ຣ��ͷ"HIC"������ʱ$N��$w"HIC"��������������"NOR"",
});
int valid_enable(string usage) 
{ 
        return usage == "sword" || usage == "parry"; 
}

int valid_learn(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ( me->query("max_neili") < 100)
                return notify_fail("�������������\n");

        if ( me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");

        if ( me->query_skill("parry", 1) < 10)
                return notify_fail("��Ļ����мܻ��̫ǳ��\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        int i, j, level, damage;

        level = me->query_skill("huifeng-jian", 1);
        i = random(me->query_skill("force"))+50;
        if( i<100 ) i = 100;
        j = random(40)-5;
        damage = (random(6)+1)*35;
        if( damage < 50 ) damage =50;

        if( me->query_temp("liaoyuan") && me->query("jiali")) {
                                return ([
                                       "action": HIW+replace_string(replace_string(msg[random(sizeof(msg))], "$w", "$w"), "$w", "$w"HIW)+NOR,                                   
                                       "damage": 150 + random(120),
                                       "damage_type": "����",
                                       "dodge":  random(20),
                                       "parry":  random(20),
                                       "force":  300 + random(250),
                                        "attack" : random(30),
                                        "damage_type" : "����",
                                ]);     // �����������䣬�������
                        }


                        if( level > 350 ) {
                        if( level > 400 ) level = 400;
                        return ([
                                "action": HIC+feiyue_msg[random(sizeof(feiyue_msg))],
                                "damage": 200 + random(150),
                                "damage_type": "����",
                                "dodge":  random(20),
                                "parry":  random(20),
                                "force":  350 + random(270),
                            "attack" : random(50),
                        ]);
                }
                
        return ([
                "action":msg[random(sizeof(msg))],
                "damage": 80 + random(140),
                "damage_type": "����",
                "dodge": random(30)-10,
                "parry": random(20),
                "force": 200 + random(350),
        ]);
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 50 || me->query("neili") < 20 )
                return notify_fail("��������������ط��������\n");

        me->receive_damage("jingli", 40);
        me->add("neili", -15);
        return 1;
}


int ob_hit(object ob, object me, int damage)
{
        object weapon, weapon1;
        string msg, *limbs, limb;
        int ap, dp, skill, j, i;

        if( ob->query("env/invisibility") ) return 0;
        if( !userp(me) && random(2) ) return 0;
  if( me->busy()) return 0;
        weapon1 = me->query_temp("weapon");

        if( me->query_skill("huifeng-jian", 1) < 150
         || me->query_skill_mapped("sword") != "huifeng-jian"
         || me->query_skill_mapped("parry") != "huifeng-jian"   // �мܱ����ǻط������
         || !weapon1
         || weapon1->query("skill_type") != "sword" ) return 0;

        if( random(me->query_skill("parry")) > ob->query_skill("force")/3
         || random(me->query_con()) > ob->query_str()/3 )
                me->add_temp("hfj/"+ob->query("id"), 1);        // ��ӷ�������

//      ԭ�����������жϣ�ȥ���˷����ж�
        if( me->query("combat_exp") < ob->query("combat_exp")/2 || damage < 100 ) return 0;

        skill = me->query_skill("huifeng-jian", 1);
        weapon = ob->query_temp("weapon");

        if( objectp(weapon) )
                msg = weapon->query("skill_type");
        else {
                mapping prepare = ob->query_skill_prepare();
                if( !sizeof(prepare) ) msg = "unarmed";
                else msg = keys(prepare)[0];
        }

        if ( me->query("neili") < ob->query("neili")/5 ) return 0;

        ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
        if ( weapon ) ap *= 2;
        if ( ob->query("neili") > me->query("neili") * 2 ) ap += ap/2;

        dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;
        if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;  
        else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;

        ap = ABS(ap);
        dp = ABS(dp);

        if ( random(me->query("dex")) > ob->query("dex")/2) dp += random(dp/2);
        if ( skill > 350 ) dp += random(dp);

        if ( wizardp(me) ) tell_object(me, sprintf("ap: %d, dp: %d\n", ap ,dp ));

        if ( random(dp + ap) > ap ) {     // ���ʽ��͵�
                limbs = ob->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                msg = HIW+"ֻ��$N��������";
                msg += query_action(me, weapon1)["action"];
                msg = replace_string( msg, "$l", limb);
                msg = replace_string( msg, "$w", weapon1->name()+HIW) + "��\n"NOR;
                if( userp(ob) && !userp(me) && damage > 1500 )
                        damage = 1500 + (damage-1500)/10;       // �޸����˺��Ŀ���
//      �˺�����ȫ�������ڶ���
//              ob->receive_damage("qi", damage/3*2 + ob->query("jiali")*2, me);
//              ob->receive_wound("qi", damage/2, me);
                j = damage/2 + me->query_skill("sword") + me->query("jiali");
                if( wizardp(me) ) tell_object(me, "��ĺ������˺�Ϊ��"+j+"��\n"NOR);
                ob->receive_damage("qi", j, me);
                ob->receive_wound("qi", j/2, me);
                msg += COMBAT_D->damage_msg(j, "����");
                msg = replace_string( msg, "$l", limb);
                msg = replace_string( msg, "$w", weapon1->name());
                message_vision(msg, me, ob);
                COMBAT_D->report_status(ob, ob->query("qi") >= 0 || ob->query("eff_qi")+ob->query_temp("apply/qi") < 0);
                return -6000;
        }
        
//      ���ҽ�����Ч�� �������ˡ�
        else if( me->query_temp("hfj/"+ob->query("id")) > ( 1 + random(3) ) 
         && ( random(me->query_skill("parry")) > ob->query_skill("force")/2
         || random(me->query_con()) > ob->query_str()/2 ) ) {
                me->delete_temp("hfj/"+ob->query("id"));
                msg = HIW"$N��͸��$n���书��·��"+weapon1->name()+HIW"΢�࣬�㼴��������������$n�����У���"NOR;
                message_vision(msg, me, ob);
                i = ob->query("qi");
                me->set_temp("jianjue", 1);
                me->add_temp("apply/attack",  me->query_skill("huifeng-jian", 1)/4);
                COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), random(3)?1:3);
                me->add_temp("apply/attack", -me->query_skill("huifeng-jian", 1)/4);
                me->delete_temp("jianjue");
                if( i > ob->query("qi") ) return -damage/2;
                else return -damage;
        }
        return 0;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
//      ���Ӷ��ҽ������������������ʺܵ�
        object weapon; 
        int i;
        weapon = me->query_temp("weapon");
        i = me->query_skill("huifeng-jian", 1);

        if( !userp(me) && random(2) ) return 0;

        if( !weapon || weapon->query("skill_type") != "sword" ) return 0;
        if( i < 300 ) return 0;
        if( !me->query("emei/jianjue")) return 0;
        if( me->query_temp("jianjue") ) return 0;
// 227:         if( me->query_temp("liaoyuan") ) return 0;
        if( damage_bonus < 100 ) return 0;
        if( !living(victim) ) return 0;

        if( i >= 300 && !random(3)
         && random(me->query_con()) > victim->query_con()/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3 ) {
                if( me->query_skill_prepared("hand") == "jieshou-jiushi"
                 && me->query_skill_mapped("hand") == "jieshou-jiushi"
                 && me->query_skill("jieshou-jiushi", 1) >= 200 && random(2) ) {
                        message_vision(HIW"$NĬ����ҽ�������"CYN"������ʹ�����˲��Ӽ����ɼ����ͣ�������"HIW"�������͵��˽���ת�����ֽ��־�ʽ�澢����"NOR, me);
                        weapon->unequip();
                        me->add_temp("apply/attack",  me->query_skill("jieshou-jiushi", 1)/3);
                        COMBAT_D->do_attack(me, victim, 0, 3);
                        me->add_temp("apply/attack", -me->query_skill("jieshou-jiushi", 1)/3);
                        weapon->wield();
                } else {
                        message_vision(HIW"$NĬ����ҽ�������"HIY"�����ܴ��ģ��ɼ��Դ��ˡ�ǰ�����ˣ�����ǡ�ϡ�"HIW"��������"+weapon->name()+HIW"�͵Ļ�ת�ٴδ̳���"NOR, me);
                        me->set_temp("jianjue", 1);
                        me->add_temp("apply/attack",  me->query_skill("huifeng-jian", 1)/3);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), random(4)?1:3);
                        me->add_temp("apply/attack", -me->query_skill("huifeng-jian", 1)/3);
                        me->delete_temp("jianjue");
                }
        }
        else if( i >= 400 && random(2)
         && random(me->query("combat_exp")) > victim->query("combat_exp")/3
         && random(me->query_skill("sword")) > victim->query_skill("parry")/3
         && random(me->query_con()) > victim->query_str()/3
         && !victim->query_temp("lost_attack") ) {
                message_vision(HIW"$NĬ����ҽ�������"HBRED+HIW"ǰ�����ң�ȫ�޶��򣬺����ˣ��ȷ������ˡ�"NOR+HIW"����ʱ�����ݺᣬ��$n�������ֲ�����\n"NOR, me, victim);
                victim->add_temp("lost_attack", 1+random(3));
                return random(me->query_skill("sword"))/3;
        }
        return 0;
}

string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}

