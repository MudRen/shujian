// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("̫������ͼ", ({ "board" }) );
        set("location", "/d/wudang/sanqing");
	set("board_id", "wudang_b");
	set("long", "����һ���䵱ɽ��̫������ͼ�����滭��һЩ������\n" );
	setup();
	set("capacity", 60);
}

