#include <ansi.h>
#include <job_mul.h>

inherit NPC;
int ask_job();
int ask_finish();
int ask_quit();
int ask_cure();
object ppl;

void create()
{
	set_name("����", ({ "zhao min", "zhao", "min" }));
	set("gender", "Ů��");
	set("long", "�����ɹ��������ĳ�Ů������\n");
	set("age", 18);
	set("str", 20);
	set("int",35);
	set("con",20);
	set("dex",30);
	set("per",45);
	set("no_get", 1);
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("max_qi",2000);
	set("max_jing",1000);
	set("neili",2000);
	set("max_neili",2000);
	set("qi",2000);
	set("jing",1000);
	set("jingli",1000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", 300);

	set("inquiry", ([
//                "����": (: ask_job :),
		"���": (: ask_finish :),
		"�˳�": (: ask_quit :),
		"��ҩ": (: ask_cure :),
	]) );

	setup();
	carry_object(ARMOR_D("wcloth"))->wear();
	carry_object(ARMOR_D("pixue"))->wear();
}

void init()
{
	::init();
	add_action("do_quit", "abandon");
}

int ask_job()
{
	object me = this_player();
	int  exp;
	object where, target, *list;

	exp = me->query("combat_exp");
	if (me->query_temp("zhao")){
		command("say ��ȥ����ѽ��");
		return 1;
	}
	if (exp < 500000) {
		command("say ���书̫������\n");
		return 1;
	}
	if (me->query("potential") > me->query("max_pot")){
		command("say ����ȥ�������Ǳ�ܰɣ���˲����°빦����");
		command("giggle");
		return 1;
	}
	if( me->query_condition("job_busy")){
		command("say ��ʱ��û��ʲô����Ȥ���书��\n");
		return 1;
	}
	ppl = me;
	list = filter_array(users(), (:
    	    $1->query("combat_exp")/3 > ppl->query("combat_exp")/4
    	 && $1->query("combat_exp")/5 < ppl->query("combat_exp")/4
    	 && !wizardp($1)
    	 && $1->query_temp("user_type") != "worker"
    	 && query_idle($1)<120
    	 && !$1->query("menggu")
    	 && environment($1)
    	 && !$1->query_temp("caught")
    	 && !$1->query_temp("pigging_seat")
    	 && $1->query("duanzhi")<10
    	 && !$1->query_condition("ruanjin_poison")
    	 && $1->query("family")
    	 && query_ip_number($1) != query_ip_number(ppl)
   	 && !$1->query_condition("relax")
    	 && !$1->query_condition("wuguan_job")
	 && !$1->query_condition("killer")
    	:));
	list -= ({me,0});

	if(sizeof(list) < random(10)+1) {
		command("say ����ûʲô���֣����˰ɡ�\n");
		return 1;
	}

	target = list[random(sizeof(list))];
	if (target->query_temp("zm_job_time") > uptime()) {
		command("say ����ûʲô���֣����˰ɡ�\n");
		return 1;
	}
	target->set_temp("zm_job_time", uptime() + 3600);
	where = environment(target);
	me->set_temp("zhao/target",target->query("name"));
	me->set_temp("zhao/targetid",target->query("id"));
	me->apply_condition("job_busy", 4 + random(2));
	command("say ����ѧ��" + target->query("family/family_name") + "���书�������ȥץ����������");
	command("wink");
	command("whisper " + me->query("id") + " �뵽" HIR+ where->query("short") + CYN"��"HIW
	+ target->query("name") + HIY"(" + target->query("id") + ")"GRN"�����");
	command("say ���ʮ�����ɢ����ȥ�ɡ�");
	command("say �����޷�Ȱ��(quanxiang)����������(fu)�������");
	new(__DIR__"letter")->move(me);
	new(__DIR__"ruanjin")->move(me);
	message_vision(HIY"$N�õ���һС��ʮ�����ɢ��һ�����š�\n"NOR,me);
	return 1;
}

int ask_finish()
{
	object me, ob;
	int exp, pot;
	string ob_id;

	me = this_player();
	if (!me->query_temp("zhao")){
		command("?");
		return 1;
	}
	ob_id = me->query_temp("zhao/targetid");
	ob = present(ob_id, environment(me));
	if (!ob){
		command("say ���أ�");
		command("angry");
		return 1;
	}
	if (sizeof(filter_array(deep_inventory(ob), (:userp:)))) {
		command("hmm");
		command("whisper "+me->query("id")+ " ��һ���ô�����Ÿ��˰���");
		return 1;
	}
	if( !ob->query_condition("ruanjin_poison")
	 && (!ob->query_temp("convinced"))) {
		command("hmm");
		command("whisper "+me->query("id")+ " ����ôû����һ����һ��ѽ��");
		return 1;
	}
	command("hehe "+ob->query("id"));
	ob->apply_condition("wuguan_job",10+random(ob->query_kar()));
	message_vision("������������ʿ������$N�����ˡ�\n",ob);
	ob->move(__DIR__"jail");
	command("smile "+me->query("id"));
	command("say ����û��������ˣ�����ȥ��Ϣ�ɡ�");
	exp = random(4)+2;
	pot = me->query("combat_exp",1)/100000;
	pot += 100 + random(20) + me->query("job_time/����");
	if (me->query("menggu")) pot += 30 + random(10);
	
       	/*�������ƿ�ʼ*/
        if (me->query("registered")==3){
			exp = exp * ZM_JOB_MUL * VIP_MUL /10000;
            		pot = pot * ZM_JOB_MUL * VIP_MUL /10000;
		}
		else
		{
			exp = exp * ZM_JOB_MUL /100;
           		pot = pot * ZM_JOB_MUL /100;
		}
		/*�������ƽ���*/ 	
	
	
	me->add("combat_exp",exp);
	me->add("potential",pot);
	if (me->query("menggu")) me->add("balance", exp*10000);
	me->add("job_time/����",1);
	log_file("job/zhaomin", sprintf("%8s%-10s��%4d��ץ�˵õ�����%2d��Ǳ��%4d���־���%d��\n",
		me->name(1),"("+me->query("id")+")",(int)me->query("job_time/����"),exp,pot, me->query("combat_exp")), me);

	me->delete_temp("zhao");
	message_vision(HIW"$N�õ��� "HIM+exp+HIW" �㾭�飬"
		HIG+pot+HIW" ��Ǳ�ܣ�$N�ܹ���ץ�� "HIR+me->query("job_time/����")+HIW" ���ˡ�\n" NOR, me);
	GIFT_D->check_count(me,this_object(),"����");
	me->apply_condition("job_busy", 5 + random(3));
	return 1;
}

int do_quit()
{
	object me = this_player();
	object ob;

	if (ob = present("shixiang ruanjinsan", me)) {
		command("look " + me->query("id"));
		destruct(ob);
		command("kick3 " + me->query("id"));
		me->delete_temp("zhao");
		me->add_condition("job_busy", 6 + random(4));
		return 1;
	}
	return 0;
}

int ask_quit()
{
	object me = this_player();

	if (me->query("menggu")) {
		command("sneer");
		command("say ����Ҳ����Ҫ�����ַ����޳��ļһ");
		me->set("potential",0);
		me->add("combat_exp",-me->query("combat_exp")/100);
		message_vision(BLINK+HIR"$N��Ϊ�����޳������飬Ǳ�ܶ������ˡ�\n"NOR,me);
		me->delete("menggu");
		return 1;
	}
	return 0;
}

int accept_object(object who, object ob)
{
	if (who->query("gender") != "����") {
		command("idle " +who->query("id"));
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 500000) {
		if (!wizardp(who)) {
			command("en");
			return 1;
		}
		else {
			command("blush");
			command("remove all");
			command("lean "+who->query("id"));
			command("sweat "+who->query("id"));
			command("wear all ");
		}
		return 1;
	}
	return 0;
}

int ask_cure()
{
	object me = this_player();
	if (!me->query("menggu")) {
		command("en "+me->query("id"));
		return 1;
	}
//	else {
//		if (me->query("job_time/����")/25 > me->query("zhaocure")) {
			command("ok zhao min");
			new(__DIR__"cure")->move(me);
			me->add("zhaocure",1);
			message_vision(HIG"$N�õ���һ��ҩ�ۡ�\n",me);
			return 1;
//		}
/*		else {
			command("en");
			command("say ���ٰ�æ�Ҷ������°ɡ�");
			return 1;
		}
	}
*/
}

void kill_ob(object me)
{
	object ob;
	command("sneer " + me->query("id"));
	ob = present("lu zhangke",environment(me));
	if (ob) {
		ob->force_me("guard zhao min");
		ob->kill_ob(me);
	}
	ob = present("he biweng",environment(me));
	if (ob) {
		ob->force_me("guard zhao min");
		ob->kill_ob(me);
	}
	remove_all_enemy();
}
