#include <ansi.h>

inherit SPEC; 

void create()
{
    set_name (HIR"��ֽƬ"NOR, ({ "suizhi pian"}));
    set("long",HIR"����һƬ��Ͱ͵���ֽƬ��ֽƬ�Ѿ����ƣ����������Ȼģ�����塣\n"NOR);

    set("unit","Ƭ");
	set_weight(100);
	set("value",3000000);
	
    set("no_give",1);
    set("no_drop",1);	
    set("no_get",1);
    set("treasure",1);
    set("degree",1);
    set("flag","spec/suizhi");
    set("rest",5);
    set("desc","��˵�������Ž���֮��!");
    set("credit",1200);
	setup();
}

void init()
{
    add_action("do_chakan","chakan");
  
}

int do_chakan(string arg)
{
        mapping fam;
	object me=this_player();
        fam = me->query("family");

        if (arg!="suizhi pian" )
              return notify_fail("��Ҫ�鿴ʲô?\n");
         if ( me->query("combat_exp") < 800000)
              return notify_fail("�㻹��ץ��ʱ��ȥ���ӵ㽭�������ɣ�800Kǰ��û����İ���\n");

        if ( fam["family_name"] != "����" || fam["master_name"] != "���޼�" )

              return notify_fail(HIR"�����˵��ħ�̽��������ܣ��㻹���ٴ���Ϊ�á� \n "NOR,);
      	
        if (!restrict()) 
            { return notify_fail("�������Ѿ�������ʹ��"+this_object()->query("name")+"�ˡ�\n");}   ;
 
        if ( !me->query("jiuyang/wei")  && me->query("kar") <31 && random(me->query("kar")) >= 26 )  
            {             
                me->set("jiuyang/wei", 1);
 write(HIR"ֽƬ���ʲݵ�д�����������У��������С���������Գ�У���Ȼ����ֻ���Գ�� \n"NOR,);
 write(HIR"ֽƬ���ʲݵ�д����ԭ����ˣ�ԭ����ˣ� \n"NOR,);
 write(HIM"������˼�⣺������Ī�Ǿ��ǽ��������������澭�������ǸϽ�ȥ�ҽ����ʸ����ײ��ǡ�\n"NOR,);
 CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + me->name(1) +
                                 "����ֽƬ�з����˾����澭�Ĵ������ܣ�\n"NOR);

                log_file("quest/jiuyang",
                          sprintf("%-18sͨ��ͨ����Ʒ�õ����Ż��ᣬ��%d��\n",
                           me->name(1)+"("+capitalize(getuid(me))+")", 
                           me->query("kar")
                         ), me);
                return 1; 
             }	 

        me->set_temp("sj_credit/quest/mj/jiuyang",1);
         
       write(HIW"�㷴���鿴����"HIR"��ֽƬ"HIW"��ϣ���ܴ�����鵽��ʲô��ͻȻ������ģ�����ֵ�ӳ���������������"HIR"����..."HIW"��!\n"NOR);
        
	degree();
	return 1;

}
