// 冰蚕毒掌解谜 by hongba
#include <ansi.h>
inherit ITEM;
void setup()
{}
void create()
{
           set_name( YEL"油布小包"NOR, ({"youbu xiaobao","youbu","xiaobao"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                
                set("value", 10000000);
               
set("no_cun",1);
set("no_give",1);
set("no_get",1);

                
        }
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
       object me, obj,ob;
       
       me = this_player();
       obj= this_object();
       
       if( !arg || arg != "xiaobao" ) return notify_fail("你要打开什么?\n");
       if ( me->is_busy() || me->is_fighting())
 return notify_fail("你正忙着呢。\n");
       
       if( obj->query_temp("owner") != me->query("id"))
              return notify_fail("你从哪弄来的东东？\n");
       
       message_vision(HIY"$N打开油布，见里面是一本书，随手翻阅，每一页上都写满了弯弯曲曲的文字，没一字识得。\n"NOR,me);
       ob = new("clone/misc/shenzujing");
ob->move(me);
       destruct(obj);

       return 1;
}
