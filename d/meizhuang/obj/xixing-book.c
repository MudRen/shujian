// yingshe-boook.c
// by daidai
#include <ansi.h>
 
inherit ITEM;
 
void create()
 {
         set_name(HIR"吸星大法拓本"NOR, ({ "xixing miji","miji","book" }));
         set_weight(200);
         if( clonep() )
                 set_default_object(__FILE__);
         else {
                 set("unit", "本");
                 set("long","这是一本记录吸星大法的秘籍，是从梅庄地牢密室拓下来的，一般人无法领悟。\n");
                 set("value", 500000);
                 set("no_get","这是那人的宝贝，你如何拿的走？\n");
                 set("no_drop","这么珍贵的东西，你敢乱丢？\n");
                 set("treasure",1);
                 set("unique",1);
                 set("material", "paper");
         } 
 }
 
 void init()
 {
         add_action("do_du", "read");
 }
 
 int do_du(string arg)
 {
         object me = this_player();
         int neili, lev;
         
         if(!id(arg)) return 0;
 
         if(me->is_fighting())
                 return notify_fail("你无法在战斗中专心下来研读新知！\n");
         if(me->is_busy()) 
                 return notify_fail("你现在正忙着呢。\n");
 
         if(!me->query("quest/xxdf/pass"))
                 return notify_fail("你从哪里偷来的秘籍？可不能偷读哦！\n");
         if(this_object()->query("clone_by_wizard") && !wizardp(me)) 
                 return notify_fail("你从哪里偷来的？可不能偷读哦！\n"); 
         if(!me->query_skill("literate", 1)) 
                 return notify_fail("你是个文盲，先学点文化(literate)吧。\n");        
         if(me->query("jing") < 20)
                 return notify_fail("你现在过于疲倦，无法专心下来研读新知。\n");
         lev = me->query_skill("xixing-dafa", 1);
         if (lev >200)
                 return notify_fail("你已经不能从这本书里得到任何指点了。\n");
             neili = 20+random(20);
              if (me->query("neili") < neili) 
                 return notify_fail("你内力不够，无法钻研这么高深的武功。\n");
          if (!lev)
                 write(HIR"\n你看了看秘籍，封皮上赫然写道："HIR"\n\n\t\t\t吸星大法\n\n"HIY"你翻开秘籍，发现这本居然是日月神教吸星大法之内功诀要。\n"NOR);
         write("你研读「吸星大法」秘籍拓本，对照自己的领悟要诀，似乎有些心得。\n");
         me->receive_damage("jing", 30);
         me->receive_damage("neili", neili);
         me->improve_skill("xixing-dafa", me->query_skill("literate", 1) );
 
         if (!random(5))
                 message("vision", me->name() + "拿着一本秘籍在认真地研读着。\n", environment(me), ({me}));
         return 1;
 } 
 
 


