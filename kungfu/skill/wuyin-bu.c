// xinyuegong.c ������

inherit SKILL;

string *dodge_msg = ({
"ֻ��$nһ�����Ѿ��������߿��⡣\n",
"ȴ��$n���β����������������Ѿ�����$N���档\n",
"��֪$n��ǰһ�Ű�������ת��$p�Ѿ������ˡ�\n",
"$n����һ��һת����$Nһ��ʧȥ��$p����Ӱ��\n"
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

string query_dodge_msg(object weapon)
{        
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        return notify_fail("NPC�书��������ҿ��š�\n");
}