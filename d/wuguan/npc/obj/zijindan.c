// zijindan
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"�Ͻ�"NOR,({"zijin dan", "dan" }));
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
	int per,kar,pur;
	per = me->query("per");
	kar = me->query("kar");
	pur = me->query("pur");
	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N����һ��" + name() + "�����������˿����һ���������ˣ���\n", me);
	message_vision("һ������˵����$N����ò��"+per+"��,��Դ��"+kar+"��,������"+pur+"�㡣\n", me);
	me->reincarnate();
	me->set("neili", me->query("max_neili")*2);
        destruct(this_object());
	return 1;
}

int query_autoload()
{
	return 1;
}






