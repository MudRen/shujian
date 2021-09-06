
#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/force.h"
#include <combat_msg.h>

int valid_enable(string usage) {
   if ( this_player()->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach"))
             return usage == "force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");
        return 1;
}

void skill_improved(object me)
{
        if (me->query_skill("lengquan-shengong", 1)>=220 && !me->query("quest/ѩɽ�ɺ�/�书/lengquan"))
        {
                tell_object(me, HIW"\n��Ȼ����о����ں���Խ��Խʢ��ȫ���ƺ�������ѣ�����̹ǣ�\n"NOR);
                tell_object(me, HIW"\n����һ�ᣬ���ں����𽥾��ڵ��ﴦ��ȫ����Ϊ֮һ�񣬹�����Ϊ���������\n"NOR);
                me->add("max_neili", me->query_skill("lengquan-shengong", 1)*2 + random(me->query_skill("lengquan-shengong", 1)*2));
                me->set("quest/ѩɽ�ɺ�/�书/lengquan", 1);
        }
}
int practice_skill(object me)
{
        if((int)me->query_skill("lengquan-shengong", 1) >= 200)
        {
                if( (int)me->query("potential", 1) > 5
                 && (int)me->query("neili", 1) > 200)
                {
                        me->improve_skill("lengquan-shengong", (int)me->query_int()*2);
                        me->add("neili", -100); 
                        me->add("potential", -1*(1+random(3)));
                        return 1;
                }
                else
                        return notify_fail("�����ڵ���Ϊ�����������Ȫ���ˡ�\n");
        }
        else
                return notify_fail("�����ڵ���Ȫ����Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
       return __DIR__"lengquan-shengong/" + func;
}

mapping exercise_msg(object me)
{
  return ([
     "status_msg" : HIB + me->name()+"��ϥ���������Ͼ������Գ�����!" NOR,
    "start_my_msg" : HIW"����ϥ�����������һ�����ˡ�"HIB"��Ȫ��"HIW"��������Ȫ�ھ�����ȫ���硣\n"NOR,
    "start_other_msg" : HIW + me->name()+"��ϥ��������ʼ�˹�������\n"NOR,
    "halt_msg" : HIY"��Ȼ$N˫��һ����һ����Х������תȫ��ġ�"HIB"��Ȫ�ھ�"HIY"��ɢȥ���漴վ��������\n"NOR,
    "end_my_msg" : HIB"���ѽ�����Ȫ�ھ�������ȫ������Ѩ��ֻ��������棬�ھ������ޱȣ�\n"NOR,
    "end_other_msg" : HIC"ֻ��"+me->name()+"΢΢һЦ�������������������ƣ�����վ�����������Ͼ�͸����������\n"NOR,
    "heal_msg" : HIC"$N����"+chinese_number(3+random(7))+"����Ȫ�ھ����������翪ʼ�˹����ˣ�\n"NOR,
    "heal_finish_msg" : HIC"��һգ�۹���$N˫�ۻ����������������³���һ�����������ﻹ�а�����˵����ӣ�\n"NOR,
    "heal_unfinish_msg" : HIM"$NͻȻ��������һ�����³���һ���������������Ʋ�û����ȫ��ת��\n"NOR,
    "heal_halt_msg" : HIB"$N����һ����������ȫ�����Ȫ�ھ�����ɢȥ������������ʢ��\n"NOR,
    ]);
}


int ob_hit(object ob, object me, int damage)
{
	int skill = me->query_skill("force");
	int skill2= ob->query_skill("force");
	int neili = me->query_skill("neili");
	int neili2= ob->query_skill("neili");
        int i = 1;
	string msg;

   if(!me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach"))     return 1;
//   if(me->query_temp("hjdf/fdj")) return 1;
   if ( random(skill) > (skill2*14/10/2-1)/2 ||  me->query("qi") < me->query("max_qi")*2/3 )
	{
                   msg = HIB"$N"+HIB+"Ĭ����Ȫ�񹦣���ȥ��$n"HIB;
			if(neili > neili2*2)
			{
				msg += "�󲿷ֵĹ�����\n"NOR;
                           i = -(damage/2 + random(damage/2));
			}
			else 
			{
				if(neili < neili2/4) 
				{
					msg += "���ٵ�һ�㹥����\n"NOR;
                                   i = -random(damage/5);
				}
				else 
				{
					msg += "һ���ֵĹ�����\n"NOR;
                                   i = -(damage/4+random(damage/4));
				}
			}
		   message_vision(msg, me, ob);		
	}
   if (me->query_temp("lqsg/lq")|| me->query("qi")<= me->query("max_qi") * 2/3 ){
       message_vision(HIW"Ȼ��$N������"HIB"��Ȫ"HIW"���������ӵ����쾡�£�$n�ľ����ֱ�$N����İ���ȥ���٣�$N����û��ô�յ���ι�����Ӱ�죡\n"NOR,me,ob);
       i = i - (i+damage)/2;
   }
	return i;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string attack_skill)
{
	if(!me->query_temp("quest/ѩɽ�ɺ�/�书/lengquan"))	return;
	if(random(me->query("combat_exp"))<victim->query("combat_exp")/4) return;
	if(me->query_temp("quest/ѩɽ�ɺ�/�书/force_attack"))
	{
		me->delete_temp("quest/ѩɽ�ɺ�/�书/force_attack");
		return;
    }
	me->set_temp("quest/ѩɽ�ɺ�/�书/force_attack",1);
	if (random(me->query_dex()) > victim->query_dex()/2)
	{
		message_vision(WHT"$n��$N��һ�п��ˣ���æ������������������������һ����æ���ң�\n"NOR, me, victim);
	    victim->start_lost(2+random(2));
		me->add("jingli",-50);
		me->add("neili",-100);
	 }
	 else if (random(me->query_con()) > victim->query_con()/2)
	 {
        message_vision(WHT"$nͻȻ����һ�ƺ����Ѿ����뵽������������æ����������ȴΪʱ����\n"NOR,me,victim);	
        victim->apply_condition("cold_poison", victim->query_condition("cold_poison")+random(2)+1);
	 }
/*
         else if(userp(me))
//���ӣ�fix bug
	 {
		 	
	    skill = me->query_skill("force");

	    i = damage_bonus * (skill+1) / 1000;
	    i = i/2+ random(i);
	    if(me->query_temp("weapon"))
		    i = i*3;
	    if(me->query_temp("apply/damage")>=100)
		i = i/3;
        message_vision(WHT"$nͻȻ�о��������ң���æ��������������ȴֻ�о��ؿ����ƣ����Ƹ������أ�\n"NOR,me,victim);	
          if(victim->query("qi")<i) i=victim->query("qi");
//���ӣ�fix bug
		victim->recieve_wound("qi",i,me);
//       victim->receive_damage("qi",i,me);
//���ӣ�fix bug
	 }
 */
} 
