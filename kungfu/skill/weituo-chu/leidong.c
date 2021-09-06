#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill,improve;

        if( !target && me->is_fighting() ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("���׶����졹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "club" )
                return notify_fail("�������޹����������á��׶����졹����\n");

        if( me->query_temp("sl_leidong"))
                return notify_fail("���ʹ�꡸�׶����졹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

        if( me->query_temp("fumo"))
                return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");

        if( me->query_temp("sl/xiouliqiankun"))
        	return notify_fail("����ʹ�ð����Ƶľ�������Ǭ���ء�\n");

	if(me->query("menggu"))
		return notify_fail("�����ַ��Ű��࣬����ܹ����÷����񹦡�\n");

        if((int)me->query_skill("weituo-chu", 1) < 150
         ||(int)me->query_skill("weituo-chu", 1) < 150
         ||(int)me->query_str() <=30 )
                return notify_fail("����Ϊ����������δ�������׶����졹��\n");

        if( me->query_skill("yijin-jing", 1) < 150 )
                return notify_fail("����ڹ���Ϊ���δ����ʩչֻ���˼�����\n");

        if( me->query_skill_mapped("force") != "yijin-jing")
                return notify_fail("�����õ��ڹ��롸�׶����졹�ķ���㣣�\n");

        if (me->query_skill_mapped("club") != "weituo-chu"
         || me->query_skill_mapped("parry") != "weituo-chu")
                return notify_fail("�������޷�ʹ�á��׶����졹���й�����\n");

        if( me->query("max_neili") <= 2000 )
                return notify_fail("���������Ϊ���㣬����������ʩչ���׶����졹��\n");

        if( me->query("neili") <= 600 )
                return notify_fail("�����������������������ʩչ���׶����졹��\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ������ޣ�������ʩչ���׶����졹��\n");

        message_vision(BLU"\nͻȻ$N���һ�������׶����졹����ɫ৵ı��ͨ�죬�뷢�Էɣ���������"+weapon->name()+BLU"���У����ˡ���һ��������"HIW"��������"BLU"��\n" NOR, me);

        if(userp(me)){
           me->add("neili", -300);
           me->add("jingli", -50);
           if(weapon->query("rigidity")<10)
                weapon->add("rigidity", 1);
        }
        skill = me->query_skill("club");
      	improve = skill/4 + random(skill/4);//ԭ����5
      	if ( improve > 100 ) improve = 100 + random(improve-100) / 5;

        me->set_temp("sl_leidong", improve);
        me->add_temp("apply/damage", improve);//
        me->add_temp("apply/club", improve);//
        me->add_temp("apply/strength", improve);//
        call_out("remove_effect", 1,  me, weapon, skill);
        me->start_perform(5, "���׶����졹");
        return 1;
}

void remove_effect(object me,object weapon,int count)
{
        int i;
        if(!me) return;
        if(! me->is_fighting()
         || !weapon
         || me->query_skill_mapped("club") != "weituo-chu"
         || me->query_skill_mapped("parry") != "weituo-chu"
         || count < 1 ){
          i = me->query_temp("sl_leidong");
          me->add_temp("apply/club", -i);
          me->add_temp("apply/damage", -i);
          me->add_temp("apply/strength", -i);
          me->delete_temp("sl_leidong");
	if (weapon)
		message_vision(HIY"\n$Nһ�ס��׶����졹ʹ�꣬����"NOR+weapon->name()+HIY"�ϵĹ�â����Ҳ��ʧ�ˡ�\n"NOR, me);
          return;
        }
        else {
          me->start_perform(1,"���׶����졹");
          call_out("remove_effect", 1, me, weapon, count -1);
        }
}

string perform_name(){ return BLU"�׶�����"NOR; }

int help(object me)
{
        write(
@HELP
�׶�����
       �Ƿ����񹦣���Τ���Ƶ����⹥������һ������ڹ�ע���������������У�
       ն����ħ���޼᲻�ݣ������ނ������Ƿ��ŵ�һ�ȵķ�ħ�񹦡�
HELP
        );
        return 1;
}
