//Create By lsxk@hsbbs 2007/6/14

#include <ansi.h>

inherit F_SSERVER;

string exert_name() {return HIM"��ϼ����"NOR;}

int exert(object me, object target)
{
        object weapon = me->query_temp("weapon");  
        int skill;
        string jianyi_set;
    
        if( !target ) target = offensive_target(me);

        if(!me->is_fighting() )
                return notify_fail("����ϼ���⡹ֻ����ս����ʹ�á�\n");

           if(userp(me) && !me->query("quest/zixia/pass"))
                return notify_fail("��ϼ���˻�ɽ���ھ�ѧ����δ�ý��ڣ�����͵ѧ������ϼ�񹦣�\n");

        if((int)me->query_skill("zixia-gong", 1) < 250 )
                return notify_fail("�����ϼ�񹦲���������ʹ�á���ϼ���⡹��\n");
    
        if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("��Ļ����ڹ�����������ʹ�á���ϼ���⡹��\n");

        if ((int)me->query_skill("huashan-jianfa", 1) < 250 )
                return notify_fail("��Ļ�ɽ����������죬�����������ӡ���ϼ���⡹��\n");
    
        if (!weapon 
         || weapon->query("skill_type") != "sword")
                return notify_fail("�������޷�ʹ�á���ϼ���⡹��\n");
    
        if ((int)me->query("neili") < 800 )
                return notify_fail("����������̫��������ʹ�á���ϼ���⡹��\n");

        if ((int)me->query("jingli") < 500 )
                return notify_fail("�����ھ���̫�٣�����ʹ�á���ϼ���⡹��\n");

        if ((int)me->query_temp("hsj_junzi"))
                return notify_fail("������ʹ�á����ӽ�����������\n"); 

        if ((int)me->query_temp("hsj_shunv"))
                return notify_fail("������ʹ�á���Ů������������\n"); 
    
        if ( (int)me->query_temp("hsj_xiyi") ) 
                return notify_fail("������ʹ�á�ϣ�Ľ�������\n");

        if ( (int)me->query_temp("zxg/jianyi") ) 
                return notify_fail("������ʹ�á���ϼ���⡹��\n");

        if (me->query_skill_mapped("force") != "zixia-gong")
                return notify_fail("����ڹ������޷�ʹ�á���ϼ���⡹��\n");

        if(me->query("env/��ϼ����")) jianyi_set = me->query("env/��ϼ����");

        if(jianyi_set!="����"
        && jianyi_set!="��Ů"
        && jianyi_set!="ϣ��"
        && jianyi_set!="�ں�") jianyi_set = "�ں�";

        if(jianyi_set=="����" && (int)me->query_skill("huashan-jianfa", 1) < 449 ){
            message_vision(HIM"$N������ϼ���ھ���������"+weapon->name()+HIM"�ϣ���ϼ�������Ķ��������������ˣ�\n"+
            HIC"$Nɲ�Ǽ����������Ԧ��֮��Ҫ����������ⷢ�ӵ����쾡�£���������������\n"NOR,me,target);
            me->start_exert(1,"����ϼ���⡹");
            me->start_perform(6+random(3));
            me->set_temp("zxg/jianyi/����",1);
            me->add("neili", -400);
            me->add("jingli", -200);

            skill = (int)me->query_skill("huashan-jianfa", 1);
            me->add_temp("apply/damage",  skill);

            call_out("check_fight", 1, me, weapon, skill);
            return 1;
        }
        if(jianyi_set=="��Ů"){
            message_vision(HIM"$N������ϼ���⣬����"+weapon->name()+HIM"����һ�䣬������ӯ����֮����\n"+
            "$N����"+weapon->name()+HIM"�����ߣ���ɽ����һһչ����������ˮ������֮���ɣ�ʵ��������\n"NOR,me,target);
            me->start_exert(1,"����ϼ���⡹");
            me->start_perform(1,"����ϼ���⡹");
            me->add("neili", -200);
            me->add("jingli", -100);
            me->set_temp("zxg/jianyi/��Ů",1);

            skill = (int)me->query_skill("huashan-jianfa", 1);
            me->add_temp("apply/dexerity",  skill/5);

            call_out("check_fight", 1, me, weapon, skill);
            return 1;
        }
        if(jianyi_set=="ϣ��"){
            message_vision(HIM"����$NͻȻһ�����У�������죬ȴ������֮�ƣ�ʵ�˷�����˼��"+
            HIY"\n$N������ϼ���⣬���о������һ��ͭǽ���ڣ�$n���а����ֵĻ��᣿\n"NOR,me,target);
            me->start_exert(1,"����ϼ���⡹");
            me->start_perform(1,"����ϼ���⡹");
            me->add("neili", -200);
            me->add("jingli", -100);
            me->set_temp("zxg/jianyi/ϣ��",1);

            skill = (int)me->query_skill("huashan-jianfa", 1);
            me->add_temp("apply/armor",  skill/2);
            me->add_temp("apply/parry",  skill/4*3);
            me->add_temp("apply/dodge",  skill/4*3);
            me->add_temp("apply/damage",  -skill/4);

            call_out("check_fight", 1, me, weapon, skill);
            return 1;
        }
        if(jianyi_set=="�ں�"){
            message_vision(HIM"$N������ϼ�񹦣�������ϼ���������ڻ�ɽ����֮�У�����ʹ�ô���֮����"+
            HIW"\n$N������ɽ����֮���ӣ���Ů��ϣ����ʽ�����ں�һ������ʽ�ֺ�������о�Ҳ��������Ϣ��\n"NOR,me,target);
            me->start_exert(1+random(2),"����ϼ���⡹");
            me->start_perform(3+random(3),"����ϼ���⡹");
            me->add("neili", -800);
            me->add("jingli", -600);
            me->set_temp("zxg/jianyi/�ں�",1);

            skill = (int)me->query_skill("huashan-jianfa", 1);
            me->add_temp("apply/damage",  skill/3);
            me->add_temp("apply/armor",  skill/6);
            me->add_temp("apply/parry",  skill/4);
            me->add_temp("apply/dodge",  skill/4);
            me->add_temp("apply/dexerity",  skill/10);

            call_out("check_fight", 1, me, weapon, skill);
            return 1;
        }


        if(jianyi_set=="����" && (int)me->query_skill("huashan-jianfa", 1) > 449){
            message_vision(HIM"$N������ϼ���ھ���������"+weapon->name()+HIM"�ϣ���ϼ�������Ķ��������������ˣ�\n"+
            HBMAG"$N�������Ԧ��֮��Ҫ��������ϼ�񹦣�����ɽ�������ӵ����쾡�£�\n"NOR,me,target);
//          me->start_exert(1,"����ϼ���⡹");
//          me->start_perform(3+random(3),"��?�ϼ����?);
            me->add("neili", -800);
            me->add("jingli", -600);
            me->set_temp("zxg/jianyi/�ں�",1);
    //        target->start_busy(3);
  
            skill = (int)me->query_skill("huashan-jianfa", 1);
            me->add_temp("apply/damage",  skill/3);
            me->add_temp("apply/armor",  skill/6);
            me->add_temp("apply/parry",  skill/4);
            me->add_temp("apply/dodge",  skill/4);
            me->add_temp("apply/dexerity",  skill/10);

            call_out("check_fight", 1, me, weapon, skill);
            return 1;
        }


}

void check_fight(object me, object weapon,int skill)
{  
        object wep;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if( !me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || !wep
         ||me->query_skill_mapped("parry") != "huashan-jianfa"
         ||me->query_skill_mapped("sword") != "huashan-jianfa"
         || weapon != wep ){
             if(me->query_temp("zxg/jianyi/����")){
                 me->add_temp("apply/damage",  -skill);
                 me->delete_temp("zxg/jianyi");
             }
             else if(me->query_temp("zxg/jianyi/��Ů")){
                 me->add_temp("apply/dexerity",  -skill/5);
                 me->delete_temp("zxg/jianyi");
             }
             else if(me->query_temp("zxg/jianyi/ϣ��")){
                 me->add_temp("apply/armor",  -skill/2);
                 me->add_temp("apply/parry",  -skill/4*3);
                 me->add_temp("apply/dodge",  -skill/4*3);
                 me->add_temp("apply/damage",  skill/4);
                 me->delete_temp("zxg/jianyi");
             }
             else if(me->query_temp("zxg/jianyi/�ں�")){
                 me->add_temp("apply/damage",  -skill/3);
                 me->add_temp("apply/armor",  -skill/6);
                 me->add_temp("apply/parry",  -skill/4);
                 me->add_temp("apply/dodge",  -skill/4);
                 me->add_temp("apply/dexerity",  -skill/10);
                 me->delete_temp("zxg/jianyi");
             }
             else{
                 message_vision(HIR"�������������֪ͨ����wiz!\n"NOR, me);
             }
           if(living(me) && !me->is_ghost())
              message_vision(HIM"$N��ϼ�����ñϣ�������ʽ�����������Ľ���������ʧ��\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon, skill);
 return ;
}

int help(object me)
{
    write(YEL"\n��ϼ�񹦡�"HIM"��ϼ����"YEL"����"NOR"\n");
    write(@HELP

    Ҫ����ϼ�񹦵ȼ� 250 ���ϣ�
          �����ڹ��ȼ� 250 ���ϣ�
          ��ɽ�����ȼ� 250 ���ϣ�
          ��ǰ���� 800 ���ϣ�
          ��ǰ���� 500 ���ϡ�

HELP
    );
    return 1;
}
