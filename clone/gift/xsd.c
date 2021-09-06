//Created by Zhuifeng@SJFY 2010/8/16

#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //玉
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //矿
#define BULIAO    "/d/zhiye/obj/buliao" //布料
inherit SPEC;
void create()
{
        set_name(HIR"相思豆"NOR, ({ "xiangsi dou","dou"}) );
        set_weight(10);
                set("unit", "颗");
                set("long", "质坚如钻、色艳如血、形似跳动的心脏，红而发亮，不蛀不腐，色泽晶莹而永不褪色。其外形及纹路，皆为“心”字形。\n"
                            "真的是大心套小心，心心相印。传说是心有相思之苦的人，落泪树下，难以化解，最终凝结而成，是相恋之人相思之意。\n"
                             "你若有心你就来思恋的你的爱人(Airen)吧！\n");
                set("value", 10);
                set("material", "wood");
                set("no_drop", "你如何能丢弃这些许年来的相思之情。\n");
                set("no_get", "你又如何能够懂得别人相思之苦，又何必陷己入相思之苦呢。\n");
                set_weight(50);
                set("value",3000);
                set("treasure",1);
                set("desc","红豆生南国，春来发几枝。愿君多采撷，此物最相思。");
                set("credit",1000);    

       setup();
}
void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(1);

       if(arg!="airen")
          return notify_fail(HIM"你想思念谁？\n"NOR);                    

       switch(i) {                          
                        case 1:         
                                obj = new (KUANGSHI);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1)); 
                                break;       
 
                        case 0:         
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

        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"听说%s从"HIY"相思红豆"HIM"中获得了一"+obj->query("unit")+obj->name()+"！", me->name(1)));
        message_vision("$N渐渐陷入了久久的沉思.......\n",me); 
               
        destruct(this_object());
        return 1;               
}

