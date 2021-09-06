// bei.c ����ʯ
// By River 2003.2.26
// ��ҪNPC.ɱ���� by spiderii@ty
// ͳһ�����㷨  by lsxk@hsbbs 2008/1/10

#include <ansi.h>
#include <job_mul.h>
#include <get_place.h>
inherit NPC;

string ask_job();
string ask_times();
string ask_finish();
string ask_fail();
int check(object ob);

void create()
{
	set_name("����ʯ",({"bei haishi", "bei", "haishi"}));
	set("title", "���ְ��ܹ�");
	set("nickname",HIY"���ֻش�"NOR);
	set("long", "�����ǳ��ְ��ܹܣ��˳����ֻش��ı���ʯ��\n"+
		"����һ�����в��ݵ����ߡ�\n");
	set("age", 65);
	set("attitude", "friendly");
	set("shen", 0);
	set("str", 26);
	set("int", 29);
	set("con", 27);
	set("dex", 30);
	set("no_get", 1);
	set("no_bark", 1);
	set("job_npc", 1);
	set("no_ansuan", 1);

	set("max_qi", 4500);
	set("max_jing", 3200);
	set("eff_jingli", 3500);
	set("jiali", 80);
	set("combat_exp", 2500000); 
	set("unique", 1);

	set_skill("dodge",220);
	set_skill("force", 220);
	set_skill("literate", 200);
	set_skill("strike", 220);
	set_skill("kunlun-shenfa", 220);
	set_skill("banruo-zhang", 220);
	set_skill("shenzhao-jing", 220);
	set_skill("parry", 220);
	set_skill("medicine", 160);

	map_skill("force", "shenzhao-jing");
	map_skill("dodge", "kunlun-shenfa");
	map_skill("parry", "banruo-zhang");
	map_skill("strike", "banruo-zhang");
	prepare_skill("strike", "banruo-zhang");

	set("inquiry", ([
		"����"	:	(: ask_job :),
		"job"	:	(: ask_job :),
		"���"	:	(: ask_finish :),
		"finish":	(: ask_finish :),
		"����"	:	(: ask_times :),
		"����"	:	(: ask_fail :),
		"fangqi":	(: ask_fail :),
		"����"	:	"�����Ѿ�ʧ�ٶ��գ��������ڵ���Ѱ���С�",
		"���͵�":	"���Ҫ�Ȱ��������󣬲������顣",
		"���ְ�":	"���ְ��Ϊ�����á�ʨ���á������á������úͱ��������á�",
	]));

	setup();
	carry_object(ARMOR_D("changshan"))->wear();
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}

string *party = ({"������","ʨ����","������","������","������"});

string ask_job()
{
	object me, ob, *living, target;
	string str, str2, address;
	object objwhere;
	int i,j;

	me = this_player();
	str2 = party[random(sizeof(party))];

	if (me->query_temp("changle/changle_job") && !me->query_temp("changle/job_place"))
		return "���������Բ��𣬵ص�������������������ɡ�";

	if (me->query_temp("changle/job_place1"))
		return "�㲻���Ѿ�֪���ˣ�ɱ���Ұ���ڵĳ�����"+me->query_temp("changle/job_place1")+CYN"һ�����ֹ���";

	if ( me->query_temp("changle/done"))
		return "�㲻���Ѿ���չ��һ���ز��ˣ����Ǽ���Ŭ���ɣ�";

	if (me->query_temp("changle/changle_job"))
		return "�Ҳ��Ǹ����������Ұ�������"+me->query_temp("changle/job_place")+CYN"����Ϯ�����㻹���Ͽ�ǰȥ��Ԯ��";

	if (me->query("job_name") =="���ְ�" && !wizardp(me))
		return "������곤�ְ����񣬻�����ȥ��Ϣһ��ɡ�";

	if (me->query("combat_exp") < 100000 )
		return "��λ" + RANK_D->query_respect(me) + "�书δ�ɣ��Ұﻹ����Ҫ��İ�����";

	if ( me->query_condition("job_busy"))
		return "�Ұ����ڱȽϿ��У���ʱ��û����������ȥ����";
	
	if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			target = living[j];
			objwhere = environment(target);
			str = objwhere->query("short");
			if (!sizeof(objwhere->query("exits"))
			|| str == "��ɮ��"
			|| str == "ɮ��"
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
			if( get_place(base_name(environment(target))) != "" ) break;
		}
	}

	if( !target )
		return "��ʱû��������Ҫ�������һ��������ɡ�";

	ob = new(__DIR__"zhong");
	ob->set_temp("target", getuid(me));
	ob->set("title", HIR"���ְ�"+str2+"���°���"NOR);
	ob->move(objwhere);
	ob->set("env/invisibilty", 10);

	for ( j = 0; j < 5; j ++)
		ob->random_move();

	if ( environment(ob)->query("no_fight") || environment(ob)->query("quest") )
		ob->random_move();

	ob->delete("env/invisibilty");

	if (strsrch(file_name(environment(ob)), "/d/zhiye/") >= 0
	 || strsrch(file_name(environment(ob)), "/d/group/") >= 0) {
	 	if ( environment(ob)->query("outdoors"))
			me->set_temp("change/job_place", environment(ob)->query("outdoors")+environment(ob)->query("short"));
	 	else if ( environment(ob)->query("indoors"))
			me->set_temp("change/job_place", environment(ob)->query("indoors")+environment(ob)->query("short"));
		else me->set_temp("changle/job_place", environment(ob)->query("short"));
	}
	else me->set_temp("changle/job_place", get_place(base_name(environment(ob)))+environment(ob)->query("short"));

	if ( ! me->query_temp("changle/job_place"))
		return "��ʱû��������Ҫ������͹�һ��������ɡ�";

	address = strip(me->query_temp("changle/job_place"));
	me->set_temp("changle/changle_job",1);
	me->set_temp("changle/times", uptime());
	me->apply_condition("job_busy", 40 );
	me->set_temp("changle/npc_name", ob->name(1));
	command("bow "+ me->query("id"));
	command("whisper "+ me->query("id")+" �ҽӵ��ɸ봫�飬"+str2+"���°���"+ob->query("name")+"��"+ address +"������Ϯ������Ͽ�ǰȥ��Ԯ��");
	return "��λ"+RANK_D->query_respect(me)+"��Ϊ�Ұ�������������ʹ�����������͡�";
}

string ask_finish()
{
	object ob, me = this_player();
	int gold;
	string msg;

	if (!me->query_temp("changle"))
		return "�������û�����������ʲô����";

	if ( !me->query_temp("changle/done"))
		return "��������������ô��";

	msg = me->query_temp("changle/target_family");
	switch(me->query_temp("changle/done")){
		case 1:
                   TASKREWARD_D->get_reward(me,"���ְ�",0,0,0,-3,0,0,0);
			msg = "��Ȼ�Ѿ�֪������"+msg+"��Ϊ���ߣ��������������ˡ�";
			me->add("job_time/���ְ�", -1);
			break;
		case 2:
                   TASKREWARD_D->get_reward(me,"���ְ�",0,0,1,1,0,0,0);
			msg = "������ϧ�������д˼�������"+msg+"���Ұ������������ˡ�";
			me->add("job_time/���ְ�", -1);
			break;
		case 3:
                   TASKREWARD_D->get_reward(me,"���ְ�",0,0,1+random(1),4,0,0,0,this_object());
			gold = 1 +random(3);
			MONEY_D->pay_player(me, gold * 10000);
			msg = "���ĺã���Щ����"+RANK_D->query_respect(me)+"����ȥ�㻨���´λ���Ҫ����Ϊ�Ұ������";			
			break;
		default:
			msg = "�����������ˣ��뱨�濪����Ա��顣";
			me->add("job_time/���ְ�", -1);
			break;
	}
		

	me->delete_temp("changle");
	me->clear_condition("job_busy");
	me->set("job_name", "���ְ�");
	if ( objectp(ob= present("cu bu", me)))
		destruct(ob);

/*
	tell_object(me,HIW"����������"+chinese_number(exp)+"�㾭�飬"+chinese_number(pot)+"��Ǳ�ܣ����Ѿ�Ϊ���ְ����"+chinese_number(me->query("job_time/���ְ�"))+"�Ρ�\n"NOR);
*/
	return msg;
}

string ask_fail()
{
	object ob, me = this_player();
	int i;

	if (!me->query_temp("changle"))
		return "�������û�����������ʲô����";

	i = 40 - me->query_condition("job_busy");
	if ( i > 8 ) i = 8;
		me->apply_condition("job_busy", 9-i );

	if ( objectp(ob= present("cu bu", me)))
		destruct(ob);

	command("disapp "+ me->query("id"));
	me->delete_temp("changle");
	me->add("combat_exp", -(30+random(10)));
	return "��Ȼ���޷���ɣ���Ҳֻ������ˡ�";
}

string ask_times()
{
	object me = this_player();

	if ( !me->query("job_time/���ְ�"))
		return "��λ"+RANK_D->query_respect(me)+"����δΪ�����������";

	command("addoil "+ me->query("id"));
	return "��λ"+RANK_D->query_respect(me)+"�����Ѿ�Ϊ�������"+chinese_number(me->query("job_time/���ְ�"))+"���ˡ�";
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/changle/") == 0
	 || strsrch(room_name, "/d/city/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
            || strsrch(room_name, "/d/xiaoyao/") == 0
   || strsrch(room_name, "/d/quanzhen") == 0
   || strsrch(room_name, "/d/menggu/") == 0
   || strsrch(room_name, "/d/xiakedao/") == 0
   || strsrch(room_name, "/d/luoyang/") == 0    
   || strsrch(room_name, "/d/beijing/") == 0
         || strsrch(room_name, "/d/baituo/") == 0)
		return 0;
	return 1;
}

void die()
{
	object ob;
	if (!query_temp("living"))
	{
		ob = new("/d/changle/npc/bei");
		ob->move("/d/changle/xiaoting");
	}
	::die();
}

