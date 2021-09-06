#include <ansi.h>

int main(object me,string arg)
{
	object obj,weapon;
	int delay,level,flag;
	int cost_jing,cost_money;
	mapping myskill;
	string type;

	if( me->is_busy() ) return notify_fail("����æ���أ�\n");

	if( me->is_fight()) return notify_fail("����æ���أ�\n");

	if( !arg ) return notify_fail("��Ҫ��ʲô��\n");

	if( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( mapp(obj->query("weapon_prop")) && (int)obj->query("imbued") ) {
// �������
		if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
			return notify_fail("�����װ������������ά�ޱ�����\n");

		if( obj->query("weapon_mp/dur") >= obj->query("weapon_mp/max_dur") )
			return notify_fail("����������������������\n");

		if( obj->query("weapon_mp/dur") <= 0  )
			return notify_fail("��������Ѿ��������ˣ��޷�����\n");

		flag = strsrch(obj->query("save_id"),getuid(me))==0;

		level = (int)me->query_skill("duanzao",1);
		switch( (int)obj->query("imbued") ) {
			case 1: if(level<80)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
			case 2: if(level<120)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
			case 3: if(level<160)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
			case 4: if(level<200) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
			case 5: //if(level<300) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
				return notify_fail("��˵�е������������ˡ�\n");
			default:return notify_fail("������Ǵ�˵�еĳ���������\n");               
		}

		myskill = me->query("forging");//����Quest��

		if( !mapp(myskill) || member_array(obj->query("skill_type"),keys(myskill)) == -1 )
			return notify_fail("�����������������˽ⲻ�࣬�޷�����\n");
	
		cost_money = obj->query("value")/2;
	
		if( !flag ) cost_money += cost_money;
		cost_jing = obj->query("weapon_mp/max_dur") - obj->query("weapon_mp/dur");
		if( !flag ) cost_jing +=  cost_jing;
		cost_jing /= 4;
		cost_jing = cost_jing*3/4;
	//	if( me->query("jingli")<cost_jing || me->query("jing")<cost_jing )
	//		return notify_fail("�����ھ���״̬���ѣ����ǵȻ�������ɡ�\n");
	
		switch(MONEY_D->player_pay(me,cost_money))
		{
			case 1:break;
			default:return notify_fail("�������Ǯ�����ˣ�����Ҫ"+MONEY_D->money_str( cost_money )+"������á�\n");
		}
	
		write("�㱾��������"+MONEY_D->money_str(cost_money)+"��\n");
	     
		me->set_temp("last_damage_from", "����߼����������Ļ���");
	//	me->receive_damage("jing", cost_jing );
//		me->receive_damage("jingli", cost_jing );

		message_vision(HIY"$N��ʼ��ϸ��ά��"+obj->query("name")+HIY"����ʱ���������ô��......\n\n"NOR, me);
		delay = 15 + random(30);
		if( wizardp(me) && (int)me->query("env/test") ) delay = 3;
		me->start_busy(delay);
		weapon->use();
		call_out("xiu_weapon_finish",delay*2-1,me,obj);
		return 1;
        
	} else if( mapp(obj->query("armor_prop")) && (int)obj->query("imbued") ) {
// �������
		if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="jian dao" )
			return notify_fail("�����װ�������������޲����ߡ�\n");

		if( obj->query("armor_mp/dur") >= obj->query("armor_mp/max_dur") )
			return notify_fail("�������������������޲���\n");

		if( obj->query("armor_mp/dur") <= 0  )
			return notify_fail("��������Ѿ��������ˣ��޷��޲���\n");

		flag = strsrch(obj->query("save_id"),getuid(me))==0;

		level = (int)me->query_skill("zhizao",1);
		switch( (int)obj->query("imbued") ) {
			case 1: if(level<80)  return notify_fail("���֯�켼�ܲ�����\n"); break;
			case 2: if(level<120)  return notify_fail("���֯�켼�ܲ�����\n"); break;
			case 3: if(level<160)  return notify_fail("���֯�켼�ܲ�����\n"); break;
			case 4: if(level<200) return notify_fail("���֯�켼�ܲ�����\n"); break;
			case 5: //if(level<300) return notify_fail("���֯�켼�ܲ�����\n"); break;
				return notify_fail("��˵�еķ������޲����ˡ�\n");
			default:return notify_fail("������Ǵ�˵�еĳ������ߣ�\n");               
		}

		switch( obj->query("armor_type") ) {
			case "head":type="cap";break;
			case "hands":type="glove";break;
			case "boots":type="boot";break;
			case "waist":type="belt";break;
			case "surcoat":type="mantle";break;
			case "coat":type="coat";break;
			case "armor":type="armor";break;
			default:return notify_fail("�������ַ��ߣ����˽ⲻ�࣬�޷��޲���\n");               
		}

		myskill = me->query("forging");//����Quest��

		if( !mapp(myskill) || member_array(type,keys(myskill)) == -1 )
			return notify_fail("�������ַ��ߣ����˽ⲻ�࣬�޷��޲���\n");

		cost_money = obj->query("value")/2;
	
		if( !flag ) cost_money += cost_money;
		cost_jing = obj->query("armor_mp/max_dur") - obj->query("armor_mp/dur");
		if( !flag ) cost_jing +=  cost_jing;
		cost_jing /= 4;
		cost_jing = cost_jing*3/4;
		if( me->query("jingli")<cost_jing || me->query("jing")<cost_jing )
			return notify_fail("�����ھ���״̬���ѣ����ǵȻ����޲��ɡ�\n");
	
		switch(MONEY_D->player_pay(me,cost_money))
		{
			case 1:break;
			default:return notify_fail("�������Ǯ�����ˣ�����Ҫ"+MONEY_D->money_str( cost_money )+"�޲����á�\n");
		}
	
		write("�㱾���޲�����"+MONEY_D->money_str(cost_money)+"��\n");
	     
		me->set_temp("last_damage_from", "�޲����߰����Ļ���");
		me->receive_damage("jing", cost_jing );
		me->receive_damage("jingli", cost_jing );

		message_vision(HIY"$N��ʼ��ϸ���޲�"+obj->query("name")+HIY"����ʱ�ü������زü�������......\n\n"NOR, me);
		delay = 15 + random(30);
		if( wizardp(me) && (int)me->query("env/test") ) delay = 3;
		me->start_busy(delay);
		weapon->use();
		call_out("xiu_armor_finish",delay*2-1,me,obj);
		return 1;

	} else return notify_fail("��ֻ��ά������������װ����\n");

        return 1;
}

int decvar(object ob,string type,int times,int decmin,int min)
{
        int i,j;
        ///5 10 10
        if( times <= 0 ) return 0;
        i = (int)ob->query(type) * 100;//1000
        if( i == 0 ) return 0;
        decmin *= 100;//1000
        min *= 100;//1000

        j = i / times;
        //200
        if( j < decmin ) j = decmin;
        i = i - j;
        if( i < min ) i = min;

        ob->set(type,i/100);
        return i/100;
}

void xiu_weapon_finish(object me,object obj)
{
        int i;

        if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

        message_vision(HIY"$N��ϸ��ά��"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
        WORKER_D->check_impove(me,"duanzao",me->query_int()/2,2);

        //i = decvar(obj,"weapon_mp/max_dur",9,10,100);
        i = obj->query("weapon_mp/max_dur");
        obj->set("dur",i);
        obj->set("weapon_mp/dur",i);
                
        obj->save_weapon(me);
}

void xiu_armor_finish(object me,object obj)
{
        int i;

        if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

        message_vision(HIY"$N��ϸ���޲�"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
        WORKER_D->check_impove(me,"zhizao",me->query_int()/2,2);

        //i = decvar(obj,"weapon_mp/max_dur",9,10,100);
        i = obj->query("armor_mp/max_dur");
        obj->set("dur",i);
        obj->set("armor_mp/dur",i);
                
        obj->save_weapon(me);
}

int help(object me)
{
	write(@HELP
	��ʽ��repair <���� or ����>
	
	��������Լ��޸������װ����δ�����𺦵�װ������
	���������Ҫװ���������������Ҫװ��������
	��Ҫһ���ļ��ܵȼ�֧�֣�
	���ĵ�ǰ���������ͽ�Ǯ��
HELP
	);
	return 1;
}

/*
        decvar(obj,"weapon_prop/damage",(5+random(7))*2,2,10);
        decvar(obj,"weapon_prop/qi",(5+random(7))*2,10,10);
        decvar(obj,"weapon_prop/jing",(5+random(7))*2,10,10);
        decvar(obj,"weapon_prop/jingli",(5+random(7))*2,10,10);
        decvar(obj,"weapon_prop/neili",(5+random(7))*2,10,10);
        decvar(obj,"weapon_prop/attack",(5+random(7))*2,2,1);
        decvar(obj,"weapon_prop/dodge",(5+random(7))*2,3,1);
        decvar(obj,"weapon_prop/parry",(5+random(7))*2,3,1);

        i = decvar(obj,"weapon_mp/rigidity",5,1,1);
        obj->set("rigidity",i);
        i = decvar(obj,"weapon_mp/sharpness",5,1,1);
        obj->set("sharpness",i);
        i = decvar(obj,"weapon_mp/value",6,10,1);
        obj->set("value",i);
*/
