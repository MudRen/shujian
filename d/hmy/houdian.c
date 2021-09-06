// /d/hmy/houdian.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����޴�����ڵ������λε����򣬵��аڷ�һ�Ŵ��������԰����˸�
ʽ���ӣ�һ����֪�������ǽ�����Ҫ��������ı�ߵĵط���
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"changlang6",
		"west" : __DIR__"changlang5",
	]));

	set("objects", ([ 
		__DIR__"npc/zhou" : 1,
		__DIR__"npc/wu" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_push",({"tui","push"}));
}

void close_passage(object me)
{
	if (!query("exits/east")) return;
	message_vision("ǽ��ͻȻ�����ĺ�£��������ĳ��ڵ�ס�ˡ�\n",me);
	delete("exits/east");
	return;
}

int do_push(string arg)
{
	object me = this_player();
	object ob = this_object();
	object obj1,obj2;

	if (!arg || arg == "")
		return notify_fail("��Ҫ��ʲô��\n");
	if (arg == "wall") {
		if ( me->query("neili") < 1000)
			return notify_fail("���þ�ȫ���뽫ǽ���������ߣ���������������\n");
		if (!query("exits/east")) {
			message_vision("$N�þ�ȫ����ǽ����������ȥ��\n",me);
			obj1 = present("wu baiying",ob);
			obj2 = present("zhou gutong",ob);
			if (objectp(obj1)) {
				message_vision(obj1->name() + "���ְ�$N��ס���е�������ʲô����\n",me);
				return 1;
			}
			if (objectp(obj2)) {
				message_vision(obj2->name() + "���ְ�$N��ס���е�������ʲô����\n",me);
				return 1;
			}
			message_vision("ǽ��ͻȻ�����߻����ƶ���¶����һ���򶫵ĳ��ڡ�\n",me);
			me->add("neili",-500);
			me->start_busy(random(2) + 1);
			set("exits/east", __DIR__"andao1");
			call_out("close_passage", 5 , me);
			return 1;
		}
		else {
			message_vision("$N�þ�ȫ��ȥ��ǽ�ڣ�����ǽ��ȴ��˿������\n",me);
			me->add("neili",-500);
			me->start_busy(random(2) + 1);
			return 1;
		}
	}
	else return notify_fail("ʲô��\n");
}
