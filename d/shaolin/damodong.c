// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��Ħ��");
	set("long", @LONG
�����Ǵ�Ħ�Ŷ��������ǰ������ɮ�������Ħ���������£����˷�ˮ
���أ���ס�������޵��ӣ��������ڣ����������·������ǧ�겻��֮����
��Ħ��ʦ���ڴ���������һ��ʮ�꣬�ڼ��������Կɿ��������ʱ�Ĵ���
��̬�������ϵļ�����Ƭ�⣬���п���һ�
LONG
	);

	set("exits", ([
		"out" : __DIR__"bamboo1",
	]));

	set("coor/x",40);
	set("coor/y",520);
	set("coor/z",150);
	setup();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("bamboo/count") == 14 
	&&  (int)me->query_skill("dodge", 1) >= 30 
	&&  (int)me->query_skill("dodge", 1) <= 100 
	&&  present("bamboo", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("dodge", me->query("int"));
	}

	add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	int i,j,x,y;
	object me = this_player();
	i = (int)me->query("shen");
	j = me->query("combat_exp");
	y = me->query_skill("yijin-jing",1);
	x = me->query_skill("buddhism",1);

	if ( me->is_busy() ) return notify_fail("����æ����,���龲��������\n");

	me->start_busy(random(2));
	if (me->query("jing") < 100)
		return notify_fail("�㾫���㱣���Ҫ��Ϣ�ˡ�\n");
	me->receive_damage("jing", 50+random(50));
	if (x >= 200)
		if (i < 0) {
			me->add("shen",1000+random(5000));
			message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
			me->set_temp("sl_mianbi",1);
			return 1;
		} else if ( i > 0) {
			me->add("shen",-1000-random(5000));
			me->set_temp("sl_mianbi",2);
			message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ھ�����˼���ã���������\n", me);
			return 1;
		}
	message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڳ�˼��һ�ᣬ�������Խ��Խ�ң����ɵ�վ��������\n", me);
	return 1;
}
