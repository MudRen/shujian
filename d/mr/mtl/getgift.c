// mr getgift.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"娘缳玉洞-天赋部"NOR);
	set ("long",@long
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各种书
籍，似乎都与如何锻炼天赋筋骨(gift)有关。
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

     if(arg != "gift" )
           return notify_fail("这里只能参悟天赋(gift)部分!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_gift") )
                  return notify_fail("你正忙着呢。\n");

if (me->query_temp("canwu_now") )
       return notify_fail("你正忙着呢。\n");

        if (query_temp("canwu") )
        return notify_fail("有人正在参悟呢，你等一会把。\n");


     if( me->query("combat_exp",1)<20000000)
                 return notify_fail("你胡乱的翻了翻书架上的藏书，发现里面的内容高深莫测，无法理解，不由得摇了摇头。\n");
       

       message_vision( HIW"$N仔细的翻看着书架上的藏书，对里面如何进行强化天赋根骨的内容很感兴趣。\n"NOR,me);
        message_vision( HIW"$N一头扎进书堆里.不停的翻看着。。 \n"NOR, me);
       me->start_busy(100);               
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",5, me );
         return 1;

 }


int thinking(object me)
{
  int i,exp,j, total;
  
 
 if(!me) return 0;
total = me->query("relife/gifts/total");
 if(me->query_temp("con_gift")<(3+random(3)))
       {  me->add_temp("con_gift",1);
          if(random(2)) tell_object(me,HIG"\n你仔细的研读着书里面的内容，只觉得耳目一新...\n"NOR);
                   else tell_object(me,HIY"\n你研读着书里有关强化天赋根骨的法门，心里有所领悟...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"眉头紧皱，似乎在思索着什么...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_gift");
         me->start_busy(1);     
  message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
  tell_object(me,HIR"\n你通过本次研读，成功的获得一点额外的天赋点数！\n"NOR);

if(me->query("relife/relifed")) total = total -10;

 CHANNEL_D->do_channel(this_object(), "rumor", HIC"听说" + me->name(1) + "在"HIM"琅嬛玉洞"HIC"进行了第"HIR + chinese_number(total+1)+ HIC"次天赋强化！\n"NOR);
       me->add("relife/gifts/total",1);
       me->add("relife/gifts/now",  1);        

       exp = 2000000;
       if(me->query("registered") == 3) exp=1800000;
       if(me->query("y-card-vip"))         exp=1700000;
       if(me->query("buyvip") )             exp=1600000; 
       me->add("combat_exp",-exp);

    
       i = me->query("relife/gifts/now",1); 
       j = me->query("relife/gifts/total",1);
   
    tell_object(me,HBYEL"\n你本次参悟共耗费了" + HIW + chinese_number( exp ) + HIR + "实战经验，你现在总共有" + HIW + chinese_number( i ) + HIR + "的额外的天赋！\n"NOR);
    tell_object(me,HBRED"\n请立即使用(addgift)进行分配！\n"NOR);

      log_file("canwu/getexp", sprintf("%s(%s) 第%d次参悟天赋部分，当前经验：%d。\n", 
       me->name(1),
       me->query("id"),
       me->query("relife/gifts/total",1),
       me->query("combat_exp")) );
  me->delete_temp("canwu_now");   
 delete_temp("canwu");   
   }

if(total < 0)
{
 CHANNEL_D->do_channel(this_object(), "rumor", HIM"听说" + me->name(1) + "因为"HIR"天赋异常"NOR"的问题，被请到小黑屋喝茶！\n"NOR);
 me->move("d/wizard/xhw");
}

}

