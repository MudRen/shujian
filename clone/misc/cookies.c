
// By fengyue
// ����3

#include <ansi.h>

inherit SPEC;
void create()
{
        set_name(HIY"����С���"NOR, ({ "cookie" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "����һ�а�װ����������С�������ϸƷ��(pinchang)���ɡ�\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/gqcookie");
                set("desc","����С���");
                set("credit",150);    
       setup();
}

void init()
{
        add_action("do_chai", "pinchang");
}



int do_chai(string arg)
{        
        object me = this_player();
        int t, ts, exp, total;
        object obj,obn, obm;
        

        if(arg!="cookie"&&arg!="bing")
           return notify_fail("��ҪƷ��ʲô?\n");  
 /*
      if(me->query("wizpot1")) 
         return notify_fail("�����ô�಻�³�����\n"); 
 */              

      message_vision(HIW"$N�����ζ��Ʒ����һ��"+HIY+"����С���"+HIW+" ��\n"NOR,me); 
    

        obj = new("/cmds/leitai/bwdh/obj/danwan");
        obj->set("owner",me->query("id"));
        obj->set("secret_obj",1);
        obj->set("bonus","combat_exp");
        obj->move(me);          
     message_vision(HIC"$N��"+HIY+"����С���"+HIC+"�з���һ��"+obj->name()+"��\n"NOR, me);  

        obn = new("/cmds/leitai/bwdh/obj/danwan");
        obn->set("owner",me->query("id"));
        obn->set("secret_obj",1);
        obn->set("bonus","combat_exp");
        obn->move(me);          

     message_vision(HIC"$N��"+HIY+"����С���"+HIC+"�з���һ��"+obn->name()+"��\n"NOR, me);  

        obm = new("/cmds/leitai/bwdh/obj/danwan");
        obm->set("owner",me->query("id"));
        obm->set("secret_obj",1);
        obm->set("bonus","combat_exp");
        obm->move(me);          

     message_vision(HIC"$N��"+HIY+"����С���"+HIC+"�з���һ��"+obm->name()+"��\n"NOR, me);  


if(me->query("relife/combat_exp"))
{
      t = (int)me->query("relife/time",1);
     ts = (int)me->query("relife/times",1);
    exp = (int)me->query("relife/combat_exp",1);
  total = (int)me->query("relife/gift/total",1);


   if(total>50)  total = (int)me->query("relife/gift/total",1);
   if(total>40 && total< 50 )  total = 45+random(5);
   if(total>30 && total< 40)  total = 35+random(5);
   if(total <30)  total = 25+random(5);
 
 
      me->delete("relife");       
      me->set("relife/time",t); 
      me->set("relife/times",ts);
      me->set("relife/combat_exp",exp);
      me->set("relife/gift/now",total);
      me->set("relife/gift/total",total);
      me->set("wizpot1",1);

if((int)me->query("relife/combat_exp",1)>= 50000000)
      { me->set("relife/exp_ext",25); }
       
       else if((int)me->query("relife/combat_exp",1)>= 40000000)
           {me->set("relife/exp_ext",20);}

            else if((int)me->query("relife/combat_exp",1)>= 30000000)
                {me->set("relife/exp_ext",15);}

                 else{ me->set("relife/exp_ext",10); }
      tell_object(me, HIG"��õ���Ů������׺յ�ף�������ת��exp�⻷ǿ�������ˣ�\n"NOR);
   
      tell_object(me, HIM"��õ���Ů������׺յ�ף�����츳���·���!��������"+ HIR + chinese_number(total) + CYN +"�㡸"+HIM+"�츳����"+CYN+"����\n"NOR);
}
      me->set("kar,30");
      message_vision(HIW"$N����������ˣ� \n"NOR,me); 
      destruct(this_object());
        return 1;
                
}

