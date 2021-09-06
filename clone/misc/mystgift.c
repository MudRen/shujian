
// By fengyue
// 国庆礼物

#include <ansi.h>

#define BOOK    "/clone/gift/book"      //书
#define MIC     "/clone/gift/danwan"    //药
#define MON     "/clone/gift/money"     //钱
#define JADE    "/d/zhiye/obj/othermaterial" //玉
#define MIJI    "/d/zhiye/obj/othermaterial" //玉

inherit SPEC;
void create()
{
        set_name(HIR"★"HIG"国"HIR"★"HIG"庆"HIR"★"HIG"礼"HIR"★"HIG"物"HIR"★"NOR, ({ "gift","box" }) );
        set_weight(10);
                set("unit", "盒");
                set("long", "这是一个包装精美的小盒子，上面写着“国庆快乐”四个小字。 据说拆开(chai)它可以得到女神奥黛雷赫的祝福。\n");
                set("value", 0);
                set("material", "xuantie");
                set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/gqlw");
                set("desc","★国★庆★礼★物★");
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
                    return notify_fail("你要打开什么?\n");

       switch(i) {
                        case 0:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "极品";
                                
                                str += "玉";  
                                break;    
                         case 1:         
                                obj = new (JADE);
                               
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "极品";
                                
                                str += "玉";  
                                break;      
                         case 2:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "极品";
                                
                                str += "玉";  
                                break;   
                                break;                                      
                     
                        default:return 1;
                }
        obj->move(this_player());
        message_vision(HIW"$N小心翼翼的打开礼物，拿出一"+obj->query("unit")+obj->name()+"。\n\n"NOR,me); 
 

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
      tell_object(me, HIG"你得到了女神奥黛雷赫的祝福，获得"+ HIR + chinese_number(j) + CYN +"点「"+HIG+"天赋技能"+CYN+"」！\n"NOR);
      tell_object(me, HIW"如果你已经转生，你现在就可以分配天赋点数。\n"NOR);
     tell_object(me, HIW"如果你还没有转生，那么加油！所得到的天赋点数已经累计在你的人物数据中，转生即可分配。\n"NOR); 
     tell_object(me, HIM"你得到了女神奥黛雷赫的祝福，你的运气增加了"+ HIR + chinese_number(z) + CYN +"点！\n"NOR);
      destruct(this_object());
        return 1;
                
}

