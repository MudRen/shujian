// char.c
// Modified by snowman@SJ 07/04/10
// added query_temp(apply/xxx)

// Modified by mxzhao 2004/04/28 for add "env/wimpycmd"

#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>
#include <job_mul.h>


inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;
inherit F_LINEUP;

// Use a tick with longer period than heart beat to save cpu's work
nosave int tick;
nosave int save = 15 + random(15);
// static int exp_tick = 1;
// static int exp = 0;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	if (!clonep()) return;
	seteuid(getuid());

	set_heart_beat(1);
	tick = 9 + random(3);
	enable_player();

	CHAR_D->setup_char(this_object());
}

void heart_beat()
{
	int wimpy_ratio, cnd_flag;
	mapping my;
	object ob;

	if (!environment()) return;
	if ((ob = query_temp("link_ob")) && !ob->is_character() && --save == 0) {
		save = 285 + random(30);
		ob->save();
		this_object()->save();
		write(HIG "���������Ѿ��Զ�������ˡ�\n" NOR);
		
	}

	ob = this_object();
	my = query_entire_dbase();
	
	// check user's client type
	if( userp(ob) ) CLIENT_D->CheckStateChange(ob);

	if (my["neili"] < 0) my["neili"] = 0;
	if (my["max_neili"] < 0) my["max_neili"] = 0;
	if (my["combat_exp"] < 0) my["combat_exp"] = 0;
	if (my["potential"] < 0) my["potential"] = 0;
	
	// here is the change.
	if (my["eff_qi"] > my["max_qi"])
		my["eff_qi"] = my["max_qi"];
	if (my["qi"] > my["eff_qi"] + query_temp("apply/qi")) 
		my["qi"] = my["eff_qi"] + query_temp("apply/qi");
/*
	if (userp(ob) && --exp_tick == 0) {
		exp_tick = 300;
		if (exp > 0) {
			exp -= my["combat_exp"];
			if (exp < -800) message("wizard:yuj", sprintf("%s:%d\n", my["id"], -exp), users());
		}
		exp = my["combat_exp"];
	}
*/
	// If we are dying because of mortal wounds?
	
	// and here
	if( (my["eff_qi"] + query_temp("apply/qi")) < 0
	|| (my["eff_jing"] + query_temp("apply/jing")) < 0 ) {
		remove_all_enemy();
		die();
		return;
	}

	// If we're dying or falling unconcious?
	if( my["qi"] < 0 || my["jing"] < 0 || my["jingli"] < 0) {
		remove_all_enemy();
		if( !living(ob) ) die();
		else unconcious();
		return;
	}

	continue_action();

	if (is_busy()) {
		// halt from dazuo, tune, heal ... etc.
		if (query_temp("pending") && is_fighting() && !userp(ob))
			interrupt_me();

		// We don't want heart beat be halt eventually, so return here.
		//	      return; // ����������ػ���� condition �޷����£��������ε���
	} 
	else 
	{
		// Is it time to flee?
		if (is_fighting()
		&& intp(wimpy_ratio = (int)query("env/wimpy"))
		&& wimpy_ratio > 0
		&& (my["qi"] * 100 / (my["max_qi"]+query_temp("apply/qi")) <= wimpy_ratio
		|| my["jing"] * 100 / (my["max_jing"]+query_temp("apply/jing")) <= wimpy_ratio
		|| (my["jingli"]+1) * 100 / (my["eff_jingli"]+query_temp("apply/jingli")+1) <= wimpy_ratio) )
		// Modified by mxzhao 2004/04/28
		{
			int success = 0;
			
			string wimpycmd = query("env/wimpycmd");

			if (stringp(wimpycmd))
			{
				int count = 0;
				foreach (string cmd in explode(wimpycmd, "\\"))
				{
					if (count++ > 4)
					{
						break;
					}

					if (command(process_input(cmd)))
					{
						success++;
					}
				}
			}
			
			if (success == 0)
			{
				GO_CMD->do_flee(ob);
			}
		}
		// End

		// Do attack or clean up enemy if we have fleed.
		attack();
	}

	if( !ob ) return;
	if( !userp(ob) ) {
		ob->chat();
		// chat() may do anything -- include destruct(this_object())
		if (!ob) return;
	}

	if( tick-- ) return;
	tick = 7 + random(5);
	if( userp(ob) ) UPDATE_D->check_inventory(ob);

	if (!is_ghost()) {
		cnd_flag = update_condition();
		if( !ob ) return;
	}

	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P
	if( (cnd_flag & CND_NO_HEAL_UP) || !heal_up());

	if (!interactive(ob)) {
		if (!query_condition("killer") && !is_fighting()
		&& !sizeof(filter_array(all_inventory(environment()), (: interactive :))))
			set_heart_beat(0);
		return;
	}

	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	//       remember how much time has passed since last call.
	ob->update_age();
	
	if (query_idle(ob) > IDLE_TIMEOUT)
	//if (query_idle(ob) > 10)
	{
		//ob->user_dump(DUMP_IDLE);
		call_out("eval_function", 1,(:call_other,ob,"user_dump",DUMP_IDLE:));
	}
}

int visible(object ob)
{
	int lvl, invis;

	if (geteuid() == "spiderii" || geteuid() == "server")
	{
		return 1;
	}

	lvl = wiz_level(this_object());

	if( lvl > wiz_level(ob) ) return 1;
	invis = wizardp(ob)?(int)ob->query("env/invisibility"):!userp(ob)?(int)ob->query("env/invisibility"):0;
	if( intp(invis) && (invis > lvl) ) return 0;

	if ( ob->is_ghost() && !userp(ob) ) return 0;
	return 1;
}

int is_vip()
{
	return query("registered")>=3;
}

int is_robot(int unset)
{
	if(unset)
	{
		delete("iamrobot");
		return 0;
	}
	else
	{
		return (int)query("iamrobot");
	}
}

int add_exp_combat(int iexp,mixed giver,string reason,int no_job,int gift_flag)
{
	int gift_mul,oexp;
	int k,l,m;
	int extra_exp;//���⽱��
	int extra_t;
	int end_time = 1112803200; //7 April 2005
	string site;

	int job_flag = 0;//�ж��ֶ�����ı��

	if(!clonep()) return 0;

	
	if(reason) gift_mul = JOB_GIFT_MUL[reason];
	if(!gift_mul) 
	{
		gift_mul = 100;
		log_file("job/DEBUG",
		sprintf("%s����ͳһ������������\n",
		reason)
		);

	}
	
	if (is_vip())
	{
		oexp = iexp * gift_mul * VIP_MUL /10000;
	}
	else
	{
		oexp = iexp * gift_mul /100;
	}
	
	extra_t = end_time - time();
	if (extra_t > 0 && (site=="sh" || site=="sh2"))
	{
	extra_exp = iexp * (15+random(5))/100;
	add("combat_exp",extra_exp);	
	write(sprintf(HIY"���������%s�㾭��ֵ����ʱ����վ���⽱����������%s��\n",chinese_number(extra_exp),CHINESE_D->chinese_time(extra_t)));
			log_file("static/REDEEM",
				sprintf("%s ��ö��⾭�飺%d reason:%s��\n",query("id"),extra_exp,reason?reason:""));
	}

	/*�������ƺ���*/
	k = uptime()-query_temp("time");
	if(reason=="���ְ�" || reason=="�䵱" || reason=="�ٸ�" || reason=="����" || reason=="��ʧ����"||
		 reason=="��Ħ��" || reason=="��������")
		job_flag = 1;
		
	if (!job_flag && k>0 && (query("combat_exp") > 8000000))
	{
	l = query("combat_exp") - query_temp("combat_exp");
	m = l*3600/k;
	//����ٶ�,�����Ƿ�Ϊ������
		
	  	if (is_robot(0))
		{
			if(m<4000) oexp = oexp;
			else if(m<5000) oexp = oexp * 60/100;
			else if(m<6000) oexp = oexp * 55/100;
			else if(m<7000) oexp = oexp * 50/100;
			else if(m<8000) oexp = oexp * 40/100;
			else oexp =  oexp * 30/100;	
		}
		else
		{
			if(m<6000) oexp = oexp;
			else if(m<7000) oexp = oexp * 85/100;
			else if(m<8000) oexp = oexp * 75/100;
			else if(m<9000) oexp = oexp * 65/100;
			else if(m<10000) oexp = oexp * 55/100;
			else oexp =  oexp * 50/100;	
		}
	}
	if(query("combat_exp")>50000000){
		oexp = oexp * 5/100;
		write("������Լ����������������ѧ���о��Ѿ������˾ٲ�Ω��ĳ̶ȣ��ƺ����ǽ�����˵�ġ�"+HIG+"��ѧ��"+NOR+"����\n");
	}
	/*�������ƺ�������*/
	//runner reward
	if(is_robot(0))
	{
		oexp = oexp * 80 / 100;
	}
	//int reward
	
	if(!no_job)
	{
		add("job_time/"+reason,1);
		GIFT_D->check_count(this_object(),giver,reason,gift_flag);
	}
	if (query_condition("db_exp")>0)
	{
		add("combat_exp", oexp);	
		write(HBGRN+HIG+"��о�����Ӣ֮�������������ã�����ĵõ���"+chinese_number(oexp)+"�㾭��ֵ��\n"+NOR);
	}

	add("combat_exp", oexp);	
	return oexp;
}
/*
this function get the party's status,and return 3 status
garrison 
*/
string party_status()
{
	string family;
	family = query("family/family_name");
	if (family=="�䵱��"||family=="��Ĺ��"||family=="������"||family=="��ɽ��"||family=="������"||family=="������"||family=="ȫ���")
		return "����";
	else if (family=="���ư�"||family=="������"||family=="������"||family=="������"||family=="��ɽ��")	
		return "а��";
	else
		return "������";	
}
