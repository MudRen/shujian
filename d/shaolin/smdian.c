// Room: /d/shaolin/smdian.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;
#include <ansi.h>


void init();
void close_gate();
string look_gate();
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"


void create()
{
	set("short", HIY"ɽ�ŵ�"NOR);
	set("long", @LONG
�����������µ�ǰ��ɽ�ŵ������ש�̵أ�������кߡ�������������
��ΰ�������ŭ��ͷ�����ڣ��ϰ�����¶����ִ����ƣ�һ�ıǣ�һ�ſڣ�¶
����Ŀ�����Ϳ�η�����߸���һ��ľ���������������Թ�ɮ��ߵ�ݡ�������
һƬ�㳡��������һ���������ߵ����ɼľ��ͭ����(gate)��
LONG
	);

	set("exits", ([
		"north" : __DIR__"gchang-1",
	]));

	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("objects",([
		__DIR__"npc/zn-seng" : 2,
	]));
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"guangchang")) )
		room = load_object(__DIR__"guangchang");
	if(objectp(room)){
		delete("exits/south");
			message("vision", "ɮ����ǰ�Ѵ��Ź���������\n", this_object());
		room->delete("exits/north");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N��ɮ�����˵�ͷ��\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"guangchang")) )
		room = load_object(__DIR__"guangchang");
	if(objectp(room))
	{
		set("exits/south", __DIR__"guangchang");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n";
}

int valid_leave(object me, string dir)
{
	if (dir == "south") {
		if (me->id("seng bing")) return 0;
		if (me->id("mo tou")) return 0;
	}
   if(dir == "south"&&!me->query_condition("killer") && me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"shaolinzhen"))
  {
   message_vision(HIC"\nͻȻ��׼���뿪�����£�$N�ƺ���Ѫ��Щ��˳�����Ž���һ������\n"NOR,me); 
   message_vision(WHT"һ��ִ��ɮ�Ҵ������˹�������$Nһ���ֵ����������ӷ�ʩ������׺ݣ�������������Ǳ�޷𷨵úá���\n"NOR,me);
   me->move("/d/shaolin/shaolinzhen");
   tell_room(environment(me), HIR"\n����У��ƺ�һ���˵����������㶨��һ����Ȼ��"+ me->name()+ "��\n"NOR, ({ me }));
   log_file("quest/TLBB", sprintf("%s(%s)���ؽ������󡣾��飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
   return notify_fail(HIR"���ɻ���һ�£�ȴ��������Χ��һȦ�ˣ��ƺ������ַ�ħȦ��\n"NOR);
  }
	return ::valid_leave(me, dir);
}
