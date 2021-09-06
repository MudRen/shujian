// Room: /d/tianshan/bctang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
���������չ���ҩ�������аڷ��Ÿ��ֲ�ͬ����ҩ���þߺ�һЩ�Ѿ����
�˵�ҩ��
LONG);
	set("exits", ([
		"south" : __DIR__"zoulang3",
        ]));
	set("objects", ([
		__DIR__"npc/f-dizi" : 1,
	]));  

	setup();
}

void init()
{
	add_action("do_move", "search");
}

int do_move(string arg)
{
	object me = this_player();
	object ob;
	
	if (!arg || arg != "yaofang") 
		return 0;
	
	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_temp("ljg/book"))
		return notify_fail("�����˰��죬��������ʲôҲû�С�\n");

	if (random(me->query("kar")) > 20) {
		ob = unew(MEDICINE_D("m-book10"));
		if(!clonep(ob)) return notify_fail("�����˰��죬��������ʲôҲû�С�\n");
		if(clonep(ob) && ob->violate_unique()){
			destruct(ob);
			return notify_fail("�����˰��죬��������ʲôҲû�С�\n");
		}
		message_vision("$N������ҩ���Ľ��������һ����ɫ������顣\n", me);
		ob->move(me);
		me->set_temp("ljg/book", 1);
		return 1;
	}
	me->set_temp("ljg/book", 1);
	return notify_fail("�����˰��죬��������ʲôҲû�С�\n");
}
