// jianjue.c ȫ�潣�� ͬ�齣��
// modified by xjqx@SJ 2009/01/01
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill,improve;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ͬ�齣����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽�������ܹ�ʹ����ͬ�齣��������\n");

        if( (int)me->query_skill("quanzhen-jianfa", 1) < 150 )
                return notify_fail("���ȫ�潣��������죬�޷�ʹ����ͬ�齣������\n");
                
        if( me->query_temp("qzjf/jianjue"))
                return notify_fail("������ʹ�á�ͬ�齣������\n");

        if( (int)me->query_skill("xiantian-gong", 1) < 150 )
         return notify_fail("��������ڹ���򲻹����޷�ʹ����ͬ�齣������\n");

        if( me->query_skill_mapped("force") != "xiantian-gong")
        return notify_fail("�������ʹ�õ��ڹ����ԣ��޷�ʹ����ͬ�齣������\n");    

        if (me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || me->query_skill_mapped("parry") != "quanzhen-jianfa")
                return notify_fail("�������޷�ʹ�á�ͬ�齣�������й�����\n");

        if( me->query("max_neili") <= 2500 )
                return notify_fail("���������Ϊ���㣬����������ʩչ��ͬ�齣������\n");

        if( me->query("neili") <= 1500 )
                return notify_fail("�����������������������ʩչ��ͬ�齣������\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("��ľ������ޣ�������ʩչ��ͬ�齣������\n");

        message_vision(HIC+me->name()+HIC"������һ����������������" + weapon->name() + ""HIC"��ƴ������������һʽ��"HIR"ͬ�齣��"NOR"��"HIC"��\n"HIC"Ԧ�����Ҿ��׵س���"+target->name()+HIC",��ͼ��"+target->name()+HIR"ͬ��һ��"NOR+HIC"��\n"NOR, me);
 if(userp(me)){
           me->add("neili", -300);
           me->add("jingli", -50);
        }
        skill = me->query_skill("sword",1);
        improve = skill/10 + random(skill/10);
      	if ( improve > 100 ) improve = 100 + random(improve-100) / 5;

        me->set_temp("qzjf/jianjue", improve);
        me->add_temp("apply/damage", improve);//
        me->add_temp("apply/sword", improve);//
        me->add_temp("apply/strength", improve);//
        call_out("remove_effect", 1,  me, weapon, skill);
        me->start_perform(5, "��ͬ�齣����");
        return 1;
}

void remove_effect(object me,object weapon,int count)
{
        int i;
        if(!me) return;
        if(! me->is_fighting()
         || !weapon
         || me->query_skill_mapped("sword") != "quanzhen-jianfa"
         || me->query_skill_mapped("parry") != "quanzhen-jianfa"
         || count < 1 ){
          i = me->query_temp("qzjf/jianjue");
          me->add_temp("apply/sword", -i);
          me->add_temp("apply/damage", -i);
          me->add_temp("apply/strength", -i);
          me->delete_temp("qzjf/jianjue");
	if (weapon)
                message_vision(HIW"$Nʹ��"NOR"��"HIR"ͬ�齣��"NOR+HIW"����"NOR+weapon->name()+HIW"��ȫ�潣������ʧ�����������\n"NOR, me);
          return;
        }
        else {
          me->start_perform(1,"��ͬ�齣����");
          call_out("remove_effect", 1, me, weapon, count -1);
        }
}               
string perform_name(){ return HIC"ͬ�齣��"NOR; }
