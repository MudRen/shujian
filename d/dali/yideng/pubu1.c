// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "�ٲ���");
	set("long", @LONG
̧ͷ���ӣ�ֻ����ɽ�崩�Ʋ��죬��֮����ɽ����ָ���ȸ�������ɽʯ��
���ݲ�������Ƭ���ٲ�ǡ��ӿն��������ٲ����ڶ�ȥ��ˮĭ�Ľ���ʹ��
���ò���Ŀѣ�ľ���һ�Խ���������ɽʯ֮�У�����β��ȴ�������һΡ�
LONG
	);
	set("outdoors", "��Դ��");
	set("no_fight", 1);
	set("no_save", 1);
	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_zhua", ({ "zhua", "qin" }));
	remove_call_out("check_ppl");
	call_out("check_ppl", 1, this_player(), 300);
}

void check_ppl(object me, int count)
{
	if ( ! me || environment(me) != this_object()) {
		delete("ppl");
		return;
	}
	if ( me->query("qi") > 500 ) {
		me->add("qi", -500 );
		me->add_busy(1);
		write(HIB"��վ���ٲ��У�ˮ���ļ���ѹ������е���������Щ�����ˡ�\n"NOR);
	}
	else {
		write("��ʵ��֧�Ų���ȥ�ˣ������������ٲ����ߡ�\n");
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "�������ĵ�Ծ���˰��ߡ�\n", ({ me }));
		delete("ppl");
		return;
	}
	if ( count < 1 ){
		write("��ʵ��֧�Ų���ȥ�ˣ������������ٲ����ߡ�\n");
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "�������ĵ�Ծ���˰��ߡ�\n", ({ me }));
		delete("ppl");
		return;
	}
	call_out("check_ppl", 5, me, count-5 );
}

int do_zhua(string arg)
{
	object me = this_player();
	object ob, weapon;

	if ( ! arg || arg != "yu")
		return notify_fail("��Ҫץʲô��\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_str(1) < 30 )
		return notify_fail("��������������������޷�ץס�������ˡ�\n");

	if ( me->query_temp("yideng/yuren_done"))
		return notify_fail("�㲻���Ѿ�ץ����������ô��\n");

	if ( weapon = me->query_temp("weapon"))
		return notify_fail("����"+weapon->name()+"��ץ������ô��\n");

	if ( me->query_temp("yideng/zhua") < 5 || (!random(30) && me->query_temp("yideng/zhua"))){
		message_vision(HIW"$N��������ȥ׽�ǶԽ����ޣ�һ��һ������ס�˽����޵�β����������������\n"+
				"ֻ��Ū���˹��㣬����ʹ������֪�ǽ���������ȫ��ճҺ�������쳣������Ť\n"+
				"����������$N���գ��Ⱥ����ʯ�ס�\n"NOR, me);
		me->add_temp("yideng/zhua", 1);
		me->add_busy(2);
		return 1;
	}
	else {
		message_vision(HIW"\n$N���ֵ����������Ǵ�ʯ��������һ̧��ֻ����ʯ΢΢ҡ����˫�������;٣�\n"+
				"ˮ���촦���Ǿ�ʯ����$P̧��������$P�������٣���ʯһ����ʱһ�к��ƹ�\n"+
				"ȥ���Ǿ�ʯ��ˮ���������л�������$P���ԣ�����¡¡������������Ԩ��ȥ�ˣ�\n"
				"������ɽ�ȼ伤���������������Ȼ���ò�����$N����ץס����Խ����ޡ�\n\n"NOR, me);
		me->delete_temp("yideng/zhua");
		me->set_temp("yideng/yuren_done", 1);
		ob = new(__DIR__"obj/wawa");
		ob->set_temp("owner", me->query("id"));
		ob->move(me);
		return 1;
	}
}

int do_jump(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "anbian")	return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if ( me->query_temp("yideng/yuren_done"))
		message_vision(HIY"\n$N�������Ź��㣬ֻ��һ�����ֱ�������ȥ��������ˮ����������������һ�㣬\n"+
				"���Ӷ�Ȼ����ٲ������������������������Ϻ���һ�ţ�����Ծ�����ϣ�\n\n"NOR,me);
	else
		message_vision(HIY"\n$N��ˮ����������������һ�㣬���Ӷ�Ȼ����ٲ���������������������\n"+
				"���Ϻ���һ�ţ����ѽ���Ծ�����ϣ�\n\n"NOR,me);
	delete("ppl");
	me->move(__DIR__"pubu");
	tell_room(environment(me), me->name() + "����Ծ���˰��ߡ�\n", ({ me }));
	return 1;
}
