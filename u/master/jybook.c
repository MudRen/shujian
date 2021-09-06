// By action@SJ 作弊专用
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"金庸全集"NOR, ({ "book","quanji" }) );
        set_weight(10);
                set("unit", "本");
                set("long", "一本神奇的书籍，据说预示着整个泥巴世界末日的来临。\n");
 //               set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
                set_weight(100);
	              set("value",3000000);
	              set("no_give",1);
	              set("treasure",1);
	              set("degree",1);
	              set("flag","spec/jiemi");
	              set("rest",1);
	              set("desc",HIR"末日天书"NOR);
	              set("credit",1);

       setup();
}



void init()
{
        add_action("do_eat", "read");
}


int do_eat(string arg)
{
	object me = this_player();
	
	if(arg!="book")
             return notify_fail("你要翻看什么?\n");
       if (me->is_busy()) {return notify_fail("你正忙着呢。\n");}
	if (!me->query("wizard/jiemi"))
	{
		tell_object(me, HIR"末日即将来临，你可以选择以下几种技能来度过余下的时光：\n"NOR);
		tell_object(me, HIR"1：九阴上卷。\n"NOR);
		tell_object(me, HIR"2：九阴下卷。\n"NOR);
		tell_object(me, HIR"3：冷泉神功。\n"NOR);
		tell_object(me, HIR"4：蛤蟆功。\n"NOR);
		tell_object(me, HIR"5：凌波微步。\n"NOR);
		tell_object(me, HIR"6：葵花宝典。\n"NOR);
		tell_object(me, HIR"7：左右互搏。\n"NOR);
		tell_object(me, HIR"8：凝血神爪。\n"NOR);

		tell_object(me, HIR"你想要得到的是："NOR);
		input_to("get_gift", 1);
	}
	else
		tell_object(me, HIR"你的机会已经使用过了!\n"NOR);
	return 1;
}



void get_gift(string arg)
{
	object me = this_player();
	int select;
	string str;
	
	if (!sscanf(arg, "%d", select))
	{
		tell_object(me,HIR"你只能选择1-8中的一个，请重新选择："NOR);
		input_to("get_gift", 1);
		return;
	}

	switch (select)
	{

		case 1: if (me->query("quest/jiuyin1/pass"))
			{
				tell_object(me, HIC"你已经学会了九阴神功上卷。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                   
                     	  tell_object(me,HIG"恭喜,你学到了九阴神功的上卷。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "九阴神功上卷" + NOR + "。\n");
	                       me->set("quest/jiuyin1/pass",1);
                      
			str = "好好保重吧，英雄。期待新世界里再见！\n";
			break;
			
		case 2: if (me->query("quest/jiuyin2/pass"))
			{
				tell_object(me, HIC"你已经学会了九阴神功下卷。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
						
	             
                     	  tell_object(me,HIG"恭喜,你学到了九阴神功的下卷。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "九阴神功下卷" + NOR + "。\n");
                              me->set("quest/jiuyin2/pass",1);
                     
			str = "好好保重吧，英雄。期待新世界里再见！\n";
			break;	
			
		case 3: if (me->query("quest/雪山飞狐/武功/lengquanshengong"))
			{
				tell_object(me, HIC"你已经学会了冷泉神功。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                    
                   	         tell_object(me,HIG"恭喜,你学到了冷泉神功。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "冷泉神功" + NOR + "。\n");                                              
                              me->set("quest/雪山飞狐/武功/lengquanshengong", 1);
                   
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
		
		case 4: if (me->query("oyf/son")&&me->query("oyf/hamagong"))
			{
				tell_object(me, HIC"你已经学会了蛤蟆功。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                 
                 
                   	         tell_object(me,HIG"恭喜,你学到了蛤蟆功。\n"NOR);
                               CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "蛤蟆功" + NOR + "。\n");                                               
                              me->set("oyf/hamagong", 1);
                              me->set("oyf/son",1);
                              me->set_skill("hamagong",10);
                     
       
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
       
		case 5:  if(me->query("quest/天龙八部/武功/yuxiang") && me->query("quest/天龙八部/武功/pass"))
			{
				tell_object(me, HIC"你已经学会了凌波微步。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                                       	        
                              tell_object(me,HIG"恭喜,你学到了凌波微步。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "凌波微步" + NOR + "。\n");                                              
                              me->set("quest/天龙八部/武功/yuxiang", 1);
                              me->set("quest/天龙八部/武功/pass",1);
                        
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
       
		case 6: if (me->query("quest/pixie/pass"))
			{
				tell_object(me, HIC"你已经学会了葵花宝典。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
              
                   	         tell_object(me,HIG"恭喜,你学到了葵花宝典。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "葵花宝典" + NOR + "。\n");                                              
                              me->set("quest/pixie/pass", 1);
                     
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
       
		case 7: if (me->query("quest/hubo/pass")&&me->query("double_attack"))
			{
				tell_object(me, HIC"你已经学会了左右互搏。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                 tell_object(me,HIG"恭喜,你学到了左右互搏。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "左右互搏" + NOR + "。\n");                                              
                              me->set("quest/hubo/pass", 1);
                              me->set("double_attack",1);
                        
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
		case 8: if (me->query("quest/ningxue/pass"))
			{
				tell_object(me, HIC"你已经学会了凝血神爪。请重新选择："NOR);
				input_to("get_gift", 1);
				return;
			}
                
                   	         tell_object(me,HIG"恭喜,你学到了凝血神爪。\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "机缘巧合之下,学到了" + HIW + "凝血神爪" + NOR + "。\n");                                              
                              me->set("quest/ningxue/pass", 1);
       str = "好好保重吧，英雄。期待新世界里再见！\n";
       break;	
       
       
		default:tell_object(me,HIR"你只能选择1-8中的一个，请重新选择："NOR);
			input_to("get_gift", 1);
			return;
	}
	
	
	
	me->set("wizard/jiemi",1);
	tell_object(me, HIR"你已经选择过末日终极技能了。\n"NOR);
	tell_object(me, HIR + str + NOR);
	destruct(this_object());
	return;
}

