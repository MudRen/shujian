//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
        set_name (RED"�󻹵�(��)"NOR, ({ "da huandan","dahuan","dan"}));
	set("long","����һ��͸��ͨ��ĵ�ҩ�������˳�"HIR"���󻹵���"NOR"����˵���ż�������������Ч����
����Է��ã�"HIY"fu"NOR"���������ˡ�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
       set("no_get",1);
//       set("no_cun",1);
	set("degree",10);
	set("flag","spec/dahuan");
	set("desc","����ʥҩ���˼�Ʒ��");
set("credit",18);    
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
      		
        if (arg!="dan" && arg!="danhuan" && arg!="dahuan dan")
      		return notify_fail("��Ҫ����ʲô?\n");
      	
      		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
	
	if (me->is_busy()) {return notify_fail("����æ���ء�\n");}
			
	"/adm/daemons/emoted"->do_emote(me,"taste");
	me->reincarnate();
	me->set("neili", me->query("max_neili")*2);
	me->set("jingli", me->query("eff_jingli")*2);
 if( random(2) && me->is_fighting())  me->add_busy(1);
set("no_cun",1);
	write(HIW"�����һ��"RED"�󻹵�"HIW"�����õ��ﴦ��ů��ӿ�ϣ���ʱ����Ȭ����Ѫ��ӯ��\n"NOR);
	degree();
	return 1;
}	 
