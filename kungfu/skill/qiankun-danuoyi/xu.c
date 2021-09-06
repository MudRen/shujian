// xu.c Ǭ����Ų�ơ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int check_fight(object me);
string perform_name(){ return HIB"���־�"NOR; }

int perform(object me, string arg)
{
	object ob;
	string msg;
	int i, jiali, p, damage;
        
	if(!me->is_fighting())
		return notify_fail("��û��ս�����أ�\n");

	if(me->query_temp("weapon"))
		return notify_fail("����־��˿��־������������������ʹ�ó���\n");

	if ( me->query_temp("qkdny/xu") == 1)
		return notify_fail("���Ѿ�ʹ���ˡ���־��ˡ�\n");

	if ( me->query_temp("qkdny/yi") )
		return notify_fail("������ʩչ���ơ��־��أ�\n");

	if ( me->query_temp("qkdny/yin") )
		return notify_fail("������ʩչ�������־��أ�\n");

	if ( me->query_temp("qkdny/hua") )
		return notify_fail("������ʩչ�������־��أ�\n");

	if(me->query_temp("qkdny/xu") > 1) {
		if(arg && !objectp(ob = present(arg, environment(me))))
			return notify_fail("��û��ս�����أ�\n");
		else    ob = offensive_target(me);

		if(!ob 
		 || !ob->is_character() 
		 || !me->is_fighting(ob) 
		 || environment(ob) != environment(me) 
		 || !living(ob))
			return notify_fail("����־������������ֻ�ܶ�ս���ж���ʹ�á�\n");
         	
		i = me->query_temp("qkdny/xu");
         	
		if(me->query("neili") < i)
			i = me->query("neili");
         		
		jiali = me->query("jiali");
         	
		if(jiali > i)
			i = jiali;
         		
		if(i < 10)
			return notify_fail("�㡸��־������������̫�٣�ֻ��û��ʲô���ã�\n");
         	
		me->set("jiali", i+jiali);

		if(wizardp(me))
			tell_object(me, "����־����� = "+i+"\n");

		msg = HIY"\n$NͻȻ����һ�������������ʮ���Ƶ������鲢��Ϊһ��Ѹ������$n��\n"+
			"����һ�������ɽ�鱬��ʱ�����˺�ˮ���͵�����̱�������ˮ�������������\n"+
			"ԭ����˴�����$p������ʵ�ˣ�������ʱ��ǡ��۹ǡ���ǡ��߹�һ���۶ϣ���\n"+
			"ѪҲ�粻������������Ϊһ��Ѫ��ģ�������òҲ����ԣ�\n"NOR;

		damage = me->query_temp("qkdny/xu") * (4+random(2));
		ob->receive_damage("qi", damage, me);
		ob->receive_wound("qi", damage/3*2 + random(damage/3), me);
		if (random(2)) {
			p = (ob->query("eff_qi")+ob->query_temp("apply/qi"))*100/(ob->query("max_qi")+ob->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		}
		else {
			p = ob->query("qi")*100/(ob->query("max_qi")+ob->query_temp("apply/qi"));
			msg += COMBAT_D->damage_msg(damage, "����");
			msg += "( $n"+COMBAT_D->status_msg(p)+" )\n";
		}
		message_vision(msg, me, ob);

		me->set("jiali", jiali);
		me->delete_temp("qkdny/xu");
		me->reset_action();
		me->start_busy(2);
		ob->add_busy(2);
		me->start_perform(2, "����־�");
		return 1;
	}

	if(me->query_skill("qiankun-danuoyi", 1) < 200 )
		return notify_fail("���Ǭ����Ų�ƻ�δ�������߲㣬����ʹ�á���־���\n");

	if(me->query_skill_mapped("parry") != "qiankun-danuoyi")
		return notify_fail("��û��ʹ��Ǭ����Ų����Ϊ�н����޷�ʹ�á���־���\n");

	if (!me->query_skill("jiuyang-shengong", 1))
	if( me->query_skill("shenghuo-shengong", 1) < 200 )
		return notify_fail("���ʥ���񹦵ȼ�������\n");
                 
	if((int)me->query("neili") < 300 )
		return notify_fail("��Ŀǰ������������\n");
	if((int)me->query_skill("force") < 300 )
		return notify_fail("����־���Ҫ�����ڹ�����������������󻹲�����\n");
        
	if((int)me->query_temp("qkdny/yi") )
		return notify_fail("������ʩչ���ơ��־��أ�\n");
                
	me->add("neili", -200);
	tell_object(me, BLU"\n�㰵������Ǭ����Ų���ķ��е��߲㹦��ʩչ����־������Է���������������������\n\n"NOR); 
	me->set_temp("qkdny/xu", 1);
	check_fight(me);
	return 1;
}

int check_fight(object me)
{

	if (!me || !me->query_temp("qkdny/xu")) return 0;

	else if(me->is_ghost() || !living(me))
		me->delete_temp("qkdny/xu");
        
	else if(!me->is_fighting()){
		tell_object(me, BLU"\n���˳���ս�����㽫�������������ɢ�˳�ȥ��\n"NOR);
		me->delete_temp("qkdny/xu");
	}

	else if(me->query("neili") <= 100){
		tell_object(me, BLU"\n��ͻȻ���ֱ���������Ѿ�Ҫ�ݽ�����æ�ѻ��������ɢ�˳�ȥ��\n"NOR);
		me->delete_temp("qkdny/xu");
	}

	else if (me->query_skill_mapped("parry") != "qiankun-danuoyi"
	 || me->query_temp("weapon")){
		tell_object(me, BLU"\n������һת���ı���ս�����ѻ��������ɢ�˳�ȥ��\n"NOR);
		me->delete_temp("qkdny/xu");
	}

	else call_out("check_fight", 1, me);
	return 1;
}

int help(object me)
{
        write(HIB"\nǬ����Ų�ơ����־�����"NOR"\n");
        write(@HELP
        Ҫ��  ��ǰ���� 200 ���ϣ�
                Ǭ����Ų�Ƶȼ� 200 ���ϣ�
                �ڹ���Ч�ȼ� 300 ���ϣ�
                �����м�ΪǬ����Ų���ҿ��֡�
HELP
        );
        return 1;
}
