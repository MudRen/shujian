// wang zhanggui
// by augx@sj  3/21/2002

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
#include <group.h>

void create()
{
	set_name("���ƹ�", ({"wang zhanggui", "wang", "zhanggui"}));
	set("title", "�������ϰ�");
	set("gender", "����");
	set("long", "��λ���ƹ��Ѿ��ڴ˾�������ж��꣬�����ܺã����кܶ཭�������������\n����������������ʹ����Ʊ��\n");
	set("age", 50);

	set("no_kill",1);
	set("no_ansuan",1);
	set("no_bark",1);
	set("no_get", 1);

	set("max_qi", 99999);
	set("qi", 99999);
	set("max_jing", 99999);
	set("jing", 99999);
	set("max_neili", 99999);
	set("neili", 99999);
	set("eff_jingli", 99999);
	set("jingli", 99999);

	set("combat_exp",5000000);
	set("chat_chance", 1);
	set("chat_msg", ({
		"���ƹ񽾰���˵�������еĽ������ϺͶ��ǻ����ʵ�İ���\n",
		"���ƹ�˵�����Һͺܶ���Ĵ�綼�й�ϵ�ޣ��������ҵĵ����������ǡ�\n"
	}));

	set_skill("unarmed", 350);
	set_skill("dodge", 350);
	set_skill("parry", 400);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 30);

	set("vendor_goods", ({
		(["name": "/d/group/obj/biaozhi.c","number":5]),
		(["name": "/d/group/obj/qiangui.c","number":5]),
		(["name": "/d/group/obj/shiliao.c","number":20]),
		(["name": "/d/group/obj/muliao.c","number":20]),
		(["name": "/d/group/obj/shihui.c","number":30]),
		(["name": "/d/group/obj/door.c","number":5]),
		(["name": "/d/group/obj/board.c","number":5]),
		(["name": "/d/group/obj/guard.c","number":10]),
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int query_goods_value(string goods, int number)
{
	object me = this_player();
	int value, trade_level;
	int cur;

	value = ((object)goods)->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 20) trade_level = 20;
	value = value /100 * (120 - trade_level);

	cur = query_temp("vendor_goods/"+goods);
	if( cur!=number ) value += value/5 /number*cur;

	return value;
}

int do_buy(string arg)
{
	int i, improve, delay;
	string ob_file;
	object ob;
	object me = this_player();
	mapping goods;

	if (!living(this_object()))
		return notify_fail("���ǵȶԷ�������˵�ɡ�\n");
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (!me->query("group/id"))
		return notify_fail("����û�м����ᣬҪ����Щ������ʲô��\n");
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
	if (!(int)query("move_seller") && base_name(environment()) != query("startroom"))
		return notify_fail("�⡭��������ǳ�������ģ����´����ɡ�\n");
	if (!arg) return notify_fail("������ʲô��\n");
	if ((ob_file = is_vendor_good(arg)) == "")
		return notify_fail("������Ķ���������û�С�\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	goods=query("vendor_goods");
	for(i=0;i<sizeof(goods);i++)
		if(goods[i]["name"]==ob_file)
			break;

	ob = new(ob_file);
	if( ob->query("guard") && file_size("/d/group/"+me->query("group/id"))!=-2 ) {
		destruct(ob);
		return notify_fail("��İ��ɻ�û�н������أ�Ҫ���ڸ�ʲô��\n");
	}

	i = query_goods_value(ob_file,goods[i]["number"]);

	if( me->query("group/id") && me->query("group/class")<=3
	    && (GROUP_D->query_money(me->query("group/id"))-LIMIT_GOLD)>(i/10000+1) ) {
		i = i/10000 + 1;
		if( GROUP_D->add_money(me->query("group/id"),-i) < -50000 ) {
			destruct(ob);
			return notify_fail("���ݿ����ʧ�ܣ��뱨����ʦ��\n");
		}
		i *= 10000;
	}
	else {
		if( MONEY_D->player_pay(me,i,1) == 0 ) {
			destruct(ob);
			return notify_fail("��⵰��һ�ߴ���ȥ��\n");
		}
	}

	if( ob->query("guard") ) {
		message_vision("$N����"+MONEY_D->price_str(i)+"�ļ۸��$n�����Ӷһλ" + ob->name() + "��\n", me, this_object());
		ob_file = ob->query("guard_file");
		destruct(ob);

		ob_file = GROUP_D->create_group_npc(ob_file,me);
		if( strlen(ob_file)>3 && ob_file[0..2]!="/d/" )
			return notify_fail(ob_file);

		delay = 10;
		if( wizardp(me) && me->query("env/test") ) delay = 2;
		me->start_busy(delay);
		call_out("create_group_npc_finish",delay*2-1,me,ob_file);
	}
	else {
		if (!ob->move(me)) {
			destruct(ob);
			return 0;
		}
		message_vision("$N��"+MONEY_D->price_str(i)+"�ļ۸��$n����������һ" + ob->query("unit") + ob->name() + "��\n", me, this_object());
	}
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve + random(improve));
	add_temp("vendor_goods/"+ob_file,1);

	set_temp("busy", 1);
	call_out("delete_temp", 2, "busy");

	return 1;
}

void create_group_npc_finish(object me,string file)
{
	object ob;
	string * ids;

	if( !me ) return;
	if( !(ob=new(file)) ) {
		tell_object(me,"NPC����ʧ�ܣ��뱨����ʦ��\n");
		return;
	}

	ob->move( environment(me) );
	ob->set("title",GROUP_D->get_group_name(me->query("group/id"))+"����");
	ob->set("group",copy(me->query("group")));
	ob->set("group/class",5);
	ids = ob->parse_command_id_list();
	if( sizeof(ids) > 1 ) ob->set("id1",ids[1]); else ob->set("id1",ob->query("id"));
	if( sizeof(ids) > 2 ) ob->set("id2",ids[2]); else ob->set("id2",ob->query("id"));
	ob->save();

	tell_object(me,"��Ҫ��Ӷ�ı���"+ob->name()+"���˹�����\n");
	ob->set_leader(me);
	tell_object(me,ob->name()+"��������"+me->name()+"һ���ж���\n");
}
