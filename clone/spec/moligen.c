//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIC"���������"NOR, ({ "moligen","gen"}));
	set("long","����һ��ӵ�а�����ʷ�����򻨵�"HIW"���������"NOR"����˵���������˱�ĳ�ª����?
����Է��ã�"HIY"fu"NOR"������������ò1-3��\n");
	set("unit","ֻ");
	set_weight(100);
	set("value",3000000);
  set("no_give",1);
  set("no_drop",1);	
  set("no_get",1);
	set("degree",1);
	set("flag","spec/moligen");
	set("desc","����һ��������ò��");
        set("credit",200);
	
	setup();
}

void init()
{
	add_action("do_eat","fu");
  
}

int do_eat(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("��Ҫ����ʲô?\n");
      		
	if (arg!="gen" && arg!="huagen")
      		return notify_fail("��Ҫ����ʲô?\n");
      	
      	if (me->query("per")<2)
      		return notify_fail("�㶼��������ˣ������ȥ����!\n");
      		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}

	me->add("per",-(1+random(2)));
	write(HIW"�����һֻ����������������Ϸ���һ����鴤���Եø������ܡ�\n"NOR);
	degree();
	return 1;
}	 
