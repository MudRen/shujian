// Room: /d/emei/jiulaodong.c ������ ���϶�

inherit ROOM;

void create()
{
	set("short", "�����ֹ㳡");
	set("long", @LONG
�����Ƕ��һ����ֵĹ㳡������������ש����ǰ����һ��̨�ף�ͨ����
�۱����ǰ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�������գ�����Ʈ�ơ�
�㳡���м���Сʦ̫�����������Դ����Ҹ���һ������ͨ���
LONG
	);

	set("exits", ([
//		"northeast" : __DIR__"jiudaoguai4",
//		"northwest" : __DIR__"lianhuashi",
	]));

	set("objects",([
		"/d/shaolin/obj/book-bamboo" : 1,
	]));
	setup();
}
/*
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

        add_action("do_mianbi","���");	
        add_action("do_mianbi","mianbi");	
}

int do_mianbi()
{
	object me = this_player();

	message_vision("$N����Ŵ�Ħ�����ߵ�ʯ�ڵ�����˼�����ã���������\n", me);
	
	me->set_busy(10);
	me->set("shen",0);

	return 1;
}
*/
