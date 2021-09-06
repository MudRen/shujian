// /clone/npc/thd/man1.h

#include <job_mul.h>
void dest()
{
	object jober;
	if ( stringp(query("��ػ�jober"))
	&& objectp( jober = find_player(query("��ػ�jober")))
	&& jober->query_temp("tdhjob")
	&& jober->query_temp("��ػ�job/target_1id") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s��%4d������ʧ��(1)��ʱ�䣺%4d���־��飺%d��",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/��ػ�")+1, uptime()-jober->query_temp("��ػ�job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("��ػ�job");
		jober->set_temp("��ػ�job/lost", query("name"));
		tell_object(jober, HIY"\n�����㶯��̫����"+this_object()->name()+"Ϊ�����͢׷���������в����ˣ�������ʧ�ܣ�\n"NOR);
	}
	destruct(this_object());
}

string ask_fq()
{
	object me=this_player();

	if ( !me->query_temp("��ػ�job") || !me->query("��ػ�")
	|| me->query_temp("��ػ�job/target_1id") != query("id")) {
		command("fear "+me->query("id"));
		me->add_temp("asktimes", 1);
		return "��Ҫ��˵���ǿ���Ҫ���Դ��ģ�\n";
	}
	if ( !me->query_temp("asked") ) {
		me->delete_temp("asktimes");
		command("? "+me->query("id"));
		me->set_temp("asked", 1);
		return "���²��������ֺţ�����Ҳ��֪������һ·�ϵ����ѡ�\n";
	}
	return "������Ȼ��\n";
}

string ask_qk()
{
	object me=this_player();

	if (!me->query_temp("��ػ�job") || !me->query("��ػ�")
	|| me->query_temp("��ػ�job/target_1id") != query("id"))
		return "ʲô�пڣ������浶�ģ�����������˼��\n";
	if ( !query("wait_answer") && me->query_temp("asked") ){
		set("wait_answer", 1);
		return "�пڣ��������е���˼������˵˵(qiekou)��\n";
	}
	return "����߸ԣ�һ��Ϫɽǧ���㡣\n";
}

void init()
{
	object me = this_player();

	::init();

	add_action("do_da", ({"da", "qiekou"}));

	if ( me->query("tdh_bing") == this_object()){
		kill_ob(me);
		me->kill_ob(this_object());
	}
	if (interactive(me)
	&& userp(me)
	&& me->query_temp("��ػ�job/target_1id") == query("id")
	&& query("��ػ�jober") == me->query("id") ) {
		if (stringp(me->query_temp("��ػ�job/get")) ) {
			remove_call_out("finish");
			call_out("finish", 0, me);
			command("nod ");
		}
		else {
			remove_call_out("checking");
			call_out("checking", 1, me);
			command("lazy ");
		}
	}
}

void heart_beat()
{
	object me, ob = this_object();
	::heart_beat();
	if ( !query("��ػ�jober")){
		dest();
		return;
	}
	if ( !objectp(me = find_player(query("��ػ�jober"))) || !environment(me) || !environment(ob)) return;
	if ( environment(ob)->query("no_fight"))
		random_move();
	if ( me->query_temp("��ػ�job/target_1id") != query("id"))
		dest();
}

void finish(object me)
{
	object target, ob = this_object();
	mapping tdh;
	string str;
	//int exp, pot, time;

	if (!me
	 || !present(me, environment(ob))
	 || !mapp( tdh = me->query_temp("��ػ�job")) )
		return;

	if ( tdh["target_2"] && objectp(target = present(tdh["target_2"], environment(me))) ){
		me->add_busy(2);
		target->set_leader(0);
		if ( tdh["killer"] >= 7 ){
			me->query("gender")=="����"? str = me->name()+"��":str = me->name()+"��";
			message_vision(CYN"$N��Ҿ������ "+target->name()+"�֡�"+str+"��·�������ˣ���л"+str+"��������\n"NOR, ob, me);
			message_vision(CYN"$N��$n���������º�"+target->name()+"�ֻ���Ҫ�������ȸ���ˡ���\n"NOR, ob, me);
			command("bye ");


						
			me->set("job_name", "��ػ�");
			me->clear_condition("job_busy");

                   TASKREWARD_D->get_reward(me,"��ػ�",1,0,0,15+random(6),0,0,0,this_object());

			me->delete_temp("��ػ�job");
			me->delete_temp("tdhjob");
			
			destruct(target);
			destruct(ob);
			return;
		}
		else if ( tdh["shiwei"] > 14){
			me->query("gender")=="����"? str = me->name()+"��":str = me->name()+"��";
			message_vision(CYN"$N��Ҿ������ "+target->name()+"�֡�"+str+"��·�������ˣ���л"+str+"��������\n"NOR, ob, me);
			message_vision(CYN"$N��$n���������������������ڣ����ǻ��Ƿֱ��˰ɡ���\n"NOR, ob, me);
			command("bye ");



			me->set("job_name", "��ػ�");
			me->clear_condition("job_busy");


TASKREWARD_D->get_reward(me,"��ػ�",1,0,0,16+random(6),0,0,0,this_object());

			me->delete_temp("��ػ�job");
			me->delete_temp("tdhjob");
			destruct(target);
			destruct(ob);
			return;
		}
		else if (!query("miss")) {
			set("miss", 1);
			me->query("gender")=="����"? str = me->name()+"��":str = me->name()+"��";
			message_vision(CYN"\n$N���ֵ�����"+target->name()+"�֡�"+str+"�����һ��˵������\n", ob, me);
			message_vision(HIW"ֻ��$N��Զ�����һ�������������������������������������������������ʮ�㡣\n"NOR, ob, me);
			remove_call_out("addbing");
			call_out("addbing", 3, me, ob, target);
		}
	}
	remove_call_out("checking");
	call_out("checking", 5, me);
	return;
}

void checking(object me)
{
	object ob, target;
	mapping tdh;
	ob = this_object();

	if (!me || !ob || !present(me, environment(ob)) || !mapp( tdh = me->query_temp("��ػ�job")) )
		return;

	if ( stringp(tdh["lost"]) ) {
		message_vision(CYN"\n$N��$n����̾�˿�������"+tdh["lost"]+"�Ѿ������ˡ���˵��ҡ��ҡͷ��ת�����ˡ�\n"NOR, ob, me);
		me->delete_temp("��ػ�job");
		me->delete_temp("asked");
		me->delete_temp("tdhjob");
		destruct(ob);
		return;
	}
	if ((!ob->query("qi") >= ob->query("max_qi")/2)
	&& (ob->query("cure") < 5)){
		 ob->add("qi",ob->query("max_qi")/8);
		 ob->add_temp("cure",1);
		 tell_room(environment(ob), ob->name()+"��������˿�������ɫ��ʱ������ࡣ\n", ({ob}));
	}
	if ( stringp(tdh["get"])
	&& objectp(target = present(tdh["target_2"], environment(me)))
	&& tdh["killer"] < 7
	&& tdh["shiwei"] < 14 ) {
		remove_call_out("addbing");
		call_out("addbing", 5, me, ob, target);
	}
	else if ( stringp(tdh["get"])
	 && objectp(target = present(tdh["target_2"], environment(me)))
	 && tdh["meet"] < 1
	 && tdh["shiwei"] >= 14){
	 	target->set_leader(0);
		remove_call_out("finish");
		call_out("finish", 0, me);
	}
	else if ( stringp(tdh["get"])
	&& objectp(target = present(tdh["target_2"], environment(me)))
	&& tdh["meet"] < 1
	&& tdh["killer"] >= 7 ) {
		me->add_busy(2);
		target->set_leader(0);
		remove_call_out("finish");
		call_out("finish", 0, me);
	}
	else if ( stringp(tdh["get"]) ){
		remove_call_out("finish");
		call_out("finish", 15, me);
	}
	remove_call_out("checking");
	call_out("checking", 15, me);
}

void addbing(object me, object ob, object ob2)
{
	object target;
	int i;

	if ( !ob || !ob2 || !me || query("��ػ�jober") != me->query("id") )
		return;

	if ( me->query_temp("��ػ�job/meet") > 0) {
		remove_call_out("checking");
		call_out("checking", 5, me);
		return;
	}
	for (i =0; i < 3; i++){
		target = new(__DIR__"bing");
		target->set("��ػ�jober", me->query("id"));
		target->set("tdh_bing", ob);
		target->set("tdh_bing2", ob2);
		copy_npc(me, target, 80);
		target->move(environment(me));
		me->add_temp("��ػ�job/meet", 1);
		me->add_temp("��ػ�job/shiwei", 1);
		target->kill_ob(me);
	}

	me->add_busy(1 + random(2));
	command("grpfight ");

	tell_room(environment(ob), HIR"Χ�۵���Ⱥ��ͻȻ���˺���������ǰ����"+target->name()+"���ڴˣ��������ߣ�����\n"NOR, ({ob}));
	tell_room(environment(ob), CYN+target->name()+"�е����������շ��������˵���������˵�ձ���"+me->name()+"��ս����һ��\n"NOR,({ob}));
	remove_call_out("checking");
	call_out("checking", 5, me);
}

int do_da(string arg)
{
	object me, ob, target, *living, fname, troom;
	string tk, t_title, tname, str, where;
	int i, j, x, y;

	if ( arg || !query("wait_answer") ) return 0;

	me = this_player();
	ob = this_object();

	if ( !ob || !me
	|| !me->query_temp("asked")
	|| me->query_temp("��ػ�job/target_2")
	|| !me->query_temp("��ػ�job/start_place") )
		return 0;
	if ( me->query("id") != ob->query("��ػ�jober"))
		return 0;
	if ((!me->query("��ػ�") && !wizardp(me))
	|| me->is_fighting() || me->is_busy() ) {
		command("bored "+me->query("id"));
		return 1;
	}
	me->delete_temp("asked");
	tk = ob->query("��ػ�/tangkou");
	t_title = ob->query("��ػ�/title");
	tname = tk+t_title+ob->name();

	message_vision(HIY"$N��$n��������������߸ԣ�һ��Ϫɽǧ���㡣��\n"NOR, me, ob);
	message_vision(HIY"$n��$N�����������ų��󺣣����Ӻ�ˮ����������\n"NOR, me, ob);
	random(2)>0 ? command("touch "+me->query("id")) : command("hug "+me->query("id"));
	command("say ԭ��������Լ��ˣ�����"+tname+"��");
	ob->set_temp("title", HIW"��ػ�"+tk+t_title+NOR);


	set("job3a", 1);
	living = livings();
	for (i=0 ;i < sizeof(living); i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			fname = living[j];
			troom = environment(fname);
			str = troom->query("short");
			if (!sizeof(troom->query("exits"))
			|| str == "��ɮ��"
			|| str == "����"
			|| str == "����"
			|| str == "����"
			|| str == "����"
			|| str == "����"
			|| str == "����"
			|| str == "��Ӫ"
			|| str == "ɮ��"
			|| str == "��Ϣ��"
			|| str == "Ů��Ϣ��"
			|| str == "����Ϣ��"
			|| str == "����"
			|| str == "���"
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
			if ( get_place(base_name(environment(fname))) == get_place(base_name(environment(ob)))) continue;
			if ( get_place(base_name(environment(fname))) != "" ) break;
		}
	}

	if( !fname ) {
		command("say ��ʱû��������Ҫ�����Ժ���˵�ɡ�");
		return 1;
	}

// ��һ��npc �趨
	target = new(__DIR__"man2");
	target->set("��ػ�jober", me->query("id") );
	target->move(troom);

	for (i=0; i < 5; i++)
		target->random_move();

	if (environment(target)->query("no_fight"))
		target->random_move();

	copy_npc(me, target, 125);

	if (strsrch(file_name(environment(target)), "/d/zhiye/") >= 0
	 || strsrch(file_name(environment(target)), "/d/group/") >= 0){
	 	if ( environment(target)->query("outdoors"))
			where =  environment(target)->query("outdoors")+environment(target)->query("short");
	 	else if ( environment(target)->query("indoors"))
			where =  environment(target)->query("indoors")+environment(target)->query("short");
		else where =  environment(target)->query("short");
	}
	else where = get_place(base_name(environment(target)))+environment(target)->query("short");

	me->set_temp("��ػ�job/goon_place", where);
	me->set_temp("��ػ�job/3a", ob->query("id"));
	me->set_temp("��ػ�job/target_2", target->query("id"));

	command("say ��"+where+"��һλ����"+target->name()+"���ֵܣ��������������ػᡣ");
	command("whisper "+me->query("id")+" ������ò�ǡ���������ӵģ�ƾ�������һ�۾��ϵó�����");
	command("say ��͢�Ѿ������ڼ��������뾡��ϵ����ֵܻ���Ҫ��������������һ���ˡ�");

	log_file("job/tiandi", sprintf("%8s%-10s������%4d������Ŀ�꣺%s��%s��Ŀǰ���飺%d��\n",
		me->name(),"("+me->query("id")+")", me->query("job_time/��ػ�")+1, where,target->name(), me->query("combat_exp")), me);
	return 1;

}

string ask_tdh()
{
	object me=this_player();
	if (!me->query_temp("��ػ�job"))
		return "������˵��ػ�Ķ��Ǻú��ӣ�ֻ����Ե�ύ��\n";
	return "���֪����������ʲô�£�\n";
}

string ask_chen()
{
	object me=this_player();
	message_vision(CYN"$N��$n����������˵��ƽ����ʶ�½��ϣ��ͳ�Ӣ��Ҳ��Ȼ������֪���ֿ�ʶ�ó��ܶ�����\n"NOR, me, this_object());
	if (me->query_temp("asktimes") > 10)
		return"����Ҵ���ʲô���Ͳ��������ܶ�������Ѫ��צ��\n";
	if (!me->query("��ػ�"))
		return "�ܶ��������������ġ�\n";
	return "��Ҳ������ܶ���һ�棬������֪�������˼������\n";
}

string ask_zheng()
{
	object me=this_player();
	if (me->query("��ػ�"))
		return "����ү�ǵ�����һӢ�ۣ��ڶ����Ҫ�������ܶ����ˡ�\n";
	return "�����˼��ǵ�����һӢ�ۡ�\n";
}

string ask_target()
{
	string str;
	object me=this_player();

	if (!me->query("��ػ�")) return 0;
	if (!me->query_temp("��ػ�job/goon_place"))
		return "����һֱ��������صķ���־ʿ��\n";
	str = me->query_temp("��ػ�job/goon_place");
	return "��ȥ"+ str +CYN"����ȥ��ء�\n";
}
                                                                                                    
