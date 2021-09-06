// fengche.c ֽ�糵
// By River@SJ 

inherit ITEM;
#include <ansi.h> 

void create()
{
	set_name(HIC"ֽ�糵"NOR, ({ "zhi fengche", "zhi", "fengche" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ò�ֽ�۵��ķ糵,ʮ�־��ɡ�\n");
		set("value", 1000);
		set("material", "paper");
	}
	setup();
}

void init()
{
	add_action("do_blow", "blow");
}

int do_blow(string arg)
{
	object me =this_player();
	string color;
	string *colors=({HIY,MAG,HIW,HIG,HIM,CYN,HIR,WHT});

        if (!id(arg))  return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        color = colors[random(sizeof(colors))];

	switch (random(2)){
		case 0:	message_vision(color+"\n$N����ش����·糵���糵����ת������,�������������Ų�ɫ�Ĺ⡣\n"NOR, me); break;
		case 1: message_vision(color+"\n$N������������ش��ŷ糵,�糵ɳɳ��ת������.....\n"NOR,me); break;
	}
        me->add_busy(1);
	return 1;
}
