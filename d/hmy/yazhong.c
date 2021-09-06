// /d/hmy/ryping.c
#include <ansi.h>

#define	SHIP_DOWN 	__DIR__"ryping"
#define	SHIP_UP		__DIR__"yading"

inherit ROOM;

void create()
{
	set("short", "����ƽ��");
	set("long", @LONG
����������������ɽ���滨�������������������춷�̡����̲�ʯ����
������ɽ�µ��в�һ��ƽ�أ����¶����в��پ��룬��ľ��ʵ��̫�ߣ���
�仹��һ�����̣��������߻�Ҫ����һ����¨(lou)��
LONG
	);
	set("item_desc",([
		"lou" : "һ���޴����¨�����(yell)һ�������Թ�������(shangya)������(xiaya)��\n",
	]));
	set("outdoors", "��ľ��");
	setup();
}

void init()
{
    add_action("do_yell", "yell");
}

// up
void check_trigger()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/up") ) {
		if( !(room = find_object(__DIR__"zhulou1")) )
			room = load_object(__DIR__"zhulou1");
		if( room = find_object(__DIR__"zhulou1") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/up", __DIR__"zhulou1");
				room->set("exits/out", __FILE__);
				message("vision", "һ������¨�����ؽ���������ͣ�������ǰ��\n", thisroom);
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
		                message("vision", "ֻ����������������������������æ���š�����\n", thisroom);
		}
		else
			message("vision", "ERROR: zhulou not found\n", thisroom);
	}
	else 
		message("vision", "��¨��ͣ�������ǰ, �����Ͽ���ȥ��\n", thisroom);
}


void on_board()
{
    	object room;

    	if( !query("exits/up") ) return;

    	message("vision", "ͭ�����죬�¶��Ľ��̿�ʼת������¨�������ߡ�\n", this_object() );

    	if( room = find_object(__DIR__"zhulou1") ) {
        	room->delete("exits/out");
        	message("vision", "ͭ�����죬�¶��Ľ��̿�ʼת������¨�������ߡ�\n",room);
    	}
    	delete("exits/up");

    	remove_call_out("flying");
    	call_out("flying", 10);
}

void flying()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou1") )
        	message("vision", HIC"\n��ҹ֮�У��Կɼ���һƬƬ���ƴ�ͷ��Ʈ����\n"HIB"\n�ٹ�һ�ᣬ������������¨�ף������ڳ�����һƬ�����ƻ�Ҳ�������ˡ���\n"NOR,room);

    	remove_call_out("arrive");
    	call_out("arrive", 10);
}

void arrive()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou1") ) {
        	room->set("exits/out", SHIP_UP);
        	message("vision", "��¨���˼��£�������ƽ��ͣ��������\n",room);
    	}
    
    	remove_call_out("close_passage");
    	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"zhulou1") ) {
		room->delete("exits/out");

		tell_room(room, "һ�����ڶ���ȵ�����վ�������ʲô�������Ͽ���������\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "���ڰ�$Ņ������¨��\n", ob[i]);
				else tell_room(room, "$N���˽��ڵĻ����ԹԵ�������¨��\n", ({ob[i]}));
				ob[i]->move(SHIP_UP);
				if (!living(ob[i])) tell_room(SHIP_UP, ob[i]->name() + "��̧������¨��\n", ({ob[i]}));
				else tell_room(SHIP_UP, ob[i]->name() + "��������¨��\n", ({ob[i]}));
			}
		}
		message("vision", "��¨���˼��£��ִ�ʯ��ʻ�����¡�\n", room);
		room->delete("yell_trigger"); 
	}
}

// down
void check_trigger1()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/down") ) {
		if( !(room = find_object(__DIR__"zhulou")) )
			room = load_object(__DIR__"zhulou");
		if( room = find_object(__DIR__"zhulou") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/down", __DIR__"zhulou");
				room->set("exits/out", __FILE__);
				message("vision", "һ������¨����������������ͣ�������ǰ��\n", thisroom);
				remove_call_out("on_board1");
				call_out("on_board1", 15);
			}
			else
		                message("vision", "ֻ����������������������������æ���š�����\n", thisroom);
		}
		else
			message("vision", "ERROR: zhulou not found\n", thisroom);
	}
	else 
		message("vision", "��¨��ͣ�������ǰ, �����Ͽ���ȥ��\n", thisroom);
}


void on_board1()
{
    	object room;

    	if( !query("exits/down") ) return;

    	message("vision", "ͭ�����죬���µĽ��̿�ʼת������¨����������ȥ��\n", this_object() );

    	if( room = find_object(__DIR__"zhulou") ) {
        	room->delete("exits/out");
        	message("vision", "ͭ�����죬���µĽ��̿�ʼת������¨����������ȥ��\n",room);
    	}
    	delete("exits/down");

    	remove_call_out("flying1");
    	call_out("flying1", 5);
}

void flying1()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou") )
        	message("vision", MAG"\n��¨�����½�����ͷ������ͷ��������ǣ���ĸ���ңԶ��\n"NOR,room);

    	remove_call_out("arrive1");
    	call_out("arrive1", 5);
}

void arrive1()
{
    	object room;
    
    	if( room = find_object(__DIR__"zhulou") ) {
        	room->set("exits/out", SHIP_DOWN);
        	message("vision", "��¨���˼��£����µ�����ƺͣ��������\n",room);
    	}
    
    	remove_call_out("close_passage1");
    	call_out("close_passage1", 20);
}

void close_passage1()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"zhulou") ) {
		room->delete("exits/out");

		tell_room(room, "һ�����ڶ���ȵ�����վ�������ʲô�������Ͽ���������\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "���ڰ�$Ņ������¨��\n", ob[i]);
				else tell_room(room, "$N���˽��ڵĻ����ԹԵ�������¨��\n", ({ob[i]}));
				ob[i]->move(SHIP_DOWN);
				if (!living(ob[i])) tell_room(SHIP_DOWN, ob[i]->name() + "��̧������¨��\n", ({ob[i]}));
				else tell_room(SHIP_DOWN, ob[i]->name() + "��������¨��\n", ({ob[i]}));
			}
		}
		message("vision", "��¨���˼��£��ִ�ʯ��ʻ�����¡�\n", room);
		room->delete("yell_trigger"); 
	}
}

void reset()
{
	object room;

	::reset();
	if (room = find_object(__DIR__"zhulou1"))
		room->delete("yell_trigger"); 
	if (room = find_object(__DIR__"zhulou"))
		room->delete("yell_trigger"); 
}

int do_yell(string arg)
{
	object me = this_player();

	if (!arg) return 0;

	if (arg == "shangya") arg = "����";
	if (arg == "xiaya") arg = "����";
	if (me->query("age") < 16  )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if (arg == "����")
		check_trigger();
	else if (arg == "����")
		check_trigger1();
	else {
		message_vision("����ԶԶ����һ���������" + arg + "��������\n", me);
		message_vision("��Ȼ��շ���һ�ţ���$N����һ����ͷ��һ��������̽��ںȵ������˴���ֹ��������\n", me);
	}
	return 1;
}
