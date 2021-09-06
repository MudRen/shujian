// shenzhao-jing.c
// written by Xiaoyao 98.7.25
// hehehe by Ciwei@SJ
// ��ʽquest skill by tangfeng@SJ 2004/11/1
// ��������˼ *_* ciwei��

inherit FORCE;
#include <ansi.h>
#include "/kungfu/skill/force.h"
#include <combat_msg.h>

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	return 1;
}

int practice_skill(object me)
{
        if((int)me->query_skill("shenzhao-jing", 1) >= 120 )
       {
	   if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
	   {
		   me->improve_skill("shenzhao-jing", (int)me->query_int());
		   me->add("neili", -100); 
		   me->add("potential", -1*(1+random(3)));
		   return 1;
	   }
	   else return notify_fail("�����ڵ���Ϊ������������վ��ˡ�\n");
       }
	else return notify_fail("���վ�ֻ��ͨ��ѧϰ�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return SKILL_D("shenzhao-jing/") + func;
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIW + me->name()+"˫�ְ�����ǰ��ͷ������Խ��ԽŨ��"NOR,
    "start_my_msg" : "��������ϥ������˫�ְ�����ǰ������һ��ů���澭��������ת��\n",
    "start_other_msg" :HIW + me->name()+"�������£�����˫�ְ�����ǰ��ͷ�ϰ���������\n"NOR,
    "halt_msg" : HIW "$N�͵�����˫�ۣ�˫��Ѹ�ٻظ���࣬��ϸ�������ܡ�\n"NOR,
    "end_my_msg" : "��һ�������н������������ӵ�վ��������\n",
    "end_other_msg" : HIW "ֻ��������"+me->name()+"ͷ���İ���������ɢ��"+me->name()+"����˫�ۣ�վ��������\n"NOR
     ]);
}

mixed hit_ob(object me, object ob, int damage)
{
	//if(!wizardp(me) || !me->query("env/shenzhao_test")) return;
	int busy,p;
	string msg;

	if(!me->query("quest/���Ǿ�/�书/shenzhao")) return;
	if(me->query_temp("szj_power"))
	{
		me->add_temp("szj_power",-1);
		return;
	}
     //tell_object(me,"�غϣ�"+me->query_temp("combat_time")+"��\n");
	 if(me->query_temp("combat_time")>10 && random(3) ||(me->query("env/����")&& !random(4)) )
	 {
		me->set_temp("szj_power",1);
	 	me->delete_temp("combat_time");
	 	message_vision(HIW"$N�������վ���Խս��Խ�£����ް���֮�ࡣ\n"NOR,me);
	 	me->set_temp("action_flag",1);
	 	me->add_temp("apply/attack",me->query_temp("combat_time")*10);
	 	me->add_temp("apply/damage",me->query_temp("combat_time")*10);
	 	me->add_temp("apply/parry",me->query_temp("combat_time")*10);
	 	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), random(2)?1:3);
	 	me->add_temp("apply/attack",-me->query_temp("combat_time")*10);
	 	me->add_temp("apply/damage",-me->query_temp("combat_time")*10);
	 	me->add_temp("apply/parry",-me->query_temp("combat_time")*10);
		me->delete_temp("action_flag");
	 	return;
	 }
	 else
		 if( !ob->busy()
	 && me->query_str()*10/2+random(me->query_str()*10/2) > random(ob->query_dex()*10) 
	 && random(me->query("neili"))>1000
	 && me->query("jingli")>1000
	 && random(3)==1
	 ){
		me->set_temp("szj_power",5);
	 	msg = HIW"$Nһ�Բ�����һ���ֱ�ץס$n���ؿڡ�\n$n������������һ��$Pץס�������������ĺ���������\n"NOR;
	 	busy = me->query_str()-ob->query_dex();
	 	if(busy<=0) busy = 1+random(2);
	 	if(busy>5) busy=5;
	 	ob->add_busy(busy);

             ob->set_temp("no_fight",1);
             ob->apply_condition("no_fight",1);

	 	//message("wizard",sprintf("���վ���%s���ӹ���%s busy:%d\n",me->name(),ob->name(),busy),environment(me));
	 	return msg;
	 }
	 else 
		 if(random(me->query("neili"))>1500
	 && me->query("jingli")>500
	 && me->query("jiali") > 30
	 && !me->query_temp("weapon")
	 && random(6)==1 
	 ){
		me->set_temp("szj_power",5);
	 	msg = HIW"����$N˫����������ʹ�㣬��;�лؽ����������һ������������$n���䡣\n"NOR;
	 	damage = (me->query_str()*10+me->query_skill("force")-ob->query_skill("parry",1))*5;
	 	if(damage<=0) damage = 1;
	 	if(damage>4000) damage = 4000;
	 	//message("wizard",sprintf("���վ���%s���ӹ���%s damage ��������:%d\n",me->name(),ob->name(),damage),environment(me));
	 	ob->receive_wound("qi", damage - ob->query_temp("apply/armor"), me);
		p=(int)ob->query("qi")*100 / (int)ob->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	 	return msg;
	 }
}

mixed ob_hit(object ob,object me,int damage)
{
	//if(!wizardp(me) || !me->query("env/shenzhao_test")) return;
	int p;
	string msg;
	
	
	
	 if(me->query("env/����"))
	 	{
	 		if( (me->query("qi")-damage) >=  me->query("max_qi")*2/3 ) return;
	 			
	 if(ob->query_temp("weapon"))
		
			msg = HIW"$n�������ܣ�����"+ob->query_temp("weapon")->query("name")+HIW"������ͷ����֮����ͻȻһ��������$N��࣬����ײ��������$P�ϸ���\n"NOR;
		else 
		
			msg = HIW"$n�������ܣ�$N��������ͷ����֮����ͻȻһ��������$N��࣬����ײ��������$P�ϸ���\n"NOR;
		
		damage = (me->query_str()*10+me->query_skill("force")-ob->query_skill("parry",1))*5;
		
		if(damage<=0) damage = 1;
	 	if(damage>4000) damage = 4000;
	 		
	 	ob->receive_damage("qi", damage, me);
	 	
	 	p=(int)ob->query("qi")*100 / (int)ob->query("max_qi");

             ob->set_temp("no_fight",1);
             ob->apply_condition("no_fight",1);
             ob->apply_condition("no_perform",2);

		
		msg += damage_msg(damage, "����");
		msg += "( $N"+eff_status_msg(p)+" )\n";
	 	
	 	return msg;
	 		 	
	 		}
	 
	 
	
	
	
	
	
	
	if(!me->query("quest/���Ǿ�/�书/shenzhao")) return;
	if(me->query_skill("shenzhao-jing",1)<180
	 ||me->query_str()<40
         ||me->query_con()<40
         ||random(6)
	 ) return;
	 
	 
	 
	if(me->query("neili")>500
	&& me->query("jingli")>500
	&& me->query("jiali") > 30
	&& random(10)==1
	) {
		if(ob->query_temp("weapon"))
			msg = HIW"$n�������ܣ�����"+ob->query_temp("weapon")->query("name")+HIW"������ͷ����֮����ͻȻһ��������$N��࣬����ײ��������$P�ϸ���\n"NOR;
		else 
			msg = HIW"$n�������ܣ�$N��������ͷ����֮����ͻȻһ��������$N��࣬����ײ��������$P�ϸ���\n"NOR;
		damage = (me->query_str()*10+me->query_skill("force")-ob->query_skill("parry",1))*5;
		if(damage<=0) damage = 1;
	 	if(damage>4000) damage = 4000;
	 	ob->receive_damage("qi", damage - ob->query_temp("apply/armor"), me);
	 	//message("wizard",sprintf("���վ���%s���ӹ���%s damage:%d\n",me->name(),ob->name(),damage),environment(me));
		p=(int)ob->query("qi")*100 / (int)ob->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $N"+eff_status_msg(p)+" )\n";
	 	return msg;
	}
	else
	{
		if(ob->query_temp("weapon"))
			msg = HIW"$n�������ܣ�����"+ob->query_temp("weapon")->query("name")+HIW"������ͷ����֮����ͻȻ����һ�䣬һ����Ȼǡ�ö��˹�ȥ��\n"NOR;
		else 
			msg = HIW"$n�������ܣ�$N��������ͷ����֮����ͻȻ����һ�䣬һ����Ȼǡ�ö��˹�ȥ��\n"NOR;
		message_vision(msg,ob,me);
	 	return -(8000-damage);
	}
}
