// /clone/board/quanzhen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("全真教留言簿", ({ "board" }) );
	set("location", "/d/quanzhen/datang1");
	set("board_id", "quanzhen_b");
	set("long", "这是一张全真教留言簿。\n" );
	setup();
	set("capacity", 60);
}
