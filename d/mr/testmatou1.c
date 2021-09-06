// /d/mr/testmatou1.c
inherit ROOM;
#include <ansi.h>  
mapping *sign=({
([ 
	"name":"����С��",
	"id":"mr",
	"file":__DIR__"duchuan",
	"value":500
]),
([
	"name":"������",
	"id":"yanziwu",
	"file" :__DIR__"zhou",
	"value":1000
]),
});
string look_sign();
int do_go(string);

void create()
{
	set("short", "��ͷ");
	set("long",@LONG
������Ľ�ݼҵļ��ͺ�Ѿ�߳���̫����ˮ����ͷ��ֻ����������������һ
�����糾���ͣ���ͷ�ߵ��ϴ���������߹���������Ц�Ǻǵ�ӭ����ȥ����ͷ
��������һ�ż۸��(sign)��
LONG 
);
	set("outdoors","Ľ��");
	set("exits",([
		"north" : __DIR__"shiqiao",
	]));
	set("item_desc", ([
		"sign" : (: look_sign :)
	]));

	setup();
}

void init()
{
	add_action("do_go", "qu");
//	add_action("do_yue", "yue");
}

string look_sign()
{
	string str="";
	int i=sizeof(sign);

	while (i--) {
		str += sign[i]["name"];
		str += "(" + sign[i]["id"] + ") ";
		str += MONEY_D->price_str(sign[i]["value"]) + "\n";
	}
	str += "Ľ�ݵ�����ѡ�\n";
	return str;
}

void do_move(object ob, int i)
{
	if (ob->query("family/family_name") == "����Ľ��") {
		message_vision(YEL"\n$N�Ѻʹ��Ҵ������к���������$N����һ��С�ۡ�\n\n"NOR,ob);
	}
	else {
		message_vision(YEL"\n$N��Ǯ�������ң�������$N����һ��С�ۡ�\n\n"NOR,ob); 
	}
	ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(sign);

	if (!arg) return 0;
	if(ob->query_temp("ride_horse"))
		return notify_fail("�Բ�������ֻ������ˣ�\n");
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");
	while(i--) {
		if (arg == sign[i]["id"]) {
			if (ob->query("family/family_name") != "����Ľ��") {
				switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
					case 0: 
						return notify_fail("��⵰��һ�ߴ���ȥ��\n");
					case 2:
						return notify_fail("����Ǯ��\n");
				}
				message_vision("$N�ڿڴ��﷭����ȥ���Ҵ�Ǯ��\n", ob);
			}
			else {
				message_vision("�������´�����$N��\n", ob);
			}
			ob->start_busy(3);
			call_out("do_move", 3, ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}

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
	me->move(__DIR__"anbian4");
	me->start_busy(3);
	tell_room(environment(me), HIY+me->name()+"����Ӻ�����Ծ���ں��ĵ���«έ��һ�㣬�Ӻ����洮�˹�����\n" NOR, ({me}));
	return 1;
}
