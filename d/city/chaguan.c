// Room: /city/chaguan.c

inherit ROOM;
inherit F_SAVE;

#include <ansi.h>
string look_paizi();
string query_save_file()
{
	return "/log/quest/lottery";
}

mapping lottery;

void create()
{
	restore();
	if (!mapp(lottery))
		lottery = ([ ]);
	set("short", "���");
	set("long", @LONG
�������ݳ��ϵ�һ�Ҳ�ݡ�һ�߽��������ŵ�һ�ɲ���������Ƣ����ľ�
��Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ���
���Ϲ���һ������(zitie) ���������һ˵��֮�ˣ���������־��ˮ䰴�����
��Ӣ�Ҵ��ȵ�Ӣ�۹��¡��販ʿ����ߺ�����к�����, �ݲ���ˮ, æ�Ĳ�����
����
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("item_desc", ([
		"zitie" : HIC"\t\nʮ��һ�������Σ�Ӯ����¥��������\n"NOR,
		"paizi": (: look_paizi :),
	]));
	set("objects", ([
		__DIR__"npc/boshi" : 1,
		__DIR__"npc/shuren" : 1,
	]));

	setup();
}
/*
��ʱ�رգ��������¸Ľ�
void init()
{
	if ( wiz_level(this_player()) >= 5 )
		add_action("do_set", "game");
	add_action("do_ling", "draw");
	add_action("do_dui", "exchange");
}
*/
string help()
{
	return 	"game start					��ʼ��ȡ��ȯ\n"+
		"game close					��ֹ��ȡ��ȯ\n"+
		"game number <����> <����> <����> <����>         �����н�����(4λ)\n"+
		"game name <����>				�����н����\n";
}

int do_set(string arg)
{
	object me = this_player();
	int a, b, c, d;
	string str, msg, *type;

	if ( ! arg ) return notify_fail(help());

	if ( arg == "start") {
		if ( ! lottery["number"] )
			return notify_fail("�㻹û�����ñ����н��ĺ��룡\n");
		if ( ! lottery["name"] )
			return notify_fail("�㻹û�����ñ����н��ı�ǡ�\n");
		lottery["set"] = 1;
		msg = "�齱����ڿ�ʼ��\n";
	}
	else if ( arg == "close") {
		if ( lottery["set"] != 1) 
			return notify_fail("�齱���û��ʼ�������ʲô��\n");
		lottery["set"] = 0;
		msg = "�齱����ڽ�����\n";
	}
	else if ( sscanf(arg, "number %d %d %d %d", a, b, c, d) == 4) {
		if ( a > 9 || b > 9 || c > 9 || d > 9)
			return notify_fail("ÿλ��ֻ���Ǹ�λ����\n");
		if ( a == b || a == c || a == d || b == c || b == d || c == d)
			return notify_fail("ÿλ��������ͬ��\n");
		type = ({ chinese_number(a) }) + ({ chinese_number(b) }) + ({ chinese_number(c) }) + ({ chinese_number(d) });
		lottery["type"] = type;
		lottery["number"] = chinese_number(a) + chinese_number(b)+ chinese_number(c)+ chinese_number(d);
		msg = "���γ齱����ֵ�趨Ϊ��"+ lottery["number"] +"��\n";
	}
	else if ( sscanf(arg, "name %s", str) == 1){
		lottery["name"] = str;
		msg = "���γ齱���Ϊ��"+ str+"����\n";
	}
	else msg = help();

	save();
	tell_object(me, msg);
	return 1;
}


mixed get_number(object me)
{
	string *numbers=({"��","һ","��","��","��","��","��","��","��","��"});
	int x, i, j = sizeof(numbers);
	string num, str, *num_type;


	for ( x = 0; x < 4 ; x ++ ) {
		num = numbers[random(j)];
		num_type = me->query("lottery/type");

		if ( ! sizeof( num_type)) {
			me->set("lottery/type", ({ num }) );
			str =  num;
		}
		else {
			for ( i = 0; i < j ;i ++) {
				if (member_array( num, num_type) != -1)
					num = numbers[i];
			}
			me->set("lottery/type", num_type + ({ num }) ); 
			str += num;
		}
	}
	return str;
}

int do_ling()
{
	object ob, me = this_player();
	string str;

	if ( me->query("registered") < 3 ) {
		tell_object(me, "ֻ����ʽ�û�������ȡ��ȯ��\n");
		return 1;
	}

	if ( lottery["set"] != 1) {
		tell_object(me, "�齱��Ѿ������ˡ�\n");
		return 1;
	}

	if ( me->query("lottery/name") == lottery["name"]) {
		tell_object(me, "�㲻���Ѿ���ȡ����ȯ��ô��\n");
		return 1;
	}

	me->delete("lottery");
	str = get_number(me);
	me->set("lottery/name", lottery["name"]);
	me->set("lottery/time", time());
	me->set("lottery/number", str);
	ob = new(__DIR__"obj/lottery_paper");
	ob->set("lottery_number", str);
	ob->move(me);
	message_vision(HIY"$N�����ȡ��һ�Ŷҽ�ȯ��������ϸ�������ܿ�������д��һЩ���롣\n"NOR, me);
	return 1;
}

int do_dui()
{
	object ob, me = this_player();
	int i, j;
	string num, *num_type;

	ob = present("duijiang quan", me);
	num = me->query("lottery/number");
	num_type = me->query("lottery/type");

	if ( ! num ) 
		return notify_fail("�㶼û����ȡ��ȯ������ʲô������\n");

	if ( me->query("lottery/finish"))
		return notify_fail("�㲻���Ѿ��ҹ�����ô����ô������\n");

	if ( ob && !me->query_temp("lottery_look"))
		return notify_fail("������ȯ���������������ҽ�����\n");

	if ( num == lottery["number"])
		i = 5;
	else {
		for ( j = 0; j < sizeof( num_type); j ++)
			if (member_array(num_type[j], lottery["type"]) != -1)
				i ++;
	}
	switch (i) {
		case 5:	
			me->add("combat_exp", 50000);
			me->add("potential", 2000);
			me->add("balance", 10000000);
			me->add("max_neili", 100);
			me->add("max_jingli", 100);
			tell_object(me, HIR"��ϲ�������صȽ���\n");
			tell_object(me, "������������ʵս���顢��ǧ��Ǳ�ܡ�һǧ���ƽ�һ�ٵ����������һ�ٵ��������\n"NOR);
			break;
		case 4:	
			me->add("combat_exp", 25000);
			me->add("potential", 1000);
			me->add("balance", 5000000);
			me->add("max_neili", 50);
			me->add("max_jingli", 50);
			tell_object(me,	HIR"��ϲ������һ�Ƚ���\n");
			tell_object(me, "������˶�����ǧ��ʵս���顢һǧ��Ǳ�ܡ���ٶ��ƽ���ʮ�������������ʮ���������\n"NOR);
			break;
		case 3:	
			me->add("combat_exp", 10000);
			me->add("potential", 500);
			me->add("balance", 3000000);
			me->add("max_neili", 20);
			me->add("max_jingli", 20);
			tell_object(me, HIR"��ϲ�����˶��Ƚ���\n");
			tell_object(me, "�������һ���ʵս���顢��ٵ�Ǳ�ܡ����ٶ��ƽ𡢶�ʮ�������������ʮ���������\n"NOR);
			break;
		case 2:	
			me->add("combat_exp", 5000);
			me->add("potential", 200);
			me->add("balance", 2000000);
			me->add("max_neili", 10);
			me->add("max_jingli", 10);
			tell_object(me, HIR"��ϲ���������Ƚ���\n");
			tell_object(me, "���������ǧ��ʵս���顢���ٵ�Ǳ�ܡ����ٶ��ƽ�ʮ�����������ʮ���������\n"NOR);
			break;
		case 1:	
			me->add("combat_exp", 3000);
			me->add("potential", 100);
			me->add("balance", 1000000);
			tell_object(me, HIR"��ϲ�������ĵȽ���\n");
			tell_object(me, "���������ǧ��ʵս���顢һ�ٵ�Ǳ�ܡ�һ�ٶ��ƽ�\n"NOR);
			break;
		default:
			tell_object(me, "���ź�����û���н������ǿ��´ΰɡ�\n");
			break;
	}
	me->set("lottery/finish", 1);
	me->delete_temp("lottery_look");
	if ( ob) destruct(ob);
	log_file("quest/bonus", 
		sprintf("%18s ���룺%s���н����룺%s������ %d��",
			me->name(1)+"("+ me->query("id") +")",
			num,
			lottery["number"],
			i,
		), me
	);
	return 1;
}

string look_paizi()
{
	string str;

	if ( lottery["set"] != 1)
		return "����û�г齱���\n";

	str = "\nһ���ص㣺���ݳǲ�ݡ�\n";
	str += "����ָ�������ȡ��ȯ(draw)��Ȼ��ҽ�(exchange)��\n";
	str += "�������Χ����ʽ��Ҽ��ɡ�\n";
	str += "�ġ�������Χ��\n";
	str += "1���صȽ���Ҫ����ҳ齱�����빫�����н�������ֵ������˳����ȫ��ͬ��\n";
	str += "��Ʒ�������ʵս���顢��ǧ��Ǳ�ܡ�һǧ���ƽ�һ�ٵ����������һ�ٵ��������\n";
	str += "2��һ�Ƚ���Ҫ����λ���빫�����н�������ͬ��˳������ν��\n";
	str += "��Ʒ��������ǧ��ʵս���顢һǧ��Ǳ�ܡ���ٶ��ƽ���ʮ�������������ʮ���������\n";
	str += "3�����Ƚ���Ҫ����λ���빫�����н�������ͬ��˳������ν��\n";
	str += "��Ʒ��һ���ʵս���顢��ٵ�Ǳ�ܡ����ٶ��ƽ𡢶�ʮ�������������ʮ���������\n";
	str += "4�����Ƚ���Ҫ���λ���빫�����н�������ͬ��˳������ν��	\n";
	str += "��Ʒ����ǧ��ʵս���顢���ٵ�Ǳ�ܡ����ٶ��ƽ�ʮ�����������ʮ���������\n";
	str += "5���ĵȽ���Ҫ��һλ���빫�����н�������ͬ��˳������ν��\n";
	str += "��Ʒ����ǧ��ʵս���顢һ�ٵ�Ǳ�ܡ�һ�ٶ��ƽ�\n";
	str += "6��û��һλ���빫�����н�������ͬ��û�н�����\n";

	str +="\n\n�����н������ǣ�\n";
	str += CHINESE_D->font(lottery["number"]);
	str += "\n\n";

	return str;
}
                                                                                          