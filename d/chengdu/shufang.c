// Room: /d/chengdu/zijuefushufang.c
// By Jpei

inherit ROOM;

string look_shelf();

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����Ӿ������鷿�����������߸�����(shelf)������ȫ�����ס�
LONG
	);

	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));

	set("exits", ([
                "east" : __DIR__"zjhall",
	]));

	set("incity",1);
	setup();
}

string look_shelf()
{
	object me = this_player();

	if (!present("ouxue pu", me) && me->query_temp("qipu_guess_win") && !me->query_temp("ouxiepu_got")) {
		new("d/meizhuang/obj/ouxuepu")->move(me);
		return "��������Ϸ�����ȥ����Ȼ����һ�źܹžɵ����ף���͵͵�ذ����ص��˻��\n";
	}
	return "��������Ϸ�����ȥ��û����ʲô���õĶ�����\n";
}

