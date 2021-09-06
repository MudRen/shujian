//Cracked by Roath
// ma-fu.c ���
// cleansword 12/25/96

inherit NPC;
inherit F_DEALER;

string ask_me_buy();
string ask_me_sell();
string ask_me_feed();
string ask_me_rent();

void create()
{
	set_name("���", ({ "ma fu", "fu", "pawn" }) );
	set("gender", "����" );
	set("age", 20+random(20));
	set("long",
		"����λ��ʵ�ͽ��������ͷ�󺹣���������մ���˲���м���������Űѷ�����ա����\n");
	set("combat_exp", random(5000));
	set("attitude", "friendly");
	set("no_get", 1);

	set("inquiry", ([
		"����" : (: ask_me_buy  :),
		"����" : (: ask_me_sell :),
		"ι��" : (: ask_me_feed :),
		"����" : (: ask_me_rent :),
	]));

	set("vendor_goods", ({
		"/d/shaolin/obj/caoliao",
		"/d/shaolin/obj/hulu",
	}));

	setup();
}

void init()
{	
	object me, ob, env, *inv;
	mapping exits;
	string *dirs;
	int i;

	me = this_object();
	ob = this_player();
	env = environment(me);
	inv = all_inventory(env);

	if( ob->query("race") == "Ұ��"
	&& mapp(exits = environment()->query("exits")) 
	&& query("jingli") < query("max_jingli") / 2 ) {
//		dirs = keys(exits);
//		message_vision("���һ�����Ʋ����æ���˳�ȥ��\n", ob);
        message_vision("\nͻȻ��ֻ��$N����ο�һ�Ѳ��ϣ�����¶��һ�����ţ����˽�ȥ���������߰��������ˡ�\n",
		this_object());
		destruct(this_object());
//		command("go " + dirs[random(sizeof(dirs))]);
	}

	for( i=0; i<sizeof(inv); i++ ) {
		if( inv[i]->query("race") == "����" && inv[i]->query_lord() == ob ) {
			if( !living(inv[i]) ) {
				command("say �͹٣��������ι�ȥ�ˣ�������Ū������");
				message_vision("�����һͰˮ���������ϣ�\n", ob);
				inv[i]->revive();
			} else command("say �͹٣�����������������Ͱ���ǣ������");	

			inv[i]->set_leader(ob);
			if( !ob->query("rided") ) {
				inv[i]->set("rider", ob);
				ob->set("rided", inv[i]);
				ob->delete_temp("horse_guest");
				remove_call_out("byebying");
				call_out("byebying", 3, ob);
			}

			return;
		}
	}

	if( ob->query_temp("horse_guest") ) {
		say("����ɥ���������͹٣�ʵ�ڶԲ������Ҳ����������� ... \n");
		command("say �����ǲ�������һƥ��ˣ� �������������ۣ�");
		ob->delete_temp("horse_guest");
		ob->set_temp("horse_loser", 1);
		return;
	}

	if( interactive(ob) && ob->query("race") == "����" && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_train", "train");
	add_action("do_train", "xun");
}

void greeting(object ob)
{
	object animal;
	mapping exits;
	string *dirs;

	if( !ob || environment(ob) != environment() ) return;

	if( objectp(animal = ob->query("rided")) && environment(animal) == environment() ) {
		if( animal->query("race") == "Ұ��"
		&& mapp(exits = environment()->query("exits")) ) {
//			dirs = keys(exits);
//			message_vision("���һ�����Ʋ����æ���˳�ȥ��\n", ob);
        message_vision("\nͻȻ��ֻ��$N����ο�һ�Ѳ��ϣ�����¶��һ�����ţ����˽�ȥ���������߰��������ˡ�\n",
		this_object());
		 	destruct(this_object());	
//			command("go " + dirs[random(sizeof(dirs))]);		
		} else say("���С�����˹�����Ц�����͹ٿ���Ҫ������ι���ڣ��뾡�ܷԸ���\n");
	} else {
		switch( random(2) ) {
		case 0:
			say( "����ͷ������˵������λ�͹٣����뵽������һƥ����ɣ�\n");
			break;
		case 1:
			say( "���Ц����˵������λ�͹������������������Ǹ����������������ơ�\n");
			break;
		}
	}
}

void byebying(object ob, object horse)
{
	if( !ob || environment(ob) != environment() || !horse) return;
	message_vision("\n�������ذ�$Nǣ�˹���������$n������ȥ��\n\n", horse, ob);
	say("�����ֵ����͹����ߣ��´�����ѽ��\n");
}

int accept_object(object ob, object money)
{
	object me, horse, env, *inv;
	string name;
	int i, value;

	me = this_object();
	env = environment(me);
	inv = all_inventory(env);

	if(!money->query("money_id")) {
		say("�����ֵ����Բ���С�Ĳ������ն�����\n");
		return 0;
	}

	if( ob->query_temp("horse_guest") && !ob->query_temp("horse_loser") ) {	
		if( money->value() >= 100 + random(500) ) {
			say("������˵������л���͹�����ģ��������һ����Ϻõģ�\n");
			for( i=0; i<sizeof(inv); i++ ) {
				if( inv[i]->query("race") == "����" && inv[i]->query_lord() == ob ) {
					if( !living(inv[i]) ) inv[i]->revive();
					message_vision("����¾Ͱ���ǣ����۱�ι��\n", ob);

					inv[i]->set("water", inv[i]->max_water_capacity() * 8 /10 );
					inv[i]->set("food", inv[i]->max_food_capacity() * 8 /10 );
					inv[i]->set("jingli", inv[i]->query("max_jingli") * 8 /10 );
					return 1;
				}
			}
		} else {
			say("����ͷЦ����С�Ķ�л�͹��ˣ�������\n");
			command("bow " + ob->id());
			return 1;
		}
	} else {
		if( objectp(horse = ob->query_temp("horse_asked")) ) {
			if( ob->query("horse_loser"))
				value = horse->query("value") * 50;
			else	value = horse->query("value") * 100;

			if( money->value() >= value ) {
				say("���һ�����ص�ͷ�������˹��ˣ�����Ͱ�" +
			horse->query("name") +"ǣ����������\n");	

				horse->set_lord(ob);
				horse->set_leader(ob);

				if( !ob->query("rided") ) {
					horse->set("rider", ob);
					ob->set("rided", horse);
					ob->delete_temp("horse_asked");
					remove_call_out("byebying");
					call_out("byebying", 3, ob, horse);
				}
				return 1;
			} else {
				say("���ס����֣�ҡͷ�����Բ��𣬿͹١����Ǯ������\n");
				return 0;
			}
		} else {
			say("���ҡͷ�����͹ٸ�С���������������������ڴ���ƥ����\n");
			return 0;
		}
	}

	return 1;
}

int do_train(string arg)
{
	object me, ob, animal, xunbu1, xunbu2, butou;

	me = this_object();
	ob = this_player();

	if(ob->is_fighting()){
		say("����æ���أ�\n");
	return 1;
	}
	if( stringp(arg) && arg != 0 
	&& objectp(animal = present(arg, environment())) 
	&& animal->query("race") == "����" 
	&& !me->is_fighting() ) {
		message_vision("����һ��������ͷ����͵��˵�ճ���$N�ͳ��˹�����\n", ob);
//		command("chat ��������" + ob->query("name") + "���"
//		+  RANK_D->query_rude(ob) + "��͵��");
//		me->kill_ob(ob);
//		message_vision("��ͷ������λѲ������ææ���˽�����\n", ob);
		ob->apply_condition("killer", 100);
/*		xunbu1=new("/d/city/npc/xunbu");
		xunbu1->move(environment(ob));
		xunbu1->set_leader(ob);
		xunbu1->kill_ob(ob);
		xunbu2=new("/d/city/npc/xunbu");
                xunbu2->move(environment(ob));
                xunbu2->set_leader(ob);
                xunbu2->kill_ob(ob);
		butou=new("/d/city/npc/xunbu");
                butou->move(environment(ob));
                butou->set_leader(ob);
                butou->kill_ob(ob);
*/
		return 1;
	}

	return 0;
}

int do_say(string arg)
{
	object ob, horse, *inv;
	string name;
	int i, value;

	ob = this_player();
	inv = all_inventory(environment());

	if( objectp(horse = ob->query_temp("horse_asked")) ) {
		if( arg == "����" )
			say("���Ц�����ǺǺǣ��Ǿ͸�Ǯ�ɣ��͹٣�\n");
		if( arg == "������" )
			say("���Ц����û��ϵ���͹���������һƥ�ɣ�\n");
		return 1;
	}

	if( stringp(arg) && arg != 0 ) {
		for( i=0; i<sizeof(inv); i++ ) {
			if( inv[i]->query("race") == "����" && inv[i]->query("name") == arg ) {
				if( inv[i]->query_lord() )
					ob->set_temp("horse_else", inv[i]);
				else	ob->set_temp("horse_asked", inv[i]);
			}
		}
		
		if( objectp(horse = ob->query_temp("horse_asked")) && horse->name() == arg ) {
			say("�������͹ٺ���������ƥ" + horse->name() + "ֻҪ" 
			+ chinese_number(horse->query("value")) + "�����ӣ������ⲻ��\n");
			return 1;
		}

		if( objectp(horse = ob->query_temp("horse_else")) && horse->name() == arg ) {
			say("�������͹٣���ƥ���Ǳ��˼�������ģ���������\n");
			ob->delete_temp("horse_else");
			return 1;
		}		
	}
//	remove_action("do_say", "say");
	
	return 0;
}

string ask_me_buy()
{
	object *inv;
	string word;
	int i, j;

	inv = all_inventory(environment());

	if( sizeof(inv) < 1 )
	return "���������˵Ŀ���̫�࣬���������Ѿ�û������ˣ�";

	say("���˵�������ƣ�\n");
	for( i=0; i<sizeof(inv); i++ ) {
		if( inv[i]->query("race") == "����" ) {
			j++;
			if( objectp(inv[i]->query_lord()) ) word = "�������ˡ�\n";
			else word = "ֵ" + chinese_number(inv[i]->query("value")) + "�����ӡ�\n";
			say("	��" + chinese_number(j) + "ƥ" + inv[i]->name() + word);
		}
	}

	add_action("do_say", "say");
	return "���������е��Ǻ�����˵Ҫ��һƥ�ɣ�";
}

string ask_me_sell()
{
	object ob, horse, silver;
	int value;

	ob = this_player();	

	if( objectp(horse = ob->query("rided")) && environment(horse) == environment() ) {
		if( horse->query("qi") <= horse->query("max_qi")/10 
		||  horse->query("jing") <= horse->query("max_jing")/10 
		||  horse->query("jingli") <= horse->query("max_jingli")/10 )
			return "���������ˣ���������������";
		if( horse->query("baituo"))
			return "С��ֻ��һ���Դ�������ɽ���˵�����ɲ�����ġ�";
		else {
			value = horse->query("value")/2;

			horse->set_lord(0);
			horse->set_leader(0);
			horse->delete("rider");
			ob->delete("rided");

			silver=new("/clone/money/silver");
			silver->set_amount(value);
			silver->move(ob);

			message_vision("�����ͷ���Ӹ�$N�������ӡ�����ǣ����������������һ�ԡ�\n", ob);

			return "��ƥ�������ֳ�ֻ��������ĥ����" 
			+ chinese_number(value) + "�����Ӱɣ�";
		}
	} else return "���أ�";
}

string ask_me_feed()
{
	object ob, horse;
	ob = this_player();	

	if( objectp(horse = ob->query("rided")) && environment(horse) == environment() ) {
		horse->set_leader(0);
		horse->delete("rider");
		ob->delete("rided");
		ob->set_temp("horse_guest", 1);

		message_vision("���ǣ����������������һ�ԡ�\n", ob);
		return "�͹ٷ��ģ��������һ��տ��õġ�";
	} 
	else 	return "���أ�";
}

string ask_me_rent()
{
	return "������������û����⣡";
}
int accept_kill(object me)
{
	object xunbu1, xunbu2, butou;
	if (!this_object()->is_fightin()){
	command("chat ��������" + me->query("name") + "���"
	+  RANK_D->query_rude(me) + "��͵��");
        me->apply_condition("killer", 100);
        return 1;
	}
}
void unconcious()
{
        message_vision("\nͻȻ��ֻ��$N����ο�һ�Ѳ��ϣ�����¶��һ�����ţ����˽�ȥ���������߰��������ˡ�\n",
                this_object());
        destruct(this_object());
}

