// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"������"NOR);
	set("long", @LONG
������������ͷ�������У�ˮ���䲻���ٲ����ͳ���£�ȴҲ���Ǽ��٣�
�㻮��������٣��ü�����Щ��ˮ��õ�����ȥ��
LONG
	);
	set("outdoors", "��Դ��");
	set("no_fight", 1);
	set("no_save", 1);
	setup();
}

void init()
{
	remove_call_out("check_ppl");
	call_out("check_ppl", 1, this_player(), 300);
	add_action("do_hua", ({ "ban", "hua" }));
	add_action("do_jump", ({ "jump", "tiao" }));
}

void check_ppl(object me, int count)
{
	if ( ! me || environment(me) != this_object()){
		delete("ppl");
		return;
	}
	if ( count -- < 1) {
		message_vision("ͻȻ��һ�ɴ����嵽��$Nδ�������������������֣��ֱ����������ԭ����\n", me);
		me->move(__DIR__"pubu");
		delete("ppl");
		return;
	}
	call_out("check_ppl", 1, me, count);
}

int do_hua(string arg)
{
	object me = this_player();
	object weapon;

	if ( !arg || arg != "boat")
		return notify_fail("��Ҫ��ʲô����\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (!weapon= me->query_temp("weapon"))
		return notify_fail("�����У����ֻ�����\n");

	if ( weapon->query("id") != "tie jiang" )
		return notify_fail("�����У���"+weapon->name()+"������\n");

	if ( me->query_temp("yideng/hua_done"))
		return notify_fail("���Ѿ��������ˣ���취�ϰ��ɣ�\n");

	if ( me->query_temp("yideng/hua"))
		return notify_fail("�����ڻ��أ�\n");

	message_vision(HIW"\n$N����������æ�ӳ�������һ�⣬���۵�ʱ���������ߣ�������������һ�⣬\n"+
		"�������������������ߡ�\n\n"NOR, me);
	me->add_busy(3);
	me->set_temp("yideng/hua", 1);
	call_out("next_place", 10 , me);
	return 1;
}

void next_place(object me)
{
	if (! me || environment(me) != this_object()) return;
	message_vision(HIC"\n����һ�󣬻���������̲��һת�䣬��ǰ��ɫ�续����Ϫ������ˮ��ƽ��֮����\n"+
			"���ƶ�ס��������Ϫˮ��Լ�������Դ�����ˮ������֮���ֲ������������\n"+
			"���ڴ����һ�ʢ��֮ʱ�����һƬ���壬����ҫ�ۡ���ʱ�����һ�����ˮ����\n"+
			"��һ�Դ԰�ɫС�������������\n\n"NOR, me);
	call_out("next_place1", 10 , me);
	return;
}

void next_place1(object me)
{
	if (! me || environment(me) != this_object()) return;
	message_vision(HIC"\nϪˮ�����������Ѽ��ף����ס�������ˣ���������ֱ�´�����֪̽Ϫ�׾�\n"+
			"�ж��ͻȻ��һ�ɴ����嵽����δ�������������������֣�ԭ��Ϫ��ˮƽ��\n"+
			"��������ȴ��һ�������ļ�����\n\n"NOR, me);
	message_vision(HIW"\n�����ۻ�����ǰʻȥ�������Լ�ʱ�з�����������Ȼ������һ��ɽ����\n"NOR, me);
	me->set_temp("yideng/hua_done", 1);
	return;
}

int do_jump(string arg)
{
	object me = this_player();
	object ob = present("tie jiang", me);

	if ( !me->query_temp("yideng/hua_done")) return 0;

	if (! arg || arg != "shandong")
		return notify_fail("������������\n");

	message_vision(HIY"\n$N�������˰����������������ʯ�ϣ��ع�ͷ����ȴ��ˮ����̫����ҫ��ӳ��\n"+
			"һ��ѣĿ�����Ĳʺ硣\n\n"NOR, me);

	if ( objectp(ob))
		destruct(ob);

	me->delete_temp("yideng");
	delete("ppl");
	me->move(__DIR__"shandong");
	return 1;
}
