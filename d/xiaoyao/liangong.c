// liangong.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ������в�û��ʲô
�ر�İ�������������ܵ��κζ�����ɧ�ţ��Ǹ������ڹ��ĺõط���
��������и�ľ��(door)��ͨ��һ����֪��ʲôȥ����С·��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
void init()
{
         add_action("do_push", "push");
}

int do_push(string arg)
{
         object me = this_player();
         if (arg != "door")
                 return notify_fail("��Ҫ��ʲô?\n");
         if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

     message_vision("$N������ƿ�ľ�ţ�ԭ��ȴ��һ�����ѵ�С·��ò�ƿ���ֱ����ǡ�\n", me);
         me->receive_damage("jing", 30);
         me->move("/d/zhiye/gaoshan0");
         message_vision("$N��ͷ�󺹵Ĵ����ɽһ����С·���˹�����\n", me);
         me->start_busy(random(2));
         return 1;
}










