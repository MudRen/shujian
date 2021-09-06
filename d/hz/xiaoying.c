// /u/beyond/hz/xiaoyingzhou.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
void create()
{
	set("short",CYN"СӮ��"NOR);
	set("long", @LONG
СӮ����ȡ��ѻ��ɵ�С�ޣ�Χ�Ի��е̹������ɡ������е���������
�����ľ��ɫ������Ũ��е���ͤ��ӳˮ����Ҷ��԰���������̣�ʹ����
�����롰��ɫ�����С�
LONG
        );
	set("exits", ([
		"south" : __DIR__"juquqiao",
	]));
	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
	]));

	set("outdoors", "����");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
		if( !(room = find_object(__DIR__"duchuan")) )
			room = load_object(__DIR__"duchuan");
			if( room = find_object(__DIR__"duchuan") ) {
				if((int)room->query("yell_trigger")==0 ) {
					room->set("yell_trigger", 1);
					set("exits/enter", __DIR__"duchuan");
					room->set("exits/out", __FILE__);
					message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n", this_object() );
					message("vision", "������һ��̤�Ű���ϵ̰����γ�һ�����ϵĽ��ݡ�\n", room);
					remove_call_out("on_board");
					call_out("on_board", 15);
				}
				else
					message("vision", "ֻ���ú��治Զ����������������������æ���š�����\n",this_object() );
			}
			else
				message("vision", "ERROR: boat not found\n", this_object() );
		}
		else 
			message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",this_object() );
}


void on_board()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "������̤�Ű��������������һ�㣬���������ʻȥ��\n", this_object() );

	if( room = find_object(__DIR__"duchuan")){
		room->delete("exits/out");
		message("vision", "������̤�Ű���������˵��һ��������ඡ������һ�㣬������\n����ʻȥ��\n", room );
	}
	delete("exits/enter");
	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"duchuan")) {
		room->set("exits/out", __DIR__"hubian2");
		message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");
		message("vision","������̤�Ű����������ѱ���ʻ����С�\n", room);
		room->delete("yell_trigger"); 
	}
}

int do_yell(string arg)
{
	if( !arg || arg=="" ) return 0;

	if( arg=="boat" ) arg = "����";
	if (arg != "����") arg = "��";
	if( (int)this_player()->query("age") < 16 )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", this_player());
	else
		message_vision("$N������������Хһ������" + arg + "����\n", this_player());
	if( arg=="����") {
		check_trigger();
		return 1;
	}
	else
		message_vision("������ԶԶ����һ���������" + arg + "��������\n", this_player());
	return 1;
}

void reset()
{
	object room;

	::reset();
	if( room = find_object(__DIR__"duchuan") )
		room->delete("yell_trigger"); 
}
