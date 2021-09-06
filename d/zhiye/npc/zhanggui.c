// zhanggui
// by augx@sj  9/17/2001

#ifndef NPCDATA
#define NPCDATA		"/data/npc/"
#endif
#define SAVE_DIR	NPCDATA + "zhanggui1"
  
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#define CHECK_TIME	5

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

	set("chat_chance", 5);
 	set("chat_msg", ({
 		"�ƹ񽾰���˵�������������ı����ɶ�����õı�������\n",
 		"�ƹ�˵��������Щ�����ǿɶ��ǿ��Ҳŷ��˴�ơ���\n",
 	}) );
 	
	set("inquiry", ([
		"����"		: (: ask_money :),
		"money"		: (: ask_money :),
	]));
		
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin",99);
	
	call_out("check_var",CHECK_TIME*60);
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
	object obj = this_object();
	int value, rank;
	string target , saveid;

	if (!living(obj))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");

	if (!arg || sscanf(arg,"%d %s",value,target)<2 || !(ob = present(target, me)))
		return notify_fail("�ƹ�˵������Ҫ����ʲô��\n");

	if (query_temp("busy"))
		return notify_fail("�ƹ�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	
	if ( !(int)ob->query("imbued") )
		return notify_fail("�ƹ�˵��������ֻ��������������Ʒ��\n");
		
	rank = WORKER_D->weapon_rank(ob);
	if ( (int)ob->query("imbued")<3 || rank<=125 )
		return notify_fail("�ƹ�˵���������Ʒ������̫����ڱ��귷���ή�����ǵ������ġ�\n");

	ob->save_weapon(obj);
	ob->set_temp("quit_dest",1);
	
	saveid = "goods/" + ob->query("weapon_mp/save_id") + "/";
	obj->set(saveid+"time",time());
	obj->set(saveid+"value",value);
	obj->set(saveid+"rank",rank);
	obj->set(saveid+"type","weapon");
	obj->set(saveid+"seller",me->query("id"));
	obj->set(saveid+"seller2",me->query("name"));
	WORKER_D->save_zhanggui(obj);
	
	message_vision("$N��"+CHINESE_D->chinese_number(value)+"��"+HIY"�ƽ�"NOR+"�ļ۸������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, obj);
	ob->delete_weapon(me);
	destruct(ob);
	
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}

int do_list(string arg)
{
	object obj = this_object() , me = this_player();
	mapping mp , mp2;
	string * gkeys;
	mixed * gvalues;
	int i,j;
	
	if (!living(obj))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("�ƹ�˵��������æ���ء�\n");
		
	if (!arg)
		return notify_fail("�ƹ�˵������Ҫ����һ����Ʒ����weapon,armor,drug��\n");
		
	switch (arg) {
		case "weapon": break;
		case "armor":
		case "drug": return notify_fail("�ƹ�˵�����������Ʒ��û�п��ţ�\n");
		default: return notify_fail("�ƹ�˵������Ҫ����һ����Ʒ����weapon,armor,drug��\n");
	}
	
	if(!mapp(obj->query("goods"))) return notify_fail("�ƹ�˵����Ŀǰû�д�������Ʒ����\n");
	
	write(query("name") + "Ŀǰ���۵Ļ����У�\n");
	write("��������������������������������������������������������������������������������������\n");
	write("��  ��  ��                    ��  ��         �ȼ�  ����    ����          ����       ��\n");
	write("�ǩ�����������������������������������������������������������������������������������\n");
		
	j = sizeof(obj->query("goods"));
	gkeys = keys(obj->query("goods"));
	gvalues = values(obj->query("goods"));
	for(i=0;i<j;i++) {
		if( !mapp(gvalues[i]) ) continue;
		mp = gvalues[i];
		if (mp["type"]!=arg) continue;
		mp2 = obj->query("worker/"+gkeys[i]);

		write(sprintf("��%-26s%-16s%-6s%-6s%-12s%-14s��\n",
			mp2["name"]+"("+mp2["id"][0]+")",
			CHINESE_D->chinese_number(mp["value"])+"��"+HIY"�ƽ�"NOR,
			CHINESE_D->chinese_number(mp2["imbued"]),
			CHINESE_D->chinese_number(mp["rank"]),
			mp["seller2"]+"("+mp["seller"]+")",
			CHINESE_D->chinese_date(mp["time"])
		));
	}
	
	write("��������������������������������������������������������������������������������������\n");
		
	me->start_busy(1);		
	return 1;
}

int do_buy(string arg)
{
	return 1;
}

int do_getback(string arg)
{
	return 1;
}

string ask_money()
{
	return "";
}

void check_var()
{
}