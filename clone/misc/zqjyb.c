// By action@sjcb bt物品
#include <ansi.h>
#define BOOK    "/clone/gift/book"      //书
#define MIC     "/clone/gift/danwan"    //药
#define MON     "/clone/gift/money"     //钱
#define JADE    "/d/zhiye/obj/othermaterial" //玉
#define MIJI    "/d/zhiye/obj/othermaterial" //玉
inherit SPEC;
void create()
{
        set_name(HIY"中"HIC"秋"HIM"节"HIR"月"HIW"饼"NOR, ({ "yue bing","yuebing" ,"bing"}) );
        set_weight(10);
                set("unit", "个");
                set("long", "一个神奇的中秋节月饼。\n是传说中天神卡謬(action)买来的，吃了它有可能给你带来巨大惊喜。\n是不是经不起它的诱惑呢，那就快尝（pinchang）它吧。。。\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/yuebing");
                set("desc","据说吃了它就会出现神奇的事情出现。");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_pinchang", "pinchang");
}

int do_pinchang(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(2);

       if(arg!="bing" && arg!="yuebing")
                    return notify_fail("你要吃什么?\n");

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
        message_vision(HIW"$N从月饼的馅中得到了一"+obj->query("unit")+obj->name()+"。\n\n"NOR,me); 
        destruct(this_object());
        return 1;
                
}

