// Room: /d/xiangyang/hanshui1.c

#include <ansi.h>

#define	SHIP_TO	__DIR__"hanshui2"

inherit ROOM;

void check_trigger();
void on_board();
void on_boat(object me);
void taiping_dian(object me);
void arrive(object me);
void close_passage();

void create()
{
	set("short", "��ˮ����");
	set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)�� �������������۾����������ɴ���
������������һ�����������̯����Ҿͽ������ڰ��ߣ�������������֧һ��
ľ�壬���ϰ����˻�������ĺ������㡣��ȥ��Զ�����������Ϻӿڣ����ٹ�
���Ͷ�������ȴ��ɴ��ڶɡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"outnroad3",
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
	object room, me, *ob;

	if( !query("exits/enter") ) return;

	me = this_object();
	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");

		ob = all_inventory(room);
		if (sizeof(ob) == 1) {
			me = ob[0];
			if (userp(me) && me->query("age") < 16 && me->query("gender") == "����" && me->query("food") < 100 && !me->query("hanshui_food") && !random(5)) {
				tell_room(room, "��Ҫ����ʱ����Ȼһ���ϵ�����ƮƮ��Ծ�����У���Ȼ�������ƺ��ͣ����Ǵ���û��˿����ҡ�Σ�\n", ({}));
				new("/kungfu/class/wudang/zhang")->move(room);
			}
			else
				me = this_object();
		}
		message("vision", "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������ʻȥ��\n", room);
	}
	delete("exits/enter");

	remove_call_out("on_boat");
	call_out("on_boat", 10, me);
}

void on_boat(object me)
{
	object room;

	if (userp(me)) {
		if( room = find_object(__DIR__"duchuan") ) {
			tell_room(room, "\n\n�����ý������˽к������ҽ�����ɵػ�����\n", ({}));
			tell_room(room, "��Ŀ��ʱ��ֻ��ǰ��һ��С���Ĵ���������һ����״󺺣���������һ��С�к���һ��СŮ����\n", ({}));
			tell_room(room, "������ϵ��ɹ���ٺͷ�ɮ�乭���������ǰ��Ĵ󺺡�\n", ({}));
			tell_room(room, "�����������������̽������˹�ȥ��������һ���Һ���С���е��к��������У��ۿ��ǲ�����ˡ�\n", ({}));
			tell_room(room, "��һ����Ҳ�������˼���������ľ������ˮ�С�����󴬸���������������ٺͷ�ɮ������С����\n", ({}));
			tell_room(room, "����������Ծ�𣬰��������С�������¾ͽ�������ٽ���ˣ�ʣ������Ӹ�æ�ӻش󴬣�������ȥ��\n", ({}));
			tell_room(room, "�󺺺�Ů���ϵ��ɴ�������ԭ����λ�������̵ĳ�������Ϊ�˱�����������׷ɱ��\n", ({}));
			tell_room(room, "��Ů�������֮Ů��ԼĪʮ�����ң������׾ɣ�����˫�㣬���������������и����ŵ����֣�������������\n\n\n", ({}));
			remove_call_out("taiping_dian");
			call_out("taiping_dian", 10, me);
			return;
		}
	}
	remove_call_out("arrive");
	call_out("arrive", 10, me);
}

void taiping_dian(object me)
{
	object room;

	if (userp(me)) {
		if( room = find_object(__DIR__"duchuan") ) {
			tell_room(room, "������̫ƽ�꣬����ʱ�㾹Ȼʳ�����ʣ�������ι��Ҳû���ã����������������������ȳԷ��գ�����ι��λС�๫����\n", ({}));
			tell_room(room, "����������Ǽ����޾����ټ�����֭��ϸ�ĵ��ø���ԣ������ʮ�����𣬳Թ���һ���롣\n\n\n", ({}));
			me->set("food", me->max_food_capacity());
			me->set("water", me->max_water_capacity());
			me->set("hanshui_food", 1);
		}
	}
	remove_call_out("arrive");
	call_out("arrive", 10, me);
}

void arrive(object me)
{
	object room, ob;

	if( room = find_object(__DIR__"duchuan") )
	{
		room->set("exits/out", SHIP_TO);
		message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n", room);
		if (userp(me)) {
			tell_room(room, "�������ݱ������ᣬ��Ѱ����ҽ�ɶ�ȥ��������ҲЯ���������ˡ�\n", ({}));
		}
		if (ob = present("zhang sanfeng", room))
			destruct(ob);
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
