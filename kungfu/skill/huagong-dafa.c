// huagong-dafa.c ������
// By Spiderii ����autoЧ����
// �ٴ��޸ģ�����ۼӵ�����
//�����ҡ���555..�޸�Ϊyun power����autoЧ����
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) {	  if (this_player()->query("family/family_name")=="������"|| this_player()->query("cw_mp/������") ) return usage == "force"; }
#include "/kungfu/skill/force.h"
#include <combat_msg.h>

int valid_learn(object me)
{
		mapping fam  = me->query("family");
	int j, t, lvl, shen, mforce;

	lvl = (int)me->query_skill("huagong-dafa", 1);
	shen = (int)me->query("shen");
	mforce = me->query_skill("force", 1);

	if ((!fam || fam["family_name"] != "������" )&& !me->query("cw_mp/������") )
			 	return notify_fail("�㲢�������ɵ��ӣ����ϰ���˻����󷨡�\n");
	t = 1;

	for ( j = 1; j < lvl / 10; j++) t *= 2;
	if ( t > 5000 ) t = 5000;

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("�����˱����ķ�����ѧ�����󷨻��߻���ħ��\n");


	if ( mforce < 10)
		return notify_fail("��Ļ����ڹ�������, ѧ���˻����󷨡�\n");

	if ( lvl > mforce + 10 && lvl >= 200 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");
/*
	if ( (lvl > 10 && lvl < 100 && shen > -(t * 200))
	|| ( lvl >=100 && shen > -50000))
		return notify_fail("���а��̫���ˡ�\n");
*/
        return valid_public(me);
}

int practice_skill(object me)
{
	if( me->query_skill("huagong-dafa", 1) >= 200 ){
		if( me->query("potential", 1) > 5 && me->query("neili", 1) > 200) {
			me->improve_skill("huagong-dafa", me->query_int());
			me->add("neili", -100);
			me->add("potential", -1*(1+random(3)));
			return 1;
		}
		return notify_fail("�����ڵ���Ϊ��������߻������ˡ�\n");
	}
	return notify_fail("�����ڵĻ�������Ϊֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"huagong-dafa/" + func;
}

void skill_improved(object me)
{
	int skill, poison;
	skill = me->query_skill("huagong-dafa", 1);
	poison = me->query_skill("poison", 1);

	if(skill >= 100 && !me->query("hgdf") && poison > 100){
		tell_object(me, HIY"ڤڤ����о������ڵĻ����󷨺Ͷ����໥��ã�ʹ���������Ϊ������ߣ�\n"NOR);
		me->add("max_neili", 50);
		me->set("hgdf", 1);
	}
	if(skill >= 150 && me->query("hgdf")==1 && poison > 150){
		tell_object(me, HIY"ڤڤ����о������ڵĻ����󷨺Ͷ����໥��ã�ʹ��ľ�����Ϊ������ߣ�\n"NOR);
		me->add("max_jingli", 50);
		me->add("eff_jingli", 50);
		me->set("hgdf", 2);
	}
	if(skill >= 200 && me->query("hgdf")==2 && poison > 200){
		tell_object(me, HIY"ڤڤ����о����ڵĻ����󷨺Ͷ����໥��ã�ʹ����书��Ϊ������ߣ�\n"NOR);
		me->add("combat_exp", 5000);
		me->set("hgdf", 3);
	}
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : BLU + me->name()+"�����ڵ���������Ϣ�����屻һ�����̻�����" NOR,
		"start_my_msg" : "�����˵�������ڶ��������Ƴ����������������㻺��Ʈ������о����ھ���ʼ������ǿ�ˡ�\n",
		"start_other_msg" : me->name()+"��ϥ�����˹������彥����һ����������Χ��\n",
		"halt_msg" : "$N˫��һ�����������һ�����⣬��������һЦ��վ��������\n",
		"end_my_msg" : "��о�����ԽתԽ�죬�Ϳ�Ҫ������Ŀ����ˣ�����æ�ջض��غ���Ϣ����Цһ��վ��������\n",
		"end_other_msg" : me->name()+"����һ����Ц������һ�����̣�վ���������ӵ�ɨ���ڳ�����һ�ۡ�\n"
	]);
}
mixed hit_ob(object me, object ob, int damage)
{
	
	int busy,p;
	string msg;

	if( me->query_temp("hgdf_power")) {
	 if( ob->busy() && random(4)==1  )
	 {
		
	 	
	 	message_vision(BLU"$N���𻯹��󷨣�������Ȼ�����˱�֮������\n"NOR,me);
	 	me->set_temp("action_flag",1);
	 	me->add_temp("apply/attack",me->query_temp("combat_time")*10);
	 	me->add_temp("apply/damage",me->query_temp("combat_time")*10);
	 	me->add_temp("apply/claw",me->query_temp("combat_time")*10);
	 	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), random(2)?1:3);
	 	me->add_temp("apply/attack",-me->query_temp("combat_time")*10);
	 	me->add_temp("apply/damage",-me->query_temp("combat_time")*10);
	 	me->add_temp("apply/claw",-me->query_temp("combat_time")*10);
		me->delete_temp("action_flag");
	 	return;
	 }
	 else
		 if( !ob->busy()
	 && me->query_str()*10/2+random(me->query_str()*10/2) > random(ob->query_con()*10) 
	 && random(me->query("neili"))>1000
	 && me->query("jingli")>1000
	 && random(5)==1
	 ){
		
	 	msg = BLU"$N��ʽһ�䣬̧�ֱ���ס��$n���ؿ�ҪѨ��\n$n������������������ȻԴԴ���ϵı����˹�ȥ��һʱ�������á�\n"NOR;
	 	busy = me->query_str()-ob->query_con();
	 	if(busy<=0) busy = 1+random(2);
	 	if(busy>5) busy=5;
	 	ob->start_busy(busy);
	 	ob->add("neili", -busy*100);
              me->add("neili",busy*100); //ϣ���������bug,�Ͼ���auto
	 	return msg;
	 }
	 else 
		 if(random(me->query("neili"))>1500
	 && me->query("jingli")>500
	 && me->query("jiali") > 30
	 && !me->query_temp("weapon")
	 && random(6)==1 
	 ){
		
	 	msg = BLU"$N˫�ֻӶ��䣬�ȷ����$nһʱ��֮��������$N���ؿ����ػ���һ�ơ�\n"NOR;
	 	damage = (me->query_str()*10+me->query_skill("force")-ob->query_skill("parry",1))*5;
	 	if(damage<=0) damage = 1;
	 	if(damage>1000) damage = 1000;
	 	
	 	ob->receive_wound("qi", damage - ob->query_temp("apply/armor"), me);
		p=(int)ob->query("qi")*100 / (int)ob->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	 	return msg;
	 }
}
}
