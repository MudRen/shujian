// hujia-daofa.c
// query("quest/ѩɽ�ɺ�/�书/miaojiajianfa")��ѧϰ�Ļ�������
// query("quest/ѩɽ�ɺ�/�书/ronghe") �ǵ����ںϵı�־
// query_temp("quest/ѩɽ�ɺ�/�书/lengquan") ����Ȫ�ڹ�yun lengquan֮��ı�־

#include <ansi.h>
inherit SKILL;
#include <combat_msg.h>

mapping *action = ({
([   "action" : "$N��¶΢Ц������$wһ��������ಽ��Ѹ���ޱȣ����Ⱪ�������е�$w����һ����������$n",
     "force"  : 150,
     "dodge"  : 10,
     "parry"  : 25,
     "damage" : 180,
     "lvl"    : 0,
     "damage_type":  "����"
]),
([   "action" : "$N����$w�����ļ��죬ֻ�ϵ�$n�ۻ����ң��벻֪�Ӻι�����$w��һ�����벻���ķ�λб����$n",
     "force"  : 160,
     "dodge"  : 25,
     "parry"  : 30,
     "damage" : 200,
     "lvl"    : 10,
     "damage_type":  "����"
]),
([   "action" : "$N�������ߣ����׸���������ͻ�������ж��䣬�󳷲�������$w��Ȼ���ϣ�һ�����ϴ���$n",
     "force"  : 170,
     "dodge"  : 22,
     "parry"  : 32,
     "damage" : 200,
     "lvl"    : 20,
     "damage_type":  "����"
]),
([   "action" : "$Nȴ���Ჽ�����е�$w�Ƶ��ǵ�������һ�Σ����Ӷ��ϣ�����$w����һ������׼$n��$l��������",
     "force"  : 180,
     "dodge"  : 40,
     "parry"  : 35,
     "damage" : 225,
     "lvl"    : 30,
     "damage_type":  "����"
]),
([   "action" : "$Nһ�����е�$w���������������������$n������������ת��������$w���Ȼ��������$n��ȥ",
     "force"  : 190,
     "dodge"  : 45,
     "parry"  : 100,
     "damage" : 200,
     "lvl"    : 40,
     "damage_type":  "����"
]),
([   "action" : "$N�鲽�������ὣ�ؽ��������ϱ�������$w��������һ�̣�û���κλ��ɣ�Ȼ����ò���˼��",
     "force"  : 200,
     "dodge"  : 50,
     "parry"  : 45,
     "damage" : 200,
     "lvl"    : 50,
     "damage_type":  "����"
]),
([   "action" : "$N������ת�����ֽ�ָ��΢΢һ��ת������$w�û��������ǵ㣬����$wȴ�������´�������$n",
     "force"  : 210,
     "dodge"  : 40,
     "parry"  : 47,
     "damage" : 200,
     "lvl"    : 60,
     "damage_type":  "����"
]),
([   "action" : "$N��ɫ΢�䣬ƽ��бϴ����Բ��ֱ��һ�С����ﳯ���������ж�ʱ��������ޱȣ���ƥ��������$n",
     "force"  : 220,
     "dodge"  : 30,
     "parry"  : 52,
     "damage" : 240,
     "lvl"    : 70,
     "damage_type":  "����"
]),
([   "action" : "$N���ֽ�ָ������ת������һŤ��һ�С�ϴ�����б��¡�������$w�й�ֱ����Ѹ���ޱ���$n��ȥ",
     "force"  : 230,
     "dodge"  : 20,
     "parry"  : 54,
     "damage" : 200,
     "lvl"    : 80,
     "damage_type":  "����"
]),
([   "action" : "$N�ݲ����ߣ���������$n���䣬$n��Ҫ����ط���ֻ��ɲ�Ǽ佣��һ����һ�С�ӭ���ȷ�����ɽ��",
     "force"  : 240,
     "dodge"  : 30,
     "parry"  : 62,
     "damage" : 220,
     "lvl"    : 90,
     "damage_type":  "����"
]),
([   "action" : "$N����ಽ��һ�С�������´��ʡ�������$w���ּ�������������$w����������϶�������$n",
     "force"  : 250,
     "dodge"  : 65,
     "parry"  : 65,
     "damage" : 220,
     "lvl"    : 100,
     "damage_type":  "����"
]),
([   "action" : "$N����̧�ۣ�һ�С�����ת�����롹����ؼ���һ�����ֳ�ǰ������һ�������Ļ�����$n��ȥ",
     "force"  : 260,
     "dodge"  : 40,
     "parry"  : 68,
     "damage" : 250,
     "lvl"    : 110,
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С��ϲ��Ʊ�ժ�¡�������Ծ�𣬽���ȴ�ִӰ���д��£�˫������$w�����Ʊ��˵ش���$n",
     "force"  : 270,
     "attack" : 97,
     "dodge"  : 60,
     "parry"  : 72,
     "damage" : 250,
     "lvl"    : 120,
     "damage_type":  "����"
]),
([   "action" : "$Nһ�С����ý��׺���᡹������$w���͡���һ��б������գ��漴���¡��ৡ�����һ������",
     "force"  : 280,
     "attack" : 100,
     "dodge"  : 45,
     "parry"  : 75,
     "damage" : 250,
     "lvl"    : 130,
     "damage_type":  "����"
]),
([   "action" : "$N����̧�ۣ�����΢̧��һ�С����������ر�����������$w�͵����·����𣬼���һ�ɾ��練��$n",
     "force"  : 300,
     "dodge"  : 50,
     "parry"  : 82,
     "damage" : 250,
     "lvl"    : 140,
     "damage_type":  "����"
]),
});

int valid_enable(string usage) {
   if ( this_player()->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa"))
                   return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 700)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("force") < 90)
                return notify_fail("����ڹ����̫ǳ��\n");

        if ((int)me->query_skill("sword", 1) < 100)
                return notify_fail("��Ļ���������򲻹����޷�ѧϰ��ҽ�����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("miaojia-jianfa", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ҽ�����\n");

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
        level   = (int) me->query_skill("miaojia-jianfa",1);
        enemy = me->query_enemy();
        if(sizeof(enemy)>0)
        {
           target = enemy[random(sizeof(enemy))];
     	   if(me->query_temp("quest/ѩɽ�ɺ�/�书/powerup")
		    ||(!me->query_temp("quest/ѩɽ�ɺ�/�书/kongzhi")
		    && me->query_temp("quest/ѩɽ�ɺ�/�书/lengquan")
		    && me->query_skill_mapped("parry") == "miaojia-jianfa"
			&& random(me->query_skill("force"))>target->query_skill("force")/4 
			&& random(me->query("combat_exp"))>target->query("combat_exp")/4
			))
		   {
			str =action[random(sizeof(action))]["action"];
			//SKILL_D("miaojia-jianfa")->query_action(me, me->query_temp("weapon"))["action"]
          	switch(random(2)){
                	case 0: str +="��\n";
						    str +=HIC"ͻȻ������һ˲֮�䣬$N�ִ̳�һ���������ϲ�һ�������Ϳ�ݾ��׵Ľ�����ø���������"NOR;
							break;
                	case 1: str +="��\n";
						    str +=HIW"ͻȻ$N���е�"+weapon->name()+HIW"����һ����$nֻ����һ������ӹ���һ������ֱָ$n�������ڣ�" NOR;
							break;
            }
	        target->set_temp("must_be_hit",1);
			me->set_temp("quest/ѩɽ�ɺ�/�书/kongzhi",1);
			//���ƴ����￪ʼ��powerup��������֮�󣬱�����ͨ������������֮��ſ��ܳ����´�powerup����
          	return ([
                	"action":str, 
                	"damage":(random(3)+4)*80,
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
        if(me->query_temp("mjjf/lianhuan/color")
        && me->query_temp("mjjf/lianhuan/lq") ){
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIB+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIB)+NOR,
                      "damage_type": "����",
                      "dodge": random(40)+10,
                      "damage":(random(3)+4)*70,
                      "force": random(me->query_skill("force"))+100,
           ]);
        }
        else if(me->query_temp("mjjf/lianhuan/color") ){
            str =action[random(sizeof(action))]["action"];
            return ([
                      "action" : HIW+replace_string(replace_string(str, "$w", "$W"), "$W", "$w"HIW)+NOR,
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
       if( me->query_skill_mapped("blade") != "hujia-daofa") return;
        me->add("neili",-100);
        if (me->query("neili")<0) me->set("neili",0);
        weapon1 = me->query_temp("weapon");      
        if(!weapon1) return;
        obj = all_inventory(me);
        for(i=0; i<sizeof(obj); i++) 
          if(mapp(obj[i]->query("weapon_prop"))
             && obj[i]->query("skill_type")=="blade")
              weapon2 = obj[i];
        if(!weapon2) return;
        i = me->query_skill("sword")+me->query_skill("blade");
        
        if(random(2))  message_vision(HIC"\n�����ţ�$N˳�ֳ���"+weapon2->query("name")+HIC"������һ������Ȼʹ�����ҵ�����\n"NOR,me,target);
 		else message_vision(HIC"\n$N����һ����Х��ͻȻ"+weapon1->query("name")+HIC"����һ�Σ�"+weapon2->query("name")+HIC"��$n������ػ���һ����\n"NOR,me,target);

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

        if (!objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query("jingli") < 80)
                return notify_fail("�������Ŀǰû�а취��ϰ��ҽ�����\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("��������������޷���ϰ��ҽ�����\n");
        
        me->add("jingli", -41-random(40));
        me->add("neili", -31-random(30));
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"miaojia-jianfa/" + action;
}


mixed hit_ob(object me, object victim, int damage)
{
        if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach")
        && me->query_temp("lqsg/lq")
        && me->query_skill_mapped("force") == "lengquan-shengong" )
        message_vision(HIR"$N������Ȫ�����õó����뻯��ÿһ�У�ÿһʽ��������Ȫ�ھ����������ˣ�\n"NOR, me);
        if(!me->query_temp("quest/ѩɽ�ɺ�/�书/kongzhi")) return;
 		if(victim->query_temp("must_be_hit")  && !me->query_temp("pfmronghe") ) victim->delete_temp("must_be_hit");
	    if( me->query_skill_mapped("force") != "lengquan-shengong") return;
	    if( me->query_skill_mapped("parry") != "miaojia-jianfa") return;
	    if( me->query_skill_mapped("sword") != "miaojia-jianfa") return;
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
int ob_hit(object ob, object me, int damage) //piaojian����
{
	if(!me->query_temp("quest/ѩɽ�ɺ�/�书/piao"))	return 1;
	if( me->query_skill_mapped("force") != "lengquan-shengong") return 1;
	if( me->query_skill_mapped("parry") != "miaojia-jianfa") return 1;
	if( me->query_skill_mapped("sword") != "miaojia-jianfa") return 1;
    if(!me->query_temp("weapon")) return 1;
	if (random(me->query("combat_exp"))>ob->query("combat_exp")/4)
	{
       if(me->is_busy())
	   {
           message_vision(HIW"$NͻȻʹ�á�Ʈ��������������Ʈ��������$n�Ծ�֮�࣬�������ɱ仺��\n" NOR, me,ob);
               return  -damage*2/3-random(damage/3);
	   }
	   else 
	   {
           message_vision(HIW"$N��һ������ʹ����Ʈ����������ֻ��$N�㲻մ�أ������Ṧ���ν����裬����Ʈ��������" NOR, me);
           me->set_temp("quest/ѩɽ�ɺ�/�书/kongzhi",1);
		   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 3);
		   me->delete_temp("quest/ѩɽ�ɺ�/�书/kongzhi");
	  }
      me->start_perform(3,"��Ʈ�־���");
               return  -damage/3-random(damage*2/3);
	}
}
