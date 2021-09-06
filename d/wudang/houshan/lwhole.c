// add wd quest ���� by Lane@SJ 2005.7.11
// Room: lwhole.c
// Update By lsxk@hsbbs ����ͨ��������߽��Գɹ��� 2007/7/18

#include <ansi.h>;

inherit ROOM;

string wall(object me);

void create()
{
	set("short", HIB"ʯ���Ҷ�"NOR);
	set("long", @LONG
����һ��Ȼʯ�������Ǻ����̫������ʱ��ֱ��ȫ�������������ڴ�ס
����������һʯ������߷���һЩʯ�룬�����ʯ��(wall)���ƺ�����С�֣�
����Գ����Ķ�(read)һ�¡�
LONG
	);

	set("exits", ([
		"out" : __DIR__"wanniansong",
	]));    

	set("item_desc", ([
		"wall" : (: wall :)
	]));

	setup();
}

void init()
{
	add_action("do_study", "read");
}

int do_study(string arg)
{
	object me;
	me = this_player();

	if( !living(me) ) return 0;

	if( (int)me->query_skill("literate", 1) < 10 )
		return notify_fail("����Ҳ����ʶ����,����ж������ķ���\n");

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
         
	if( arg == "wall" ) {
		if( me->query_temp("wudang/jianjue") ) {
			message_vision("$N��������ĥ��ʯ���ϵ�С�֡�\n", me);
			tell_object(me, HIW"\t\t�ϵ����ѹ��٣������䵱���˲��࣬�������ģ��ղ������á�����չ��´����ž���\n"+
			"\t��"RED"̫��ȭ"HIW"���͡�"RED"̫����"HIW"�������ܹ������������츣�����������չʵأ������Դ�����ȴ��Ը ...

			"HIY"������Ȼ��������죬�Ծ��ƶ����ᷢ���ˡ�
			"HIG"�޼�����������֮ĸ��������ã���Ϊ������
			"RED"�������У������һ��Բת�ᴮ�����ϲ�����
			"HIC"��֮��������֮����������˫�ޣ��������С�

				\t\t\t"WHT"������\n"NOR);
		write(HIW"�㾲����ϰʯ���ϵ�С�ӣ����ид����ԡ�̫����������ָ�������һ����Ρ�\n"NOR);
		tell_object(me, BMAG"��ϲ�㣬����" + NATURE_D->game_time() + "����ԡ�̫��������⡣\n"NOR);
		me->delete_temp("wudang/jianjue");
		me->set("wudang/jianjue", 1);
		return 1;
		}

		if( (int)me->query("jing") < 30 )
			return notify_fail("��̫���ˣ�����Ъ�����ж��ɣ�\n");
		if( (int)me->query_skill("yinyun-ziqi", 1) >= 41 )
			return notify_fail("�����ʯ����ϰһ�ᣬֻ���������Ѿ������ء�\n");

		message_vision("$N��ʼ�����ĥ��\n", me);
		write("�㾲����ϰʯ���ϵ��ؼ������ڹ��ķ���Щ����\n");
		me->receive_damage("jing", 40);
		me->receive_damage("jingli", 15);
		me->improve_skill("yinyun-ziqi", (int)me->query("int"));
		return 1;
	}
	return notify_fail("ʲô��\n");
}

string wall(object me)
{
	int exp, time;

	if( me->query("family/family_name") != "�䵱��" )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"NOR;

	if( me->query_skill("yinyun-ziqi", 1) < 450 )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"NOR;

	if( me->query_skill("taiji-jian", 1) < 450 )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"NOR;

	if( me->query("wudang/jianjue") )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"+
			"\t\t\tʯ�ڶ����ļ���̫���ھ���ϡ�ɼ� ...\n"NOR;

	time = time() - me->query("wd_jianjue/time");
	if( me->query("wd_jianjue/time") && time < 86400 && !wizardp(me) )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"+
			"\t\t\t������Ѿ����˺ü����ˣ������������ ...\n"NOR;

	exp = me->query("combat_exp") - me->query("wd_jianjue/exp");
	if( me->query("wd_jianjue/exp") && exp < 100000 && !wizardp(me) )
		return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
			"���������飬������ȥ�����������飬������ȥ......\n"+
			"\t\t\t������Ѿ����˺ü����ˣ������������ ...\n"NOR;

	me->set("wd_jianjue/time", time());
	me->set("wd_jianjue/exp", me->query("combat_exp"));
	message_vision(HIY"$N��ϸ�Ĵ�����ʯ�ڣ���ʵ�⼸��ھ��������μ�����.........\n"NOR, me);

   if( ( random(2) && random(me->query_int()) >= 15 && random(me->query("kar")) >= 15 )||
      (me->query_temp("sj_credit/quest/wd/taiji")&&random(me->query_int()) >= 15&&random(me->query("kar")) >= 10)
      // ����ͨ���������ӽ��Լ��� by lsxk@hsbbs 2007/7/18
      ){
           me->delete_temp("sj_credit/quest/wd/taiji");
		message_vision(HIR"$NͻȻ����ʯ�ڶ����ƺ�����С�ӣ�$N�������������ʲô�أ���\n"NOR, me);
		me->set_temp("wudang/jianjue", 1);
	} else {
           me->delete_temp("sj_credit/quest/wd/taiji");
		message_vision(HIW"$N�������ܽ��ʲôҲû���� ...\n"NOR, me);
	}
	me->set("wd_jianjue/time", time());
	me->set("wd_jianjue/exp", me->query("combat_exp"));
	return  HIW" ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��\n"+
		"���������飬������ȥ�����������飬������ȥ......\n"NOR;

}
