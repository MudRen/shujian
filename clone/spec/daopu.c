// daopu.c �ƾɵ��� For ѩɽ�ɺ�֮���ҵ��� quest by lsxk@hsbbs /2007/7/20
#include <ansi.h>

inherit SPEC; 

void create()
{
    set_name (HIB"�ƾɵ���"NOR, ({"pojiudaopu"}));
    set("long",HIC"�⾹Ȼ��һ����¼�˺��ҵ����ĵ���,�⵶���Ѿ��ǳ��ƾɣ����������Ѿ����ѱ��ϡ�\n"NOR);

    set("unit","��");
	set_weight(100);
	set("value",3000000);
	
    set("no_give",1);
    set("no_drop",1);	
    set("no_get",1);
    set("treasure",1);
    set("degree",1);
    set("flag","spec/daopu");
    set("rest",3);
    set("desc","��˵��¼���������������ĺ��ҵ���!");
    set("credit",200);
	setup();
}

void init()
{
    add_action("do_bianren","bianren");
  
}

int do_bianren(string arg)
{
	object me=this_player();
	
	    
    if (arg!="pojiu daopu")
                    return notify_fail("��Ҫ����ʲô?\n");
      	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
    me->set_temp("sj_credit/quest/public/hjdf",1);
    write(HIW"���뼫��ȥ���ϵ����е����ԣ����ǵ���ʵ��̫���ˣ��㻹���޷�ѧ���κζ���!\n"+
          "��������ã������������΢ָ����һ�£�����������������ž�����\n"NOR);
	degree();
	return 1;
}	 
