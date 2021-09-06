// qudu.c �������޼�����
// Write by cht 1999/9/
// rewrite by olives@SJ 4/27/2001
// ��������µ�����д
// ��������
// �Ժ�ֻҪ����query_conditions_by_type("poison") query�����Ķ������Խ���
// ����������б�����Ķ��þ綾������
// By Spiderii ��Ȼ�б���Ķ�������qudu.Ϊʲôxx_poison�����ԣ�
#include <ansi.h>

mapping get_poison(string poison);
mixed get_my_poison(object me);
string get_msg(object me,object target,mapping poison);

string exert_name(){ return HIG"�����޼���"NOR; }
//�����б�
mapping *poi_list = ({
([
"id":		"snake_poison",	// ���ж���E������
"name":		"�߶�",		// ���ж�����������
"col":		""BLU"",	// �ж���������ɫ
"con":		"տ��֮��",	// �ж�������״̬
]), 
([
"id":		"xx_poison",
"name":		"�����ƶ�",
"col":		""BLU"",
"con":		"տ��֮��",
]),
([
"id":		"xuanmin_poison",
"name":		"��ڤ�ƶ�",
"col":		""HIW"",
"con":		"˪��֮��",
]),
([
"id":		"dsy_poison",
"name": 	"���ڴ���ӡ�ƶ�",
"col":		""CYN"",
"con":		"����",
]),
([
"id":		"fs_poison",
"name":		"��ʬ��",
"col":		""HIG"",
"con":		"����",
]),
([
"id":		"huagu_poison",
"name":		"�������ƾ綾",
"col":		""BLU"",
"con":		"տ��֮��",
]),
([
"id":		"man_poison",
"name":		"�����ܻ���",
"col":		""HIB"",
"con":		"����",
]),
([
"id":		"qinghua_poison",
"name":		"�黨��",
"col":		""MAG"",
"con":		"����",
]),
([
"id":		"qishang_poison",
"name":		"����ȭ��",
"col":		""HIR"",
"con":		"����֮��",
]),
([
"id":		"qzhu_poison",
"name":		"ǧ�����ֶ�",
"col":		""HIR"",
"con":		"����֮��",
]),
([
"id":		"sl_poison",
"name":		"������",
"col":		""BLU"",
"con":		"տ��֮��",
]),
([
"id":		"sy_poison",
"name":		"����ӡ�ƶ�",
"col":		""HIR"",
"con":		"����֮��",
]),
([
"id":		"warm_poison",
"name":		"�ȶ�",
"col":		""RED"",
"con":		"���֮��",
]),
([
"id":		"hot_poison",
"name":		"��",
"col":		""HIR"",
"con":		"����֮��",
]),
([
"id":		"cold_poison",
"name":		"����",
"col":		""HIC"",
"con":		"����֮��",
]),
([
"id":		"bing_poison",
"name":		"�������붾",
"col":		""HIB"",
"con":		"տ��֮��",
]),
([
"id":		"bt_poison",
"name":		"���߶�",
"col":		""YEL"",
"con":		"����֮��",
]),
([
"id":		"hb_poison",
"name":		"�������ƶ�",
"col":		""HIB"",
"con":		"տ��֮��",
]),
});

mapping get_poison(string poison)
{
	int i;
	for(i=0;i<sizeof(poi_list);i++) {
		if(poi_list[i]["id"]==poison)
			return poi_list[i];
	}
	return ([
		"id":		poison,
		"name":		"�綾",
		"col":		""GRN"",
		"con":		"����",
	]);
}

mixed get_my_poison(object me)
{
	mapping conditions,my_poison;
 	string *names,name;
 	int lvl=0;
	int i;
	if(!objectp(me))
		return 0;
	if(mapp(conditions = me->query_conditions_by_type("poison"))){
		names = keys(conditions);
		for(i=0;i<sizeof(conditions);i++){
			if(conditions[names[i]]>lvl)
				lvl = conditions[names[i]];
			name  = names[i];
			break;
		}
		if(intp(lvl) 
		&& stringp(name)
		&& lvl
		&& name!="")/*�ж�*/{
			my_poison = get_poison(name);
			my_poison["lvl"] = lvl;
			return my_poison;
		}
	}
	return 0;//����0������û�ҵ�����
}

//��ʾ���·���msg
//���̫���ˣ��ҵ��г����ġ�
string get_msg(object me,object target,mapping poison)
{		
	object myarmor,urarmor;
	string msg;
	myarmor = me->query_temp("armor/cloth");
	urarmor = target->query_temp("armor/cloth");

	if (objectp(myarmor) && objectp(urarmor)) {
		msg = "$N��ָ���죬����$n����"+ chinese_number((poison["lvl"]/100)+3) +"����Ѩ��$pѨ�����㣬��ʱ���ٲ���������" +poison["col"] + poison["con"] + NOR"ȴ������Ũ��\n"
			"$N���³�ȥ$n����" + urarmor->name() + "���Լ�Ҳ�⿪" + myarmor->name() + "�����ź�$p�ı���������\n"+
			"��ʼ��"HIY"�������޼�����"NOR"��ȡ$n���ϵ�"+poison["col"] + poison["name"] + NOR"��\n\n";
			myarmor->unequip();
			urarmor->unequip();
	}
	else if( objectp(myarmor) && !objectp(urarmor)){
		msg = "$N��ָ���죬����$n����"+ chinese_number((poison["lvl"]/100)+3) +"����Ѩ��$pѨ�����㣬��ʱ���ٲ���������" +poison["col"] + poison["con"] + NOR"ȴ������Ũ��\n"
			"$N���½⿪" + myarmor->name() + "�����ź�$p�ı���������\n"+
			"��ʼ��"HIY"�������޼�����"NOR"��ȡ$n���ϵ�"+poison["col"] + poison["name"] + NOR"��\n\n";
			myarmor->unequip();
	}

	else if( !objectp(myarmor) && objectp(urarmor)){
		urarmor->unequip();
		msg = "$N��ָ���죬����$n����"+ chinese_number((poison["lvl"]/100)+3) +"����Ѩ��$pѨ�����㣬��ʱ���ٲ���������" +poison["col"] + poison["con"] + NOR"ȴ������\n"
		"Ũ��$N���³�ȥ$n����" + urarmor->name() + "�����ź�$p�ı���������\n"+
		"��ʼ��"HIY"�������޼�����"NOR"��ȡ$n���ϵ�\n"+poison["col"] + poison["name"] + NOR"��\n\n";
	}
	else
		msg = "$N��ָ���죬����$n����"+ chinese_number((poison["lvl"]/100)+3) +"����Ѩ��$pѨ�����㣬��ʱ���ٲ���������" +poison["col"] + poison["con"] + NOR"ȴ������Ũ��\n"
			"$N�������ź�$p�ı���������\n"+
			"��ʼ��"HIY"�������޼�����"NOR"��ȡ$n���ϵ�"+poison["col"] + poison["name"] + NOR"��\n\n";

	return msg;
}

int exert(object me, object target)
{
	string msg;//, *No_Save_Id;
	int i, yyzq_lvl, neili_cost, yyzq_reg;
	object *inv,where;
	mapping poison;

	where=environment(me);
	yyzq_lvl = (int)me->query_skill("yinyun-ziqi", 1);

	if ( !present(target,where) )
		return notify_fail("��Ҫ��˭�ƶ���\n");
	
	if( me->is_fighting() )
		return notify_fail("���޷���ս�����˹��ƶ���\n");

	if ( !userp(me))
		return notify_fail("");

	if((int)me->query_skill("yinyun-ziqi", 1) < 160 )
		return notify_fail("��ġ������������𲻹����������á������޼��������ˡ�\n");

	if((int)me->query_skill("taoism", 1) < 160 )
		return notify_fail("��ԡ���ѧ�ķ���������������á������޼��������ˡ�\n");

	if( (int)me->query("max_neili", 1) < 3000 )
		return notify_fail("���������Ϊ̫�������������á������޼��������ˡ�\n"); 

	if((int)me->query_skill("medicine", 1) < 80 )
			return notify_fail("�㻹�ö�ѧ���ľҩ��\n");

	me->start_exert(1,"�������޼�����");

	if(!target || target == me ){
		poison = get_my_poison(me);
		if(!mapp(poison))
			return notify_fail("�㲢û���ж���\n");

	//	if ( poison["id"] == "xx_poison" || poison["id"] == "fs_poison")
	//		return notify_fail("������֮����Ϊ���죬�����޷��ƶ���\n");

		neili_cost = poison["lvl"]*5;
		yyzq_reg = 160 + poison["lvl"]/2;

		if( (int)me->query("neili") < neili_cost )
			return notify_fail("�����ڵ���������"NOR"��\n");
		
		if( yyzq_lvl < yyzq_reg )
			return notify_fail("���"MAG"����������"NOR"��Ϊ�����ܻ���"+poison["col"] + poison["name"] + NOR "��\n");

		me->set("jiali", 0);
		message_vision("$N����һ�ԣ�����������ͨ�����أ��ĵ������е�"MAG"����������"NOR"�������ڵ�"+poison["col"] + poison["name"] + NOR"һ˿˿�Ļ�����\n", me);
		me->start_busy(10);
		call_out("huadu", poison["lvl"]/30+2, me,  poison,yyzq_lvl, neili_cost);
		return 1;
	}
	else {
		if( !target->is_character() )
			  return notify_fail("����Ǹ���������ƶ���\n");
/*
		if( file_size("/log/skills/no_lifesave") > 0 ){
			No_Save_Id = explode(read_file("/log/skills/no_lifesave"), "\n");
			if( sizeof(No_Save_Id) > 0 && member_array(getuid(target), No_Save_Id) != -1 )
				return notify_fail("����Ϊ�䵱��У���Ҫ����ʦ�ţ���\n");
		}
*/
		if( me->query("gender") == "����" ){
			if(target->query("gender")=="Ů��"){
				inv = all_inventory(environment(me));
				for( i=0; i < sizeof(inv); i++ ) 
					if((string)inv[i]->query("race") == "����"
					&& inv[i] != me 
					&& inv[i] != target)
						return notify_fail("��Ŀ��֮���ѹ����ѣ���Ҳ�����˼����룿\n");
			}
		}
		else if( me->query("gender") == "Ů��" ) {
			if(target->query("gender")=="Ů��"
			|| target->is_spouse_of(me)) {
				inv = all_inventory(environment(me));
				for( i=0; i < sizeof(inv); i++ ) 
					if((string)inv[i]->query("race") == "����"
					&& inv[i] != me 
					&& (inv[i]->query("gender")!="Ů��"
					&&!me->is_spouse_of(inv[i])))
						return notify_fail("��Ϊ�䵱���ӣ�����Ŀ��֮���ѹ����ѣ���ֱ�����˷绯��\n");
			}
			else
				return notify_fail("��Ů���ܲ��ף��䵱�������߽������Ůɫ�������ɼ��Ͻ���\n");
		}
		else return notify_fail("�����޸�����֮�ˣ����ʹ�á������޼�������\n");
				
		poison=get_my_poison(me);
		if(mapp(poison))
		       return notify_fail("��������"+poison["col"] + poison["name"] + NOR"���ֻ�ɢ��" + target->name() + "��\n");

		poison = get_my_poison(target);

		if(!mapp(poison))
			return notify_fail(target->name() + "��δ�ж���\n");

	//	if ( poison["id"] == "xx_poison" || poison["id"] == "fs_poison")
	//		return notify_fail(target->name()+"����֮����Ϊ���죬�������޷�Ϊ���ƶ���\n");

		if( target->is_fighting() )
			return notify_fail(target->name() + "����ս���У����޷�Ϊ���ƶ���\n");

		if( target->is_busy() )
			return notify_fail(target->name() + "��æ���أ����޷�Ϊ���ƶ���\n");

		neili_cost = poison["lvl"]*5;
		yyzq_reg = 160 + poison["lvl"]/2;

		if( yyzq_lvl < yyzq_reg )
			return notify_fail("���"HIY"�������޼�����"NOR"��Ϊ������Ϊ"
			 + target->name() + "��ȡ"+ poison["col"] + poison["name"] + NOR"��\n");

		me->set("jiali", 0);
		
		msg = get_msg(me,target,poison);
		message_vision(msg, me, target);

		me->start_busy(poison["lvl"]/30);
		target->start_busy(poison["lvl"]/30);

		if( (int)me->query("neili") < neili_cost )
			call_out("selfhurt", 1, me, target, neili_cost);
		else
			call_out("xidu", poison["lvl"]/30+2, me, target, poison,yyzq_lvl, neili_cost);

		return 1;
	}
	return 1;
}

int huadu(object me, mapping poison, int yyzq_lvl, int neili_cost)
{
	int poi_amount, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) )
		return 0;
	if(wizardp(me)) {
		tell_object(me, poison["id"]);
		tell_object(me, "\n");
	}
	poi_amount = (int)me->query_condition(poison["id"]);
	//����Ϊʲô����poison["lvl"]�أ���Ϊ��call_out��ʱ�򣬿����Ѿ�������������
	//����poison["lvl"]��׼�ģ����ܴ�
	cure_amount = yyzq_lvl;
	cure = yyzq_lvl/10;

	me->add("neili", -neili_cost);

	if( poi_amount > cure_amount ){
		tell_object(me, "������"+poison["col"] + poison["name"] + NOR"̫������޷�������\n");
		return 0;
	}

	tell_object(me, "\n�㽫����ѭ��һ�ܣ���������¶����������������������ƣ��������ڡ�\n");

	if( poi_amount <= cure )
		me->clear_condition(poison["id"]);
	else
		me->add_condition(poison["id"], -cure);
	return 1;
}

int xidu(object me, object target, mapping poison, int yyzq_lvl, int neili_cost)
{
	int  ur_poi, cure_amount, cure;

	if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
		return 0;
	//��ȥ�ⶾ���ˣ�����Ӧ��û�ж�
	//my_poi = (int)me->query_condition(poison["id"]);
	ur_poi = (int)target->query_condition(poison["id"]);

	cure_amount = yyzq_lvl;
	cure = yyzq_lvl/10;

	me->add("neili", -neili_cost);

	if( ur_poi > cure_amount || !interactive(target) || !interactive(me)) {
		tell_object(me, target->name() + "���ϵ����е�"+poison["col"] + poison["name"] + NOR"̫���������ڻ�����������\n");
		return 0;
	}    
	else {
		message_vision("\n����ԼĪ���ʱ����ֻ��$N���������ֳ�"+poison["col"] + poison["con"] + NOR"����ָ΢΢������\n", me);
		if( ur_poi <= cure ) {
			me->add_condition(poison["id"], ur_poi);
			target->clear_condition(poison["id"]);
		}
		else {
			me->add_condition(poison["id"], cure);
			target->add_condition(poison["id"], -cure);
		}
	}
	return 1;
}

int selfhurt(object me, object target, int neili_cost)
{
	if( !me || me->is_ghost() || !living(me) || !target || target->is_ghost() )
		return 0;

	message_vision(HIW"$N��$nһ���뻳����ʱ���һ����ȫ������\n"NOR, me, target);

	if(me->query("neili") < neili_cost/2) {
		me->set("neili", 0);
		me->receive_damage("qi", (int)me->query("qi")+1, "������������");
		return 1;
	}
	else {
		me->add("neili", -(neili_cost/2));
		me->receive_damage("qi", neili_cost, "������������");
		me->receive_wound("qi", neili_cost/5, "������������");
		return 1;
	}
}

int help(object me)
{
        write(WHT"\n�������������޼�������"NOR"\n");
        write(@HELP
        �������Ը��඾Ҳ������������������ɱƳ������ڵĶ��أ�������е���
        �������ô����޼������Լ������ӻ��߱�������������ڵĸ��ֶ��ء��������
        �ж����Ҳ���췥���ˡ�

        Ҫ���������ȼ� 160 ���ϣ�
              ��ѧ�ķ��ȼ� 160 ���ϣ�
              ��������ȼ� 80 ���ϣ�
              ������� 3000 ���ϡ�

HELP
        );
        return 1;
}
