// fengling.c ���Ƿ���
// By River@SJ 

inherit ITEM;
#include <ansi.h> 

void create()
{
	set_name(MAG"���Ƿ���"NOR, ({ "fengling", "ling" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���ø�ɫ�������ɵķ���,���ʮɫ,��һ��,�����ö��Ķ�����������\n");
		set("value", 1300);
		set("material", "shell");
	}
	setup();
}

void init()
{
	add_action("do_bo", "bo");
}

int do_bo(string arg)
{
	object me =this_player();
	string color;
	string *colors=({HIY,MAG,HIW,HIG,HIM,CYN,HIR,WHT});

        if (!id(arg))  return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	
        color = colors[random(sizeof(colors))];

        message_vision(color+"\n$N����ָ����ظ�Ū�ŷ���,˼��Ҳ�·���������Ʈ��Զ����\n"NOR, me); 
        me->add_busy(1);
	return 1;
}
