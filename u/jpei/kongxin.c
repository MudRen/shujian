//flowray 2005.6.16
// By Spiderii@ty ����Ч��
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (WHT"����ɢ"NOR, ({ "kongxin san","kongxin","san"}));
	set("long","����һ����üɽ�ش���"WHT"����ɢ"NOR"����ν"HIW"������������������ɫ�����ľ������ӹ�������"NOR"
����Է�("HIY"fu"NOR")����������µ����š�\n");

	set("unit","��");
	set_weight(100);
//        set("no_cun",1);
	set("value",3000000);
        set("treasure",1);
        set("degree",25);
	set("flag","spec/kongxin");
	set("desc","��������æ״̬��");
        set("rest",200);
        set("credit",20);
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
	    
        if (arg!="kongxin" && arg!="san" && arg!="kongxin san")
      		return notify_fail("��Ҫ����ʲô?\n");
      	
        if (!restrict()&& !me->query("buyvip") && !me->query("y-card-vip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    
	if (!me->query_condition("job_busy") )
		return notify_fail("�����ڲ���Ҫ���ÿ���ɢ��\n");
	
	me->clear_condition("job_busy");
	
	//�������һЩ�ɽṹ��job busy�Ĵ���
	me->clear_condition("gb_job_busy");
	me->clear_condition("gumu_job");
	me->clear_condition("hs_job");
	me->clear_condition("lh_job");
	me->clear_condition("mrhua_busy");
	me->clear_condition("mr_job");
	me->clear_condition("sljob");
	me->clear_condition("sl_job_busy");
	me->clear_condition("thd_job");
	me->clear_condition("wd_job");
	me->clear_condition("wait_mr_job");
	me->clear_condition("wait_xx_job");
	me->clear_condition("xs_job");
set("no_cun",1);
	
	write("�����һЩ"WHT"����ɢ"NOR"������������,�ѽ�����������һ�ɶ���!\n");
	degree();
	return 1;
}	 
