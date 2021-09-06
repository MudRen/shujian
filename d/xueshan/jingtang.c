// Room: jingtang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��Ϊʮ��Ъɽ�������ƾ��壬���ù�ģ������д�����ǧ������ͬʱ����
������ɮ��ͬʱ�о�����ǰ��Ծ����������ţ�����ޡ������ʯ���񡣵��ڴ�
��������ǽ���Ͽ������ģ��м���ɮ��������������(chanding)������Щɮ�˶�
��ǽ���ϵľ���ڤ˼����(mingxiang)��
LONG
        );

        set("exits", ([
                "west" : __DIR__"fanyinge",
                "south" : __DIR__"jingjinzhacang",
        ]));

        setup();
}

void init()
{
        add_action("do_chanding", "chanding");
        add_action("do_mingxiang", "mingxiang");
        add_action("do_write","write");
}

int do_chanding()
{
	object me;
	me = this_player();

	if (me->is_fighting())
		return notify_fail("���޷���ս����������\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("������������ʶ�ֲ��࣬�޷�����\n");

	if (me->query_skill("huanxi-chan",1) > 30)
		return notify_fail("ʯ���ϵľ������Ѿ�����͸���ˣ���������ûʲô�����ˡ�\n");

	if((int)me->query("jing") < 20) 
		return notify_fail("���Ҫڤ�룬ֻ����������ת��ԭ����̫ƣ����......\n");

	me->add("jing", -10+random(5));
	me->improve_skill("huanxi-chan", me->query("int"));
	write("����Ŵ����������·�Դ����ϵľ�����������\n");
	return 1;
}

int do_mingxiang()
{
	object me;
	me = this_player();
	
	if (me->is_fighting())
		return notify_fail("���޷���ս����ڤ�롣\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("������������ʶ�ֲ��࣬�޷�����\n");

	if (me->query_skill("huanxi-chan",1) < 30)
		return notify_fail("����Ϣ��������Ŀڤ�롣����ȴһƬ�հף�ԭ����Ļ���̫���ˡ�\n");

	if (me->query_skill("huanxi-chan",1) > 100)
		return notify_fail("ʯ���ϵľ������Ѿ�����͸���ˣ�ڤ�����ûʲô�����ˡ�\n");

	if((int)me->query("jing") < 50)
		return notify_fail("���Ҫڤ�룬ֻ����������ת��ԭ����̫ƣ����......\n");

	me->add("jing", -(20+random(10)));
	me->improve_skill("huanxi-chan", me->query("int"));   
	write("����Ϣ��������Ŀڤ�룬�ƺ���ǽ���ϵľ�����������\n");
	return 1;
}

int do_write(string arg)
{
	object me ;
	int lite;

	me = this_player();
	lite = me->query_skill("literate");

	if ( arg != "jingshu" || !arg) 
		return notify_fail("��Ҫдʲô��\n");

	if (me->is_fighting())
		return notify_fail("���޷���ս����д���顣\n");

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	if (me->query_skill("literate",1) < 10)
		return notify_fail("����ֲ�ʶ������Ҳ��д���飿\n");

	if (me->query_skill("huanxi-chan",1) < 30)
		return notify_fail("�㿴����ǽ������������֣�ֻ��ͷ�Է��ǣ�û��ͷ����ԭ����Ļ���̫���ˡ�\n");

	if ((!present("bo juan", this_player())) || (!present("mao bi", this_player()))) 
		return notify_fail("��������д���õ����߲������޷�д���顣\n");
 
        if( me->query_temp("fojing"))
                return notify_fail("���Ѿ����þ����ˡ�\n");

	if ((me->query_temp("write") == 20 ) && (lite < 30)) {
		new("/clone/misc/fojing3")->move(me);
		me->set_temp("fojing", 1);
		message_vision("�㽫д�õĲ��������˳�����˸����������ڳ����ˡ�\n",me);
		return 1;
	}
	if ((me->query_temp("write") == 35 ) && (lite < 100) && (lite >= 30)) {
		me->set_temp("fojing", 1);
		new("/clone/misc/fojing1")->move(me);
		message_vision("�㽫д�õĲ��������˳�����˸����������ڳ����ˡ�\n",me);
		return 1;
	}
	if ((me->query_temp("write") == 50 ) && (lite >= 100)) {
		new("/clone/misc/fojing2")->move(me);
		me->set_temp("fojing", 1);
		message_vision("�㽫д�õĲ��������˳�����˸����������ڳ����ˡ�\n",me);
		return 1;
	}
	me->add_temp("write", 1);
	message_vision("$Nչ����ƽ�����ë�ʽ�ǽ���ϵľ��Ĺ���������¼��������\n", me);
	return 1;
}
