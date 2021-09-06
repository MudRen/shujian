// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set("board_id", "wiz_b");
	set("location", "/d/wizard/wizard_room");
	setup();
	set_name("��ʦ���Բ�", ({ "board" }) );
	set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
	set("capacity", 999);
}

void init()
{
	::init();
	add_action("do_meet", "sj_meet");
}

int do_post(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("ȥ����\n");
	return ::do_post(arg);
}

int do_read(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("ȥ����\n");
	return ::do_read(arg);
}

int do_list(string arg)
{
	if (!wizardp(this_player()))
		return notify_fail("ȥ����\n");
	return ::do_list(arg);
}

int do_meet()
{
	object *ob = objects();
	int i = sizeof(ob);

	message_vision("$N���������ټ���ʦ��\n", this_player());
	while (i--)
		if (userp(ob[i]) && wiz_level(ob[i])
		&& !present(ob[i], environment())) {
			ob[i]->move(environment());
			message_vision("$Nϡ���Ϳ�ر����˹�����\n", ob[i]);
		}

	EMOTE_D->do_emote(this_player(), "meeting");
	return 1;
}
