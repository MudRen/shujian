// /clone/board/towiz_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("������ԩ��", ({ "board" }) );
        set("location", "/d/city/yamen");
	set("board_id", "towiz_b");
        set("long", "����һ������������ԩ�����԰塣\n" );
	setup();
	set("capacity", 60);
}
