// guiyuan-tunafa.c ���ư� ��Ԫ���ɷ�
//�����ڹ�Ч�� By Spiderii@ty �ο�tz player tekken����
//��֪����һ�þ����������������ޱȣ������յ���һ���̿����æ���֣�
//����ȴ�ѱ��Է�����ץס�������������һֱ�յ�������̲�ס��С�
//³�н�������������ǧ���Ƕ�Ƥȴ�м������������ν����Դ���ס��
//����֮��ֻ�����Ž������̣�ͬʱ˫��Ҳ��������һֻ��¯֮�У���ʹ���ȡ�
//����һ�������֪��ߵغ�Ҫ����ǧ����������ڶ�������ǧ���³�нŵĹ���Ƭ�Ρ�

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
	  if (this_player()->query("family/family_name")=="���ư�"|| this_player()->query("cw_mp/���ư�") )       
 return usage == "force";
}

#include "/kungfu/skill/force.h"

int valid_learn(object me)
{
		mapping fam  = me->query("family");
        int nf;
        nf = (int)me->query_skill("force", 1);



	if ((!fam || fam["family_name"] != "���ư�" )&& !me->query("cw_mp/���ư�") )
			 	return notify_fail("�㲢�����Ƶ��ӣ����ϰ���������ķ���\n");
        if ( nf < 10)
                return notify_fail("��Ļ����ڹ���򻹲������޷�����Ԫ���ŷ���\n");

        if ((int)me->query_skill("guiyuan-tunafa", 1) > me->query_skill("force", 1) + 10
         && me->query_skill("guiyuan-tunafa", 1) >= 200 )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        return valid_public(me);
}

int practice_skill(object me)
{
        if((int)me->query_skill("guiyuan-tunafa", 1) >= 200 ) {
                if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
                        me->improve_skill("guiyuan-tunafa", (int)me->query_int());
                        me->add("neili", -100); 
                        me->add("potential", -1*(1+random(3)));
                        return 1;
                }
                else return notify_fail("�����ڵ���Ϊ��������߹�Ԫ���ŷ��ˡ�\n");
        }
        else return notify_fail("�����ڵĹ�Ԫ���ŷ���Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"guiyuan-tunafa/" + func;
}

mapping exercise_msg(object me)
{
        return ([
                "status_msg" : YEL + me->name()+"��ϥ���£���ȡ���֮����������������ӿ������ãã����"NOR,
                "start_my_msg" : "����ϥ���£�������������ͼ��ȡ���֮������ֻ�������ܰ�����������ضٺϣ����ܰ�ããһƬ��\n",
                "start_other_msg" :HIY + me->name()+"��ϥ���£�������������ͼ��ȡ���֮������ֻ�������ܰ�����������ضٺϣ����ܰ�ããһƬ��\n"NOR,
                "halt_msg" : HIY"$N��Ϣһת��Ѹ�������������չ�վ��������\n"NOR,
                "end_my_msg" : "��˫��΢�գ���������ؾ���֮����������,����ػָ��������չ�վ��������\n",
                "end_other_msg" : HIY +me->name()+"˫��΢�գ���������ؾ���֮����������,�����������ˣ�����ɢȥ���չ�վ��������\n"NOR,
                "heal_msg" : YEL"$N������Ȼ��˫Ŀ��գ���ʼ�������ܲ�ľ����Ϊ�����ã��ָ�����Ԫ����\n"NOR,
                "heal_finish_msg" : YEL"$N����ľ��������Ϣ����һ�壬�о�������ȻȬ��������Ҳ�������������\n"NOR,
                "heal_unfinish_msg" : HIR"$N��Ϣ����Ϊ�̣���ɫ�������ֻ࣬����ͣ���ˣ�վ��������\n"NOR,
                "heal_halt_msg" : YEL"$Nͻ�в�ľ������������Ϣ�ں�,�������˷���������Ԫ����æǿѹ��Ϣ������վ��\n"NOR,
        ]);
}

mixed hit_ob(object me, object ob, int damage)
{

        if(me->query_temp("tz/focus")
        && me->query_skill_mapped("parry") == "tiezhang-zhangfa"
        && !ob->query_condition("hot_poison")
        && random(4)==1
        ) 
         {   message_vision(HIR"$N���ǽ��ھ�����˫�ƣ����ĳ��ȣ�$n����֮����ʹ���̣����类����һ�㣡\n"NOR,me,ob);
             ob->apply_condition("hot_poison",(int)me->query_skill("tiezhang-xinfa",1)/10);
                 }
         else
               if(me->query_temp("tz/focus")
               && me->query_skill_mapped("parry") == "tiezhang-zhangfa"
               && !ob->busy()
               && me->query("neili")>2000
               && random(4)==1
         ){
                 message_vision(HIR"$nֻ�������Ʒ�����,�������ں��ξ���֮�У���ʽҲԽ��ɬ�ͣ�\n"NOR,me,ob);
               ob->add_busy(1+random(2));
         }
         return 1;
}

