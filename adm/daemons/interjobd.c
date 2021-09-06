// by spiderii@ty ����JOB����
//#include <mudlib.h>

// remove all killer
void reset_player(object victim, string job_name)
{
	int i, j;
	object *living;
	if (job_name == "xyjob")
	{
		living = filter_array(livings(), "check_xyjob", this_object());
		j = sizeof(living);
		for (i = 0;i < j;i++)
		{
			victim->remove_killer(living[i]);
			living[i]->remove_killer(victim);
		}
		victim->delete_temp("living");
        	victim->clear_conditions_by_type("poison");
 		victim->clear_conditions_by_type("hurt");
 		victim->clear_conditions_by_type("busy");
 		victim->clear_condition("job_busy");
 		victim->delete_temp("apply/short");
	}
	/*if (job_name == "gmdjob")
	{
		living = filter_array(livings(), "check_gmdjob", this_object());
		j = sizeof(living);
		for (i = 0;i < j;i++)
		{
			victim->remove_killer(living[i]);
			living[i]->remove_killer(victim);
		}
		victim->delete_temp("living");
        	victim->clear_conditions_by_type("poison");
 		victim->clear_conditions_by_type("hurt");
 		victim->clear_conditions_by_type("busy");
 		victim->clear_condition("job_busy");
 		victim->delete_temp("apply/short");
	}*/
}

void xyjob_die(object killer, object victim)
{
	int i, kexp, vexp;

	reset_player(victim, "xyjob");

	i = 1;
        vexp = victim->query("combat_exp");
        kexp = killer->query("combat_exp");
        if (vexp >= kexp)
        	i += vexp/kexp;
        else
        {
        	i = 2;
        	i -= kexp/vexp;
        }
        if (i < 0)
        	i = 0;
        if (killer->query_temp("xyjob/xy_defend"))
        {
        	if (victim->query_temp("xyjob/mg_attack"))
        		killer->add_temp("xyjob/defend",i);
        	else
        		killer->add_temp("xyjob/defend",-1);
        }

        else
        {
        	if (victim->query_temp("xyjob/xy_defend"))
        		killer->add_temp("xyjob/attack",i);
        	else
        		killer->add_temp("xyjob/attack",-1);
        }

}
/*
void gmdjob_die(object killer, object victim)
{
	int i, kexp, vexp;

	reset_player(victim, "gmdjob");

	i = 1;
        vexp = victim->query("combat_exp");
        kexp = killer->query("combat_exp");
        if (vexp >= kexp)
        	i += vexp/kexp;
        else
        {
        	i = 2;
        	i -= kexp/vexp;
        }
        if (i < 0)
        	i = 0;
        if (killer->query_temp("gmdjob/mj_defend"))
        {
        	if (victim->query_temp("gmdjob/wg_attack"))
        		killer->add_temp("gmdjob/defend",i);
        	else
        		killer->add_temp("gmdjob/defend",-1);
        }
        else
        {
        	if (victim->query_temp("gmdjob/mj_defend"))
        		killer->add_temp("gmdjob/attack",i);
        	else
        		killer->add_temp("gmdjob/attack",-1);
        }
}
*/
//��������
void special_die(object killer, object victim)
{
	string str;
	object *obj, *users;
	int i, j;

	obj = deep_inventory(victim);
	users = "/cmds/std/xyjob"->player_list();
        j = sizeof(obj);
	for (i = 0;i < j;i ++)
		foreach (object user in users)
			if(obj[i] == user)
				obj[i]->move(environment(killer));
	if (victim->query_temp("xyjob"))
	{
		xyjob_die(killer, victim);
		str = "����������ս��������";
	}
/*
	if (victim->query_temp("gmdjob"))
	{
		gmdjob_die(killer, victim);
		if (victim->query_temp("gmdjob/mj_defend"))
			str = "��������Χ��������ʱ����������";
		else
			str = "��������Χ��������ʱѪս������";
	}
*/
	CHANNEL_D->do_channel(this_object(), "rumor", victim->query("name") + "(" + capitalize(getuid(victim)) + ")" +str);
}

int check_xyjob(object ob)
{
	reset_eval_cost();

	if(!objectp(ob) || !ob->query_temp("special_die") || !ob->query_temp("xyjob"))
		return 0;
	return 1;
}
/*
int check_gmdjob(object ob)
{
	reset_eval_cost();

	if(!objectp(ob) || !ob->query_temp("special_die") || !ob->query_temp("gmdjob"))
		return 0;
	return 1;
}
*/
int job_check(object ob)
{
  if(ob)
   if(wizardp(ob) &&
     (ob->query("id")=="lsxk"||ob->query("id")=="server"||ob->query("id")=="spiderii"||ob->query("id")=="meng ge"||ob->query("id")=="guo jing") &&
     ob->query("xyjob_force") )
          return 1;

	if (!random(35))
        	return 1;
	else
                return 0;
}
