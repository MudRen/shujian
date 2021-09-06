#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
	  if (this_player()->query("family/family_name")=="����Ľ��" || this_player()->query("cw_mp/����Ľ��"))
        return usage == "force";
}

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
	if ((!fam || fam["family_name"] != "����Ľ��" )&& !me->query("cw_mp/����Ľ��") )
			 	return notify_fail("�㲢��Ľ�ݵ��ӣ����ϰ����Ľ���񹦡�\n");
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷������Ԫ����\n");

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ������������������������Ԫ����\n");

        if ((int)me->query_skill("shenyuan-gong", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("shenyuan-gong", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
       if((int)me->query_skill("shenyuan-gong", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("shenyuan-gong", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ�����������Ԫ���ˡ�\n");
       }
        else return notify_fail("�����ڵ���Ԫ����Ϊֻ����ѧ(learn)�������������ȡ�\n");

              
}

string exert_function_file(string func)
{
        return __DIR__"shenyuan-gong/" + func;
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIB + me->name()+"������������̬��Ϊ����" NOR,
		"start_my_msg" : "������һվ��˫�ֻ���̧������һ������������ʼ��������ת��\n",
		"start_other_msg" : me->name()+"����������һվ��˫�ֻ���̧������ʼ�������������\n",
		"halt_msg" : "$Nüͷһ�壬�������������ַ���������\n",
		"end_my_msg" : "�㽫����������������������һȦ���������뵤������֣�������һ������\n",
		"end_other_msg" : "ֻ��"+me->name()+"���۾��������ϣ��������������ַ��£�������һ������\n"
	]);
}





mixed hit_ob(object me, object target)
{
	string msg;
	int j;
	j = me->query_skill("canhe-zhi", 1);
 
     if (me->query_skill_prepared("finger") != "canhe-zhi"
           || me->query_skill_mapped("finger") != "canhe-zhi")
      return 0;

  
  
  
  
	if ( random(me->query_dex(1)) >= (target->query_dex(1)/3)
	       &&j > 120 
         && random(me->query_skill("parry",1)) > 120 
         && random(10)>5
	       && me->query("jingli") > 300
	       && random(me->query("combat_exp")) > random(target->query("combat_exp")/3)
         && me->query("neili") > 500
         || ( userp(me) && me->query_temp("lianhuan") && random(j)>=120 )
         ||( !userp(target) && me->query_temp("lianhuan")) )
         {
		switch(random(2)) {
			case 0 :
				msg = HIW"$NĬ����Ԫ�񹦣�ָ����ƮƮ�ص���$n��һ���ھ�������Ϣ������$n�����Ѩ��\n";
				msg += "$nֻ��ȫ��һ�飬�ѱ�һ�е��С�����Ѩ����\n"NOR; 
				target->add_busy(1+random(3));
target->add_condition("no_perform",1+random(2));
				break;
			case 1 :
				msg = HIR"$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ���ؿ�һʹ��ȫ��������к������\n"NOR;
				target->recevied_damage("neili", j);
target->add_busy(1+random(3));
target->add_condition("no_exert",1+random(2));
				if ( target->query("neili") < 0 )
					target->set("neili", 0);
				me->add("neili",-20);
				break;
		}
		message_vision(msg, me, target);
	}
}
