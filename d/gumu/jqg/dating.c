// dating.c 大厅
// Modify By River 99.5.25
inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
	set("short",HIW"大厅"NOR);
	set("long",@LONG
这里是绝情谷的大厅，是公孙谷主会客的地方，大厅正前大梁上挂着一块
大匾(bian)，上面刻着四个龙飞凤舞的金字，异常气派。主人又特地在大匾之
下挂了一幅「白鹤鸣天」之图(hua)，画技精深，看得出其主特立独行的性格。
LONG
	);

	set("item_desc",([ 
		"bian": HIY"    
          ※※※※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※※※※
          ※※※　                          ※※※
          ※※※   绝        情        谷   ※※※
          ※※※　                          ※※※    
          ※※※※※※※※※※※※※※※※※※※※
          ※※※※※※※※※※※※※※※※※※※※\n"NOR,
		"dao": "这是一条秘道。\n",   
		"hua": "这是一幅「白鹤鸣天」图，但是图后的墙上似乎有条通道。\n",
	]));

	set("exits",([
		"out": __DIR__"shiwu",
	]));
	set("objects",([
		__DIR__"npc/gsz" : 1,
	]));
	set("valid_startroom", 1);
	setup();
}

void init()
{
	object me;
  me = this_player();
  if (this_player()->query_temp("quest/jindaoheijian/yideng"))
     {
     message_vision(HIG"突然之间，站在屋角待候的一名老仆奔上前来，叫道：“主母，主母，你可没死啊。”裘千尺\n"+
                       "点头道：“张二叔，亏你还记得我。那老仆极是忠心，见主母无恙，”喜不自胜连连磕头，叫\n"+
                       "道：“主母，这才是真正的大喜了。”厅上贺客之中，除了金轮法王等少数几个外人，其余都\n"+
                       "是谷中邻里，凡是三四十岁以上的大半认得裘千尺，登时七张八嘴拥上前来问长问短\n"NOR,me); 
     remove_call_out("action");
     call_out("action", 1, me);      
     write(CYN"\n你不由感到十分好奇，你停了下来，静静倾听。\n"NOR);
    }
    add_action("do_xian","xian");
	  add_action("do_enter","zuan");
	  add_action("do_wa","jie");
}
int do_xian(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if(!arg) return 0;
	if(arg =="hua"){
		message("vision",me->name() +"揭开图画，发现墙后有一条密道。\n", environment(me), ({me}));
		write("你揭起图画，发现墙后有一条密道(dao)。\n");
		me->set_temp("mark/揭",1);   
		return 1;
	}
	return notify_fail("你想干什么? \n");                    
}

int do_enter(string arg)
{
	object me = this_player();

	if(!arg || arg !="dao")
		return notify_fail("你往哪里钻？\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_temp("gsz_agree"))
		return notify_fail("这里是绝情谷的禁地，没有庄主的命令，外来弟子不能进入！！\n");
	if((int)me->query_temp("mark/揭")){
		message("vision", me->name() + "弓身钻进密道。\n", environment(me), ({me}));
		tell_object(me,"你弓身钻进密道。\n");
		me->move(__DIR__"houtang");
		message("vision",me->name() +"弓身从密道中钻了过来。\n", environment(me), ({me}));
		me->delete_temp("mark/揭");
		return 1;
	}
	return notify_fail("没事你乱钻什么？ \n");
}

int do_wa(string arg,object ob)
{
	object weapon, me=this_player();

	if(!me->query_temp("jqd/chi")) return 0;

	if( !arg || arg !="zhuan")
		return notify_fail("你乱揭什么啊？\n");

	if(!weapon=(me->query_temp("weapon")))
		return notify_fail("你准备用手揭开青砖么？\n");        

	if( weapon->query("flag") != 4 )
		return notify_fail("你手上这件兵器无锋无刃，能揭开青砖么？\n");

	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");

	ob=unew(__DIR__"obj/jqdan");
	if(!clonep(ob))
		return notify_fail("你来晚了，绝情丹已给别人拿走了。\n");  
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return notify_fail("你来晚了，绝情丹已给别人取走了。\n");
	}
	tell_object(me,"你数到第五块青砖，拔出腰间"+weapon->name()+"，从砖缝中插入，揭起砖块，发现下面的绝情丹。\n");
	   message("vision", me->name() + "拔出腰间"+weapon->name()+"，从砖缝中插入，揭起砖块。\n", environment(me), ({me}));
	me->delete_temp("jqd/chi");
	ob->move(me);
	return 1;
}

int valid_leave(object me, string dir)
 {
     if ( me->query_temp("quest/jindaoheijian/yideng"))
             return notify_fail("你还是先安心解谜吧！！\n");
     return ::valid_leave(me, dir);
 }

void action(object me)
{
  if(!me) return;
     message_vision(HIC"公孙止冷笑道：“请她原恕？我有什么不对了？”绿萼道：“你将妈妈幽闭地底石窟之中，\n"+
                       "让她死不死、活不活的苦渡十多年时光。爹，你怎对得住她？”公孙止冷然道：“是她先下手\n"+
                       "害我，你可知道？她将我推在情花丛中，叫我身受千针万刺之苦，你可知道？她将解药浸在砒\n"+
                       "霜液中，叫我服了也死，不服也绿萼哭道：“女儿死，你可知道？她还逼我手刃……手刃一个\n"+
                       "我心爱之人，你可知道？”都知道，那是柔儿。”\n"NOR,me); 
   remove_call_out("action2");
   call_out("action2", 1, me);      
}

void action2(object me)
{
  if(!me) return;
  	 message_vision(HIR"忽听公孙止大喝一声：“滚开！”右脚一抬，绿萼身子飞起，向外撞将出来，显是给父亲踢一\n"+
                       "脚。她身子去向正是对准了裘千尺的胸膛。裘千尺手足用不得力，只得低头闪避，但绿了萼来\n"+
                       "势太快，砰的一响，身子与母亲肩头相撞。裘千尺仰天一交，连人带椅向后摔出，光秃秃的脑\n"+
                       "门撞在石柱之上，登时鲜血溅柱，爬不起身。绿萼给父亲踢了这一脚，也是俯伏在地，昏了过\n"+
                       "去。\n"NOR,me);
  	remove_call_out("action3");
    call_out("action3", 1, me);      
}

void action3(object me)
{
  if(!me) return;
  	 message_vision(HIG"杨过本欲置身於这场是非之外，眼见公孙止如此凶暴，忍不住怒气勃发，正要上前与他理论，\n"+
                       "小龙女已抢上扶起裘千尺，在她脑後“玉枕穴”上推拿几下，抑住流血，然後撕下衣襟，给她\n"+
                       "包扎伤处，向著公孙止喝道：“公孙先生，她是你元配夫人，为何你待她如此？你既有夫人，\n"+
                       "何以又想娶我？便算我嫁了你，你日後对我，岂不也如对她一般？”\n"NOR,me);
  	remove_call_out("action4");
    call_out("action4", 1, me);      
}

void action4(object me)
{
  if(!me) return;
  	 message_vision(HIC"小龙女冷笑道：“过儿，这等恶人，原也不必跟他客气。”呛啷一响，也从新娘的大红喜服之\n"+
                       "下取出一对剑来，正是那君子剑与淑女剑。她虽然不通世务，但对付心中恨恶之人，下手时却\n"+
                       "半点也不留情，当时为孙婆婆报仇，即曾杀得重阳宫中全真诸道心惊胆战，广宁子郝大通几乎\n"+
                       "性命不保。此日公孙止害得她与杨过不能团圆，她早已有了以死相拚之念，是以喜服下暗藏双\n"+
                       "剑，只待公孙止救治了杨过，立时俟机相刺，若是不胜，那便自刎以殉，决不将贞洁丧在绝情\n"+
                       "谷中。\n"NOR,me);

  	remove_call_out("action5");
    call_out("action5", 1, me);      
}


void action5(object me)
{
  if(!me) return;
  	 message_vision(HIR"小龙女使动玉女剑法，等要和杨过心意相通，发扬“素心剑法”威力，那知他目光始终不瞧过\n"+
                       "来，只是自顾自的挥剑拒战。小龙女好生奇怪，问道：“过儿，你怎麽不瞧我？”她心中柔情\n"+
                       "渐动，剑光忽长。杨过听了她的语声，心中一震，登时胸口剧痛，剑招稍缓，嗤的一下，衣袖\n"+
                       "已被黑剑划破，小龙女大惊，刷刷刷连攻三剑，阻住公孙止进击。杨过道：“我不能瞧你，也\n"+
                       "不能听你说话。”小龙女软语温柔：“为甚麽？”杨过只怕再遇危险，粗声答道：“你要我死\n"+
                       "，那就跟我说话好了！”他怒气一生，疼痛登止，将公孙止黑剑的招数尽行接过。\n"NOR,me);
    remove_call_out("action6");
    call_out("action6", 1, me);      
}

void action6(object me)
{
  if(!me) return;
  	 message_vision(HIG"便在此时，裘千尺嘶声叫道：“假刀非刀，假剑非剑！”杨过与小龙女听了都是一怔，不明白\n"+
                       "她这两句话的用意。裘千尺又叫：“刀即是刀，剑即是剑！”杨过与公孙止斗了两次，一直在\n"+
                       "潜心思索阴阳倒乱刃法的秘奥所在，但见他挥动轻飘飘的黑剑硬砍硬斫。一柄沉厚重实的锯齿\n"+
                       "金刀却是灵动飞翔，走的全是单剑路子，招数出手与武学至理恰正相反；但若始终以刀作剑，\n"+
                       "以剑作刀，那也罢了，偏生倏忽之间剑法中又显示刀法，而刀招中隐隐含著剑招的杀著，端的\n"+
                       "是变化无方，捉摸不定，此时忽听得裘千尺叫了那十六个字，心道：“难道他刀上的剑招、剑\n"+
                       "上的刀招全是花假？”眼见黑剑横肩砍来，明明是单刀的招数，心中便只当他是柄长剑，君子\n"+
                       "剑挺出，双剑相交，铮的一声，两人各自後退了一步。才知这黑剑底子里果然仍旧是剑，所使\n"+
                       "的刀招只是炫人耳目，但若对方武功稍差，应付失宜，刀招却也能够伤人。\n"NOR,me);

  	remove_call_out("action7");
    call_out("action7", 1, me);      
}

void action7(object me)
{
  if(!me) return;
     message_vision(HIR"十馀招後，杨过又渐落下风，给公孙止逼得不住倒退。裘千尺屡次出言指点，但杨过恼她有意\n"+
                       "损伤小龙女，对她呼叫宛似不闻，暗道：“谁要你来罗唆？”刷刷刷刷四剑，长声吟道：“良\n"+
                       "马既闻，丽服有晖，左揽繁弱，右接忘归。”口中长吟，剑招配合了诗句，挥舞得潇洒有致。\n"+
                       "公孙止一呆，道：“甚麽？”杨过又吟道：“风驰电逝，蹑景追飞。凌厉中原，顾盼生姿。”\n"+
                       "诗句是四字一句，剑招也是四招一组，吟到“风驰电逝，蹑景追飞”时剑去奇速，於“凌厉中\n"+
                       "原，顾盼生姿”这句上却是迅猛之馀，继以飘逸。公孙止从没见过这路剑法，听他吟得好听，\n"+
                       "攻势登缓，凝神捉摸他诗中之意，心知他剑招与诗意相合，只要领会了诗义，便能破其剑法。\n"NOR,me);
  	remove_call_out("action8");
    call_out("action8", 1, me);      
}

void action8(object me)
{
  if(!me) return;
     message_vision(HIG"此时裘千尺又在旁呼喝：“他剑刺右腰，刀劈项颈！”“他剑削右肩，刀守左胁。”竟将公\n"+
                       "孙止每一路招数都先行喝了出来。如此一来，杨过自是有胜无败，他不再长吟，法王便无法知\n"+
                       "他剑大大意。公孙止的阴阳双刃虽系家传武学，但经裘千尺去芜存菁、创新补阙，的整顿过一\n"+
                       "番，斗到酣处，他所使招数自是尽在裘千尺料中，不论如何腾挪变化，总是给她先行叫破。蓦\n"+
                       "听得裘千尺叫道：“他刀剑齐攻你上盘。”这句呼喝时刻拿捏得极是阴毒，恰好公孙止刀剑已\n"+
                       "出，难以中途改变，杨过却有馀裕抵挡。杨过低头疾趋，横剑护背，左指已戳到了对方脐下一\n"+
                       "寸五分处的“气海穴”。杨过一指得手，心中大喜，料想敌人必受重创，岂知公孙止飞出一腿\n"+
                       "，竟向他下颚踢到。\n"NOR,me);

  	remove_call_out("action9");
    call_out("action9", 1, me);      
}

void action9(object me)
{
  if(!me) return;
     message_vision(HIM"裘千尺“哼”了一声，道：“斟两碗茶过来。”绿萼心中烦乱，但依言斟了两碗茶，抢到母亲\n"+
                       "面前。裘千尺举起双手，取下了包在头顶的那块血布。她脑门撞柱流血，小龙女撕下了衣襟替\n"+
                       "她包扎，此时取下包布，头顶又有鲜向流出。绿萼惊道：“妈！”裘千尺道：“死不了！”将\n"+
                       "血布抛在膝头，双手各接一只茶碗，每手四指持碗，拇指却浸入了茶水之中，满指鲜血都混入\n"+
                       "茶内。她随手轻幌，片刻间鲜血便不见痕迹，叫道：“都斗得累了，喝一碗茶再打！”对绿萼\n"+
                       "道：“送茶去给他们解渴，一人一碗。”\n"NOR,me);
  	remove_call_out("action10");
    call_out("action10", 1, me);      
}

void action10(object me)
{
  if(!me) return;
     message_vision(HIG"绿萼知道母亲对父亲怨毒极深，料想她决无这般好心，竟要送茶给他解渴，此举多半会对父亲\n"+
                       "不利，但两碗茶是自己所斟，其中绝无毒药，又是一般无异，想来母亲是体惜杨过，但父亲倘\n"+
                       "若无茶，便决计不肯住手，杨过这碗茶仍是喝不到，眼见两人确是累得狠了，当下走到厅心，\n"+
                       "朗声说道：“请喝茶罢！”\n"NOR,me);
  	remove_call_out("action11");
    call_out("action11", 1, me);      
}

void action11(object me)
{
  if(!me) return;
     message_vision(HIC"公孙止一呆，但觉舌根处隐隐有血腥之味，这一惊当真是非同小可。原来他所练的家传闭穴功\n"+
                       "夫有一项重大禁忌，决不能饮食半点荤腥，否则功夫立破，上代祖宗生怕无意之中沾到，是以\n"+
                       "祖训严令谷中人人不食荤腥，旁人虽然不练这门上乘内功，却也迫得陪著吃素。他向来防备周\n"+
                       "密，那想到裘千尺竟会行此毒计，将自己血液和入茶中？杨过喝一碗血茶自是丝毫无损，公孙\n"+
                       "止毕生苦练的闭穴功却就此付於流水。\n"NOR,me);

  	remove_call_out("action12");
    call_out("action12", 1, me);      
}

void action12(object me)
{
  if(!me) return;
     message_vision(HIR"当杨过与公孙止激斗之际，她早已嘴嚼蜜枣，在口中含了七八颗枣核。眼见公孙止武功大进，\n"+
                       "自己纵然喷出枣核袭击，他也必闪避得了，若是一击不中，给他有了防备，以後便再难相伤，\n"+
                       "因此於他酣斗之馀先用血茶破了他闭穴功夫，乘他怒气勃发之际突发枣核。这是她十馀年潜心\n"+
                       "苦修的唯一武功，劲道之强，准头之确，不轮於天下任何厉害暗器。若不是绿萼突然抢出，挡\n"+
                       "在面前，公孙止不但双目齐瞎，而且眉心穴道中核，登时便送了性命。\n"NOR,me);

  	remove_call_out("action13");
    call_out("action13", 1, me);      
}

void action13(object me)
{
  if(!me) return;
     message_vision(HIG"绿萼心中不忍，呆了一呆，叫道：“爹爹，爹爹！”想要追出去察看。裘千尺厉声道：“你要\n"+
                       "爹爹，便跟他去，永远别再见我。”绿萼愕然停步，左右为难，但想此事毕竟是父亲不对，母\n"+
                       "亲受苦之惨，远胜於他，再者父亲已然远去，要追也追赶不上，当下从门口缓缓回来，垂首不\n"+
                       "语。\n"NOR,me);

 	   message_vision(HIR"公孙止对你叫道：“我马上找人过来帮忙，一转身几个起落就不见了。裘千尺深深地叹了一口\n"+	         
                       "气！裘千尺对你吼道：“刚才弟子樊一翁来报，黄蓉带了大批武林高手来绝情谷，你还不出去\n"+ 
                       "把黄蓉杀了。你听了裘千尺的话吓了一跳，当即退了出去。\n"NOR,me);
 	   me->set_temp("quest/jindaoheijian/yideng",0);
     me->set_temp("quest/jindaoheijian/waityd",1);  
 	   me->move("/d/gumu/jqg/shiwu");
}

