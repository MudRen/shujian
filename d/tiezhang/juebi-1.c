//juebi-1.c ����

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
���ߵ��������ǰ���Ѿ�û��·�ˡ�����ǰ��һ��������ɽ�壬������
�ƣ���������ͷ��ʯ���������źܶ����������紵����ɳɳ���졣�������Ϸ�
����ֻ������ȥ�ˡ�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"shangu-2",
	]));

	set("no_clean_up", 0);
        set("outdoors", "����ɽ");
	setup();
}

void init()
{
	add_action("do_zhua","zhua");
        add_action("do_climb","climb");
}

int do_zhua(string arg)
{
        object me=this_player();
        if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        if (arg =="����"){
		write("�����ε�ץסʯ���ϵ�������\n");
		me->set_temp("marks/ץ1", 1);
		return 1;
	}
        return notify_fail("��Ҫץʲô��\n");
}

int do_climb(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        if ((int)me->query_skill("dodge", 1) < 30)
		return notify_fail("����Ṧ�������޷�����ȥ��\n");
	if (!arg || arg != "up")
		return notify_fail("��Ҫ���Ķ�����\n");
        if (me->query("family/family_name") != "���ư�")
		return notify_fail("��Ǳ�����ӣ������Ϸ壡\n");
        if (me->query_temp("marks/ץ1") && arg =="up" ){
		write("�����˿�����С�ĵ�������ȥ��\n");
		message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"juebi-2");
		me->receive_damage("jingli",50);
		message("vision", me->name() + "����������\n",
		environment(me), ({me}) );
		me->delete_temp("marks/ץ1");
		return 1;
	}
	return notify_fail("�����޴���Ԯ�����޷�����ȥ��\n");
}
