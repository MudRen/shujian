// /d/dzd/shiwu.c

#include <ansi.h>

inherit __DIR__"dzd_room";

void create()
{
	set("short","ʯ��");
	set("long",@LONG
���Ǵ��ǵ��ϵ�һ����ͨ��С�֣��������Ӷ�����ʯͷ�гɣ��м乩��һ�����
���Ӵ�ɨ��һ����Ⱦ��С���Եð��������ӡ���͡�
LONG
	);
	set("no_fight",1);
	set("objects",([
		__DIR__"npc/shenni" : 1,
	]));
	setup();
}

void init()
{
	object me = this_player();
	
	::init();
	if(userp(me)) {
		me->clear_condition("bingcan_poison");
		me->clear_condition("haitang_poison");
		me->clear_condition("lingfu_poison");
		me->clear_condition("yufeng_poison");
		me->clear_condition("snake_poison");
		me->reincarnate();
		
	}
}
	