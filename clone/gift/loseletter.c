// loseletter.c
//
// Created by mxzhao 2004/03/22

#include <ansi.h>
#include <job_mul.h>

inherit ITEM;

#define BASE_EXP   300
#define BASE_POT	400
#define BASE_MONEY	100

#define RAND_EXP   200
#define RAND_POT	600
#define RAND_MONEY	200

#define GET_EXP(exp)		(exp = (BASE_EXP + random(RAND_EXP)) * LOSELETTER_JOB_MUL/100)
#define GET_POT(pot)		(pot = (BASE_POT + random(RAND_POT)) * LOSELETTER_JOB_MUL/100)
#define GET_MONEY(money)	(money = BASE_MONEY + random(RAND_MONEY))
#define GET_ITEM(obj)		(obj = new(bonus_items[random(sizeof(bonus_items))]))

string do_look();
private int set_addressee();
private int do_send(string arg);

string *bonus_items = ({
	"/clone/medicine/renshen-guo", 
});


void create()
{
	set_name(YEL"ʧ����ż�"NOR, ({ "letter", "xin", "lose letter" }));

	set_weight(10);

	if(clonep())
	{
		set_default_object(__FILE__);
	}
	else
	{
		set("unit", "��");
		set("value", 0);
		set("material", "paper");
		set("no_drop",1);
	}

	set("long", (: do_look :));

	set_addressee();

	setup();
}

void init()
{
	object me = this_player();

	if (!query("bearer"))
	{
		message_vision("$N�õ���һ��" + name() + "��\n", me);
		set("bearer", me->query("id"));
	}

	if (me->query("id") == query("bearer"))
	{
		if (me->query("id") == query("addressee"))
		{
			set_addressee();
		}
		
		if (query("addressee"))
		{
			add_action("do_send", "songxin");
		}
	}

	if (!query("calldest"))
	{
		set("calldest", 1);
		call_out("dest", random(300) + 300);
	}
}

string do_look()
{
	object ob;

	string str = "����һ���������������ͳ������š�\n"
		"�ŷ�ֽɫ���ƣ������û�����š�\n";

	string target = query("addressee");

	if (target && objectp(ob = find_player(target)))
	{
		str += "�ŷ���д�ţ�" + ob->short(1) 
			+ "\n�����Ǻ���Ҫ���ż㣬Ҫץ��ʱ�������ȥ��\n";
	}
	else
	{
		str += "�ŷ��ϵ��ּ�ģ�����壬��֪�������䵽�˴���\n";
	}

	return str;
}

private int set_addressee()
{
	object *list = filter_array(users(), 
		(: $1->query("combat_exp") > 100000
		&& !wizardp($1)
		&& environment($1)
		:));

	list -= ({ this_player() });

	if(sizeof(list) == 0)
	{
		delete("addressee");
		return 0;
	}

	set("addressee", list[random(sizeof(list))]->query("id"));

	return 1;
}

private int do_send(string arg)
{
	int exp, pot, money;
	int obexp, obpot, obmoney;

	object ob, obj, obobj;
	object me = this_player();

	if ( !arg || !objectp(ob = present(arg, environment(me))))
	{
		return notify_fail("��Ҫ�͸�˭��\n");
	}

	if ( query("addressee") != arg )
	{
		return notify_fail("����Ų����͸�����˵ġ�\n");
	}

	if ( me->is_busy() || me->is_fighting() )
	{
		return notify_fail("����æ���ء�\n");
	}


	if ( !living(ob) )
	{
		return notify_fail("������㣬���ǻ����𣿣�\n");
	}

	if ( !userp(ob) )
	{
		return notify_fail("�ٺ٣������ף���\n");
	}

	me->add_busy(random(2));

	message_vision("$n��" + name() + "������$N��\n", ob, me);

	if (random(10)==0)
	{
		message_vision("$N���ɵؿ���$n����������ô�䵽������ϣ���\n"
			"$N���´�����$n���ۣ����㵱��û��͵����������" 
			+ RANK_D->query_self(ob) + "��������˽Ȩ�ġ���\n", ob, me);
		
		EMOTE_D->do_emote(ob, "liar");

		message_vision("$NԽ��Խ������������$nһ�٣����$n�������ˡ�\n", ob, me);

		GET_EXP(exp);

		exp = random(exp/2);

		tell_object(me, "�㱻" + ob->name() + "������ˣ������½���" 
			+ chinese_number(exp) + "�㡣\n");

		exp = -exp;

		//me->add("combat_exp", exp);
		me->add_exp_combat(exp, ob, "��ʧ����", 1);

		EMOTE_D->do_emote(me, "wuwu", me->query("id"));
	}
	else
	{
		int itemp;

		EMOTE_D->do_emote(ob, "touch", me->query("id"));

		message_vision("����һ�����$N��˵�������ҵȺ����ү����Ϣ��ʱ��"
			"���ڳ��Ϊ����Ѷȫ�ޣ����Ƕ�л��λ" 
			+ RANK_D->query_respect(me) + "����\n", ob, me);
		
		switch (random(100)%5)
		{
		case 0:
			itemp = random(10) + 1;
			message_vision("$N���ż㿴�˿���ϲ���������ڴ��������ĸ�����Ʊ����" 
				+ chinese_number(itemp) + "�Ƚ�����������\n", ob, me);
			EMOTE_D->do_emote(ob, "yeah");

			GET_MONEY(money);
			money /= itemp;
			money *= 10000;
			me->add("balance", money);

			GET_MONEY(obmoney);
			obmoney /= itemp;
			obmoney *= 10000;
			ob->add("balance", obmoney);

			tell_object(ob, "�����˴����������Ʊ��������" 
				+ MONEY_D->money_str(obmoney) + "�������ѻ�������˻���\n");

			tell_object(me, "Ϊ�˸�л���ʰ���š�������" + ob->name() 
				+ "������˻�������" + MONEY_D->money_str(money) + "��\n");
			break;
		case 1:
			itemp = random(100) + 1;
			message_vision("$N���ż㣬����д�ţ�����������Ĵ���������ɷ�����µ���" 
				+ chinese_number(itemp) + "���ٷֵ㣡������\n", ob);
			EMOTE_D->do_emote(ob, "xbc");
			message_vision("$N˵��������л��λ" + RANK_D->query_respect(me) 
				+ "���Ÿ��ң���Ҫ�Ͻ�ȥ�����ˡ���\n", ob);

			GET_POT(pot);
			pot = pot*itemp/100;
			if (pot < 0)
			{
				pot = 0;
			}
			me->add("potential", pot);

			tell_object(me, "����˲���ͷ�ϵĺ������룺���ҿ���û�����ƹ�Ʊ��"
				"����С����ñ�����û�ˣ������Ƕ���װ����\n"
				"������Լ���Ӣ�����䣬��ʱ�����泩��������" 
				+ chinese_number(pot) + "��Ǳ�ܡ�\n");
			break;
		case 2:
			message_vision("$N���ż㿴�˿�����ϲ����������Ϊ�����ڿң�"
				"�Ѿ�����ѡΪ��������Ͷ�ģ���ˣ���\n", ob);

			EMOTE_D->do_emote(ob, "touch");

			message_vision("$N˵��������л��λ" + RANK_D->query_respect(me) 
				+ "���Ÿ��ҡ���\n", ob);

			GET_EXP(exp);
			GET_POT(pot);
				
			//me->add("combat_exp", exp);
			exp = me->add_exp_combat(exp, ob, "��ʧ����", 1);
			
			me->add("potential", pot);

			GET_EXP(obexp);
			GET_POT(obpot);
			//ob->add("combat_exp", obexp);
			obexp = ob->add_exp_combat(obexp, me, "��ʧ����", 1);
			ob->add("potential", obpot);

			tell_object(ob, "�㱻��ѡΪ��������Ͷ�ģ���������" 
				+ chinese_number(obexp) + "�㾭�飬" + chinese_number(obpot) + "��Ǳ�ܡ�\n");
			
			tell_object(me, "�������Լ�ʰ���š��������ڴ˻������ټӰѾ���"
				"��������Ҳ����Ϊ���ٵ��Ͷ�ģ�������ɾ����Ϊ��ܡ�\n"
				"������" + chinese_number(exp) + "�㾭�飬" 
				+ chinese_number(pot) + "��Ǳ�ܡ�\n");
			break;
		case 3:
			message_vision("$N���ż㣬��ü�������������������Ͷ������"
				"�Ѿ��Ҵ������¾ֵ�һ��ɸѡ���ܾ���\n"
				"����ͼ�лߴ��������쵼����Ϊ�ѱ����飬�����ͻأ�"
				"�ҹ�����׷����������Ȩ��������\n", ob);
			
			EMOTE_D->do_emote(ob, "wait");

			GET_ITEM(obj);

			message_vision("$N��ݺݵõ���$nһ�ۣ����Ĺĵİ��ż��ڷ�Ļ�¸��Ʒ��" 
				+ obj->name() + "�����ڵ��ϡ�\n", ob, me);

			GET_EXP(obexp);
			GET_POT(obpot);
			//ob->add("combat_exp", obexp);
			obexp = ob->add_exp_combat(obexp, me, "��ʧ����", 1);
			ob->add("potential", obpot);

			tell_object(ob, "���л���ְʧ�ܣ���н������������ѧ�������" 
				+ chinese_number(obexp) + "�㾭�飬" + chinese_number(obpot) + "��Ǳ�ܡ�\n");

			tell_object(me, "�����" + ob->name() + "�ӵ��ġ�" + obj->name() + "����\n");

			obj->move(me);
			break;
		case 4:
			message_vision("$N���ż㣬ȴ���ȵķ��֣����滹��һ���ż㡣\n"
				"$N����һЦ����һ�����ĸ���ͷϺ�Ѹ����˵��ż��װ�����ҵ��ŷ����ˡ���\n", ob, me);

			new(__FILE__)->move(ob);

			EMOTE_D->do_emote(ob, "thank ", me->query("id"));

			GET_EXP(exp);
			GET_POT(pot);
			
			//me->add("combat_exp", exp);
			exp = me->add_exp_combat(exp, ob, "��ʧ����", 1);
			me->add("potential", pot);
			
			tell_object(me, "����Ϊ�Լ�ʰ���š������������" 
				+ chinese_number(exp) + "�㾭�飬" + chinese_number(pot) + "��Ǳ�ܡ�\n");
		default:
			break;
		}
	}

	log_file("job/loseletter",
		strip(sprintf("%s(%s)��" + name() + "��%s(%s)��"
		"����%s�㾭��%s��Ǳ��%s����Ʒ��%s��\n",
		me->query("name"),
		me->query("id"),
		ob->query("name"),
		ob->query("id"),
		chinese_number(exp),
		chinese_number(pot), 
		MONEY_D->money_str(money), 
		objectp(obj)?obj->name():"��"
		)), 
		me );
	
	if (obexp>0 || obpot>0 || obmoney>0 || objectp(obobj))
	{
		log_file("job/loseletter",
			strip(sprintf("%s(%s)��%s(%s)���յ�" + name() + "��"
			"����%s�㾭��%s��Ǳ��%s����Ʒ��%s��\n",
			ob->query("name"),
			ob->query("id"),
			me->query("name"),
			me->query("id"),
			chinese_number(obexp),
			chinese_number(obpot), 
			MONEY_D->money_str(obmoney), 
			objectp(obobj)?obobj->name():"��"
			)), 
			me );
	}

	destruct(this_object());
	return 1;
}

void dest()
{
	object ob = environment(this_object());
	if (userp(ob))
	{
		tell_object(ob, "��������ȥ���²��ؼ����߸߹��𣬺α�Ϊ���˿�౼����\n"
			"����˲�ע�⣬͵͵��" + this_object()->name() + "�ӽ���·�ߵĲݴԡ�\n");
	}

	destruct(this_object());
}

