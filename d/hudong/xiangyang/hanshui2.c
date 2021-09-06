// Room: /d/xiangyang/hanshui2.c

#include <ansi.h>

#define	SHIP_TO	__DIR__"hanshui1"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();

void create()
{
	set("short", "��ˮ����");
	set("long", @LONG
��ˮ����Ҳ���൱���֣��������ɿ�������һ����ֱ����·ֱͨ�䵱ɽ��
�˵���紾�ӣ�·�Լ��������������������Ҷ���һ����ġ��ơ���ӭ��Ʈ
�εΪ׳�ۡ�Ҳ�в���С����·��������ѱ棬ȴҲ����ʢ����ȴ��
LONG
	);

	set("exits", ([
		"west" : "/d/wudang/wdroad6",
	]));

	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
	]));

	set("outdoors", "����");
	setup();
}

/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */
void init()
{
	add_action("do_yell", "yell");
	add_action("du_jiang", "dujiang");
}

void check_trigger()
{
	object room;
	object thisroom = this_object();

	if(!query("exits/enter") ) {
		if( !(room = find_object(__DIR__"duchuan")) )
			room = load_object(__DIR__"duchuan");
		if( room = find_object(__DIR__"duchuan") ) {
			if((int)room->query("yell_trigger")==0 ) {
				room->set("yell_trigger", 1);
				set("exits/enter", __DIR__"duchuan");
				room->set("exits/out", __FILE__);
				message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n", thisroom);
				message("vision", "������һ��̤�Ű���ϵ̰����γ�һ�����ϵĽ��ݡ�\n", room);
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "ֻ���ý�������������������������æ���š�����\n", thisroom);
		}
		else
			message("vision", "ERROR: boat not found\n", thisroom);
	}
	else
		message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n", thisroom);
}

void on_board()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n",	this_object());

	if( room = find_object(__DIR__"duchuan") )
	{
		room->delete("exits/out");
		message("vision", "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������ʻȥ��\n", room);
	}
	delete("exits/enter");

	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;

	if( room = find_object(__DIR__"duchuan") )
	{
		room->set("exits/out", SHIP_TO);
		message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n", room);
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room, *ob;
	int i;

	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");

		tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
		ob = all_inventory(room);
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
				else tell_room(room, "$N���������Ļ����ԹԵ����˴���\n", ({ob[i]}));
				ob[i]->move(SHIP_TO);
				if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
				else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
			}
		}
		message("vision", "������̤�Ű����������ѱ���ʻ���ġ�\n", room);
		room->delete("yell_trigger");
	}
}

int do_yell(string arg)
{
	object me = this_player();

	if (!arg) return 0;

	if (arg == "boat") arg = "����";
	if (arg != "����") arg = "��";
	if (me->query("age") < 16  )
		message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
	else if (me->query("neili") > 500)
		message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
	else
		message_vision("$N������������Хһ������" + arg + "����\n", me);
	if (arg == "����")
	{
		check_trigger();
		return 1;
	}
	else {
		message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
		message_vision("��Ȼ��շ���һ�ţ���$N����һ����ͷ��һ���������ȵ������˴���ֹ��������\n", me);
	}
	return 1;
}

int du_jiang()
{
	object me = this_player();

	if (!living(me)) return 0;
	if (me->query_skill("dodge") < 80)
		return notify_fail("�����Ϊ������\n");
        if (me->is_busy()|| me->is_fighting())
                return notify_fail("����æ���ء�\n");
	tell_room(environment(me), HIG + me->name() + "����һ��«έ����ˮ�У������ŷ���Ծ��«έ������ƮƮ���ɹ��˺�ˮ��\n" NOR, ({me}));
	write("��ʹ����һέ�ɽ����ɹ��˺�ˮ��\n");
	me->move(SHIP_TO);
	tell_room(environment(me), HIG "ֻ��" + me->name() + "����һ��«έ�Ӷ԰���������̬���������ڰ��ߡ�\n" NOR, ({me}));
	return 1;
}
