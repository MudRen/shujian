//modified by action 2009/2/17
#include <ansi.h>

inherit SPEC; 

void create()
{
	set_name (HIW"�����ֵ��"NOR, ({ "vipcard"}));
	set("long","����һ���齣ר�õ�"HBRED"�����ֵ��"NOR"���������������齣����ҽ��г�ֵ("HIY"credit vip"NOR")��\n");

	set("unit","��");
	set_weight(200);
	set("value",3000000);
  set("no_give",1);
  set("no_drop",1);	
  set("no_get",1);
    set("no_cun",1);
	set("degree",1);
	set("flag","spec/vipcard");
        set("desc","����Ϊ����˺ų�ֵһ���¹��VIP��");
  set("credit",50000);       
	setup();
}

void init()
{
	add_action("do_credit","credit");
  
}

int do_credit(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("��Ҫ��ֵʲô?\n");
      		
	if (arg!="vip")
      		return notify_fail("��Ҫ��ֵʲô?\n");     	      		


	  me->set("registered", 3);    
me->set("vip/vip_time",time());
me->add("vip/vip_time",7*24*3600);
me->set("vip/vip_start_time",time());    
 me->set("use_vipcard",1);    
	write(HIY"\n�㽫"HIW"�����ֵ��"NOR+HIY"���齣�Զ��տ����һˢ\n"NOR);
        write(HIW"\n�齣�Զ�ϵͳΪ����������Ĺ��VIP��������"HIB"time"HIW"�鿴����л�Ķ��齣��֧�֡�\n"NOR);
	degree();
	return 1;
}	 
int query_autoload()
{
return 1;
}
