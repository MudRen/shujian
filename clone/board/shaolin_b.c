// /clone/board/shaolin_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��������������", ({ "board" }) );
	set("location", "/d/shaolin/guangchang");
	set("board_id", "shaolin_b");
	set("long", "����һ��޴��ʯ�������������������\n" );
	setup();
	set("capacity", 60);
}
