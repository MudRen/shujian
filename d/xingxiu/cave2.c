// room: /d/xingxiu/cave2.c
// Modify by Lklv 2001.10.16

inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����Ǻ������ɽ������ֲ�����ָ��ֻ��һ˿΢��Ӷ������ѷ�͸��
����������ǿ������������һ��ʯ�ף�ɢ����Ũ��ĸ�ʬ��ζ��΢���¸��Ե�
������ɭ���¡�һ����һ�����Ӱ����ʯ�ڱߣ���ֻ����������۾���������
����ɽ�������˹�����֮����
LONG);
	set("objects", ([
		__DIR__"npc/piaoran" : 1,
		__DIR__"obj/shiguan" : 1,
                __DIR__"obj/muding" : 1,
"/clone/misc/fire" : 2,
	]));
	setup();
}

void init()
{
	add_action("do_use", "use");
	add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (me->is_busy() || me->is_fighting()) return 0;
	if (!present("fire", me))  return 0;
	if(arg=="fire") {
		write("���ȼ�˻��ۣ����ֶ���ʯ���ϵ�һ���ѷ������(zuan)��ȥ��\n");
		me->set_temp("marks/��", 1);
		me->start_busy(2);
		return 1;
	}
}

int do_zuan(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting()) return 0;
	if(me->query_temp("marks/��") ) {
		message("vision", me->name() + "����һ�²�֪��ʲô�ط����ȥ�ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"cave");
		message("vision", me->name() + "��֪��ʲô�ط����˳�����\n", environment(me), ({me}) );
		me->set_temp("marks/��", 0);
		return 1;
	}
	else {
		write("�������Ķ���?!\n");
		return 1;
	}
}
