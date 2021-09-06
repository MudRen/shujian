// Room: /d/shaolin/guangchang1.c
// Date: YZC 96/01/19

#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void init();
int do_open();
string look_gate();
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"

void create()
{
	set("short", "�㳡");
	set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹��������
����Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡��Χ��������
�������֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ������ǰ����ǽ���ߣ�����
���ݣ�����һ�����������������ߵ����ɼľ��ͭ����(gate)���Ϸ�һ���
�ң����ɷ�������š�[1;33m������[0;37;0m���������֡���ǰ����������վ�ż���ɮ�ˡ�
LONG
    );

	set("exits", ([
		"east" : __DIR__"gchange",
		"south" : __DIR__"shifang",
		"west" : __DIR__"gchangw",
	]));

	set("outdoors", "shaolin");
	set("item_desc",([
		"gate"        :    (: look_gate :),
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-fa" : 1,
	]));

	setup();
	"/clone/board/shaolin_b"->foo();
}

void init()
{
	object me;
  me = this_player();
  if(!me->query_condition("killer") && me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"dagouzhen"))
  {
   tell_object(me,HIC"\n�������߳������£�����ɽ�ŵ�㳡��ͻȻ������һ�ֲ����Ԥ�С�\n"NOR); 
   message_vision(WHT"ɽ�´Ҵ�����һ���ˣ���$Nһ���ֵ������ٺ٣�ʩ������׺ݣ�������������Ǳ�޷𷨵úð�����\n"NOR,me);
   me->move("/d/gb/dagouzhen");
   tell_object(me,HIR"���ɻ���һ�£�ȴ��������Χ��һȦ�ˣ��ƺ���ؤ����󷨡�\n"NOR);
   log_file("quest/TLBB", sprintf("%s(%s)���ؽ����󡣾��飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
   return;
  }
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room)) {
	delete("exits/north");
	message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", this_object());
	room->delete("exits/south");
	if (objectp(present("qingfa biqiu", room)))
		message("vision", "�巨������ǰ�Ѵ��Ź���������\n", room);
	else
		message("vision", "׳��ɮ����ǰ�Ѵ��Ź���������\n", room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");

	if(objectp(room)) {
		set("exits/north", __DIR__"smdian");
		message_vision("$N������������ţ�ֻ��֨��һ����һλ׳��ɮ��Ӧ���򿪴��ţ�\n"
				"����������Ŀ���������´�����$N��\n",this_player());
		room->set("exits/south", __FILE__);
		message("vision", "���洫��һ����������׳��ɮ��Ӧ����ǰ�Ѵ��ſ���\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" )
	return ::valid_leave(me, dir);

	if (is_wanted(me))
		return 0;
	if ( me->query("family/family_name") == "������" ) {
		if ( me->query("guilty") == 0
		 && me->query("K_record") == ( me->query("PKS") + me->query("MKS"))) {
			message_vision("׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n", me);
			return 1;
		}
		else {
			if((int)me->query("guilty") == 0) {
				int shen = me->query("shen");
				if((int)me->query("shen_record") > shen)
					me->set("guilty", 1);
				else
					me->set("guilty", 2);
				me->set("K_record", me->query("PKS") + me->query("MKS"));
				if (shen > 0 && shen > me->query("combat_exp")) shen = me->query("combat_exp");
				if (shen < 0 && -shen > me->query("combat_exp")) shen = -me->query("combat_exp");
				if (shen < 0) shen += shen / 9;
				else shen -= shen / 9;
				me->set("shen_record", shen);
			}
			write("׳��ɮ�˳���������˵��������Ժ�������Ŵ�ʦ��ʦ�ֻ���ȥ����Ժ�������й�����\n");
			return 1;
		}
	}
	else if( present("yingxiong ling", me)){
		message_vision("׳��ɮ�˺�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n", me);
		return 1;
	}
	else if (me->query("luohan_winner")) {
		message_vision(HIY "׳��ɮ�˶�$N��ʮΪ�񣬲����ÿ���˵����ԭ���Ǵ����޺���Ĵ�Ӣ�ۼݵ�����������\n" NOR, me);
		return 1;
	}
	if (me->query("shen") >= 0) {
		if (me->query("gender") == "Ů��") {
			return notify_fail("׳��ɮ��˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�\n");
		}
		else {
			return notify_fail("׳��ɮ��˵������λʩ����ذգ����²��Ӵ����ˡ�\n");
		}
	}
	return notify_fail("׳��ɮ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�\n"
			"�����׼����ؿڣ���üŭĿ��˵�������аħ������������ҹ�����\n"
			"�Ժ��ٸ��߽�����һ��������ʱ��ն�����ǵĹ��ȣ�\n");

	if(me->query("no_quest"))
		return notify_fail("\n");
}

string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
