#include <ansi.h>

inherit SPEC; 

void create()
{
    set_name (HIR"碎纸片"NOR, ({ "suizhi pian"}));
    set("long",HIR"这是一片皱巴巴的碎纸片，纸片已经泛黄，里面的字已然模糊不清。\n"NOR);

    set("unit","片");
	set_weight(100);
	set("value",3000000);
	
    set("no_give",1);
    set("no_drop",1);	
    set("no_get",1);
    set("treasure",1);
    set("degree",1);
    set("flag","spec/suizhi");
    set("rest",5);
    set("desc","传说是明教张教主之物!");
    set("credit",1200);
	setup();
}

void init()
{
    add_action("do_chakan","chakan");
  
}

int do_chakan(string arg)
{
        mapping fam;
	object me=this_player();
        fam = me->query("family");

        if (arg!="suizhi pian" )
              return notify_fail("你要查看什么?\n");
         if ( me->query("combat_exp") < 800000)
              return notify_fail("你还是抓紧时间去增加点江湖阅历吧！800K前是没机会的啊！\n");

        if ( fam["family_name"] != "明教" || fam["master_name"] != "张无忌" )

              return notify_fail(HIR"这个据说是魔教教主的秘密，你还是少打听为好。 \n "NOR,);
      	
        if (!restrict()) 
            { return notify_fail("本周你已经不能再使用"+this_object()->query("name")+"了。\n");}   ;
 
        if ( !me->query("jiuyang/wei")  && me->query("kar") <31 && random(me->query("kar")) >= 26 )  
            {             
                me->set("jiuyang/wei", 1);
 write(HIR"纸片上潦草的写道：经在油中，经在油中。。。经在猿中！居然是那只大白猿！ \n"NOR,);
 write(HIR"纸片上潦草的写道：原来如此！原来如此！ \n"NOR,);
 write(HIM"你心下思忖：“经”莫非就是教主所怀“九阳真经”？还是赶紧去找教主问个明白才是。\n"NOR,);
 CHANNEL_D->do_channel(this_object(), "rumor", HIC"听说" + me->name(1) +
                                 "在碎纸片中发现了九阳真经的传闻秘密！\n"NOR);

                log_file("quest/jiuyang",
                          sprintf("%-18s通过通宝物品得到传闻机会，富%d。\n",
                           me->name(1)+"("+capitalize(getuid(me))+")", 
                           me->query("kar")
                         ), me);
                return 1; 
             }	 

        me->set_temp("sj_credit/quest/mj/jiuyang",1);
         
       write(HIW"你反复查看这张"HIR"碎纸片"HIW"，希望能从上面查到点什么。突然，两个模糊的字的映入你的眼帘——“"HIR"经在..."HIW"”!\n"NOR);
        
	degree();
	return 1;

}
