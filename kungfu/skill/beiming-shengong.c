// beiming-shengong.c ������
//updated by Zmud@Sjmud 12/3/2009

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { 
	 if (this_player()->query("quest/�����˲�/��ڤ��/pass") 
	  || this_player()->query("family/family_name")=="��ң��"
          || this_player()->query("cw_mp/��ң��")
 )
	return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("beiming-shengong", 1);
	int t = 1, j;

	for( j = 1; j < lvl / 10; j++) t *= 2;
	if( t > 5000 ) t = 5000;
	if( me->query("gender") == "����" && lvl > 49 )
		return notify_fail("���޸����ԣ���������������������ı�ڤ�񹦡�\n");


        if( (int)me->query_skill("force", 1) < 30 )
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if( (int)me->query_skill("beiming-shengong", 1) > me->query_skill("force", 1) + 10
	&& me->query_skill("beiming-shengong", 1) >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
if( (int)me->query_skill("beiming-shengong", 1) >= 210 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
			me->improve_skill("beiming-shengong", (int)me->query_int());
			me->add("neili", -100); 
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ��������߱�ڤ���ˡ�\n");
	}
	else return notify_fail("�����ڵı�ڤ����Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"ͷ�������ű�ڤ��������ɫ����" NOR,
		"start_my_msg" : "����ϥ������˫Ŀ���գ�������һ�������뵤�����ڤ�������������Ѩ������\n",
		"start_other_msg" : me->name()+"��ϥ����������˫�����ճ�ȭ����һ�ᣬͷ��ð����ڤ������\n",
		"halt_msg" : "$N΢һ��ü������Ϣѹ�ص������һ������վ��������\n",
		"end_my_msg" : "�㽫��ڤ��������������ʮ�����죬���ص��ֻ����ȫ��̩ͨ�ġ�\n",
		"end_other_msg" : me->name()+"����һ������ɢȥȫ��ڤ������һ���½�վ��������\n"
	]);
}

int ob_hit(object ob, object me, int damage)
{
    int m_bmsg,t_force,i;
    m_bmsg = random((int)me->query_skill("beiming-shengong",1));
    t_force = (int)ob->query_skill("force",1);

    if((int)me->query_skill("beiming-shengong",1)>=300)
    if(me->query_temp("bmsg/bm")
    	&&me->query("quest/�����˲�/��ڤ��/pass")){
    	
    	if(m_bmsg > t_force*9/10 && !random(3)){
            i = - damage;
            message_vision(HIC"$N�񹦶�����������ڤ�������ۼ���ȫ��˫������$n�ؿڹ�ȥ����������Ϊ�ᴩ��$n��������֮�С�\n"NOR,me,ob);
            me->add("neili",-1000);
           ob->receive_damage("qi", damage);
           COMBAT_D->report_status(ob, random(2));
            return i;
        }
         else if(m_bmsg > t_force*6/10){
            i = - damage;
            message_vision(WHT"$NĬ���ڤ�������ľ���"HBMAG+HIW"������ˮ������֮�ϣ����Ϊ֮�ۣ��ñ����򽺣�ˮǳ���۴�Ҳ����"NOR+WHT"����ʱ����$n�˹�����\n"NOR,me,ob);
            me->add("neili",2000);
            ob->add("neili",-2000);
            COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);       
            return i;
        }
        else if(m_bmsg > t_force*5/10 ){
            i = - damage;
            message_vision(WHT"$N��Ȼ���򡸱�ڤ��֮����"HBRED+HIW"���ҷ�ˮ֮��Ҳ�������为����Ҳ������"NOR+WHT"��$n������������������ж��ȫ��������\n"NOR,me,ob);
            me->add("neili",1000);
            ob->add("neili",-1000);
            COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);          
            return i;
        }
        
        else if(m_bmsg > t_force*4/10){
            i = - damage*4/5;
            message_vision(WHT"$N��Ȼ��б��һ��������Ʈ�磬��ס$n�ؿڡ�"CYN"����Ѩ"NOR+WHT"����$nһ��֮�£���������������ͻ�����������пռ�к������\n"NOR, me,ob);
            ob->add("neili",-500);
            me->add("qi",500);  
            me->add("neili",500);              
            ob->start_busy(1+random(2)); 
ob->apply_condition("no_exert",1);
            return i;
        }
        else if(m_bmsg > t_force*3/10){
        	  i = - damage*4/5;
            message_vision(WHT"$N��������ץס$n�����ϵġ�"BLU"����Ѩ"NOR+WHT"����$n��������������ͻ�����������ڿռ�к������ȫ���������һ�㣡\n"NOR, me,ob);
            ob->add("neili",-500);
            me->add("qi",500);
            me->add("neili",500);    
            ob->start_busy(1+random(2));   
ob->apply_condition("no_fight",1);
            return i;
        }
    }
    return 0;
}
