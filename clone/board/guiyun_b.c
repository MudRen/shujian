// /clone/board/guiyun_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("����ׯ�ÿ����԰�", ({ "board" }) );
        set("location", "/d/thd/guiyun/qianting");
	set("board_id", "guiyun_b");
	set("long", "����һ�����һ������½��������԰塣\n" );
	setup();
	set("capacity", 60);
}

