// ruyi.c
// action@SJ 2008/12/28
//modified by Zhuifeng@SJFY
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int focus, i, j;

	focus = me->query_temp("ry/focus");
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("����������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_skill("ruyi-dao", 1) < 100 )
		return notify_fail("������������ȼ����㣬�޷�ʹ�á�����������������\n");

	if( me->query_skill("blade", 1) < 100 )
		return notify_fail("��Ļ��������ȼ����㣬�޷�ʹ�á�����������������\n");

       	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 150 )
       	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 100 )
		return notify_fail("��ı�ڤ�񹦵ȼ����㣬�޷�ʹ�á�����������������\n");
                
	if( me->query("max_neili") < 1000 )
		return notify_fail("����������㣬�޷�ʹ�á�����������������\n");

	if( me->query("neili") < 800 )
		return notify_fail("����������㣬�޷�ʹ�á�����������������\n");

         if (me->query_skill_mapped("force") != "beiming-shengong")
         if (me->query_skill_mapped("force") != "bahuang-gong" )   
		return notify_fail("��ʹ�õ��ڹ����ԣ��޷�ʹ�á�����������������\n");

	if (!objectp(weapon = me->query_temp("weapon")) 
	|| weapon->query("skill_type") != "blade"
	|| me->query_skill_mapped("blade") != "ruyi-dao"
	|| me->query_skill_mapped("parry") != "ruyi-dao" )
		return notify_fail("�������޷�ʹ�á�����������������\n");

	i = me->query_skill("ruyi-dao", 1);
       if(!userp(me)) i = i/3;

message_vision(HIC"\n$Nһ����Ц�����ֽ�����"+weapon->query("name")+HIC"�ӳ���$Nֻ�������������⣬�������أ��Ĺ�ʲô�Ƿ����裬ֻ��Ʈ�ݷǷ���������ͨ����\n"NOR, me);

	j = i / 4;
        if ( i > 350 )
                j = to_int(i/ 4.0 * i/ 350.0);

	if ( focus > 15 ) focus = 15;

	j += 1 * focus;
 
  if (me->query("family/family_name") == "��ң��") {             
	me->add_temp("apply/attack", j  );
};
  if (me->query("family/family_name") == "���չ�") {             
	me->add_temp("apply/attack", j *2 );
		me->add_temp("apply/damage", j  );
};

	me->add_temp("apply/blade",  j * 2  );
	me->add_temp("apply/damage", j  );
	me->set_temp("ryd/ruyi",1);
if(!userp(target)) target->add_busy(2);

message_vision(MAG "\n$N���һ������һ������ֻ��"+weapon->query("name")+MAG"����$N������˳������һ����"NOR, me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

	if(me->is_fighting(target)) {
                message_vision(MAG "\n$N���һ�����ڶ�������$N�������������δ������������һ����"NOR, me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),  3);};

   if(me->is_fighting(target) && (int)me->query_skill("ruyi-dao", 1) > 100 ) {
        message_vision(MAG "\n$N���һ��������������$N������ת������һ���ֻ�ת������\n"NOR, me,target);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);};

 if (me->query("family/family_name") == "��ң��") {
	me->add_temp("apply/attack", -j  );
};

  if (me->query("family/family_name") == "���չ�") {             
	me->add_temp("apply/attack",- j *2 );
			me->add_temp("apply/damage",- j  );
};

	me->add_temp("apply/blade",  -j * 2 );
	me->add_temp("apply/damage", -j );
        me->start_perform(2+random(3), "��������");
	me->add("neili", -200);
	me->add("jingli", -100);
	if( i > 220 && me->is_fighting(target)&& target->is_fighting(me) )
              call_out("perform2", random(2)+1, me, target); 
	return 1;
}

int perform2(object me, object target)
   {  
	int focus,  j;
if(!me) return;
             j = me->query_skill("ruyi-dao", 1);
                   if(!userp(me)) j = j/2;
                
		focus = me->query_temp("ry/focus");
   	
	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("����������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


          me->add_temp("apply/attack", j / 4);
          me->add_temp("apply/blade",  j / 2 );
	  me->add_temp("apply/damage", j / 2);
	  me->set_temp("ryd/ruyi",1);
if(!userp(target)) target->add_busy(2);
		 if(me->is_fighting(target)&&!me->is_busy()) {
     message_vision(MAG "\n$N���һ�������ĵ�����$N���浶ת��˳������һ����"NOR, me,target); 
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"),  3);};

	   if(me->is_fighting(target)&&!me->is_busy()) {
		 message_vision(MAG "\n$N���һ�������嵶����$N�������������δ������������һ����"NOR, me,target);
	   COMBAT_D->do_attack(me, target, me->query_temp("weapon"),  3);};

     if(me->is_fighting(target) && (int)me->query_skill("ruyi-dao", 1) > 100 &&!me->is_busy()) {
   	 message_vision(MAG "\n$N���һ��������������$N������ת������һ���ֻ�ת������"NOR, me,target);
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);};


	me->add_temp("apply/attack", -j /4);
	me->add_temp("apply/damage", -j /2);
	me->add_temp("apply/blade",  -j /2 );

	me->add("neili", -200);
	me->add("jingli", -100);
	me->delete_temp("ryd/ruyi");
	me->start_busy(random(2));
	me->start_perform(3+random(3), "��������");
}
string perform_name(){ return HIY"��������"NOR; }

int help(object me)
{
        write(HIY"\n���⵶��֮��������������"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 800 ���ϣ�
                ������� 1200 ���ϣ�
                ��ǰ���� 500 ���ϣ�
                ���⵶���ȼ� 100 ���ϣ�
                ��ڤ�񹦵ȼ� 100 ���ϣ�
                ���������ȼ� 100 ���ϣ�
                ��������Ϊ���⵶����
                �����м�Ϊ���⵶����
                �����ڹ�Ϊ��ڤ�񹦣�
                ���ֱֳ�����

HELP
        );
        return 1;
}
