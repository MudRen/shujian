//

#include <ansi.h>


inherit SPEC;

void create()
{
	set_name (HIW"������"NOR, ({ "zhengshen wan","wan"}));
	set("long","����һ��"HIW"������"NOR"������Է�(fu)��������������ֵ��\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
  set("no_give",1);
  set("no_drop",1);	
  set("no_get",1);
	set("degree",1);
	set("flag","spec/addshen");
	set("rest",1);
        set("desc","���2M����");
  set("credit",50);                  
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
	    
	if (arg!="zhengshen wan" && arg!="wan")
		return notify_fail("��Ҫ����ʲô?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    
        me->add("shen", 2000000);

 
        write(HIY"�����һ��"HIW"������"HIY"�پ�ȫ���������Ȼ����\n"NOR);
        degree(); 
	return 1;
}	 
