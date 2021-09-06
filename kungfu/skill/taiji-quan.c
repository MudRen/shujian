// taiji-quan.c ̫��ȭ
// write by snowman@SJ
// modify by snowman@SJ 23/02/2000
// Modified by snowman@SJ 24/05/2001
// ����pfm taiji�ĸ���autoЧ�� BY Spiderii
#include <ansi.h>
#include <combat.h>

inherit SKILL;

#include <combat_msg.h>
#define TAIJI    "/kungfu/skill/yinyun-ziqi/taiji"

mapping taiji_names = ([
        "luanhuan":     "���һ�����",
        "yinyang":      "����������",
        "dongjing":     "����������",
        "liangyi":      "�����Ǿ���",
        "gangrou":      "���������",
        "zhannian":     "��մ����",
        "ji":           "�����־���",
        "yin":          "�����־���",
        "an":           "�����־���",
        "zhuanfan":     "�귭",
        "luoxuan":      "����",
        "jingheng":     "����",
        "kaihe":        "����",
        "ruanshou":     "����",
        "xuling":       "����",
]);

int taiji(object me, object victim, object weapon, int damage);

string *parry_msg = ({
"$p˫��һ������$P�����ƾ�����ȥ��$N��������������һƬճ��֮���м�һ�㡣\n",
"$p�Ҽ�б����������ָƾ�ջ��˼���Ȧ�ӣ�������΢��������$Nǧ�������\n",
"$p�ۼ�$P����������ʹ��һ�С���ȸβ�����ҽ�ʵ������飬���𡰼����־���ճ��ճ�棬�����Ѵ�ס$P���󣬺ᾢ������$N����������ǰһ�壬�����������ʼվ����\n",
"����$p˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�ֻ����$P��ԭ�ؼ�ת�߰��¡�\n",
"$p��������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ��������ʱ���׵�$P����ײײ�������������㲻�ȡ�\n",
"$pʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$P�׿���\n",
"$p����Ϣ΢�ϣ�����һ�С�б���ơ�����$P��ƫ��\n",
"$p��һ����������������ת�����ƻӳ���һ��һӭ����$P�������������˻�ȥ��\n",
"$p˫��һ����ʹ��һ�С����֡���˫���ᵽ�˼������������飬��$P�ļ���������ȥ��\n",
"$p����˫��һ�ӭ��$P��ȥ���������ƽ���δ��֮�ʣ�ʩ������ȸβʽ�������¡��𼦶���ʽ��������صأ��������գ�ȫ��ת������һö���ݡ�\n",
"��������ʯ���һ˲֮�䣬$p����һ�������ǡ��׺����᡹��ǰ���У�$P�ľ�����ʱ��ա�\n",
});

string query_parry_msg(object weapon, object victim)
{
	if (victim->query_temp("weapon"))
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return parry_msg[random(sizeof(parry_msg))];
}

string *att_msg = ({
"$N����һ�С���ȸβ����˫�ֻ��˸���Ȧ����������������$n��$l",
"$N���$n��һ�С����ޡ���������ȭ�������ϻ�����һǰһ�����ƽ��",
"$N���С��������ơ�������������������ǰ����۰뻷���ұ�ֱ�죬����$n��$l",
"$N���Ŷ����������鰴������ʹһ�С��׺����᡹����ȭ��ץ��$n��$l��ȥ",
"$N����΢�����鲽��һ�ǡ�§ϥ��������������ǰ�����»�������$n$l��",
"$N�ұ۰뻷������������һ�С��ֻ����á���ʮָ���ţ���������$n��$l",
"$N������ֱ�������黮�������ұ��������һ�ǡ�����������������$n��$l",
"$N�����������������黮���������»�����ȭ��һ�ǡ�ָ�ɴ�������$n���ɲ�",
"$N˫���»���ȭ�������ǰ������Ȧ��һ�С�˫�������������������$n��̫��Ѩ",
"$N�󲽳��飬���������鰴�����ֳ�����ʹһ�С��������š�����$n��$l��ȥ",
"$N�ҽ����������ֻ�Ȧ�󸧣�һ�С���̽��������Բת��ǰ����$n���Ż�ȥ",
"$Nʩ��������ʽ�����������⻮��ס$n��������������ָ������$n��$l",
"$N���ֱ��ƺ�����ǰ��������ȭ�����´�����һ�С���׿�����������$n��$l",
"$N���ǰ̤�벽����������ʹһ�С������롹����ָ�������ϴ���$n���ɲ�",
"$Nһ�С���ͨ�ۡ������һ������������$n��ǰ�������Ͼ���Ʋ������̫����������$n",
"$N�ҽ�̤������������ȭ�黮�����ƻ��б��£���ǡ������ơ�һ�����㽫$n����̫��Ȧ��",
"$N�����������ȡ��ɿ衢��������ϥ������������һ�С�������������$n��$l",
"$N���������ҽŶ�����ʹһ�С��𼦶�������˫ȭ����������̫��ȦȦ��$n��$l",
"$N������̤��˫����ȭ�����ӳ���ʹһʽ����Ů���󡹣�˳��$n�ֱ�ֱ�ϣ�����$nǰ��",
"$N���ֻ�Ȧ�����־���ǰ��������ǰƲ����ʹһ�С�����Ʋ��������$n��$l��ȥ",
"$N�����鰴�����ֱ���������黮һ�С�ת����ȡ��������������$n��$l",
"$N����һ�С��Դ��������ֻ�̫��Ȧ§��ϥ��������ȭ���»���������$n��$l",
"$N��̤���Ƿ�λ�������ң�˫ȭ�����ʮ�֣�һ�С��������ǡ�����$n��$l��ȥ",
"$N����΢ת��������ֱ���ұ�΢����������ϣ�ʹһ�С�����������$n���ֱ˦��ȥ",
"$N˫���쿪������������һ����Բ����һ�С�ת�����������$n������������������̫��Ȧ��",
"$N���ֻ������գ�������ȭ��ǰ�Ƴ���ȭ�������һ�С��乭�仢����ֱ��$n$l��ȥ",
"$Nʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$n$l��ס��̫���ᾢ�漴����",
"$N����һ�������Ծ����˫�ֻ�̫��Ȧ����$n�Ĺ�������������ץ��$n������������",
"����$Nһ�С�б���ơ�����$n������ƫ��˫ȭ�ڻ������������ɾ���һ������$n",
"����$N���С�������ɽ����˫ȭ����������бת����$n���һ�ƣ���������Ҫ��$n�Ƴ�",
"$N������Ұ����ס���ת��$n�����ǰ�������ƽ����$n����һ�����뽫�����",
"$N�����ֱ��������ƣ����ֽ��棬�̶����ҷֿ�������������ǰ�������������������ϣ���������Ʊա���ǰ��������$n",
"$N����΢��ת����ϥ���裬���С�ʮ���֡�����ֻ�ֱ�΢����������������ǰ�����ϱ����أ�������ʮ���Σ��ֱ��������໮������",
});

string *taiji_level = ({
"��ȸβ","����","��������","�׺�����","§ϥ����","�ֻ�����","����������","ָ�ɴ�",
"˫����","��������","��̽��","����ʽ","��׿���","������","��ͨ��","������","����",
"�𼦶���","��Ů����","����Ʋ��","ת�����","�Դ�","��������","�����","ת�����",
"�乭�仢","����","���Ծ","б����","������ɽ","Ұ�����","����Ʊ�","ʮ����",
});

string *taiji_msg = ({
"$N�ȵ��������С���һ��һ��˫���Ƴ���ȥ������������ȴ�����ھ�",
"$Nת����������������$n������΢�������²���",
"$N��ƮƮ��һ���ĳ��������������ޣ��������룬ȦȦ��������������һ����������б��ԲȦ��͸������",
"$N˫��Բת��ÿһ�ж�����̫��ʽ�������仯����΢���������졢�Ծ��ƶ�",
"$N˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ������",
"$N˫�����Ҵ���һ��һ�����ѻ�������",
"$N�����黮���ֱ�����$n",
"$N˫�ַ������������Ʒ���",
"$N˫�����⻮������Բ�����ɹ��£�û��һ˿�켣��Ѱ",
"$N˫��һ�����������򣬳�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����",
"$N��һ����������������ת�����ƻӳ���һ��һӭ��Ҫ��ס$n",
"$N�Ҽ�б��������ƾ�ջ��˼���Ȧ��",
"$N���Ӱ�б�����ƻ���Ȧ����������������$n����б��Ӧ��",
"$N˫���ᷭ���ᵽ�˼������������飬��$n��ǰ���ػ���",
"$N��һ�鲽��������$n��ǰ�����˼���ԲȦ",
"$N˫��һ��һ��������$n���߼����鲽��ת�˸���̫��Ȧ",
"$N��ƽ������˫����Ȼ�Ӷ���������ˮ�л��������Ἣ��",
"$N���˸������֡�ʽ��˫�������в�����ú����ʵ��Ư�첻��",
"$N�ۿ�$n���������Ų�æ�ؽ�˫���������绳��̫��",
"$N����������������Ŀ������$n��������$p������£������������ɽ��ȴ����������",
"$N����ת������ԲȦ������ͻ��Ȧ�д���������$n",
"$N�������У�����ԲȦ���ұ�һ�죬��Ҫ��ס$n���ֱ�",
"$N�����ִ��������˸���Ȧ������˳�����Ҳ�����Ƴ�һ��С̫��Ȧ",
"$N�鲽�󳷣�˫�ֻ���ֹ����ǰ����ǰ�Һ󣬻�����$n����",
"$nһ�д����ȴ��$N���ָߣ����ֵͣ�һ��̫��ԲȦ�׳�",
"$N�ҽ�ʵ������飬����̫���ھ���ճ��ճ�棬һ����ԲȦҪ��ס$n",
"$N����һЦ���ұ��������$n��ǰ����������"+chinese_number(1+random(10))+"��ԲȦ",
"$N����һЦ������������$n��ǰ����������"+chinese_number(1+random(10))+"��ԲȦ",
});

string *taiji_hit_msg = ({
"$n��δ��������������������ƣ�����Ӳ�ӣ�����б���������ѱ�$N�ۻ�����������ס��\n",
"$p����������ǰһ�壬ȴ���ÿ����$PȦ�ɵ�����֮�У�\n",
"����$n������$p��ס����һ�����ƣ�ȴ���������������䵱��̫���ķ������ɻ�Բ��\n",
"��Ȼ��$P������$p˫�֣�˳��һȦһ�ƣ���$p˦����\n",
"$n֪��������Ҫ�뵲�ܣ�ȴ��$N˳��һ��һ�𣬷��˳�ȥ��\n",
"$pһ��С�ģ���ԲȦ��ס�������������ݰ㼱ת��Ȧ��\n",
"$n�����ֵ��������ѳ���$N��̫��ԲȦ��ȴ�����Լ�С���ѱ�������Ϣ�ذ���һ�ƣ�\n",
"����$nһ�д�������$N������ǧ���һ����ƾ����ɳ�ȥ��\n",
"$P˫��һȦһת��ʹ��̫���еġ����Ͼ������ѽ�$nȦס��\n",
"����һ���ӵĽӴ���$p�㱻̫��������ס�����ɼ��ط��˳�ȥ��\n",
"����$n��Ҫ��ǰץס$N��ȴ��$P����һ��һ�ƣ����Լ��ľ������������\n",
"$n��Ҫ��ס$N��ȴ������գ�����һ��Ȧס��˦�˳�ȥ��\n",
"$n��Ц������$N��˫�֣�ȴ�����ɼ���һ���������Լ����ϣ�\n",
"��һ̫��Ȧ����һ���ۻ��ޱȵ��������γɵ����д���$p�޷����㣡\n",
"$nһ��֮���ֲ����ף�ֻ��һ�ɴ�����������$p��������\n",
"��ԲȦһ��һת�������糤����ӣ�һ����һ������$n��\n",
"��̫��Բת����ʹ�Ͼ���$n����ס��ֻ����һֻ�����Ѱ�����$p��ǰ��Ѩ�ϣ�\n",
"̫��֮�ƽڽڹᴮ���糤����ӣ����ϲ���������$n��֪���ԣ�\n",
"��ʽ�޿����ܣ��޿ɵ�������$n���̸�·ȫ����$N˫�Ƶ�����֮�£�\n",
"����׾ٽ�$n��ס�������һ�����У���$p���Ӵ���б�ƶ�����\n",
"��Ȧ�����ʵ����ס$n���ͼ�����һ�½�$p������\n",
"˫����һ�Ӵ���̫��֮�����䣬����Ϊʵ����ס��$n��\n",
});

string *super_msg = ({
"һָ����$n���ھ����������������ƿ�֮��",
"�ֱۻ�ת������һ����Ȧ���ƿ�֮����֮�������������ν���",
"����ָ�⣬˳�����ֽ�����ǰһ̽��ָ�Ϸ����ľ�������һ��������ֱ��$n$l",
"���ֽ��󳷣�����˳��һ�ڣ�һ�������ƿն���",
"���ֽ�����ת���ۣ�����һ̽���ƿ���������һ�������ı���",
});


int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	mapping fam  = me->query("family");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("yinyun-ziqi", 1) < 100)
		return notify_fail("�����������򲻹����޷�ѧϰ̫��ȭ��\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("��Ŀǰ������̫�����޷���̫��ȭ��\n");
	if(me->query("taiji_quest") > me->query("taiji_zsf"))
		return notify_fail("����ö�̫��ȭ��������⣬�޷�������ϰ̫��ȭ��\n");
	return 1;
}

string query_skill_name(int level)
{
	if (level < sizeof(taiji_level)-1)
		return taiji_level[level/6];
	else return taiji_level[sizeof(taiji_level)-1];

}

void skill_improved(object me)
{
	int skill = me->query_skill("taiji-quan", 1);

	if(skill == 50 && !me->query("taiji_quest")) me->set("taiji_quest", 1);
	if(skill == 80 && me->query("taiji_zsf") < 2) me->set("taiji_quest", 2);
	if(skill == 110 && me->query("taiji_zsf") < 3) me->set("taiji_quest", 3);
	if(skill == 140 && me->query("taiji_zsf") < 4) me->set("taiji_quest", 4);
	if(skill == 170 && me->query("taiji_zsf") < 5) me->set("taiji_quest", 5);
	if(skill == 200 && me->query("taiji_zsf") < 6) me->set("taiji_quest", 6);
	me->add("shen", me->query("combat_exp")/30);
	if(skill > 100 && random(3) == 1){
		tell_object(me, CYN"��˫�����رȻ�����ȫ����ˮй��ͨ���Է���֮������ʶ������\n"NOR);
		me->improve_skill("parry", skill * me->query_int(), 1);
	}
   if(skill > 350 && me->query("quest/tjq/taiji")=="faild"){
      if(!random(5)) {
           message_vision(HIW"$N������ϰ��̫��ȭ��ͻȻ�뵽��ʦ�������̫���������Խ̻�,�پ����ж�̫������������һ��ǰ��δ�е��¾��磡��\n"NOR, me);
           me->set("quest/tjq/taiji","pass");
       }
      else me->delete("quest/tjq/taiji");
   }
}

mapping query_action(object me, object weapon)
{
	int i, level, force, dodge, parry;
	object ob, victim;
	string msg, type = "����";

	level   = me->query_skill("taiji-quan",1);
	force = 200;
	dodge = random(10);
	parry = random(10);

	if( me->query_temp("tjj/super_hit") )
		return ([
			"action" : HIG"$Nһ�����У����ϱ��У������������ָ��" + super_msg[random(sizeof(super_msg))]+NOR,
			"force" :  500 + random(300),
			"dodge":   level,
			"parry":   level,
			"weapon": random(2)==1?"����":"���ν�",
			"damage_type" : random(2)==1?"����":"����",
		]);

	if( !me->query_temp("tjq/start") && me->query_temp("taiji")){
		me->set_temp("tjq/start", 1);
		msg = CYN"ֻ������$Nʹ��̫��ȭ������ʽ����$P˫���´����ֱ����⣬��ָ΢�棬����ֿ�ƽ�У���������������������ǰ����۰뻷��������Գ����ƣ����Ʒ���������" NOR;
		dodge = parry = 200;
		type = "����";
	}

	else if ( me->query_temp("tj/̫��") || level > 350 ){
		if (random( level) > 400) {
			msg = random(2)==1?"ֻ��$N���鶥�������ذα����������Ρ�����׹�⣬˫�ֱ��˸�̫��ʽ��ԲȦ����������̫�����Ѵ������һ���Ķ������ľ���":
					"ɲʱ��$N����̫��ȭּ�С����ɷ��ɣ���չδչ�������ⲻ�ϡ��ľ�΢����֮����ʹ��һ������������ˮ�������ޱ�";
			level *= 2;
			force += 400;
		}
           else if (level > 450)  {
               msg = WHT + taiji_msg[random(sizeof(taiji_msg))] + NOR;
               force += random(450);
               if( level > 400 ) level = 400;
           }
		else if (level > 300)  {
			msg = taiji_msg[random(sizeof(taiji_msg))];
			force += random(350);

			if( level > 400 ) level = 400;
		}
		else {
			msg = att_msg[random(sizeof(att_msg))];
			force += random(350);
			if( level > 400 ) level = 400;
		}
		dodge += random(me->query_dex(1)/2);
		parry += me->query_con(1)/2;
		type = i != 0?"����":i != 1?"����":"����";
	}
	else {
		i = level > 198?33:level/6;
		msg = att_msg[random(i)];
	}
	ob = me->select_opponent();
	if( objectp(victim = me->query_temp("tjq/zhannian")) ) {
		if( me->query("neili") < 400 || me->query("jingli") < 100 ) {
			tell_object(me, "\n�㷢���Լ��������ӣ�ȭ���ͻ�����մ������ʱ�жϡ�\n");
			me->delete_temp("tjq/zhannian");
		}
		else if( ob == victim && !ob->query_temp("lost_attack") && random(3) == 1) {
			i = random(me->query("int")/3);
			ob->set_temp("lost_attack", i);
			ob->add("jing", -(me->query_int(1)+me->query_con(1) )* 2);
			me->receive_damage("neili", me->query("int"), "����͸֧����");
			me->receive_damage("jingli", me->query("int")/2, "����͸֧����");
			message_vision(RED"\n$n��$N��մ�����������ж��ͻ�����ֱ�޷����У�\n"NOR, me, ob);
			if(wizardp(me) && (string)me->query("env/combat")=="verbose")
				tell_object(me, "Zhannian = "+i+"\n");
		}
	}

	if ( level > 180
	&& random(level) > 120
	&& (me->query_temp("tj/̫��") || level > 350 ))
		return ([
			"action" : msg,
			"force" :  force + random(150),
			"dodge":   dodge,
			"parry":   parry,
			"damage_type" : random(2)==1?"����":"����",
			"post_action": (: taiji :)
		]);

	return ([
		"action" : msg,
		"force" :  force,
		"dodge":   random(30)-10,
		"parry":   random(20),
		"damage_type" : random(2)==1?"����":"����",
	]);
}

int practice_skill(object me)
{
	int i, lvl = me->query_skill("taiji-quan", 1);

	if (lvl < sizeof(taiji_level)-1)
		if (!i = lvl % 6)
			return notify_fail("���̫��ȭ�ġ�"+taiji_level[lvl/6]+"����һ�л�û��ʲô��ʶ����ϰ���ˡ�\n");

	if ((int)me->query("jingli") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������̫��ȭ��\n");

	me->receive_damage("jingli", 40);

	if(me->query_skill("juehu-shou", 1))
		me->receive_damage("neili", me->query_skill("juehu-shou", 1)/5);

	me->receive_damage("neili", 15);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
   int taiji_damage;
   string cur_taiji,next_taiji,taiji_set;

   taiji_set = me->query("env/taiji");

	if( me->query_temp("tjj/super_hit") ) return;
        if(me->query("combat_exp")< victim->query("combat_exp") * 2/3 ) return;
	if ((int)me->query_temp("tjq/taiji")>0) {
	     if( sscanf(taiji_set, "%s|%s", cur_taiji,next_taiji)) {
		if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIW+"�����ֱ���С���ˣ�"+WHT+"��,�㰵����������̫��"+HIW+"������"+WHT+"�־���ʹ�ĳ����뻯��\n"+
					HIW"$n��$N��ôһ����ֻ���ص���ײײ��վ�����ȣ�\n"NOR,me,victim);
                   victim->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
                   victim->add_busy(1+random(2));
			me->set("env/taiji",next_taiji);
			me->add_temp("tjq/taiji",-1);
			return;
		}
		else if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIB+"����������С���ˣ�"+WHT+"��,�㰵������������ȭΪ�ƣ���Ȼ���ص�"+HIB+"������"+WHT+"����$n��ǰ��\n"+
					HIB"$N��һ��ʵ�������������Ϊ���������ڹ���$n��ʱ������ؿ����类һǧ��֮ʯѹ�ȣ���Ϣ��Ҳ�޷����ۣ�\n"NOR,me,victim);
			me->add("neili", -300);
			me->set("env/taiji",next_taiji);
			me->add_temp("tjq/taiji",-1);
                   victim->apply_condition("no_exert",1);
                   victim->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			return;
		}
		else if (cur_taiji == "��" && victim->is_busy()){
			message_vision(WHT"$N�����������"+RED+"����ʮָ��С���ˣ�"+WHT+"��,�㰵���������� ˳��ʹ��̫��"+RED+"���ɡ�"+WHT+"�־���\n"+
					RED"$nһ�����ɡ����������е�һ�ɺ�������ھ�Ϯ����$n���������ס��һ����Ѫ�漴���˳�����\n"NOR,me,victim);
			taiji_damage = (int)me->query_skill("taiji-quan",1)*((int)me->query_con()+(int)me->query_str())/10;
			taiji_damage += random(taiji_damage);
                        if(userp(victim)) taiji_damage = taiji_damage *2 /5; 
			if (wizardp(me))
				write("damage is: "+ taiji_damage +"!\n");
                   victim->receive_damage("qi", taiji_damage*4/5);
			message_vision(damage_msg(taiji_damage, "����")+"( $n"+eff_status_msg((int)victim->query("qi")*100/(int)victim->query("max_qi"))+" )\n",me,victim);
                   victim->receive_wound("qi", taiji_damage*3/5);
                 victim->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			me->add("neili", -800);
			me->add("jingli",-300);
			me->add_temp("tjq/taiji",-1);
			me->set("env/taiji",next_taiji);
			return;
		}
		else if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIR+"������ʹ��С���ˣ�"+WHT+"��,һʽ̫��"+HIR+"���⡹"+WHT+"�־��������ʽ�����ػ���$n��\n"+
					HIR"$nһ�����ֲ��������类һǧ���������У�����ίʵ����!\n"NOR,me,victim);
			taiji_damage = (int)me->query_skill("taiji-quan",1)*((int)me->query_con()+(int)me->query_str())/10;
			taiji_damage = taiji_damage/2 + random(taiji_damage/2);
                     if(userp(victim)) taiji_damage = taiji_damage *2 /5; 
			if (wizardp(me))
				write("damage is: "+ taiji_damage +"!\n");
                   victim->receive_damage("qi", taiji_damage*4/5);
			message_vision(damage_msg(taiji_damage, "����")+"( $n"+eff_status_msg((int)victim->query("qi")*100/(int)victim->query("max_qi"))+" )\n",me,victim);
                   victim->receive_wound("qi", taiji_damage*3/5);
                   victim->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			me->add("neili", -500);
			me->add_temp("tjq/taiji",-1);
			me->set("env/taiji",next_taiji);
			return;
		}
		me->set("env/taiji",next_taiji);
		if ((int)me->query_temp("tjq/taiji")>0)
			me->add_temp("tjq/taiji",-1);
		else
			me->delete_temp("tjq/taiji");
	      }
	     if (!sscanf(taiji_set, "%s|%s", cur_taiji,next_taiji))
			me->delete_temp("tjq/taiji");
	}

	if( (me->query_skill("taiji-quan",1) > 250 && me->query_temp("tj/̫��"))
	|| me->query_skill("taiji-quan", 1) > 350 ){
		message_vision(taiji_hit_msg[random(sizeof(taiji_hit_msg))], me, victim);
		return me->query_int(1);
	}
}

int taiji(object me, object victim, object weapon, int damage)
{
	string str, file;
	int ap, dp, i = 6;

	if( !me->query("env/̫����") && userp(me)) return 0;

	if(!victim
	|| !intp(me->query_temp("tjq/"+victim->query("id")))
	|| !present(victim, environment(me))
	|| !victim->is_character()
	|| !me->is_fighting(victim)
	|| !living(victim)
	|| damage != RESULT_PARRY
	|| me->query_skill_mapped("force") != "yinyun-ziqi"
	|| me->query_skill_mapped("parry") != "taiji-quan")
		return 0;

	ap = COMBAT_D->skill_power(me, "cuff", 1)/100;
	dp = COMBAT_D->skill_power(victim, "parry", 2)/100;

	if( random( ap + dp/2 ) > dp
	&& !victim->query("env/invisibility")){
		if(wizardp(me) && (string)me->query("env/combat")=="verbose")
			tell_object(me, "Your taiji AP: "+ap+"��Target DP: "+dp+"��Your taiji temp��"+me->query_temp("tjq/"+victim->query("id"))+"��\n");
		if(victim->is_busy()) i = 7;
		switch(random(i)){
			case 0: str = "luanhuan"; break;
			case 1: str = "yinyang"; break;
			case 2: str = "dongjing"; break;
			case 3: str = "liangyi"; break;
			case 4: str = "gangrou"; break;
			case 5: str = "zhannian"; break;
			case 6: str = "an"; break;
			default: return 0;
		}

		file = TAIJI->check_force(victim);
		me->set("env/���Ͼ�", file);

		if( !stringp(file = (string)this_object()->perform_action_file(str))
		|| file_size(file + ".c") <= 0
		|| me->query_perform() == taiji_names[str])
			return 0;

		return (int)call_other( file, "main", me, victim);
	}
}

int ob_hit(object ob, object me, int damage)
{
	object weapon;
	string msg;
	int ap, dp, j = 0, skill;
   string taiji_set,cur_taiji,next_taiji;

	if( ob == me->query_temp("tjq/an") && !ob->query_temp("weapon") ) {
		if( me->query("neili") < 1500 || me->query("jingli") < 300 ) {
			tell_object(me, "\n�㷢���Լ��������ӣ�ȭ���ͻ��������־���������ɢ��\n");
			me->delete_temp("tjq/an");
			me->start_perform(1);
			return 1;
		}
		else if( random(me->query_int(1)) * me->query("combat_exp") > (ob->query_int(1) * ob->query("combat_exp"))/2
		&& random(4) ) {
			me->delete_temp("tjq/an");
			me->start_perform(2+random(2), "�����־���");
			msg = HIB"����$N����һ�䣬�����ո�������$n��һ���ù���˫�ƻ����Ƴ����õ���̫��ȭ�е�"HIR"�����־���"HIB"�������ƻ�$n���ƣ�����Ѹ�����𷴹���ֻһգ�ۣ�������$p����֮�ϣ�\n"NOR;
			ap = me->query("jiali") / 10 + me->query_int(1) - ob->query_int(1);
			if( ap < 3 ) ap = 3;
			damage = me->query_skill("taiji-quan", 1) * ap;
                        if(userp(ob)) damage = damage *2 /5;
			ob->receive_damage("qi", damage, me);
			ob->receive_wound("qi", damage/3*2, me);
                     ob->add("jing",-(me->query_int(1)+ me->query_con(1))* 3 );
			me->receive_damage("neili", 1000, "����͸֧����");
			me->receive_damage("jingli", 300, "����͸֧����");
			j = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += damage_msg(damage, "����")+"( $n"+eff_status_msg(j)+" )\n";
			message_vision(msg, me, ob);
			if(wizardp(me) && (string)me->query("env/combat")=="verbose")
				tell_object(me, "An��damage = "+damage+"��Ap = "+ap+"\n");
			return -8000;
		}
	}
	if( me->query_temp("fanzhen")){
		me->delete_temp("fanzhen");
		return 1;
	}

   taiji_set = me->query("env/taiji");

   if ((int)me->query_temp("tjq/taiji") > 0) {
	     if( sscanf(taiji_set, "%s|%s", cur_taiji,next_taiji)) {
		if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIC+"�������ۣ�С���ˣ�"+WHT+"��,�㰵����������̫��"+HIC+"����"+WHT+"�־������׳���\n"+
					HIC"$n����֪����̫�������־�����㱻�Լ���ʽ���ɣ�������ʵ���ᣡ\n"NOR,me,ob);
                   if(userp(ob)) damage = damage /5;
                   ob->receive_damage("qi", damage*4/5);
                   ob->receive_wound("qi", damage/3);
                   me->add("neili", -(int)me->query("max_neili",1)/6);
                   if(me->query("neili")<0) me->set("neili",0);
                   ob->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			me->add("jingli",-300);
			me->add_temp("tjq/taiji",-1);
			message_vision(damage_msg(damage*3/2, "����")+"( $n"+eff_status_msg((int)ob->query("qi")*100/(int)ob->query("max_qi"))+" )\n",me,ob);
			me->set("env/taiji",next_taiji);
			return -damage;
		}
		else if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIG+"�������У�С���ˣ�"+WHT+"��,�㰵����������̫��"+HIG+"���ۡ�"+WHT+"�־����ַ�����\n"+
					HIG"$n�ù���˲��㱻̫�����ۡ��־����⣡\n"NOR,me,ob);
			me->add("neili", -300);
			me->set("env/taiji",next_taiji);
			me->add_temp("tjq/taiji",-1);
			return -damage*2/3;
		}
		else if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIY+"�������ţ�С���ˣ�"+WHT+"��,�㰵����������ʹ�þ���̫��"+HIY+"������"+WHT+"�־���\n"+
					HIY"$nһ������,�㱻������������ʱֻ����Ϣ���ȣ�ȫ������˵���������ܣ�\n"NOR,me,ob);
			me->add("neili", -100);
			me->set("env/taiji",next_taiji);
			ob->apply_condition("no_perform",1);
                     ob->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			me->add_temp("tjq/taiji",-1);
			return 1;
		}
		else if (cur_taiji == "��"){
			message_vision(WHT"$N�����������"+HIM+"���ڼ��أ�С���ˣ�"+WHT+"��,��������ϣ�ʹ��һʽ̫��"+HIM+"������"+WHT+"�־���\n"+
					HIM"$N���о�������$nʹ�������������˾�����ʽ�����±���æ���ң���Ҳ���������ˡ�\n"NOR,me,ob);
			me->add("neili", -500);
			me->set("env/taiji",next_taiji);
			ob->apply_condition("no_fight",2);
                     ob->add("jing",-(me->query_int(1)+ me->query_con(1))* 2 );
			me->add_temp("tjq/taiji",-1);
			return 1;
		}
		me->set("env/taiji",next_taiji);
		if ((int)me->query_temp("tjq/taiji")>0)
			me->add_temp("tjq/taiji",-1);
		else
			me->delete_temp("tjq/taiji");
	      }
	     if (!sscanf(taiji_set, "%s|%s", cur_taiji,next_taiji))
			me->delete_temp("tjq/taiji");
	}

	if (me->query_skill("yinyun-ziqi", 1) < 80
	|| me->query_skill_mapped("force") != "yinyun-ziqi"
	|| me->query_skill_mapped("parry") != "taiji-quan"
	|| me->query("combat_exp") < ob->query("combat_exp")/2
	|| me->query_temp("weapon")) return 0;

	skill = me->query_skill("taiji-quan", 1);

	if ( skill < 80 ) return 0;
	if ( skill < 300 && !me->query_temp("tj/̫��") ) return 0;

	if ( me->query("neili") < ob->query("neili")/5 ) return 0;

	if(objectp(weapon = ob->query_temp("weapon")) ) msg = weapon->query("skill_type");
	else {
		mapping prepare = ob->query_skill_prepare();
		if (!sizeof(prepare)) msg = "unarmed";
		else msg = keys(prepare)[0];
	}

	ap = COMBAT_D->skill_power(ob, msg, SKILL_USAGE_ATTACK) / 1000;
	if ( weapon ) ap *= 2;
	if ( ob->query("neili") > me->query("neili") * 2 ) ap += ap/2;

	dp = COMBAT_D->skill_power(me, "parry", SKILL_USAGE_DEFENSE) / 1000;
	if ( me->is_busy() ) dp /= 2;
	if ( me->query("neili") > ob->query("neili") * 2 ) dp *= 2;
	else if ( me->query("neili") > ob->query("neili") / 2 * 3 ) dp += dp/2;

	if ( random(10) < 3 ) me->set_temp("fanzhen", 1);

	ap = ABS(ap);
	dp = ABS(dp);
	if ( skill > 550 ) dp += random(dp*2);
	if ( skill > 450 ) dp += random(dp/2*3);
	else if ( skill > 350 ) dp += random(dp);

	if ( random(dp) > ap || ( me->query("jiali") < 1 && random( dp * 2 ) > ap ) ) {
		if( me->query("neili") > ob->query("neili") /3*2
		 || ( me->query("jiali") < 1 && me->query("neili") > ob->query("neili")/3 ) ) {
			if( weapon ) msg = "$N����һ������$n��"+weapon->name()+"��˳��һת����������һ�ư���$p���ߣ�\n";
			else msg = "$N����һ������ס$n������˳��һ�ƣ�����������$p�ľ���ȫ��������ȥ��\n";
			ob->receive_damage("qi", damage/2 + ob->query("jiali")*2, me);
			ob->receive_wound("qi", ob->query("jiali")+1, me);
			j = (int)ob->query("qi") * 100 / (int)ob->query("max_qi");
			msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(j)+" )\n";
			j = -3000;
		}
		else {
			if( weapon ) msg = "$N����һת��һ����������ǧ��֮�ɾ������Ŀ���$n�ݽ����"+weapon->name()+"��\n";
			else msg = "$N����һ��������һת����������ǧ��֮�ɾ���$n������ж��һ�ԣ�\n";
			j = -3000;
		}
	}

	else if ( random( dp * 2 ) > ap ) {
		if( weapon ) msg = "$N����һת��һ����������ǧ��֮�ɾ������Ŀ���$n�ݽ����"+weapon->name()+"��\n";
		else {
			msg = parry_msg[random(sizeof(parry_msg))];
			message_vision(msg, ob, me);
		}
		return -3000;
	}
	else if( random( dp * 3 ) > ap ) {
		if( weapon ) msg = "$N�鼱֮�£�������ǧ��һ������$n�ݽ����"+weapon->name()+"֮�ԣ�ж����$pһ���־�����\n";
		else msg = "$N��æ˫��һ�ӣ���������ǧ��֮�ɾ���$n������ж����һ���֣�\n";
		j = -damage/2;
	}
	else if( random( dp * 4 ) > ap ) {
		if( weapon ) msg = "$N�������ǣ��ý�������֮��ʹ����΢�࣬��"+weapon->name()+"�����Լ���\n";
		else msg = "$N��æ�ý�������֮�����ϣ���Ҫж��һ���־�����\n";
		j = -damage/4;
	}
	else return 0;
	message_vision(msg, me, ob);
	return j;
}

int help(object me)
{
	write(WHT"\n̫��ȭ��"NOR"\n");
	write(@HELP
	̫��ȭ��Ϊ��ĩԪ���䵱�����������������ϵ���֮˵��������Ȼ��������
	��죬�Ծ��ƶ����ᷢ���ˣ���Ϊ����֮����ϳ���ѧ��ȭ��ʱ˫��Բת��
	ÿһ�ж�����̫��ʽ�������仯����΢���ʵ�ǿ�������ѧ�д���δ�е�
	����ء�����Ϊ�����鶥�������ذα����������Ρ�����׹�⡹ʮ�����֣�
	�������У���������������һ������·ȭ����Ҫּ��
	̫��ȭ����Ҫ�����ɷ��ɣ���չδչ�������ⲻ�ϣ����������Ϊ����һ����

	Ҫ��	�������ȼ� 100 ���ϣ�
		���� 500 ���ϣ�
		���������״�ȭ�С�
HELP
	);
	return 1;
}
