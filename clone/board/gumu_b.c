// /clone/board/gumu_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ʯ��", ({ "board" }) );
	set("location", "/d/gumu/rukou");
	set("board_id", "gumu_b");
	set("long", "����һ�����ڹ�Ĺ���µ�ʯ����������������˵ıʼ���\n" );
	setup();
	set("capacity", 60);
}

