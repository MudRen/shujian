//Room: lgfang.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"������"NOR);
	set("long", @LONG
����һ���û��������ɵ�ʯ�ݡ�����һ����¯��ȼ��ľ̿��������������
��һ�춫������������������Сͯ��һ����ʹ���������ŷ��䣬��һ��������
����������֮�����ɳɳ֮����������������ɳ���������е��ӱ�Ŀ��ϥ��
�ڹ�ǰ����������ϵ��������ţ����ָ�����п�����
LONG
	);
	set("exits", ([
		"east" : __DIR__"guangchang",
	]));
	set("item_desc", ([
		"huo" : "����һ�ھ޴������������ʢ����ɳ������ȼ��̿���ǰ����������õġ�\n",
	]));
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}

int do_chazhi(string arg)
{
	object me = this_player();

	if (!living(me)) return 0;
	if (!living(this_player()) || arg != "huo" ){
		write("�������Ķ���?\n");
		return 1;
	}
	if (me->query("family/family_name") != "���ư�")
		return notify_fail("��Ǳ�����ӣ������ڴ�������\n");
	if ((int)me->query_skill("strike", 1) < 30) {
		write("�㽫˫�ֲ������У���Ȼ�����ܲ�������ɳ���¶ȡ�\n");
		write("�����һ������ֱ�������������ѵ���\n");
		me->unconcious();
		return 1;
	}
	if ((int)me->query_skill("strike", 1) > 120)
		return notify_fail("�㽫˫�ֲ������У�������ɳ���¶ȶ�����˵̫�ͣ��Ѻ��������ˡ�\n");
	if ((int)me->query("qi") < 40){
		me->receive_damage("qi",10);
		write("�����һ������ֱ�������������ѵ���\n");
		me->unconcious();
          	return 1;
	}
	me->receive_damage("qi", 20+ random(20));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N��˫�ַ���������е���ɳ�\n", me);
	if (random(2)) write("���ȵ���ɳ�����˫���̵�ͨ�죬�����˫�ֱ��ǿ׳������\n");
	return 1;
}
