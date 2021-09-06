// hengshan-jianfa.c
//  by hongba
#include <ansi.h>

inherit SKILL;



int tydamage = (this_player()->query("tydamage/unarmed")?this_player()->query("tydamage/unarmed"):this_player()->query_skill("hengshan-sword"))*5;

mapping *action = ({
([
        "action":  "$N����$w����ָ����ͻȻ���ڿ���һ������������֮�������ű���
��������������$w���Ⱪ������$n��$l��ȥ",
        "dodge":    50,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([
        "action":  "$N����$w������ȣ���Ȼ���Ƶ���$n����$n��æת������ֻ��
����������",
        "dodge":   -70,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([      "name":    "�ٱ�ǧ��",
        "action":  "$N����$w���ⶸ�������е�$w���͵ط��̣�ֱָ$n�ؿڡ���һ��
���п켫������������ã����ǡ�"+HIW+"�ٱ�ǧ�ú�ɽ����ʮ��ʽ��"+NOR+"�еľ���",
        "dodge":   -40,
        "damage":   tydamage,
        "damage_type":  "����"
]),
([      "name":    "Ȫ��ܽ��",
        "action":  "$N�����Է�������·������$wˢ��һ����"+HIC+"Ȫ��ܽ��"+NOR+"������$nС
����ȥ",
        "dodge":   -40,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([      "name":    "�����ϸ�",
        "action":  "$N�����Է�������·������$wˢ��һ����"+HIM+"�����ϸ�"+NOR+"������$n��
ͷ��ȥ",
        "dodge":   -40,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([      "name":    "ʯ������",
        "action":  "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ�С�"+HIW+"ʯ������"+NOR+"����
��$n$l��ȥ",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([      "name":    "��������",
        "action":  "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������
һ�С�"+HIY+"��������"+NOR+"����ָ��$n$l",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "����"
]),
([      "name":    "���ף��",
        "action" : "$N����Ծ�𣬡�"+HIC+"���ף��"+NOR+"������$w����һ�������Ӱ��������$n��
$l",
        "dodge":   60,
        "damage":  tydamage,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_neili") < 50 )
        return notify_fail("�������������û�а취����ɽ������\n");

    if( !(ob = me->query_temp("weapon"))
    ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("���������һ�ѽ�������������\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}


int practice_skill(object me)
{
    if( (int)me->query("qi") < 30
    ||      (int)me->query("neili") < 5 )
        return notify_fail("�����������������û�а취��ϰ��ɽ������\n");
 me->receive_damage("qi", 30);        // �����ǲ����е���å�ˣ�
    me->add("neili", -5);
    write("�㰴����ѧ����һ���ɽ������\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i, j, level;

        level = (int) me->query_skill("hengshan-jianfa",1);
        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                        j = NewRandom(i, 20, level/5);
                        return ([
                       "action" : YEL+action[j]["action"]+NOR,
                                "force" : 200 + random(350),
                                "dodge" : random(25)-5,
                                "parry": 20-random(10),
                                "damage" : 100 + random(120),
                                "damage_type" : action[j]["damage_type"],
                                "lvl": action[j]["lvl"],
                        ]);
                }
        }
}

string perform_action_file(string action)
{
        return __DIR__"hengshan-jianfa/" + action;
}

