//banker.c
// Each banker should support do_ + check, convert, deposit, withdraw 4 commands

#include <dbase.h>

int query_balance_limit(object me)
{
	int i, exp = me->query("combat_exp");
        if(exp>35000000) exp =35000000;
          i = exp* 30;
           
        if( me->query("registered") == 3 ) i = i * 2;    
       if( me->query("buyvip")) i = i * 2 ;
	
         if(i>200000000 || i<0 )  i = 2000000000; 
	
		return i;
}

string withdraw_cost_str = "";

int query_withdraw_cost(object me, int v)
{
	int b = me->query("balance"), i;

	if (!stringp(me->query_temp("user_type")))
		me->query_user_type();
	if (me->query_temp("user_type")=="worker") {
		if (b<500000)
			i = 10;		//   50 Golds
		else if (b<10000000)
			i = 15;		// 1000 Golds
		else if (b<20000000)
			i = 20;		// 2000 Golds
		else if (b<35000000)
			i = 25;		// 3000 Golds
		else if (b<50000000)
			i = 30;		// 5000 Golds
		else if (b<75000000)
			i = 35;		// 7500 Golds			
		else i = 40;
	} else {
		if (b<2000000)
			i = 3;		// 300 Golds
		else if(b<10000000)
			i = 5;		// 1000 Golds
		else if(b<20000000)
			i = 10;		// 2000 GOlds
		else if(b<40000000)
			i = 15;		// 4000 Golds
		else i = 20;
	}
	if (i<10)
		withdraw_cost_str = CHINESE_D->chinese_number(i) + "��";
	else {
		withdraw_cost_str = CHINESE_D->chinese_number(i/10) + "��";
		if (i%10)
			withdraw_cost_str += "��";
	}
	v = v / 10 * i / 10;
	if (v < 1)
		v = 1;
	return v;
}

int do_check()
{
	object me = this_player();
	int total = me->query("balance");

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (query_temp("busy") || this_object()->is_busy())
		return notify_fail(this_object()->name()+"˵������Ӵ����Ǹ�����������æ���ء��������Ժ򡣡�\n");

	if (total <= 0) {
		me->set("balance", 0);
                tell_object(me, "�ϰ������۾��ֹ��˰��죬��о������񲻴�Ծ�����\n");
		write("���ڱ��̺�û�д�Ǯ��\n");
	} else
		write(this_object()->name()+"���˷��ʲ��������㣺�����ڱ��̺Ź�����"+MONEY_D->money_str(total)+"��\n");
	if( me->query("registered") == 3 && !me->query("buyvip") )
		write("���ǹ����ң��������Ĵ������Ҫ����ͨ��Ҷ�һ����\n��Ŀǰ�Ĵ�������ǣ�"+MONEY_D->money_str(query_balance_limit(me))+"��\n");
	if( me->query("buyvip") )
		write("��������VIP����ң��������Ĵ������Ҫ�ȹ����һ����\n��Ŀǰ�Ĵ�������ǣ�"+MONEY_D->money_str(query_balance_limit(me))+"��\n");

	else
		write("��Ŀǰ�Ĵ�������ǣ�"+MONEY_D->money_str(query_balance_limit(me))+"��\n");
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2, exp;
	object from_ob, to_ob;
	object me;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (query_temp("busy") || this_object()->is_busy())
		return notify_fail(this_object()->name()+"˵������Ӵ����Ǹ�����������æ���ء��������Ժ򡣡�\n");

	me = this_player();
	exp = me->query("combat_exp");
	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");

	if (from == "cash")
		from = "thousand-cash";

	from_ob = present(from + "_money", me);
	if (!from_ob)
		return notify_fail("������û�д�����Ǯ��\n");

	if (exp < 15000 && from_ob->query("id") == "thousand-cash")
		return notify_fail("�㹦��δ����������������ô��Ǯ��\n");

	if (to == "cash")
		to = "thousand-cash";

	to_ob = present(to + "_money", me);
	if (file_size("/clone/money/" + to + ".c") < 0)
		return notify_fail("����һ���ʲô��\n");

	if (amount < 1)
		return notify_fail("�����׬����\n");

	if ((int)from_ob->query_amount() < amount)
		return notify_fail("�����" + from_ob->name() + "������\n");

	bv1 = from_ob->query("base_value");
	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );

	if (bv1 < bv2) amount -= amount % (bv2 / bv1);

	if (amount == 0)
		return notify_fail("��Щ" + from_ob->name() + "��������\n");

	exp = amount * bv1 / bv2;

	if (exp < 1) return notify_fail(this_object()->name()+"��ɫһ�䣬��������λ"
		+RANK_D->query_respect(me)+"��С��Ŀǰû����ô���ֽ��Ƿ��ٻ�һ�㣿��\n");

	// allowed to convert now
	to_ob = new("/clone/money/" + to);
	to_ob->set_amount(exp);
	if (!to_ob->move(me)) {
		destruct(to_ob);
		return notify_fail("���������ô��Ǯ��\n");
	}

	set_temp("busy", 1);

	from_ob = present(from + "_money", me);

	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->name(),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"),
		to_ob->name()), me);
	from_ob->add_amount(-amount);

	call_out("delete_temp", 1, "busy");

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount, limit;
	object what_ob, me;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (query_temp("busy") || this_object()->is_busy())
		return notify_fail(this_object()->name()+"˵������Ӵ����Ǹ�����������æ���ء��������Ժ򡣡�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��deposit|cun <����> <���ҵ�λ>\n");

	if (what == "cash")
		what = "thousand-cash";

	if (!what_ob = present(what + "_money", me))
		return notify_fail("������û�д�����Ǯ��\n");

	if (amount < 1)
		return notify_fail("��������" + what_ob->name() + "��\n");

	if ((int)what_ob->query_amount() < amount)
		return notify_fail("������" + what_ob->name() + "������\n");

	limit = query_balance_limit(me);

	limit -= me->query("balance");
	if (limit < what_ob->query("base_value") * amount)
		return notify_fail("��Ŀǰ���д��"+MONEY_D->money_str(me->query("balance"))+"���ٴ���ô���Ǯ��С�ſ��ѱ����ˡ�\n");

	set_temp("busy", 1);
	limit = amount;
	amount *= what_ob->query("base_value");
	if (amount < 1) return notify_fail(this_object()->name()+"�ѿ���ЦЦ��������λ"
		+RANK_D->query_respect(me)+"����ô���ֽ����㲻�����ˣ��Ƿ������������������\n");

	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", chinese_number(limit), what_ob->query("base_unit"), what_ob->name()), me);

	what_ob->add_amount(-limit);
	write(query("name")+"�����ʣ����˵�ͷ�������ڱ��̺�����"+MONEY_D->money_str(me->add("balance", amount))+"����\n");
	call_out("delete_temp", 1, "busy");
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me, money;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");

	if (query_temp("busy") || this_object()->is_busy())
		return notify_fail(this_object()->name()+"˵������Ӵ����Ǹ�����������æ���ء��������Ժ򡣡�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");

	if (what == "cash")
		what = "thousand-cash";

	if (file_size("/clone/money/" + what + ".c") < 0)
		return notify_fail("����ȡ��ʲôǮ��\n");

	if (amount < 1)
		return notify_fail(this_object()->name()+"һ����ãȻ���ʵ�������λ"
		+RANK_D->query_respect(me)+"������Ҫ��ȡ����Ǯ���\n");

	what = "/clone/money/" + what;
	if (me->query("balance") > query_balance_limit(me) ) {
		log_file("balance",
			sprintf("%-19s������ %10d ���ּ�Ϊ��%10d��\n",
				me->name(1)+"("+me->query("id")+")", me->query("balance"), query_balance_limit(me)
			), me
		);


 me->add("SJ_Credit",(me->query("balance")-query_balance_limit(me))/1000000  );
                me->set("balance", query_balance_limit(me));
                tell_object(me, "���Ĵ����Ŀ���󣬱����Ѿ���飬����Ĵ���Ѿ�����100�ƽ�:1ͨ��ת����Ϊͨ�������õ����ˡ�\n");

	}

	if ((v = amount * what->query("base_value")) > me->query("balance"))
		return notify_fail("��û�д���ô���Ǯ��\n");

	if ((v += query_withdraw_cost(me,v)) > me->query("balance"))
		return notify_fail("��Ĵ���֧�������ѣ���ȡ��ɡ�\n");

	if (v < 1)
		return notify_fail(this_object()->name()+"��ɫһ�䣬��������λ"
			+RANK_D->query_respect(me)+"���Ƿ������������������\n");

	message_vision(sprintf("$N��������ȡ��%s%s%s��\n", chinese_number(amount), what->query("base_unit"), what->name()), me);
	(money = new(what))->set_amount(amount);
	money->move(me);
	write(query("name")+"�����ʣ������㣺���۳�"+withdraw_cost_str+"�����ѣ����ڱ��̺��ֻ���"+MONEY_D->money_str(me->add("balance", -v))+"����\n");
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");
	return 1;
}
