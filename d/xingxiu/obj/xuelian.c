// medicine: xuelian.c
// Jay 3/18/96

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��ɽѩ��", ({"xue lian", "lian", "lotus"}));
	set_weight(250);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һֻ֧���ں���ĵط�����������ѩ����\n");
                set("value", 100);
		set("treasure", 1);
        }
        setup();
}

int do_eat(string arg)
{
       object me = this_player();

       if (!id(arg))
               return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy()) return notify_fail("����æ���ء�\n");
       message_vision(HIG "$N����һö"
	+this_object()->query("name")+
	HIG "����ʱ����ͷ����ˬ������Ϊ֮һ��\n"
	NOR,me);
       me->set("qi", me->query("max_qi"));
       me->set("jing", me->query("max_jing"));
	me->start_busy(1);
       destruct(this_object());
       return 1;
}

