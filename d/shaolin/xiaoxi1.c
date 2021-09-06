// Room: /d/shaolin/xiaoxi1.c
// by bren

inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "Ϫ�Կյ�");
	set("long", 
"����Ϫ�Ե�һ��յأ������̲����𣬼���׺��һЩ�в������ӵ�Ұ\n"
"ɽ����Զ������������¶��һƬ��ǽ�����������Ѿ������б�Ե�ش��ˡ�ǰ\n"
"���Ϊ���ĵط�����һ��Ъɽ���ܣ��߶��㣬�������ӵ�¥��¥����һ\n"
"�����ң����顺"HIY"�ؾ���"NOR"�������֡�\n"

	);

	set("exits", ([
		"enter" : __DIR__"cjlou",
	]));

	set("outdoors", "����");
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi") {
		if (me->is_busy() || me->is_fighting()) write("����æ���ء�\n");
		else if (me->query_skill("dodge", 1) >= 60) {
			message("vision", me->name() + "���˿��������������Ծȥ��\n",environment(me), ({me}) );
			write("�����˿��������������Ծȥ��\n");
			me->move(__DIR__"xiaoxi");
			message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",environment(me), ({me}) );
		}
		else {
			message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ��Ϫ�У��Ǳ������˻�����\n", environment(me), ({me}) );
			write("�����������Ծȥ��ֻ������ͨ��һ������ˤ��Ϫ�У��Ǳ������˻�����\n");
                        me->receive_damage("qi",30);
		}
		return 1;
	}
	return 0;
}
