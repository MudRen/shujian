//By Jpei 王重阳已死

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "后山山洞");
        set("long", @LONG
这里是重阳真人生前静修的山洞。洞壁上悬挂着一副画(hua)。题写着姬志真手书的《重阳祖师开道碑》：
"原夫至道出自先天，太上卓尔立其宗，累圣袭而张其后，灵源妙本，既发而不蒙，出楗玄关，大开而弗闭。
从兹设教，代不乏人。然而顺世污隆，乘时步骤，去圣愈远，灵光不属。波澜既荡，异派争流，枝叶方联而纷
华竟生。散无名之大朴，遗罔象之玄珠，忘本迷源，随声逐色。正涂壅底，道间荒凉。由是圣人复起，究天元
一气之初，洪造更新，应历数万灵之会，天挺神授而力拯颓网，祖建宗承而载维新纽、弃华摭实，授溺录迷。
革弊鼎新而玄关复启焉。重阳祖师乃其人也……。”
    下面是个神案，放着几本道藏经典，供着一把「七星宝剑」。洞内纤尘不染，极其整洁。
LONG);
        set("exits", ([
                "out" : __DIR__"xiaolu3",
        ]));
        set("item_desc", ([
        	"hua": YEL "画中是一个中年道士的背影，看不出什么相"
                       "貌，画中道人一手指着天，\n                                         画角题着「" HIR "活"
                       "死人像" NOR + YEL "」几个字。\n" NOR,
        ]) );
        set("paper_count", 1);
        setup();
}

void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_fan","fankan");
}

int do_ketou(string arg)
{
        object sword;
        object me = this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");


        if ( !(me->query("family/family_name")=="全真教") || me->query_temp("get_sword") ) 
                return notify_fail("你看着重阳真人的画像，想象着他傲视群雄睥睨天下的绝代风采，不由得拜了一拜。\n"); 
                
        if ( me->query("qi") <= 50)
        	      return notify_fail("就你当前身体现状还是去休息吧。"); 
        	      
       sword= new(BINGQI_D("sword/qixing-jian"));
  
       if( me->query_temp("ketou") && arg =="宝剑")
       {
            message_vision(HIG"$N走向前去，恭恭敬敬的拔出七星宝剑。\n"NOR,me);
            sword->move(me);
            me->set_temp("get_sword",1);
            return 1;
         }
          else
          {
             message_vision("$N恭恭敬敬地在神案前的团蒲上跪了下来，对着祖师画像磕了三个响头。\n", me);
             me->add_temp("ketou", 1);
             return 1;
          }
 }

//先天功quest的触发点
//触发的书也不是那么好拿的

int do_fan(string arg)
{
        object paper;
        object me = this_player();

        if (!arg || arg != "道藏经典")
                return notify_fail("你要翻什么？\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
   
        if ( !(me->query("family/family_name")=="全真教") ) 
                return notify_fail("你随意的翻看了几页，都是玄门温养丹鼎之法，你只觉得云里雾里，不甚了解，索然无味。\n"); 
               
       if ( !me->query_temp("ketou")  ) 
                return notify_fail("你翻看了几页，都是玄门温养丹鼎之法，只觉得深奥无比。\n");        

       if ( query("paper_count") <1  ) 
                return notify_fail("你翻看了几页，都是玄门温养丹鼎之法，只觉得深奥无比。\n");        
 
        if ( me->query_skill("xiantian-gong", 1)>=300 
             && me->query_skill("taoism", 1)>=200 
             && me->query_skill("quanzhen-jianfa", 1)>=300 
             && random(50) >=25  
             && !me->query_temp("quanzhen/force")
             && !me->query("quanzhen/force") ) 
        {
                paper=new(__DIR__"obj/xtg_book");
                if ( !paper ) return 1;

                add("paper_count", -1);
                me->set_temp("quanzhen/force", 1);

                message_vision(HIR"$N仔细的翻看着洞中所藏道学经典，忽然间你发现其中一本中似乎夹了一小段丝绢。\n"NOR,me);
                write(MAG"你仔细的将丝绢抽出一看，上面密密麻麻的记载了练功心法，似乎与先天功一脉相承，但却更加深奥。\n"NOR);
                message_vision("$N连忙将密笈收好。\n",me);
                paper->move(me, 1);
              return 1;
        } 
       else  
            {   me->add_temp("ketou",-1);
              message_vision("$N随意的翻看了几页，都是玄门温养丹鼎之法，你只觉得云里雾里，不甚了解，索然无味。\n",me); 
              return 1;
              }

}

