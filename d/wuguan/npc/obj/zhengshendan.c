//zhengshendan
#include <ansi.h>

inherit ITEM;


void create()
{
        set_name(HIY"����"NOR,({"zhengshen dan", "dan" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��˵�ǰ���̫���Ͼ���ʧ���˼�ġ�������ƪ�����ƶ��ɡ�\n");
                set("unit", "��");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("value", 0);                
         }
	setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N����һ��" + name() + "���ٸ���̨����������Ϊ֮һ��\n", me);
	me->set("shen", 100000);
        destruct(this_object());
	return 1;
}

int query_autoload()
{
	return 1;
}



