// horse.h for horse fainting when riding.

void condition_check()
{
        object ob, me = this_object();
        int my_yq, my_mj;// addjing;

        my_yq  = (int)me->query("jingli");
	my_mj = (int)me->query("eff_jingli");
	//addjing = (my_mj - my_yq)/2;
        //if (addjing < 0) addjing=0;

	if(!living(me)) return;

	if(my_yq <=10) {
        	if (objectp(ob == me->query_temp("is_rided_by"))) {
                       ob->delete_temp("riding_beast");
                       ob->delete_temp("is_riding");
                       message_vision("$Nһͷ��$n������������������������\n", ob, me);
                       ob->receive_wound("qi", 150, "��"+me->name()+"�ϵ�����ˤ");
                }
                me->delete_temp("is_rided_by");
                // modified by aln to let horses follow none after be faint
                me->set_leader(0);
                me->unconcious();
                return;
        }

        if(my_yq <=30 && my_yq > 20){
                if (!random(3))
                say(me->name() +"ֻ�ڴ����������ؿ��ܲ����ˣ�\n");
           	return;
        }

	if(my_yq <= my_mj/3){
                if (!random(3))
                say(me->name() +"��ڴ�ڵش��Ŵ�����\n");
                return;
        }
}

void init()
{
	int my_jing, my_mj, i, addjing;
	object me = this_object();
        object *obs = all_inventory(environment(me));
        object ob = me->query_temp("rided_by");

        if (objectp(ob) && (ob->query_temp("netdead") || !interactive(ob))) {
                   message_vision("$N��$n��һԾ���¡�\n", ob, me);
                   me->delete_temp("rided_by");
                   ob->delete_temp("riding_beast");
                   ob->delete_temp("is_riding");
        }

        if (random(10) > 3 || !living(me))
                return;

        if (!query("horse"))
                set("horse", 1);

        for(i=0; i<sizeof(obs); i++) {
                if (obs[i]->query_temp("riding_beast")!=me) continue;
                if (!objectp(ob) && !random(10) && !me->query_leader()) {
                         me->delete_temp("rided_by");
                         break;
                }
                if (objectp(ob) && (!living(ob) || ob->is_ghost())) {
                         me->delete_temp("rided_by");
                         me->set_leader(0);
                         ob->delete_temp("riding_beast");
                         ob->delete_temp("is_riding");
                         break;
                }
        }

	if (((int)environment(me)->query("grass") > 0
        ||      strsrch(environment(me)->query("short"), "�ݵ�") >= 0
        ||      strsrch(environment(me)->query("short"), "����") >= 0
        ||      strsrch(environment(me)->query("short"), "�ݺ�") >= 0
        ||      strsrch(environment(me)->query("short"), "��԰") >= 0)
        &&      environment(me)->query("outdoors")
        &&     	me->query("food") < (me->max_food_capacity())) {
           	my_jing  = (int)me->query("jingli");
                my_mj = (int)me->query("eff_jingli");
                addjing = (my_mj - my_jing)/2;
                if (addjing < 0) addjing = 0;
           	me->add("food", (int)me->max_food_capacity()/4);
          	me->add("jingli", addjing);
                if (me->query("jingli") > (int)me->query("eff_jingli"))
                         me->set("jingli", me->query("eff_jingli"));
                if (me->query("jingli") + addjing < me->query("eff_jingli"))
                         me->add("jingli", addjing);
                if ((int)environment(me)->query("grass"))
                         environment(me)->add("grass", -1);
                message("vision", me->name() + "����ͷ�ڲݵ��ϳ��������\n", environment(me), me); 
	}
}

