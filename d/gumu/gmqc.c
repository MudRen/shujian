// Room: /u/xdd/gumu/gmqiecuo.c
// Modify by river 98/08/29
#include <ansi.h>
inherit ROOM;

void delete_qiecuo(object me, object arg);

void create()
{
	set("short",HIR"�д���"NOR);
	set("long", @LONG
���ǹ�Ĺ�ɵ����д��似�ĵط����տ���һ��ʯ�ң�û���κΰ��衣����
�������ٻ�ѣ���Ҳ�ƻ�ͨ����ʯ�������м������˵���ӡ����ʯ���֣��Լ�
�Ǹ����ཻ��Ϊ��
LONG        );

	set("no_fight", 1);

	set("exits", ([
		"north" : __DIR__"gmqt",
	]));

	setup();
}

void init()
{
	add_action("do_qiecuo", "qiecuo");
	add_action("do_qiecuo", "chaizhao");
}

int do_qiecuo(object arg)
{
	object me = this_player();
	object ob;
	mapping fam;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if (!arg)
		return notify_fail("��Ҫ��˭�д����գ�\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˡ�\n");
	if (me->query("combat_exp") > 2000000)
		return notify_fail("ȥ��һЩ��Σ�յ��������\n");
	if (!(ob = present(arg, this_object())))
		return notify_fail("�������ڲ������\n");
	if (me == ob)
		return notify_fail("������˫�ֻ�����\n");
	if (!living(ob))
		return notify_fail("������Ȱ�" + arg->name() + "Ū�ѡ�\n");
	if (!userp(ob))
		return notify_fail("��ֻ�ܺ�����д����գ�\n");
	if (ob->query("combat_exp") < me->query("combat_exp")/4*5 )
		return notify_fail("���˹����������̫Զ���޷�����������\n");
	if (me->query("jing") < 45 || me->query("qi") < 45)
		return notify_fail("��̫���ˣ���������Ϣһ����ɣ�\n");
	if ( me->query("potential") < 1 )
		return notify_fail("���Ǳ�����Ĺ��ˣ���ʱ�޷��д����ա�\n");
	if( ob->query("potential") < 1)
		return notify_fail( ob->name()+"��Ǳ�����Ĺ��ˣ���ʱ�޷��д����ա�\n");
	if (me->query_temp("gumu_qiecuo"))
		return notify_fail("���������ںͱ��˲��У�\n");
	if (me->query("gender") == "����" )
		return notify_fail("����֮�˲��ܴ��д��еõ�������\n"); 
	if (me->query("gender") != ob->query("gender") )
		return notify_fail("ͬ��֮�˲������д��еõ�������\n");

	me->set_temp("gumu_qiecuo", ob->query("id"));

	tell_object(ob,me->name()+"����������ǰ���������д����ա�\n");
	tell_object(me,"�������"+ob->name()+"��ǰ���������д����ա�\n");

	if ( ob->query_temp("gumu_qiecuo") 
	 && ob->query_temp("gumu_qiecuo") != me->query("id"))
		return notify_fail("�Է��ƺ���û��Ҫ�����д����յ���˼��\n");

	if (!ob->query_temp("gumu_qiecuo")) return 1;
	message_vision("$N��$n������ʽ������������\n", me, ob);
	me->start_busy((: delete_qiecuo :));
	ob->start_busy((: delete_qiecuo :));
	call_out("delete_qiecuo", 20 + random(20), me, ob);
	return 1;
}

void delete_qiecuo(object me, object ob)
{
	mapping my;
	int i ,j ;
	if (!me || !ob) return;
	my = me->query_entire_dbase();

	me->delete_temp("gumu_qiecuo");
	ob->delete_temp("gumu_qiecuo");
	message_vision("$N��$n�㹥���أ����α�ã�ת�۱��Ѳ���ʮ����.....\n",me, ob);
	message_vision("$N��$nֻ���ô˷���ϰ���ջ��ķᣬ�������յĸ�������ˣ�\n",me,ob);
	me->add("potential", -1);
	me->receive_damage("jing", 25 + random(20));
	me->receive_damage("qi",  25 + random(20));
	i = 5+random((my["max_pot"]-100)/3) ;
	if ( i > 40 ) i = 20 + random(20);
	me->add("combat_exp", i);
	ob->add("potential", -1);
	ob->receive_damage("jing", 25+random(20));
	ob->receive_damage("qi",  25+random(20));
	j = 5+random((ob->query("max_pot")-100)/3) ;
	if ( j > 40 ) j = 20 + random(20);
	ob->add("combat_exp", j); 
	log_file("job/qiecuo", sprintf("%8s%-10s��%8s%-10s�д裬�ֱ�õ����飺%2d �� %2d ��", 
		me->name(), "("+me->query("id")+")", ob->name(), "("+ob->query("id")+")",
		i , j ), me);
	return;
}
