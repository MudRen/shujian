// btyao.c

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_eat", "yan");
	add_action("do_eat", "tun");
}

void create()
{
        set_name(HIG "��̥�׽���" NOR, ({"baotaiyijinwan","wan","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
                "һ�����������ҩ�����ƶ��ɵ�ҩ�裬��˵����֮�˳��˿��Թ��������������
		 ��Ҳδ�����档\n");
		set("unit", "��");
		set("no_sell",1);
		set("medicine", "drug");
		//set("no_get", 1);
//                set("no_drop", 1);
	}
}

int do_eat(string arg)
{
	object me = this_player();

	if (!living(me)) return notify_fail("�뵱����\n");
	if (!id(arg)) return 0;
	if(!me->query("quest_kill/btyao"))
	{
            message_vision(HIG "$N����һ��"
	    +this_object()->query("name")+
	    HIG "����ʱ����ȫ���ȣ�һ������ֱ��ͷ���������嶥������\n"
	    NOR,me);
	    me->add("max_jingli", 20);
	    me->add("eff_jingli", 20);
    	    me->add("max_neili", 20);
	    me->set("quest_kill/btyao",1);
	    //me->set("quest_kill/jieyao",1);
	    me->update_age();
	    me->set("quest_kill/bt_year",me->query("age"));
	    me->set("quest_kill/bt_month",me->query("month"));	    
	    //write_file("/u/emnil/btyao",me->query("id"),0);
	}
        else
        {
	    message_vision(HIG "$N����һ��"
	    +this_object()->query("name")+
	    HIG "����ʱ���ø�ʹ��ʣ�����ס�ҽ�һ�����赹�ڵء�\n"
	    NOR,me); 
	    me->add("eff_jingli", -me->query("eff_jingli")/10);
	    if(me->query("max_neili")>=2)
		me->add("max_neili",-2);
	    me->set("jingli",0);
	    me->set("neili",0);
	    me->receive_wound("qi", me->query("eff_qi")/2);
	    me->receive_wound("jing", me->query("eff_jing")/2);
	    me->unconcious(); 
	}
	destruct(this_object());
	return 1;
}
