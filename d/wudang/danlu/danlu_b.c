// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
    set_name("��ҩ���԰�", ({ "board" }) );
    set("location", "/d/wudang/yaofang");
    set("board_id", "danlu_b");
    set("long", "�����£գǣ���д���⡣���벻Ҫ��ҩ�������ڴˣ�Υ���ϳͣ�\n" );
	setup();
    set("capacity", 100);
}

