// Room: xuelingquan.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "ѩ��Ȫ");
	set("long", @LONG
������ѩɽ��ѩ�ڻ��������ɵ�һ��СϪ�������������ƽ̹�������һ��
Ȫˮ(quanshui)���峺����������͸�ǡ����ǣ�
    ˮ���е�������������ʱ��
    ǧɽ�ڲ�ס���Ͼ�����ȥ��
    ˮԶ����֪��ˮ�⣬ȴ����ɽ��Զ��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"shanlu5",
		"southdown" : __DIR__"fengjiantai",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-300);
  set("coor/y",160);
   set("coor/z",20);
   setup();
}
void init()
  {
	if (is_wanted(this_player()))
		return;
        add_action("do_tiao", "tiao");
  }
int do_tiao(string arg)
{
        object ob;
        ob = this_player();

        if( arg != "quanshui" ) 
             return notify_fail("��Ҫ����������\n");

        message_vision("$N������Ȫˮ��������ȥ��\n",ob);
        ob->move(__DIR__"quanshui");
        return 1;
}
