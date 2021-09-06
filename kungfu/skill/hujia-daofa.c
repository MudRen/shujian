// hujia-daofa.c
// query("quest/ѩɽ�ɺ�/�书/hujiadaofa")��ѧϰ�Ļ�������
// query("quest/ѩɽ�ɺ�/�书/ronghe") �ǵ����ںϵı�־
// query_temp("quest/ѩɽ�ɺ�/�书/lengquan") ����Ȫ�ڹ�yun lengquan֮��ı�־

inherit SKILL;
#include <ansi.h>
int perform_fdj(object,object);

string  *msg = ({
HIB"ͻȻ$n��ǰһ�Σ���һ�����캮�������ĸо���$n����������ȫ�������ˣ�"NOR,
HIB"��Щ$w"HIB"��������֮���$n��ǰ�����ݺᣬ��������֮�䣬��ȫ��������������"NOR,
HIB"ֻ��$n�ܱߺ���Խ��Խ�أ����������������絶���Ҫ��$n��������"NOR,
HIB"ֻ��$N�߶���Ȫ�񹦣�$n�о�����Խ��Խ�أ���������������Ҳ�����絶�������"NOR,
HIB"ͻȻһ�󵶷�Ϯ����$n��ҪԾ���������棬����һ��$w"HIB"�Ѿ�͸��$n����"NOR,
HIB"$n�ܱߺ���Խ��Խ�أ�����$n������֮�У�$w"HIB"�Ѿ�͸��$n����"NOR,
HIB"$N�ĵ���ͻȻ���ⶸǿ�������������أ�$n�ж�Խ������"NOR,
HIB"ֻ��$n�ܱߺ���Խ��Խ�أ�ͻȻ���������������絶���Ҫ��$n��������"NOR,
HIB"$n�ܱߵĺ����ƺ��������أ�����$nһ��֮�ʣ�һ��$w�Ѿ�͸��$n����"NOR,
HIB"ͻȻ������������ʯ������裬��$n�ҵñ�������"NOR,
});
mapping *action = ({
([      "action" : "$N����$w���ƣ�һ�С��Ʋ������������滮�˸��뻡��$wһ��һ�գ�����������$n��ȥ",
        "skill_name" : "�Ʋ�����",
        "force"  : 120,
        "dodge"  : 30,
        "parry"  : 12,
        "lvl"    : 0,
        "damage" : 190,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�ɳŸ�Ӳ������������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���",
        "skill_name" : "ɳŸ�Ӳ�",
        "force"  : 160,
        "dodge"  : 40,
        "parry"  : 15,
        "lvl"    : 30,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$N��̤���Է�λ��б����ǰ��ʹ��һ�С���������������$w��������һ��ѹ��$n",
        "skill_name" : "��������",
        "force"  : 185,
        "dodge"  : 45,
        "parry"  : 17,
        "lvl"    : 50,
        "damage" : 210,
        "damage_type" : "����",
]),
([      "action" : "$N����$w��ת��Ծ��һ�С���´��ʡ�������б�̣���Ȼ����һ����ն$n������",
        "skill_name" : "��´���",
        "force"  : 255,
        "dodge"  : 60,
        "parry"  : 32,
        "lvl"    : 160,
        "damage" : 280,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ��������$w��ʹ��һ�С��׺���᡹���������ã����ҿ�����������$n",
        "skill_name" : "�׺����",
        "force"  : 290,
        "dodge"  : 70,
        "parry"  : 35,
        "lvl"    : 180,
        "damage" : 290,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�������ů�������Ծ����أ�������㣬$w˳����ǰ��Ю��������$n��$l",
        "skill_name" : "������ů",
        "force"  : 320,
        "dodge"  : 85,
        "parry"  : 35,
        "lvl"    : 190,
        "damage" : 200,
        "damage_type" : "����",
]),
([      "action" : "$N���һ�㣬���ʹһ�С��˷��ص�������ʱ�����������䵶��������˷�ӿ��$nȫ��",
        "skill_name" : "�˷��ص�",
        "force"  : 340,
        "dodge"  : 100,
        "parry"  : 50,
        "lvl"    : 200,
        "damage" : 210,
        "damage_type" : "����",
]),
});

int valid_enable(string usage) {
   if ( this_player()->query("quest/ѩɽ�ɺ�/�书/hujiadaofa"))
             return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 300)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 50)
                return notify_fail("����ڹ����̫ǳ��\n");

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
        int i,level;
        object target;
        object *enemy;
		string str;
        level   = (int) me->query_skill("hujia-daofa",1);
        if ( me->query_temp("quest/ѩɽ�ɺ�/�书/kuaidao")){
             return ([
                "action": HIC"ͻȻ֮�䣬$N���е�$w"NOR+HIC"����һ�������Բ������$nбб������$n�پ�����һ�ϡ�"NOR,
                "damage": 550,
                "dodge" : 100,
                "damage_type": "����"
			 ]);
        }
        if( !userp(me) && me->query("env/invisibility")
             && me->query("master_user/user") ){
                return ([
                        "action": msg[random(sizeof(msg))],
                        "damage":(random(2)+4)*80,
                        "damage_type":random(2)?"����":"����",
                        "dodge": 5,
                        "force":250+random(250)
                ]);
        }
        enemy = me->query_enemy();
        if(sizeof(enemy)>0)
        {
           target = enemy[random(sizeof(enemy))];
      	   if(me->query_temp("quest/ѩɽ�ɺ�/�书/powerup")
		  ||(!me->query_temp("quest/ѩɽ�ɺ�/�书/kongzhi")
		    && me->query_temp("quest/ѩɽ�ɺ�/�书/lengquan")
		    && me->query_skill_mapped("parry") == "hujia-daofa"
			&& random(me->query_skill("force"))>target->query_skill("force")/4 
			&& random(me->query("combat_exp"))>target->query("combat_exp")/4)){
			str =action[random(sizeof(action))]["action"];
			//SKILL_D("hujia-daofa")->query_action(me, me->query_temp("weapon"))["action"]
          	switch(random(2)){
                	case 0: str +="��\n"+HIR"$NͻȻ����Ծ�������һ������"+weapon->name()+HIR"��Х��������������һ����"NOR;break;
                	case 1: str +="��\n"+HIY"$N����Գ�ۣ����е�"+weapon->name()+HIY"�������£��仯Ī�⣬������$n"HIY"����Ҫ����" NOR; break;
            }
	        target->set_temp("must_be_hit",1);
			me->set_temp("quest/ѩɽ�ɺ�/�书/kongzhi",1);
			//���ƴ����￪ʼ��powerup��������֮�󣬱�����ͨ������������֮��ſ��ܳ����´�powerup����
          	return ([
                	"action":str, 
                	"damage":(random(3)+4)*60,
                	"damage_type": "����",
                	"dodge": random(40)+40,
                	"force": random(me->query_skill("force"))+250,
           ]);
           }
		}
        if(sizeof(enemy)>0)
        {
           target = enemy[random(sizeof(enemy))];
           if ( random(me->query_skill("force"))>(target->query_skill("force")/3) 
	            && me->query("quest/ѩɽ�ɺ�/�书/ronghe") 
                && !me->query_temp("quest/ѩɽ�ɺ�/�书/ronghe") 
				&& random(10)>6
                && random(me->query_skill("lengquan-shengong", 1))>200
                && me->query_skill_mapped("force") == "lengquan-shengong")
                        call_out("autopfm",1,me,target);
        }
        if(me->query_temp("hjdf/ldj/color")=="color"
        && me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq") ){
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIB+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIB)+NOR,
                      "damage_type": "����",
                      "dodge": random(40)+10,
                      "damage":(random(3)+4)*70,
                      "force": random(me->query_skill("force"))+100,
           ]);
       }
        else if(me->query_temp("hjdf/ldj/color")=="color") {
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIR+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIR)+NOR,
                      "damage_type": "����",
                      "dodge": random(40)+10,
                      "force": random(me->query_skill("force"))+100,
           ]);
       }

        if(me->query_temp("hjdf/fdj/color")=="color"
        && me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq") ){
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIW+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIW)+NOR,
                      "damage_type": "����",
                      "dodge": random(40)+10,
                      "damage":(random(3)+4)*70,
                      "force": random(me->query_skill("force"))+100,
           ]);
       }
        else if(me->query_temp("hjdf/fdj/color")=="color") {
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIC+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIC)+NOR,
                      "damage_type": "����",
                      "dodge": random(40)+10,
                      "force": random(me->query_skill("force"))+100,
           ]);
       }
        for(i = sizeof(action); i > 0; i--)
		          if(level >= action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

void autopfm(object me,object target)
{
        object weapon1,weapon2,* obj;
        int i;
        if(!me || !target || !me->is_fighting(target)) return;
        if(me->is_busy()) return;
       if( me->query_skill_mapped("sword") != "miaojia-jianfa") return;
        me->add("neili",-100);
        if (me->query("neili")<0) me->set("neili",0);
        weapon1 = me->query_temp("weapon");      
        if(!weapon1) return;
        obj = all_inventory(me);
        for(i=0; i<sizeof(obj); i++) 
          if(mapp(obj[i]->query("weapon_prop"))
             && obj[i]->query("skill_type")=="sword")
              weapon2 = obj[i];
        if(!weapon2) return;
        i = me->query_skill("sword")+me->query_skill("blade");
        if(random(2)) 	message_vision(HIC"\n�����ţ�$N˳�ֳ���"+weapon2->query("name")+HIC"�������һ������Ȼʹ����ҽ�����\n"NOR,me,target);
 		else message_vision(HIC"\n$N��Цһ����ͻȻ"+weapon1->query("name")+HIC"����һ�Σ�"+weapon2->query("name")+HIC"һ������Ȼʹ����ҽ�����\n"NOR,me,target);
        weapon1->unequip(); 
        weapon2->wield();
		me->set_temp("quest/ѩɽ�ɺ�/�书/ronghe",1);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        me->delete_temp("quest/ѩɽ�ɺ�/�书/ronghe");
		weapon2->unequip(); 
        weapon1->wield();       
        return;   
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("jingli") < 80)
                return notify_fail("������������������˺��ҵ�����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("������������������˺��ҵ�����\n");

        me->receive_damage("jingli", -41-random(40));
        me->add("neili", -31-random(30));
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}

mixed hit_ob(object me, object victim, int damage)
{
       if (living(victim) && me->query_temp("hjdf/ldj") ){
          me->set_temp("hjdf/ldj/attack_chance",1);
       }
        if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq")
        && me->query_skill_mapped("force") == "lengquan-shengong" )
        message_vision(HIY"$N�ѽ���Ȫ�����õó����뻯��ÿһ�У�ÿһʽ��������Ȫ�ھ����������ˣ�\n"NOR, me);
        if(!me->query_temp("quest/ѩɽ�ɺ�/�书/kongzhi")) return;
 		if(victim->query_temp("must_be_hit") && !me->query_temp("pfmronghe")) victim->delete_temp("must_be_hit");
	    if( me->query_skill_mapped("force") != "lengquan-shengong") return;
	    if( me->query_skill_mapped("parry") != "hujia-daofa") return;
	    if( me->query_skill_mapped("blade") != "hujia-daofa") return;
        if(!me->query_temp("weapon")) return;
        if(me->query_temp("quest/ѩɽ�ɺ�/�书/kongzhi")>=3)
		{
           me->delete_temp("quest/ѩɽ�ɺ�/�书/kongzhi");  //ɾ�����Ʊ�־���л����powerup����
		   return;
		}
		if (me->query_temp("quest/ѩɽ�ɺ�/�书/lengquan") 
            && me->query_skill_mapped("force") == "lengquan-shengong"
            && (random(me->query("combat_exp"))>(victim->query("combat_exp")/3)
            || random(me->query_skill("lengquan-shengong"))>(victim->query_skill("force")/3)))
            me->add_temp("quest/ѩɽ�ɺ�/�书/kongzhi",1); //����powerup����

}

int ob_hit(object me, object ob, int damage)
{
    if (living(me) && ob->query_temp("hjdf/fdj") && random(2)==0 ){
        perform_fdj(ob,me);
   }
}

int perform_fdj(object me,object target)
{
  if (!me->is_busy()){
    message_vision(HIY"����$n����һ˲�䣬$N�Ϳ�����$n�����������㰵�ˡ��ɵ���������Ϯ��$n��\n"NOR,me,target);
    me->set_temp("hjdf/fdj/color","color");
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    for (;random(3);)
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
    me->delete_temp("hjdf/fdj/color");
  }
    return 1;
}
