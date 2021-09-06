// mmr.h for hs job

int do_clone(object me, object ob);

int count = 0;
void init()
{
	object ling, name1;
	object ob = this_player();
	name1 = ob->query("id");
	ling = present("ling pai");

	::init();
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ling
	&& ling->query_temp("mmr") == name1
	&& ling->query_temp("hsjob") == name1
	&& query_temp("mmr") == name1
	&& ob->query_temp("hs/jobji")
	&& ob->query_temp("hs/have")){
		if (count++) {
			if (count == 10) {
				remove_call_out("kill");
				call_out("dest", 1);
			}
		}
		else {
			set_leader(ob);
			ob->start_busy(2);
			this_object()->start_busy(2);
			if (!query_temp("skillset")) do_clone(this_object(), ob);
			call_out("kill", 1, ob); 
		}
	}
}

void kill(object ob)
{
	command("say ���ܣ���ү����ͳ����㣡����");
	kill_ob(ob);
}

void copy_name(object ob)
{
	mapping name;
	int i;

	i = random(3)+ 1;

	name = RNAME_D->get_random_name(i);

	if (!ob) return;
		
	set_name(name["name"], name["id"]);		
	/*
	if ( ob->query_temp("hs/power")) {		
		message_vision(CYN"\n$N�����������֣����һ�������������������в����գ�"+name["name"]+"��Ҳ��\n"NOR, this_object());
	}
	*/	
}	

void kill_ob(object ob)
{
	if (ob->query("id") != query_temp("mmr")) {
		ob->remove_enemy(this_object());
		ob->remove_killer(this_object());
		this_object()->remove_enemy(ob );
		this_object()->remove_killer(ob );
		tell_object(ob, "�ⲻ�����������Ƶ��ˡ�\n");
		return;
	}
	::kill_ob(ob);
}

//ob->set_temp("done",done);
int do_clone(object me, object ob)
{
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;	
	int done;
		
	done = (int)query_temp("done",1);
	
	set("max_cure",5);
	
	number = (int)ob->query("max_pot");
	number = number-100;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	killerskill1 = skill2[random(sizeof(skill2))];
	number = (int)(number - (random(2)?1:-1)*random(number/10));

	me->set("dex", ob->query("dex")*6/5);
	me->set("str", ob->query("str")*6/5);
	me->set("con", ob->query("con")*6/5);
	
	if(done==0){
		delete("max_cure");//���ָ�
		me->delete("chat_msg");//���ƶ�
		me->set("dex", ob->query("dex")*5/6);
		me->set("str", ob->query("str")*5/6);
		me->set("con", ob->query("con")*5/6);
		me->set("max_qi", ob->query("max_qi")*5/6);
		me->set("max_jing", ob->query("max_jing")*5/6);
		me->set("max_neili", ob->query("max_neili")*5/6);
		number = number*5/6;
		//�ѶȽ���
	}
	
	

	//add log to HS_JOB_LOG
	//      if (userp(ob) && (number > ((int)ob->query("max_pot")-100)))
/*
	if (number > ((int)ob->query("max_pot")-100))
	log_file("job/huashan",sprintf("%8s%-10s��%5d������Ŀ��ȼ�%3d�����˵ȼ�%3d��\n",
		ob->name(1),"("+ob->query("id")+")",ob->query("job_time/��ɽ"),number,ob->query("max_pot")-100),ob);
*/
	/*set killer's skill*/

	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];       
	
	copy_name(me);
	set_name(query("name"),parse_command_id_list()+({ ob->query("id")+"'s mengmian ren"  }) );
	
	if( random(5)==1 && done>=1 ) add_money("gold",random(3)+1)->move(me);
	
	//for robot

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);


	/* set killer's  skill maps */

	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

	/* set killer's skill prepares */

	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

	/* copy entire dbase values */

	me->set("max_qi",k_qi*6/5);
	me->set("eff_qi",k_qi*6/5);
	me->set("qi",k_qi*6/5);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("jing",k_jing);
	me->set("eff_jingli", ob->query("eff_jingli")*3/2);
	me->set("jingli", ob->query("eff_jingli")*3/2);
	me->set("max_neili",k_neili);
	me->set("neili", k_neili);
	me->set("jiali", number/(3+random(4)));
	me->set("combat_exp",ob->query("combat_exp"));

	if ( ob->query("combat_exp", 1) > 2000000)
		me->set("combat_exp", ob->query("combat_exp")* 6/5);

	if ( ob->query("combat_exp", 1) > 2000000 && random(20) == 1)
		me->set("double_attack", 1);

	if(done>=1){
		me->add_temp("apply/attack",  number / 10 + random(number / 10));
		me->set_temp("apply/dodge", 50);
		me->set_temp("apply/armor", 100);
	}
		
	me->set_temp("skillset",1);
	remove_call_out("dest");
	call_out("dest",300);
	return 1;
}

void dest()
{
	if (!living(this_object())) {
		call_out("dest", 10);
		return;
	}
	if (count >= 5) command("say ��үûʱ��������");
	else command("say �����̵ģ�������������»ؿ����ӻ��ĵ����㣡");
	say(name()+"�Ҵ��뿪��\n");
	destruct(this_object());
}

void unconcious()
{
	object me,ob;

	me = this_object();
	ob = query_temp("last_damage_from");
	if (!objectp(ob) || !me) return;
	if ( me->query("cure") < me->query("max_cure")-2 && me->query("combat_exp") > 2500000){
		me->receive_curing("qi", me->query("max_qi"));
		me->receive_curing("jing", me->query("max_jing")/5);
		me->add("qi", me->query("max_qi")/5);
		me->set("jing", me->query("max_jing"));
		ob->kill_ob(me);
		me->add("cure", 1);
		return;
	}
	::unconcious();
}

void die()
{
	object me,ob;

	me = this_object();
	ob = query_temp("last_damage_from");

	if (!objectp(ob) || !me ) return;
	if ( me->query("cure") < me->query("max_cure")-2 && me->query("combat_exp") > 2500000){
		me->receive_curing("qi", me->query("max_qi")/5);
		me->receive_curing("jing", me->query("max_jing"));
		me->set("jing", me->query("max_jing"));
		me->add("qi", me->query("max_qi")/5);
		ob->kill_ob(me);
		me->add("cure", 1);
		return;
	}
	::die();
}

/*
int hit = 0;

int hit_ob(object me, object ob, int damage)
{
	hit+=2;
	if (damage > 800) return (800-damage);
	return 0;
}

int ob_hit(object me, object ob, int damage)
{
	if (!hit) return -damage*8/10;
	hit--;
	return 0;
}
*/
