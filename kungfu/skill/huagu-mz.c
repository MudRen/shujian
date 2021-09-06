// huagu-mianzhang.c ��������
// rewrite by olives@SJ
// 4/19/2000
// Update By lsxk@Hsbbs ������ɫЧ��  2007/6/6

inherit SKILL;
#include <ansi.h>
#include <combat_msg.h>
#include <combat.h>

mapping *action = ({
([
	"action" : "ֻ��$N����չ��������$n��ͣתȦ������죬һʽ�������������һ����һ�Ƶ���$n���ϻ�ȥ",
	"damage_type" : "����",
	"lvl" : 0,
	"post_action" : (: call_other, __FILE__, "do_attack" :),  //�������õ�һ�㣬СplayerҲ�����ó���
	"skill_name" : "�������"
]),
([
	"action" : "$N˫��һ����һʽ�����߳����������ֻ���Ϊץ���۵�һ����Ю��һ�ɾ�����$n����ץ��ȥ",
	"damage_type" : "����",
	"lvl" : 15,
	"post_action" : (: call_other, __FILE__, "qin_na" :),  //�������õ�һ�㣬СplayerҲ�����ó���
	"skill_name" : "���߳���"
]),
([
	"action" : "$N�����ؾ���˫�ƣ�һʽ�����ϸ�꡹������һ�����������������$n��ǰ��",
	"damage_type" : "����",
	"lvl" : 30,
	"post_action" : (: call_other, __FILE__, "no_pfm" :),  //�������õ�һ�㣬СplayerҲ�����ó���
	"skill_name" : "���ϸ��"
]),
([
	"action" : "ֻ��$Nһ��ת�����ֻ��棬���ַ�������$n������һʽ�����в��ȡ����͵�һ�ƻ���",
	"damage_type" : "����",
	"lvl" : 45,
	"post_action" : (: call_other, __FILE__, "do_damage" :),
	"skill_name" : "���в���"
]),
([
	"action" : "$N������ƫ����$n�������һ����Ȼ�������򴩳���һʽ��������硹����$n��$l����������ȥ",
	"damage_type" : "����",
	"lvl" : 60,
	"post_action" : (: call_other, __FILE__, "dian_xue" :),
	"skill_name" : "�������"
]),
([
	"action" : "$N�����͵�����Ծ��һʽ����Ӱ���Ρ���˫�������޹ǰ�ز���$n��˫�ۣ�Ȼ��˫��һ�ϣ���ƮƮ����$nǰ����ȥ",
	"damage_type" : "����",
	"lvl" : 80,
	"post_action" : (: call_other, __FILE__, "san_du" :),
	"skill_name" : "��Ӱ����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 30)
		return notify_fail("��Ķ����󷨻�򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 250)
		return notify_fail("�������̫�����޷����������ơ�\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, j;
   string msg;
	level = (int)me->query_skill("huagu-mianzhang", 1);

	for(i = sizeof(action); i > 0; i--) {
		if(level >= action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
												
                   msg = action[j]["action"];
                    if (me->query_temp("sld/pfm/bujue"))
                        msg = HIC + msg + NOR;

			if(me->query_temp("sld/dianxue"))
			return ([
                           "action": msg,
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"post_action": (: call_other, __FILE__, "dianxue" :),
				"force": me->query("shen")>0?200 +random(200):250+random(250),
				"attack": me->query("shen")>0?50 +random(100):100+random(150),
				"dodge": me->query("shen")>0?random(30):random(30)-10,
				"parry": me->query("shen")>0?random(30):random(20),
			]);
						
			return ([
                           "action": msg,
				"lvl": action[j]["lvl"],
				"damage_type": action[j]["damage_type"],
				"post_action": action[j]["post_action"],
				"force": me->query("shen")>0?150 +random(300):200+random(350),
				"dodge": me->query("shen")>0?random(30):random(30)-10,
				"parry": me->query("shen")>0?random(30):random(20),
			]);
		}
	}
}

int practice_skill(object me)
{
	int lvl = me->query_skill("huagu-mianzhang", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ( me->query("jingli") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ( me->query("neili") < 20)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("jingli", 40 );
	me->add("neili", -15);
	return 1;
}

string perform_action_file(string action)
{   
	return __DIR__"huagu-mianzhang/" + action;	   
}

void skill_improved(object me)
{
	int skill, yl;
	skill = me->query_skill("huagu-mianzhang", 1);
	yl = me->query_skill("shenlong-yaoli", 1);
	if( skill >= 200 && !me->query("sld/hgmz") ){
		tell_object(me, HIW"\n��Ȼ�����������һ��Ȼ������ֻ��������������ʹ����ľ���������Х��������\n"NOR);
		me->add("max_neili", random(yl+random(yl)));
		me->set("sld/hgmz", 1);
	}
}
void dianxue(object me,object victim,object weapon,int damage)
{
	int ap,dp,pp,lvl;
	if (!victim->is_fighting(me)
	|| victim == me
	|| victim->is_ghost()
	|| !living(victim)
	)
		return;
	if (me->query_skill("tenglong-bifa",1) < 30)
		return;
	if( damage > 0 )
	{
		if( objectp(me) )
		{
			ap = COMBAT_D->skill_power(me,"dagger",SKILL_USAGE_ATTACK);
			dp = COMBAT_D->skill_power(victim,"dodge",SKILL_USAGE_DEFENSE);
			pp = COMBAT_D->skill_power(victim,"parry",SKILL_USAGE_DEFENSE);
			lvl = me->query_skill("tenglong-bifa",1);
			if(random(ap+dp)>dp/2 && random(ap+pp)>pp/2)
			{
					switch(random(3))
					{
						case 0:
							message_vision(HIW"ֻ��$n�ƺ�һ����ԭ��$p�ġ����Ѩ���Ѿ���$N���У�\n"NOR,me,victim);
							victim->add_condition("no_exert",1+random(lvl/20));
							break;
						case 1:
							message_vision(HIR"ֻ��$n�ƺ�һ����ԭ��$p�ġ����Ѩ���Ѿ���$N���У�\n"NOR,me,victim);
							victim->add_condition("no_perform",1+random(lvl/20));
							break;
						case 2:
							message_vision(HIC"ֻ��$n�ƺ�һ����ԭ��$p�ġ�����Ѩ���Ѿ���$N���У�\n"NOR,me,victim);
							victim->start_lost(1+random(lvl/10));
							break;
					}
			}
		}
	}
}

void do_attack(object me,object victim,object weapon,int damage)
{
	int ap,dp,pp,lvl;

	if (!victim->is_fighting(me)
	|| victim == me
	|| victim->is_ghost()
	|| !living(victim)
	|| me->query_temp("sld/post_action/neishang")	// ����Ƿ�ֹ�����post_action������do_attack���������
	|| me->is_perform()
	|| me->query_temp("sld/pfm")
	)
		return;

	if (me->query_skill("huagu-mianzhang",1) < 30)
		return;

	me->set_temp("sld/post_action/neishang",1);

	if( damage > 0 )
	{
		if( objectp(me) )
		{
			ap = COMBAT_D->skill_power(me,"strike",SKILL_USAGE_ATTACK);
			dp = COMBAT_D->skill_power(victim,"dodge",SKILL_USAGE_DEFENSE);
			pp = COMBAT_D->skill_power(victim,"parry",SKILL_USAGE_DEFENSE);
			lvl = me->query_skill("huagu-mianzhang",1);
			if(random(ap+dp)>dp/2 && random(ap+pp)>pp/2)
			{
					message_vision("$N��$n�����Ѿ�������δ��֮�ʳ˻��ֲ���һ�ơ�\n"NOR ,me,victim);
					me->add_temp("apply/attack",lvl/10);
					COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_REGULAR);
					me->add_temp("apply/attack",-lvl/10);

					if(!random(5)
					&& me->query("env/��������")=="����")
					{
						me->add_temp("apply/attack",lvl/8);
						message_vision("ֻ��$N�ֱ���ͬ����һ�������޹ǣ��ڼ��������ܷ��е�����£�����$n���ֱۣ��ٷ�һ�С�\n"NOR,me,victim);
						COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_REGULAR);
						me->add_temp("apply/attack",-lvl/8);
						me->start_perform(1+random(2),"���������ˡ�");
					}

			}
		}
	}
	me->delete_temp("sld/post_action/neishang");
}

void qin_na(object me,object victim,object weapon,int damage)
{
	int ap,dp,pp;
	object vwp;

	if(!victim->is_fighting(me)
	|| victim == me
	|| victim->is_ghost()
	|| !living(victim)
	|| me->query_temp("sld/post_action/qinna")   // ����Ƿ�ֹ�����post_action������do_attack���������
	|| me->is_perform()
	|| me->query_temp("sld/pfm")           // pfm��ʱ������ٳ�����������ܻ�̫ǿ
	//|| me->query("env/��������")!= "����"    // ��������ã�Ҳ����ǿ��
	|| victim->query_temp("lost_attack")       // �Է��Ѿ�������ס�ˣ�û��Ҫ�������ˡ�
	)
		return;

	if(me->query_skill("huagu-mianzhang",1)<60)
		return;

	me->set_temp("sld/post_action/qinna",1);

	if( damage > 0 )
	{
		if( objectp(me) )
		{
			ap = COMBAT_D->skill_power(me,"dagger",SKILL_USAGE_ATTACK);
			dp = COMBAT_D->skill_power(victim,"dodge",SKILL_USAGE_DEFENSE);
			pp = COMBAT_D->skill_power(victim,"parry",SKILL_USAGE_DEFENSE);
			if(random(ap+dp+pp)>dp+pp) //֮������ô�ж�Ҫ��ߣ���һ��ʼ̫ǿ
			{
				message_vision(HIW"$n�ܸ߷��ͣ�����ӯ������$N�ֱ���ͬ����һ�㣬����$n���ֱۣ���\n"NOR,me,victim);
				message_vision(HIW"ֻ��$N���ֿ�ס$n�����ţ����ַ���һ��һ�㣬��ȡ$n�������ϪѨ��\n"NOR,me,victim);
				vwp = victim->query_temp("weapon");
				if(objectp(vwp))
				{
					message_vision(HIW"$nֻ������һ�����飬���е�"+vwp->name()+HIW+"��Ҳ�ѳֲ�ס�����һ���������˵��ϡ�\n"NOR,me,victim);
					vwp->unequip();
					vwp->move(environment(me));
					if(vwp->query("no_get")
					|| vwp->query("unique"))
						destruct(vwp);
					victim->reset_action();
					victim->set_temp("lost_attack",2);
				}
				else
				{
					message_vision(HIW"���һ�����У�$nֻ��������һ�����飬��Ȼ��Ҳ̧����������\n"NOR,me,victim);
					victim->set_temp("lost_attack",3+random(3));
				}
				me->start_perform(3,"����Ѩ���á�");
			}
		}
	}
	me->delete_temp("sld/post_action/qinna");
}

void no_pfm(object me,object victim,object weapon,int damage)
{
	int m_neili,v_neili,m_force,v_force,effect;

	if(!victim->is_fighting(me)
	||  victim == me
	||  victim->is_ghost()
	|| !living(victim)
	||  victim->query_condition("no_perform")   // ����Է��Ѿ�����perform�ˣ��Ͳ����ٸ���Ч���ˡ�
	|| me->is_perform()
	||  me->query_temp("sld/pfm")
	)
		return;

	if(me->query_skill("huagu-mianzhang",1)<100)
		return;

	if( damage > 0 )
	{
		if( objectp(me) && objectp(victim) )
		{
			message_vision(HIY"$N�����ƽ�����$n�����壬���ľ������£��ھ�����$n���澭������\n"NOR,me,victim);
			m_neili = me->query("neili");
			v_neili = victim->query("neili");
			m_force = me->query_skill("force");
			v_force = victim->query_skill("force");
			effect = SKILL_D("dulong-dafa")->force_effect(victim->query_skill_mapped("force"));
			if(random(m_neili+m_force*8)>(v_neili+v_force*8)/3
			&& random(effect) > 0)
			{
				message_vision("$n������񣬼�æ������������������������������ȴ���������Ѿ����뵽�Լ��������������޷�������\n"NOR,me,victim);
				if(effect<3)
					victim->apply_condition("no_perform",1+random(5-effect));
				me->start_perform(2+random(3),"���ھ����꡹");
			}
			else
			{
				message_vision("$n���Ų�æ����������"+(effect>0?"����":"�ۻ�")+"������գ�۹������������������\n"NOR,me,victim);
				me->start_perform(1+random(2),"���ھ����꡹");
			}
		}
	}
}

void do_damage(object me,object victim,object weapon,int damage)
{
	int m_neili,v_neili,m_force,v_force,effect;

	if(!victim->is_fighting(me)
	||  victim == me
	||  victim->is_ghost()
	|| !living(victim)
	|| me->is_perform()
	||  me->query_temp("sld/pfm")
	)
		return;

	if(me->query_skill("huagu-mianzhang",1)<100)
		return;

	if( damage > 0 )
	{
		if( objectp(me) && objectp(victim) )
		{
			message_vision(HIY"$N�����ƽ�����$n�����壬�������²������ͳ�һ�������ޱȵ��ھ���\n"NOR,me,victim);
			m_neili = me->query("neili");
			v_neili = victim->query("neili")+1;
			m_force = me->query_skill("force");
			v_force = victim->query_skill("force");
			effect = SKILL_D("dulong-dafa")->force_effect(victim->query_skill_mapped("force"));
			damage = m_force+ me->query("jiali");
			damage = damage/2 + random(damage/2);
	     if(m_neili<m_force) m_neili = m_force;
	     if(v_neili<v_force) v_neili = v_force;
		    if(v_force<=0) v_force = 1;
			   damage *= (m_neili*100/v_neili/100);
			damage *= (5-effect);
			if(wizardp(me))
				tell_object(me,sprintf("damage = %O",damage));
			if(damage)
			{
				if(random(m_neili+m_force*8)>(v_neili+v_force*8)/3
				&& !random(effect))
				{
					message_vision("$n��æ����������������Ҫ�������ں����������Ѿ����Լ���������������˺ܴ���˺���\n"NOR,me,victim);
					victim->recieve_damage("qi",damage);
					victim->recieve_wound("qi",damage/2);
					COMBAT_D->report_status(victim);
					me->start_perform(1+random(3),"���ڹ��˵С�");
				}
				else
				{
					message_vision("$n���Ų�æ����������"+(effect>0?"����":"�ۻ�")+"������$N��ע��������Ȼ˿���������ã�\n"NOR,me,victim);
					me->start_perform(1+random(2),"���ڹ��˵С�");
				}
			}
		}
	}
}

void dian_xue(object me,object victim,object weapon,int damage)
{
	int effect;

	if(!victim->is_fighting(me)
	||  victim == me
	||  victim->is_ghost()
	|| !living(victim) 
	//||  me->query("env/��������")!= "��Ѩ"    // ��������ã�Ҳ����ǿ��
	|| me->is_perform()
	||  me->query_temp("sld/pfm")
	||  victim->is_busy()
	)
		return;

	if(me->query_skill("huagu-mianzhang",1)<100)
		return;

	if( damage > 0 )
	{
		if( objectp(me) && objectp(victim) )
		{
			message_vision(HIY"$N�����ű���Ϊָ����ָ���������$n����������Ѩ��\n"NOR,me,victim);
			effect = SKILL_D("dulong-dafa")->force_effect(victim->query_skill_mapped("force"));
			if(random(me->query("combat_exp")+victim->query("combat_exp"))>victim->query("combat_exp")
			&& !random(effect))
			{
				message_vision(HIY"һ�������ָ����֮����$n�������Ѩ��\n"NOR,me,victim);
				victim->apply_condition("fx_busy",1+random(5-effect));
				me->start_perform(1+random(3),"��ָ����Ѩ��");
			}
			else
			{
				message_vision("$n���Ų�æ����������"+(effect>0?"����":"�ۻ�")+"������$N��ע��������Ȼ˿���������ã�\n"NOR,me,victim);
				me->start_perform(1+random(2),"��ָ����Ѩ��");
			}
		}
	}
}

void san_du(object me,object victim,object weapon,int damage)
{
	int effect;

	if(!victim->is_fighting(me)
	||  victim == me
	||  victim->is_ghost()
	|| !living(victim) 
	//||  me->query("env/��������")!= "ɢ��"    // ��������ã�Ҳ����ǿ��
	|| me->is_perform()
	||  me->query_temp("sld/pfm")
	||  victim->is_busy()
	)
		return;

	if(me->query_skill("huagu-mianzhang",1)<100)
		return;

	if( damage > 0 )
	{
		if( objectp(me) && objectp(victim) )
		{
			message_vision(HIG"$N���������İ�ס$n���Ŀڣ��������£����ľ�Ȼ�ֳ����̵���ɫ��\n"NOR,me,victim);
			effect = SKILL_D("dulong-dafa")->force_effect(victim->query_skill_mapped("force"));
			if(random(me->query("combat_exp")+victim->query("combat_exp"))>victim->query("combat_exp")
			&& !random(effect))
			{
				message_vision(HIG"$nһ�������񱻴��˸����š�\n"NOR,me,victim);
				if(5-effect>0)
					{
						switch (me->query("env/ɢ��"))
						{
							case "qianli"  : victim->apply_condition("qianli_poison",2+random(5-effect));
									 break;
							case "ruanjin" : victim->apply_condition("7bug_poison",2+random(5-effect));
									 break;
							case "fugu"    : victim->apply_condition("fugu_poison",2+random(5-effect));
									 break;
							default	       : victim->apply_condition("snake_poison",2+random(5-effect));
									 break;
						}

					}
				me->start_perform(1+random(3),"������ɢ����");
			}
			else
			{
				message_vision("$n���Ų�æ����������"+(effect>0?"����":"�ۻ�")+"�����$N���������Ķ�����Ȼ�޷�����$n�������ߣ�\n"NOR,me,victim);
				me->start_perform(1+random(2),"������ɢ����");
			}
		}
	}
}
