
inherit ITEM;
#include <ansi.h>
string do_look();

void create()
{
	set_name("����", ({ "cai pu", "pu", "hong's menu" }));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", (: do_look:));
		set("value", 100);
		set("no_get", 1);
		set("no_give", 1);
		set("no_steal", 1);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	add_action("do_make", ({"make", "zuo"}));
}

int do_make(string arg)
{
	object me, ob, meat1, meat2, meat3, meat4, meat5;
	int i ;	

	me = this_player();
	meat1 = present("yanggao zuotun", me);
	meat2 = present("xiaozhu erduo", me);
	meat3 = present("xiaoniu yaozi", me);
	meat4 = present("zhangtui rou", me);
	meat5 = present("tu rou", me);

	if ( ! arg || arg != "cai")
		return 0;

	if ( ! me->query_temp("potjob/job", 1))
		return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");

	if ( ! meat1 || ! meat2 || !meat3 || !meat4 || !meat5)
		return notify_fail("����ȱ��һЩԭ�ϰ���\n");

	if ( meat1->query_temp("job_id") != me )
		return notify_fail("���������κ����Ǻ��߹�Ҫ���ҵ�����ԭ�ϰɣ�\n");

	if ( meat2->query_temp("job_id") != me )
		return notify_fail("���С���������Ǻ��߹�Ҫ���ҵ�����ԭ�ϰɣ�\n");

	if ( meat3->query_temp("job_id") != me )
		return notify_fail("���Сţ���Ӻ����Ǻ��߹�Ҫ���ҵ�����ԭ�ϰɣ�\n");

	if ( meat4->query_temp("job_id") != me )
		return notify_fail("������������Ǻ��߹�Ҫ���ҵ�����ԭ�ϰɣ�\n");

	if ( meat5->query_temp("job_id") != me )
		return notify_fail("�����������Ǻ��߹�Ҫ���ҵ�����ԭ�ϰɣ�\n");

	destruct(meat1);
	destruct(meat2);
	destruct(meat3);
	destruct(meat4);
	destruct(meat5);

	i = me->query_temp("potjob/do_time") +1;
	i *= 3;

	if ( random(i)){
		ob = new(__DIR__"pot_food");
		ob->set_name("���˭������÷", ({"yudi luomei", "luomei", "food"}));
		ob->set("long", "����һ�̡����˭������÷������Ʈ���磬������ζ������\n");
		ob->set("unit", "��");
		ob->setup();
		ob->move(me);
		me->set_temp("potjob/finish", 1);
		message_vision(HIY"$N��ԭ�Ϸ���һ��һ���������һ�������ζ�ġ����˭������÷����\n"NOR, me);
	}
	else {
		me->delete_temp("potjob");
		message_vision(HIY"$Nһʱ���񣬷Ŵ������ϣ��˷����Ƴɡ����˭������÷���Ĵ�û��ᡣ\n"NOR, me);
	}
	return 1;
}

string do_look()
{
	object me = this_player();
	mapping place, be_get;
	int i, j;
	string msg;

	if ( me->query_temp("potjob/job")) {
		if ( me->query_temp("potjob/finish"))
			return "���Ѿ�˳������ˡ����˭������÷��������\n";

		place = me->query_temp("potjob/pot_job_place");
		i = sizeof(keys(place));
		if ( i > 0) {
			msg = "�㻹������ԭ����δ�ҵ���\n\n";
			for( j =0; j < i; j ++){
				msg += sprintf("%-8s  %-20s  %-8s\n", keys(place)[j], values(place)[j], 
				me->query_temp("potjob/for_menu/"+keys(place)[j]));
			}
			msg += "\n���Ѿ��ҵ���ԭ���У�";
			be_get = me->query_temp("potjob/be_get");
			if ( be_get )
				i = sizeof(keys(be_get));
			else 
				i = 0;
			if ( i > 0 ){
				for (j = 0; j < i; j ++){
					msg += sprintf("%s ", keys(be_get)[j]);
				}
			}
			else
				msg += "��";
			msg += "\n";
			return msg;
		}
		return "���Ѿ�������ԭ�ϣ��Ͽ��������˭������÷��(zuo cai)�ɡ�\n";
	}
	return "һ�����ף������ǽ��������⿡����˭������÷�����顣\n";
}
