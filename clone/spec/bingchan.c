//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIW"�쾦���"NOR, ({ "bingchan"}));
	set("long",""HIW"һֻ�����������ܣ�ͨ����ѩ��Ө���ף�����ȴѪ
Ҳ��죬ģ�����ǿɰ���ȴҲ�����к�����֮����"NOR"

���������������("HIY"xidu"NOR")��\n");

	set("unit","ֻ");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);	
	set("degree",1);
	set("flag","spec/bingchan");
	set("desc","�ɽ�ٶ���");
        set("credit",200);       
	setup();
}

void init()
{
	add_action("do_xidu","xidu");
  
}

int do_xidu()
{
	object me=this_player();
      	
      		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
	
	if (me->is_busy()) {return notify_fail("����æ���ء�\n");}
			
	if(!mapp(me->query_conditions_by_type("poison")))
		{return notify_fail("�����û���ж��ɡ�\n");}
	
	me->clear_conditions_by_type("poison");
		
	write(HIW"���ȥ������쾦�������ؿڣ�Ƭ��֮�����ת�ɺ�ɫ���������Ҳ������һЩ��\n"NOR);
	degree();
	return 1;
}	 
