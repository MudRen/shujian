// qianshou.c ǧ��
// By lius 99/8
#include <ansi.h>

inherit	F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object target,object	me);

string *xue_name1 =({
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","�羮Ѩ"});
string *xue_name2 = ({
"�ٻ�Ѩ","����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ"});
string *xue_name3 = ({
"����Ѩ","����Ѩ","�縮Ѩ","����Ѩ","��̨Ѩ","����Ѩ","����Ѩ","��ͻѨ"});
 
 int perform(object me,	object target)
{      object weapon = me->query_temp("weapon");
	int p,i,j,z;
	string name1,name2,name3;
	weapon = me->query_temp("weapon");
	name1 =	xue_name1[random(sizeof(xue_name1))];
	name2 =	xue_name2[random(sizeof(xue_name2))];
	name3 =	xue_name1[random(sizeof(xue_name3))];
	if( !target) target = offensive_target(me);
	if( !target || !me->is_fighting(target)	|| !living(target)
		    || environment(target)!=environment(me))
	   return notify_fail("û��ս��������������˾޴�������û�ǧ�֣�\n"); 
	if (! present("furong jinzhen",me ))
	   return notify_fail("û�н��룬��ʹ�û�ǧ�����к���?!\n");
	if(!weapon || weapon->query("skill_type") != "throwing"	)
	   return notify_fail("�����м��ް������û�ǧ��Ҳ�����ã�\n");
	if( (int)me->query_skill("yinyun-ziqi",1) < 150	)
	   return notify_fail("�����������Ϊ���㣬�޷��û�ǧ�֣�\n");
	if( (int)me->query_skill("furong-jinzhen",1) < 150 )
	   return notify_fail("���ܽ�ؽ���ȼ��������޷�������˸�����似��\n");
	if( (int)me->query_skill("force", 1) < 150 )
	   return notify_fail("��Ļ����ڹ���Ϊ���㣬�������⵽���棡\n");
	if( (int)me->query_skill("throwing", 1)	< 150 )
	   return notify_fail("��Ļ���������Ϊ���㣬���ܼ�����˸��ӵ��ַ���\n");
	if (me->query_skill_mapped("throwing") != "furong-jinzhen")
	   return notify_fail("������ܽ�ؽ������ʹ��ǧ�־�������\n");
	if (me->query_skill_mapped("parry") != "furong-jinzhen")
	   return notify_fail("������ܽ�ؽ������ʹ��ǧ�־�������\n");
	if( (int)me->query("neili") < 600 )
	   return notify_fail("����������㣬����ʹ��ǧ�־�����\n");
	if( (int)me->query("max_neili") < 1200 )
	   return notify_fail("����������㣬����ʹ��ǧ�־�����\n");
	if( (int)me->query("jingli") < 300 )
	   return notify_fail("��ľ������㣬����ʹ��ǧ�־�����\n");
	if(target->query_temp("qianshou"))
	   return notify_fail("�Է��Ѿ��������ס������Ѩ�������ٶ���ֽ��ˣ�\n");

i=me->query_skill("furong-jinzhen",1)+me->query_skill("throwing",1)+me->query_skill("force",1);
j=target->query_skill("parry",1)+target->query_skill("dodge",1)+me->query_skill("force",1);
	p = random(i/3);
	z = (i -j)/3;
	if ( z < 3 ) z = 3;
	if ( z > 12 ) z	=12;
      
       message_vision(HIR"\nͻȻ$Nһ����Х���ֱ����գ������ֱ���糵����ת������
��ͬ�û���ǧ�����ֱۣ��ѷֲ�������������Ӱ����\n"NOR,me,target);
	 
	 me->add("neili", -500);
	 me->add("jingli", -50);
      if ( random(z) > 10 && me->query_skill("throwing", 1) > 200 && me->query_skill("furong-jinzhen", 1) > 200	){ 
      tell_object(me, MAG"���һ����Ч��ѹ����������²��ٹ��ǣ��������ȣ���\n"NOR);
      tell_object(target, MAG"�����У���ͻ��"RED+name1+MAG"��"RED+name2+MAG"��"RED+name3+MAG"ͬʱһ�飬һ������ɢ����֫Ҳ��ʼ��ľ��ɲʱ�����ң���\n"NOR);
	 target->receive_damage("qi", i/3+p);
	 me->start_busy(3);
	 target->start_busy(5);
	 target->set_temp("qianshou", 1);
	 target->set_temp("apply/strength", -(target->query("str", 1)/3));    
	 target->set_temp("apply/dexerity", -(target->query("dex", 1)/3));  
	 target->set_temp("apply/intelligence",	-(target->query("int", 1)/3));	  
	 target->set_temp("apply/constitution",	-(target->query("con", 1)/3));	
	 target->apply_condition("no_perform", i/26);
	 target->start_call_out((:call_other,__FILE__,"remove_effect",target:),i/6); 
	 return	1; }
	 if (random((int)me->query("combat_exp",1)) > (int)target->query("combat_exp",1)/2 && random(i)	> j/3)
       {  if ( random(z) > 5 &&	(int)me->query_skill("throwing", 1) > 180 && (int)me->query_skill("furong-jinzhen", 1) > 180 ){
	tell_object(me,	HIB"���"+target->name()+"˫üͻȻ����һ��������ʹ�������ǳԿ����٣���ʱ�������\n"NOR);
	tell_object(target, HIB"��ս�У���ͻ��"RED+name1+HIB"��"RED+name2+HIB"ͬʱһ�飬Ѫ����ʱΪ֮һ��������æ���������
�������죬�����ް���ȴҲ��Ū�Ķ��ϼ�����֪�ǳԿ����١�\n"NOR);
	     target->receive_damage("qi", i/3+p);	     
	    me->start_busy(3);
	    target->start_busy(3);
	    return 1; }
       else
       switch(random(2)) {
	  case "0":
	   tell_object(me, HIM"����������������Է���ֻ��΢΢һ�������������ϣ����ﰵ���Ի�\n"NOR);
	   tell_object(target, HIM"��ս�У���΢��"RED+name1+HIM"һ�飬֪�ǽ������ˣ�æ������أ����˴�����Щ��ʹ��ȴ���޴󰭡�\n"NOR);
	   target->receive_damage("qi",	i/3);		 
	  me->start_busy(2);
	  target->start_busy(1);
	  break;
	  case "1":		  {	  
	   me->start_busy(3);
	   me->add("neili", -(100+random(50)));	
	   me->add("jingli", -100);		
	   message_vision(BLU"ֻ��$p����Ʈ���������ޱȵıܿ���$N����������������⡣\n"NOR,me, target);
	    break;}
	 return	1;}
	return 1;}
}

void remove_effect(object target,object	me)
{
      me = this_player();
      if(!target) return;
      target->delete_temp("apply/strength");	
      target->delete_temp("apply/dexerity");  
      target->delete_temp("apply/intelligence");    
      target->delete_temp("apply/constitution");  
      target->clear_condition("no_perform");
      target->delete_temp("qianshou");
      message_vision(WHT"ֻ��$p����һ�����������ۡ������ϱƳ���ö���룬����֮��������\n"NOR,target);
      tell_object(me,WHT"��پ�����֮��ȫ�������а������泩�ޱȡ�\n"NOR);
}
