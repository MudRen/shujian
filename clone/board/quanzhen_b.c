// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ȫ������Բ�", ({ "board" }) );
	set("location", "/d/quanzhen/datang1");
	set("board_id", "quanzhen_b");
	set("long", "����һ��ȫ������Բ���\n" );
	setup();
	set("capacity", 60);
}
