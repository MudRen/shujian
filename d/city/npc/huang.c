// huang.c ���ϰ�

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("�����ϰ�", ({ "lao ban", "laoban" }));
	set("shen_type", 0);
        set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"�����ϰ����ڶ����㿴����ȥ��\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	//if (clonep()) call_out("do_bid", 200+random(200));
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}
/*
mixed *item;

mixed ask_obj()
{
	object me = this_player(), obj;

	if (me->query("registered") < 3) {
		command("need1 "+me->query("id"));
		return 1;
	}
	if (me->query("last_bid_time") > time() - 900) {
		command("taoyan "+me->query("id"));
		return 1;
	}
	if (!sizeof(item)) return "��ѽ�������Ѿ���ԭ����ȡ���ˡ�";
	delete("bid_obj");
	command("take "+item[0]+" "+item[1]);
	if (!(obj = query("bid_obj")))  return "��ѽ��"+item[2]+"�Ѿ���ԭ����ȡ���ˡ�";
	command("pat "+me->query("id"));
	if (present("1") == obj) command("give 1 to "+me->query("id"));
	else obj->move(me);
	me->set("last_bid_time", time());
	delete("bid_obj");
	delete("inquiry");
	return 1;
}

void do_bid()
{
	int i;
	mixed *obj = environment()->query_by_time(5*360*12*120);

	remove_call_out("do_bid");
	call_out("do_bid", 200+random(200));
	item = 0;
	delete("inquiry");
	if (!(i = sizeof(obj))) return;
	item = obj[random(i)];
	command("chat "+item[2]+"��С���Ѿ������"+chinese_number((time()-item[3])/360/12/120)+"�����࣬ ԭ����("+capitalize(item[0])+")����֧����� һֱδ��ȡ�ߣ� ���޳�ת�ã� ������������Ǣ̸��");
	set("inquiry/"+strip(item[2]), (: ask_obj :));
}
*/
