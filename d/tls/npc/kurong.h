int ask_xingyue(object who)
{
	object me,ob;
	mapping myfam;

	me=this_player();

	myfam = me->query("family");
	if (!myfam || myfam["family_name"] != "������") {
		command("knock "+(string)me->query("id"));
		command("say ������ɵ��ӣ�Ҳ�������ĳ���!\n");
		return 1;
	}
	if (me->query_skill("buddhism", 1) < 180){
		command("pat "+(string)me->query("id"));
		command("say ��ķ𷨻��辫��������������Ŀǰ�ǲ��ʺ����!\n");
		return 1;
	}
	command("nod "+(string)me->query("id"));
	ob=present("xingyue puti",this_object());
	if(ob){
		ob->move(me);
		command("say ����ô�ڷ����У��������������������!\n");
	} else
		command("say ����ô�ڷ����У���������ϧ���Ѿ������͸����ʦ�ֵ��ˡ�\n");
	return 1;
}

void attempt_apprentice(object ob)
{
	string old_name,new_name;
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if (!myfam) return;
	if (myfam["family_name"] != "������") {
		command ("say �㲻�������µ��ӣ��⻰�Ӻ�˵��\n");
		return;
	}
	if((int)ob->query_skill("buddhism",1)<140){
		command("say �Ҷμ��书���ѧϢϢ��أ��ҿ�"+RANK_D->query_respect(ob)+"��������Ϊ�ƺ�������");
		return;
	}
	if((int)ob->query_skill("yiyang-zhi",1)<160){
		command("say ���������书����һ��ָ���ҿ�"+RANK_D->query_respect(ob)+"�ƺ�Ӧ��һ��ָ�϶��µ㹦��");
		return;
	}
	if((int)ob->query_skill("qiantian-yiyang",1)<160) {
		command("say ����һ��ָ�ڹ���Ϊ��Ҫ���ҿ�"+RANK_D->query_respect(ob)+"�ƺ�Ӧ��Ǭ��һ�����϶��µ㹦��");
		return;
	}
	if(!(ob->query("tls")) && !(ob->query_temp("tls_app"))){
		command("say �����ӷ���ذɣ�ƶɮ�������ճ��ҵ��ӡ�");
		return;
	}
	if(ob->query("tls")&&((int)ob->query("shen") > 1000 || (int)ob->query("shen")+1000 <0 )){
		command("say ��������������֮�أ����ҿ�"+RANK_D->query_respect(ob)+"�ƺ��쳾δ��,���˼������С�");
		return;
	}

	command("smile");
	old_name = ob->query("name");
	if (ob->query("tls") && (string)ob->query("class") =="bonze"){
        	new_name="��"+old_name[2..3];
	}
	else{
		new_name="��"+old_name[0..1];
	}
	if (!ob->query("tls") || (string)ob->query("class")!="bonze"){
		command("say ƶɮֻ�ճ��ҵ��ӣ�������ɮ������ȡ�");
		message_vision("$N˫�ֺ�ʲ�������: \n",ob);
		message_vision("���Ÿ�����  ���н�����  ������ֹˮ  ����ȸ��� \n",ob);
		message_vision("���ӹ�����  ����������  ��Ϊ������  ��ȥ����Ѳ \n",ob);
		message_vision("�����Ը  Ը�˼�����  ֻ�ܹ�ȥ��  ����δ���� \n",ob);
		message_vision("�����ǻ�ˮ  ��ϴ���ճ�  ����������  �ٽᷳ�Ǹ� \n",ob);
		message_vision("������ʦ���һֻƤ����ͷ��������"+ob->query("name")+"��ͷ��һ������ʱͷ�����䡣\n",ob);
	}
	ob->set("name",new_name);
	ob->set("class","bonze");
	ob->set("tls",1);
	command("chat ������������"+new_name);
	command("recruit " + ob->query("id") );
	command("chat ��������!");
	command("chat ���������ҵ�һ���ɴ��²�֮��,���ǿ�ϲ�ɺ�!");
	return;
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "bonze");
}

int ask_dudan(object who)
{
	object me,ob_dan;
	mapping myfam;
	me=this_player();
	myfam = (mapping)me->query("family");
	if (!myfam || myfam["family_name"] != "������") {
		command("slap "+(string)me->query("id"));
		command("say ������ɵ��ӣ�Ҳ�������ĳ���!\n");
		return 1;
	}
        if (me->query_skill("kurong-changong", 1) < 200){
		command("pat "+(string)me->query("id"));
		command("say ��Ŀ������������������ⶾ�����ǲ��ܸ���Ե�!\n");
		return 1;
	}
	if((int)me->query("dudan_given") < (int)(me->query_skill("kurong-changong", 1)/10)) {
		command("nod "+(string)me->query("id"));
		me->add("dudan_given",1);
		ob_dan = new("/d/tls/npc/obj/dudan");
		ob_dan->move(me);
		message_vision("$N���һ�Ŷ�����\n",this_player());
		command("say ����һ�Ŷ��������Ƕ�������������������Ϊ���棬����ô�ڷ��������������!\n");
		return 1;
	}
	else  {
		command("say �����ڻ��Ǻú������������������뿿ҩ�������ǿ��ǲ���! \n");
		return 1;
	}
}

string ask_liumai2()
{
        object me,ob,*thing;
	mapping myfam;
	int i;
	ob=this_player();
	me=this_object();

	myfam = (mapping)ob->query("family");

	if (myfam["family_name"] != "������"||!ob->query("tls")||ob->query("class") != "bonze"){
		return "�Բ����Ҳ�֪����\n";

	}
   if (ob->query("liumai_pass") && (ob->query_skill("liumai-shenjian",1) < 181)) {
		command ("nod "+ ob->query("id"));
		message_vision("���ٳ���һ�������ȥ������Ȼ�ƿ�һ��ʯ�ţ�$N��Ҳ���������˹�ȥ��\n", ob);
		thing = deep_inventory(ob);
		i = sizeof(thing);
		while (i--)
		if (thing[i]->is_character()) {
			message_vision("���ٳ���ͻȻ����һ������������ô�����˽�������\n", ob);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, me);
			return " ";
		}
		ob->move("/d/tls/pyd");
		return "";
	}
	if( ob->query_skill("yiyang-zhi",1) < 180 )
		return "���һ��ָ��������ô�������ȥ�ú�����!!\n";
	if (ob->query("max_neili") < 4500)
		return "���������������ô�������ȥ�ú�����!!\n";
	if (ob->query_skill("force", 1) < 200)
		return "����ڹ���������ô�������ȥ�ú�����!!\n";
	if (ob->query_temp("try_fight"))
		return "�㲻�����ڽ��ҵ�����!\n";
	if (ob->query_temp("try"))
		return "�����׼�����ˣ���ȷ��(try)�� \n";
	if (me->query_temp("try"))
		return "�Բ���������������׼������. \n";
	if (me->query_temp("try_fight"))
		return "�Բ�����������æ�ţ�����ʲôҪ��һ�����˵. \n";
        if (ob->query_skill("liumai-shenjian",1) > 180){
		ob->set("quest/�����˲�/�书/liumai_update",1);
		return "�����������Ϊ�Ѿ��Ƿ��켶����������Ҳ���ܸ���ʲô�����ˣ�\n"+
			"��ȥ�����������Ӷ����ɣ�Ҳ�����ܸ���Щ������";
	}
	else {
		command("say �������������ϴ��¹�أ�" + RANK_D->query_respect(ob) + "����������ʮ�в������裬�Ź��ʸ�����ƶ���ϰ�����񽣡�");
		ob->set_temp("try",1);
		me->set_temp("try",1);
		call_out("wait", 1, me, 0);
		return "�����׼�����˽��У���ȷ����try)��\n";
	}
}

void init()
{
	object me;
	me = this_player();
	::init();
	if (interactive(me) && living(me)) {
	 	if(me->query(QUESTDIR2+"start")&& !me->query(QUESTDIR2+"over"))
    {
    	command("look "+me->query("id"));
    	command("touch "+me->query("id"));
    	command("say ����λ������æ�����µ��ɸ��������ˡ�"); 
    }
	} 
	add_action("do_yes", "try");
	add_action("do_kill", "kill");
	add_action("do_kill", "tk");
	add_action("do_kill", "teamkill");
	add_action("do_kill", "hit");
}

int do_kill(string arg)
{
	object ob,ob2;
	object me = this_player();
	ob2 = this_object();

	if (!arg) return 0;
	ob = present(arg, environment(me));

	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;

	if (ob->query("family/family_name") == "������") {
		if (me->query("family/family_name") == "������") {
			message_vision(ob2->name()+"��$N�����ȵ��������˽�ɱ������ô���Լ���ͬ�Ŷ�ɱ����\n", me);
		}
		else {
			message_vision(ob2->name()+"��$N�����ȵ����󵨿�ͽ����Ȼ�����������ף�\n", me);
			kill_ob(me);
		}
		me->set("vendetta/������", 1);
		return 1;
	}
	return 0;
}

int do_yes()
{
	object me,ob,room;
	ob = this_player();
	me = this_object();

	if( !ob->query_temp("try")) return 0;

	message_vision("$N����һ��������˵�������롱��\n",ob );
	set("max_jing",3000);
	set("jing",3000);
	set("eff_jingli",3000);
	set("max_qi",5000);
	set("qi",5000);
	set("jiali",100);
	set("neili",8000);
	set("max_neili",8000);
	command("yun rong");
	if(!( room = find_object("/d/tls/lsy" )) )
		room = load_object("/d/tls/lsy");
	room->delete("exits");
	ob->delete_temp("try");
	me->delete_temp("try");
	me->set_temp("try_fight",1);
	ob->set_temp("try_fight",1);
	call_out("fighting",  3, me, ob, 0);
	message_vision("���ٴ�ʦ˫�ƺ�ʲ������һҾ�����������ĵ�������ָ�̡���\n",ob);
	return 1;
}

void waiting(object me, int wait_time)
{
	object fighter;

	if( wait_time >= 150 ) {
		say( "���ٴ�ʦ˵���������㲻�������ʮ���ˣ�\n\n");
		call_out("do_recover", 0, me);
		return;
	}
	if( !objectp( fighter = present( me->query_temp("fight"), environment(me) ) ) ){
		call_out("waiting", 1, me, wait_time + 1);
		return;
	}
}

void fighting(object me, object fighter, int count)
{
	object room;

	if (!fighter || !living(fighter) || environment(fighter)!=environment(me)) {
		if(!( room = find_object("/d/tls/lsy" )) )
                room = load_object("/d/tls/lsy");
		if( objectp(fighter)) {
			fighter->delete_temp("try_fight");
			fighter->delete_temp("beat_count");
		}
		me->delete_temp("try_fight");
		room->set("exits/out","/d/tls/songlin-1");
                command("chat* ҡ��ҡͷ��˵�����벻��... ����");
		command("sigh");
		return;
	}
	else if (count <10) {
		if (interactive(fighter) && fighter->query_temp("try_fight") && living(fighter))
	 		COMBAT_D->do_attack(this_object(), fighter, query_temp("weapon"), random(2)?1:2);
	 	count++;
		call_out("fighting", 2, me, fighter, count);
	}
	else call_out("do_congra", 3, me, fighter);
}

void do_congra(object me, object fighter)
{
	int i;
	object room,*thing;

	if(!( room = find_object("/d/tls/lsy" )) )
		room = load_object("/d/tls/lsy");
	fighter->delete_temp("try_fight");
	fighter->set("liumai_pass",1);
	me->delete_temp("try_fight");
	command("smile");
        command("say ��ϲ����ϲ���㼼���������ʤ������������ϰ������������,��ȥ�ɡ�\n");
	room->set("exits/out","/d/tls/songlin-1");
	message_vision(HIY"\n���ٳ���һ�������ȥ������Ȼ�ƿ�һ��ʯ�ţ�$N��Ҳ���������˹�ȥ��\n"NOR,fighter);

        thing = deep_inventory(fighter);
	i = sizeof(thing);
	while (i--)
	if (thing[i]->is_character()) {
		message_vision("���ٳ���ͻȻ����һ������������ô�����˽�������\n", fighter);
		me->set_leader(fighter);
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, me);
		return;
	}
	fighter->move("/d/tls/pyd");
	return;
}
