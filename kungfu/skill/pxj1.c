// pixie-jian.c ��а����
// by snowman 22/11/98
// By Spiderii@ty ����
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include <combat_msg.h>

string *dodge_msg = ({
"ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
"$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
"$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
"$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
"$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
"$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨣�\n",
"$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
});

string *feiyue_msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�����Ϯ��",
"$N��һ������һ������һ������һ������$n��������������������һת������$n",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������",
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ",
"$N��Ȼ����Ϊ�����ó�����������Ӱ���ٻ���$n������$w�û����������н���$n��$l",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"
});

string *msg = ({
"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
"�����$N�����ϣ��ڵ�$n�����̳�һ��������˲��Ծ��ԭ��",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$NͻȻ���з�һ�䣬һ�С�����Ū�ѡ���$w�����������ʽ������ס�$n����֮�з������",
"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ��һ�С��������𡹣�����$wֱָ$n��$l",
"$N����Ʈ����������ȣ�ת�˼�ת��һ�С��������������Ʋ���$n�����",
"$Nһ����Ц��һ�С����Ǹ��¡�������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
"$N�ȵ������ã������㼴�γ�$w��һ�С����ഩ���������ִ̳�������ת����ȥ",
"$N��س嵽$n��ǰ��һ�С���ظ��Ŀ��������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
"$N����Ծ��$ņ��һ����������$Nһ�С����Ƿɶ项������ֱ����£�����$w����$n��$l",
"$Nһ�С�Ⱥа���ס�����֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}
mapping query_action(object me, object weapon)
{
	int i, j, level, damage;

	level = me->query_skill("pixie-jian", 1);
	i = random(me->query_skill("force"))+50;
	if( i<100 ) i = 100;
	j = random(40)-5;
	damage = (random(6)+1)*35;
	if( damage < 50 ) damage =50;

		if( level > 400 ) {
			return ([
				"action": HIM+replace_string(replace_string(feiyue_msg[random(sizeof(feiyue_msg))], "$w", "$w"), "$w", "$w"HIM)+NOR,
				"damage": 200 + random(150),
				"damage_type": "����",
				"dodge":  random(100),
				"parry":  random(100),
				"force":  300 + random(250),

			]);
		}

	return ([
		"action":msg[random(sizeof(msg))],
		"damage": 100 + random(100),
		"damage_type": "����",
		"dodge": random(50),
		"parry": random(50),
		"force": 200 + random(120),
	]);
}


string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string query_parry_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ( !me->query("quest/pixie/pass") || me->query("gender") != "����")
		return notify_fail("��а����ֻ��ͨ����ϰ���������䡹��ѧϰ��\n");
	if (me->query_skill("pixie-jian",1) >= 240) return 1;
		return notify_fail("��а����ֻ��ͨ����ϰ���������䡹��ѧϰ��\n");
}

string perform_action_file(string action)
{
        return __DIR__"pixie-jian/" + action;
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���������\n");
       if (me->query_skill("pixie-jian",1) < 180) return 0;
        me->receive_damage("jingli", 30);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   	object weapon = me->query_temp("weapon");

    	if (!weapon) return;
   	if(((string)weapon->query("id")=="xiuhua zhen" || (string)weapon->query("id")=="lanyu duzhen")  
            && random(me->query_str(1)) > victim->query_str(1)/3){
		victim->receive_wound("qi", me->query_str()* 3 +random(500));
		 return HIR "ֻ�����͡�һ����һ��Ѫ˿��"+victim->name()+"���̵���״������\n" NOR;
	}


         if ( me->query_skill_mapped("force") == "kuihua-shengong"
        && random(me->query_con(1)) > victim->query_con(1)/3){
		victim->receive_wound("qi", me->query_con() * 3 +random(500));
                victim->add_busy(1); 
		 return HIM "����ħ�������ޱȣ�"+victim->name()+"ֻ����һ����������״�͸�룬�����������������ߣ���ʱ��Ϣ���ң�\n" NOR;
	}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon, weapon1;
        string msg, *limbs, limb;
        int ap, dp, skill, j, i;

        if( ob->query("env/invisibility") ) return 0;
        if( !userp(me) && random(2) ) return 0;

        weapon1 = me->query_temp("weapon");

        if( me->query_skill("pixie-jian", 1) < 200
         || me->query_skill_mapped("sword") != "pixie-jian"
         || !weapon1
         || weapon1->query("skill_type") != "sword" ) return 0;

        if( me->query("combat_exp") < ob->query("combat_exp")/2 || me->is_busy() || damage < 100 ) return 0;

        skill = me->query_skill("pixie-jian", 1);
        weapon = ob->query_temp("weapon");

        if( objectp(weapon) )
                msg = weapon->query("skill_type");
        else {
                mapping prepare = ob->query_skill_prepare();
                if( !sizeof(prepare) ) msg = "unarmed";
                else msg = keys(prepare)[0];
        }

        if ( me->query("neili") < ob->query("neili")/5 ) return 0;

        ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
        if ( weapon ) ap *= 2;
        if ( ob->query("neili") > me->query("neili") * 2 ) ap += ap/2;

        dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;
        if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;  
        else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;

        ap = ABS(ap);
        dp = ABS(dp);

        if ( random(me->query("dex")) > ob->query("dex")/2) dp += random(dp/2);
        if ( skill > 350 ) dp += random(dp);

        if ( wizardp(me) ) tell_object(me, sprintf("ap: %d, dp: %d\n", ap ,dp ));

        if ( random(dp + ap) > ap && !random(3) ) {     
                limbs = ob->query("limbs");
                limb = limbs[random(sizeof(limbs))];
                msg = BLU+"ֻ��$N����Խ��Խ��,�����к�����֮ʽ��\n";
                msg += query_action(me, weapon1)["action"];
                msg = replace_string( msg, "$l", limb);
                msg = replace_string( msg, "$w", weapon1->name()+BLU) + "��\n"NOR;
                if( userp(ob) && !userp(me) && damage > 1000 )
                        damage = 1000 + (damage-1000)/10;       
                j = damage/2 + me->query_skill("sword") + me->query("jiali");
                ob->receive_damage("qi", j, me);
                ob->receive_wound("qi", j/2, me);
                msg += COMBAT_D->damage_msg(j, "����");
                msg = replace_string( msg, "$l", limb);
                msg = replace_string( msg, "$w", weapon1->name());
                message_vision(msg, me, ob);
                COMBAT_D->report_status(ob, ob->query("qi") >= 0 || ob->query("eff_qi")+ob->query_temp("apply/qi") < 0);
                return -6000;
        }
                return 0;
}
int double_attack(object me)
{
	if ( me->query_skill("pixie-jian", 1) >= 160
	&& me->query_skill_mapped("sword") == "pixie-jian"
	&& me->query("quest/pixie/pass")
	&& me->query("gender") == "����")
		return 1;
}
