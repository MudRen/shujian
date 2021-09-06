inherit ROOM;

void create()
{
	set("short","���̷�");
	set("long","�����ˡ���\n");
	set("no_update", 1);
	set("exits/out", VOID_OB);
	setup();
}

void init()
{
	object ob = this_player();

	if (wizardp(ob))
		return;
	ob->clear_condition();
	ob->set_ghost(0);
	ob->set("startroom", __FILE__[0..<3]);
	ob->save();
	add_action("block_cmd","", 1);
}

int block_cmd(string arg)
{
	switch(query_verb()) {
		case "look":
			if (arg) return 1;
		case "go":
		case "out":
		case "quit":
		case "suicide":
			return 0;
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	int exp = me->query("combat_exp");

	if (exp < 100000)
		return notify_fail("�㻹������ʵʵ�ش��Űɡ�\n");
	if (exp > 1000000)
		exp /= 10;
	else
		exp = 100000;
	if (!me->query_temp("confirm")) {
		me->set_temp("confirm", 1);
		me->start_busy(2);
		return notify_fail("�뿪���ｫ�ܵ��۳�"+chinese_number(exp)+"�㾭��Ĵ����������ͬ�⣬��������һ�� out\n");
	}
	me->delete_temp("confirm");
	me->add("combat_exp", -exp);
	tell_object(me, "�㱻�۳���"+chinese_number(exp)+"�㾭�顣\n");
	me->setup();
	return ::valid_leave(me, dir);
}
