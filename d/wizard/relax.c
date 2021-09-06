// Modify by Looklove 2000/8/25
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�һ�Դ");
	set("long",
"��ԵϪ�У���·֮Զ���������һ��֣��а����ٲ�����������������������
��Ӣ�ͷף�������֮����ǰ�У��������֡��־�ˮԴ�����һɽ��ɽ��������
��ɣ��֮������İ��ͨ����Ȯ���š���Ů������Ϥ�����ˣ��Ʒ����أ�����Ȼ
���֡�
    ����Ǵ�˵�е��һ�Դ��һ�������������ĵط���
	ʹ�� "HIY"pay ������"NOR" ����������þ�������
	ȡ�����ͷŵ�ʱ�䣬150�㾭��/ÿ���ӡ�
");
	set("no_update", 1);
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("sleep_room", 1);
	set("valid_startroom", 1);
	setup();
}

void init()
{
	object me = this_player();
	me->set("water",200);
	me->set("food",200);
	if (!wizardp(me)) {
		me->set("startroom", __FILE__[0..<3]);
		add_action("do_action", "");
		if (!me->query_condition("relax"))
			me->apply_condition("relax", 1);
		me->save();
	}
}

int do_action(string arg)
{
	string action = query_verb();
	object me;
	int i, j;

	switch (action) {
		case "look":
		case "quit":
			if (!arg)
				return 0;
			return 1;
		case "pay":
			if (!arg || !sscanf(arg, "%d", i))
				return 0;
			if (!i) return 0;
			if (i < 0) i = -i;
			me = this_player();
			j = (me->query_condition("relax")-1) / 3;
			if (j < 1)
				return notify_fail("�����Ͼ�Ҫ�ų�ȥ�ˡ�\n");
			if (i > j) i = j;
			if (me->query("combat_exp") < i * 150)
				return notify_fail("��ľ��鲻����\n");
			me->add("combat_exp", -i * 150);
			me->add_condition("relax", -i * 3);
			message_vision("$N��"+chinese_number(i*150)
				+"�㾭�黻ȡ�˴�Լ"+chinese_number(i)+"���ӵ������ͷ�ʱ�䡣\n", me
			);
			return 1;
		default:
			write("����Ļ�����ô�ð�����ЪЪ��˵�ɡ�\n");
			return 1;
	}
}
