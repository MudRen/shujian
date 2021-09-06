// /d/thd/npc/huangrong.c
// Modified by action@sj
//射雕英雄传第28回

#include <ansi.h>
inherit NPC;
#include "nadir.c"
#include "thdjob.h"

int ask_husband();
int ask_shouhuan();
int ask_jiuyin();
int ask_job_s();
int ask_job();
int ask_job_time();
int ask_quest();
int ask_book();
int ask_qqzhang();
int ask_qqchi();

void create()
{
	set_name("黄蓉", ({ "huang rong", "huang", "rong" }));
	set("long",
			"她方当韶龄，不过十五六岁年纪，肌肤胜雪，娇美无比，容色绝丽，不可逼视。\n"
			"她长发披肩，全身白衣，头发上束了一条金带，灿然生光。一身装束犹如仙女一般。\n");
	set("gender", "女性");
	set("rank_info/rude", "小妖女");
	set("age", 16);
	set("attitude","peaceful");
	set("str", 16);
	set("dex", 26);
	set("con", 18);
	set("int", 30);
	set("per", 50);
	set("shen_type", 0);

	set("tu", 1);
	set("shu", 1);
	set("shouhuan",1);

	set("jiali",50);
	set_skill("force", 200);
	set_skill("huntian-qigong", 200);
	set_skill("bihai-chaosheng", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("luoying-zhang", 200);
	set_skill("hand", 200);
	set_skill("lanhua-shou", 200);
	set_skill("finger", 200);
	set_skill("tanzhi-shentong", 200);
	set_skill("sword", 200);
	set_skill("yuxiao-jian", 200);
	set_skill("literate",500);
	set_skill("qimen-bagua", 500);
	set_skill("bangjue",200);
	set_skill("dagou-bang",200);
	set_skill("stick",200);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "luoying-zhang");
	map_skill("hand", "lanhua-shou");
	map_skill("finger", "tanzhi-shentong");
	map_skill("parry", "dagou-bang");
	map_skill("sword", "yuxiao-jian");
	map_skill("stick", "dagou-bang");
	prepare_skill("hand", "lanhua-shou");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.ban" :),
		(: perform_action, "stick.yin" :),
		(: perform_action, "stick.chuo" :),
		(: perform_action, "stick.chan" :),
		(: perform_action, "stick.wugou" :),
		(: exert_function, "huntian" :),
	}));

	set("combat_exp", 2500000);
	set("max_qi", 5000);
	set("max_jing", 4000);
	set("neili", 7500);
	set("max_jingli", 8500);
	set("eff_jingli", 8500);
	set("max_neili", 8500);

	set("inquiry", ([
		"name" : "在下黄蓉，是桃花岛主的女儿。",
		"rumors" : "我爹爹在这里布了一个八卦阵，必须精通八卦的卦象才能通过。",
		"here" : "这里就是桃花岛了。寒雨那个小坏蛋在这里加了无数的ｑｕｅｓｔ，看你能不能找全了。",
		"郭靖" : "靖哥哥虽然有点傻乎乎的，对我却是真心的。",
		"黄蓉" : "你找我有什么事吗？",
		"黄药师" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
		"爹爹" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
		"东邪" : "我爹爹聪明绝顶，文才武学，书画琴棋，算数韬略，医卜星相，奇门五行，无一不精。",
		"周伯通" : (: ask_jiuyin :),
		"八卦阵" : "是爹爹按八卦的卦象排的，不同的方向表示爻的变化与否，每三爻为一卦，八卦按顺序都走对就过阵了。",
		"爻" : "这也不知道？我没法帮你了。",
		"丈夫" : (: ask_husband :),
		"手环" : (: ask_shouhuan :),
		"夫君" : (: ask_husband :),
		"寒雨": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
		"jpei": "说起来也是他创造了我，不过这家伙是个造ｑｕｅｓｔ狂。",
// here add thd-job "ask huang" by Numa 19990911
		"师母": (: ask_job_s :),
		"守墓": (: ask_job :),
// ask job times by Numa 19991005
		"功劳": (: ask_job_time :),
// add for taohua quest
		"梅超风": (: ask_quest :),
		"陈玄风": (: ask_quest :),
// for hetu/luoshu
		"奇门八卦": (: ask_book :),
		"裘千丈": (: ask_qqzhang :),
		"裘千尺": (: ask_qqchi :),
//		"裘千仞": (: ask_qqren :),
	]) );

//here set do job's number
	set("thd/havejob",1);

	setup();

	carry_object(__THD__"obj/gold_ribbon.c")->wear();
	carry_object("/d/city/obj/necklace.c")->wear();
	carry_object(__THD__"obj/white_cloth.c")->wear();
	carry_object(__THD__"obj/gold_belt.c")->wear();
	carry_object("/d/city/obj/goldring.c")->wear();
	carry_object("/clone/weapon/zhubang")->wield();
}

void reset()
{
	set("tu", 1);
	set("shu", 1);
	set("shouhuan",1);
}

int ask_jiuyin()
{
	object me= this_player();
	if (me->query_temp("jyquest")!=1) {
		command("say 不知道他现在怎么了。");
		command("consider");
		return 1;
	}

	command("say 他好像是被爹爹关在岛上，不知道为什么。");
	command("say 我天天都给他送饭，不过今天爹爹要我好好练些奇门算数。");
	command("angry");
	command("say 这样吧，你帮我送去可好？");
	message_vision(HIY"黄蓉给$N一个饭盒。\n"NOR,me);
	me->set_temp("jyquest",2);
	new(__THD__"obj/fanhe")->move(me);
	return 1;
}

int ask_shouhuan()
{
	object me= this_player();
	if (me->query("family/family_name")!= "桃花岛") {
		command("say 你又不是我桃花岛弟子，跑这里来瞎嚷嚷什么？");
		return 1;
	}
	if( present("yin shouhuan", me)) {
		command("angry");
		command("say 已经给你啦！");
	}
	if(query("shouhuan") < 1)
		return notify_fail("手环已经被人拿走了。\n");

	if(me->query("job_time/桃花岛") < 300) {
		command("say 你不多帮忙，我才不给你。");
		return 1;
	}
	command("say 好吧，看在你平常帮我不少忙，就给你了吧。\n");
	new("/d/thd/obj/shouhuan")->move(me);
	add("shouhuan",-1);
	return 1;
}

int ask_husband()
{
	object nvxu, user;
	object ob = this_player();
	string id;
	int user_load = 0;

	if (!(nvxu = find_object("/clone/npc/huang-son-in-law")))
		nvxu = load_object("/clone/npc/huang-son-in-law");
	id = nvxu->query("winner");
	if (!id)
		id = "";
	if (id == ob->query("id")) {
		if (nvxu->query("death_count") < ob->query("death_count"))
			say("黄蓉低下头，弄着衣角，什么话也不说。\n");
		else
			message_vision(CYN"黄蓉含情脉脉地看着$N，眼光娇羞无限。\n"NOR, ob);
	}
	else {
		if (!(user = find_player(id))) {
			user = new(LOADUSER_OB, id);
			if (!user->restore()) {
				say("黄蓉低下头，弄着衣角，什么话也不说。\n");
				destruct(user);
				return 1;
			}
			user_load = 1;
		}
		if (nvxu->query("death_count") < user->query("death_count"))
			say("黄蓉低下头，弄着衣角，什么话也不说。\n");
		else
			command("say 我的丈夫就是" + nvxu->query("name") + "！");
		if (user_load) destruct(user);
	}
	return 1;
}

int ask_job_time()
{
	object me = this_player();
	int i;

	if (me->query("family/family_name")!= "桃花岛") {
		command("say 你又不是我桃花岛弟子，跑这里来瞎嚷嚷什么？");
		return 1;
	}
	if(!intp(i = me->query("job_time/桃花岛")) || i<=1 ) {
		command("say 你好象从来没守过墓吧?");
		return 1;
	}
	message_vision("黄蓉点了点头对着$N说道：你已为我桃花岛成功守墓" + chinese_number(i) + "次。\n",me);
	command("addoil " + me->query("id"));
	return 1;
}

int ask_book()
{
	object me = this_player();
	object book;
	int i = random(20) + 1;

	if(me->query("potential") < i)
		return notify_fail("你的潜能不够了。\n");

	if(me->query("job_time/桃花岛") < 200) {
		command("say 你没帮忙我做过事吧？");
		command("hehe");
		return 1;
	}

	if((present("he tu", me)||present("luo shu", me)) && (me->query_skill("qimen-bagua",1) < 200)) {
		command("say 我就指点你一点奇门八卦的技巧吧。");
		message_vision(HIW"黄蓉指导了$N一点河图、洛书的奇门之学。\n"NOR,me);
		me->improve_skill("qimen-bagua", random(me->query_int())* i);
		me->add("potential", -i);
		if(me->query("job_time/桃花岛") < 0)
			me->set("job_time/桃花岛",0);
		return 1;
	}

	if (me->query("family/family_name")!= "桃花岛") {
		command("say 你又不是我桃花岛弟子，跑这里来瞎嚷嚷什么？");
		return 1;
	}

	if ((me->query("job_time/桃花岛")<200) && (me->query("thd/finish")<1)) {
		command("say 你帮我多做些事，我才要借你书。");
		command("xixi");
		return 1;
	}
	if((me->query_skill("qimen-bagua",1)<120) && (query("tu")>0)) {
		book = unew("/d/thd/obj/hetu");
		if (book) {
			command("say 好吧，这本河图你拿去好好研读吧。");
			book->move(me);
			add("tu",-1);
		} else {
			command("say 书已经不在我这了。");
			command("sorry");
		}
		return 1;
	}
	if( me->query_skill("qimen-bagua",1) > 100
	 && query("shu") > 0 ) {
		book = unew("/d/thd/obj/luoshu");
		if (book) {
			command("say 好吧，这本洛书你拿去好好研读吧。");
			book->move(me);
			add("shu",-1);
		} else {
			command("say 书已经不在我这了。");
			command("sorry");
		}
		return 1;
	}
	command("say 我现在没那种心情，别吵我啦。");
	command("yawn");
	return 1;
}

int ask_quest()
{
	object me = this_player();

	if (me->query("family/family_name")!= "桃花岛")	{
		command("say 你又不是我桃花岛弟子，跑这里来瞎嚷嚷什么？");
		return 1;
	}
	if (me->query_temp("thd/onquest")==0)	{
		command("say 他们本来是爹爹的徒弟......你还是自己去问爹吧。");
		command("consider");
		return 1;
	}
	if (me->query_temp("thd/onquest")==2)	{
		command("say 他们武功高强，你要小心了！");
		command("fear");
		return 1;
	}
	command("ah");
	command("say 我这儿有把匕首，你拿去防身....有危险时，就抽(chou)出来吧。");
	message_vision(HIY"$N小心翼翼地把匕首插在靴子。\n"NOR, me);
	command("say 这上面有靖哥哥的名字，可别弄掉了。");
	command("blush");
	me->set_temp("thd/onquest",2);
	return 1;
}

int ask_qqzhang()
{
	      object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong")!=1) {
		 command("say 20多年了不怎么记得了，你问这个干什么。");
		 command("consider");
		  return 1;
	}
	   command("say 当年裘千丈把我和靖哥哥骗的好苦啊。不过裘千丈铁掌峰偷袭我，失足掉入山崖。");
	   message_vision(WHT"\n黄蓉颜色凝重，慢慢回忆当年发生铁掌峰的经历!\n"NOR,me); 
	   command("sigh");
     message_vision(HIC"郭靖立时省悟：“他们不敢进入禁地，便使火攻。山洞中无着火之物，不致焚毁，可是咱们三\n"+     
        	             "个却要活活的给烤成焦炭了急忙回身抱起黄蓉，只听裘千丈躺在地下破口大骂，于是在他腰眼\n"+
        	             "里轻轻踢了两脚，解开他的穴道，让他自行逃走，将木盒和两本册子揣在怀里，不敢逗留径往\n"+
        	             "峰顶爬去。那石穴是在中指峰的第二指节，离峰顶尚有数十丈之遥。郭靖凝神提气，片刻之间\n"+        	                      
        	             "攀登峰顶。裘千丈也跟着一步步的挨上来。郭靖回头向下望去，见火焰正缓缓烧上，虽然一时\n"+
        	             "不致便到但终究是难以脱身，不由得长叹一声。黄蓉忽道：“岳武穆王名飞，字鹏举，咱们来\n"+
        	             "个雕举，好不好？”。郭靖问道：“甚么雕举？”黄蓉道：“叫雕儿负了咱们飞下去啊。”一\n"+
        	             "听此言，郭靖喜得跳起身来，叫道：“那当真好玩得紧。我唤雕儿上来。只不知雕儿有没这个\n"+
        	             "力气。”。黄蓉叹道：“反正是死，也只得冒险一试了。”郭靖当下盘膝坐定，凝聚中气，在\n"+
        	             "丹田盘旋片刻，然后从喉间一吐而出，啸声远远传了出去，”这正是马钰当年授他的全真派玄\n"+
        	             "门内功，他修习《九阴真经》之后，功力更是精进。”这中指峰自峰顶至峰脚相距何止数里，\n"+
        	             "但啸声发出，过不多时便白影临空，双雕在月光下御风而至，停在二人面前。”郭靖替黄蓉解\n"+
        	             "下身上软猬甲，扶她伏在雌雕背上，怕她伤后无力扶持，”用衣带将她身子与雕身缚住，然后\n"+
        	             "自己伏上雄雕之背，搂住雕颈，口中一声呼啸，双雕振翅而起。”两人斗然凭虚临空，但双雕\n"+
        	             "一飞离地，立感平稳异常。郭靖初时还怕自己身子重，”那雕儿未必负荷得起，岂知那白雕双\n"+
        	             "翅展开，竟然并无急堕之像。”黄蓉究是小孩心性，心想这是天下奇观，可得让裘千丈那老儿\n"+
        	             "瞧个仔细，于是轻拉雕颈，要它飞向裘千丈身旁。”雌雕依命飞近。裘千丈正自慌乱，眼见之\n"+
        	             "下，不禁又惊又羡，叫道：“好姑娘，也带我走罢。”大火便要烧上来，老儿可活不成啦！”\n"+
        	             "黄蓉笑道：“我这雕儿负不起两人。你求你弟弟救你，不就成啦？”你比他多三千尺，他非听\n"+
        	             "你号令不可。”轻拍雕颈，转身飞开。”裘千丈大急，叫道：“好姑娘，你瞧我这玩意儿有趣\n"+
        	             "不？””黄蓉好奇心起，拉雕回头，要瞧瞧他有甚么玩意。哪知裘千丈突然和身向前猛扑，”\n"+
        	             "飞离山峰，向黄蓉背上抱去。他深知若是冲下峰去，纵能脱出火圈，但私入禁地，犯了帮中严\n"+
        	             "规，莫说是帮主的兄弟，”纵是帮主本人，也未必能够活命，这时便想再深入石洞避火，来路\n"+
        	             "也被大火阻断，”是以不顾一切的要抢上雕背逃走。那白雕虽然神骏，究竟负不起两人，黄蓉\n"+
        	             "被裘千丈一抱住，”白雕立时向峰下深谷急落。那雕双翅用力扑打，始终支持不住。”裘千丈\n"+
        	             "抓住黄蓉后心，用力要将她摔下雕背，但她身子用衣带缚在雕上，急切间摔她不下。”黄蓉手\n"+
        	             "足被缚，也是难以回手。眼见二人一雕都要摔入深谷，粉身碎骨。”铁掌帮帮众站在山腰看得\n"+
        	             "明白，个个骇得目瞪口呆，做声不得。”正危急间，那雄雕负着郭靖疾扑而至，钢喙啄去，正\n"+
        	             "中裘千丈顶门。”那老儿斗然间头顶剧痛，伸手抵挡，就只这么一松手，已一连串的筋斗翻将\n"+
        	             "下去，”长声惨呼从山谷下传将上来。雌雕背上斗轻，纵吭欢唳，振翅直上。双雕负着二人，\n"+
        	             "比翼北去。\n"NOR,me);
	   me->delete_temp("quest/jindaoheijian/huangrong");
	   me->set_temp("quest/jindaoheijian/huangrong2",1);
	    return 1;
}

int ask_qqchi()
{
	object me= this_player();
	if (me->query_temp("quest/jindaoheijian/huangrong2")!=1) {
		command("say 没听说过。");
		command("@@");
		return 1;
	}

	command("say 没想到裘千丈、裘千仞还有个妹妹。不过当年发生的事也不能怪我们，若非裘千丈袭击我们，被白雕啄掉下山谷。");
	message_vision(WHT"\n你将在绝情谷遇见裘千尺以及找黄蓉复仇的事情告诉黄蓉！\n"NOR,me); 
	command("disapp");
	command("consider");
	command("say 这位大侠能帮我一个忙吗，我想你帮我去一趟桃园县找一灯大师，希望他能带裘千仞去劝解他的妹妹来化解恩怨。");
	command("say 哎！冤冤相报何时能了！");
	me->delete_temp("quest/jindaoheijian/huangrong2");
	me->set_temp("quest/jindaoheijian/huangrong3",1);
	return 1;
}