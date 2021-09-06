#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
	if((int) me->query_skill("jiuyin-zhengong", 1) < 220)
		return notify_fail("��ֻ��ͨ���ж������澭����߾����湦��\n");

	if ((int)me->query_skill("jiuyin-zhengong", 1) > me->query_skill("force", 1) + 10
	&& me->query_skill("jiuyin-zhengong", 1) >= 220 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        if ((int)me->query_skill("jiuyin-zhengong", 1) + 10 > me->query_skill("daode-jing", 1)
        || me->query_skill("daode-jing", 1) < 221)
		return notify_fail("��ĵ��¾����������ܼ�����ϰ�����湦��\n");
       
      if((int)me->query_skill("shenzhao-jing", 1) >= 1 )
                return notify_fail("�㲻ɢȥ���վ�����ô���������湦��\n");
    
        if((int)me->query_skill("hamagong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ��󡹦����ô���������湦��\n");

        if((int)me->query_skill("lengquan-shengong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ��Ȫ�񹦣���ô���������湦��\n");

       if((int)me->query_skill("kuihua-mogong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ����ħ������ô���������湦��\n");  
    
        if((int)me->query_skill("jiuyang-gong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ�����񹦣���ô���������湦��\n");  
     
       if((int)me->query_skill("luohan-fumogong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ�޺���ħ������ô���������湦��\n");

        if((int)me->query_skill("taixuan-gong", 1) >= 1 )
                return notify_fail("�㲻ɢȥ̫��������ô���������湦��\n");  
      
        if (me->query("gender") == "����")
                return notify_fail( HIW"���޸�����֮�˺����޵�����������ķ�����\n");
 

        if ((int)me->query_dex()< 35)
                return notify_fail("������Լ����������鶯��������������ôƮ�"
                                   "������ڹ��ķ���\n");
 
       if ((int)me->query_int()< 40)
                return notify_fail("������Լ����������Բ�����������������ô����"
                                   "������ڹ��ķ���\n");
       if ((int)me->query_str()< 28)
                return notify_fail("������Լ����������������������������ô����"
                                   "������ڹ��ķ���\n");

       

	return 1;
}

int practice_skill(object me)
{
	if((int)me->query_skill("jiuyin-zhengong", 1) >= 220 ) {
		if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200){
			me->improve_skill("jiuyin-zhengong", (int)me->query_int());
			me->add("neili", -150);
			me->add("potential", -1*(1+random(2)));
			return 1;
		}
		else return notify_fail("�����ڵ���Ϊ��������߾����湦�ˡ�\n");
	}
	else return notify_fail("�����ڵľ����湦��Ϊֻ���ж�(study)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return SKILL_D("jiuyin-zhengong/") + func;
}

void skill_improved(object me)
{
	if( me->query_skill("jiuyin-zhengong",1) > 0
	&& !me->query("jiuyin/bonus")){
		tell_object(me, "��ľ����湦���������������Ϊ��\n");
		me->set("jiuyin/bonus", 1);
		me->add("max_neili", 10); 
	}
	if( me->query_skill("jiuyin-zhengong",1) >= 100
	&& me->query("jiuyin/bonus") < 2 ){
		tell_object(me, "��ľ����湦���������������Ϊ��\n");
		me->add("jiuyin/bonus", 1);
		me->add("max_neili", 100);
	}
	if( me->query_skill("jiuyin-zhengong",1) >= 220
	&& me->query("jiuyin/bonus") < 3 ) {
		tell_object(me, "��ľ����湦���������������Ϊ��\n");
		me->add("jiuyin/bonus", 1);
		me->add("max_neili", 200); 
	}
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIC + me->name() + "˫��΢�գ���һ�ɾ�������Χ������" NOR,
                "start_my_msg" : HIC"���������£�˫Ŀ΢�գ�˫���������������̫�������˺�һ���������顣\n"NOR,
                "start_other_msg" : me->name() + "�������£�˫Ŀ΢�գ�˫���������������̫������紵����" + me->name() + "���ϵ����۾�Ȼ��Ϊ������\n",
                "end_my_msg" : HIC"�㽫��Ϣ������һ��С���죬�������뵤�˫��һ��վ��������\n"NOR,
                "end_other_msg" : me->name() + "�����϶�Ȼһ������������ȥ���漴˫��һ��վ��������\n"
        ]);
}
