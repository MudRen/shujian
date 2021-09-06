// Modify By River 99.5.26
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string *pictures=({
"�ľ�����","�������","��������","�����ˮ","�ǻ��չ�","��������","��ʬ����", "ӹ������"
});

int perform(object me)
{
        object target;
        string picture;
        int i,j;       
        i = me->query_skill("anran-zhang", 1)/2;
        if( me->query("eff_qi") > 0)
        j = me->query("max_qi") / me->query("eff_qi");
        else j = 0;
        picture = pictures[random(sizeof(pictures))];

        if( !target ) target = offensive_target(me);

        if( !target
         || !me->is_fighting(target) )
               return notify_fail("�����꡹ֻ����ս���жԶ���ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á����꡹������\n");   

        if( me->query_skill_prepared("strike") != "anran-zhang"
         || me->query_skill_mapped("strike") != "anran-zhang"
         || me->query_skill_mapped("parry") != "anran-zhang"
         || me->query_skill_mapped("force") != "yunu-xinjing")
               return notify_fail("����������ʹ�á����꡹������\n"); 

        if((int)me->query_skill("anran-zhang", 1) < 150 )
               return notify_fail("�����Ȼ�����Ʒ���򲻹���ʹ���������꡹������\n");

        if((int)me->query_skill("strike", 1) < 150 )
               return notify_fail("��Ļ�������������죬ʹ���������꡹������\n");

        if((int)me->query_skill("force") < 200 )
               return notify_fail("����ڹ��ȼ�������ʹ���������꡹������\n");

        if((int)me->query_temp("xinjing")) 
                return notify_fail("������ʹ�á��ľ����־���\n");

        if((int)me->query_str() < 30)
               return notify_fail("�������������ǿ����ʹ���������꡹������\n");

        if((int)me->query_dex() < 30)
                return notify_fail("�����������Ѹ�ͣ�ʹ���������꡹������\n");

        if((int)me->query_skill("yunu-xinjing", 1) < 150 )   
                return notify_fail("�����Ů�ľ���Ϊ�������޷�ʹ�á����꡹������\n");  

        if((int)me->query_temp("xiaohun")) 
                return notify_fail("����������ʹ�á����꡹������\n"); 

        if((int)me->query("max_qi") <= (int)me->query("eff_qi"))
                return notify_fail("�������ڵ��ľ�����ʹ�÷��ӳ����������\n"); 

        if((int)me->query("neili") < i*3 )
                return notify_fail("�������������\n");

        if((int)me->query("jingli") < i*2)
                return notify_fail("��ľ���������\n");

        message_vision(HIW"\n$N����������ݾ��������������ң���Ȼ֮�����Ķ�����û����ɵ��ĳ�һ�ơ�"+picture+"����\n"+
                          "�����Ʒ缤�����л��㱣�����ԼԼ��ɲʱ��Ȼ�����������������Ʋ��ɵ���\n"NOR,me,target);

        j *= i;
        if ( j > 350 ) j = 350;

        me->add("neili", -i*2);
        me->add("jingli", -i/2);
        me->add_temp("apply/attack", j);
        me->start_perform(2,"�������");
        me->set_temp("xiaohun", j );
        call_out("check_fight", 1 , me, target);
        return 1;
}

void check_fight(object me,object target)
{
        int time;
        if (!me) return;
        time = me->query_skill("force")/5; 
        if (me->query_temp("weapon")
         || me->query_temp("secondary_weapon")
         || me->query_skill_prepared("strike") != "anran-zhang" ){
            me->add_temp("apply/attack", - me->query_temp("xiaohun"));
            me->delete_temp("xiaohun");
            tell_object(me, HIR"\n�㡸���꡹����������ϣ����ص���.\n" NOR);
            return;
        }
        if ( ! target
         || time < 1
         || ! me->is_fighting(target)) {
            me->add_temp("apply/attack", - me->query_temp("xiaohun"));
            me->delete_temp("xiaohun");
            tell_object(me, HIR"\n�㡸���꡹����������ϣ����ص���.\n" NOR);
            return;
        }
        call_out("check_fight", 1, me, target,time -1);
}
string perform_name(){ return HIW"����"NOR; }
int help(object me)
{
        write(HIW"\n��Ȼ�����ơ����꡹��"NOR"\n");
        write(@HELP

����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣�������ҹ˼������С��Ů��
��������������������Ȥ�����ں���֮�п��������������һʮ����
�Ʒ������������Ʒ�����Ϊ��Ȼ�����ƣ�ȡ���ǽ��͡��𸳡����Ǿ�
��Ȼ�����ߣ�Ψ�������֮�⡣���Ʒ�������������������壬��һ
������ۺ�������Խ������Խ��,ʵ�������ض��ú���!

Ҫ��
        ��Ů�ľ���150
        ��Ȼ�����ƣ�150
HELP
        );
        return 1;
}
