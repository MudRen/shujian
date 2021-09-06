// /d/miaojiang/shandong.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���ɽ���������ģ����������ֲ�����ָ����ϸ��ȥ������ԼԼ���Կ�
���ı������������٣�shuteng���� ���ټ�·���ʲô���������������㲻��
�������⡣
LONG
        );
	set("exits", ([
		"out" : __DIR__"slu9",
	]));
	set("xuezhu_count", 1);
        setup();
}

void reset()
{
	set("xuezhu_count", 1);
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_yao", ({ "zuan", "yao" }));
}

int do_dian(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	if (!present("fire", me))  return 0;
	if( arg=="fire" ) {
		write("\n���ȼ�˻��ۣ����Ź����㿴�������ı�ȫ�����٣�\n"+
		"���ٵĿ�϶�в�����ѩ�׵�֩������\n");
		me->set_temp("mark/��", 1);
		return 1;
	}
}

int do_yao(string arg)
{
	object me = this_player();
	if ( !arg || arg != "shuteng" )
		return notify_fail("��Ҫ��ʲ�᣿\n");
	if (!me->query_temp("mark/��"))
		return notify_fail("����̫���ˣ����������٣��㻹�ǵ�����۰ɡ�\n");
	if (query("xuezhu_count") > 0) {
		message_vision("$N����ҡ�����٣���Ȼ����һֻѩ�롣\n", me);
		add("xuezhu_count", -1);
		new(__DIR__"npc/xuezhu")->move(__DIR__"shandong",);
		me->delete_temp("mark/��");
	}
	else
		message_vision("$N�ζ��˰��죬����ʲ��Ҳû�С�\n", me);
	return 1;
}
