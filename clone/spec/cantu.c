// cantu.c ��ҽ�����ͼ For ѩɽ�ɺ�֮��ҽ��� quest by lsxk@hsbbs /2007/7/20
#include <ansi.h>

inherit SPEC; 

void create()
{
    set_name (HIY"��ҽ�����ͼ"NOR, ({"cantu","mjjf cantu"}));
    set("long",YEL"����һ���¼����ҽ����Ĳ�ͼ,ͼ�ϵĽ����Ѿ��൱ģ��,������޷�����ѧ���κ����ö�����\n"NOR);

    set("unit","��");
	set_weight(100);
	set("value",3000000);
	
    set("no_give",1);
    set("no_drop",1);	
    set("no_get",1);
    set("treasure",1);
    set("degree",1);
    set("flag","spec/cantu");
    set("rest",3);
    set("desc","��¼��ҽ��������һ��ͼ��!");
    set("credit",200);
	setup();
}

void init()
{
    add_action("do_fanyue","fanyue");
  
}

int do_fanyue(string arg)
{
	object me=this_player();
	
	    
    if (arg!="mjjf cantu")
                    return notify_fail("��Ҫ����ʲô?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}

    me->set_temp("sj_credit/quest/public/mjjf",1);
    write(HIM"�㷴����������ͼ,���������������΢ָ��һ��,��Ӧ���ܱȽ����ɵ�ѧ����������Ľ���!\n"NOR);
	degree();
	return 1;
}	 
