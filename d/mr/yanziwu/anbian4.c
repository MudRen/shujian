// /u/beyond/mr/anbian4.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>

#define SHIP_TO "/d/mr/mtl/anbian1"
#define	BOAT	"/d/mr/zhou5"

inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();
void create()
{       set("short",HIW"����"NOR);
        set("long", @long
������˴����Ե�����٢��ɽׯ��һλ������͵��ϴ������ڰ�����Ϣ��
����Ժ���һ��(yell)�����Ҿͻ�ڴ�������
long);
	set("outdoors", "Ľ��");
	set("exits",([
		"east" : __DIR__"shuixie",
	]));
	setup();
}

void init()
{
	add_action("do_yell", "yell");
//	add_action("do_yue", "yue");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
		if( !(room = find_object(BOAT)) )
			room = load_object(BOAT);
		if( room = find_object(BOAT) ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/enter", BOAT);
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
		message("vision", "����һֻС���ϵ�������˵�������������أ������ɡ�\n", this_object() );
}


void on_board()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "������̤�Ű��������������һ�㣬���������ʻȥ��\n", this_object() );

	if( room = find_object(BOAT)){
		room->delete("exits/out");
		message("vision", "������̤�Ű���������˵��һ��������ඡ������һ�㣬���������ʻȥ��\n", room );
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(BOAT)){
		room->set("exits/out", SHIP_TO);
		message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
        int i;

	if( room = find_object(BOAT) ) {
		tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
				else tell_room(room, "$N���������Ļ����ԹԵ����˴����\n", ob[i]);
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
			}
		}
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
	if( room = find_object(BOAT) )
		room->delete("yell_trigger"); 
}
/*
int do_yue(string arg)
{ 
       object me;
       me = this_player(); 

        if(!arg) return notify_fail("��Ҫ��ʲô��\n");
        if(arg != "hu") return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���أ�\n");
        if (me->query_skill("dodge") < 400) 
                return notify_fail("�����Ϊ������\n");
        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ����������֧�֣���\n");
        if (me->query("neili") < 2000)
                return notify_fail("������������ˣ�\n");
        if (me->query("jingli") < 1500)
                return notify_fail("��ľ��������ˣ�\n");
        me->receive_damage("neili", 300);
        me->receive_damage("jingli", 150);
          tell_room(environment(me), HIY+me->name()+"����������������ĭ�����˽�������ʩչ��һέ�ɽ�����������Ծ�����棡\n" NOR, ({me}));
          write("������������������ĭ�����˽�������ʩչ��һέ�ɽ�����������Ծ�����棡\n");
        me->move(__DIR__"testmatou1");
        me->start_busy(3);
        tell_room(environment(me), HIY+me->name()+"����Ӻ�����Ծ���ں��ĵ���«έ��һ�㣬�Ӻ����洮�˹�����\n" NOR, ({me}));
                return 1;
}
*/
