//flowray 2005.6.16
// By Spiderii �ſ�ÿ�ܵ�ʹ�ô�������
#include <ansi.h>


inherit SPEC;

void create()
{
	set_name (HIR"��Ʒ"HIW"����"NOR, ({ "jipinwan","wan","jipin wan" }));
	set("long","����һ��"HIR"��Ʒ"HIW"����"NOR"������Է�(fu)������߾�����������Ϊ��\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/yuji1");
	set("rest",5 );
	set("desc","��ߴ������������������ޡ�");
        set("credit",1000);
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
	    
	if (arg!="jipin wan" && arg!="wan")
		return notify_fail("��Ҫ����ʲô?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
  
    
	me->add("neili", 900 + random(200) );
	me->add("max_neili", 900 + random(200) );
	me->add("jingli", 900 + random(200) );
	me->add("max_jingli", 900 + random(200) );

      me->setup();
	write(HIY"�����һ��"HIR"��Ʒ"HIW"����"HIY",�پ�������������!\n"NOR);
	degree(); 
	return 1;
}	 
