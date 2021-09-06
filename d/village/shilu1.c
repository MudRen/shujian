// Room: /d/village/shilu1.c

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿������������
�Ҳ��࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·�������Ǽ��ʵ����
լ��
LONG
        );
        set("exits", ([
		"west"  : __DIR__"minfang1",
		"north" : __DIR__"shilu2",
		"south" : __DIR__"sexit",
	]));
        set("outdoors", "��ɽ");

	setup();
}

void init()
{
	object me = this_player();
	int times = me->query("random_job");
	if ((int)me->query("combat_exp") >1500000 
	&&  random(me->query("kar")) > 30
	&& (times < 5)
	&&  !(me->query_temp("hs/meetjob"))
	&&  me->query("neili") > 4000
        &&  random(600) == 251
 ) {
		tell_object(me, YEL"������·�����ţ���Ȼ·�Ե���լ�ﴫ�������������ĺ�����\n"+
				"�㲻�ɵ�ͣ�½Ų������߹�ȥ����������\n"NOR);
		me->add_busy(4 + random(4));
		me->set("random_job",times + 1);
		call_out("do_helpme", 4, me);
	}
} 

void do_helpme(object me)
{
	object ob;
	if (!me) return;
	tell_object(me, YEL"ͻȻ������լ����һ���ˣ��㶨��һ����ԭ���Ǹ��¹ڲ������ٸ���\n"NOR);
	tell_object(me, HIC"���ٸ����ŵش������㣬��������������˵��������λ" + RANK_D->query_respect(me) + "�������������и����ˣ�\n"NOR);
	tell_object(me, HIC"����СŮ�ӷ���" + RANK_D->query_respect(me) + "�ܷ����һ���������£����к񱨡�\n"NOR);
	tell_object(me, YEL"���ٸ�˵�꣬��Ҳ�Ƶ�������ȥ��\n"NOR);
	tell_object(me, YEL"��ת������������ȥ���������ٸ���˵�Ĵ��˾������档\n"NOR);
        ob=new(__DIR__"npc/chdd");
        ob->move(__DIR__"minfang1");
	me->set_temp("hs/meetjob", 1);
}
