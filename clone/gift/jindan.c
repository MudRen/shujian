// By action@SJ 
// 2009年过年砸金蛋
#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //玉
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //矿
#define BULIAO    "/d/zhiye/obj/buliao" //布料
inherit SPEC;
void create()
{
        set_name(HIY"金蛋"NOR, ({ "jindan"}) );
        set_weight(10);
                set("unit", "颗");
                set("long", HIY"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR+
                	HIY"※"HBBLU+HIW"牛年新年快来到了，卡谬特地去找李咏要来的金蛋，你是不是在《幸运52中》看到过哦。"NOR+HIY"※\n"NOR+
                	HIY"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR+
                	HIY"※※※"HBRED"过年砸金蛋，开年见喜，祝各位书剑玩家：新春愉快，财源滚滚，牛年行大运。"NOR+HIY"※※※\n"NOR+
                	HIY"※※※※※※※※"HBGRN+HIW"还是去找把木槌去把金蛋砸开吧，去木匠店师傅找找吧！"NOR+HIY"※※※※※※※※\n"NOR+
                	HIY"※※※※※※※※※"HBGRN+HIW"或许他们哪儿有木槌你可以使用(za)命令砸开金蛋！"NOR+HIY"※※※※※※※※※\n"NOR+
                	HIY"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR);
                set("value", 1500);
                set("unique", 1);
                set("material", "wood");
                set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("desc","《幸运52中》中经常看见的金蛋。");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_za", "za");
}

int do_za(string arg)
{        
       object ob, me = this_player();
       object obj,obnew,obj2;
       string str = "";
       int i = random(2);

       if(arg!="jindan")
          return notify_fail(HIR"厉害啊！大过年的你想要砸电视机？还是空调机？\n"NOR);
                    
       if (!(ob = present("mu chui", me))) 
		      return notify_fail(HIR"没有木槌，怎么地你想用手砸？小心李咏大哥知道了槌你？\n"NOR);

       switch(i) {
                        case 0:         
                        	      obj = new (BULIAO);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1));
                                break;                                
                        case 1:         
                                obj = new (KUANGSHI);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1)); 
                                break;       
 
                        case 2:         
                                obj = new (JADE);
                                obj->set("secret_obj",1);
                                obj->set_level(5+random(1));
                                str = "极品";
                                str += "玉"; 
                                break;        
                                break;                                                           
                        default:return 1;
                }
      	obj->move(this_player());

        message_vision(HIW"\n\n你挥着木槌朝着"HIY"金蛋"NOR+HIW"砸去，"HIY"金蛋"NOR+HIW"顿时开花，散发出"HIR"金"HIM"花"HIG"四"HIC"溅"NOR+HIW"的“"HIR"光"HIB"芒”"GRN"．．．．．．\n"NOR
                "\n" 
		"            "HIM"^ǒ^^ǒ^^ǒ^^ǒ^\^ǒ^^ǒ^^ǒ^ "NOR"\n"+
		"          "HIR"(*^﹏^*)"HIC"(*^﹏^*)"HIG"(*^﹏^*)"NOR"\n"+
		"         "HIB"▓ "HIR"☆"HIY"★"HIG"☆"HIM"★"HIC"㏒"HIR"☆"HIM"☆"HIB"★"HIY"☆"HIB"★"MAG"☆"HIB"▓ \n"NOR+
		"                  "HIC"△"HIR"�"HIB"〇"HIR"�"HIC"△ \n"+
		"                    "HIG"♀"HIG"♀     \n"+
		"                     "GRN"♀     \n"NOR+
                "\n" NOR, me, ob);  
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"听说%s从"HIY"金蛋"HIM"中获得了一"+obj->query("unit")+obj->name()+"！", me->name(1)));
        message_vision("$N从"HIY"金蛋"NOR"中得到了一"+obj->query("unit")+obj->name()+"。\n\n",me); 
               
        destruct(this_object());
        return 1;               
}

