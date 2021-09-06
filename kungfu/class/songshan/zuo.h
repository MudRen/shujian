// zuo.h
// Lklv creat at 2001.10.19

string do_cancel()
{
	object me;
	int exp, i;

	me = this_player();
	exp = me->query("combat_exp");

	if(!me->query_temp("quest") || me->query_temp("quest/family") != "��ɽ��")
		return "��û�������񣬺�������ʲô��";

	me->add("combat_exp",-(20+random(50)));
	if(exp > 500000){
	      me->add("combat_exp",-(30+random(40)));
	}
	i = 40 - me->query_condition("job_busy");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);
	me->delete_temp("songshan_job");
	me->delete_temp("quest");
	return "��Ȼ��ɲ���Ҳû��ϵ����ȥ�̿������ɣ��Ժ�����Ϊ���ǵĲ��ɴ�Ƴ�����";
}

string do_ask()
{
	object me, ob;
	string type, t;
	mapping quest;

	me = this_player();
	ob = this_object();

	if(ob->is_busy()) return "����æ���أ���ȵȡ�";

	if(me->query("combat_exp") > 4000000)
		return "��Ĺ�����ô�ߣ������������ˡ�";

	if( me->query("combat_exp") < 100000
	 || me->query("shen") > -1000)
		return RANK_D->query_respect(ob)+"�ҿ����ֽ�ɢ�����ж��ٻ����ټ��������������ܷ�������ȥ������أ�";

	if( me->query("job_name") == "��ɽ����")
		return "�ţ�����������˼�����ɴ�ƣ������š�";

	if( me->query_temp("quest/id")&& me->query_temp("songshan_job"))
		return "��������ȥ"+HIY+me->query_temp("quest/place")+CYN+me->query_temp("quest/type")+HIG+me->query_temp("quest/name")+CYN+"������ô�������";

	if( me->query_condition("job_busy"))
		return "�ţ�������æ�������š�";

	type = random(2)?"��":"ɱ";

	// get a random npc from TASK_D.
	if(!mapp(quest= TASK_D->get_quest(me, 0, type, "��ɽ��")))
		return "�ţ�����������˼�����ɴ�ƣ������š�";

	me->set_temp("quest", quest);
	me->apply_condition("job_busy", 40);
	t = TASK_D->get_time(quest["time"]);   // get time limit.

	me->set_temp("songshan_job", 1);
	if(type == "ɱ"){
		command("grin");
		command("say �������ˣ��е��ӻر�"HIR+quest["name"]+CYN"���˶�����������֮�����������ô����");
		return "�ٺ٣�����"HIY+quest["place"]+CYN"һ������ȥ����ɱ�ˣ������"+t+CYN"֮ǰ��������ʬ��ϻ�����\n";
	}
	else{
		command("nod");
		command("say ���ˣ�"HIG+quest["name"]+CYN"���ҽ��鲻���������������������֮�¼�ֱ���練�ơ�");
		return "��ʹ�����ȥ"HIY+quest["place"]+CYN"�������������"+t+CYN"֮ǰ�ϻ�����";
	}
}

int accept_object(object who, object ob,object me)
{
       int type,count,exp,pot;
       me=this_object();

       // check job.

       if( who->query_temp("quest/family") != "��ɽ��")
		    return 0;

       type = TASK_D->is_target(ob, who);
       switch (type){
	    case 0: command("say ���ø�"+ob->name()+"���Ҹ��");
		    return 0;
	    case -1:command("say Ү���������㲻ȥ����ɱ�˶���ȥ�ˣ�������");
		    return 0;
	    case -2:command("say �ٺ٣�˭����ȥ��ɱ���ˣ���ֱ�Ǹ�����ɽ��Ĩ�ڣ�");
		    who->apply_condition("job_busy", 9);
		    return 0;
	    case -3:command("say �ţ���ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
		    who->apply_condition("job_busy", 9);
		    return 0;
	    case -4:command("say Ŷ�����Ǹ�ͬ��ͬ�Ե��ˣ�������ù�ɣ�");
		    return 0;
	    default:command("haha");
		    command("say �ã��ã�����²����ǿ�����ӡ�");
		    message_vision("\n$N��$n����һЩ��ѧ�ϵ����ѣ�$n������˼�ص���ͷ��\n",me, who);
		    // give rewards.
		    TASK_D->give_reward(who, who->query_temp("quest"), -1, ABS(me->query("job_time/��ɽ")/100) ,this_object(),"��ɽ" );

	//who->add("job_time/��ɽ", 1);
	//GIFT_D->check_count(who,this_object(),"��ɽ");
	
	who->delete_temp("songshan_job");
	count = who->query("job_time/��ɽ");
	if (count<1) count=1;
	pot= who->query_temp("quest/pot_reward");
	exp= who->query_temp("quest/exp_reward");
	who->delete_temp("quest");

	log_file("job/songshan",sprintf("%8s%-10s��%4d����ɽɱ��������%3d�㾭�飬%2d��Ǳ�ܣ����飺%d\n",
	who->name(),"("+who->query("id")+")",count,exp,pot,who->query("combat_exp")),who);
	who->set("job_name", "��ɽ����");
	who->clear_condition("job_busy");
	call_out("destroy", 1, ob);
	return 1;
	    }
      return 1;
}

void destroy(object ob)
{
	destruct(ob);
}

string do_ask_hb()
{
	object me = this_player();

	if (!me->query("ss/hb_improve"))
		return "ʲô����Ǹ���ѽ����";
	if (random(2)==1)
		return "��������ص���Ҳ���Ǻ������";
	me->set_temp("ss/hb_1",1);
		return "��ŵص����һ��Ͽ�ȸ���������ص���ʵ���벻�����ˡ�";
}

void reset()
{
	object ob;

	if (clonep() && (ob = unew(BINGQI_D("sword/guanri-jian")))) {
		ob->move(this_object());
		command("wield guanri qin");
	}
}

string do_ask_grj()
{
	object me=this_player() , weapon;

	if (me->query("family/master_name") != "������")
		return 0;
	weapon = present("guanri jian", this_object());
	if (!objectp(weapon))
		return "���ս��Ѿ�����ʦ��������,���ڲ��������";
	command("unwield guanri jian");
	command("give guanri jian to " + me->query("id"));
	return "����ս��͸����ˣ����Ҫ���Ʊ��ܺã�";
}

string do_ask_times(object who)
{
	object me = this_player();
	int i;

	if(!intp(i = me->query("job_time/��ɽ")))
		return "�����С�쵰����������ˣ�����ɱ���ˣ���ƭ�ң�";
	message_vision("$N����$n�����룬˵������Ŀǰ�Ѽǹ�" + chinese_number(i) + "�Ρ�\n", who,me);
	return "����ɽ�����ͷ�����������Ŭ���ɣ�";
}
