// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG
ֻ���˴�ˮ����̫����ҫ��ӳ��һ��ѣĿ�����Ĳʺ磬����������������
�ٰ�����֮�⣬ȴҲ��֪˵��ô���ã�ֻ������ʯ�ϣ�����һƬ���������ޱ�
����˰��Σ������òʺ�󴫳�һ�������ֻ���������Ǹ�"ɽ����"��������
���Ա���ȥ��ֻ��ɽ��һ���ֱ۴�ϸ�ĳ���(teng)���ط���ϡ�
LONG
	);
	set("outdoors", "��Դ��");

	set("exits", ([
		"enter" : __DIR__"shandong",
	]));

	set("item_desc", ([
		"teng": "����ͷ��������ɽ����ϰ����������֮�У���֪�嶥���ж�ߡ�\n",
	]));

	set("objects", ([
		__DIR__"npc/jiaozi" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_pa", "pa");
}

int do_pa(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "teng") return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( !me->query_temp("yideng/jiaozi_pass")){
		if (present("jiao zi", environment(me)))
			return notify_fail("�������ڲ࣬��ס�����·�ߡ�\n");
		else
			return notify_fail("�ⳤ�ٲ�֪ͨ��δ����㲻����Щ��ԥ��\n");
	}

	message_vision(YEL"\n$N˫�����ų��٣��������ϣ�˫�۽�����Ԯ����������Ѹ�ݣ�Ƭ��֮�䣬���\n"+
		"����ʮ���ɣ������������������ڳ�����\n\n"NOR, me);
	me->move(__DIR__"shanding");
	me->delete_temp("yideng");
	return 1;
}
