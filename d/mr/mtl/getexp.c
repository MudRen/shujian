// mr getexp.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"娘缳玉洞-实战部"NOR);
	set ("long",@long
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各种书
籍，似乎与如何更快的获取实战经验有关。你可以在这里参悟(canwu)相关内容。
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "canwu"); 
         add_action("do_canwu", "yandu");
 }



int do_canwu(string arg)
 {
     object me = this_player();

     if(arg != "combat")
           return notify_fail("这里只能参悟实战(combat)部分!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_exp") )
                  return notify_fail("你正忙着呢。\n");


     if( me->query("combat_exp",1)<15000000)
                 return notify_fail("你胡乱的翻了翻书架上的藏书，发现里面的内容高深莫测，无法理解，不由得摇了摇头。\n");
       
     
     if ( me->query("relife/exp_ext",1) >=20 )
                 return notify_fail("你已经完全掌握了实战部分藏书的精髓，无法更进一步了。。\n");

  if (me->query_temp("canwu_now") )
       return notify_fail("你正忙着呢。\n");

        if (query_temp("canwu") )
        return notify_fail("有人正在参悟呢，你等一会把。\n");

       message_vision( HIW"$N仔细的翻看着书架上的藏书，对里面如何更好的获取实战经验的内容很感兴趣。\n"NOR,me);
        message_vision( HIW"$N一头扎进书堆里.不停的翻看着。。 \n"NOR, me);
       me->start_busy(100);               
     me->set_temp("canwu_now",1); 
     set_temp("canwu",1);         
     call_out("thinking",5, me );
         return 1;

 }


int thinking(object me)
{
  int i, exp;
  if(!me) return 0;
	
  if(me->query_temp("con_exp")<(3+random(3)))
       {  me->add_temp("con_exp",1);
          if(random(2)) tell_object(me,HIG"\n你仔细的研读着书里面的内容，只觉得耳目一新...\n"NOR);
                   else tell_object(me,HIY"\n你参照着自己过往的实战过程，心里有所领悟...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"眉头紧皱，似乎在思索着什么...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_exp");
         me->start_busy(1);     
  message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
  
     tell_object(me,HIR"\n你通过本次研读，成功的参悟得一点实战诀窍！\n"NOR);
me->add("cw_exp",1);
       me->add("relife/exp_ext",1);
       i = me->query("relife/exp_ext",1) * 5;
       exp = 2000000;
       if(me->query("registered") == 3) exp=1800000;
       if(me->query("y-card-vip"))         exp=1700000;
       if(me->query("buyvip") )             exp=1600000; 
       me->add("combat_exp",-exp);

    tell_object(me,HBYEL"\n你本次参悟共耗费了" + HIW + chinese_number( exp ) + HIR + "实战经验，但是你将在每次实战中多获取百分之" + HIW + chinese_number( i ) + HIR + "的经验！\n"NOR);

      log_file("canwu/getexp", sprintf("%s(%s) 第%d次参悟实战经验部分，当前经验：%d。\n",
       me->name(1),
       me->query("id"),
       me->query("relife/exp_ext",1),
       me->query("combat_exp")) );

   me->delete_temp("canwu_now");  
delete_temp("canwu");   
   }


}


