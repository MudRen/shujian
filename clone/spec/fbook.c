//flowray 2005.6.20
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIW"�����˲�"NOR, ({ "tianlong","book"}));
	set("long","����һ����������������"HIW"�����˲�"NOR"��������Ķ�("HIY"read"NOR")����\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/tianlong");
	set("rest",7);
	set("desc","��˵����֮��������䡣");
        set("credit",100);       
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
      		return notify_fail("��Ҫ�Ķ�ʲô?\n");
      		
	if (arg!="book")
      		return notify_fail("��Ҫ�Ķ�ʲô?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}


	me->set("pur",10+random(21));
	
	write(HIY"��ϸϸ�����Ȿ"HIW"�����˲�"HIY"����������ÿ����ɫ��ϲŭ����......\n"NOR);
	write(HIW"�㲻֪�����ز�����һЩ��������,�������Ҳ������һЩ΢��ı仯��\n"NOR);
       write(HIW"�㵱ǰ�Ĵ���ֵΪ:"+HIC+(string)me->query("pur")+"\n"NOR);
	degree();
	return 1;
}	 
