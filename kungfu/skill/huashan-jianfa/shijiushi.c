// shijiushi.c ��Ůʮ��ʽ

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#define MAX_HITS   9
 
string perform_name() {return HIC"��Ůʮ��ʽ"NOR;}

int perform(object me, object target)
{
        string weapon;
        int i,hits,lvl;

        if( !target ) target = offensive_target(me);

        if( !target 
         || !me->is_fighting(target)
         || !objectp(target)
         || environment(target)!= environment(me))
                return notify_fail("��Ůʮ��ʽֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
        if (me->query_skill_mapped("force") != "zixia-gong"
          &&me->query_skill_mapped("force") != "huashan-qigong")
                return notify_fail("����ڹ������޷�ʹ�á���Ůʮ��ʽ����\n");

        if( me->query_dex() < 60 )
                return notify_fail("�������������������㣬����ʹ����Ůʮ��ʽ��\n");
        
        if( me->query_skill("zixia-gong", 1) < 300
         && me->query_skill("huashan-qigong", 1) < 300)
                return notify_fail("��������ڹ����δ�����޷�ʩչ��Ůʮ��ʽ��\n");

        if( (int)me->query_skill("huashan-jianfa",1) < 300 )
                return notify_fail("��Ļ�ɽ��������㣬�޷�ʹ�þ�����׵���Ůʮ��ʽ��\n");

        if( me->query_skill("dodge") < 300 )
                return notify_fail("��Ůʮ��ʽ��Ҫ�������Ṧ��ϣ�������Чʩչ��\n");

        if( me->query_skill("sword") < 300 )
                return notify_fail("�㽣��δ��¯����֮����������ʹ����Ůʮ��ʽ��\n");

        if( me->query("neili") <= 5000 )
                return notify_fail("�����������ʹ����Ůʮ��ʽ��\n");

        if( me->query("jingli") <= 3000 )
                return notify_fail("��ľ�������ʹ����Ůʮ��ʽ��\n");

        if( me->query_temp("hsj_19"))
                return notify_fail("������������Ůʮ��ʽ��\n");

      if(!me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("�������޽�����ʹ����Ůʮ��ʽ����\n");


      if(me->query_skill_mapped("sword") != "huashan-jianfa")
        if(me->query_skill_mapped("sword") != "dugu-jiujian")
                return notify_fail("�㲻�û�ɽ��������ôȥʩչ��Ůʮ��ʽ����\n");

        weapon = (me->query_temp("weapon"))->query("name");
        lvl = me->query_skill("huashan-jianfa",1);
        message_vision(HIC "\n$N�˽���磬����ǳ��ġ���Ů��ʮ��ʽ��һʽʽʩչ������" + weapon + HIC"����������,���������⣡\n" +
        "���֮�䣬$N������Ůʮ�Ž�������ʮ��ʽ��������һ���ǳɵ�ʹ�˳������������б���һ�У�����֮�죬ֱ�Ƿ�����˼��\n" NOR, me, target);
        me->set_temp("hsj_19",1);
     
   if(me->query("quest/huashan")=="����" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/damage",lvl/5);
    
   if(me->query("quest/huashan")=="����" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/attack",lvl/5);
       
      me->add_temp("apply/damage", lvl/4);
      me->add_temp("apply/attack", lvl/4);
      
      hits =random(MAX_HITS);
   if(hits<4) hits = 4;

 if (me->query("quest/huashan") == "����") {
    if(hits<6) hits = 4+random(3);
                 if(random(2)|| !userp(target)){
                 message_vision(HBGRN"$N�˿̽���ɽ�ɽ��ڵľ����������ӵ����£�$nֻ����"+weapon+HBGRN+"��Ӱ���У����޿ɵ���\n"NOR,me,target);
                                target->apply_condition("no_fight",1);
                            }
                            
               
if(me->query("quest/zixia/pass") && me->query_temp("zxg")) 
             {   message_vision(HIM"$N������ɽ�����ڵ����ɾ�����ϼ�ھ��˵����£�����"+weapon+HIM+"����ϼ����������ƥ��$n�ĸ��мܣ�ֻ���ݱܷ�â���������ˣ���\n"NOR,me,target);
                              target->add_busy(hits);
             }


                me->add("jingli", -300);
                                                      }
                                                      
                                                      
                                                      
                                                      

   else  if (me->query("quest/huashan") == "����" || me->query("quest/zixia/pass")) {            
                 if(random(2)){
                 message_vision(HIM"$N������ɽ�����ڵ����ɾ�����ϼ�ھ��˵����£�"+weapon+HIM+"��â����������������ƥ��\n"NOR,me,target);
                                target->apply_condition("no_fight",1);
                              }
                if(random(2)|| !userp(target)){
                message_vision(HIM"$N����"+weapon+HIM+"����ϼ����������ƥ��$n�ĸ��мܣ�ֻ���ݱܷ�â���������ˣ���\n"NOR,me,target);
                      target->add_busy(2);
                              }
                me->add("neili", -500);
                                                    }
   for( i = 0; i < hits; i ++ ) {

    if (target && me->is_fighting(target) )    
{
              
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

 }
    else break;
 }
  
  
   if(me->query("quest/huashan")=="����" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/damage",-lvl/5);
    
   if(me->query("quest/huashan")=="����" ||me->query("quest/zixia/pass"))
          me->add_temp("apply/attack",-lvl/5);
       
      me->add_temp("apply/damage", -lvl/4);
      me->add_temp("apply/attack", -lvl/4);
        
        me->add("jingli", -100);
        me->add("neili", -500);
        me->delete_temp("hsj_19");
        me->start_perform(3+random(3),"��Ůʮ��ʽ");
        me->start_busy(1);
        return 1;
}

int help(object me)
{
   write(WHT"\n��ɽ������"HIC"��Ůʮ��ʽ"WHT"����"NOR"\n");
   write(@HELP
    ���С���Ůʮ��ʽ�����ɽ�ȱ���Ѫ��������ɽ���ڣ����ڶ�����
    ��ȴ��������ͬ�����ڽ���������ӯ���ɣ�����������������ȴ����
    ���������Ԧ������ˣ�����ʹ������Զǿ�ڽ��ڣ� ��������������
    ����Ϊ����������Զ�������ڡ�
    ���м����õ���æ�ҡ�
    ����ܻ�ɽ���ɾ�ѧ���¾Ž�����ϼ�񹦣��������ɷ��������¡�
    ָ�perform shijiushi

    Ҫ�󣺻�ɽ���� ���� ��ϼ�� 300��
          ����������60��
          ��ɽ����300����
          ��������300����
          �����Ṧ300����
          ��ǰ����5000���ϣ�
          ��ǰ����3000���ϡ�
HELP
   );
  return 1;
}
