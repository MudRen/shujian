// jiuxuebiyun-dan

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name(HIY"��ѩ���Ƶ�"NOR, ({"jiuxuebiyun dan","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө��͸�ĵ�ҩ��\n");
                set("value", 10000);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�������������뿪�㡣\n");
                set("no_get", "�����������������\n");
        }

        set("wudu",1);
        setup();
}
int do_fu(string arg)
{
	object me = this_player();

	if (!id(arg))
	return notify_fail("�㺬��ʲô��\n");
 
//	if ( (int)me->query_condition("wudu_jiedu"))
//	{
		 
//        message_vision(HIY "$N��һ�ž�ѩ���Ƶ�������ҧ�麬������پ��������ʣ���ɫ����\n" NOR, me);
//	}
//	else
//	{
		 
	message_vision(HIY "$N��һ�ž�ѩ���Ƶ�������ҧ�麬������پ��������ʣ���ɫ����\n" NOR, me);
//	}

	 
	
	destruct(this_object());
	return 1;
} 
