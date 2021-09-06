// skill.c
// From ES2
// Modified by Yu Jue for JY (07/18/98)
// Modified by snowman@SJ 07/04/2001
// added string query_sk_mapped(string skill)
// Modified by augx@sj 8/31/2001

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

string query_user_type();

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;

	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_prepare) ) {
		map_delete(skill_prepare, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;

	if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
	else skill_prepare[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

string query_skill_prepared(string skill)
{
	if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
		return skill_prepare[skill];
	return 0;
}

string query_sk_mapped(string skill)
{
	string *sk;
	int i;

	if( !mapp(skill_map) || !skill || !stringp(skill) ) return 0;
	sk = keys(skill_map);

	for(i = 0; i<sizeof(sk); i++)
		if( skill_map[sk[i]] == skill ) return sk[i];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s;

		s = query_temp("apply/" + skill);

		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
				s += skills[skill_map[skill]];
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

mapping query_skill_prepare()
{
	return skill_prepare;
}

varargs int skill_death_penalty(int mode)
{
	string *sk;
	int i, j;

	if( !mapp(skills) ) return 0;

	if( !mode || mode<2 || mode>6 ) mode = 2;
	sk = keys(skills);

	if (!mapp(learned)) learned = ([ ]);
	for(i = 0; i<sizeof(sk); i++) {
		j = skills[sk[i]] + 1;
		learned[sk[i]] -= (j*j+1) / mode;
		if (learned[sk[i]] < 0) {
			learned[sk[i]] += (j*j+1) / mode;
			j = skills[sk[i]]--;
			learned[sk[i]] += (j*j+1) / mode;
		}
		if (j <= 1) {
			map_delete(skills,sk[i]);
			map_delete(learned,sk[i]);
		}
	}
	skill_map = 0;
	skill_prepare = 0;
	return 1;
}

// Ϊ��ְҵϵͳ������һЩ��� by augx@sj
varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi = 40;
	int lvl = 0;
	object me = this_object();

	//if (!userp(me)) return;
	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if (mapp(skills) &&( SKILL_D(skill)->type() == "martial" || SKILL_D(skill)->type2() == "worker") ) {
		lvl = skills[skill];
		if (lvl*lvl*lvl/10 > me->query("combat_exp")) weak_mode = 2;
	}
	
	//if( !SKILL_D(skill)->valid_learn(me) ) return;//by Ciwei@SJ

	if (!mapp(skills))
		skills = ([]);
	if( !weak_mode )
		if (undefinedp(skills[skill]))
			skills[skill] = 0;

	// Add limit for multi-career system
	if( SKILL_D(skill)->type2() == "worker" ) {
		if ( skills[skill]>=360 ) {
			if ( skills[skill]>=390 ) amount /= 3;
			else if ( skills[skill]>=375 ) amount /= 2;
			else amount = amount * 2/3;
		}
	}

	// Give learning penalty to those learning too much skills.
	if( sizeof(skills) > spi )
		amount /= sizeof(skills) - spi;

	if (amount < 1) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if (learned[skill] > (spi = (skills[skill] + 1) * (skills[skill] + 1))) {
		learned[skill] = spi;
		if (weak_mode > 1) {
			if (!random(5)) tell_object(me,
				HIY "����ʵս���鲻�㣬�谭����ġ�" + to_chinese(skill) + "��������\n" NOR);
		} else if (!weak_mode) {
			// Add limit for multi-career system
			/*
			if( SKILL_D(skill)->type() == "martial" ) {
				if( skills[skill]>=200 && query_user_type()!="martial") {
					tell_object(me, HIY"������Բ��㣬�����������ܵ�������\n"NOR);
					return;
				}
			}			
			else */
			if( SKILL_D(skill)->type2() == "worker" ) {
				/*			
				if( skills[skill]>=200 && query_user_type()!="worker") {
					tell_object(me, HIY"������Բ��㣬�����������ܵ�������\n"NOR);
					return;
				}
				*/
				//if ( skills[skill]>=400 ) {
				//	tell_object(me, HIY"��������Ѿ��޷������ˣ�\n"NOR);
				//	return;
				//}
				if ( (int)me->worker_skill("limit")>2000 ) {
					me->delete_temp("worker_skill_limit");
					tell_object(me, HIY"������Բ��㣬�����������ܵ�������\n"NOR);
					return;
				}
			}
			skills[skill]++;
			learned[skill] = 0;
			tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
			SKILL_D(skill)->skill_improved(this_object());
		}
	}
}

string query_user_type()
{
	int i,j,a,b;
	mapping skl;
	string *sk;

	//if (!userp(this_object())) return "";
	skl = this_object()->query_skills();
	if (!mapp(skl)) return "martial";
	sk = keys(skl);

	j = sizeof(sk);
	a = 0;	
	for(i=0;i<j;i++) {
		if( SKILL_D(sk[i])->type() == "martial" ) {
			if(skl[sk[i]]>a) a = skl[sk[i]];
		}
	}
	b = this_object()->worker_skill("highest");
	if(a<220 && b>220) {
		this_object()->set_temp("user_type","worker");
		return "worker";
	}//worker ������ѧ�����ѶȼӴ�
	if(a>b && a>220){
		this_object()->set_temp("user_type","martial");
		return "martial";
	}//martial ����ֹ�μӹ����Ĳ���Job ����
	return "martial";//��ͨ ������set_temp Ҳ���Ǽ����Բ��빤�������� ����������ѧ���ܵ��ٶȸ� martial һ��
	/*if (a>b) {
		this_object()->set_temp("user_type","martial");
		return "martial";
	}
	else {
		if(b<220) return "martial";
		//this_object()->set_temp("worker_skill_limit",limit);
		//this_object()->set_temp("worker_skill_highest",b);
		this_object()->set_temp("user_type","worker");
		return "worker";
	}*/
}

int worker_skill(string flag)
{
	int i,j,b,limit=0;
	mapping skl;
	string *sk;
		
	skl = this_object()->query_skills();
	if (!mapp(skl)) return 0;
	sk = keys(skl);

	j = sizeof(sk);	
	b = 0;
	for(i=0;i<j;i++) {
		if( SKILL_D(sk[i])->type2() == "worker" ) {
			if(skl[sk[i]]>b) b = skl[sk[i]];
			limit += skl[sk[i]];
		}
	}	
	this_object()->set_temp("worker_skill_limit",limit);
	this_object()->set_temp("worker_skill_highest",b);//��ֹ������Code��ͻ
	if(flag=="limit") return limit;
	if(flag=="highest") return b;
	return 0;
}
