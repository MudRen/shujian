//flowray 2005.6.16
// By Spiderii �ſ�ÿ�ܵ�ʹ�ô�������
#include <ansi.h>


inherit SPEC;

void create()
{
	set_name (HIW"����"NOR, ({ "yuji wan","yuji","wan"}));
	set("long","����һ��"HIW"����"NOR"������Է�(fu)������߾�����������Ϊ��\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/yuji");
        set("rest",5);
	set("desc","���һ�ٵ�������һ�ٵ㾫�������ޡ�");
         set("credit",100);                  
	setup();
}

void init()
{
	add_action("do_eat","eat");
	add_action("do_eat","fu");    
}

int do_eat(string arg)
{
	object me=this_player();
	
	if (!arg)
		return notify_fail("��Ҫ����ʲô?\n");
	    
	if (arg!="yuji" && arg!="wan")
		return notify_fail("��Ҫ����ʲô?\n");
      	
      if (!restrict()&& !me->query("buyvip") ) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
//    if (!restrict() ) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    
	me->add("neili", 100);
	me->add("max_neili", 100);
	me->add("jingli", 100);
	me->add("max_jingli", 100);


   me->reincarnate();
me->setup();
 
        write(HIY"�����һ��"HIW"����"HIY"�پ�������������!\n"NOR);
        degree(); 
	return 1;
}	 
