// Room: yanbi.c �ұ�

inherit ROOM;

void create()
{
	set("short", "�ұ�");
	set("long", @LONG
������ӽ����������ұ��ϣ�˿�������뿪��֣����еĺ��粻��
��Ϯ�������㲻�����˸����¡�
LONG);
/*
        set("objects", ([ 
	    __DIR__"obj/shizi" : 1,
        ]));
*/
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	add_action("do_down","pa");
	add_action("do_down","climb");
}

int do_down(string arg)
{
	object me = this_player();
	
	if (!present("song sheng",me))
		return 0;
	if (!arg && arg != "down")
		return notify_fail("��Ҫ����������\n");
	message_vision("$N˳�����Ӽ���������ȥ��\n",me);
    me->move(__DIR__"gudi");
	return 1;
}
