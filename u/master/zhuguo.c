//fengyue 2009.1.17
#include <ansi.h>


inherit SPEC; 

void create()
{
     set_name (HIR"�������"NOR, ({ "zhuguo"}));
     set("long",HIR"����һö�������羫���������������,��(eat)�����ᷢ����ֵ����顣\n"NOR);

     set("unit","ö");
     set_weight(100);
     set("value",3000000);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("degree",2);
     set("flag","spec/zhuguo");
     set("rest",9);
     set("desc","������Ʒ��");
     set("credit",15000);
     setup(); 

 }
 
void init()
 {
    add_action("do_eat","eat");
   
 }

int do_eat(string arg)
 {
     object me=this_player();
     
         
     if (arg!="zhuguo")
                     return notify_fail("��Ҫ��ʲô?\n");
            
            if (!restrict()) {return notify_fail("�������Ѿ������ٳ�"+this_object()->query("name")+"�ˡ�\n");}   

            me->add("potential",100000);
//            me->add("SJ_Credit",1000);
//            me->add("balance",1000000);
            me->add("combat_exp",100000);
    write(HIY"�����һö"HIR"�������"HIY"�����Լ���ѧ��Ϊ����!\n"NOR);
     degree();
    return 1;
}    
