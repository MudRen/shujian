// miejue.h
// ��������
// Lklv 2001.10.18 update

int ask_jiuyin()
{
	object me=this_player();
	object book;

        mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "������" ) {
		message_vision("���ʦ̫��м�ؿ���$Nһ�ۣ�һ��������������ӡ�\n", me);
		return 1;}



	if( !me->query("jiuyin/emei") || present("jiuyin sucheng", me) ) {
		command("?");
		command("crazy");
		return 1;
	}
	book = unew("/d/emei/obj/emei-jiuyin");
	if( !clonep(book) ) {
		command("?");
		return 1;
	}
	book->set("owner", me->query("id"));
	book->move(me);
	command("say �ðɣ������ȥ�ɡ�\n");
	message_vision("���ʦ̫��$Nһ������澭�ٳ�ƪ���ֳ�����\n",me);
	return 1;
}

void attempt_apprentice(object ob)
{
	string *prename = ({ "��", "��" });
	string name, new_name;
	if ((string)ob->query("gender") != "Ů��" ){
		command ("say ���������������е��ӣ��������ң�");
		return;
	}
	if ((string)ob->query("class")!="bonze" ){
		command ("say �����ӷ������Ҳ����׼ҵ��ӡ�");
		return;
	}
	if ((int)ob->query_skill("linji-zhuang", 1) < 120 ){
		command("say �����Ҳ�����������֮�ˣ��㻹�Ƕ���������ټ�ʮ��ׯ�ɡ�");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 100 ){
		command("say �����Ҳ�����������֮�ˣ��㻹�Ƕ�������Ļ����ڹ��ɡ�");
		return;
	}
	if ((int)ob->query("shen") < 0){
		command("say �������ϲ���ľ����׶�֮ͽ��");
		return;
	}

	name = ob->query("name");
	new_name = prename[random(sizeof(prename))] + name[2..3];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("say �����ӷ����գ����գ�");
	command("smile");
	command("recruit " + ob->query("id"));
	ob->set("name", new_name);
	ob->set("title", "�����ɵ��Ĵ�����");
}

void kill_ob(object me)
{
	command("sneer " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command("say ��̾������ϧ���Ƕ���������δѡ����˭Ҫ�����ҵ�..������.��..���ܵ���..");
	::unconcious();
}

int pass_yitian(object me, object ob)
{
	COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 1);
	if (!present(me,environment(ob))
	 || me->query("qi") <= 0
	 || me->query("jing") <= 0
	 || me->query("jingli") <= 0)  {
		command("sneer");
		command("say ��˲��ã�Ҳ������콣�����⣿��");
		ob->set("max_qi", 2000);
		ob->set("max_jing", 2000);
		ob->set("neili", 2000);
		ob->set("max_neili", 2000);
		ob->set("jiali", 100);
		ob->set("combat_exp", 1200000);
		if (present("yitian jian",ob))
			destruct(present("yitian jian", ob));
		ob->carry_object(BINGQI_D("changjian"))->wield();
		return 0;
	}
	return 1;
}

int ask_sword()
{
	mapping fam;
	object me, ob, tmp;
	int i,p =0;

	me = this_player();
	ob = this_object();
	fam = me->query("family");

	if (present("yitian jian", me)) {
		command("say �����ϲ��������콣��ô����ô�����ң�");
		command("sneer " + me->query("id"));
		command("consider " + me->query("id"));
		return 1;
	}
	if (me->query_temp("marks/pass_yitian")) {
		command("say ����˵��ô�������ŵ���ָ�����������콣�Ϳɸ������á�");
		return 1;
	}
	if (ob->is_busy()) {
		command("nonsense miejue shitai");
		command("nonsense");
		return 1;
	}
	if( ob->is_fighting() ) {
		command("nonsense miejue shitai");
		command("nonsense");
		return 1;
    	}
        if( me->query("age") < 14
	 || (int)me->query("combat_exp", 1) < 500000 ) {
		command("say ������Ҳ������콣��ע�⣿");
		ob->kill_ob(me);
		me->kill_ob(ob);
		return 1;
	}
	tmp = unew(BINGQI_D("sword/yitian-jian"));
	if (!objectp(tmp)) {
		command("say ���콣���Ѿ������ˡ�");
		return 1;
	}
	else destruct(tmp);
	command("say �����������������£����첻����˭�����棬����������");
	set("combat_exp", 4000000);
	set("max_qi", 6000);
	set("eff_jingli", 4000);
	set("eff_jing", 3000);
	set("qi", 6000);
	set("max_neili", 9000);
	set("neili", 12000);
	set("jingli", 4000);
	set("jing", 3000);
	set("jiali", 100);
	if (present("changjian", ob)) {
		command("unwield changjian");
		destruct(present("changjian", ob));
	}
	if (!present("yitian jian", ob)) {
		carry_object(BINGQI_D("sword/yitian-jian"))->wield();
	}
	prepare_skill("strike");
	prepare_skill("sword");
	ob->reset_action();
	prepare_skill("strike", "sixiang-zhang");

	command("say �ðɣ���Ȼ��õ����콣����ô�ͽ����Ἰ�С�\n");
	command("grin " + me->name());

	if (fam && me->query("family/family_name") == "������") p = 5;
	for ( i = 0; i < (8 - p);i++){
		pass_yitian(me, ob);
	}
	if ( fam && me->query("family/family_name") == "������") {
		command("say �ðɣ��������ָ�����������콣�Ϳɸ������á�\n");
		tell_room(environment(me), "���ʦ̫��" + me->name() + "˵�����ðɣ�������ŵ���ָ�����������콣�Ϳɸ������á�\n", ({me}));
		me->set_temp("marks/pass_yitian", 1);
		ob->set("max_qi", 2000);
		ob->set("max_jing", 2000);
		ob->set("neili", 2000);
		ob->set("max_neili", 2000);
		ob->set("jiali", 30);
		ob->set("combat_exp", 1200000);
		if (present("yitian jian",ob))
			destruct(present("yitian jian", ob));
		carry_object(BINGQI_D("changjian"))->wield();
		return 1;
	}
	else {
		command("say �����㿹ס����ʮ��Ҳ���У��������ɡ�");
		if (!present("changjian",ob))
			carry_object(BINGQI_D("changjian"))->wield();
		else
			command("wield changjian");
		prepare_skill("strike");
		prepare_skill("sword");
		ob->reset_action();
		ob->set("combat_exp", 2200000);
		ob->set("jiali", 100);
		ob->kill_ob(me);
		me->kill_ob(ob);
		return 1;
	}
	return 1;
}

int accept_object(object who, object ob)
{
	object sword, me;
	mapping fam;
	me = this_object();
	if( !who || environment(who) != environment() ) return 0;
	if( !objectp(ob) ) return 0;
	if( !present(ob, who) ) return notify_fail("��û�����������");

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "������" ) {
		command("thank "+ (string)who->query("id"));
		command("say ���뱾��������������֪Ϊ������˺���? \n");
//		remove_call_out("destroying");
//		call_out("destroying", 1, this_object(), ob);
		return 0;
	}

	if( (string)ob->query("id") == "zhi huan") {
		if( !(who->query_temp("marks/pass_yitian")) ) {
			command("say ��Ҳ�������콣��\n");
			return 0;
		}
		if( !(who->query_temp("marks/get_ring")) ) {
			command("say ����ָ������������ô��\n");
			return 0;
		}
		sword = unew(BINGQI_D("sword/yitian-jian"));
		if( !objectp(sword) ) {
			command("say �������Ϻ�Ϳ�ˣ�����֪�����ˡ�\n");
/*			if (!who->query("emei/jianjue") && who->query_temp("emei/jianjue")) {
				command("say ��Ȼ��ˣ��Ҿͽ̵�����ҵĽ������ˡ�");
				who->set("emei/jianjue",1);
			}
*/
			return 0;
		}
		sword->move(who);
		who->delete_temp("marks/get_ring");
		who->delete_temp("marks/pass_yitian");
		command("say ��������⽣Ϊ���������ұ�ȡ������!\n");
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), ob);
		return 1;
	} else return 0;

	return 1;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int ask_guo()
{
	object me=this_player();

mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "������" ) {
		message_vision("���ʦ̫��м�ؿ���$Nһ�ۣ�һ��������������ӡ�\n", me);
		return 1;}

	if( !me->query_skill("jiuyin-baiguzhua", 1) || !me->query("quest/jiuyin2/emei")) {
		message_vision("���ʦ̫��м�ؿ���$Nһ�ۣ�һ��������������ӡ�\n", me);
		return 1;
	}
	if( me->query("shen") < -10000 ) {
		command("say ����һ��а�������Ҵ��������������ţ�\n");
		command("consider "+ me->query("id"));
		return 1;
	}

        if( me->query("combat_exp") < 1000000 ) {
		command("say ������ʱ���ж̣��书��΢����������������ɲ������ܴ����ġ�\n");
		command("addoil "+ me->query("id"));
		return 1;
	}
	command("say ���ɵĴ�����ʦ��Ů�������ǵ������������СŮ���������������������£���ƽ����\n"+
		"����գ���һ���о����̵ı�������������书���������ķ��˻��ػ�Ů�����Ǵ������ǣ�\n"+
		"���ۼ�Ԫ���ƴ������ղ����أ����򸾶��˾�������������������֪�䲻�ɶ�Ϊ֮�ĳ�\n"+
		"�ľ��ң����������ľ�������ʹ�ʧ�����񲻿�ϧ���ο��������ɹ�����Ȼһʱռ������\n"+
		"�����Һ����վ�����Ϊ����ū�����պ���ԭѪս���Ǳ������书������м�����ô���\n"+
		"�����Ƹ�ø��ֽ��ˣ��������������ͱ��ɹ���ʦ��һ�������ؽ����ˣ��ټ���������\n"+
		"��������һ����������һ�����콣��\n");

	me->set_temp("jiuyin140", 1);
	return 1;
}

int ask_zhou()
{

        mapping fam;
	object me=this_player();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "������" ) {
		message_vision("���ʦ̫��м�ؿ���$Nһ�ۣ�һ��������������ӡ�\n", me);
		return 1;}

	if( me->query_temp("jiuyin140") >= 1 ) {
		command("say �����������ɵĵ��Ĵ����ӣ��˿���Ȼ������λʦ梣��պ�ȴ�ǲ���������\n");
		me->set_temp("jiuyin140", 2 );
		return 1;
	}
	command("say ��������ʲô��\n");
	command("say " + me->query("name") + "��Ȼ�ǿ���������Ҫ�����������С�\n");
	command("consider " + me->query("id") );
	return 1;
}

int ask_dragon()
{
        mapping fam;

	object me=this_player();
	object ob = this_object();


	if( !(fam = this_player()->query("family")) || fam["family_name"] != "������" ) {
		command("say ���ɵ��ش���������ô֪���ˣ���������\n");
		ob->set("neili", 3999);
		ob->kill_ob(me);
		return 1;}



	if( me->query_temp("jiuyin140") < 4 ) {
		command("say ���ɵ��ش���������ô֪���ˣ���������\n");
		ob->set("neili", 3999);
		ob->kill_ob(me);
		return 1;
	}
	command("say ��Ȼ�������ѳɴ���������͸�������İɡ�\n");
	me->set_temp("jiuyin140", 5 );
	return 1;
}
