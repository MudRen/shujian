//KinGSo 2006��5���޸�

#include <ansi.h>

inherit SKILL;

string *parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ����ұۣ���Ҫʹ$P������ˡ�\n",
        "$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$P�͹����ػӳ���λ�����̩ɽ���������������\n",
        "$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ�������������ͼ��ʹ$P���С�\n",
        "$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n"
        "$n�������ܣ��ٽ������ʹ�������両�ࡹ����$P��$l���뵲������С�\n",
        "$nͻȻʹ��������ɷ罣���ġ����ڤڤ������������$Pһ�ʣ���ͼͻ��$P�Ĺ��ơ�\n"
        "$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$P��$l����ͼ��$P�Ĺ��ƻ��⡣\n",
        "ֻ��$n���˷���������Ʈ�磬һʽ�����������������޶�����ס��$P��\n������\n",
        "$n���˷�����ʹ����ɽ���С�������롹��ɭɭ�����������ܣ��ܿ���$P������\n",
});
         
mapping *action = ({
([      "action" : "����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�" HIC "������"
                   "Ȫ" NOR "��ֱ��$n��$l",
        "force" : 290,
        "dodge" : 30,
        "parry" : 40,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N������$n�ӳ���" CYN "Ȫ��ܽ��" NOR "������" MAG "����"
                   "�ϸ�" NOR "������" HIG "ʯ������" NOR "������" HIW "����"
                   "����" NOR "������" HIY "���ף��" NOR "����\nɽ����",
        "force" : 210,
        
        "dodge" : 35,
        "parry" : 35,
        "damage": 190,
        "damage_type" : "����"
]),
([
        "action" : "$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ��" HIW "��Ůʮ�Ž�"
                   NOR "�������������ʮ�Ž�����һ�У��ַ�֮�죬\nֱ�Ƿ�����"
                   "˼",
        "force" : 240,
        
        "dodge" : 35,
        "parry" : 45,
        "damage": 175,
        "damage_type" : "����"
]),
([      "action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n��"
                   "����ȥ",
        "force" : 280,
        
        "dodge" : 55,
        "parry" : 65,
        "damage": 160,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ"
                   "�������ɽ���ƻ���$n",
        "force" : 340,
        
        "dodge" : 45,
        "parry" : 45,
        "damage": 210,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����"
                   "������" HIY "̩ɽʮ����" NOR "��Ϊһ����\n��$n",
        "force" : 250,
        
        "dodge" : 55,
        "parry" : 55,
        "damage": 210,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ�䣬ʹ����ɽ�ġ�" HIB "һ�������" NOR "��������$n"
                   "��$l����֪������;��ͻȻת�򣬴��$n\n����֮��",
        "force" : 240,
        
        "dodge" : 45,
        "parry" : 35,
        "damage": 210,
        "damage_type" : "����"
]),
([      "action" : "$N����������һ�����ǡ�" CYN "������ɽ" NOR "��������$w����"
                   "ն�䣬ֱ����$n��$l",
        "force" : 345,
        
        "dodge" : 55,
        "parry" : 45,
        "damage": 195,
        "damage_type" : "����"
]),
([      "action" : "$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ�" HIW "�ٱ�ǧ������ʮ"
                   "��ʽ" NOR "������ʽ�����ƾ���ӿ���Թ�\n�߲��ɵ�ĿΪ֮ѣ",
        "force" : 330,
        
        "dodge" : 65,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ�" HIR "��Ħ��" NOR "��"
                   "Ϊһʽ������ش���$n",
        "force" : 330,
        
        "dodge" : 35,
        "parry" : 45,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N����$w��ʹ��" CYN "̫����" NOR "�����⣬�������СС��"
                   "����ԲȦ�������޾�ԴԴ�����ز���$n",
        "force" : 230,
        
        "dodge" : 85,
        "parry" : 55,
        "damage": 220,
        "damage_type" : "����"
]),
([      "action" : "$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n����"
                   HIR "��Ħ��" NOR "���Ľ����¶����",
        "force" : 330,
       
        "dodge" : 45,
        "parry" : 55,
        "damage": 180,
        "damage_type" : "����"
]),
([      "action" : "ȴ��$NͻȻ�鲽������ʹ�������䵱��" HIG "���ѵ�ˮ" NOR
                   "����һ��",
        "force" : 180,
        
        "dodge" : 55,
        "parry" : 35,
        "damage": 210,
        "damage_type" : "����"
]),
([      "action" : "$N�˽���磬��������з���$n��$l�����Ա�$n���أ���������"
                   "��" HIR "��ħ��" NOR "���ġ�" HIR "����ʽ" NOR "��",
        "force" : 270,
        
        "dodge" : 45,
        "parry" : 55,
        "damage": 170,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ�˽����һ�ֹ���ġ�" HIY "�����罣��" NOR "����"
                   "��Ȼ��$n�����Ҵ�����",
        "force" : 330,
        
        "dodge" : 55,
        "parry" : 55,
        "damage": 180,
        "damage_type" : "����"
]),
([      "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N����"
                   "����ʵ",
        "force" : 310,
        
        "dodge" : 45,
        "parry" : 45,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����"
                   "ʲô����",
        "force" : 330,
        
        "dodge" : 55,
        "parry" : 35,
        "damage": 175,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��"
                   "֪����Ǻ�",
        "force" : 360,
        
        "dodge" : 50,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "����"
]),
([      "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ�������"
                   "�ȵ�$n���ò���",
        "force" : 310,
        
        "dodge" : 35,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���"
                   "$n���Կ��彣������",
        "force" : 334,
        
        "dodge" : 55,
        "parry" : 65,
        "damage": 180,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô"
                   "��ʽ",
        "force" : 360,
       
        "dodge" : 45,
        "parry" : 55,
        "damage": 190,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף���"
                   "��˼��",
        "force" : 360,
        
        "dodge" : 45,
        "parry" : 55,
        "damage": 188,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������"
                   "$n��$l",
        "force" : 350,
        
        "dodge" : 65,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "����"
]),
([
        "action" : "$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮������������"
                   "�Ѳ�",
        "force" : 310,
        
        "dodge" : 65,
        "parry" : 65,
        "damage": 210,
        "damage_type" : "����"
])
});

mapping *action2 = ({
([      "action" : HIW "����$N����$w" HIW "�ƿճ�����ƽƽһ������$n��������ʽ����"NOR,
        "force" : 400,
        
        "dodge" : 80,
        "parry" : 80,
        "damage": 300,
        "damage_type" : "����"
]),
([      "action" : HIW "$N�����۽������赭д������̳�һ������֮����������ʽ"NOR,
        "force" : 450,
        
        "dodge" : 90,
        "parry" : 90,
        "damage": 360,
        "damage_type" : "����"
]),
([      "action" : HIW "$N��Ʈ�ݣ���̬��Ȼ������������У�����$w" HIW "�����������������"
                   "�Ž��ѵ����շ�����ľ���"NOR,
        "force" : 500,
        
        "dodge" : 100,
        "parry" : 100,
        "damage": 380,
        "damage_type" : "����"
]),
([
        "action" : HIW "$N��$w"HIW"����һ�ڣ�����$n�Լ���$wײ����������֮������������" 
                   "�Ѳ�"NOR,
        "force" : 510,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 310,
        "damage_type" : "����"
]),
([      "action" : HIW "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô" 
                   "��ʽ"NOR,
        "force" : 460,
       
        "dodge" : 95,
        "parry" : 95,
        "damage": 320,
        "damage_type" : "����"
]),
([      "action" : HIW "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף���" 
                   "��˼��"NOR,
        "force" : 460,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 328,
        "damage_type" : "����"
]),
([      "action" : HIW "$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������" 
                   "$n��$l"NOR,
        "force" : 450,
        
        "dodge" : 95,
        "parry" : 95,
        "damage": 310,
        "damage_type" : "����"
]),

});
int valid_enable(string usage)
{
        return (usage == "sword") || (usage == "parry") ;
}

mapping query_action(object me, object weapon)
{
        if (me->query_skill("dugu-jiujian", 1) > 300 )
               return action2[random(sizeof(action2))];

        else   return action[random(sizeof(action))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;
        object m_weapon;

        if ((int) me->query_skill("dugu-jiujian", 1) < 120
           || ! (m_weapon = me->query_temp("weapon"))
           || ! living(me) || me->is_busy()
           || m_weapon->query("skill_type") != "sword")
                return;
         
	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return;

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return;




        ap = ob->query_skill("parry")+ mp; //+ mp;
      //  mp = random (me->query_skill("dugu-jiujian", 1));
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("dugu-jiujian", 1);
         
        // ����
        if (me->query("quest/pass/dugu-jiujian/wuzhao"))

        {
             if (me->query_skill("sword") * 3 / 4 + random(me->query_skill("sword"))
                 > ob->query_skill("parry"))
             {
                        result = ([ "damage": -damage ]);

                        result += (["msg" : HBWHT HIB "$n" HIG "�����$N" HIG "�Ĺ��ƣ�"
                                    "����ӳ�һ����������$N" HIG "��\n" NOR]);
            
                        ob->start_busy(1);
             }
             
             return result;
             
        }

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(9))
                {
                case 0:
                        result += (["msg" : HBWHT HIC "ȴ��$n" HIC "̤ǰһ������ʽбָ$P" HIC
                                            "�ұۣ���ʽѸ���ޱȣ�ʹ��$N" HIC "�������"
                                            "��\n" NOR]);
                        break;

                case 1:
                        result += (["msg" : HBWHT HIC "��$n" HIC "�Թ�Ϊ�أ��Խ�Ϊ�ˣ�������"
                                            "����$N" HIC "�͹����ػӳ���λ�����̩ɽ"
                                            "��" NOR + YEL "�����" NOR + HIC "��������"
                                            "\n" NOR]);
                        break;

                case 2:
                        result += (["msg" : HBWHT HIC "$n" HIC "ͻȻһ������$N" HIC "����һ��"
                                            "ȴ�����������ţ�$N" HIC "��ʱ�����޴룬��"
                                            "�Ʋ�������ͣ��������\n" NOR]);
                        break;

                case 3:
                        result += (["msg" : HBWHT HIC "����$n" HIC "�������ܣ��ٽ������ʹ��"
                                            "��" NOR + HIG "���両��" NOR + HIC "������"
                                            "$N" HIC "���󣬵����˴��С�\n" NOR]);
                        break;

                case 4:
                        result += (["msg" : HBWHT HIC "ȴ��$n" HIC "ͻȻʹ��������ɷ罣����"
                                            NOR + CYN "���ڤڤ" NOR + HIC "����������"
                                            "��$N" HIC "һ�ʣ���ʱͻ���˹��ơ�\n" NOR]);
                        break;

                case 5:
                        result += (["msg" : HBWHT HIC "$n" HIC "ͦ�����䣬��һ�С�" NOR + HIW
                                            "���Ƴ��" NOR + HIC "���ش�$N" HIC "����"
                                            "ʱ�ѽ����ƻ��⡣\n" NOR]);
                        break;

                case 6:
                        result += (["msg" : HBWHT HIB "ֻ��$n" HIB "���˷���������Ʈ�磬һʽ" 
                                            "��" NOR + HIW "��������" NOR + HIC "������"
                                            "�޶�����ס�˽�����\n" NOR]);
                        break;

                case 7:
                        result += (["msg" : HBWHT HIC "����$n" HIC "���˷�����ʹ����ɽ���С�"
                                            NOR + HIY "�������" NOR + HIC "����������"
                                            "�磬�ܿ���$N" HIC "���С�\n" NOR]);
                        break;

                default:
                        result += (["msg" : HBWHT HIC "$n" HIC "����ͻ�䣬������������������"
                                            "��ز����ʹ��ɽ�����ġ�" NOR + HIY "������"
                                            "��" NOR + HIC "����ͼ��ʹ$N" HIC "���С�\n"
                                            NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "һ�����е�" + m_weapon->name() +
                                 HIY "���й�ֱ��һ��ͦ��������$N" HIY "���и���"
                                 "����Ϯ$n" HIY "��\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "����" + m_weapon->name() + "����"
                                 "��" HIY "��ָ��$N" HIY "�����е�����������$N"
                                 HIY "����һ�䣬�������̲���Ϊ������\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "����" + m_weapon->name() + HIY
                                 "���任���ֽ��У�Ȼ��$N" HIY "��Ҳ�����ٴι�"
                                 "����˿������$n" HIY "���Ի�\n"  NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;
        object weapon, weapon2;
        int i, ap, dpp, dpd, dpf;
        string type, msg;

        lvl = me->query_skill("dugu-jiujian", 1);

        if (me->query("neili") < 2000
           || me->query_skill_mapped("sword") != "dugu-jiujian"
           ||! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword"
           ||  !me->query("quest/pass/dugu-jiujian/wuzhao") )

                     return 0;

         
	if((string)me->query_skill_mapped("sword") != "dugu-jiujian" && userp(me))
		  return 0;

	if((string)me->query_skill_mapped("parry") != "dugu-jiujian" && userp(me))
		  return 0;


        ap = me->query_skill("sword") + me->query_dex() + me->query_int()   ;
        dpp = victim->query_skill("parry");
        dpd = victim->query_skill("dodge");
        dpf = victim->query_skill("force");


        me->add("neili", -100);

        switch(random(5))
        {
           case 1:
              if (ap * 3 / 4 + random(ap) > dpp)
              {
                  me->add("neili", -220);
                  victim->receive_wound("qi", (damage_bonus - 30) / 2, me);
                  
                  return random(2) ? HIR "$N" HIR "һ��������������ɣ�" + weapon->name() + HIR
                                     "ʱ���������գ�ʱ��������ƣ�ȴ��֪����ͨ��"
                                     "һ��֮�о��̲������������\n" NOR:
                                     HIR "$N" HIR "����" + weapon->name() + HIR "��"
                                     "�������۾�һ�㣬һ������ӳ�����ֱ����$n" HIR 
                                     "С��������ƽ��������λ������ȴ�����ǡ���ô���\n" NOR;
             }
             break;

           case 2:
              if (ap * 3 / 4 + random(ap) > dpp && me->query_dex() >= 50)
              {
                  me->add("neili", -220);
                  victim->receive_wound("qi", (damage_bonus - 30) / 2, me);
                  
                  return random(2) ? HBWHT HIR "$N" HIR "һ��������������ɣ�" + weapon->name() + HIR
                                     "ʱ���������գ�ʱ��������ƣ�ȴ��֪����ͨ��"
                                     "һ��֮�о��̲������������\n" NOR:
                                     HIR "$N" HIR "����" + weapon->name() + HIR "��"
                                     "�������۾�һ�㣬һ������ӳ�����ֱ����$n" HIR 
                                     "С��������ƽ��������λ������ȴ�����ǡ���ô���\n" NOR;
             }
             break;

          case 3:
             message_vision(HIC "\n$N" HIC "����������е�" + weapon->name() +
                            HIC "�����дӳ��䲻��ķ�λֱָ$n" HIC "��ʽ�е�"
                            "������\n" NOR, me, victim);

             if (! me->is_busy())
             {
                  weapon = me->query_temp("weapon");
                  weapon2 = victim->query_temp("weapon");
                  if (weapon2)type = weapon2->query("skill_type");


                  if (ap * 3 / 4 + random(ap) >= dpf && weapon2
                      && type != "pin")
                  {
                           msg = HIW "$n" HIW "������ǰ�ۻ����ң�����"
                                 "��" + weapon2->name() + HIW "һʱ��"
                                 "Ȼ����ס�����ֶ�����\n" NOR;
                           weapon2->move(environment(me));      
                           me->add("neili", -100);                 
                  } else
                  {
                           msg = HIY "$n" HIY "�Եÿ�϶��Ϣ��һʱ��ȴ"
                                 "Ҳ����������\n" NOR;
                           me->add("neili", -40);
                  }
             }else 
             if (ap * 4 / 5 + random(ap) > dpd)
             {
                          msg = HBWHT HIY "$n" HIY "��æ�ֵ���һʱ�䲻����æ���ң�"
                                "��Ͼ������\n" NOR;

                          me->start_busy(1);
                          victim->start_busy(1 + random(lvl / 100));
             }
             else
             {
                          msg = HIC "$N" HIC "������������е�" + weapon->name() +
                                HIC "����$n" HIC "������$n" HIC "���ص��쳣���ܣ�$N"
                                HIC "һʱ��Ȼ�޷��ҵ�������\n" NOR;
                          me->start_busy(1 + random(2));
                          victim->start_busy(1);
             }
             message_vision(msg, me, victim);
             break;
          
          case 4:
             if (ap * 4 / 5 + random(ap) > dpd && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian") &&
                 me->query_dex() >= 60)
             {
                weapon = me->query_temp("weapon");
                message_vision(HIY "\n$N" HIY "�زؽ��⣬����" + weapon->name() + HIY 
                             "��������������ٶ�֮�죬��λ֮׼�����Ƕ��¾Ž��Ѵﵽ"
                             "�շ�����ľ��硣\n" NOR,
                             me, victim);

                me->add("neili", -320);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 3; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, random(4)?1:3);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
          
          default :
             if (ap * 4 / 5 + random(ap) > dpd && 
                 ! me->is_busy() &&
                 ! me->query_temp("dugu-jiujian/lian"))
             {
                weapon = me->query_temp("weapon");
message_vision(HBWHT HIB "\n$N" HIB "�زؽ��⣬����" + weapon->name() + HBWHT HIB
                             "��������������ٶ�֮�죬��λ֮׼�����Ƕ��¾Ž��Ѵﵽ"
                             "�շ�����ľ��硣\n" NOR,
                             me, victim);

                me->add("neili", -320);
              
                me->set_temp("dugu-jiujian/lian", 1);
                for (i = 0; i < 3; i++)
                {
                    if (! me->is_fighting(victim))
                            break;
                   
                    if (! victim->is_busy() && random(2) == 1)
                            victim->start_busy(1);

                    COMBAT_D->do_attack(me, victim, weapon, random(4)?1:3);
                }
                me->delete_temp("dugu-jiujian/lian");
                
             }
             break;                        
       }
}

int valid_learn(object me)
{
	mapping my_fam  = me->query("family");
	if(!my_fam || my_fam["master_name"] != "������")
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ѧϰ�����¾Ž�����\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("dugu-jiujian",1) > 60
		 &&(int)me->query_skill("dugu-jiujian",1) < 300)
		return notify_fail("���׽����Ҿͽ̵�������Ժ��Ҫ�����Լ�ȥ�����ˡ�\n");
	return 1;
}

int query_effect_parry(object attacker, object me)
{
        object weapon;
        int lvl;

        if (! objectp(weapon = me->query_temp("weapon")) ||
           (string)weapon->query("skill_type") != "sword")
                return 0;

        lvl = me->query_skill("dugu-jiujian", 1);
        if (lvl < 90)  return 0;
        if (lvl < 100) return 50;
        if (lvl < 125) return 55;
        if (lvl < 150) return 60;
        if (lvl < 175) return 65;
        if (lvl < 200) return 70;
        if (lvl < 225) return 75;
        if (lvl < 250) return 80;
        if (lvl < 275) return 90;
        if (lvl < 325) return 100;
        if (lvl < 350) return 110;
        return 120;
}

int practice_skill(object me)
{
	if ( me->query_skill("dugu-jiujian", 1 ) < 300)
		return notify_fail("���¾Ž�ֻ��ͨ����������ߡ�\n");

	if ( me->query("jingli") < 50)
		return notify_fail("����������������¾Ž���\n");
	if ( me->query("neili") < 50)
		return notify_fail("�������������ϰ���¾Ž���\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{

        return __DIR__"dugu-jiujian/" + action;
}

void skill_improved(object me)
{
        int lvl, i;

        i = me->query("int") / 3;
        lvl = me->query_skill("dugu-jiujian", 1);

        if (lvl > 120
           && me->query("can_perform/dugu/qi") <= 100
           && ! me->query("quest/pass/dugu-jiujian/wuzhao"))
        {
                if (me->add("can_perform/dugu/qi", random(i)) < 100)
		{
                        tell_object(me, HIC "��Զ��¾Ž���" HIW "����ʽ"
                                        HIC "�������µ�����\n" NOR);
                } else
		{
                        tell_object(me, HIC "��ͨ���˶��¾Ž���" HIW "��"
                                        "��ʽ" HIC "���İ��ء�\n" NOR);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
		}
        }

        if (lvl > 150
           && me->query("can_perform/dugu/po") <= 100
           && ! me->query("quest/pass/dugu-jiujian/wuzhao"))
        {
                if (me->add("can_perform/dugu/po", random(i)) < 100)
		{
                        tell_object(me, HIC "��Զ��¾Ž���" HIR "�ܾ�ʽ"
                                        HIC "�������µ�����\n" NOR);
                } else
		{
                        tell_object(me, HIC "��ͨ���˶��¾Ž���" HIR "��"
                                        "��ʽ" HIC "���İ��ء�\n" NOR);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
                        me->improve_skill("dugu-jiujian", 1500000);
		}
        }
}

int difficult_level()
{
        object me = this_object();
       
        if ((int) me->query_skill("dugu-jiujian", 1) > 400 )

               return 1200;

        else   return 600;
}
