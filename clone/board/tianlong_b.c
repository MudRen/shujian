// /clone/board/tianlong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�������±�", ({ "board" }) );
        set("location", "/d/tls/road");
        set("board_id", "tianlong_b");
        set("long", "�����������е��������±���\n" );
        setup();
        set("capacity", 60);
}

