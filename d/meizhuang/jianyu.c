// /d/meizhuang/jianyu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"梅庄地牢"NOR);
	set("long", @LONG
这里黑黑暗暗，几乎伸手不见五指。唯一的光亮来自墙上忽明忽暗
的松油灯。地上和墙上布满了暗红色的血痕，散发出阵阵腥气。不断传
来的喘息声在死沉的地牢里回荡，令人毛骨耸然。从地牢的墙缝里透出
几缕阳光。西边是一扇紧闭的囚门。
LONG
	);
	set("item_desc", ([
		"door" : "囚门似乎以前有人动过什么手脚。\n",
		"门"   : "囚门似乎以前有人动过什么手脚。\n",
	]) );
	
			set("objects", ([
		"d/meizhuang/npc/renwoxing" : 1,
				]) );
				set("item_desc", ([
                "man": "这个人如同稀泥一般，双目涣散，没有一点神采。整个人似乎只剩下
了一个干枯的躯壳，然而却还有一口气，如果不是铁镣锁着，也许可
以把他搬下床来。\n",
        ]));

	set("valid_startroom","1");

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", -10);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_move", "move");
}

void check_trigger()
{
	object room;
	if( (int)query("trigger")==8 && !query("exits/out") )
	{
		message("vision","囚室门被你推得裂开了一道缝隙，刚好可以容你钻出去。\n", this_object() );
		set("exits/south", __DIR__"didao7");
		if(!( room = find_object(__DIR__"didao7")) )
			room = load_object(__DIR__"didao7");
		message("vision", "囚室门突然裂开一条窄缝。\n", room );
		room->set("exits/north", __FILE__);
		delete("trigger");
		call_out("close_passage", 5);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/south") ) return;
	message("vision","铁门伊咿呀呀一阵响，砰地一声又关上了。\n", this_object());
	if( room = find_object(__DIR__"didao7") )
	{
		message("vision", "铁门伊咿呀呀一阵响，砰地一声又关上了。\n", room);
		room->delete("exits/north");
	}
	delete("exits/south");
}

int do_push(string arg ,string dir)
{
	object me;
	me = this_player();

		
	if( !arg || arg=="" )
	{
		write("你要推什么？\n");
		return 1;
	}
	
	if (me->query_skill("xixing-dafa",1) < 200)
		{
	write(HIR"\n你现在吸星大法太低了，恐怕出去抵档不住梅庄四友的攻击，还是赶快研读吸星大法吧。\n"NOR);
	return 1;
     }
if (me->query_skill("xixing-dafa",1) >= 200 && me->query("quest/xxdf/pass"))
		{
	write(HIW"\n你刚想推门，突然听见门外有人走路的声音，你立即躺到笼子里，假装用锁链锁住自己的手脚。\n"NOR);
	write(HIG"\n你发现居然是黑白子进来了，还没有等黑白子说话，你一跃而起，牢牢扣住黑白子的手腕。。。\n"NOR);
	write(HIC"\n黑白子只觉内力愈泄愈快，勉强凝气，还暂时能止得住，但呼吸终究难免，一呼一吸之际，\n"
	"内力便大量外泄，这时早忘了足趾上的疼痛，只求右手能从方孔中脱出，纵然少了一只手\n"
	"一只脚也是甘愿，一想到此处，伸手便去腰间拔剑。他身子这么一动，手腕上“内关”“\n"
	"外关”两处穴道便如开了两个大缺口，立时全身内力急泻而出，有如河水决堤，再也难以\n"
	"堵截。黑白子知道只须再捱得一刻，全身内力便尽数被对方吸去，当下奋力抽出腰间长剑，\n"
	"咬紧牙齿，举将起来，便欲将自己手臂砍断。但这么一使力，内力奔腾而出，耳朵中嗡的\n"
	"一声，便晕了过去。\n\n"NOR);
  write(HIR"你不管三七二十一，打开监狱大门，一路狂奔，拣荒僻的小路飞奔，到了一处无人的山野，然后\n"
  "一路小跑到达杭州城白堤。你发现自己如此迅捷飞奔，停下来时竟既不疲累，也不气喘，比之受\n"
  "伤之前，似乎功力尚有胜过。你忽然发现白堤上站了一个高人。\n\n"NOR);
  
  write(HIG"任我行对着你嘿嘿嘿的笑着对你说到：小子！看在你救我份上，我就收下你，你是（否）愿意拜我为师？\n"NOR);
  me->move("d/hz/baidi");
  me->set_skill("qixian-wuxingjian",1);
  write(HIG"任我行对着你嘿嘿嘿的笑着对你说到：可惜你非我神教弟子，我就将梅庄大庄主七弦无形剑教授与你吧？\n"NOR);
  message_vision(HIC"\n你的「七弦无形剑」进步了！”\n"NOR,me); 

	return 1;
     }
	if( arg=="door" || arg == "门")
	{
		add("trigger", 1);
		write("\n你试着用力推着紧闭着的囚门，似乎有一点松动....\n");
		check_trigger();
		return 1;
	}
	return 1;
}

void reset()
{
	::reset();
	delete("trigger");
}

int do_move(string arg)
{       
        int i;
        object me;
        object ob;      

        me = this_player();
        i =me->query("kar");
        
        
        if (arg != "man")
                return notify_fail("你要搬什么？\n");

        if (me->query_temp("get_xxbook"))
                return notify_fail("你没兴趣理这个半死不活"
                                   "的人，现在只想快点离开这里。\n");

        if (!me->query_temp("quest/xxdf/startlass") 
                || random(i) < 28
        	||  me->query("combat_exp") - me->query("quest/xxdf/fail_exp") <100000
        	|| time()-me->query("quest/xxdf/time")<86400 
        	 )
        {
                write(HIY"你走上前去，却发现锁人的铁镣上面有一个细细的缺口，而且看上去前不久有人曾经扭开过，
不禁有些迷惑，不知道有什么机关，索性就不再理床上那人。\n"NOR);
    write(HIG"你在囚室里转悠了许久，也没有发现什么特别的地方，于是就推开囚门，转身走了出去。
你觉得此地甚是诡异，不可久留， 于是就不告而别，当下一个人悄悄出了梅庄。
待到白堤，仔细回想，忽觉得那人床下石板似有玄机，可惜已经错过，不禁大感懊悔。\n"NOR);
               me->delete_temp("quest/xxdf/start");
        
            me->set("quest/xxdf/fail_exp", me->query("combat_exp") );
            me->set("quest/xxdf/time",time());
            me->add("quest/xxdf/fail,1");
            
      tell_object(me,HBBLU"\n很可惜，你本次尝试解密吸星大法失败！\n"NOR);
      tell_object(me,HBBLU"你目前的经验是" + me->query("combat_exp") + "，现在时间是书剑"+ NATURE_D->game_time() + "，请记录。\n"NOR);
      tell_object(me,HBBLU"你将在间隔24小时并增加100K实战经验后获得下一次机会！。\n\n"NOR);                   
               me->move("d/hz/baidi");
                return 1;
        }
        

        
        

        write(HIW"你仔细看了看铁镣，发现它虽然是精钢制成，却有一个细细的缺口，
这种东西也能锁住人？你不禁哑然失笑，随即把那个奄奄一息的人
搬了下来，这是你突然发现原来床上刻着一些字，你不禁有些疑惑。
于是将它抄了下来，准备慢慢研究，随即想了想，用力将上面刻的
字抹去，然后把那个人重新放到床上，不再理会。\n\n"NOR);

        if(i >30) {
         me->die(); 
        return 1;
        }

        me->set("quest/xxdf/pass", 1);
        me->delete_temp("quest/xxdf/start");

        ob = new("/d/meizhuang/obj/xixing-book");
        ob->move(me, 1);
        
        
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"听说%s在梅庄地牢获得一本"HIR"吸星大法拓本"NOR"！", me->name(1)));
        
        write(HIY"\n你成功将铁笼中的文字拓下一本吸星大法拓本。\n"NOR);
        log_file("quest/xixing",sprintf("%8s%-10s在梅庄地牢成功获得吸星大法拓本，华山：%4d，武当：%4d，失败：%2d，福：%2d。\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/华山"), 
			me->query("job_time/武当"), me->query("quest/xxdf/fail"),me->query("kar")),me);

        return 1;
}
