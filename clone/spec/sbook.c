//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIC"����֮��"NOR, ({ "sbook"}));
	set("long","����һ��"HIC"����֮��"NOR"��������Ķ�(read)�й���������(str)����(int)����(con)��(dex)�����֪ʶ��\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/sbook");
	set("desc","��ʱ�����һЩ�츳��");
	set("credit",50);	
	setup();
}

void init()
{
	add_action("do_read","read");
  
}

int do_read(string arg)
{
	object me=this_player();
	int i;
	    
	if (!arg)
      		return notify_fail("��Ҫ�Ķ�ʲô֪ʶ?\n");
      		
	if (arg!="str" && arg!="dex" && arg!="int" && arg!="con")
      		return notify_fail("��Ҫ�Ķ�ʲô֪ʶ?\n");
      	
      	if (me->query_temp("sbook")>9)
      		return notify_fail("�㿴�˿��Ȿ�飬�����Ѿ�ûʲô��ѧ����!\n");
      		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}

	i=random(3)+3;
	if (i+query_temp("sbook")>9) i=10-query_temp("sbook");
	
	switch(arg)
	{
		case "int":
			me->add_temp("apply/intelligence",i);
			break;
		case "str":
			me->add_temp("apply/strength",i);
			break;
		case "dex":
			me->add_temp("apply/dexerity",i);
			break;
		case "con":
			me->add_temp("apply/constitution",i);
			break;
	}
	me->add_temp("sbook",i);
	write(HIY"�����"HIC"����֮��"HIY"�����Լ�������������һ�㡣\n"NOR);
	degree();
	return 1;
}	 