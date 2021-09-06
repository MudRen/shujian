// mmr.h for hsc job

#include <ansi.h>
void init()
{
        object ob = this_player();
        object me = this_object();

        ::init();

        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
        && ob->query_temp("hs/meetjob"))
        {
	        add_action("do_yes","yes");
        	add_action("do_no","no");
                me->set_temp("apply/attack",  random(30));
                me->set_temp("apply/dodge",  random(50));

                if (!me->query_temp("skillset")) {
			command("look " + ob->query("id"));      
	                command("say " + "��λ" + RANK_D->query_respect(ob) + "�����·�Ȱһ�䣬������¶��ƨ�����ǿ��Ǿ�ˮ������ˮ��\n");
	                command("say " + "��������Ͼ͵�û������������һ���պ��к�(yes/no)��\n");
	                ob->start_busy(2);
	                remove_call_out("dest");
	                call_out("dest",100);
	                remove_call_out("do_clone");
	                call_out("do_clone", 0, me, ob);
                }
                else  {
			command("look " + ob->query("id"));      
			command("say " +"��λ" + RANK_D->query_respect(ob) + "�����·�Ȱһ�䣬������¶��ƨ�����ǿ��Ǿ�ˮ������ˮ��\n");
			command("say " + "��������Ͼ͵�û������������һ���պ��к�(yes/no)��\n");
			ob->start_busy(2);
			remove_call_out("dest");
			call_out("dest",100);
                }
        }
}       

int do_clone(object me, object ob)
{
        mapping killerskill1;
        int number,k_qi,k_neili,k_jing, j, k;
        string t_force,t_dodge;
        number = (int)ob->query("max_pot");
        number = number-100;
        k_qi = (int)ob->query("max_qi") * 2;
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") * 2;
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        killerskill1 = skill2[random(sizeof(skill2))];
        number = (int)(number + random(number/10));

//add log to HS_JOB_LOG

	log_file("job/caihua", sprintf("%8s%-10s�ɻ��������ȼ���%3d�����˵ȼ��� %3d��\n",
		ob->name(1),"("+ob->query("id")+")",number,(int)ob->query("max_pot")-100), ob);

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
        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("combat_exp",ob->query("combat_exp"));
        me->set_temp("skillset",1);
        return 1;
}

void dest()
{
       object me,ob;
       me = this_player();
       ob = this_object();
       write(ob->query("name")+"���������̵ģ�����ûʱ�������������Ģ����ȥ׷С�Ҫ����\n",me); 
       write(ob->query("name")+"һ�����У�����һ�Σ�����׷ȥ��\n",me);
       destruct(this_object());
}


int do_no()
{
        object me, ob;
        ob = this_object();
        me = this_player();

        if ((int)me->query("shen") < 1){
		command("say ��λ"+RANK_D->query_respect(me)+"һ��а����ȴ������װʲô����Ӣ���أ�\n");
		command("grpfight " + me->query("id"));
		me->set_leader(ob);
		ob->set("hsjob2",me);
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, me);
		return 1;
        }
        command("say ��λ"+RANK_D->query_respect(me)+"�������������ǹܶ��ˣ��������ɡ�\n");
        command("grpfight " + me->query("id"));
        me->set_leader(ob);
	ob->set("hsjob2",me);
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me); 
        return 1;
}
   
int do_yes()
{
        object me, ob;
        ob = this_object();
        me = this_player();
        command("say �Թŵ���ʶʱ����Ϊ���ܣ���"+RANK_D->query_respect(me)+"��ȴ������������ǲ�����ˡ�\n");
        command("bye " + me->query("id"));
        tell_room(environment(me), ob->query("name")+"��������׷ȥ��\n", ({ob}));     
        destruct(ob);
        return 1;
}

void die()
{
        object me, ob;
	int exp;
	ob = this_object();
	me = ob->query("hsjob2");
	if ( me != 0 ) {
		if (me->query_temp("hs/meetjob")) {
			exp = 300+random(800);
			message_vision(YEL "��ɱ�˲ɻ���������ɵô��ĵ�����һ�ɺ�����\n",me);
			message_vision(YEL "����ϸ����ղźͲɻ�����Ĵ򶷾����������Լ�����ѧ������������һ�㣡\n",me);
			message_vision(NOR "������"+CHINESE_D->chinese_number(exp)+"�㾭�顣\n",me);
			me->add("combat_exp", exp);
//add log to HS_JOB_LOG
			log_file("job/caihua",sprintf("%8s%-10s�ɻ��������������ֵ%4d��\n",
				me->name(1),"("+me->query("id")+")",exp), me);
		}
	}
        ::die();
}

int accept_fight(object me)
{
        command("say ��ү����Ҫȥ׷�Ǹ�С椣�û��˼���㶯�֡�");
        return 0;
}
