// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Modify by Yu Jue 98-8-5
// Modify by Yu Jue 2000-9-28
// Modify by Yuj@SJ 2001-04-28
// Modify by augx@sj 9/4/2001
// �ḻ 
#include <ansi.h>
#include <dbase.h>

nosave mapping armor = ([]);
nosave mapping book = ([]);
nosave mapping misc = ([]);
nosave mapping weapon = ([]);

int query_goods_value(object goods, string method)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 5;
	if (trade_level > 40) trade_level = 40;
	if (method == "buy")
		value = value * (140 - trade_level) / 100;
	else if (method == "sell" || method == "value")
		value = value * (50 + trade_level) / 100;
	return value;
}

string is_vendor_good(string arg)
{
	string *goods;
	int i;

	if (arrayp(goods = query("vendor_goods")))
		for (i = 0; i < sizeof(goods); i++)
			if (goods[i]->id(arg)) return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;
        mixed ns;
        
	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (base_name(environment()) != query("startroom"))
	{
                command("say �⡭��������ǳ����������ݵģ����´����ɡ�" );
                return 1;
        }

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ۣ�\n");

	message_vision("$N�������ó�һ"+ob->query("unit")+ob->name()+"��$n���ۡ�\n", this_player(), this_object());
	if (ob->query("money_id"))
        {
                command("say ��û�ù�Ǯ����" );
                return 1;
        }

        if (ob->is_character())
        {
                command("say ����Ҳ�������ۣ�" );
		command("admire");
                return 1;
        }

	value = query_goods_value(ob, "value");
	if (value < 30)
		command("say "+ob->name()+"һ�Ĳ�ֵ��" );
	else        
	if (ob->query("no_drop") || (ns = ob->query("no_sell")))
        {
                if (stringp(ns))
                {
                        command("say " + ns );
                        return 1;
                }
                command("say �ⶫ���е�Ź֣��ҿɲ��ù��ۡ�" );               
        }
        else
		command("say "+ob->name()+"ֵ"+ MONEY_D->price_str(value) + "��" );
	return 1;
}

int do_sell(string arg)
{
	object ob, tmp;
	object me = this_player();
	int value, value1, improve;
        mixed ns;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");

	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
	{
                command("say �⡭��������ǳ����������ݵģ����´����ɡ�" );
                return 1;
        }

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("��Ҫ��ʲô��\n");
	
	message_vision("$N�������ó�һ"+ob->query("unit")+ob->name()+"��Ҫ����$n��\n", this_player(), this_object());

	if (ob->query("money_id"))
	{
                command("say ������������������Ǯ����" );
                return 1;
        }
	
	if (ob->query("no_drop") ||
            (ns = ob->query("no_sell") || ob->query("no_get")))
        {
                if (stringp(ns))
                {
                        command("say " + ns);
                        return 1;
                }
                command("say ���ֶ����Ҳ�ʶ��������Ҫ��" );
                return 1;
        }

	if (ob->query("unique"))
	{
		command("say �����ı����ҿ�����");
		return 1;	
	}

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
		//command������flood

	if (is_vendor_good(arg) != "")
	{
		command("say �ٺ٣���������ò��ã�");
		return 1;	
	}	
	if (ob->query("food_supply"))
	{
		command("say ʣ��ʣ���������Լ��ðɡ�");
		return 1;	
	}
	
	if (ob->is_character())
        {
                command("say �ߣ����������������⣬��������Щ��");
                return 1;
        }
	
	if (ob->query("shaolin"))
	{
		command("say С��ֻ��һ���Դ����ɲ��������������");
		return 1;	
	}

	if (ob->query("tianlongsi"))
	{
		command("say ������Ц�ɣ������µ������Ҳ�е�������");
		return 1;	
	}

	if (ob->query("emei"))
	{
		command("say �����ɵĶ������ҿɲ�����");
		return 1;	
	}
   if (ob->query("sld"))
 {
          command("say �������Ķ�����������������");
         return 1;   
   } 
	if (ob->query("wudang"))
	{
		command("say �䵱ɽ���۵Ķ�����������������");
		return 1;	
	}

	value = ob->query("value");
	value1 = query_goods_value(ob, "sell");
	if (value < 30)
		command("say "+ ob->name() + "��ֵǮ����������Ҳû�á�\n");
	else if (value >= 500000)
		command("say " + ob->name() + "�ǳ��������ǿ�����");
	else {
		if (value < 200 || ob->query_amount()) {
			message_vision("$N��"+MONEY_D->price_str(value1)+"�ļ۸�������һ" + ob->query("unit") +
				ob->name() + "��$n��\n", me, this_object());
			message_vision("$N��$n����һ�ӣ�˵������ô����ֵǮ������Ҳ��������\n",
				this_object(), ob);
			destruct(ob);
		} else {
			if (sizeof(all_inventory()) > 50) {
				tmp = all_inventory()[25];
				if (!tmp->query("no_get")) ;
				else if (tmp->query("armor_type")) armor[base_name(tmp)]--;
				else if (tmp->query("skill")) book[base_name(tmp)]--;
				else if (tmp->query("weapon_prop")) weapon[base_name(tmp)]--;
				else misc[base_name(tmp)]--;
				this_object()->add_temp(base_name(tmp)+".c", -1);
				destruct(tmp);
			}
			if (ob->move(this_object())) {
				message_vision("$N��"+MONEY_D->price_str(value1)+"�ļ۸�������һ" + ob->query("unit") +
					ob->name() + "��$n��\n", me, this_object());
				ob->set("no_get", 1);
				this_object()->add_temp(base_name(ob)+".c", 1);
				if (ob->query("armor_type")) armor[base_name(ob)]++;
				else if (ob->query("skill")) book[base_name(ob)]++;
				else if (ob->query("weapon_prop")) weapon[base_name(ob)]++;
				else misc[base_name(ob)]++;
			}
			else return notify_fail("��������Ѿ�̫���ˣ���ʱֹͣ�չ���\n");
		}
		MONEY_D->pay_player(me, value1);
		improve = 40 - me->query("pur");
		me->improve_skill("trade", improve / 2 + random(improve));
	}
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}

int do_list(string arg)
{
	string *goods;
	mapping ptr;
	object *inv;
	int i, j, flag = 0;
	object me = this_player();

	if (!living(this_object()))
	{
		tell_object(me,"���ǵȶԷ�������˵�ɡ�\n");
		return 1;
	}

	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
	{
                command("say �⡭��������ǳ����������ݵģ����´����ɡ�" );
                return 1;
        }

	if (arrayp(goods = query("vendor_goods"))) {
		write(query("name") + "Ŀǰ�������»��\n");
		for (i = 0; i < sizeof(goods); i++)
			printf("%30-s��%s\n", goods[i]->short(),
				MONEY_D->price_str(query_goods_value((object)goods[i], "buy")));
		return 1;
	}

	switch (arg) {
		case "armor":	arg = "����";	ptr = armor;	break;
		case "book":	arg = "�鼮";	ptr = book;	break;
		case "misc":	arg = "����";	ptr = misc;	break;
		case "weapon":	arg = "����";	ptr = weapon;	break;
		default: tell_object(me,"���뿴��һ�ֻ���(armor, book, misc, weapon)��\n"); return 1;
	}

	i = sizeof(ptr);
	if (!i) 
	{
		command("say Ŀǰû�п�������"+arg+"��" );
		return 1;
	}

	goods = keys(ptr);
	inv = all_inventory();
	if (!flag) write(query("name") + "Ŀǰ��������"+arg+"��\n");
	write("������������������������������������������������������������������������������\n");
	write("��"+arg+"��                        ����                                ���    ��\n");
	write("�ǩ���������������������������������������������������������������������������\n");
	while (i--) {
		j = sizeof(inv);
		while (j--) {
			reset_eval_cost();
			if (inv[j]->query("no_get") && base_name(inv[j]) == goods[i]) {
				write(sprintf("��%-30s%-36s%-8s��\n", inv[j]->short(), 
					MONEY_D->price_str(query_goods_value(inv[j], "buy") * 6 / 5),
					chinese_number(query_temp(base_name(inv[j])+".c")) ));
				flag = 1;
				break;
			}
			if (j < 0 ) map_delete(ptr, goods[i]);
		}
	}
	write("������������������������������������������������������������������������������\n");
	if (!flag) command("say Ŀǰû�п�������"+arg+"��\n");
	return 1;
}

int do_buy(string arg)
{
	int value1, val_factor = 5, improve;
	string ob_file;
	object ob;
	object me = this_player();

	if (!living(this_object()))
	{
		tell_object(me,"���ǵȶԷ�������˵�ɡ�\n");
		return 1;
	}

	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
	{
                command("say �⡭��������ǳ����������ݵģ����´����ɡ�" );
                return 1;
        }

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (query_temp("busy"))
	{
		command("say Ӵ����Ǹ�����������æ���ء��������Ժ�");
		return 1;	
	}


	if (!arg) 
	{
		command("say ������ʲô��");
		return 1;	
	}

	if (ob = present(arg, this_object())) val_factor = 6;

	if (!ob || !ob->query("no_get")) {
		if ((ob_file = is_vendor_good(arg)) == "")
		{
			command("say "+arg+"�� ������Ķ���������û�С�");
			return 1;	
			}
		else ob = new(ob_file);
	}

	value1 = query_goods_value(ob, "buy") *  val_factor / 5;
	switch (MONEY_D->player_pay(me, value1)) {
		case 0:
			if (val_factor == 5) destruct(ob);
			{
			command("say ��⵰��һ�ߴ���ȥ��");
			return 1;	
			}
		case 2:
			if (val_factor == 5) destruct(ob);
			{
			command("say ������Ǯ�����ˣ���Ʊ��û���ҵÿ���");
			return 1;	
			}	
		default:
			if (!ob->move(me)) {
				if (val_factor == 5) destruct(ob);
				return 0;
			}
			if (val_factor == 6) {
				ob->delete("no_get");
				if (ob->query("armor_type")) armor[base_name(ob)]--;
				else if (ob->query("skill")) book[base_name(ob)]--;
				else if (ob->query("weapon_prop")) weapon[base_name(ob)]--;
				else misc[base_name(ob)]--;
			}
			this_object()->add_temp(base_name(ob)+".c", -1);
			message_vision("$N��"+MONEY_D->price_str(value1)+"�ļ۸��$n����������һ" + ob->query("unit") +
				ob->name() + "��\n", me, this_object());
			improve = 40 - me->query("pur");
                        improve = random(improve*2);
			me->improve_skill("trade", improve / 2 + random(improve));
	}
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}
