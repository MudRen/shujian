// /clone/board/yuelao_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��������������", ({ "board" }) );
        set("location", "/d/city/yuelaoting");
        set("board_id", "yuelao_b");
        set("long", "����һ�������������˽��ĵ����Բ���\n" );
        setup();
        set("capacity", 60);
}
