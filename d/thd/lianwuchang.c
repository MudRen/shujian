// /u/jpei/thd/lianwuchang.c

inherit ROOM;

int do_jump(string arg);
string look_zhuang();

void create()
{
	set("short","���䳡");
	set("long",@LONG
���ǹ��һ����ϵ����������ĳ��ӡ����߰������ű����ܣ�������Ÿ���
���������Ļ��Ǹ�ʽ�����Ľ����ڳ�����������һ���ܸߵ�ľ׮(zhuang)��
���������������õġ��������е�����Ϣ�ң����ϱ�����Ů������Ϣ�ҡ�����
�ǵ����ǳԷ��ͺȲ�ĵط���
LONG
);
	set("exits",([
		"north" : __DIR__"xiuxishi-m",
		"south" : __DIR__"xiuxishi-f",
		"east" : __DIR__"zoulang3",
		"west" : __DIR__"fanting1",
	]) );

	set("objects",([
		__DIR__"obj/shizi" : 1,
		"/clone/weapon/changjian" : 2,
        "/clone/weapon/sword/ziyuxiao" : 1,
//		__DIR__"npc/machine-bonze" : 4,
	]));
	
	set("item_desc",([
		"zhuang" : (: look_zhuang :),
	]) );

	set("no_clean_up",0);
	set("valid_startroom", 1);
	set("outdoors", "�һ���");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object me = this_player();
	int level, jinglicost;

	level = me->query_skill("dodge", 1);
	if (arg == "zhuang") {
		if (me->query_temp("thd_zhuang")) {
			write("���Ѿ���׮���ˣ�����վ����ͷ��ɣ�\n");
			return 1;
		}
		jinglicost = level / 4 + random(level / 3);
		if (me->query("jingli") <= jinglicost) {
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		if (level < 50) {
			write("���������ƣ���׮��Ծȥ����ϧ���ǽż⻹��һЩ���ܹ�����\n");
			return 1;
		}
		me->receive_damage("jingli", jinglicost);
		if (level < 100) {
			message_vision("$N���˿�����������ľ׮�����ƺ��Ƕ����Ṧ�ĺ÷�����\n", me);
			me->improve_skill("dodge", me->query_int());
		}
		else
			message_vision("$N����΢һ�˾��������һ�ݾ�����ľ׮��������ľ׮��$P����Ҳ̫���ˡ�\n", me);
		me->set_temp("thd_zhuang", 1);
		return 1;
	}
	if (arg == "down") {
		if (!me->query_temp("thd_zhuang")) {
			message_vision("$N���ڸ�������ȥ���Ĵ��Ȼ���һ����ȴ������Χ���˶����������۹⿴���㡣\n", me);
			return 1;
		}
		jinglicost = level / 5 + random(level / 4);
		if (me->query("jingli") <= jinglicost) {
			write("��̫���ˣ���ЪЪ�ɣ�\n");
			return 1;
		}
		me->receive_damage("jingli", jinglicost);
		if (level < 100) {
			message_vision("$N���ֱ��ŵش�׮�ϵ����������������������ͨ�Ṧ��һʽ��ƽɳ���㡱��\n", me);
			me->improve_skill("dodge", me->query_int() / 3);
		}
		else
			message_vision("$N����һ���䵽�˵��ϣ�����������ľ׮��$P����Ҳ̫���ˡ�\n", me);
		me->delete_temp("thd_zhuang");
		return 1;
	}
	return notify_fail("��Ҫ����������\n");
}

string look_zhuang()
{
	if (this_player()->query_temp("thd_zhuang"))
		return "�������µ�ľ׮��ȥ�������е���ѣ����ô��ľ׮�����Լ��ڳ�ѽ����\n";
	else
		return "ľ׮��ش���������ң�����ֻ�и��ֲ�������ȥ��\n";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("thd_zhuang"))
		return notify_fail("�ȴ�ľ׮��������(down)��˵�ɣ�\n");

	if (dir == "north" && me->query("gender") != "����")
		return notify_fail("�������Ҫ�����ߣ���Ȼ�������涼�ǹ���ӵ��е��ӣ����æ���������˳�����\n");

	if (dir == "south" && me->query("gender") != "Ů��")
		return notify_fail("�������Ҫ�����ߣ�ȴ�������洫��һ��Ů���ӵļ���������ŵø�æ���˳�����\n");

	return ::valid_leave(me, dir);
}
