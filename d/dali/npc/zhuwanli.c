//by cool 98.3.25
// ���ܺ�wd,xs jobһ������River@SJ 2000.7.19

inherit NPC;
#include <ansi.h>
#include <get_place.h>
#include <mudlib.h>

int check(object ob);
string ask_job();
string ask_fangqi();

void create()
{
	set_name("������", ({ "zhu wanli","zhu","wanli" }));
	set("title", "��������������ҽ�");
	set("gender", "����");
	set("age", 33);
	set("str", 27);
	set("dex", 26);
	set("long", "���������������ϲ���һ��������Ӣ�����ˡ�\n");
	set("combat_exp", 400000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("no_bark",1);
	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("whip", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 900);
	set("neili", 900);
	set("max_neili", 900);
	set("jiali", 20);
	set("inquiry", ([
		"����" : (: ask_job :),
		"job" : (: ask_job :),
		"����" : (: ask_fangqi :),
		"fangqi" : (: ask_fangqi :),
	]));

	setup();
	carry_object(BINGQI_D("ruansuo"))->wield();
	carry_object(ARMOR_D("junfu"))->wear();
}

string ask_fangqi()
{
	object ob = this_player();
	object obj;
	int i;
	string site;

	if (!ob->query_temp("dali_songxin"))
		return RANK_D->query_respect(ob) +"�㲢û���������ŵ�����˵ʲô��������";

	i = ob->query_temp("songxin/time") - ob->query_condition("dali_songxin");
	if ( i > 8 )	i = 8;
	ob->apply_condition("job_busy", 9-i);
	ob->delete_temp("dali_songxin");
	ob->clear_condition("dali_songxin");
	ob->delete_temp("letter_steal");
	ob->delete_temp("zuji");
	ob->delete_temp("songxin_zuji");
	ob->delete_temp("songxin");
	ob->clear_condition("job_busy");
	ob->clear_condition("dali_songxin");
//	ob->clear_condition(0);/////////////////is temp

	if(objectp(obj = present("secret letter", ob)))
		destruct(obj);
        	site = lower_case(INTERMUD_MUD_NAME);
        	//��ͬsite,�۳��Ľ�����ͬ
        	if (site=="sh" || site=="sh2")
	{
	ob->add("combat_exp", -(20+random(15)));
	}
	else
	{
	ob->add("combat_exp", -(30+random(30)));		
	}
	return "��Ȼ"+ RANK_D->query_respect(ob) +"�����ˣ�Ҳ�Ͱ��ˡ�";
}

string ask_job()
{
	object me, *living, target, ob, obj;
	int time,i,j;
	string str;

	ob=this_player();
	me=this_object();

	if (!wizardp(ob) && !ob->query_temp("dali_join"))
		return RANK_D->query_respect(ob) +"���㲻�Ǳ�������ӣ��˻��Ӻ�˵��";

	if (ob->query_temp("dali_songxin"))
		return "�㲻���Ѿ��������ŵ������𣿻�����ȥ����";

	if (ob->query("job_name") == "��������" && !wizardp(ob))
		return "�����������������񣬻���ȥ��Ϣһ��ɡ�";

	if (ob->query_condition("dali_songxin") > 0)
		return "������ʱû�и���������ٵ�"+chinese_number((ob->query_condition("dali_songxin")+5)/6)+"��ʱ���ɡ�";

	if( ob->query_condition("job_busy"))
		return "����ȥ��Ϣһ��ɣ�";

	if (ob->query("combat_exp") < 100000)
		     return ("��Ĺ��򻹲����������ſ��Ǻ�Σ�յ��£��ҿɲ��ҽ�����������");

	if(ob->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";


	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			target = living[j];
			str = environment(target)->query("short");
			if( str == "��ɮ��"
			 || str == HIR"������"NOR
			 || str =="���º�ȭ��"
			 || str == "��շ�ħȦ" ) continue;
			if( get_place(base_name(environment(target)))!="" ) break;
		}
	}

	if( !target )
		return "��ʱû������Ҫ�ͣ����һ��������ɡ�";

	time = random(10)+ 25;
	ob->delete_temp("songxin_ok");
	ob->delete_temp("dali_songxin_late");
	ob->delete_temp("songxin_zuji");
	ob->set_temp("dali_songxin", 1);
	ob->set_temp("songxin/time", time);
	ob->set_temp("songxin/times", uptime());
	ob->apply_condition("job_busy", time);

	if ( random(3)) {
		ob->apply_condition("dali_songxin", time);
		ob->set_temp("songxin/target_name", target->query("name"));
		ob->set_temp("songxin/area", load_object(target->query("startroom"))->query("short"));
		ob->set_temp("songxin/areab", target->query("startroom"));
		ob->set_temp("songxin/id", target->query("id"));
		ob->set_temp("songxin/where", get_place(ob->query_temp("songxin/areab"))+ob->query_temp("songxin/area"));
		if ( random(3) ) ob->set_temp("songxin/other", 1);
	}
	else {
		ob->apply_condition("dali_songxin", time*9/10+2);
		obj = new("/d/dali/job/sxtarget");
		obj->set("startroom", target->query("startroom"));
		obj->move(environment(target));
		ob->set_temp("songxin/other", 1);
		ob->set_temp("songxin/target_name", obj->query("name"));
		ob->set_temp("songxin/area", load_object(target->query("startroom"))->query("short"));
		ob->set_temp("songxin/areab", target->query("startroom"));
		ob->set_temp("songxin/id", obj->query("id"));
		ob->set_temp("songxin/where", get_place(ob->query_temp("songxin/areab"))+ob->query_temp("songxin/area"));
	}

	switch(random(3)) {
		case 0:{
			command("nod "+ ob->query("id"));
			command("tell "+ ob->query("id")+" �������ܺ������͵���"+ob->query_temp("songxin/where")+GRN"���ġ�"+ob->query_temp("songxin/target_name")+GRN"�����ϡ�");
			break;
		}
		case 1:{
			command("smile "+ ob->query("id"));
			command("tell "+ ob->query("id")+" �����������з��ţ���ȥ�����͵���"+ob->query_temp("songxin/where")+GRN"���ġ�"+ob->query_temp("songxin/target_name")+GRN"�����ϡ�");
			break;
		}
		case 2:{
			command("consider");
			command("tell "+ ob->query("id")+" ��Ͻ������͵���"+ob->query_temp("songxin/where")+GRN"���ġ�"+ob->query_temp("songxin/target_name")+GRN"�����ϡ�");
			break;
		}
	}
	message_vision("$N����$nһ���ܺ���\n",me,ob);
	ob=new("/d/dali/job/dali_letter");
	ob->set("ever_owner",getuid(this_player()));
	ob->move(this_player());
	return "·�ϳ���ǿ�˳�û�����С�ġ�";
}

string *no_kill_list = ({
	 "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
	object room;
	string room_name, start_room;
//	|| ob->query("chat_chance")

	if (!objectp(ob)
	|| userp(ob)
	|| ob->query("env/invisibility")
	|| ob->query("no_quest")
	|| member_array(ob->query("id"), no_kill_list) != -1
	|| ob->query("race") !="����"
	|| ob->query("attitude")=="aggressive"
	|| !ob->query("can_speak")
	|| ob->query("have_master")
	|| ob->query("combat_exp") < 20000
	|| !(start_room = ob->query("startroom"))	// add by Yuj@SJ to void job NPC
	|| !objectp(room=environment(ob))
	|| room->query("no_fight")
	|| room->query("quest")
	|| strsrch(room_name = base_name(room), "/d/") != 0
	|| ob->query("lastroom") == room_name && start_room != room_name
	|| start_room[0..5] != room_name[0..5]
	|| strsrch(room_name, "/d/wizard/") == 0
	|| strsrch(room_name, "/d/wuguan/") == 0
	|| strsrch(room_name, "/d/death/") == 0
	|| strsrch(room_name, "/d/mingjiao/bhd/") == 0
	|| strsrch(room_name, "/d/mingjiao/lsd/") == 0
	|| strsrch(room_name, "/d/dali/") == 0
	|| strsrch(room_name, "/d/tls/") == 0
	|| strsrch(room_name, "/d/shaolin/fumoquan") == 0
	|| strsrch(room_name, "/d/group/") == 0
	|| strsrch(room_name, "/d/baituo/") == 0
	|| strsrch(room_name, "/d/tianshan/") == 0
	|| strsrch(room_name, "/d/thd/") == 0 )
		return 0;
	return 1;
}
