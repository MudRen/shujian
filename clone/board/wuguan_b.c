// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
      set_name("��ݻ�����", ({ "board" }) );
      set("location", "/d/wuguan/dayuan");
      set("board_id", "wuguan_b");
      set("long", "����һ����������ڹ����������õĻ����ᡣ\n" );
	setup();
	set("capacity", 60);
}
int do_post(string arg)
{
       object me;
       me = this_player();
       if (me->query("combat_exp",1) < 200)
               return notify_fail("�����ڵĽ��������������������ԡ�\n");

       return ::do_post(arg);
}
