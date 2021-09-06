// 全真教 qixing-jian/lianzhen2 quest
//modifield by action@SJ 2008/9/18
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIB"密洞"NOR);
	set("long", @LONG
这是全真教王重阳自己挖掘的密洞，当太阳升起时能直射全洞。象是有人在此住
过，正面有一石床，左边放有一些石碗，顶上的居然有几个小洞(hole)，阳光透
过小洞直射进来，这有小洞的排列很像北斗七星的排列，你可以演练(yanlian)。
LONG
	);

	set("exits", ([
		"up" : __DIR__"shandong",
	]));    
	setup();
}

void init()
{
	add_action("do_yanlian", "yanlian");
}

int do_yanlian(string arg)
{
	object me;
	me = this_player();

	if( !living(me) ) return 0;

	if( (int)me->query_skill("qixing-jian", 1) < 400 )
		return notify_fail("你的北斗七星剑法等级不足，怎么练也没有用。\n");

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
	
  	       
	if( arg == "剑招" ) {
	
			message_vision("$N慢慢按照小洞中射进来的光线，走气北斗七星剑七星连阵的招式来。\n", me);
			me->set("/quest/quanzhen/lianzhen/time",time());
      me->set("/quest/quanzhen/lianzhen/combat_exp",me->query("combat_exp"));
		    remove_call_out("canwu");
       call_out("canwu", 1, me);  
       return 1;
         }  
      return notify_fail("什么？\n");
         
} 							
void canwu(object me)
{
  if(!me) return;  
    remove_call_out("thinking");
    call_out("thinking", 1, me); 
    tell_object(me,HIR"你跟着从小洞发出来的光线，演练着北斗七星的步法.........\n"NOR);
    me->start_busy(2);
}

int thinking(object me, object ob)
{
	int p;
	if(!me) return 0;
	
  if(me->query_temp("lianzhen_thinking")<(3+random(3)))
	{
		me->add_temp("lianzhen_thinking",1);
    if(random(2)) tell_object(me,WHT"\n你按照光线照进来的路线招式,试着练了一遍，你发现你的剑招越来越快...\n"NOR);
    else tell_object(me,HIG"\n\n突然间，你似乎抓到了什么，霎时密洞中金光闪耀，你似乎感觉到了北斗星运行变化...\n"NOR);
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp("lianzhen_thinking");

        p=random(40);

         if(p > 25 && random(me->query("kar"))>20)
    {
       tell_object(me,HIG"\n你发现你已经完全看懂了墙壁的招式，招式已如无与伦比之境，真个石室充满了一个真气。\n"NOR);
       message_vision(HIG"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
       me->set("quest/quanzhen/lianzhen","pass");
       me->delete_temp("quest/lianzhen/asked");
       message_vision(HIC"\n你根据照进来的光线，终于领悟了七星连阵的精华所在。”\n"NOR,me);     
    
       
	log_file("quest/quanzhen", sprintf("%s(%s) 失败%d次成功解开七星连阵。富源：%d；经验：%d。", me->name(1),me->query("id"), me->query("quest/quanzhen/lianzhen/fail"),me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n你脑海里似乎抓住了什么，可是依然不得要领。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，道：“好像还是很困难的。”说罢，深深地叹了口气。\n"NOR,me); 
       me->add("quest/quanzhen/lianzhen/fail",1);
       me->move("d/quanzhen/shandong");
	log_file("quest/quanzhen", sprintf("%s(%s) 解七星连阵失败：%d次。富源：%d；经验：%d。", me->name(1),me->query("id"), me->query("quest/quanzhen/lianzhen/fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}