// /clone/board/towiz_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ɽ�۽������", ({ "board" }) );
       set("location","/d/taishan/fengchan");
     set("board_id", "hslj_b");
	set("long", "����һ�����ڻ�ɽ�۽������԰塣\n" );
	setup();
	set("capacity", 60);
}

/* int do_read(string arg)
{
	if (!wizardp(this_player()))
        return notify_fail("����������Ϊ���ֻ��ܣ�ֻ����ʦ�ſ��Կ���������ԡ�\n");

     return ::do_read(arg);
} */
