// jianyu.c ����
// Modify By River@SJ 99.06
// Modify by Looklove 2000/8/26

#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIB"����"NOR);
       set("long", @LONG
���������̵ĵ��¼��������涼��ʯ�ڣ�ֻ��һ�����ţ�ֻ��������˴�
�����Ų��ܳ�ȥ����Ҫ�����ӳ�ȥ�ǲ����ܵĵ���ʮ�ֳ�ʪ����������ʱ��һ
�ñص��ز���ʯ�����õ��ӿ���һЩ��ڵĻ���....����Ӧ����͵�Ϲ���������
������Щ��������
LONG);
	set("objects",([
                FOOD_D("zongzi") : 2,
                FOOD_D("zhuhu") : 1,
        ]));
	set("no_update", 1);
        setup();
}

void init()
{
	object me = this_player();

	if( (int)me->query_condition("mj_jail") <= 0
	&& !wizardp(me)){
		message("vision",HIY "ֻ�����ſ��һ�죬һ�����Բ��ѵĵļһﱻ���˽�����\n\n" NOR, environment(me), me);
		me->set("startroom", "/d/mingjiao/jianyu");
		me->apply_condition("mj_jail", 30);
        }
}
