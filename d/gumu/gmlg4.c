// Room: /u/xdd/gumu/gmlg4.c
// by shang and xdd  97/6
// Modify By River 98/08/30
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"ʯ��"NOR);
	set("long", @LONG
��ʯ�ұ�֮��ǰ׽��ȸ��ʯ�ҳ�����Լ����һ��������������ֻ��ȸ���ڡ�
�ط���������࣬��׽��ȸ��ȻԶΪ���ѡ�ʯ���ܱգ�ǽ����ֻ����յ�����
ʯ�ҵƻ�ͨ����
LONG
	);

	set("exits", ([
		"out" : __DIR__"gmlg1",
		"south" : __DIR__"gmlg5",
	]));

	setup();
}

void init()
{
	add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
	mapping fam;
	object me = this_player();
	int i;

	if (!living(me)) return 0;

	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if ( arg == "maque") {
		if ((int)me->query_skill("dodge",1 ) < 51 )
			return notify_fail("���Ṧ��̫�ͣ�׽��ס��ô����ȸ�ġ�\n");
		if ((int)me->query_skill("dodge", 1) > 100 
		 && (int)me->query_skill("hand", 1) > 100 )
			return notify_fail("�㲻���������˷�ʱ�侫���ˡ�\n");
		if ((int)me->query("jingli") < 30 || me->query("jing") < 30 )
			return notify_fail("��̫����, ����Ϣһ�¡�\n");
		i = me->query_skill("dodge", 1) / 5;
		me->receive_damage("jing", 10 + random(15));
		me->receive_damage("jingli", 10 + random(15));
		if ( random(i) < 3 ) {
			write("�������������۵���ͷ�󺹣���˵׽��������ëҲ������һ����\n");
			if( me->query_skill("hand", 1) <= 101 )
                                me->improve_skill("hand", me->query_int() );
			if( me->query_skill("dodge", 1) <= 101 )
                                me->improve_skill("dodge", me->query_int() );
		}
		else {
			write("���۵���ͷ�󺹣����ץ������ȸ��\n");
			if( me->query_skill("hand", 1) <= 101 )
                                me->improve_skill("hand", me->query_int()* 9/2 );
			if( me->query_skill("dodge", 1) <= 101 )
                                me->improve_skill("dodge", me->query_int()* 9/2 );
		}
		return 1;
	}
	return notify_fail("��Ҫ׽ʲô��\n");       
}
