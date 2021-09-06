// shibi.c 石壁

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "石壁");
        set("long", @LONG
你的面前是块打磨光滑的大石壁(shibi)。 石壁边上点燃着八根
大火把，照耀明亮。石室中已有十多人，有的注目凝思，有的打坐练
功，有的毕目喃喃自语，更有几人在大声争辩。
LONG );
        set("item_desc",([
                "shibi"  :
"\n石壁上有首诗：\n\n\n"
"\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　侠客行　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　赵客缦胡缨，吴钩霜雪明。银鞍照白马，飒沓如流星。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　十步杀一人，千里不留行，事了拂衣去，深藏身与名。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　闲过信陵饮，脱剑膝前横。将炙啖朱亥，持觞劝侯嬴。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　三杯吐然诺，五岳倒为轻。眼花耳热后，意气素霓生。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　救赵挥金锤，邯郸先震惊，千秋二壮士，煊赫大梁城。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷　纵死侠骨香，不惭世上英，谁能书阁下，白首太玄经。　∷∷∷\n"
"\t∷∷∷　　　　　　　　　　　　　　　　　　　　　　　　　　∷∷∷\n"
"\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n",
        ]));
        
        set("no_clean_up", 0);

        set("exits", ([
 "west"  : "/d/xiakedao/dating",
                
        ]));
        setup();
        replace_program(ROOM);
}

/*
void init()
{
add_action("do_chuaimo", "chuaimo");    
}
int do_chuaimo(string arg)
{
        int i,p;
        int improve, cost, lv;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        improve /= 2;
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
                return notify_fail("你正忙着呢。\n");
                
        if (arg == "太玄功" ){             
if(!me->query_temp("taixuan/qingtie") )  
                        return notify_fail("你瞎揣摩什么?\n");
      
if( me->query_skill("taixuan-gong", 1) >= 100 )
                            return notify_fail("你已经将太玄功融会贯通了!\n");


   tell_object(me,HIG"\n你努力地想看清石壁上的文字，似有无数人影交相互动，又幻化成无数小蝌蚪在你眼前游走...\n"NOR);
   tell_object(me,HIY"\n突然间，你似乎抓到了什么...\n"NOR);
          tell_room(environment(me),HIC""+me->query("name")+HIC"似乎在思索着什么，一副愁眉不展的样子。\n"NOR, ({}));
          
remove_call_out("do_chuaimo");
call_out("do_chuaimo",4+random(3), me);

        
          p=random(me->query("kar")+10);
      lv = me->query("max_pot")-100;
     
          if(p> 27 && me->query("kar")<31 )
      {
       tell_object(me,HIG"\n你明悟其中，突然间明白了一切。\n"NOR);
       message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
         
       tell_object(me,HIR"你看得正入迷，忽然恍然大悟似乎颇有些心得。\n"NOR);
       

me->set("taixuan_pass",1);
       me->set_skill("taixuan-gong",lv);

me->delete("taixuan/qingtie");
CHANNEL_D->do_channel(this_object(), "rumor", HIW""+me->query("name")+"机缘巧合，参悟成「太玄功」 ！");
           i=180+random(40);
           
           
    }
    else
    {
       tell_object(me,HIG"\n你脑海里似乎抓住了什么，可是依然不是很明白。\n"NOR);
       
       message_vision(HIC"\n$N摇了摇头，道：“好像还是很困难的。”说罢，深深地叹了口气。\n"NOR,me); 
me->delete_temp("taixuan/qingtie");
           

    
  }
  return 1;
}
}

*/
