// moneyd.c Ǯ�Ĺ���
// ���� ���ֱ�ӵ��� �йؽ�Ǯ�Ķ�������ȫд�������� xixi
#include <ansi.h>

string money_str(int amount)
{
	// returns a chinese string of `amount` of money
	string output;

	if (amount / 10000) {
		output = chinese_number(amount / 10000) + "��"HIY"�ƽ�"NOR;
		amount %= 10000;
	}
	else
		output = "";
	if (amount / 100) {
		output = output + chinese_number(amount / 100) + "��"HIW"����"NOR;
		amount %= 100;
	}
	if (amount)
		return output + chinese_number(amount) + "��"YEL"ͭǮ"NOR;
	return output;
}

string price_str(int amount)
{
	// returns a chinese string of `amount` of money
	string output;

	if (amount < 1)
		amount = 1;

	if (amount / 10000) {
		output = chinese_number(amount / 10000) + "��"HIY"�ƽ�"NOR;
		amount %= 10000;
	}
	else
		output = "";
	if (amount / 100) {
		if (output != "")
			output += "��" + chinese_number(amount / 100) + "��"HIW"����"NOR;
		else
			output = chinese_number(amount / 100) + "��"HIW"����"NOR;
		amount %= 100;
	}
	if (amount)
		if (output != "")
			return output + "��" + chinese_number(amount) + "��"YEL"ͭǮ"NOR;
		else
			return chinese_number(amount) + "��"YEL"ͭǮ"NOR;
	return output;
}

#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif

void pay_player(object who, int amount, int cash,int balance)
{
	object ob;

	seteuid(getuid());
	
	//��ҵ��Ӫ
	//if(environment(who)) ROOMLEASE_D->add_money(base_name(environment(who)),-amount );
	//�����Ǯ�ĵط�ע���ճ�����Ŷ
	
	if(balance)
	{
		who->add("balance",amount);
		return;
	}
	
	if (amount < 1)
		amount = 1;
	if (cash && amount / 100000) {
		ob = new("/clone/money/thousand-cash");
		ob->set_amount(amount / 100000);
		ob->move(who);
		amount %= 100000;
	}
	if (amount / 10000) {
		ob = new(GOLD_OB);
		ob->set_amount(amount / 10000);
		ob->move(who);
		amount %= 10000;
	}
	if (amount / 100) {
		ob = new(SILVER_OB);
		ob->set_amount(amount / 100);
		ob->move(who);
		amount %= 100;
	}
	if (amount) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

varargs int player_pay(object who, int amount, int mode,int balance)
{
	object g_ob, s_ob, c_ob, t_ob;
	int gc, sc, cc, tc, left;

	seteuid(getuid());

	if ( mode && (t_ob=present("thousand-cash_money", who)) )
		tc = t_ob->query_amount();
	else
		tc = 0;
	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;

	if (!balance && cc + sc*100 + gc*10000 + tc*100000 < amount) {
		if ( !mode && present("thousand-cash", who) )
			return 2;
		else
			return 0;
	}
	else {
		if(balance && who->query("balance") < amount)
			return 0;
		//��ҵ��Ӫ
		if(environment(who)) ROOMLEASE_D->add_money(base_name(environment(who)),amount );
		
		if(balance)
		{
			who->add("balance",-amount);
			return 1;
		}
		left = cc + sc*100 + gc*10000 + tc*100000 - amount;
		if(mode) {
			tc = left / 100000;
			left = left % 100000;
		}
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (mode && t_ob)
			t_ob->set_amount(tc);
		else gc += (tc * 10);
		if (g_ob)
			g_ob->set_amount(gc);
		else sc += (gc * 100);
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}
		return 1;
	}
}
