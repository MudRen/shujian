inherit BULLETIN_BOARD;

void create()
{
        set_name("�����о����۰�", ({ "board" }) );
        set("location", "/d/city/kedian/pianting");
        set("board_id", "skill_b");
        set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
        setup();
	set("capacity", 300);
}

int do_post(string arg)
{
	object ob = this_player();

	if (!ob->query("can_post") && ob->query("combat_exp") < 1000000)
		return notify_fail("�㻹�����ʸ����������ԡ�\n");
	return ::do_post(arg);
}
