// huolang.c ����
// By River@SJ

inherit NPC;

inherit F_VENDOR;
#include <ansi.h>
string ask_he();

void create()
{
	set_name("����", ({ "huo lang", "lang", "huo" }) );
	set("gender", "����" );
	set("age", 50+random(15));
	set("long",  "һ���׷��ԲԵ����̣����Ż����ִ߽��ר����Щ�����˵���ʲ��\n"+
		"����һ������һ���͸е��׽��ĺ��Ƶ�Ц�ݡ�\n");
	set("combat_exp", 30000);
	set("no_quest", 1);
	set("per", 20);
	set("unique", 1);
	set("attitude", "friendly");
	set("move_seller", 1);
	set("location", 1);

	set("inquiry", ([
		"ֽ��" : (: ask_he :),
	]));

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}));

	set("vendor_goods", ({
		(["name": MISC_D("fengling"), "number": 5]),
		(["name": MISC_D("fengche"),"number" : 5]),
		(["name": MISC_D("paper"), "number" : 50]),
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

string ask_he()
{
	object me = this_player();
	if (objectp(present("jin zhihe", me))) {
		command("pat "+ me->query("id"));
		return "��ϸ�࿴����ֽ�׵��۵������ɡ�";
	}
	if ( me->query_temp("make_zhihe/done")) {
		command("congra "+ me->query("id"));
		return "��λ"+RANK_D->query_respect(me)+"���������������Ѿ���һǧֻֽ���ˡ�";
	}
	message_vision(CYN"�������ص�Ц��������λ"+RANK_D->query_respect(me)+"����Ҫ���Լ����˶�����ô����\n"NOR,me);
	me->set_temp("make_zhihe/ask", 1);
	return "������������.....";
}

int accept_object(object me, object obj)
{            
	object he;
	if(obj->query("money_id")){
		if( me->query_temp("make_zhihe/ask")){
			if( obj->value() >= 10000 ) {
				command("haha " + me->query("id"));
				command("say ��λ"+RANK_D->query_respect(me)+"������������,�������,����׵ķ����Ҿʹ�����ɡ�");
				he=new(MISC_D("jinhe"));
				he->set("owner", me->query("id"));
				he->move(me);
				message_vision("���ɸ���$Nһֻ"HIY"��ֽ��"NOR"��\n", me);
				me->delete_temp("make_zhihe/ask");
				return 1;
			}
			else {
				command("say ����ô��Ǯ�ܸ�ʲô��");
				return 1;
			}
		}
		else {
			command("wah");
			command("say �ǾͶ�л�ˣ�");
			return 1;
		}
	}
	command("? " + me->query("id"));
	command("say �Ҷ�"+obj->name()+"��ϡ����");
	return 0;
}

void unconcious()
{
	say("\n���������ڻ�������һ��ҩ�����������Ƭ��֮����ָֻ��˾���\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

void kill_ob(object ob)
{
	object me = this_object();

	command("!!!");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

void accept_fight(object ob)
{
	command("peace "+ ob->query("id"));
	return;
}
