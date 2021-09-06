// Room: /d/emei/baoguoshi.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "������" NOR);
	set("long",@LONG
�������Ƕ�üɽ�����Ժ֮һ��������ɽ���죬���յ���۵�߷��
�����ߣ���ģ��󡣵��ڷ������������������������ڷ����Ծ���������
����������һ��������(ta)�������������һ��ų߼��������ң����������
���֡����µ�һ�ɡ�������������Լ����ɴ�����¡�
LONG);
	set("item_desc", ([ 
		"ta" : HIC"    ����һ��ʮ������ͭ�����������������ף��������ѹ���С����ǧ�߰�\n"+
			"��֮�࣬�����С����Ͼ���ȫ��������֣���ұ��������񹤼��ɣ���������\n"+
			"����֮����\n"NOR,
	]));
	set("objects",([
		__DIR__"npc/xiangke" : 2,
	]));

	set("exits", ([ 
		"southwest" : __DIR__"milin",
		"enter" : __DIR__"daxiongdian",
		"west" : __DIR__"baoguosixq",
		"east" : __DIR__"baoguosm",
	]));

	setup();
}

void init()
{
	add_action("do_du", "read");
}

int do_du(string arg)
{
	object me;
	me = this_player();
	
        if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if ((int)me->query("jing") < 30 )
		return notify_fail("��̫���ˣ��޷�����ѧϰ�ˣ�\n");

	if ((int)me->query_skill("dacheng-fofa", 1) < 100 )
		return notify_fail("�����������Ϸ𷨶�����˵̫���ˡ�\n");

	if ((int)me->query_skill("dacheng-fofa", 1) > 120 )
		return notify_fail("���Ѿ����������˻������Ϸ𷨵����塣\n");

	if( !arg || arg != "ta" || arg == "")
		return notify_fail("��Ҫ��ʲô��\n");

	if ((int)me->query_skill("literate", 1) < 100 )
		return notify_fail("�㿴�˻������ϵľ��ģ�ֻ����ͷ�����ǣ���������һ����\n");
	
	if( arg == "ta") {
		me->receive_damage("jing", 20+random(10));
		me->improve_skill("dacheng-fofa", me->query("int"));
		message_vision("$N����ר���ж��������ϵĻ��Ͼ��ġ�\n", me); 	
		return 1;
	}
}
