// caifeng
// by augx@sj  10/9/2001

// Modified by mxzhao 2004/03/06 caijian => zhizao

#include "ansi.h"
#include <job_mul.h>
inherit NPC;
inherit F_VENDOR;
#include "/d/zhiye/npc/forbook.c"

#define RESET_TIME	15

string ask_job();
string ask_fail();
string ask_reward();
string ask_info();
string ask_list();

void create()
{
	set_name("�ϲ÷�",({ "lao caifeng","caifeng" }) );
	set("gender", "����" );
	set("age", 65);
	set("long",
"����λ���Ų�˹�ϻ��۾����ϲ÷죬�����������˲�֪����ٹ�����Ī��
��ӵ��������֯���һ���·�Ϊ�١�����������������ˣ��Լ��������֣�
��Ҫ�������ŵ�������ͽ���ѧ�������ˡ�");

	set("str", 35);
	set("dex", 55);
	set("con", 25);
	set("int", 35);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set_max_encumbrance(10000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
	set_skill("zhizao", 300);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/parry",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
		CYN"�ϲ÷�մմ��ϲ��˵�������������׬�˲���Ǯ����\n"NOR,
 		CYN"�ϲ÷�˵�����������ڲ����Լ�����֯���·��ˡ���\n"NOR,
 		CYN"�ϲ÷���ο��˵���������ںܶ������˶�������ѧϰ�ء���\n"NOR,
 		CYN"�ϲ÷�˵�������Ҳ�����֯�����õ��·����Ҽ�������ı��¿�Ҳ��һ������\n"NOR,
 		CYN"�ϲ÷�˵�����������·��Ŀ���̫���ˣ��Ҷ�����������˭������Ұ�����\n"NOR,
 	}) );

 	set("no_ansuan",1);
 	set("no_bark",1);

	set("inquiry", ([
		"����"		: (: ask_job :),
		"job"		: (: ask_job :),
		"����"		: (: ask_job :),
		"����"		: (: ask_fail :),
		"abandon"	: (: ask_fail :),
		"fangqi"	: (: ask_fail :),
		"���"		: (: ask_reward :),
		"����"		: (: ask_reward :),
		"reward"	: (: ask_reward :),
		"����"		: (: WORKER_D->ask_imbue("armor") :),
		"armor"		: (: WORKER_D->ask_imbue("armor") :),
		"����"		: (: ask_info :),
		"jianding"	: (: ask_info :),
		"������"        : (: ask_list :),
		"����"          : (: ask_list :)
	]));

	set("ask_user/123",1);
	set("forg_type","armor");

	set("vendor_goods", ({
		(["name":ARMOR_D("baihu-qiu"),"number": 5]),
		(["name":ARMOR_D("pifeng"),"number": 5]),
		(["name":ARMOR_D("green_silk"),"number": 5]),
		(["name":ARMOR_D("liyududou"),"number": 5]),
		(["name":ARMOR_D("changshan"),"number": 5]),
		(["name":ARMOR_D("changshan2"),"number": 5]),
		(["name":ARMOR_D("changshan3"),"number": 5]),
		(["name":ARMOR_D("changshan4"),"number": 5]),
		(["name":ARMOR_D("changshan5"),"number": 5]),
		(["name":ARMOR_D("qipao"),"number": 5]),
		(["name":ARMOR_D("xiupao"),"number": 5]),
		(["name":ARMOR_D("xiupao2"),"number": 5]),
		(["name":ARMOR_D("changqun"),"number": 5]),
		(["name":ARMOR_D("changqun2"),"number": 5]),
	}));

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/jiandao")->wield();
	add_money("coin",99);

	//if ( clonep() ) call_out("reset_var",RESET_TIME*60);
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say �Һ�����Թ�޳�Ϊ��Ҫ���ң�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say �Һ�����Թ�޳�Ϊ��Ҫ���ң�");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	//add_action("do_asktime", "asktime");
	add_action("do_jianding", "jianding");

	add_action("do_worker", "worker");
	add_action("do_taojiao","taojiao");
}



int do_worker(string arg)
{
	object me = this_player();
	string * str;

	if( getuid(me) != "ciwei" ) return 0;
	if( !arg || arg=="" ) arg = "help";

	str = explode(arg," ");
	switch (str[0]) {
		case "debug":
			WORKER_D->set_debug_mode();			
			tell_object(me,"��������ģʽ��\n");
			tell_object(me,"���棡�뾡������ʽվʹ�ô�ָ�������������� �رղ���ģʽ\n");
			break;
		case "nodebug":
			WORKER_D->unset_debug_mode();
			tell_object(me,"�رղ���ģʽ��\n");
			break;
		case "querytick":
			tell_object(me , sprintf("tick_count: %f\n",WORKER_D->query_tick_count()) );
			break;
		case "settick":
			//WORKER_D->set_tick_count(atoi(str[1]));
			WORKER_D->set_tick_count(str[1]);
			tell_object(me,"set tick_count ok.\n");
			break;
		case "help":
		default:
			tell_object(me,"���������debug ; nodebug ; querytick ; settick\n");
			break;
	}
	return 1;
}

int prevent_learn(object me, string skill)
{
	if (skill == "zhizao") return 0;
	return 1;
}

int is_apprentice_of(object me)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 150, level = ob->query_skill("zhizao", 1);

	if (level > 9) money = 300;
	if (level > 19) money = 600;
	if (level > 29) money = 1200;
	if (level > 39) money = 2500;
	if (level > 70) money = 3000;
	if (level > 140) money = 3500;	
	if (level > 220) return 0;
	
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"�����ڵ�ѧ����ÿ��"+MONEY_D->money_str(money)+"�����Ǯ������\n" ); return 0;
	}
	return 1;
}

////////////////////////////////////////////////////////////////////
int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (85 + trade_level) / 100;

	return value;
}

int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ϲ÷�˵��������æ���ء�\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("�ϲ÷�˵������Ҫ��ʲô��\n");

	if (ob->query("equipped"))
		return notify_fail("�ϲ÷�˵��������װ�����أ�����ж������˵�ɡ�\n");

	if (query_temp("busy"))
		return notify_fail("�ϲ÷�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if ( !(int)ob->query("imbued") || !mapp(ob->query("armor_mp/armor_prop")) )
		return notify_fail("�ϲ÷�˵������ֻ�չ����֯����ķ��ߡ�\n");

	if(stringp(ob->query("owner")) && ob->query("owner")!="" && ob->query("owner")!="0")
		return notify_fail("�㻹����������������˽�б�ǰɡ�\n");


	value = query_goods_value2(ob);
	message_vision("$N��"+MONEY_D->price_str(value)+"�ļ۸�������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, this_object());
	ob->delete_weapon(me);
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}

///////////////////////////// worker job ////////////////////////////
int check(object ob)
{
	object room;
	string room_name;

	if( !objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || !objectp(room=environment(ob))
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0
	 || strsrch(room_name, "/d/thd/") == 0
	 || strsrch(room_name, "/d/sld/") == 0)
		return 0;
	return 1;
}

#include <get_place.h>

string ask_job()
{
	object me = this_player() ,room ,oroom ,lastroom ,target, *living;
	int i,j,k,a,b;
	string * exits;

	if ( environment(me)->query("no_zhiye"))
		return "������ûʲô����Ҫ����";
	//if( me->query_skill("bianzhi",1)<10 )
		//return "��ı�֯����̫���ˣ��ҿɲ���������ȥ���¡�";
	if( me->query_skill("zhizao",1)<10 )
		return "���֯�켼��̫���ˣ��ҿɲ���������ȥ���¡�";
	//if( me->query_skill("bianzhi",1)>=395 )
		//return "��ı�֯������ô���ˣ��ҿɲ��������������������ˡ�";
	if( me->query_skill("zhizao",1)>=395 )
		return "���֯�켼����ô���ˣ��ҿɲ��������������������ˡ�";
	if( !wizardp(me) && me->query("worker/job3") && time()<(int)me->query("worker/job3_time") )
		return "�Ҳ��ǽ��㵽"+me->query("worker/job3_oroom")+"����ȥ�����Ҫ��˹��˿����";
	if( !wizardp(me) && time()<(int)me->query("worker/job3_time") )
		return "��̫æ�˰ɣ�Ҫע����Ϣ����";

	living = livings();
	for (i=0;i<sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if( check(living[j]) ){
			target = living[j];
			room = environment(target);
			if( !mapp(room->query("exits")) || sizeof(room->query("exits"))<1 ) continue;

			if( get_place(base_name(room))!="" ) {
				oroom = room;
				lastroom = room;
				j = 1+random(9);
				for(k=0;k<j;k++) {
					exits = values(room->query("exits"));
					b = sizeof(exits);
					while( (a=random(b))>=0 && b>1 ) {
						if (b==2)
							if ((exits[0]==base_name(lastroom) && exits[1]==base_name(oroom))
							 || (exits[1]==base_name(lastroom) && exits[0]==base_name(oroom)))
								break;
						if (exits[a]==base_name(lastroom) || exits[a]==base_name(oroom)) continue;
						break;
					}
					lastroom = room;
					if( !(room = find_object(exits[a])) )
						if( !(room = load_object(exits[a])) )
							break;
				}
				if(k<j) continue;
				break;
			}
		}
	}

	if( !target || !room )
		return "�����ûʲô���⣬���һ��������ɡ�";

	target = new(__DIR__"customer2");
	target->set("player",me->query("id"));
	target->move(room);

	me->set("worker/job3",1);
	me->set("worker/job3_oroom",get_place(base_name(oroom))+oroom->query("short"));
	me->set("worker/job3_far",j);
	me->set("worker/job3_finish",0);
	me->set("worker/job3_target",target->query("name"));
	me->set("worker/job3_room",base_name(room));
	me->set("worker/job3_time",time()+30*60);
	//me->set_temp("worker/job3_bianzhi",0);
	me->set_temp("worker/job3_zhizao",0);
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,base_name(oroom)+" -> "+base_name(room)+"\n");

	command("look "+me->query("id"));
	command("whisper "+me->query("id")+" �и���"+me->query("worker/job3_target")+"�Ŀ���Ҫ�����·�����ȥ������ȡ��ԭ�ϣ�\n����"
		+me->query("worker/job3_oroom")+"��Χ��Բ"+CHINESE_D->chinese_number(me->query("worker/job3_far"))+"��֮�ڡ�" );
	return "��ȥ��ذ���";
}

string ask_fail()
{
	object me = this_player() , bu;

	if( !me->query("worker/job3")
	 || time()>=(int)me->query("worker/job3_time")
	 || environment(me)->query("no_zhiye"))
		return "��Ҫ����ʲô��";

	me->delete("worker/job3");
	me->delete("worker/job3_oroom");
	me->delete("worker/job3_far");
	me->delete("worker/job3_target");
	me->delete("worker/job3_room");
	me->delete("worker/job3_finish");
	///me->delete_temp("worker/job3_bianzhi");
	me->delete_temp("worker/job3_zhizao");

	while ( objectp(bu = present("bosi caisi", me)) ) destruct(bu);
	while ( objectp(bu = present("bosi caichou", me)) ) destruct(bu);
	while ( objectp(bu = present("bosi cai", me)) ) destruct(bu);
	command("emote ȡ�ر߽��ϡ�");

	me->set("worker/job3_time",time()+(3+random(4))*60);
	command("disapp " + me->query("id"));
	return "û�뵽����ô�����ã�";
}

string ask_reward()
{
	object me = this_player();
	int improve,lvl,exp;

	if( !me->query("worker/job3") 
	|| environment(me)->query("no_zhiye"))
		return "����û���ҸɻҪʲô���꣡";

	if( !me->query("worker/job3_finish") )
		return "�㻹û����������أ�Ҫʲô���꣡";

	me->delete("worker/job3");
	me->delete("worker/job3_oroom");
	me->delete("worker/job3_target");
	me->delete("worker/job3_far");
	me->delete("worker/job3_room");
	me->set("worker/job3_time",time()+ 30 + random(60));
	
	///////
	////limit 220

	lvl = (int)me->query_skill("zhizao",1);
	improve = (300 + lvl/2) * 7/5;
	improve = improve * me->query("worker/job3_finish");
	improve = improve*2/3 + random(improve*2/3);
	//improve = improve*ZY_ZHIZAO_JOB_MUL/100;
	exp = improve/6;
		
	exp = me->add_exp_combat( exp ,this_object(),"֯������",1);
	//me->add("combat_exp", exp);
		
	command("applaud " + me->query("id"));	
	improve = WORKER_D->check_impove(me,"zhizao",improve,2);
	if(improve >0 ){
		me->add_temp("worker/job3_zhizao",improve);
		tell_object(me, HIC"�ϲ÷���ϸ���㽲��֯��ľ��ϣ����֯�켼��������"+CHINESE_D->chinese_number(improve)+"�㼼�ܵ�������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"+
			"    �˴��������ܹ�������"+CHINESE_D->chinese_number(me->query_temp("worker/job3_zhizao"))+"��֯�켼�ܡ�\n"NOR);
	}
	else
	tell_object(me, HIC"����"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"+
			"    �˴��������ܹ�������"+CHINESE_D->chinese_number(me->query_temp("worker/job3_zhizao"))+"��֯�켼�ܡ�\n"NOR);
	log_file("job/wzhizao",sprintf("%s(%s)��֯�죺%d�����飺%d����exp��%d\n", me->name(), me->query("id"),me->query_temp("worker/job3_zhizao"),exp,me->query("combat_exp")),me);

	me->delete("worker/job3_finish");
	//me->delete_temp("worker/job3_bianzhi");
	me->delete_temp("worker/job3_zhizao");

	return "�����������з�չǰ;����";
}

///////////////////////////////////////////////////////////////////////
string ask_list()
{
	WORKER_D->show_rank(this_player(),"armor");
	return RANK_D->query_respect(this_player())+"����Ŷ��";
}
string ask_info()
{
	return
"�����Ҫ������ķ��ߣ�����ʹ�����jianding ������ϸ�̶� ����id
���ṩ��ѵļ򵥼����������Ҫ֪�����ߵ���ϸ��Ϣ��Ҫ���Ʒѵ��ˣ�hehe......

������ϸ�̶ȣ�
	1. �򵥼���		�۸����
	2. ����ϸ�ļ���		�۸�ʮ���ƽ�
	3. ��ϸ�ļ���		�۸���ʮ���ƽ�
	4. ����ϸ�ļ���		�۸�һ�ٶ��ƽ�
	5. ��ȫ����		�۸����ٶ��ƽ�
";
}

protected string make_info(int base,int rnd)
{
	int i =  base / rnd;
	if(rnd>1)
		return CHINESE_D->chinese_number(i*rnd) +" �� "+ CHINESE_D->chinese_number((i+1)*rnd-1);
	else
		return CHINESE_D->chinese_number(base);
}

int do_jianding(string arg)
{
	object me = this_player() , wp;
	string wpname , str;
	mapping mp;
	int lvl,money, a1,a2,a3,a4;

	if (!arg) return notify_fail(CYN"�ϲ÷�˵������Ҫ����ʲô���ߣ�\n"NOR);
	if (me->query_busy()) return notify_fail(CYN"�ϲ÷�˵��������æ���أ�\n"NOR);
	if (query_temp("busy")) return notify_fail(CYN"�ϲ÷�˵��������æ���أ�\n"NOR);
	if (sscanf(arg,"%d %s",lvl,wpname)<2 || !objectp(wp=present(wpname, me)) )
		return notify_fail("��Ҫ����ʲô���ߣ�\n");
	if ( !wp->query("imbued") || !mapp(wp->query("armor_mp/armor_prop")) )
		return notify_fail(CYN"�ϲ÷�˵������ֻ�ܼ����������ķ��ߡ�\n"NOR);

	switch(lvl) {
		case 1: money=  0; break;
		case 2: money= 10*10000; break;
		case 3: money= 50*10000; break;
		case 4: money=100*10000; break;
		case 5: money=300*10000; break;
		default: return notify_fail(CYN"�ϲ÷�˵������Ҫ������ʲô�̶ȣ�\n"NOR);
	}

	if(money>0) {
		switch( MONEY_D->player_pay(me,money) ) {
			case 0:
			case 2:	return notify_fail(CYN"�ϲ÷�˵�������Ǯ��������\n");
			default: break;
		}
		message_vision("$N����$n"+MONEY_D->price_str(money)+"����$n����"+wp->query("name")+"��\n", me,this_object());
	}
	else message_vision("$N��$n����"+wp->query("name")+"��\n", me,this_object());

	command("say �˼����ߵı���ǣ�"+wp->query("armor_mp/save_id")+"    "+
		"���ߵȼ�Ϊ��"+CHINESE_D->chinese_number(6-wp->query("imbued"))+"    "+
		"�ۺ����ۣ�"+CHINESE_D->chinese_number(WORKER_D->armor_rank(wp)));
	if(lvl==1) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}

	switch(lvl) {
		case 2: a1=30; a2=10; a3=1000; break;
		case 3: a1=20; a2= 5; a3= 600; break;
		case 4: a1=10; a2= 3; a3= 300; break;
		case 5: a1= 1; a2= 1; a3=   1; break;
	}
	command("say ��������"+make_info(wp->query("armor_prop/armor"),a1)+"    "+
		"��ֵ��"+make_info(wp->query("value")/10000,a2)+"  ���ƽ�\n	      "+
		"�;ö�/����;öȣ�"+make_info(wp->query("armor_mp/dur"),a3)+" / "+make_info(wp->query("armor_mp/max_dur"),a3) );
	if(lvl<=3) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}

	switch(lvl) {
		case 4: a1=25; a2=100; a3=2000; break;
		case 5: a1= 1; a2=  1; a3=   1; break;
	}

	if( !mapp(wp->query("armor_mp/armor_prop")) ) {
		set_temp("busy", 1);
		call_out("delete_temp", 1, "busy");
		return 1;
	}
	else {
		mp = wp->query("armor_mp/armor_prop");
	}

	str = "say �������ԣ�\n	      ";	a4 = 0;
	if( !undefinedp(mp["qi"]) ) { str+="��������"+make_info(mp["qi"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["jing"]) ) { str+="���Ӿ���"+make_info(mp["jing"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["neili"]) ) { str+="����������"+make_info(mp["neili"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["jingli"]) ) { str+="���Ӿ�����"+make_info(mp["jingli"],1); a4++; }
	if( a4>0 ) { str+="\n	      "; a4=0; }

	if( !undefinedp(mp["strength"]) ) { str+="���ӱ�����"+make_info(mp["strength"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["intelligence"]) ) { str+="�������ԣ�"+make_info(mp["intelligence"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["constitution"]) ) { str+="���Ӹ��ǣ�"+make_info(mp["constitution"],1); a4++; }
	if( a4>0 ) if( a4<=1 ) str+="    "; else { str+="\n	      "; a4=0; }
	if( !undefinedp(mp["dexerity"]) ) { str+="��������"+make_info(mp["dexerity"],1); a4++; }
	if( a4>0 ) { str+="\n	      "; a4=0; }

	if( (int)wp->query("poison_number") ) str+="���ԣ�"+make_info(wp->query("poison_number"),a2)+"\n	      ";
	if( !undefinedp(mp["parry"]) ) str+="���ӷ�����"+make_info(mp["parry"],a1)+"\n	      ";
	if( !undefinedp(mp["dodge"]) ) str+="���Ӷ�ܣ�"+make_info(mp["dodge"],a1)+"\n	      ";
	if( !undefinedp(mp["armor_vs_force"]) ) str+="�����ڹ����ԣ�"+make_info(mp["armor_vs_force"],a1)+"\n	      ";

	if( (int)wp->query("storeneili") ) str+="����������"+make_info(wp->query("storeneili"),a3)+"\n	      ";
	if( (int)wp->query("storetimes") ) str+="���ı��ʣ�"+make_info(wp->query("storetimes"),a1)+"��\n	      ";
	if( (int)wp->query("decdamage") )  str+="�����˺���"+make_info(wp->query("decdamage"),a1)+"��\n	      ";

	command(str);

	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");
	return 1;
}
//******************************************************************************
/*
void reset_var()
{
	remove_call_out("reset_var");
	delete("ask_user");
	call_out("reset_var",RESET_TIME*60);
}

int do_asktime(string arg)
{
	object me = this_player() , wp;
	int delay;

	if (!arg) return notify_fail(CYN"�ϲ÷�˵������Ҫ��ѯʲô���ߣ�\n"NOR);
	if (me->query_busy()) return notify_fail(CYN"�ϲ÷�˵��������æ���أ�\n"NOR);
	if ( !objectp(wp = present(arg, me)) )
		return notify_fail("������û��������ߡ�\n");
	if ( !wp->query("imbued") )
		return notify_fail(CYN"�ϲ÷�˵������ֻ�ܲ�ѯ�������ķ��ߡ�\n"NOR);
	if ( wp->query("imbued")<=3 )
		return notify_fail(CYN"�ϲ÷�˵�������������߲���Ҫ���¡�\n"NOR);
	if ( (int)query("ask_user/"+me->query("id"))>0 )
		return notify_fail(CYN"�ϲ÷�˵������ող�ѯ������ô�����ˣ�\n"NOR);

	WORKER_D->update_UniqueValues("querytime","save_id="+wp->query("armor_mp/save_id"),"time-"+wp->query("armor_mp/save_id"));
	tell_object(me,CYN"�ϲ÷�˵�����ðɣ��Ұ������һ�£����Ե�......\n"NOR);

	delay = 20;
	if(wizardp(me) && me->query("env/test")) delay = 5;
	me->start_busy(delay);
	call_out("asktime_finish",delay,me,wp);
	return 1;
}

void asktime_finish(object me,object wp)
{
	int t;

	if ( !objectp(me) || !userp(me) || !objectp(wp) ) return;
	t = WORKER_D->query_UniqueValues("querytime","time-"+wp->query("armor_mp/save_id"));
	tell_object(me,CYN"�ϲ÷�˵������ķ��߱��Ϊ��"+wp->query("armor_mp/save_id")+"��\n"NOR);
	if(t<0)
		tell_object(me,CYN"�ϲ÷�˵������Ҳ��֪������ʱ�䣬���ܵ�ԭ���ǣ���������޷�����ͬ����������\n"NOR);
	else
		tell_object(me,CYN"�ϲ÷�˵�������������ߵĸ���ʱ��Ϊ��"+CHINESE_D->chinese_date(t,1)+"��\n"NOR);
	set("ask_user/"+me->query("id"),1);
}

void tell_limit(object me)
{
	int v1,v2,v3,v4;

	if (!objectp(me) || !userp(me)) return;

	v1 = WORKER_D->query_UniqueValues("queryarmor","");
	v3 = WORKER_D->query_UniqueValues("queryarmor2","");
	if(v1<0) {
		tell_object(me,CYN"�ϲ÷�˵������Ҳ��������ѽ�����ܵ�ԭ���ǣ���������޷�����ͬ����������\n"NOR);
	}
	else {
		v2 = v1 / 0x10000;
		v1 = v1 % 0x10000;
		v4 = v3 / 0x10000;
		v3 = v3 % 0x10000;
		tell_object(me,CYN"�ϲ÷�˵������˵�������������й���"+CHINESE_D->chinese_number(v2)+"��ͷ�ȷ��ߣ�"+CHINESE_D->chinese_number(v4)+"�����ȷ��ߡ�\n"NOR);
		tell_object(me,CYN"�ϲ÷�˵������˵����������������"+CHINESE_D->chinese_number(v1)+"��ͷ�ȷ��ߣ�"+CHINESE_D->chinese_number(v3)+"�����ȷ��ߡ�\n"NOR);
	}
	////////////////////////////
	if( WORKER_D->update_UniqueValues("queryarmor","","") > 1 ) {
		delay = 2;
		me->start_busy(delay);
		call_out("tell_limit",delay,me);
		return "��������......";
	}
	else {
		delay = 20;
		if(wizardp(me) && me->query("env/test")) delay=5;
		me->start_busy(delay);
		call_out("tell_limit",delay,me);
		return "�����Ҫ���ʱ��˲�֪�������һ��......";
	}
	
}
*/
