// lengquan.c  ��Ȫ��֮����Ȫ��.
// Create by lsxk@hsbbs 2007/5/11
// By Spiderii@ty ����Ч��,����̫ǿ�ˣ���9yin����
// ������sj test��������.lsxk��Ч��������Щ.lqsg��λΪ �м�quest
#include <ansi.h>

inherit F_SSERVER;
private int remove_effect(object me, int amount);
int exert(object me)
{
//        object weapon = me->query_temp("weapon");  
        int skill;
    
         if ((int)me->query_skill("lengquan-shengong", 1) < 200 )
                return notify_fail("����Ŀǰ��Ȫ�񹦵���Ϊ��ʵ��������������صġ���Ȫ��������\n");

        if ((int)me->query_skill("force", 1) < 200 )
                return notify_fail("��Ȫ�񹦵ġ���Ȫ����������Ҫ���������ڹ�����������Ļ����ڹ�����Ƿ���\n");
    
        if (me->query_skill_mapped("force") != "lengquan-shengong" )
                return notify_fail("��������ʹ���ˡ���Ȫ��������\n");
    
        if ((int)me->query("neili") < 2000 )
                return notify_fail("����ô�ٵ���������������������ļ�Ԧ����Ȫ��������\n");

        if ((int)me->query("jingli") < 1500 )
                return notify_fail("����ô�ٵľ�������������������ļ�Ԧ����Ȫ��������\n");

        if ((int)me->query("max_neili") < 4000 )
                return notify_fail("����Ŀǰ��������Ϊ��ʹ�á���Ȫ��������С���߻���ħ������\n");

        if ((int)me->query("max_jingli") < 2500 )
                return notify_fail("����Ŀǰ�ľ�����Ϊ��ʹ�á���Ȫ��������С���߻���ħ������\n");

        if ( me->query_temp("lqsg/lq") )
                return notify_fail("����������ʹ�á���Ȫ��������\n");

        message_vision(HIW "$N�����������У��ò�ʹ�죡�������߶���Ȫ���ھ�����ʹ����"HIB"��Ȫ"HIW"��������\n"+
        "$N��ʮ�ؿ�������Ȫ��ʹ��������������һ�ɺ��İ��������Χ��\n"+
        "������ѧ��ʶ���ˣ�һ����֪���������ڼҹ������������߾��������Ļ�����\n"+
        "��������Ȫ���˵��浱���湦���ټ���$N��ʮ����һ�յؿ����������Ȼ��\n"+
        "һ��ǽ֮�񣬿ɵ��浶ǹ���룡������ʱ��$N�����Լ���ʮ����ϰ�书ȫ���ں�\n"+
        "��������ʽ��Ȼ��Ϊһ�壬�����������Ȫ����������������֫����е�����ܿ�\n"+
        "ɽ�����أ�������Ȫ�����ھ�ɢ����������ͭǽ���ڣ����а��������Ѱ��\n"NOR,me);

        me->start_exert(random(3)+1,"����Ȫ��");
        me->add("neili", -800); 
        me->add("jingli", -500);
    
        skill = (int)me->query_skill("lengquan-shengong", 1) / 5;
        me->add_temp("apply/attack",  skill);
        me->add_temp("apply/armor",  skill);
//       me->add_temp("apply/defense",  skill* 10);
        me->add_temp("apply/dodge",  skill/10);
        me->add_temp("apply/damage", skill);
       // me->add_temp("apply/dexerity",skill/10);
       // me->add_temp("apply/strength",skill/10);
       // me->add_temp("apply/constitution",skill/10);
        me->set_temp("lqsg/lq", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me :), skill);
        return 1;
}



private int remove_effect(object me, int amount)
{         
        int skill,i;
        skill = (int)me->query_skill("lengquan-shengong", 1) / 5;
 
        me->add_temp("apply/attack",  -skill);
        me->add_temp("apply/armor",  -skill);
        me->add_temp("apply/dodge",  -skill/10);
        me->add_temp("apply/damage", -skill);
//        me->add_temp("apply/defense",  -skill* 10);
      //  me->add_temp("apply/dexerity",-skill/10);
      //  me->add_temp("apply/strength",-skill/10);
      //  me->add_temp("apply/constitution",-skill/10);
        me->delete_temp("lqsg/lq");
        if(living(me) && !me->is_ghost())
          message_vision(HIW"$N����Ȫ��֮��"HIB"��Ȫ"HIW"������ʹ�ϣ�ֻ������Ѫͨ��������ޱȣ�\n"NOR, me);
        if(me->query_skill_mapped("force") != "lengquan-shengong") return 0;
        if(living(me) && !me->is_ghost() && random((int)me->query("kar"))>25 && !random(3)){
          if (random(2)==0){
              me->add("max_neili",random(2)+1);
              tell_object(me,HIC"�㡸��Ȫ������ʹ���ֻ����������ˬ���ھ��ޱȳ��棬���������Ϊ����������ˣ�\n"NOR);
              }
          else{
              i = random(2)+1;
              me->add("max_jingli",i);
              me->add("eff_jingli",i);
              tell_object(me,HIC"�㡸��Ȫ������ʹ���ֻ����������ˬ���ھ��ޱȳ��棬��ľ�����Ϊ����������ˣ�\n"NOR);
              }
        }
        return 0;
}

int help(object me)
{
   write(WHT"\n��Ȫ�񹦡�"HIB"��Ȫ"WHT"����"NOR"\n");
   write(@HELP
   ��Ȫ���˵����ڹ�һ��,�ǳ����ܵ�Ҳ!�ˡ���Ȫ����������
   ����£�Ҳ���������Ĺ��򣬸�����Ϊ�������Ƿ��켫�ز���
   �����޷�������һ��ʽ�����ǣ��������񹦣�����������
   ��þ��У���ս���л���ʱ������ȵ��������Ĺ���������
   ���ʣ������ʣ����������������������ԡ�ֻ�´Ӵ����߽���
   �����ж��֣�������ѧ֮������豹��澳�磡���⣬��ʹ�ø�
   ����Ȫ����������������������������ѧ��ΪҲ�ǲ���
   ��֮�£�

   Ҫ��  ���� 2000 ���ϣ�
           ���� 1500 ���ϣ� 
           ������� 4000 ���ϣ� 
           ����� 2500 ���ϣ� 
           ��Ȫ�� 200 ���ϣ� 
           �����ڹ� 200 ���ϣ� 

HELP
   );
   return 1;
}

