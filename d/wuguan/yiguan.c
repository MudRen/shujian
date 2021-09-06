// yiguan.c ���

#include <ansi.h>
inherit ROOM;
mapping *paizi=({
	([  "name":"�������ݳ�",    "id":"Yangzhou",   "value":20   ]),
	([  "name":"�������޺�",    "id":"Xingxiu",    "value":80   ]),
	([  "name":"�ӱ��䵱ɽ",    "id":"Wudang",     "value":50   ]),
	([  "name":"��������ɽ",    "id":"Tiezhang",   "value":50   ]),
	([  "name":"�����һ���",    "id":"Taohuadao",  "value":100  ]),
	([  "name":"��������̲",    "id":"Shenlong",   "value":30   ]),
	([  "name":"������ɽ����",  "id":"Shaolin",    "value":70   ]),
	([  "name":"���Ϲ���Ľ��",  "id":"Murong",     "value":60   ]),
	([  "name":"��������",      "id":"Mingjiao",   "value":100  ]),
	([  "name":"����ɽ��",      "id":"Kunlun",     "value":100  ]),
	([  "name":"������ɽ��",    "id":"Huashan",    "value":40   ]),
	([  "name":"����ɽ��Ĺ",    "id":"Gumu",       "value":30   ]),
	([  "name":"�Ĵ�����ɽ",    "id":"Emei",       "value":40   ]),
	([  "name":"ѩɽ������",    "id":"Dalunsi",    "value":100  ]),
	([  "name":"���ϴ����",    "id":"Dali",       "value":50   ]),
//	([  "name":"����ɽȫ���",   "id":"Quanzhen",	  "value":30   ]),
});

string look_paizi();
int do_go(string);

void create()
{
	set("short",HIC"���"NOR);
	set("long", @LONG
������ݵ���ݣ�����ܴ���ɢ��һ��������˼��ӵ���ζ����Χͣ��
�ü����󳵣������ͣ��˻���š�һλ�ϳ���ר�Ŵ���ݸճ��ŵĵ���ȥ��
���������ɣ���һ�����߹��������ҵ���������Ц����æӭ��ǰȥ����ݵ���
���и�ľ���������Ϲ���һ�����ӣ�paizi����
LONG
	);
	set("exits",([
		"east" : __DIR__"menlang",
		"south" : "/d/xiangyang/cross2",
	]));

	set("item_desc",([
		"paizi" : (: look_paizi :)
	]));

	set("objects", ([
		__DIR__"npc/chefu" : 1,
	]));

	setup();
}

void init()
{
	 add_action("do_go", "qu");
}

string look_paizi()
{
	string str=HIW"\n��Ŀ��\n"NOR;
	int i=sizeof(paizi);

	while (i--) {
		str += chinese_number(15-i)+"��";
		str += "ȥ"+paizi[i]["name"];
		str += "("HIW + paizi[i]["id"] + NOR")";
		str += " ��"+MONEY_D->price_str(paizi[i]["value"]) + "\n";
	}
	return str;
}

void do_move(object ob, int i)
{
	message_vision(YEL"\n$N��Ǯ�����˳��򣬳�����$N����һ���󳵡�\n\n"NOR,ob);
	ob->move(__DIR__"che");
//      ob->move(paizi[i]["file"]);
}

int do_go(string arg)
{
	object ob=this_player();
	int i=sizeof(paizi);

	if (!arg) return notify_fail("��Ҫȥ���\n");
	arg = capitalize(arg);
	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("����æ���أ�\n");
	while(i--) {
		if (arg == paizi[i]["id"]) {
			switch (MONEY_D->player_pay(ob, paizi[i]["value"])) {
				case 0:
					return notify_fail("��⵰��ûǮ�ͱ�˳��ˣ������߾͵������ˣ�\n");
				case 2:
					return notify_fail("����Ǯ��û��Ǯ�Ļ�ֻ�������ߣ������ܵ�������\n");
			}
			message_vision(HIG"$N�ڳ����������˵����ȥ֮�ء�\n"NOR, ob);
			ob->start_busy(2);
			ob->set_temp("place", arg);
			call_out("do_move", 3, ob, i);
			return 1;
		}
	}
	return notify_fail("��Ҫȥ���\n");
}

int valid_leave(object me,string dir)
{
	if( dir == "east")
		return notify_fail("���Ѿ�����ȥ���������ˣ���Ҫ����������ˡ�\n");
	return ::valid_leave(me, dir);
}
