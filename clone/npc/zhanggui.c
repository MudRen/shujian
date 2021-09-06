// zhanggui
// by augx@sj  9/17/2001

#ifndef NPCDATA
#define NPCDATA		"/data/npc/"
#endif
#define SAVE_DIR	NPCDATA + "zhanggui1"

#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#define CHECK_TIME	15

string ask_money();

void create()
{
	seteuid(getuid());
	restore();

	set_name("�ƹ�",({ "zhang gui","zhanggui" }) );
	set("gender", "����" );
	set("age", 45);
	set("long","����λ�����������ˡ�");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
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
	set_skill("duanzao", 150);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 3);
 	set("chat_msg", ({
 		"�ƹ񽾰���˵�������������ı����ɶ�����õı�������\n",
 		"�ƹ�˵��������Щ�����ǿɶ��ǿ��Ҳŷ��˴�ơ���\n",
 	}) );

	set("inquiry", ([
		"����"		: (: ask_money :),
		"money"		: (: ask_money :),
	]));

	set("no_clean_up",1);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin",99);

	if ( clonep() ) call_out("check_var" , CHECK_TIME*60);
}

string query_save_file()
{
	return SAVE_DIR;
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say ��ֻ��һ�����ˣ�ΪʲôҪɱ���أ�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say ��ֻ��һ�����ˣ�ΪʲôҪɱ���أ�");
	return 0;
}

void init()
{
	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");
	add_action("do_getback", "getback");
}

int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, rank , i;
	string target, saveid, detail, type;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");

	if (!arg || sscanf(arg,"%d %s detail %s",value,target,detail)<3 || !(ob = present(target, me)))
		return notify_fail("�ƹ�˵������Ҫ����ʲô��\n");

	if (query_temp("busy"))
		return notify_fail("�ƹ�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if ( !(int)ob->query("imbued") || !stringp(ob->query("save_id")) )
		return notify_fail("�ƹ�˵��������ֻ��������������Ʒ��\n");

	type = WORKER_D->imbued_object_type(ob->query("save_id"));

	if (type=="weapon")
		rank = WORKER_D->weapon_rank(ob);
	if (type=="armor")
		rank = WORKER_D->armor_rank(ob);

	if (type=="drug") {
		if ( (int)ob->query("imbued")>3 )
			return notify_fail("�ƹ�˵���������Ʒ������̫����ڱ��귷���ή�����ǵ������ġ�\n");
		rank = ob->query("lvl");
	}
	else {
		if ( (int)ob->query("imbued")<3 || rank<=125 )
			return notify_fail("�ƹ�˵���������Ʒ������̫����ڱ��귷���ή�����ǵ������ġ�\n");
	}
	
	if(stringp(ob->query("owner")) && ob->query("owner")!="" && ob->query("owner")!="0" )
		return notify_fail("����ɾ�����������˽�б�ǡ�\n");
	
	if ( (int)query("getback/"+ob->query("save_id")) )
		return notify_fail("�ƹ�˵���������Ʒ�㲻�Ǹո��û�ȥ����ô�������ˣ����Ұ���\n");

	if ( strlen((string)detail)<1 ) detail = "��";
	if ( strlen((string)detail)>80 )
		return notify_fail("�ƹ�˵�������˵��̫���ˣ�˵����Ҫ������ʮ�����֣�\n");

	if( value<50) return notify_fail("�ƹ�˵�����㿪�ļ۸�Ҳ̫���˰ɣ�\n");
	if( value>9999 ) return notify_fail("�ƹ�˵�����㿪�ļ۸�Ҳ̫���˰ɣ�\n");
	if( value>999 ) value = value - value%100;

	if( !ob->move(this_object()) )
		return notify_fail("BUG����֪ͨ��ʦ��\n");
	me->save();

	if (type=="weapon")
		ob->save_weapon(this_object());
	if (type=="armor")
		ob->save_armor(this_object());
	if (type=="drug")
		ob->save_drug(this_object());
	ob->set_temp("quit_dest",1);

	saveid = "goods/" + ob->query("save_id") + "/";
	if(ob->query("imbued")==3) i=24; else i=36;
	set(saveid+"name",ob->name());
	set(saveid+"time",time() + i*2 * 3600);
	set(saveid+"value",value);
	set(saveid+"rank",rank);
	set(saveid+"detail","˵����"+detail);
	set(saveid+"type",type);
	set(saveid+"seller",me->query("id"));
	set(saveid+"seller2",me->query("name"));
	save();

	message_vision("$N��"+MONEY_D->price_str(value*10000)+"�ļ۸������һ"+ob->query("unit")+ob->name() + "��$n��\n", me,this_object());
	log_file("career/jimai", sprintf("sell:%-8s:%-19s:%d:%-16s:%s\n",me->query("id"),ob->query("save_id"),ob->query("weapon_mp/utime")+ob->query("armor_mp/utime"),ob->name(),ob->query("id")), me);
	destruct(ob);

	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}

nosave string *sym_di = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });
string chinese_date(int date)
{
	mixed *local;

	local = localtime(date);
	return sprintf("%s��%s��%sʱ",
			chinese_number(local[LT_MON] + 1),
			chinese_number(local[LT_MDAY]),
			sym_di[((local[LT_HOUR] + 1) % 24) / 2]);
}

int do_list(string arg)
{
	object me = this_player();
	mapping mp , mp2;
	string * gkeys;
	mixed * gvalues;
	int i,j,k,t;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");

	if (!arg)
		return notify_fail("�ƹ�˵������Ҫ����һ����Ʒ����weapon,armor,drug��\n");

	switch (arg) {
		case "weapon":
		case "armor":
		case "drug": break;
		default: return notify_fail("�ƹ�˵������Ҫ����һ����Ʒ����weapon,armor,drug��\n");
	}

	if(!mapp(query("goods"))) return notify_fail("�ƹ�˵����Ŀǰû�д�������Ʒ����\n");

	write("Ŀǰ���۵Ļ����У����۸�λ���ƽ�\n");
	write("����������������������������������������������������������������������������������������������\n");
	write("��  ��  ��                        �۸�       �ȼ� ����  ����              ��������          ��\n");
	write("�ǩ�������������������������������������������������������������������������������������������\n");

	j = sizeof(query("goods"));
	gkeys = keys(query("goods"));
	gvalues = values(query("goods"));
	t = time() + 18*3600;
	for(i=0;i<j;i++) {
		if( !mapp(gvalues[i]) ) continue;
		mp = gvalues[i];
		if (mp["type"]!=arg) continue;
		mp2 = query("worker/"+gkeys[i]);

		k = (t - mp["time"])/3600;
		if (k < 0) k = 0;
		if (k > 18) k = 18;
		write(sprintf("��%-32s%-12s%-4s%4d%|20s%'.'-18s��\n",
			mp["name"]+"("+(arg=="drug"?mp2["yao"]:mp2["id"][0])+")",
			CHINESE_D->chinese_number(mp["value"]),
			arg=="drug"?CHINESE_D->chinese_number(mp2["imbued"]):CHINESE_D->chinese_number(6-mp2["imbued"]),
			mp["rank"],
			mp["seller2"]+"("+mp["seller"]+")",
			repeat_string("o", k)
		));
		write(sprintf("������%-86s��\n",mp["detail"]));
	}

	write("����������������������������������������������������������������������������������������������\n");

	me->start_busy(1);
	return 1;
}

int do_buy(string arg)
{
	object me = this_player();
	string name1,name2;
	mapping mp , mp2;
	string * gkeys;
	mixed * gvalues;
	int num,i,j;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");

	if (query_temp("busy"))
		return notify_fail("�ƹ�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if (!arg)
		return notify_fail("�ƹ�˵������Ҫ��ʲô��\n");

	if(!mapp(query("goods")))
		return notify_fail("�ƹ�˵������Ҫ��ʲô��\n");

	if( sscanf(arg,"%s %d",name1,num)==2 ) { num--; }
	else if( sscanf(arg,"%s %s %d",name1,name2,num)==3 ) { name1+=" "+name2; num--; }
	else { name1=arg; num=0; }

	j = sizeof(query("goods"));
	gkeys = keys(query("goods"));
	gvalues = values(query("goods"));
	for(i=0;i<j;i++) {
		if( !mapp(gvalues[i]) ) continue;
		mp = gvalues[i];
		mp2 = query("worker/"+gkeys[i]);

		if( (mp["type"]!="drug" && mp2["id"][0] == name1)
		 || (mp["type"]=="drug" && mp2["yao"] == name1) ) {
			if(num) {
				num--;
				continue;
			}

			switch( MONEY_D->player_pay(me, mp["value"]*10000) ) {
				case 0:
				case 2:	return notify_fail("��⵰��һ�ߴ���ȥ��\n");
				default: break;
			}

			message_vision("$N��"+MONEY_D->price_str(mp["value"]*10000)+"�ļ۸��$n����������"+mp["name"]+"��\n", me,this_object());
			log_file("career/jimai", sprintf("buy :%-8s:%-19s\n",me->query("id"),gkeys[i]), me);
			me->set("worker/"+gkeys[i],copy(mp2));
			me->save();
			WORKER_D->load_user_object(me,mp2);

			add("reward/"+mp["seller"],mp["value"]*10000);
			delete("worker/"+gkeys[i]);
			delete("goods/"+gkeys[i]);
			save();

			break;
		}
	}

	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	if(i>=j) return notify_fail("�ƹ�˵������Ҫ��ʲô��\n");
	return 1;
}

int do_getback(string arg)
{
	object me = this_player();
	string name1,name2;
	mapping mp , mp2;
	string * gkeys;
	mixed * gvalues;
	int num,i,j;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");

	if (query_temp("busy"))
		return notify_fail("�ƹ�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	if (!arg)
		return notify_fail("�ƹ�˵������Ҫȡ��ʲô��\n");

	if(!mapp(query("goods")))
		return notify_fail("�ƹ�˵������Ҫȡ��ô��\n");

	if( sscanf(arg,"%s %d",name1,num)==2 ) { num--; }
	else if( sscanf(arg,"%s %s %d",name1,name2,num)==3 ) { name1+=" "+name2; num--; }
	else { name1=arg; num=0; }

	j = sizeof(query("goods"));
	gkeys = keys(query("goods"));
	gvalues = values(query("goods"));
	for(i=0;i<j;i++) {
		if( !mapp(gvalues[i]) ) continue;
		mp = gvalues[i];
		mp2 = query("worker/"+gkeys[i]);

		if( (mp["type"]!="drug" && mp2["id"][0] == name1)
		 || (mp["type"]=="drug" && mp2["yao"] == name1) ) {
			if(num) {
				num--;
				continue;
			}

			if( mp["seller"] != me->query("id") )
				return notify_fail("�ƹ�˵���������Ʒ����������ġ�\n");

			message_vision("$N����ǰ������"+mp["name"]+"ȡ��ȥ�ˡ�\n", me);
			log_file("career/jimai", sprintf("back:%-8s:%-19s\n",me->query("id"),gkeys[i]), me);
			me->set("worker/"+gkeys[i],copy(mp2));
			me->save();
			WORKER_D->load_user_object(me,mp2);

			set("getback/"+gkeys[i],time()+86400); // 1 day
			delete("worker/"+gkeys[i]);
			delete("goods/"+gkeys[i]);
			save();

			break;
		}
	}

	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	if(i>=j) return notify_fail("�ƹ�˵������Ҫȡ��ʲô��\n");
	return 1;
}

string ask_money()
{
	object me = this_player();
	int money;

	if (me->is_busy() || me->is_fighting())
		return "����æ���ء�\n";

	if (query_temp("busy"))
		return "Ӵ����Ǹ�����������æ���ء��������Ժ�";

	money = (int)query("reward/"+me->query("id"));
	if ( money<=0 )
		return "��û�м�����Ʒ�������Ʒ��û������ȥ��";

	money = money * 7/8;
	MONEY_D->pay_player(me,money,1);
	delete("reward/"+me->query("id"));
	save();

	message_vision("$N�۳�������"+MONEY_D->price_str(money/7)+"���ܼƸ���$n"+MONEY_D->price_str(money)+"��\n",this_object(),me);
	return "�Ժ�㵽�ö������ɱ������չ�С������Ⱑ��";
}

void check_var()
{
	mapping mp;
	mixed * gvalues;
	string * gkeys;
	object ob;
	int i,j;

	remove_call_out("check_var");
	if( !environment(this_object()) ) return;

	if( mapp(query("getback")) ) {
		mp = query("getback");
		gkeys = keys(mp);
		gvalues = values(mp);
		for(i=0;i<sizeof(mp);i++) {
			if( !intp(gvalues[i]) ) continue;
			if( time() > gvalues[i] )
				delete("getback/"+gkeys[i]);
		}
	}

	if( mapp(query("goods")) ) {
		j = sizeof(query("goods"));
		gkeys = keys(query("goods"));
		gvalues = values(query("goods"));
		for(i=0;i<j;i++) {
			if( !mapp(gvalues[i]) ) continue;
			mp = gvalues[i];
			if( time()<mp["time"] ) continue;

			ob = WORKER_D->load_user_object( this_object() , query("worker/"+gkeys[i]) );
			log_file("career/jimai", sprintf("dele:%s\n",gkeys[i]));
			add("reward/"+mp["seller"],ob->query("value")*8/10);
			delete("worker/"+gkeys[i]);
			delete("goods/"+gkeys[i]);
			destruct(ob);
		}
		save();
	}

	call_out("check_var" , CHECK_TIME*60);
}
