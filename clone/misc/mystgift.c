
// By fengyue
// ��������

#include <ansi.h>

#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define MIJI    "/d/zhiye/obj/othermaterial" //��

inherit SPEC;
void create()
{
        set_name(HIR"��"HIG"��"HIR"��"HIG"��"HIR"��"HIG"��"HIR"��"HIG"��"HIR"��"NOR, ({ "gift","box" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "����һ����װ������С���ӣ�����д�š�������֡��ĸ�С�֡� ��˵��(chai)�����Եõ�Ů������׺յ�ף����\n");
                set("value", 0);
                set("material", "xuantie");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/gqlw");
                set("desc","��������������");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_chai", "chai");
}

int do_chai(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(2);
       int j;
       int z;
       if(arg!="gift" && arg!="box")
                    return notify_fail("��Ҫ��ʲô?\n");

       switch(i) {
                        case 0:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;    
                         case 1:         
                                obj = new (JADE);
                               
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;      
                         case 2:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;   
                                break;                                      
                     
                        default:return 1;
                }
        obj->move(this_player());
        message_vision(HIW"$NС������Ĵ�����ó�һ"+obj->query("unit")+obj->name()+"��\n\n"NOR,me); 
 

     if((int)me->query("combat_exp",1)> 30000000){
          j = 15 +random(6);
      }
      else if((int)me->query("combat_exp",1)> 20000000){
          j = 10 + random(6);
      }
      else if((int)me->query("combat_exp",1)> 15000000){
          j = 15 + random(6);
      }
      else{
          j = 5 + random(5);
      }
          z = j - random(4);
      me->add("relife/gift/now",j);
      me->add("relife/gift/total",j);
      me->add("kar",z);
      tell_object(me, HIG"��õ���Ů������׺յ�ף�������"+ HIR + chinese_number(j) + CYN +"�㡸"+HIG+"�츳����"+CYN+"����\n"NOR);
      tell_object(me, HIW"������Ѿ�ת���������ھͿ��Է����츳������\n"NOR);
     tell_object(me, HIW"����㻹û��ת������ô���ͣ����õ����츳�����Ѿ��ۼ���������������У�ת�����ɷ��䡣\n"NOR); 
     tell_object(me, HIM"��õ���Ů������׺յ�ף�����������������"+ HIR + chinese_number(z) + CYN +"�㣡\n"NOR);
      destruct(this_object());
        return 1;
                
}

