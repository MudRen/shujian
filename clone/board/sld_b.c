// /clone/board/sld_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�����̵������԰�", ({ "board" }) );
set("location", "/d/sld/kongdi");
        set("board_id", "sld_b");
        set("long", "����һ���������̵���ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 60);
}
