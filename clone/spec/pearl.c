//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIM"��������"NOR, ({ "pearl"}));
	set("long","����һ�Ų��Զ���֮����"HIM"��������"NOR"����˵��������("HIY"pray pearl"NOR")����˴������ˡ�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/pearl");
        set("rest",100);
	set("desc","���Դ������ˡ�");
        set("credit",10);       
	setup();
}

void init()
{
	add_action("do_pray","pray");
  
}

int do_pray(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("��Ҫ��ʲô?\n");
      		
	if (arg!="pearl")
      		return notify_fail("��Ҫ��ʲô?\n");
      	
      	if (me->query("kar")>29)
      		return notify_fail("�������Ѿ��ܺ���!\n");
      		
      	if (!restrict()) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}   


	me->set("kar",30);
	
	write(HIY"���"HIM"��������"HIY"�����������ǰ��ĬĬ�����ϲ���......\n"NOR);
	write(HIW"������Լ��������������ˡ�\n"NOR);
	degree();
	return 1;
}	 
