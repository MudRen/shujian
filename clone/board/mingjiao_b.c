// /clone/board/tianlong_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("����ʥ��", ({ "board" }) );
        set("location", "/d/mingjiao/gmd");
       set("board_id", "mingjiao_b");
        set("long", "�������̹������Ĺ���ʥ�𱮡�\n" );
        setup();
        set("capacity", 60);
}

