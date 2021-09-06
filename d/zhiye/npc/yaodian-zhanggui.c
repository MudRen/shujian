// yaodian zhanggui
// by augx@sj  3/4/2002

// Modified by mxzhao 2004/03/06
// By Spiderii ���ҩ���������������ҳɳ���
#include "ansi.h"
inherit NPC;

string ask_job();
string ask_fail();
string ask_reward();
string ask_limit();
int ask_liaoshang();
nosave string yao_path = "/d/zhiye/obj/yao";

void add_yao(object yao)
{
	add("vendor_goods", ({
		([	"name"	: yao_path,
                        "number": 99,
			"short"	: yao->short(),
			"value"	: yao->query("value"),
			"id"	: yao->query("id"),
		]),
	}));
}


void create()
{
	object yao,me;

	set_name("ҩ���ƹ�",({ "yaodian zhanggui","zhanggui" }) );
	set("gender", "����" );
	set("age", 51);
	set("long","����λ�Ͱ����׵����˼ң��ڴ�����ҩƷ�Ѿ������ˡ�");

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
	set_skill("liandan", 220);

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
 		CYN"ҩ���ƹ�˵���������û��ʲô�õ�ҩ�ﰡ����\n"NOR,
 		CYN"ҩ���ƹ��Ĺ���˵�����������費��Ҫѧϰ������������������ѧϰ����ѧ��ô.....�ٺ١�\n"NOR,
 		CYN"ҩ���ƹ�˵������������̫æ���߲�����˭�ܰ��Ұѿ��˶��Ƶ�ҩƷ����ȥ����\n"NOR,
 	}) );

 	set("no_ansuan",1);
 	set("no_bark",1);
    set("inquiry", ([
		"����" : (:ask_liaoshang:),//for newbie
    ]));
/*
	set("inquiry", ([
		"����"		: (: ask_job :),
		"job"		: (: ask_job :),
		"����"		: (: ask_job :),
		"����"		: (: ask_fail :),
		"abandon"	: (: ask_fail :),
		"���"		: (: ask_reward :),
		"����"		: (: ask_reward :),
		"reward"	: (: ask_reward :),
		"��ҩ"		: (: ask_limit :),
		"drug"		: (: ask_limit :),
	]));
*/
	set("vendor_goods", ({ }));
	me = this_object();

	// add yao
	yao = new(yao_path);
	yao->set_type("yangjing dan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("buqi wan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("xujing dan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("neixi wan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("bushi dan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("bushui wan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("jinchuang yao",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("liaojing dan",me->query_skill("liandan",1),5000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("zhengqi dan",me->query_skill("liandan",1),10000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("xieqi wan",me->query_skill("liandan",1),10000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("yannian dan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("fuling wan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("danggui dan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("chuanbei wan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("chantui yao",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("huoxue dan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	yao = new(yao_path);
	yao->set_type("jiedu wan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);

	// test
	/*
	yao = new(yao_path);
	yao->set_type("huangqi dan",me->query_skill("liandan",1),20000,sprintf("zhanggui%dd",time()),me,0);
	add_yao(yao); destruct(yao);
	*/

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/yaochui")->wield();
	add_money("coin",99);
}
//for newbie
int ask_liaoshang()
{
	object ob;
	ob=this_player();
	if(ob->query("combat_exp")<3000) 
	{
		command("? "+ob->query("id"));     
		command("say ����ô����ݳ����˰����������Σ�հ���\n");
		command("poor "+ob->query("id"));
		return 1;
	}
	if(ob->query("combat_exp")>50000) 
	{
		command("? "+ob->query("id"));     
		command("say ���ˣ���Ǯ��ҩ������ƽ���ۣ�ͯ�����ۣ�\n");
		command("knock "+ob->query("id"));
		return 1;
	}
	if (ob->query("eff_qi") >= ob->query("max_qi"))
	{
		command("? "+ob->query("id"));     
		command("say ��Ƥ���������������ң�\n");
		command("smile "+ob->query("id"));
		return 1;
	}
	else 
	{
		message_vision("$n����$N�µ������ϰ����壬�������ˣ���ʹ��......��\n", this_object(),ob);
		command("poor "+ob->query("id"));
		command("pat "+ob->query("id"));
		command("say �ðɣ�����һ��С���ӳ�������������Ҳ�����Ľ���");
                message_vision("$N�ó�һ��������������$n���˲�λ������Ѩ����$n�о�������ˡ�\n", this_object(),ob);
		ob->start_busy(3);
		call_out("recover", 5, ob);
		return 1;
	}
}
void recover(object ob)
{
	if (!ob || !present(ob)) return;
	if (environment(ob) != environment(this_object())) return;
	ob->set("eff_qi", (int)ob->query("max_qi"));
	//ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("һ����Ĺ����ȥ�ˣ�$N���������Ѿ�����Ȭ���ˡ�\n",ob);
	command("say �����ն�,��С�ĵĻ����´����û��ô�����ˡ�\n");
	command("pat "+ob->query("id"));
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
}
/*
int prevent_learn(object me, string skill)
{
	if ( skill=="liandan" && me->query_skill("liandan",1)<=50 )
		return 0;
	else
		return 1;
}
*/
int is_apprentice_of(object ob)
{
	return 1;
}
/*
int recognize_apprentice(object ob)
{
	int money = 150, level = ob->query_skill("liandan", 1);

	if (level > 9) money = 300;
	if (level > 19) money = 600;
	if (level > 29) money = 1200;
	if (level > 39) money = 2400;

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"�����ڵ�ѧ����ÿ��"+MONEY_D->money_str(money)+"�����Ǯ������\n" ); return 0;
	}
	return 1;
}
*/

////////////////////////////////////////////////////////////////////
int query_goods_value(int value , int number , string sid)
{
	object me = this_player();
	int trade_level;
	int cur;

	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (115 - trade_level) / 100;

	cur = query_temp("vendor_goods/"+sid);
	if( cur != number )
		value += value/6 * cur/number;

	return value;
}

string is_vendor_good(string arg)
{
	mapping *goods;
	int i;

	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			if( goods[i]["id"]==arg && goods[i]["number"]!=query_temp("vendor_goods/"+goods[i]["id"]) )
				return goods[i]["name"];
	return "";
}

void reset()
{
	this_object()->delete_temp("vendor_goods");
}

int do_list(string arg)
{
	mapping *goods;
	int i;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");
	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (arrayp(goods = query("vendor_goods")))
	{
		write(query("name") + "Ŀǰ�������»��\n");
                write("��������������������������������������������������������������������������������\n");
		write("��  ��  ��                          ��  ��                          ���/���� ��\n");
		write("�ǩ�����������������������������������������������������������������������������\n");
		for (i = 0; i < sizeof(goods); i++)
			write(sprintf("��%-30s%-36s%4d/%4d ��\n", goods[i]["short"],
				MONEY_D->price_str(query_goods_value(goods[i]["value"],goods[i]["number"],goods[i]["id"])),
				goods[i]["number"]-query_temp("vendor_goods/"+goods[i]["id"]),
				goods[i]["number"])
			);
		write("��������������������������������������������������������������������������������\n");
		return 1;
	}
}

int do_buy(string arg)
{
	int i,j,improve;
	string ob_file;
	object ob;
	object me = this_player();
	mapping goods;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");
	if (!arg) return notify_fail("������ʲô��\n");
	if ((ob_file = is_vendor_good(arg)) == "")
		return notify_fail("������Ķ���������û�С�\n");

	goods = query("vendor_goods");
	for(i=0;i<sizeof(goods);i++)
		if(goods[i]["id"]==arg) break;

	ob = new(ob_file);
	ob->set_type(goods[i]["id"],this_object()->query_skill("liandan",1),goods[i]["value"],sprintf("zhanggui%dd",time()),this_object(),0);

	switch(MONEY_D->player_pay(me,j = query_goods_value(goods[i]["value"],goods[i]["number"],goods[i]["id"]))) {
	case 0:
		destruct(ob);
		return notify_fail("��⵰��һ�ߴ���ȥ��\n");
	case 2:
		destruct(ob);
		return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
	default:
		if (!ob->move(me)) {
			destruct(ob);
			return 0;
		}
		message_vision("$N��"+MONEY_D->price_str(j)+"�ļ۸��$n����������һ" + ob->query("unit") + ob->name() + "��\n", me, this_object());
		improve = 40 - me->query("pur");
		me->improve_skill("trade", improve + random(improve));
		add_temp("vendor_goods/"+goods[i]["id"],1);
	}
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}


int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (80 + trade_level) / 100;

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
		return notify_fail("ҩ���ƹ�˵��������æ���ء�\n");
	if (!arg || !(ob = present(arg, me)))
		return notify_fail("ҩ���ƹ�˵������Ҫ��ʲô��\n");
	if (query_temp("busy"))
		return notify_fail("ҩ���ƹ�˵����Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	if ( !(int)ob->query("imbued") || !(int)ob->query("yao") || !(int)ob->query("user_make") )
		return notify_fail("ҩ���ƹ�˵������ֻ�չ�������Ƶĵ�ҩ��\n");

	value = query_goods_value2(ob);
	message_vision("$N��"+MONEY_D->price_str(value)+"�ļ۸�������һ"+ob->query("unit")+ob->name() + "��$n��\n", me, this_object());
	ob->delete_drug(me);
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
	object me = this_player() ,room ,oroom ,lastroom ,target, *living , obj;
	int lv1,lv2,i,j,k,a,b;
	string * exits;

	lv1 = (int)me->query_skill("tilian",1);
	lv2 = (int)me->query_skill("liandan",1);

	if ( environment(me)->query("no_zhiye"))
		return "������ûʲô����Ҫ����";
	if( lv1<10 || lv2 <10 )
		return "��ļ���̫���ˣ��ҿɲ���������ȥ���¡�";
	if( lv1>=395 || lv2>=395 )
		return "����ˮƽ��ô���ˣ��ҿɲ����ٲ�ǲ���ˡ�";
	if( !wizardp(me) && me->query("worker/djob") && time()<(int)me->query("worker/djob_time") )
		return "�Ҳ��ǽ���ѵ�ҩ�͸�"+me->query("worker/djob_oroom")+"������"+me->query("worker/djob")+"����";
	if( !wizardp(me) && time()<(int)me->query("worker/djob_time") )
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
				if ( random(10)<3 && target->query("race")=="����" ) {
					j = 0;
					break;
				}

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

	if(j>0) {
		target = new(__DIR__"customer3");
		target->set("player",me->query("id"));
		target->move(room);
	}

	obj = new("/d/zhiye/obj/danyao");
	obj->move(me);

	me->set("worker/djob",1);
	me->set("worker/djob_oroom",get_place(base_name(oroom))+oroom->query("short"));
	me->set("worker/djob_far",j);
	me->set("worker/djob_finish",0);
	me->set("worker/djob_target",target->query("name"));
	me->set("worker/djob_room",base_name(room));
	me->set("worker/djob_time",time()+20*60);
	if(wizardp(me) && me->query("env/test"))
		tell_object(me,base_name(oroom)+" -> "+base_name(room)+"\n");

	command("pat "+me->query("id"));
	if (j)
		command("whisper "+me->query("id")+" ����Ұѵ�ҩ�͸�"+me->query("worker/djob_target")+"������"
			+me->query("worker/djob_oroom")+"��Χ��Բ"+CHINESE_D->chinese_number(me->query("worker/djob_far"))+"��֮�ڡ�" );
	else
		command("whisper "+me->query("id")+" ����Ұѵ�ҩ�͸�"+me->query("worker/djob_oroom")+"��"
			+me->query("worker/djob_target")+"��");
	message_vision(CYN"ҩ���ƹ��$Nһ�Ÿո����ƺõĵ�ҩ��\n"NOR, me);
	return "�úøɻ�Ҳ��������ġ�";
}

string ask_fail()
{
	object me = this_player() , obj;

	if( !me->query("worker/djob") 
	|| time()>=(int)me->query("worker/djob_time")
	|| environment(me)->query("no_zhiye"))
		return "��Ҫ����ʲô��";

	me->delete("worker/djob");
	me->delete("worker/djob_oroom");
	me->delete("worker/djob_far");
	me->delete("worker/djob_target");
	me->delete("worker/djob_room");
	me->delete("worker/djob_finish");

	if ( objectp(obj = present("dan yao", me)) ) {
		message_vision(CYN"$N�ѵ�ҩ��������ʦ��\n"NOR, me);
		destruct(obj);
		me->set("worker/djob_time",time()+(2+random(3))*60);
		command("disapp " + me->query("id"));
		return "û�뵽��ô�򵥵������㶼�����ˣ�";
	}
	else {
		command("slash " + me->query("id"));
		me->set("worker/djob_time",time()+(10+random(10))*60);
		return "���Ͳ���Ҳ�����ˣ�����ô�ѻ���Ū���ˣ�";
	}
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

string ask_reward()
{
	object me = this_player();
	int improve1,improve2,lv1,lv2,exp;

	if( !me->query("worker/djob")
	|| environment(me)->query("no_zhiye"))
		return "����û���ҸɻҪʲô���꣡";

	if( !me->query("worker/djob_finish") )
		return "�㻹û����������أ�Ҫʲô���꣡";

	me->delete("worker/djob");
	me->delete("worker/djob_oroom");
	me->delete("worker/djob_target");
	me->delete("worker/djob_far");
	me->delete("worker/djob_room");
	me->delete("worker/djob_finish");
	me->set("worker/djob_time",time()+ 20 + random(30));

	lv1 = (int)me->query_skill("tilian",1) / 2;
	improve1 = (300 + lv1) * 15/10 /2;
	improve1 = improve1*2/3 + random(improve1*2/3);

	lv2 = (int)me->query_skill("liandan",1) / 2;
	improve2 = (300 + lv2) * 13/10 /2;
	improve2 = improve2*2/3 + random(improve2*2/3);

	exp = (improve1+improve2) / 30;
	me->improve_skill("tilian", improve1);
	me->improve_skill("liandan", improve2);
	me->add("combat_exp", exp);

	command("applaud " + me->query("id"));
	tell_object(me, HIC"ҩ���ƹ���ϸ���㽲�������������ľ��ϣ������������������"+CHINESE_D->chinese_number(improve1)
			+"�㣬�����������������"+CHINESE_D->chinese_number(improve2)+"�㣬������"+CHINESE_D->chinese_number(exp)+"�㾭�飡\n"NOR);
	log_file("job/drugjob",sprintf("%s(%s)��������%d��������%d�����飺%d����exp��%d\n", me->name(), me->query("id"),improve1,improve2,exp,me->query("combat_exp")),me);

	return "�����ģ��ɻ����������Ժ��пջ���������ɻ��";
}

/////////////////////////////////////////////////////////////////////

string ask_limit()
{
	int delay;
	object me = this_player();

	if( WORKER_D->update_UniqueValues("querydrug","","") > 1 ) {
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

void tell_limit(object me)
{
	int v1,v2,v3,v4;

	if (!objectp(me) || !userp(me)) return;

	v1 = WORKER_D->query_UniqueValues("drug","");
	v3 = WORKER_D->query_UniqueValues("drug2","");
	if(v1<0) {
		tell_object(me,CYN"ҩ���ƹ�˵������Ҳ��������ѽ�����ܵ�ԭ���ǣ���������޷�����ͬ����������\n"NOR);
	}
	else {
		v2 = v1 / 0x10000;
		v1 = v1 % 0x10000;
		v4 = v3 / 0x10000;
		v3 = v3 % 0x10000;
		tell_object(me,CYN"ҩ���ƹ�˵������˵���ʱ���ڣ������������Ѿ����Ƴ�"+CHINESE_D->chinese_number(v2)+"��ͷ�ȵ�ҩ��"+CHINESE_D->chinese_number(v4)+"�Ŷ��ȵ�ҩ��\n"NOR);
		tell_object(me,CYN"ҩ���ƹ�˵������˵���ʱ���ڣ�������������������"+CHINESE_D->chinese_number(v1)+"��ͷ�ȵ�ҩ��"+CHINESE_D->chinese_number(v3)+"�Ŷ��ȵ�ҩ��\n"NOR);
	}
}
