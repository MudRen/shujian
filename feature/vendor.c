// vendor.c ����

// Modify by tiantian@sj

// Modify by augx@sj  9/4/2001

// Modify by LinuX@SJ 3/2/2004

#include <dbase.h>



int query_goods_value(string goods, int number)

{

	object me = this_player();

	int value, trade_level;

	int cur;



	value = ((object)goods)->query("value");

	trade_level = me->query_skill("trade", 1) / 5;

	if (trade_level > 40) trade_level = 40;

	value = value * (140 - trade_level) / 100;



	cur=query_temp("vendor_goods/"+goods);

	if( cur!=number )

		value += value*cur/number;

	

	if(me->query("quest/wxbjiebai") && query("name")=="ΤС��" )

		value = value * 9 /10;//����ֵܴ����		

	if(value<0) value = 1;

	return value;

}



string is_vendor_good(string arg)

{

	mapping *goods;

	int i;



	if (arrayp(goods = query("vendor_goods")))

		for (i = 0; i < sizeof(goods); i++)

			if (goods[i]["name"]->id(arg) &&

				goods[i]["number"] != query_temp("vendor_goods/"+goods[i]["name"]))

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

	object me = this_player();



	if (!living(this_object()))

	{

		tell_object(me,"���ǵȶԷ�������˵�ɡ�\n");

		return 1;

	}



	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))

	{	

		command("say �⡭��������ǳ�������ģ����´����ɡ�");

		return 1;

	}

	



	if (arrayp(goods = query("vendor_goods")))

	{

		write(query("name") + "Ŀǰ�������»��\n");

                write("������������������������������������������������������������������������������\n");

		write("��  ��  ��                          ��  ��                        ���/���� ��\n");

		write("�ǩ���������������������������������������������������������������������������\n");

		for (i = 0; i < sizeof(goods); i++)

                   write(sprintf("��%-30s%-34s%4d/%4d ��\n", goods[i]["name"]->short(),
				MONEY_D->price_str(query_goods_value(goods[i]["name"], goods[i]["number"])),

				goods[i]["number"]-query_temp("vendor_goods/"+goods[i]["name"]),

				goods[i]["number"])

			);

		write("������������������������������������������������������������������������������\n");

		return 1;

	}

}



int do_buy(string arg)

{

	int i, improve;

	string ob_file;

	object ob;

	object me = this_player();

	mapping goods;



	if (!living(this_object()))

	{

		tell_object(me,"���ǵȶԷ�������˵�ɡ�\n");

		return 1;

	}



	if (me->is_busy() || me->is_fighting()){

		tell_object(me,"����æ���ء�\n");

		return 1;

	}



	if (query_temp("busy")){

		tell_object(me,"Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

		return 1;

	}



	if (!(int)query("move_seller") && base_name(environment()) != query("startroom")){	

		command("say �⡭��������ǳ�������ģ����´����ɡ�");

		return 1;

	}

	

	if (!arg) {	

		command("say "+me->name(1)+",������ʲô��");

		return 1;

	}



	if ((ob_file = is_vendor_good(arg)) == "")

	{	

		command("say ������Ķ���������û�С�");

		return 1;

	}



	goods=query("vendor_goods");

	for(i=0;i<sizeof(goods);i++)

		if(goods[i]["name"]==ob_file)

			break;



	ob = new(ob_file);

	if (query("name") == "ΤС��"){

		if (query_goods_value(ob_file,goods[i]["number"]) > me->query("balance"))	

		{

		tell_object(me,"��û����ô���\n");

		return 1;

		}



		if (!ob->move(me)) {

			destruct(ob);

			return 0;

		}

		if(me->query("quest/wxbjiebai") && query("name")=="ΤС��" )

		message_vision("$N������Ц���Լ��ֵܱ��˵����ˡ�\n",this_object());

		message_vision("$N��"+MONEY_D->price_str(query_goods_value(ob_file,goods[i]["number"]))+"�ļ۸��$n����������һ" + ob->query("unit") +

			ob->name() + "����Ǯֱ�Ӵ����д��۳���\n", me, this_object());

			CHANNEL_D->do_channel( this_object(), "rumor",

		sprintf("��˵���˴�ΤС����������һ%s��", ob->query("unit")+ob->name()));

		me->add("balance",-query_goods_value(ob_file,goods[i]["number"]));

		improve = 40 - me->query("pur");

		me->improve_skill("trade", improve + random(improve));

		add_temp("vendor_goods/"+ob_file,1);

		

		

	}

	else{



	switch(MONEY_D->player_pay(me, i = query_goods_value(ob_file,goods[i]["number"]))) {

	case 0:

		destruct(ob);

		command("say ��⵰��һ�ߴ���ȥ��");

		return 1;

	case 2:

		destruct(ob);

		command("say ������Ǯ�����ˣ���Ʊ��û���ҵÿ���");

		return 1;

	default:

		if (!ob->move(me)) {

			destruct(ob);

			return 0;

		}

		message_vision("$N��"+MONEY_D->price_str(i)+"�ļ۸��$n����������һ" + ob->query("unit") +

			ob->name() + "��\n", me, this_object());

		improve = 40 - me->query("pur");

		me->improve_skill("trade", improve + random(improve));

		add_temp("vendor_goods/"+ob_file,1);

	}

	}

	set_temp("busy", 1);

	call_out("delete_temp", 1, "busy");



	return 1;

}

