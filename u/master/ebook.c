//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
        set_name (HIR"��Ӣ֮��(�����)"NOR, ({ "ebook","book"}));
        set("long","����һ��"HIR"��Ӣ֮��(�����)"NOR"���Ķ�("HIY"read"NOR")����������Ӣһ���ɳ�(1:10��)��\n");

	set("unit","��");
	set_weight(100);
	set("value",3000);
set("no_cun",1);
	set("degree",1);
        set("flag","spec/ebook_lim");
    set("rest",1);
    set("desc","һ��ʱ���ھ���ӳɡ�");
    set("credit",200);
	setup();
}

void init()
{
	add_action("do_read","read");
  
}

int do_read(string arg)
{
	object me=this_player();
	    
	if (!arg)
      		return notify_fail("��Ҫ��ʲô?\n");
      		
	if (arg!="book")
      		return notify_fail("��Ҫ��ʲô?\n");
      	
      		
      	if (!restrict()) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}   

	
	if(!mapp(me->query_conditions_by_type("db_exp")))
                me->apply_condition("db_exp", 14400);
	else
                me->add_condition("db_exp", 14400);
/*
me->add_temp("apply/attack",100);
me->add_temp("apply/damage",100);
me->add_temp("apply/defense",100);
*/
	write(HIY"��ϸϸ�Ķ�"HIC"��Ӣ֮��"HIY"��������,��ʲô�����°빦����\n"NOR);

	degree();
	return 1;
}	 
