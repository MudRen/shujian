// by cool 98.6.10
// �ı���caiji@SJ 8/24/2000

void init()
{
        object me, ob;
        string t_name;

        ::init();

        ob = this_player();
        me = this_object();
                if (ob != query("target")) return;
        t_name = ob->query("name");

        if (interactive(ob) && (!(int)ob->query_condition("xx_catch"))
        &&(!(me->query_temp("zuji_target")!=t_name))){
		call_out("dest",1);
	}
        if (interactive(ob)
        && (!me->query_temp("xx_zuji1")||
        !(me->query_temp("zuji_target")!=t_name))){
		set("no_quest", 1);
		me->set_temp("xx_zuji1",  1);
		if (!me->query_temp("zuji_target")) me->set_temp("zuji_target",t_name);
		remove_call_out("dest");
		call_out("dest",300);
		remove_call_out("do_clone");
		call_out("do_clone", 0, me, ob);
		} else {
		command("say ���ܣ��������ҽ�����������\n");
		me->set_leader(ob);
		remove_call_out("dest");
		call_out("dest",300);
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
		}

}
int do_clone(object me, object ob)
{
	mapping killerskill1;

	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;
	number = (int)ob->query("max_pot");
	number = number-100;
        k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili");

/*set killer's level*/
	if(ob->query("combat_exp")>2000000){
		killerskill1=skill2[random(sizeof(skill2))];
		number=(int)(number*(8)/10);
	}
	else if (ob->query("combat_exp")>800000){
		killerskill1 = skill2[random(sizeof(skill2))];
		number = (int)(number*(7+random(2))/10);
	}
	else if (ob->query("combat_exp")<800000&&ob->query("combat_exp") > 600000) {
		killerskill1 = skill2[random(sizeof(skill2))];
		number = (int)(number*(6+random(2))/10) ;
	}
	else if (ob->query("combat_exp")<600000&&ob->query("combat_exp") > 400000) {
		killerskill1 = skill2[random(sizeof(skill2))];
		number = (int)(number*(5+random(3))/10) ;
	}
	else if (ob->query("combat_exp")<400000&&ob->query("combat_exp") > 200000) {
		killerskill1 = skill1[random(sizeof(skill1))];
		number = (int)(number*(4+random(4))/10) ;
	}
	else if (ob->query("combat_exp")<200000) {
		killerskill1 = skill1[random(sizeof(skill1))];
		number = (int)(number*(4+random(3))/10) ;
	}

// if (number>200) number = 200;

	/*set killer's skill*/
	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];

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
	me->set("max_qi",k_qi*4/5);
	me->set("eff_qi",k_qi*4/5);
	me->set("qi",k_qi*4/5);
	me->set("max_jing",k_jing*4/5);
	me->set("eff_jing",k_jing*4/5);
	me->set("jing",k_jing*4/5);
	me->set("max_neili",k_neili*3/5);
	me->set("neili",k_neili*3/5);
	me->set("jiali",10);

	me->set("combat_exp",ob->query("combat_exp"));
	me->set_temp("skill_set",1);
	ob->set_temp("xx_zuji",1);
	me->set_leader(ob);
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, ob);
	return 1;
}

void dest()
{
	object me,ob;
	ob = this_player();
	me = this_object();

	write(me->query("name")+"���������������\n",me);
	write(me->query("name")+"�Ҵ��뿪��\n",me);
	destruct(me);
}

void dest2()
{
        object me,ob;
	ob = this_player();
	me = this_object();

	write(me->query("name")+"�������ù���һ�㲻��ʮ�壬�һ������ģ�\n",me);
	write(me->query("name")+"�Ҵ��뿪��\n",me);
	ob->delete_temp("songxin_zuji");

	destruct(me);
}
void dest3()
{
	object me;
	me = this_object();

	write(me->query("name")+"��Ц������������ˣ�\n",me);
	write(me->query("name")+"�Ҵ��뿪��\n",me);
	destruct(me);
}
