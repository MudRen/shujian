// new anran-xiaohunzhang ��Ȼ������
// by dubei
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N���۸�����ĿԶ���������鸡����ǰ�Ż�������ȫ����������ѧ�и������޲��Ǻϡ�$n��һ���ɣ�������Ϊ$N��������",
        "dodge": -30,
        "force": 400,
        "lvl" : 0,
        "damage_type": "����"
]),
([      "action": "$Nһ�С��ľ���������С�����������ͬʱ�ؿ�����������ٿ�ص���ӭ��$n��˫ȭ",
        "dodge": -15,
        "force": 380,
        "lvl" : 20,
        "damage_type": "����"
]),
([	"action": "$Nһʽ��������졹��̧ͷ���죬��$n��������������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ����£ס$nȫ��",
	"dodge": -10,
	"force": 320,
        "lvl" : 34,
	"damage_type": "ץ��"
]),
([	"action": "$NͻȻ�����붯��һʽ���������С��������䣬˫��ͷ���������ر�������������ʽ��������һ����������",
        "dodge": -15,
	"force": 160,
        "lvl" : 49,
	"damage_type": "����"
]),
([	"action": "$Nһʽ�������ˮ������������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬��������ɱ����ֱ��$n��$l",
	"dodge": -30,
	"force": 230,
        "lvl" : 54,
	"damage_type": "����"
]),
([	"action": "$N��Ӱ��ת������Ȱ��ǰ����˲��˲�ң�һʽ���ǻ��չȡ��Ʒ�����$n��$l",
	"dodge": -10,
	"force": 250,
        "lvl" : 59,
	"damage_type": "ץ��"
]),
([	"action": "$N��̾һ������ɣƣ�����������أ�ȴ��һ�С��������ġ����յ�$nȫ������֮�ʣ�����ֱ�����Ŵ�Ѩ",
	"dodge": 10,
	"force": 100,
        "lvl" : 79,
	"damage_type": "����"
]),
([	"action": "$N��Ŀ��Ȼ����ֱ֫ͦ���������ۣ����ơ���ʬ���⡹�㣬���۽��ȣ���նֱ��$n��$l",
	"dodge": -25,
	"force": 500,
        "lvl" : 90,
	"damage_type": "����"
]),
([	"action": "$Nһʽ��ӹ�����š������ִ��أ�һ�߻��ײ�ֹ������ȴҲ��ٿ�����Ƶ������������㱩��$n�ĺ���",
	"dodge": -20,
	"force": 430,
        "lvl" : 100,
	"damage_type": "����"
]),
([	"action": "$NͻȻͷ�½��ϣ��������ӣ������������У��ִ����У������ֹ���˫�����δ����˫�ֻ������������$n������",
	"dodge": -10,
	"force": 360,
        "lvl" : 120,
	"damage_type": "����"
]),
([	"action": "$N��Ȼ��Ц��ֹ�����ֵ߿�������Ц���䣬$n���������䶯�����Գ������$N��һ�ȹ���$n��$l",
	"dodge": -20,
	"force": 400,
        "lvl" : 140,
	"damage_type": "����"
]),
([	"action": "ȴ��$N����������˫�ֺ�ʮ��Ĭ�̾��ģ��������Ƴ��ְ�������У�ƾ������$n,�������ˣ��޷�Ӳ��",
	"dodge": 20,
	"force": 450,
        "lvl" : 160,
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ַ�����ϰ��Ȼ�����ơ�\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 120)
		return notify_fail("��Ů�ľ����򲻹����޷���ϰ��Ȼ�����ơ���\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�ѧ��Ȼ�����ơ�\n");
	if ((int)me->query_str() < 30 )
		return notify_fail("��û����׳�ı����޷���Ȼ�����ơ�\n");
	if ((int)me->query_con() < 30 )
		return notify_fail("��û���ۺ�������޷���Ȼ�����ơ�\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("����Ṧ̫��޷�����Ȼ�����ơ�\n");

        return 1;
      }
string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    int i, j, level;
    object target; 
            
    level   = (int) me->query_skill("xiaohun-zhang",1);
    for(i = sizeof(action); i > 0; i--) {
        if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
            target = offensive_target(me);    
            if (me->query_temp("anran")
               && me->query("jiali") >= 50 ) {                
                    return ([  
                    "action" : HIY+action[j]["action"]+NOR,
                    "force" : action[j]["force"]+30,
                    "dodge":action[j]["dodge"]+5,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"��Ȼ���Ʒ�":"��Ȼ������",
                    "damage_type" : random(2)?"����":"����",
                    ]);
               }
            if (level >= 130 && random(6) > 4
               && me->query("jiali") >= 50 ) {                
                    return ([  
                    "action" : action[j]["action"],
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"�Ʒ�":"��Ȼ����",
                    "damage_type" : "����",
                    ]);
               }
            return action[j];
        }
    }
} 

 

int practice_skill(object me)
{
          int lvl = (int)me->query_skill("xiaohun-zhang", 1);
        int i = sizeof(action);

        while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("jingli") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ȼ�����ơ�\n");
 

	me->receive_damage("jingli", 50);
	me->add("neili", -20);
        if(me->query("marry"))
        me->add("neili", -10);
	return 1;
}


string perform_action_file(string action)
{
        return __DIR__"xiaohun-zhang/" + action;
}
