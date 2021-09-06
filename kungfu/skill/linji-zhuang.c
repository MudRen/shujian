// linji-zhuang.c ����  �ټ�ʮ��ׯ
// Modified by Lane@SJ 2005/4/14
// By Spiderii�޸�Ч��

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
	  if (this_player()->query("family/family_name")=="������"  || this_player()->query("cw_mp/������"))
        return usage == "force";
}

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
        int nb, nf, nh;
        nb = (int)me->query_skill("dacheng-fofa", 1);
        nf = (int)me->query_skill("force", 1);
        nh = (int)me->query_skill("linji-zhuang", 1);


	if ((!fam || fam["family_name"] != "������" ) && !me->query("cw_mp/������"))
			 	return notify_fail("�㲢�Ƕ����ɵ��ӣ����ϰ�����ټ�ׯ��\n");
        if ( nb < 150 && nb <= nh )
                return notify_fail("��Ĵ�˷���Ϊ�������޷�����������ټ�ʮ��ׯ��\n");

        if ( nf < 15)
                return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");

        if ( me->query("gender") == "����" )
                return notify_fail("���޸����ԣ�������ϰ�ټ�ʮ��ׯ�ڹ���\n");

        if ((int)me->query_skill("linji-zhuang", 1) > me->query_skill("force", 1) + 10
          && me->query_skill("linji-zhuang", 1) >= 200 )
               return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}


int practice_skill(object me)
{
       if((int)me->query_skill("linji-zhuang", 1) >= 200 )
       {
           if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200)
           {
                   me->improve_skill("linji-zhuang", (int)me->query_int());
                   me->add("neili", -100); 
                   me->add("potential", -1*(1+random(3)));
                   return 1;
           }
           else return notify_fail("�����ڵ���Ϊ����������ټ�ʮ��ׯ�ˡ�\n");
       }
        else return notify_fail("�����ڵ��ټ�ʮ��ׯ��Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : HIR + me->name()+"���Ϻ�����֣�˫�ִ�����ϥ����" NOR,
                "start_my_msg" : HIR"��ϯ�ض������������죬���Ϻ��ʱ��ʱ�֣���Ϣ˳��������������\n"NOR,
                "start_other_msg" : MAG + me->name() +"ϯ�ض������������죬���Ϻ��ʱ��ʱ�֡�\n"NOR,
                "halt_msg" : HIW"$N����һ����������Ϣ�������˻�ȥ��վ��������\n"NOR,
                "end_my_msg" : HIC"�㽫��Ϣ���˸�С���죬���ص���չ�վ��������\n"NOR,
                "end_other_msg" : HIR"��һ���"+me->name()+"��������ĵ�վ��������\n"NOR
        ]);
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int i=0, j=0, sk;
        object weapon;

        if( ( sk = me->query_skill("linji-zhuang", 1) ) < 300 ) return 1;

        // Ů�����ӽ�������
        if( me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query("jiali") > 0
         && me->query("gender") == "Ů��" 
         && me->query_skill("huifeng-jian", 1) >= 100
         && objectp(weapon = me->query_temp("weapon"))
         && weapon->query("skill_type") == "sword" ) {
                i += ( me->query_skill("huifeng-jian", 1)/100 ) * sk/10;        // 100 level Ϊһ����Ծ
                if( me->query_temp("apply/damage") < 100 ) i = i + random(i/3);
                else i += random(i/5);
                if( wizardp(me) ) tell_object(me, "��Ľ�������������"+i+"��\n"NOR);
        }

        // �������ӽ�������
        if( me->query_skill_mapped("sword") == "huifeng-jian"
         && me->query("jiali") > 0
         && me->query("gender") == "����" 
         && me->query_skill("huifeng-jian", 1) >= 120
         && objectp(weapon = me->query_temp("weapon"))
         && weapon->query("skill_type") == "sword" ) {
                i += ( me->query_skill("huifeng-jian", 1)/120 ) * sk/10;        // 120 level Ϊһ����Ծ
                if( me->query_temp("apply/damage") < 120 ) i = i + random(i/3);
                else i += random(i/5);
                if( wizardp(me) ) tell_object(me, "��Ľ�������������"+i+"��\n"NOR);
        }


        // ���ӱ�������Ч��
        if( victim->is_perform() || victim->is_exert() ) {
                j = me->query_str() * me->query_con() / 20;
                j = j + random(j/4);
                if( wizardp(me) ) tell_object(me, "�����ڱ�������״̬���������� "+j+"��\n"NOR);
        }

        i = i + j;

        if( !userp(me) ) i = i/3;

        return i;
}

int ob_hit(object ob, object me, int damage)
{

	if(!environment(me)) return 0;
        	if(!me->query("quest/jiuyin2/emei")) return 0;


        if( (me->query("qi")-damage) >= me->query("max_qi")*2/3 ) return 0;

        if(!random(3) && me->query("env/�����ٳ�")){  message_vision(HIY"$N�������㣬ͻȻʹ����"HIW"�����澭"HIY"�ϵĹ��򣬶������������һ����\n" NOR, me);
	return -damage;}
        return 0;
}

