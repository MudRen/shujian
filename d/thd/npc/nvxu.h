int ask_marry()
{
	object nvxu, user;
	object ob = this_player();
	string id;
	int user_load = 0, user_exist = 1;

	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
		command("sneer " + ob->query("id"));
		command("say ��Ҳ��Ȣ���ţ��±��Ӱɣ�");
		return 1;
	}
	if (ob->query("gender") == "Ů��") {
		command("say �㵱��Ů����ͬ�������������");
		return 1;
	}
	if (ob->query("class") == "bonze") {
		command("sneer " + ob->query("id"));
		command("say ����Ҳ���˷��ģ���Ȣ���ţ��Ȼ�����˵�ɣ�");
		return 1;
	}
	if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
		nvxu = load_object("/clone/npc/huang-son-in-law");
	id = nvxu->query("winner");
	if (id) {
		if (id == ob->query("id") && nvxu->query("death_count") == ob->query("death_count")) {
			say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
			return 1;
		}
		if (!(user = find_player(id))) {
			user = new(LOADUSER_OB, id);
			user->set_name("", ({ id }));
			if (!user->restore()) {
				destruct(user);
				user_exist = 0;
			}
			else user_load = 1;
		}
		if (user_exist && nvxu->query("death_count") == user->query("death_count")) {
			command("say СŮ�Ѿ������" + nvxu->query("name") + "�ˡ�");
			if (user_load) destruct(user);
			return 1;
		}
		if (user_load) destruct(user);
	}
	if (ob->query("marry")) {
		command("sneer " + ob->query("id"));
		command("say �㲻���Ѿ�Ȣ��������������޸��ı��ҵ��ˣ��������£��ݹ��Ϸ�����");
		return 1;
	}
	if ((int)ob->query("shen") <= -200000) {
		command("say ����ƽ�����������ˣ����������޶�����аħ���������һ���ߣ�");
		return 1;
	}
	if ((int)ob->query("shen") >= 200000) {
		command("say ����ƽ�����������ˣ������������������Ĺ�������֮ͽ������һ���ߣ�");
		return 1;
	}
	if (ob->query("age") > 49) {
		command("sneer " + ob->query("id"));
		command("say ����ô������ͷҲ������Ů�����ɴ�������Ů�����ˡ�\n");
		return 1;
	}
	if (ob->query("age") < 20) {
		command("say �㻹С���ȳ����������ɡ�\n");
		command("pat " + ob->query("id"));
		return 1;
	}
	command("say �ðɣ�������Ҫ���������⿼���㡣");
	command("say ��һ�����书���ڶ��������ɣ���������Ĭд��");
	command("say �������󶼲�������У�");
	command("say Ҫ��׼�����˾�������һ�ذɣ�");
	ob->set_temp("thd_marry", 1);
	return 1;
}

int ask_test1()
{
	object ob=this_player();
	object me=this_object();

	if (!ob->query_temp("thd_marry")) return 0;
	if (ob->query_temp("thd_marry") > 1) {
		command("say �Ѿ�������ػ�������ʲô��");
		return 1; 
	}
	
	set("combat_exp", 250000);
	set("jiali", 25);
	if (present("dongxiao",me))
		command("unwield xiao");
	prepare_skill("strike");
	prepare_skill("leg");
	prepare_skill("hand");
	prepare_skill("finger");
	prepare_skill("sword");
	me->reset_action();
	prepare_skill("strike", "luoying-zhang");
	say("\n��ҩʦ�ȵ�����һ������Ӣ���ƣ�С�Ľ����ˣ�\n");
	COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
		command("sneer");
		command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
		if (!present("dongxiao",me))
			carry_object("/clone/weapon/sword/dongxiao.c")->wield();
		else
			command("wield xiao");
		prepare_skill("finger");
		me->reset_action();
		prepare_skill("strike", "luoying-zhang");
		prepare_skill("leg", "xuanfeng-tui");
		set("combat_exp", 2000000);
		set("jiali", 100);
		return 1;
	}
	prepare_skill("strike");
	me->reset_action();
	prepare_skill("strike", "luoying-zhang");
	say("\n��ҩʦ�ȵ����ڶ��������｣����С�Ľ����ˣ�\n");
	if (!present("dongxiao",me))
		carry_object("/clone/weapon/sword/dongxiao.c")->wield();
	else
		command("wield xiao");
	COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
		command("sneer");
		command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
		if (!present("dongxiao",me))
			carry_object("/clone/weapon/sword/dongxiao.c")->wield();
		else
			command("wield xiao");
		prepare_skill("finger");
		me->reset_action();
		prepare_skill("strike", "luoying-zhang");
		prepare_skill("leg", "xuanfeng-tui");
		set("combat_exp", 2000000);
		set("jiali", 100);
		return 1;
	}
	if (present("dongxiao",me))
		command("unwield xiao");
	prepare_skill("strike");
	me->reset_action();
	prepare_skill("hand", "lanhua-shou");
	say("\n��ҩʦ�ȵ�����������������Ѩ�֣�С�Ľ����ˣ�\n");
	COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
		command("sneer");
		command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
		if (!present("dongxiao",me))
			carry_object("/clone/weapon/sword/dongxiao.c")->wield();
		else
			command("wield xiao");
		prepare_skill("finger");
		me->reset_action();
		prepare_skill("strike", "luoying-zhang");
		prepare_skill("leg", "xuanfeng-tui");
		set("combat_exp", 2000000);
		set("jiali", 100);
		return 1;
	}
	prepare_skill("hand");
	me->reset_action();
	prepare_skill("finger", "tanzhi-shentong");
	say("\n��ҩʦ�ȵ����������ǵ�ָ��ͨ��С�Ľ����ˣ�\n");
	COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	if (!present("dongxiao",me))
		carry_object("/clone/weapon/sword/dongxiao.c")->wield();
	else
		command("wield xiao");
	prepare_skill("finger");
	me->reset_action();
	prepare_skill("strike", "luoying-zhang");
	prepare_skill("leg", "xuanfeng-tui");
	set("combat_exp", 2000000);
	set("jiali", 100);
	if (!present(ob,environment(me)) || ob->query("qi") <= 0 || ob->query("jing") <= 0 || ob->query("jingli") <= 0) {
		command("sneer");
		command("chat ��˲��ã�Ҳ�����ҵ�Ů������");
		return 1;
	}

	write("��ҩʦ˵�����ðɣ����һ�ؾ�������ˡ�\n");
	write("��ҩʦ˵������Ҫ��׼�����˾������ڶ��ذɣ�\n");
	tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ����һ�ؾ�������ˡ�\n", ({ob}));
	ob->set_temp("thd_marry", 2);
	return 1;
}

int ask_test2()
{
	object ob=this_player();

	if (!ob->query_temp("thd_marry")) return 0;
	if (ob->query_temp("thd_marry") < 2) {
		say("��ҩʦ�ȵ�����ô��������ô����\n");
		return 1; 
	}
	if (ob->query_temp("thd_marry") > 2) {
		command("say �Ѿ�������ػ�������ʲô��");
		return 1; 
	}
	
	command("say ��ν���������˹��̽����⣬����һ����ʲô��");
	return 1;
}

int ask_test3()
{
	object ob=this_player();

	if (!ob->query_temp("thd_marry")) return 0;
	if (ob->query_temp("thd_marry") < 3) {
		say("��ҩʦ�ȵ�����ô��������ô����\n");
		return 1; 
	}
	command("say �����澭�Ե�����֮����������������㣬�ǹ�....���������������ʲô��");
	return 1;
}

int ask_nvxu()
{
	object nvxu, user;
	object ob = this_player();
	string id;
	int user_load = 0;

	if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
		nvxu = load_object("/clone/npc/huang-son-in-law");
	id = nvxu->query("winner");
	if (id == ob->query("id")) {
		if (nvxu->query("death_count") < ob->query("death_count"))
			command("say СŮ������Ȼ���ֹ��С�");
		else
			say(CYN"��ҩʦЦ����" + RANK_D->query_rude(ob) + "�����������������\n"NOR);
	}
	else {
		if (id) {
			if (!(user = find_player(id))) {
				user = new(LOADUSER_OB, id);
				user->set_name("", ({ id }));
				if (!user->restore()) {
					command("say СŮ������Ȼ���ֹ��С�");
					destruct(user);
					return 1;
				}
				user_load = 1;
			}
		}
		if (!id || nvxu->query("death_count") < user->query("death_count"))
			command("say СŮ������Ȼ���ֹ��С�");
		else
			command("say ���Ѱ�СŮ�����" + nvxu->query("name") + "Ϊ���ˡ�");
		if (user_load) destruct(user);
	}
	return 1;
}

int do_answer(string arg)
{
	object ob = this_player();
	object nvxu;
    int payed;

	if (ob->query_temp("thd_marry") == 2) {
		tell_room(environment(ob), ob->name() + "�ڻ�ҩʦ�Ķ���С���ֹ���һ�䡣\n", ({ob}));
		if (arg == "��") {
			if (!present("dongxiao",this_object()))
				carry_object("/clone/weapon/sword/dongxiao.c")->wield();
			command("say ��С�ӣ������������ҵġ��̺�����������\n");
			write("��ҩʦ�ӻ���ȡ��һ֧����ŵ���ߴ�����������·������֮�У�������ӿ�������ƺ�Ҫ������û��\n");
			write("�ٳŵ�һ���㵫������������������\n");
			ob->delete_temp("thd_marry");
			ob->unconcious();
			message("vision", "��ҩʦ������������������������Բ��ѵļһﶪ������ȥ��\n", environment(ob), ob);
			ob->move(__THD__"haibin");
			message("vision","��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n",environment(ob),ob);
			return 1;
		}
		else
			if (arg == "�Ҳ�֪��" || arg == "��֪��" || arg == "dunno") {
				if (!present("dongxiao",this_object()))
					carry_object("/clone/weapon/sword/dongxiao.c")->wield();
				command("sneer " + ob->query("id"));
				command("say �ⶼ�𲻳�����\n");
				write("��ҩʦ�ӻ���ȡ��һ֧����ŵ���ߴ�����������ãȻ��֪����Ϊ�Σ����һ����������\n");
				write("��ҩʦ�ƺ��������Ӱ�죬����һ��Ͳ��ټ����ˡ�\n");
				write("��ҩʦ˵�����ðɣ���ڶ��ؾ����Ǹ�ƽ�֡�\n");
				write("��ҩʦ˵������Ҫ��׼�����˾����������ذɣ�\n");
				tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ���ڶ��ؾ����Ǹ�ƽ�֡�\n", ({ob}));
				ob->set_temp("thd_marry", 3);
				return 1;
			}
		say("��ҩʦŭ�������ԣ�\n");
		return 1;
	}
	if (ob->query_temp("thd_marry") == 3)  {
		say(ob->name() + "�ڻ�ҩʦ�Ķ���С���ֹ���һ�䡣\n");
		if (arg == "��ʤʵ") {
			command("chat* ̧ͷ���죬��˵���������⣬���⣬�����������أ���������֮�������澭���ң���ô�����Ҽ���һ�棿����������������������ô����");
			write("��ҩʦ˵�����ðɣ�������ؾ�������ˡ�\n");
			tell_room(environment(ob), "��ҩʦ��" + ob->name() + "˵�����ðɣ�������ؾ�������ˡ�\n", ({ob}));
			write("��ҩʦЦ���еؿ����㣬�·����ڴ�ʲô��\n");
			write("���ʱ���򣬹��������Ż�ҩʦ���������ؿ�������ͷ��������������������\n");
			tell_room(environment(ob), ob->name() + "���������Ż�ҩʦ���������ؿ�������ͷ��������������������\n", ({ob}));
			command("chat �ӽ�����" + ob->name() + "�����һ�ҩʦ��Ů���ˣ�");
			payed = 0;
			if (!ob->query("benefit/yaoshi") && !payed) {
				write("��ҩʦ˵����С�ֵ��������ҵ�Ů�����Ϸ�����Ϊ�����͸��㽲Щ��ѧ�ĸ������ɡ�\n");
				write("�����Ż�ҩʦ�Ľ��⣬��������֪��һ��ӡ֤����ʱ������������ѧ����\n");
				if (ob->query("family/family_name") == "�һ���")
					ob->add("combat_exp", 18000);
				else
					ob->add("combat_exp", 15000);
				ob->set("benefit/yaoshi", 1);
				payed = 1;
			}
			write("��ҩʦ˵�������Ѿ����ʸ����ѧϰ������Ѩ���ˣ��Ȿͼ���͸��㡣\n");
			new(__THD__"obj/shoufa.c")->move(ob);
//		      write("��ҩʦ˵������һ������ҪǱ����ѧ����һ����������Ұɡ�\n");
			ob->delete_temp("thd_marry");
/*		      ob->update_age();
			ob->set("thd/marry_age", ob->query("age") * 12 + ob->query("month"));*/
			if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
				nvxu = load_object("/clone/npc/huang-son-in-law");
			nvxu->do_copy(nvxu, ob);
			return 1;
		}
		say("��ҩʦŭ�������ԣ�\n");
		return 1;
	}
	return 0;
}

