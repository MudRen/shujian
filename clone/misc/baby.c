// /clone/misc/baby.c
// modified by akuma 4:23 PM 4/9/2002

#include <ansi.h>
#include <combat.h>
string status_color(int current, int max);
inherit NPC;
void create()
{
        set_name("����", ({"xiao baobao","baby"}) );
        set("gender", "Ů��");
        set("age", 1);
        set("attitude", "friendly");
        set("long","�Ա�����\n");
        set("combat_exp", 1);
        set("parents", ({"dad","mom"}));
	set("is_baby",1);
	// to allow the identification of baby. by mon.
        setup();
}

void init()
{
	add_action("do_kill",({"kill","fight","hit","steal"}));
	add_action("do_get","get");
	add_action("do_drop","drop");
	add_action("do_shape","qk");
	add_action("do_teach","jiao");
	/* follow is very costly to execute. 5/6/98 mon.
	if(member_array(this_player()->query("id"),
		this_object()->query("parents"))>-1) {
		this_object()->set_leader(this_player());
	}
	*/
}

string query_save_file()
{
	string id;

       id = query("momid");
	if( !stringp(id) ) return 0;
	return sprintf("/data/baby/%c/%s", id[0], id+".c");
}


int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
	//int i;
	//object owner, *enemy;
	int jing,qi,exp;

	exp = (int) query("combat_exp");
	jing = (int) query("max_jing");
	qi = (int) query("max_qi");

	if(!environment()->query("no_death_penalty"))
		set("combat_exp",exp/10 * 9);
	set("eff_qi", qi);
	set("eff_jing", jing);
	set("qi", qi);
	set("jing", jing);

	save();	
	::die();
}

int do_drop(string arg)
{
	object me=this_object(),who=this_player(),env;
	if(!arg) return 0;
	env = environment(who);
	if(present(arg,who)!=me) return 0;
	if(me->move(env)) {
		message_vision("$N��$n�ӻ������������\n",who,me);
		return 1;
	}
	return 0;
}

int do_get(string arg)
{
	object me=this_object(), who=this_player(), env;

	if(!arg) return 0;
	env = environment(who);
	if(present(arg, env)!=me) return 0;
	if( who->query("id") == me->query("momid") || who->query("id") == me->query("popid") ) {
		if(me->move(who)) {
			message_vision("$N��������$n����������§�ڻ��\n",who,me);
		}
		else {
			message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n",who,me);
		}
	}
	else {
		message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
	}
	return 1;
}

int do_kill(string arg)
{       
	object me,who;
	string verb,what,obj;
	if (!arg) return 0;
	verb=query_verb();
	me=this_player();

	if(verb=="steal") {
		if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
		return 0;
	}
	else obj=arg;

	if(!objectp(who=present(obj,environment(me))) || !living(who)) return 0;

	if(who==this_object()) {
		switch(verb) {
			case "kill":
				tell_object(environment(this_object()),
				who->query("name")+"ƴ���ؿ����������������������"+
				me->query("name")+"Ҫɱ�ң����������ѽ��\n");
				break;
			case "hit":
				tell_object(environment(this_object()),
				who->query("name")+"������������������������"+
				me->query("name")+"�۸��ң����������ѽ��\n");
				break;
			case "fight":
				tell_object(environment(this_object()),
				who->query("name")+"�����������������������"+
				me->query("name")+"Ҫ���ҵ��ǳԣ����������ѽ��\n");
				break;
			case "steal":
				tell_object(environment(this_object()),
				who->query("name")+"�����������������������"+
				me->query("name")+"Ҫ͵���ҵ��ǣ�\n");
				break;
			case "beg":
				tell_object(environment(this_object()),
				who->query("name")+"С��һ������������������������"+
				me->query("name")+"Ҫƭ�ҵ��ǳԣ�\n");
				break;
		}
	}
	command(verb);
	return 0;
}

int do_teach(string arg)
{
	object me;
	int gin_cost,amount;
	int myskill, itskill;
	me = this_player();

	if(!myskill = me->query_skill(arg,1)) return notify_fail("���������󻹲����أ�\n");

	if(arg != "unarmed" && arg != "dodge") return notify_fail("��ѧ��������ܵģ�\n");

	itskill = query_skill(arg,1);

	if(myskill <= itskill) return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");

	if((int)me->query("potential")-(int)me->query("learned_points") < 1) return notify_fail("���Ǳ�ܲ�����\n");

	gin_cost =  (int) query_int();

	if((int)me->query("jing") < gin_cost) return notify_fail("����Ȼ̫����û�а취�̣�\n");

	me->receive_damage("jing",gin_cost);
	me->add("potential",-1);
	amount = (int)me->query("int") * (int) query("int");
	message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());

	if( random(30) < query("tol") )
		command("emote �ܲ���Ը�غ���һ����");
	else {
		improve_skill(arg, amount);
		message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n", to_chinese(arg)), this_object());
	}
	return 1;
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
		case "kick":
			command("say �������������"  + ob->query("name") + "����Ү��");
			command("kick " + ob->query("id"));
			break;
		case "slap":
			command("say �������������"  + ob->query("name") + "����Ү����ʹ����������");
			command("slap " + ob->query("id"));
			break;
		case "hit":
			command("pain " + ob->query("id"));
			break;
		case "bite":
			command("face " + ob->query("id"));
			break;  
		case "papaya":
			command("angry");
			break;
	}
}

void relay_whisper(object me, string msg)
{
	if (member_array(me->query("id"), query("parents"))==-1) {
		message_vision((string)this_object()->query("name") + "�ɻ�ؿ���$N��\n", me);
		return;
	}

	//note, do not allow the order contain "chat", "tell"...
	//may need disable more later...
	if( strsrch(msg, "chat") != -1 || strsrch(msg, "tell") != -1 || strsrch(msg, "follow") != -1 ||
		strsrch(msg, "apprentice") != -1 || strsrch(msg, "recruit") != -1 )
		return;
	if (msg) {
		remove_call_out ("relaying");
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying (string msg)
{
	//execute the order.
	command (msg);
}

string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int do_shape(string arg)
{
	mapping my;
	//string shape;
	int at_pt, pa_pt, do_pt;
	my = query_entire_dbase();
	printf(NOR"����������������������������������������������������������������\n"NOR);
	printf("��������%s%5d/ %5d %s(%3d%%)    " NOR " ��Ѫ��%s%5d/ %5d %s(%3d%%)     "NOR"��\n" NOR,
		status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]);		
	printf("�����ף� "HIW"%-13s"NOR"ĸ�ף� "HIC"%-13s"NOR"���飺 "HIR"%-12d"NOR" ��\n",
		my["pop"], my["mom"], my["combat_exp"]);
	printf("�����ǣ� %-13d���ʣ� %-13d��̬�� %-12d ��\n", query_int(), query_con(),query_per());
	printf("���ٶȣ� %-13d������ %-13d���ԣ� %-12d ��\n", query_dex(), query_str(),query_kar());
        printf("�������� %-13d���ԣ� %-32d ��\n", my["obe"], my["tol"]);
	at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
	pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
	do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
	printf("���������� "WHT"%-21d"NOR"�������� "WHT"%-21d"NOR"��\n"NOR, at_pt+1, pa_pt/2+do_pt/2+1);
//	printf("/cmds/skill/skills"->pet_skill(this_object()));
	printf(NOR"����������������������������������������������������������������\n"NOR);
	return 1;
}
