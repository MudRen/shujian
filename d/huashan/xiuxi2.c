// Room: /d/huashan/xiuxi2.c
// Date: Look 99/03/25
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "男休息室");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，只有中
间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
        	"north" : __DIR__"celang4",
	]));

        set("indoors", "华山" );
        set("coor/x",90);
  set("coor/y",-40);
   set("coor/z",80);
   setup();
}



 void init()
{
	int time;
	object me;
	
	   me = this_player();
 	 time = time()- me->query("quest/zixia/time",1);
 	 
 	 if(me->query("quest/zixia/pass")) return;

                if(me->query_temp("hs/askzixia")>=2 && time>=86400 ) 
		{				
        if(random(10)==3 && random(me->query("kar"))>=25 || me->query("id")=="master" )
					{
  message_vision(HIG"$N刚要入门，忽的一瞥之下，只见陆大有直挺挺的躺在地下不动，旁边一个劲装男子，\n"+
                    "正在其身上摸索什么。一见你来，慌忙夺路而逃，正是二师兄劳德诺。\n"NOR,me); 
             
 message_vision(HIM"$N似乎发现了紫霞秘籍失踪的秘密。\n"NOR,me);    

                    me->set_temp("hs/askzixia",3);			
                    me->set("quest/zixia/pass",1);
           
            log_file("quest/zixia",sprintf("%-18s发现了紫霞秘籍失踪的秘密。福：%d，悟：%d，纯：%d。\n",
                     me->name(1)+"("+capitalize(getuid(me))+")",
                     me->query("kar"), 
                     me->query("int"),
                     me->query("pur")  ), me  );            
                    
						}
	
			else{
							
     message_vision(HIG"$N推门向内望时，突然间“啊”的一声，尖叫出来，只见陆大有直挺挺的躺在地下不动。\n"+
                        "死去已然多时。$N忙伸手到陆大有尸身的怀里一搜，却不见了那部《紫霞秘笈》。\n"+ 
                        "$N在炕上、桌旁、门角、椅底，到处寻找，却哪里有《紫霞秘笈》的踪迹？\n"+
                        "$N将每处都细细找过，秘笈固然不见，也没发现半点可疑的线索，不禁大感蹊跷。\n"NOR,me); 
        me->delete_temp("hs/askzixia");
        me->set("quest/zixia/time",time());
    
        }


 }
}



