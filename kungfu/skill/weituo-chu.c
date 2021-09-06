inherit SKILL;
 
mapping *action = ({
([
	"action":"$NԾ�ڰ�գ�һ�С��ɺ�չ������ɽ��������$w�ѻ���������Ӱ����$n�ۻ����ң���֪���룬��������",
	"lvl" : 0,
	"skill_name" : "�ɺ�չ������ɽ",
	"damage_type":"����"
]),
([
	"action":"$Nͦ$w��$n����ʽ��ס��˳��һ�С������λ����ɹ�����$w�������ҷɿ������������ߣ���$nѹ������",
	"lvl" : 30,
	"skill_name" : "�����λ����ɹ�",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С���¹̤�����ɲݡ�����ϥ��������$w����$n���̣�ȴδ���������ϣ��͵�һ�ᣬ��$n���ظ����ȥ",
	"lvl" : 60,
	"skill_name" : "��¹̤�����ɲ�",
	"damage_type":"����"
]),
([
	"action":"$NͻȻ�����ڵأ�$n��㵼䣬һ�С�����ԾˮǱ��ء�������$n�����´ܹ���������ͷ��$w����ɨ��$n��$l",
	"lvl" : 80,
	"skill_name" : "����ԾˮǱ���",
	"damage_type":"����"
]),
([
	"action":"$Nһ�С���Գ�׹�����������������磬����$n�ɿ챼�ܣ�����$wһ�п���һ�У�ɲ�Ǽ���$n�����ʮ����",
	"lvl" : 100,
	"skill_name" : "��Գ�׹�������",
	"damage_type":"����"
]),
([
	"action":"$N��̤����ǰ������˫�ۣ�����$w�󿪴��أ�����������һ�С���ӥ����ɨǬ����ɨ��$n������",
	"lvl" : 120,
	"skill_name" : "��ӥ����ɨǬ��",
	"damage_type":"����"
]),
([
	"action":"$N���һ����һ�С�������ˮ�����桹��$w���ַɳ������ž�������$n��$l��δ����أ������ְ�$w��������",
	"lvl" : 130,
	"skill_name" : "������ˮ������",
	"damage_type":"����"
]),
([
	"action":"$N˫ĿԲ��������Ĭ�����ԣ�һ�С�������ƺ���������$w����ǧ����������ֻ�����$n�ĵ�ͷ����",
	"lvl" : 150,
	"skill_name" : "������ƺ�����",
	"damage_type":"����"
]),
});

int valid_enable(string usage)
{
	if ( this_player()->query("family/family_name") == "������")
		return  usage == "club" || usage =="parry"; 
}

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	object weapon;
	int flag = 0;

	if (!objectp(weapon = me->query_temp("weapon"))
	 || (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!fam || fam["family_name"] != "������" )
		return notify_fail("Τ����ֻ�ܴ�������ѧ����\n");

	if ( me->query("family/generation") >= 37)
		return notify_fail("�����ڵı��ݲ����������ָ߼��书Τ���ơ�\n");

	//return notify_fail("�����������ϵļ��Ÿߵܣ��������ϰ���ִ���������Ϊ�ĸ����书��\n" );
	if( me->query("passdu"))		
		flag = 1;
	//return notify_fail("���Ѿ��������÷�����ʦ�ļ��Ÿߵܣ��������ϰ���ִ���������Ϊ�ĸ����书��\n" );
	if ( me->query("pass_xin"))		
		flag = 1;

	if ( me->query("max_neili") < 1500)
		return notify_fail("�������������\n");

	if ( me->query_skill("yijin-jing", 1) < 160)
		return notify_fail("����׽�ڹ����̫ǳ��\n");

	if ( me->query_skill("zui-gun",1) <=120)
		return notify_fail("����������㣬��������Τ���ơ�\n");

	if ( me->query_skill("ranmu-daofa",1) || (int)me->query_skill("riyue-bian",1))
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ������������\n"); 	
	
	if(flag && random(100)==50 ){
		mapping learned = me->query_learned();
		flag = random(3);
		if(flag) tell_object(me,"����з�ѧ��ȴ���ò���ϰɱ��֮���������Լ��������������еķ�ѧ��ʦԽ��ԽԶ��\n");
		if(learned["buddhism"]>=flag) learned["buddhism"] -= flag;
		else {
			int level = me->query_skill("buddhism",1);			
			me->set_skill("buddhism",level-1);
			learned["buddhism"] = level*level+learned["buddhism"]-flag;
		}
	}
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level, lvl, j;
	object target;
	mapping pre;
	string *skill, a, b;
         
	level   = (int) me->query_skill("weituo-chu",1);
	lvl = (int)me->query_skill("longzhua-gong", 1);

	if ( level >= 200
	 && lvl >= 200
	 && random(level) > lvl / 2
	 && objectp(target = me->select_opponent())
	 && objectp(weapon = me->query_temp("weapon"))
	 && me->query_skill_mapped("claw") == "longzhua-gong" 
	 && me->query_skill_prepared("claw") == "longzhua-gong" 
	 && me->query("neili") > 300 
	 && me->query("jingli") > 100 ) {
		target = offensive_target(me);
		pre = me->query_skill_prepare();
		skill = keys(pre);     
		for (i=0; i<sizeof(skill); i++){
			if(skill[i]=="claw") continue; 
			a = skill[i];
			b = pre[skill[i]];
			me->prepare_skill(skill[i]);
		}
		weapon->unequip();
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
		weapon->wield();
		me->prepare_skill(a,b);
		me->add("neili", -25);
		me->add("jingli", -10);
	}
	for(i = sizeof(action); i > 0; i--) {
		if(level > action[i-1]["lvl"]) {
			j = NewRandom(i, 20, level/5);
			return ([
				"action": action[j]["action"],
				"damage_type": action[j]["damage_type"],
				"lvl": action[j]["lvl"],
				"force": 200 + random(350),
				"dodge": random(30)-10,
				"damage": 80 + random(140),
				"parry": random(20),
			]);
		}
	}
}
 
int practice_skill(object me)
{
	if ( me->query("jingli") < 50)
		return notify_fail("�������������Τ���ơ�\n");

	if ( me->query("neili") < 20)
		return notify_fail("�������������Τ���ơ�\n"); 

	me->receive_damage("jingli", 40);
	me->add("neili",-15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"weituo-chu/" + action;
}
