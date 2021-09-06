// tdh_npc.h
// Creat by Lklv , include for ��ػ�������� NPC

#include <ansi.h>
#include <get_place.h>
#include "place.h"
#include "skill.h"

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
	{
		reincarnate();
		remove_all_killer();
	}
}

string ask_fail()
{
	object me= this_player();
	if ( !me->query_temp("tdhjob"))
		return "����û������񣬷���ʲô����";
	if ( me->query_temp("��ػ�job/lost"))
		return "����û������񣬷���ʲôѽ��";
	if ( me->query_temp("��ػ�job/get_name"))
		return "���Ѿ���"+ me->query_temp("��ػ�job/get_name")+"��ϵ���ˣ����ǿ��ȥ��"+me->query_temp("��ػ�job/target_1")+"��ϰɣ�";
	me->delete_temp("��ػ�job");
	me->delete_temp("tdhjob");
	log_file("job/tiandi", sprintf("%8s%-10s��%4d������������־��飺%d��",
		me->name(), "("+me->query("id")+")", me->query("job_time/��ػ�")+1, me->query("combat_exp")), me);
	return "��Ȼ�������ˣ�Ҳ�����ˡ�";
}

int ask_join()
{
	object me=this_player();

	if (me->query_temp("asktimes") > 10) {
		command("say �㵽������Ҵ���ʲô���ǲ��ǳ�͢������̽�ӣ�");
		return 1;
	}
	if (me->query("��ػ�")) {
		command("whisper "+me->query("id")+" �����˶����ӣ���Ҫй©�����ǵ���ݡ�");
		return 1;
	}
	command("say ԭ��"+RANK_D->query_respect(me)+"Ҳ֪����������ţ���������");
	command("look "+me->query("id"));
	me->set_temp("��ػ�join",1);
	me->add_temp("asktimes",1);
	return 1;
}

int ask_tdh()
{
	object me=this_player();

	if (me->query("shen")<10000) {
		command("say ��˵����һ�����°�ᣬ��ּ�Ƿ��帴������͢�������ڵ����������ǡ�");
		return 1;
	}


	if (me->query_temp("asktimes") > 10) {
		command("say �㵽������Ҵ���ʲô���ǲ��ǳ�͢������̽�ӣ�");
		return 1;
	}






	if (me->query_temp("��ػ�join")==2) {
		command("say "+RANK_D->query_respect(me)+"��Ȼû�г��⣬�Ǿ����ˡ�");
		me->add_temp("asktimes",1);
		return 1;
	}
	if (me->query_temp("��ػ�join")==1) {
		command("look "+me->query("id"));
		command("whisper "+me->query("id")+" ���֪������������ʲô�£�");
		me->set_temp("��ػ�join", 2);
		me->add_temp("asktimes",1);
		return 1;
	}
	if (!me->query("��ػ�")){
		command("look "+me->query("id"));
		me->add_temp("asktimes",1);
		command("say ��˵����һ�����°�ᣬ��ּ�Ƿ��帴������͢�������ڵ����������ǡ�");
		return 1;
	}
	command("shutup "+me->query("id"));
	command("whisper "+me->query("id")+" �����˶����ӣ���Ҫй©�����ǵ���ݡ�");
	return 1;
}

int ask_fq()
{
	string tk, tname;
	object me=this_player();
	object ob=this_object();

	tk = ob->query("��ػ�/tangkou");
	tname = ob->query("��ػ�/title");

	if (me->query_temp("asktimes") > 10) {
		command("say �㵽������Ҵ���ʲô���ǲ��ǳ�͢������̽�ӣ�");
		ob->kill_ob(me);
		return 1;
	}

	if (me->query_temp("��ػ�join")==2) {
		command("touch "+me->query("id"));
		command("say ��ӭ������ػ�"+tk+"��");
		command("say �Ժ��Ҿ����Լ����ˣ�����"+tk+tname+"��");
		me->delete_temp("��ػ�join");
		me->delete_temp("asktimes");
		me->set("��ػ�/tangkou", tk);
		me->set("��ػ�/title", "����");
		// ��ʱtitle
		me->set_temp("title", HIR"��ػ�"+tk+"����"NOR);
		ob->set_temp("title", HIR"��ػ�"+ob->query("��ػ�/tangkou")+ob->query("��ػ�/title")+NOR);
		ob->set("joined", me->query("id"));
		return 1;
	}
	if (!me->query("��ػ�")) {
		command("fear "+me->query("id"));
		command("say ��Ҫ��˵���ǿ���Ҫ���Դ��ģ�");
		me->add_temp("asktimes",1);
		return 1;
	}
	command("agree "+me->query("id"));
	return 1;
}

string ask_chen()
{
	object me=this_player();
	if (me->query_temp("asktimes") > 10)
		return"���Ҵ���ʲô���Ͳ��������ܶ�������Ѫ��צ��\n";
	message_vision(CYN"$N��$n����������˵��ƽ����ʶ�½��ϣ��ͳ�Ӣ��Ҳ��Ȼ������֪���ֿ�ʶ�ó��ܶ�����\n"NOR, me, this_object());
	if (!me->query("��ػ�"))
		return "�ܶ��������������ġ�\n";
	return "��Ҳ������ܶ���һ�棬������֪�������˼������\n";
}

string ask_zheng()
{
	object me=this_player();

	if (me->query("��ػ�")) {
		command("nod "+me->query("id"));
		return "����ү�ǵ�����һӢ�ۣ��ڶ����Ҫ�������ܶ����ˡ�\n";
	}
	return "�����˼��ǵ�����һӢ�ۡ�\n";
}



int ask_qk()
{
	object me=this_player();

	if (me->query_temp("asktimes") > 10) {
		command("say �㵽������Ҵ���ʲô���ǲ��ǳ�͢������̽�ӣ�");
		return 1;
	}
	if (!me->query("��ػ�")) {
		me->add_temp("asktimes",1);
		command("dunno ");
		return 1;
	}
	command("say ����߸ԣ�һ��Ϫɽǧ���㡣");
	return 1;
}

int ask_sandian()
{
	object me=this_player();

	if (!me->query("��ػ�")) {
		command("dunno "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("��ػ�job")){
		command("look "+me->query("id"));
		return 1;
	}
	command("say ���㰵�ظ����ڣ����Һ���Īͨ�硣�������ƴӳ��գ������峯һɨ�ա�");
	return 1;
}

int ask_job()
{
	int i, j, p;
	string tk, ttitle, str, str2, where;
	object me, ob, target, *living, fname, troom;

	me = this_player();
	ob = this_object();
	// ����һ����ʱû���õ�, tk
	tk = me->query("��ػ�/tangkou");
	ttitle = me->query("��ػ�/title");
	str2 = me->query_temp("��ػ�job/start_place");

	if ((!me->query("��ػ�") && !wizardp(me))
	|| me->is_fighting() || me->is_busy() ) {
		command("bored "+me->query("id"));
		return 1;
	}
	if (me->query_temp("��ػ�job/start_place") && !wizardp(me)){
		command("whisper "+me->query("id")+" ��ȥ"+ str2 +"��");
		return 1;
	}
// 325:    me->apply_condition("xs_job", 10 );
        if ( me->query_temp("tdhjob") || me->query_condition("job_busy") || me->query_condition("xs_job") ){
		command("say �㻹���������أ�");
		return 1;
	}
	if ( me->query("job_name") == "��ػ�" && !wizardp(me)){
		command("say ���������񣬻���ȥ��Ϣ��ɡ�");
		return 1;
	}

	message_vision(CYN"$N��$n�������������������Ϊ��ᾡЩ΢����������Ը���\n"NOR, me,ob);

	if ( me->query("menggu")){
		message_vision(CYN"$N��ɫһ������$n��ǰ�������˿�����Ͷ�����ɹ����ӣ����ϲ������\n"NOR, ob, me);
		command("say ��Ҫ���ҷ�������������ǰ��ʧ����Ȼ�ֵܶ�û������");
		remove_call_out("check_killer");
		call_out("check_killer", 5, me, this_object());
		return 1;
	}


	else if ( me->query_temp("guanfu_jiebang") ){
		message_vision(CYN"$N��ɫһ������$n��ǰ�������˿�����ȥ�ٸ��Ұ���Ҳ���ǣ���\n"NOR, ob, me);
		command("consider "+me->query("id"));
		command("say ��Ҫ���ҷ�������������ǰ��ʧ����Ȼ�ֵܶ�û������");
		remove_call_out("check_killer");
		call_out("check_killer", 5, me, this_object());
		return 1;
	}
	if ( me->query("combat_exp") < 100000 ){
		command("say " + RANK_D->query_respect(me) + "���书δ�ɣ��Ժ���˵�ɣ�");
		return 1;
	}

	if ( me->query("shen") < 10000 ){
		command("say " + RANK_D->query_respect(me) + "��ò�Ʋ�����������֮�ģ���������ҿɲ���������ȥ����");
		return 1;
	}

	p = me->query("job_time/��ػ�");

	if ( p > 1000 && ! me->query("quest/ningxue/time")) {
		if ( p % 50 == 0) {
			command("say ��˵���ܶ����������㣬�㻹����ȥ���ܶ���ѯ�ʰɡ�");
			me->set("quest/ningxue/meet", 1);
			return 1;
		}
	}

	(random(4)>1) ? command("consider"):command("ok "+me->query("id"));

	// ������һ��npc target_1
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
			|| str == "��ջ"
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
			if (get_place(base_name(troom)) == get_place(base_name(environment(ob)))) continue;
			if( get_place(base_name(environment(fname))) != "" ) break;
		}
	}

	if( !fname ) {
		command("say ��ʱû��������Ҫ�����Ժ���˵�ɡ�");
		return 1;
	}

	target = new(__DIR__"man1");
	target->set("��ػ�jober", me->query("id"));
	target->move(troom);

	for (i=0; i < 5; i++)
		target->random_move();

	if (environment(target)->query("no_fight"))
		target->random_move();

	copy_npc(me, target, 110);

	if (strsrch(file_name(environment(target)), "/d/zhiye/") >= 0 
	 || strsrch(file_name(environment(target)), "/d/group/") >= 0){
	 	if ( environment(target)->query("outdoors"))
			where =  environment(target)->query("outdoors")+environment(target)->query("short");
	 	else if ( environment(target)->query("indoors"))
			where =  environment(target)->query("indoors")+environment(target)->query("short");
		else where =  environment(target)->query("short");
	}
	else where = get_place(base_name(environment(target)))+environment(target)->query("short");

	log_file("job/tiandi",sprintf("%8s%-10s��ʼ��%4d������Ŀ�꣺%s��%s��Ŀǰ���飺%d��\n",
		me->name(),"("+me->query("id")+")", me->query("job_time/��ػ�")+1, where,target->query("name"), me->query("combat_exp")), me);

	if (!stringp(ttitle)) ttitle = "����";
	me->set_temp("title", HIR"��ػ�"+tk+ttitle+NOR);
	me->delete_temp("asked");

	me->set_temp("tdhjob", 1);
	me->set_temp("��ػ�job/start_place", where);
	me->set_temp("��ػ�job/target_1", target->name());
	me->set_temp("��ػ�job/target_1id", target->query("id"));
	me->set_temp("��ػ�job/time", uptime());
	me->apply_condition("job_busy", 10);
	command("whisper "+ me->query("id") +" ������ȥ"HIC+ where +GRN "����һ��������ֵܡ�");
	command("whisper "+ me->query("id") +" �������ֽ�"HIW+target->query("name")+GRN"����·��С�ġ�");
	return 1;
}

int ask_target()
{
	string str;
	object me=this_player();

	if (!me->query("��ػ�")) return 0;
	if (!me->query_temp("��ػ�job/start_place")){
		command("say ����һֱ��������صķ���־ʿ��\n");
		return 1;
	}

	str = me->query_temp("��ػ�job/start_place");
	command("whisper "+me->query("id")+" ��ȥ"+ str +"����ȥ��ء�");
	return 1;
}

void init()
{
	object ob = this_player();

	::init();

	if ( interactive(ob) && userp(ob) && living(ob)) {
		if ( ob->query_temp("��ػ�job/lost") ) {
			remove_call_out("lost_job");
			call_out("lost_job", 0, ob);
		}
		else if ( stringp(ob->query_temp("kill_tdhnpc")) ) {
			remove_call_out("check_killer");
			call_out("check_killer", 0, ob, this_object());
		}
	}
}

void lost_job(object me)
{
	string target;

	if (!me || !present(me, environment(this_object())))
		return;

	target = me->query_temp("��ػ�job/lost");

	if (!target) return;

	if ( me->query_temp("��ػ�job/lost") ) {
		command("sigh "+me->query("id"));
		command("say ̽�ӻر���"+target+"�Ѿ������ˡ�");
		me->delete_temp("��ػ�job");
		me->delete_temp("tdhjob");
		return;
	}
}

void check_killer(object me, object ob)
{
	string target;

	if ( !ob) return;

	if (!me	 || !present(me, environment(ob)))
		return;

	if ( stringp (target = me->query_temp("kill_tdhnpc")) ) {
		message_vision(HIR"\n$N��$n��ȵ���̽�ӻر����������ػ��ֵ�"+target+"���ף��������ɣ�\n"NOR, ob, me);
		command("stare "+me->query("id"));
	}
	else {
		message_vision(HIR"\n$N˫��ͨ�죬ͻȻ��$n��ȵ������������ɣ�\n"NOR, ob, me);
	}
	ob->kill_ob(me);
	return;
}

void die()
{
	object killer;

	if ( objectp(killer = query_temp("last_damage_from")) && userp(killer)){
		killer->add("shen", -3000);
		killer->set_temp("kill_tdhnpc", this_object()->name());
	}
	command("say ���ӵ��߹������ú�����");
	::die();
}

string ask_times()
{
	object me= this_player();
	int i;

	i = (int)me->query("job_time/��ػ�");

	if ( !me->query("��ػ�"))
		return "�㲻����ػ���ˣ��Һ���ûʲô��˵�ġ�";
	if ( !i ) return "��Ŀǰһ�ι���Ҳû�С�";
	return "��Ŀǰ�Ѿ�����"+chinese_number(i)+"�Ρ�";
}
