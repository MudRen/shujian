//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HBMAG"ϴ�赤"NOR, ({ "xisui dan","dan","xisui"}));
	set("long","����һ�Ž�����ʿ���������"HBMAG"ϴ�赤"NOR"����˵ʹ��("HIY"use xisui"NOR")�������̥���ǡ�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
        set("no_cun",1);
	set("degree",1);
	set("flag","spec/xishui");
        set("rest",7);
	set("desc","������ѵ����츳һ�Σ��޶����������ɱ��棩��");
        set("credit",2500);       
	setup();
}

void init()
{
	add_action("do_pray","use");
  
}

int do_pray(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("ʲô?\n");
      		
	if (arg!="xisui" && arg!="xisui dan" && arg!="dan")
      		return notify_fail("ʲô?\n");
       if (me->is_busy() || me->is_fighting() ) return notify_fail("����æ���ء�\n");      	

      	if (me->query("can_cgift"))
      		return notify_fail("���ϴη��õ�ϴ�赤��Ч����δ��ȥ�����ǵȵ����ð�!\n");
      		
      	if (!restrict()) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}   


	write(HIY"�����һ��"MAG"ϴ�赤"HIY"����ʱ���ö���Ŀ�������ǿ��......\n"NOR);
	write(HIW"������Լ����츳���������Щ��̫���ʣ�Ӧ��ʹ��cgift������һ�¡�\n"NOR);
         me->set("can_cgift",1);
	degree();
	return 1;
}	 
