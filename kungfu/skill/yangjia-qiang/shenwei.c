//shenwei.c
//Created by Redhat@Sjmud 2009/4/7
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string perform_name(){ return HIR"����ǹ"NOR; }
int perform(object me, object target)
{
        object weapon;
        int skill,improve;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("������ǹ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "spear" )
                return notify_fail("��������ǹ���������á�����ǹ������\n");

        if( me->query_temp("yjq/shenwei"))
                return notify_fail("������ʹ�á�����ǹ��������\n");
                
        if( me->query_temp("yjq/qinghe"))
                return notify_fail("������ʹ�á�������ɡ�������\n");
                
        if( me->query_temp("yjq/jifeng"))
                return notify_fail("������ʹ�á�����ǹ��������\n");

        if((int)me->query_skill("yangjia-qiang", 1) < 250
         ||(int)me->query_skill("spear", 1) < 250)
                return notify_fail("����Ϊ����������δ����������ǹ����\n");

        if (me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("�������޷�ʹ�á�����ǹ�����й�����\n");

        if( me->query("max_neili") <= 6000 )
                return notify_fail("���������Ϊ���㣬������ʩչ������ǹ����\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("�������������������ʩչ������ǹ����\n");

        if( me->query("jingli") <= 2000 )
                return notify_fail("��ľ������ޣ�������ʩչ������ǹ����\n");
                
        if( (int)me->query_str() < 25 )
		            return notify_fail("�������������㣬�����޷�ʹ��������ǹ��������\n");

        message_vision(HIM"\n$N�˳��ᢣ�ͻȻŭ�����ʹ�����ǹ����֮������ǹ����ֻ��"NOR+weapon->name()+HIM"�����ź�ɫ��â������"HIR"����ǹ"HIM"һ�㣡\n" NOR, me);

        if(userp(me)){
           me->add("neili", -300);
           me->add("jingli", -50);
        }
        skill = me->query_skill("spear");
      	improve = skill/4 + random(skill/4);
      	if ( improve > 100 ) improve = 100 + random(improve-100) / 5;

        me->set_temp("yjq/shenwei", improve);
        me->add_temp("apply/damage", improve);
        me->add_temp("apply/spear", improve);
        me->add_temp("apply/strength", improve/10 );
        call_out("remove_effect", 1,  me, weapon, skill);
        me->start_perform(5+random(8), "������ǹ��");
        return 1;
}

void remove_effect(object me,object weapon,int count)
{
        int i;
        if(!me) return;
        if(! me->is_fighting()
         || !weapon
         || me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang"
         || count < 1 ){
          i = me->query_temp("yjq/shenwei");
          me->add_temp("apply/spear", -i);
          me->add_temp("apply/damage", -i);
          me->add_temp("apply/strength", -i/10 );
          me->delete_temp("yjq/shenwei");
	if (weapon)
		message_vision(HIW"\n$Nһ�ס�����ǹ��ʹ�꣬����"NOR+weapon->name()+HIY"�ϵĺ�ɫ��â����ʧ�ˡ�\n"NOR, me);
          return;
        }
        else {
          me->start_perform(1,"������ǹ��");
          call_out("remove_effect", 1, me, weapon, count -1);
        }
}




