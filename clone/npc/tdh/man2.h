// man2.h
// Creat by Lklv for tdh job

void dest()
{
	object jober;
	if ( stringp(query("��ػ�jober"))
	 && objectp( jober = find_player(query("��ػ�jober")))
	 && jober->query_temp("tdhjob")
	 && jober->query_temp("��ػ�job/get") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s��%4d������ʧ��(2)��ʱ�䣺%4d���־��飺%d��",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/��ػ�")+1, uptime()-jober->query_temp("��ػ�job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("��ػ�job");
		jober->set_temp("��ػ�job/lost", query("name"));
		tell_object(jober, HIY"\n�����㶯��̫����"+this_object()->name()+"Ϊ�����͢׷���������в����ˣ�������ʧ�ܣ�\n"NOR);
	}
	destruct(this_object());
}

int ask_tdh()
{
	object me=this_player();

	if (!me->query_temp("��ػ�job") || !me->query("��ػ�") ) {
		command("oh "+me->query("id"));
		command("say ������˵��ػ�Ķ��Ǻú��ӣ�ֻ����Ե�ύ��");
		return 1;
	}
	command("look "+me->query("id"));
	command("say ���֪������������ʲô�£�");
	return 1;
}

int ask_fq()
{
	string tk, tname, str;
	object me=this_player();
	object ob=this_object();

	tk = me->query("��ػ�/tangkou");
	tname = me->query("��ػ�/title");
	str = me->query_temp("��ػ�job/target_1");

	if ( !me->query_temp("��ػ�job")
	|| !me->query("��ػ�")
	|| query("��ػ�jober") != me->query("id") ) {
		command("fear "+me->query("id"));
		command("say ��Ҫ��˵���ǿ���Ҫ���Դ��ģ�");
		return 1;
	}
	if ( stringp(str)
	&& !stringp(query("have_leader")) ) {
		message_vision(CYN"$N��$n����������ػ�"+tk+tname+me->name()+"������ǰ������������\n"NOR, me, ob);
		command("touch "+me->query("id"));
		command("follow "+me->query("id"));
		set_leader(me);
		set("have_leader", me->query("id"));
		me->set_temp("��ػ�job/get", ob->query("id"));
		me->set_temp("��ػ�job/get_name", ob->name());
		message_vision(CYN"$n��$N������л����Ԯ�֣�����������л���ˡ������ȥ��"+str+"��\n"NOR, me, ob);
		remove_call_out("happen");
		call_out("happen", 1, me, ob);
		return 1;
	}
	command("noshame "+me->query("id"));
	set_leader(me);
	return 1;
}

void init()
{
	object me = this_player();

	::init();

	if ( me->query("tdh_bing2") == this_object()){
		kill_ob(me);
		me->kill_ob(this_object());
	}
	if (interactive(me)
	&& userp(me)
	&& query("��ػ�jober") == me->query("id") ){
		if ( query("have_leader")
		&& !random(4)
		&& stringp(me->query_temp("��ػ�job/3a"))
		&& me->query_temp("��ػ�job/killer") < 7
		&& !(environment(me)->query("no_fight")) ) {
			me->add_busy(1 + random(1));
			remove_call_out("addbing");
			call_out("addbing", 0, me, this_object() );
		}
		else if (!query("miss")) {
			remove_call_out("greeting");
			call_out("greeting", 1, me);
		}
	}
}

void heart_beat()
{
	object me, ob;

	::heart_beat();

	ob = this_object();
	if ( !ob) return;
	if ( ! query("have_leader") || ! query("��ػ�jober")) return;
	if ( !(	me = find_player(query("��ػ�jober"))) || !environment(me) || !environment(ob)) return;
	if ( environment(ob)->query("no_fight") && ! me->query_temp("��ػ�job/get"))
		random_move();
	if ( me->query_temp("��ػ�job/target_2") != query("id")) {
		dest();
		return;
	}
	if ( environment(me) != environment(ob) && ! ob->is_fighting()){
		ob->move(environment(me));
		message_vision("$N������$n�첽���˹�����\n", ob, me);
	}
	if ( environment(me) != environment(ob) && ob->is_fighting()){
		ob->receive_wound("qi", 300);
	}
}

void greeting(object me)
{
	object ob = this_object();

	if (!me || !ob || !present(me, environment(ob)) || query("��ػ�jober") != me->query("id"))
		return;

	set("miss", 1);
	if ( !stringp(me->query_temp("��ػ�job/get")) ) {
		message_vision(HIW"\n$N��Զ����һ�ˣ����ӻ�㱺�"+me->query_temp("��ػ�job/target_1")+"˵�����˺���\n"NOR, me, ob);
		message_vision(CYN"$N����ǰȥ����Ҿ���������ʸ��¿���"+ob->name()+"���� ���˴���������ǡ���\n"NOR, me, ob);
		return;
	}

	command("look "+me->query("id"));
	command("say �����ҵ����ң����������޹ء�");
	return;
}

void happen( object me, object ob )
{
	object target;

	if ( !ob || !me || query("��ػ�jober") != me->query("id"))
		return;

	if ( me->query_temp("��ػ�job/meet") > 0) {
		call_out("addbing", 15, me, ob );
		return;
	}

	if ( me->query_temp("��ػ�job/lost")){
		command("sigh");
		command("bye "+ me->query("id"));
		dest();
		return;
	}

	target = new(__DIR__"bing");
	target->set("��ػ�jober", me->query("id"));
	target->set("tdh_bing2", ob);
	copy_npc(me, target, 110);

	target->move(environment(ob));
	me->add_temp("��ػ�job/meet", 1);
	target->kill_ob(ob);
	ob->kill_ob(target);
	message_vision(CYN"\nһ���ٲ�ģ��������$n����������$n�����ӷ��������㣬��һ�˰ɣ���\n"NOR, target, ob);
	message_vision(CYN"$N�ߵ�����$n����ȥ���ɣ�����\n"NOR, ob, target);
	message_vision(CYN"$Nŭ�������ٸ������շ��������˵���������˵�ձ���$nս����һ��\n"NOR,target, ob);

	remove_call_out("addbing");

	if (query ("have_leader"))
		call_out("addbing", 15, me, ob );
	else
		call_out("addbing", 20, me, ob );
}

void addbing( object me, object ob )
{
	object target;

	if ( !ob || !me || query("��ػ�jober") != me->query("id"))
		return;

	if ( me->query_temp("��ػ�job/lost")){
		command("sigh");
		command("bye "+ me->query("id"));
		dest();
		return;
	}
	if ( me->query_temp("��ػ�job/meet") < 2) {
		target = new(__DIR__"bing");
		target->set("��ػ�jober", me->query("id"));
		copy_npc(me, target, 110);
		target->set("tdh_bing2", ob);
		target->move(environment(me));
		me->add_temp("��ػ�job/meet", 1);
	}
	else {
		call_out("addbing", 20, me, ob );
		return;
	}

	me->add_busy(1 + random(2));
	command("escape "+me->query("id"));
	message_vision(HIR"\nԶ���ɱ���������Ӱ�����ܱ߽У�����ǰ����$N�ڴˣ���ػᷴ�����ߣ�����\n", target);
	message_vision(CYN"$N�е����������շ��������˵���������˵�ձ���$nս����һ��\n"NOR, target, me);
	message_vision(CYN"$Nֱ��$n���˹�ȥ������󺰵�����������������־��ܰɣ���\n"NOR, target, ob);
	target->kill_ob(me);
	return;
}

void kill_ob(object ob)
{
	object me=this_player();

	if (!me) return;

	if (userp(me) && query("have_killer") != me->name()){
//                command("say ��������ӵ��߹�����������Ϊ�������");
//                 command("chat "+me->name()+"��թ�ն񣬾�ȻͶ����͢�������ӵ��߹������С��...");
		set("have_killer", me->name());
		set("job_npc",1);///added by Ciwei
	}
	::kill_ob(ob);
}

void die()
{
	object jober, killer;

	killer = query_temp("last_damage_from");

	if ( objectp(killer) && userp(killer) ){
		killer->add("shen", -DE_LVL* 20);
		killer->set_temp("kill_tdhnpc", this_object()->name());
	}
	if ( stringp(query("��ػ�jober"))
	 && objectp( jober = find_player(query("��ػ�jober")))
	 && jober->query_temp("tdhjob")
	 && jober->query_temp("��ػ�job/get") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s��%4d������ʧ��(4)��ʱ�䣺%4d���־��飺%d��",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/��ػ�")+1, uptime()-jober->query_temp("��ػ�job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("��ػ�job");
		jober->set_temp("��ػ�job/lost", query("name"));
		message_vision(HIY"\n���ˣ�"+this_object()->name()+"����������ʧ�ܣ�\n"NOR, jober);
	}

	command("say ���˹���Ҳ����Ҫ���帴����");
	::die();
}
