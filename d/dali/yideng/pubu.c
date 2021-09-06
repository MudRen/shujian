// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

string look_pubu();

void create()
{
	set("short", "ɽ���ٲ�");
	set("long", @LONG
��ɽ�żţ�ˮ����ɽ�ȼ伤�����죬������ڣ�����ˮ�����󣬴�������
�붥��ֻ��һ�������ƵĴ��ٲ�(pubu)�Ӷ���˫��֮�䱼�ڶ��£��������Ǿ�
�ˡ�����������ȥ���ٲ��Ա���һ����ݡ�ֻ���ٲ�������������һ�ˣ�ͷ��
���ң�����һ��ʯ�ϣ����Դ�����
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"north" : __DIR__"xiaolu2",
		"west" : __DIR__"caowu",
	]));
	set("item_desc", ([
		"pubu" : (: look_pubu :),
	]));
	set("yideng_boat", 1);

	set("objects", ([
		__DIR__"npc/yuren" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
}

string look_pubu()
{
	object room, me = this_player();

	if(!( room = find_object(__DIR__"pubu1")))
		room = load_object(__DIR__"pubu1");

	if ( room->query("ppl"))
		return "���ٲ����ڶ�ȥ��ˮĭ�Ľ���ֻ��"+room->query("ppl")+"����վ��ˮ�ף�һ���ٲ�����ͻ������Ӿ�δҡ�Ρ�\n";

	if ( ! me->query_temp("yideng/yuren") || me->query_temp("yideng/yuren_done"))
		return "ֻ�����ٲ����ڶ�ȥ��ˮĭ�Ľ����㲻�ɿ���Ŀѣ�ľ���\n";

	if ( !me->query_temp("yideng/pubu"))
		me->set_temp("yideng/pubu", 1);

	return "\n��Ŀ��˳���ٲ�����������ͻȻ��ǰ�����˸��ˮ�������ζ���������ȥ��ֻ\n"+
		"��һ�Խ���������ɽʯ֮�У�����β��ȴ�������һΡ�\n\n";
}

int do_jump(string arg)
{
	object room, *ob, me = this_player();
	int i;

	if ( !me->query_temp("yideng/pubu")) return 0;

	if( ! arg || arg != "pubu") return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query("combat_exp", 1) < 100000 ) {
		write("����书̫�����ȥ̫Σ���ˣ�\n");
		return 1;
	}

	if ( me->query_dex(1) < 30 ) {
		write("���������������ȥ̫Σ���ˣ�\n");
		return 1;
	}

	if ( me->query_skill("dodge") < 200) {
		write("����Ṧ����������ȥ̫Σ���ˣ�\n");
		return 1;
	}

	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if (ob[i]->is_character()){
		write("�����ϱ���һ���ˣ������޷����ɵ������ٲ��С�\n");
		return 1;
	}

	if(!( room = find_object(__DIR__"pubu1")))
		room = load_object(__DIR__"pubu1");

	if ( room->query("ppl")){
		write("�ٲ����Ѿ������ˣ�������ȥ̫Σ���ˡ�\n");
		return 1;
	}

	message_vision(HIY"$N����һ�ﲻ����Ҳ�����¿�Ь�࣬ӿ������ٲ������䡣\n"NOR, me);
	room->set("ppl", me->name(1));
	me->move(__DIR__"pubu1");
	message_vision(HIY"$N˫��ʹ������ǧ��׹��������վ��ʯ�ϣ�ǡ����������������������������Ϣ��\n"NOR, me);
	return 1;
}
