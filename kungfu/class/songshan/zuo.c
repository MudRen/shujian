// zuo.c ������
// Update by looklove at 2000/8/25
// Modify by Looklove for add log_file at 2000/9/1
// Looklove@SJ 2000/10/22 fixed fangqi's bug
// Modified by darken@SJ
// Lklv 2001.10.19 modified

#include <ansi.h>
#include "zuo.h"

inherit NPC;

void create()
{
	object ob,ob2,ob3;

	set_name("������", ({ "zuo lengchan", "zuo", "lengchan" }));
	set("nickname", HIR"��������"NOR);
	set("long", "��ɽ�������������ǵ����������˲��������书��Ȼ�����뻯��
		Ϊ���ȸ����ǣ�����ٳ���������һ�ᵽ�������������֣��޲���Ȼ��\n");
	set("gender", "����");
	set("age", 52);
	set("per", 20);
	set("attitude", "heroism");
	set("class", "songshan");
	set("shen_type", -1);
	set("str", 29);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("unique", 1);
	set("no_bark",1);

	set("max_qi", 9500);
	set("max_jing", 5800);
	set("eff_jingli", 8000);
	set("jiali", 100);
	set("combat_exp", 4200000);
	set("shen", -18000);
	set("max_neili", 16000);
	set("neili", 16000);

	set_skill("literate", 220);
	set_skill("force", 380);
	set_skill("dodge", 350);
	set_skill("hand", 350);
	set_skill("strike", 380);
	set_skill("parry", 350);
	set_skill("sword", 360);
	set_skill("songshan-jian", 360);
	set_skill("songyang-shou", 350);
	set_skill("zhongyuefeng", 350);
	set_skill("hanbing-shenzhang", 380);
	set_skill("hanbing-zhenqi", 380);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	map_skill("strike", "hanbing-shenzhang");
	prepare_skill("strike", "hanbing-shenzhang");
	set("inquiry", ([
		"job": (: do_ask() :),
		"����": (: do_ask() :),
		"cancel": (: do_cancel() :),
		"����": (: do_cancel() :),
		"���": (: do_ask_hb() :),
		"����": (:do_ask_times :),
		"����": (:do_ask_times :),
		"���ս�": (:do_ask_grj() :),
	]));
	create_family("��ɽ��", 3, "������");
	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "hand.hanbing" :),
		(: exert_function, "juhan" :),
		(: exert_function, "hanbing" :),
	}));
	setup();
	if (clonep()) {
		ob = unew(BINGQI_D("sword/guanri-jian"));
		ob2 = unew(("d/meizhuang/obj/shuaiyitie"));
		ob3 = unew(("d/meizhuang/obj/lingqi"));
		ob2->move(this_object());
		ob3->move(this_object());
		if (!ob) ob = unew(BINGQI_D("gangjian"));
		ob->move(this_object());
		ob->wield();
		carry_object(ARMOR_D("changpao1"))->wear();
		carry_object(MEDICINE_D("tianwang"));
	}
	add_money("gold", 1);
}

void attempt_apprentice(object ob)
{
	if(ob->query("shen") > 0){
		command("say �����Ʋ�������Ⱥ������α���ӣ����ǰ����ǵ�ٵ�ѧ����һ�°ɡ�");
		return;
	}
	if(ob->query_skill("hanbing-zhenqi",1) < 150 ){
		command("say ����书��������죬�ٻ�ȥ�����ɡ�");
		return;
	}
/*
        if(ob->query("job_time/��ɽ") < 300) {
		command("say ���Դ�������������͵��ˣ����������ҵ���������Ϊʦ��");
		return;
}
*/
	command("say �ã���������Щ������������Դ����书�������㻹�����");
	command("recruit " + ob->query("id"));
	ob->set("title", HIC"���������״�����"NOR);
}

void init()
{
	object ob;
	ob = this_player();

	::init();
	if( interactive(ob = this_player()) && !is_fighting() && !is_busy()
	   && ob->query_temp("quest/family") == "��ɽ��"
	   && ob->query_temp("quest/type") == "��") {
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
}

void greeting(object me)
{
	object target, ob;
	mapping quest;

	if( !me || environment(me) != environment() || !living(me)) return;

	if (!mapp(quest = me->query_temp("quest")) || quest["type"] != "��"
	|| !stringp(quest["id"])) return;

	command("nod "+me->query("id"));

	ob = this_object();

	if(objectp(target=present(quest["id"], environment(me)))
	  && target->query_temp("songshan_job") == me
	  && living(target)){
		me->add_busy(2);
		target->set_leader(0);
		command("haha");
		command("touch "+target->query("id"));
		command("say "+target->name()+"����������ɽ���ֶ���һ����������������");
		call_out("done", 3, target, me, quest, 1);
		return;
	}
}

void done(object target, object me, mapping quest, int i)
{
       int count,exp,pot;

       if(me && i >= 0){
		if(target){
			message_vision("\n$N��ͷ����"+me->name()+"�����޲���������ָ�������У��͵��ǳ����ļ�����ɣ�\n", target, me);
			tell_room( environment(me), target->name() + "��" + me->name()+ "����С����˵��Щ����\n", ({ me, target }) );
			// give rewards.
			TASK_D->give_reward(me, me->query_temp("quest"), -1, ABS(me->query("job_time/��ɽ")/100) , this_object(), "��ɽ" );
			//me->add("job_time/��ɽ", 1);
			//GIFT_D->check_count(me,this_object(),"��ɽ");
			
			if ( me->query("family/family_name") == "��ɽ��"
			&& me->query_skill("hanbing-zhenqi"))
				me->improve_skill("hanbing-zhenqi",me->query("int")*2);
							
			count = me->query("job_time/��ɽ");
			if (count<1) count=1;
			pot= me->query_temp("quest/pot_reward");
			exp= me->query_temp("quest/exp_reward");
			log_file("job/songshan",sprintf("%8s%-10s��%4d����ɽ����������%3d�㾭�飬%2d��Ǳ�ܣ����飺%d\n",
				me->name(),"("+me->query("id")+")",count,exp,pot,me->query("combat_exp")),me);
			me->delete_temp("quest");
			me->delete_temp("songshan_job");
			me->clear_condition("job_busy");
			me->set("job_name", "��ɽ����");
			tell_room(environment(target), target->query("name")+"��Ц��������֪�͵��Ӵ����µ��᷿��Ϣȥ�ˡ�\n", ({target}));
			if(target->return_home()){
				target->delete_temp("songshan_job");
				target->delete_temp("last_lost_to");
				target->clear_condition("songshan_busy");
				target->set("chat_chance", target->query("chat_c"));
				if(!target->query_temp("location"))
				target->delete("location");
				target->set_leader(0);
				target->reincarnate();
			}
			else destruct(target);
		}
	}
	else if(target){
		tell_room(environment(target), target->query("name")+"��Ц��������֪�͵��Ӵ����µ��᷿��Ϣȥ�ˡ�\n", ({target}));
		destruct(target);
	}
}
