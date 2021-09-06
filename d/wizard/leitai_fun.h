// leitai_fun.h
// modified by augx@sj  10/29/2001

string look_leitai()
{
	object me, room;

	me = this_player();
	if (me->is_busy()) return "����æ���ء�\n";
	me->start_busy(2);

	room = load_object(query("leitai"));
	if (!room)
		return "������̨û��׼���ã���֪ͨ��ʦ��\n";
	message_vision("$N������̨�ߣ��쳤�˲���������ȥ��\n", me);
	"/cmds/std/look.c"->look_room(me, room);

	return "";
}

int valid_leave(object me, string dir)
{
	object room;
	int i;

	if( dir != "out" && !wizardp(me)) {
		room = load_object(query("exits/"+dir));

		i = room->query_temp("num");
		if( i > 15 ) {
			me->start_busy(1);
			return notify_fail(room->query("short")+"�Ѿ�����Ϊ�����㼷����ȥ��\n");
		}
	}

	if (userp(me) && !wizardp(me))
		add_temp("num", -1);
	return ::valid_leave(me,dir);
}

int do_action(string arg)
{
	object me = this_player();

	if (me->is_busy())
		return 1;
	me->start_busy(2);
	write("\n����Ҫ����������ͻȻ�������˽���һ�ģ��úÿ����䣬���Ҷ���\n");
	return 1;
}

int do_biwu()
{
	object me, ob;
	mapping mp;

	me = this_player();

	if( me->query("combat_exp") < 100000 )
		return notify_fail("Ҫ����̨���䣬����ʸ񻹲���Щ����ȥ�����ɡ�\n");
	if( mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp)>0 )
		return notify_fail("�㻹�����κ���Ĳ���������ɡ�\n");
	if( mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp)>0 )
		return notify_fail("�㻹���Ƚ������ĸ��˶�Թ��������ɡ�\n");

	if (!(ob = find_object(query("leitai"))))
		ob = load_object(query("leitai"));
	if( !ob )
		return notify_fail("������̨û��׼���ã���֪ͨ��ʦ��\n");
	if( ob->query_temp("leitai") > 1 )
		return notify_fail("�������ڱ����أ����ȵ����Ƿֳ�ʤ����˵�ɡ�\n");

	message_vision("\n$N�ο���Ⱥ������˵����"+RANK_D->query_self(me)+"�����ޣ�˵�����̨����ȥ��\n", me);
	return ob->load_user(me);
}
