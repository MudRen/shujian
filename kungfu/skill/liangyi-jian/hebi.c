//���������ǽ�֮˫���ϱ�
//update by cool 981104
#include <ansi.h>
inherit F_SSERVER;
string perform_name(){ return HIY"˫�����"NOR; }
//int remove_effect(object me);
int perform(object me, string arg)
{
    object weapon, weapon1, target;
    int skill, skill1;
    string msg;

    if(!arg) return notify_fail("�����˭һ���赣�\n");
    if(!objectp(target = present(arg, environment(me))))
             return notify_fail("����û������ˡ�\n");
/*��Ҫ�ж��Ƿ񹥻�ͬһ����*/
    if( !target->is_fighting() || !target->is_character() || !me->is_fighting())
                return notify_fail("���ֻ����ս����ʹ�á�\n");
    if(!living(target))
                return notify_fail(target->name()+"�Ѿ��޷�ս���ˡ�\n"); 
    if(target==me) return notify_fail("���Լ���赣�\n"); 
    if(me->is_fighting(target))
                return notify_fail("�����ں�"+target->name()+"����ء�\n");            

    weapon = me->query_temp("weapon");  
    weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "liangyi-jian"
      || me->query_skill_mapped("parry") != "liangyi-jian")
        return notify_fail("�������޷�ʹ�á�˫����赡���\n");

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "liangyi-jian"
      || target->query_skill_mapped("parry") != "liangyi-jian")
        return notify_fail(target->name()+"�����޷�ʹ�á�˫����赡���\n");

    skill = me->query_skill("liangyi-jian", 1);
    skill1 = target->query_skill("liangyi-jian", 1);

    if(skill < 100 )
        return notify_fail("������ǽ����ȼ�����������ʹ�á�˫����赡���\n");
    
    if((int)me->query_skill("xuantian-wuji", 1) < 100 )
        return notify_fail("��������޼����ȼ�����������ʹ�á�˫����赡���\n");       
    
    if((int)me->query("neili") < 500 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");
    if((int)me->query("max_neili") < 1000 )
        return notify_fail("����������̫��������ʹ�á�˫����赡���\n");

    if(me->query_temp("ly_hebi")) 
        return notify_fail("���Ѿ���ʹ�á�˫����赡��ˡ�\n");

   if(target->query_temp("ly_hebi")) 
        return notify_fail(target->name()+"�Ѿ��ں�����ʹ�á�˫����赡��ˡ�\n");

          
    if(me->query_temp("lyhebi_target")){
          if(me->query_temp("lyhebi_target")==target)
                return notify_fail("���Ѿ����ú�"+target->name()+"˫����赵�׼���ˡ�\n");
          else{
               tell_object(me->query_temp("hebi_target"), YEL+me->name()+"������������˫������ˡ�\n"NOR); 
                me->delete_temp("lyprepare_hebi");
                me->delete_temp("lyhebi_target");
               }
          }
     if(target->query_temp("lyprepare_hebi") && target->query_temp("lyhebi_target") ==me){
        message_vision(MAG"\n $N��$nʹ����ɫ,����"+weapon->name()+MAG+"��$n��"+weapon1->name()+MAG+"���������˫�����ϣ���ʱֻ����������������������\n"NOR, me, target);
       me->delete_temp("lyprepare_hebi");
       me->delete_temp("lyhebi_target");
       target->delete_temp("lyprepare_hebi");
        target->delete_temp("lyhebi_target");
        me->set_temp("ly_hebi", 1); 
        target->set_temp("ly_hebi", 1); 
        me->add("neili", -300);
        target->add("neili", -300);
        me->add("jingli", -50);
        target->add("jingli", -50);
        remove_call_out("check_reply");
        me->start_call_out( (: call_other, __FILE__, "check_fight", me, target :), 1);
        target->start_call_out( (: call_other, __FILE__, "check_fight", target, me :), 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (skill+skill1)/2);
        target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), (skill+skill1)/2);
        return 1;
        }
    message_vision(HIC"\n $N������"+weapon->name()+HIC"һ�ᣬ��ʾ$n��$Pһ������˫����赡�\n"NOR, me, target);
    tell_object(target, YEL"�����Ը���"+me->name()+"����˫���ͱڣ���Ҳ��"+me->name()+"��һ�� ( perform hebi <player's id> ) �����\n"NOR); 
    me->set_temp("lyprepare_hebi", 1);     
    me->set_temp("lyhebi_target", target);
      call_out("check_reply", 15, me); 
    return 1;
}

void check_fight(object me, object target)
{
    object weapon,weapon1;  
    
 	weapon = me->query_temp("weapon");  
      weapon1 = target->query_temp("weapon");  

    if(!weapon || weapon->query("skill_type") != "sword"
      || me->query_skill_mapped("sword") != "liangyi-jian"
      || me->query_skill_mapped("parry") != "liangyi-jian")
         call_out("remove_effect", 0, me);

    if(!weapon1 || weapon1->query("skill_type") != "sword"
      || target->query_skill_mapped("sword") != "liangyi-jian"
      || target->query_skill_mapped("parry") != "liangyi-jian")
		  call_out("remove_effect", 0, me);

     else if((!present(target->query("id"), environment(me))) ||
            !me->is_fighting() || !living(target) || !target->is_fighting()
            || target->is_ghost() || me->is_ghost() || !living(me)
            || !target->query_temp("ly_hebi"))
         call_out("remove_effect", 0, me);

    else call_out("check_fight", 1, me, target);
}
void check_reply(object me)
{
if (me->query_temp("lyprepare_hebi", 1)) {     
        me->delete_temp("lyprepare_hebi");     
        me->delete_temp("lyhebi_target");
            return notify_fail("�ƺ��Է�����İ�ʾû�з�Ӧ������ֻ��ȡ����˫���ϱڵ�����\n");
}   
}
void remove_effect(object me)
{
  if(me->query_temp("ly_hebi")){
    me->delete_temp("ly_hebi");
	return notify_fail(HIR"��˫�������ᣬ����Ҳ�ָ������ˡ�\n"NOR);
       }
}

int help(object me)
{
   write(WHT"\n�����ǽ�����"HIY"������˫�����"WHT"����"NOR"\n\n");
   write(@HELP
                 ������˫�˺�赣�һ��һ����������������         


  ����Ҫ�����ǽ����������޼�����100�����ϡ�
                 �������1000���ϣ���ǰ����500���ϡ�

HELP
   );
   return 1;
}
