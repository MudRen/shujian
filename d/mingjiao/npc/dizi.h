void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if (interactive(ob) 
	 && userp(ob)
	 && !environment(ob)->query("no_fight")
	 && !present("tieyan ling", ob) 
	 && ob->query("family/family_name") != "����"){
		if( !ob->query_temp("warned") ) {
			command("say ����˭����ô���������������ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 3) 
			ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ�����������Ұ������\n");
			remove_call_out("hiting_ob");
			call_out("hiting_ob", 1, ob);
		}
	}
}

int hiting_ob(object ob)
{
	object me;
	me=this_object();
	if(objectp(ob) 
	&& present(ob, environment(me)) 
	&& !environment(me)->query("no_fight")){
		if ( ob->query_temp("user_type") != "worker" || !random(3))
			me->set_leader(ob);
		ob->kill_ob(me);
		me->fight_ob(ob);
		remove_call_out("moving_ob");
		call_out("moving_ob",1,ob);
	}
	else if(me->query("startroom"))
		me->move(me->query("startroom"));
	else return 0;
}

void moving_ob(object ob)
{
	if (!ob) return;
	if (!living(ob)){
		switch( random(3) ) {
			case 0: command("say �ߣ������Ժ󻹸Ҳ����Ҵ�������������"); break;
			case 1: command("say ��������˴���ɣ�����һ����µġ�"); break;
			case 2: command("nod"); break;
		}
		ob->move("/d/mingjiao/jianyu");
	}
	else {
		remove_call_out("hiting_ob");
		call_out("hiting_ob",1,ob);
	}
}
