// NPC: /d/huashan/npc/yuebuqun.c
// Date: Look 99/03/25
// Modify by Looklove 2000,12,15
// By Spdierii@ty 重要npc.杀不死
// by lsxk@hsbbs  统一奖励算法 2007/1/10

inherit NPC;
inherit F_MASTER;

#include <job_mul.h>
#include <ansi.h>
string ask_zhengqi();
string ask_zixia();
string ask_me1();
string ask_me2();
string ask_pay();
string ask_fail();
string ask_qizong();

void create()
{
	set_name("岳不群",({"yue buqun", "yue", "buqun" }));
	set("title","华山派第十三代掌门人");
	set("nickname","君子剑");
	set("long", "这就是在江湖中侠名远播，疾恶如仇，华山派掌门人。\n");
	set("age", 40);
	set("attitude", "friendly");
	set("no_bark",1);
	set("shen_type", 1);
	set("job_npc", 1);
	set("no_get", 1);

	set("per", 25);
	set("pur", 10);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi",3800);
	set("qi", 3800);
	set("max_jing", 2400);
	set("jing",2400);
	set("eff_jingli", 2700);
	set("jingli", 2700);
	set("max_neili", 5500);
	set("neili", 5500);
	set("jiali", 50);
	set("combat_exp", 2400000);
	set("score", 30000);
	set("chat_chance_combat",100);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yangwu" :),
		(: perform_action, "sword.feijian" :),
		(: perform_action, "sword.junzi" :),
		(: exert_function, "zixia" :),
		(: perform_action, "sword.kuaijian" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "sword.sanqing" :),
		(: perform_action, "cuff.leidong" :),
		(: exert_function, "zixia" :),
	}));

	set_skill("poyu-quan", 180);
	set_skill("cuff", 180);
	set_skill("sword",  180);
	set_skill("dodge",  180);
	set_skill("force",  180);
	set_skill("parry",  180);
	set_skill("literate",100);
        set_skill("zixia-gong", 380);
        set_skill("huashan-qigong", 180);
   set_skill("huashan-qigong", 180);
	set_skill("huashan-jianfa",  180);
	set_skill("huashan-shenfa",  180);
	set_skill("zhengqi-jue", 180);
    set_skill("hunyuan-zhang", 180);
    set_skill("strike", 180);
    map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");
	map_skill("force","zixia-gong");
	map_skill("sword","huashan-jianfa");
	map_skill("parry","huashan-jianfa");
	map_skill("cuff","poyu-quan");
	prepare_skill("cuff","poyu-quan");
	create_family("华山派",13,"掌门");

	set("inquiry", ([
		"紫霞秘籍"	: (: ask_zixia :),
		"zixia"		: (: ask_zixia :),
		"miji"		: (: ask_zixia :),
		"失败"		: (: ask_fail :),
		"fail"		: (: ask_fail :),
		"惩恶扬善"	: (: ask_me1 :),
		"job"		: (: ask_me1 :),
		"复命"		: (: ask_me2 :),
		"完成"		: (: ask_me2 :),
		"finish"	: (: ask_me2 :),
		"正气诀"	: (: ask_zhengqi :),
		"zhengqi-jue"	: (: ask_zhengqi :),
//                   "剑气之争"      : (: ask_qizong :),
	]));

	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}

void heart_beat()
{
	::heart_beat();

	clear_conditions_by_type("poison");
	if( !is_fighting() && living(this_object()))
		reincarnate();
}

void init()
{
	object ob;
	::init();
	ob = this_player();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	int shen;
	if(!me) return;

	if ( file_name(environment(this_object())) != this_object()->query("startroom")) return;

	shen = me->query("shen");
        if(shen <= -200000 && me->query("family/family_name") == "华山派" && me->query("quest/huashan")=="气宗"){
		command("disapp "+me->query("id"));
		command("say 你满眼瘴气，身带邪气，从今天起你不再是华山弟子了！");
 command("expell " + me->query("id"));
me->delete("quest/huashan","气宗");
	}
	if(shen <0 && shen > -200000 && me->query("family/family_name") == "华山派"){
		command("sigh "+me->query("id"));
		command("say 我看你满眼瘴气，身带邪气，最近是不是在外面做了什么坏事？");
		command("say 如果被我查到你做过有辱我华山声名的事，我定不饶你！");
	}
}

void attempt_apprentice(object ob)
{
	mapping fam;
	if ( mapp(fam=ob->query("family"))
	 && (string)fam["family_name"] != "华山派"
	 && (int)ob->query("is/huashan")==1 ) {
		message_vision(CYN "$N！你这个华山派的叛徒还回来干什么 ？？？\n"NOR, ob );
		command("kick "+ob->query("id"));
		return;
	}
if ( ob->query("fengset") && !ob->query("relife/relifed")) {
		command("say 你不是已经拜了剑宗的前辈为师了么？");
		return;
	}
/*
        if(ob->query("quest/huashan")=="剑宗"){
    command("heng");
    command("say 哼哼！剑宗弟子早已离开华山，不再是华山派弟子，你又来这里，难道是想争夺这掌门之位？");
    return;
        }
*/

	if ( ob->query("gender") != "男性" ){
		command("say 我只收男徒，" + RANK_D->query_respect(ob) + "请回吧。");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return;
	}
	command("say 好吧，我就收下你了,你可要为我们华山派争口气。");
	command("recruit " + ob->query("id"));
	ob->set("title",HIW"华山派气宗亲传弟子"NOR);
  ob->set("quest/huashan","气宗");
}

string ask_qizong()
{
    object me;
    mapping fam;
    me=this_player();

   if ( mapp(fam=me->query("family"))
    && (string)fam["family_name"] != "华山派"){
    command("? "+me->query("id"));
    return "这为" + RANK_D->query_respect(me) + "哪里听来的谣传？\n";
    }

   if (me->query("quest/huashan")=="气宗")
       return "当年剑气之争，牺牲了数名华山好手，你可要好好修炼，光大华山派啊！\n";

   if (me->query("quest/huashan")=="剑宗")
       return "哼哼！剑宗弟子早已离开华山，不再是华山派弟子，你又来这里，难道是想争夺这掌门之位？\n";

   if ((int)me->query("combat_exp")<1000000)
       return "哎。。华山派不幸啊，这些陈年旧事你还提他做甚？\n";

   if(me->query_temp("quest/huashan/asked")){
       add_action("do_choose","answer");
       return "怎么？还想让我重复说一便？你当听童话故事啊？";
   }
   command("say 我华山派的确有剑气之分，当年华山玉女峰一战，同门兄弟却相互撕杀，惨不忍睹啊！");
   command("cry "+me->query("id"));
   command("say 我气宗弟子乃讲究“以气驭剑”，正所谓真气所至，草木皆为利剑。气为重，剑为辅！\n"+
   "内功一旦有成，剑招威力自然非同一日而语。再加上本派享誉江湖的“紫霞神功”，\n"+
   "练剑数十载，岂是那些只会花俏剑招，内功平平的剑宗弟子可比的？");

   add_action("do_choose","answer");
   me->set_temp("quest/huashan/asked",1);
   return me->name(1)+"，你可要从本门气功开始修炼，循序而进才行啊！";
}

int do_choose(string arg)
{
    object me=this_player();
    if(!me->query_temp("quest/huashan/asked")) return 0;

    if(!arg) return notify_fail("你想回答什么？\n");

    if(arg!="是" && arg !="yes") return notify_fail("请回答“是”来表示赞同看法！\n");
    if(arg=="是" && !me->query("quest/huashan")){
        me->set("quest/huashan","气宗");
        message_vision(HIM"$N点了点头，连声称“是，师傅！”\n"NOR,me);
        return 1;
    }
    return 0;
}

string ask_me1()
{
	int i;
	object ob, me, name1, ling;
	me=this_player();
	ob = this_object();
	ling = present("ling pai", me);
	name1 = me->query("id");
	i = me->query("shen");
if(me->query_temp("mb")) 
           return "你还是先去思过崖面壁思过去吧。 ";
	if (!wizardp(me) && me->query("shen") < 10000)
		return "你眼露凶光, 还想去惩恶扬善? ";

	if (!wizardp(me) && me->query_temp("hs/jobji"))
		return "你不能光说呀，倒是做出点成绩给我看看！\n";

	if (!wizardp(me) && (int)me->query("combat_exp") < 100000)
		return "你武功未成，这么危险的任务还是别做了！\n";

	if (me->query("job_name") == "惩恶扬善" && !wizardp(me))
		return "现在没有听说有恶人为害百姓，你自己去修习武功去吧！";

	if(!wizardp(me) && me->query_condition("job_busy"))
		return "你现在正忙着做其他任务呢！";

	if(me->query_temp("quest/busy")) //added by tangfeng 与quest冲突
		return "现在我这里没有给你的任务，你还是先处理好你其他事情再说吧。";


	ob = new(__DIR__"obj/ling");
	ob->set("ever_owner",getuid(me));
	me->set_temp("hs/jobji",1);
	command("nod "+me->query("id"));
	ob->move(me);
	ob->set_temp("hsjob", name1);
	me->apply_condition("hs_job", 30 + random(5));
	me->apply_condition("job_busy", 30);
	me->set_temp("hs_time", uptime());
	tell_object(me, "岳不群给了你一块令牌。\n");
	return "听说现在华山附近经常出现一些恶贼，骚扰百姓，你去巡视一下，遇到恶人不可手软。\n";
}

string ask_zhengqi()
{
	mapping fam;
	object me, ob;
	int shen, exp, i;
	me = this_player();
	ob = this_object();
	shen = (int)me->query("shen", 1);
	exp = (int)me->query("combat_exp", 1);
	i = (shen - exp);
	fam = me->query("family");

	if (!fam || fam["family_name"] !="华山派")
		return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？\n";
	if( i < 1000 )
		return "你的侠义之气不够，如何叫我指点你的正气诀？\n";
	if( (int)me->query_skill("zhengqi-jue", 1) < 150 )
		return "你的正气诀未到火候，恐怕我无法指点你。\n";
	if( (int)me->query_skill("zhengqi-jue", 1) >= 200 )
		return "你的正气诀已到火候，恐怕我无法指点你。";
	if( (int)me->query("jing", 1) < 100 )
		return "你现在身体状况太差了，你无法领悟正气诀的绝妙之处。\n";
	if( (int)me->query("potential", 1) < 2 )
		return "你现在潜能不足，我无法指点你关于正气诀。\n";
	me->improve_skill("zhengqi-jue", 100 + random(100));
	me->add("shen", -1000);
	me->add("potential", -1);
	me->receive_damage("jing", random(100));
	tell_object(me, HIC"你感到心中激荡着侠义正气。\n"NOR);
	return  "好吧，既然你问起我正气诀，我就指点你一下。\n" ;
}

string ask_me2()
{
	return "你的令牌呢？";
}

int accept_object(object me, object ling)
{
	object name1;
	int getshen, total_job_times, done,gold,gold2,total_job_times2, tb,i,j ;
object* ppl;	
name1 = me->query("id");



	if( ling->query("id") != "ling pai")
		return notify_fail("岳不群说道：惭愧呀，华山派居然出了你这样的骗子！\n");
	if( ling->query_temp("mmr") != name1 && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/华山",1));
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("岳不群说道：你怎么这么没用？没敢去找到恶贼？\n");
	}
	if( ling->query_temp("hsjob") != name1 && !wizardp(me)) {
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/华山",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("岳不群说道：这是你的令牌么？\n");
	}
	done = (int)ling->query_temp("done", 1);
	if( done < 2 && !(done==1 && me->query_temp("hs/robot")) )
		return notify_fail("岳不群说道：你还没完成师傅的任务呢。\n");
	if ( !me->query_temp("hs/jobji") && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/华山",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("岳不群说道：你的令牌从哪里偷来的？\n");
	}
	if ( !me->query_condition("hs_job") && !wizardp(me)){
		command("hmm "+ me->query("id"));
		me->add("shen", -(int)me->query("job_time/华山",1) * 5);
		me->delete_temp("hs/jobji");
		me->delete_temp("hs/have");
		me->delete_temp("hs/power");
		me->delete_temp("hs/robot");
		call_out("destroying", 1, ling);
		return notify_fail("岳不群说道：你怎么去了这么长时间？\n");
	}
	write("岳不群看了看你的令牌。\n", me);
	command("thumb "+ me->query("id"));
	command("say 还望" + RANK_D->query_respect(me) + "日后多行善事，必有好报。\n");
   getshen = 1;
	if( me->query("family") && me->query("family/family_name") =="桃花岛") getshen = 0;


   if(done!=2)
       TASKREWARD_D->get_reward(me,"华山",getshen,0,0,random(2)+1,0,0,0,this_object());
   
else 
       TASKREWARD_D->get_reward(me,"华山",getshen,0,0,5-random(2),0,0,0,this_object());

	

	me->delete_temp("hs_time");
	me->clear_condition("hs_job");
	me->clear_condition("job_busy");
	me->set("job_name","惩恶扬善");
              gold= 2000+random(1000);
      
        gold2=gold/5000+random(gold/5000);
              me->add("balance", gold);

	me->delete_temp("hs/jobji");
	me->delete_temp("hs/have");

	me->delete_temp("hs/power");
	me->delete_temp("hs/robot");
	me->delete_temp("mb");
	call_out("destroying", 1, ling);



	// 风清扬 quest 控制
	// 经验值大于 2M 或 华山，送信，丐帮的随机数都大于 400
	// 华山，送信，丐帮次数之和为 50 的倍数
	// 福缘随机数大于 25
	// me->query("mianbi") < me->query("mianbi")/100000 + 1
	// by mxzhao 2004/05/07


	total_job_times = me->query("job_time/华山") + me->query("job_time/送信") + me->query("job_time/丐帮");
	total_job_times2 = me->query("job_time/华山") + me->query("job_time/武当");


if(me->query("family/family_name")=="华山派"&& !me->query("fengset"))
{
ppl=users();
i=sizeof(ppl);

while(i--){
if( userp(ppl[i])&& !wizardp(ppl[i])&&!ppl[i]->query("no_pk")&& ppl[i]->query("fengset"))
        j++;
          }
	if (random(me->query("job_time/华山")) >400
		&& random(me->query("job_time/送信")) >400
                &&( (me->query_temp("sj_credit/quest/hs/jiujian") && random(me->query("kar")) >= 24 )|| random(me->query("kar")) >= 26) 
                &&( random(me->query("job_time/丐帮")) >100 || random(me->query("combat_exp"))>2000000 )
		&& !me->query("fengset")
		&& !me->query_temp("mb")
//              && !me->query("quest/hsjf/fengyi4_time")
		&& (me->query("mianbi") < me->query("combat_exp")/500000 + 1)
		&& total_job_times % 50 == 0 
                && (     ( !me->query("buyvip")&& (j<=9 ||random(j+1)>=j ))  || me->query("buyvip"))
                 ) 
	{
		me->set_temp("mb", time());
		me->add("mianbi", 1);
		log_file("quest/jiujian",sprintf("%8s%-10s第%4d次华山任务时，上思过崖面壁，送信：%4d，丐：%4d，福：%2d，次：%d。\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/华山"), me->query("job_time/送信"),
			me->query("job_time/丐帮"), me->query("kar"), me->query("mianbi")),me);
		command("say "+me->query("name")+"你杀了不少恶人，未免杀气过重不如上思过崖面壁忏悔吧。\n");
	}
}


if (wizardp(me)||random(me->query("job_time/华山")) >400
		&&( random(me->query("job_time/武当")) >400 || random(me->query("combat_exp"))>5000000 )
                && random(me->query("kar")) >= 28
		&& !me->query_temp("mz_entrance")
		&& !me->query("quest/xxdf/pass")
//		&& me->query("family/family_name")=="日月神教"
		&& total_job_times2 % 50 == 0 ) 
	{
		me->set_temp("mz_entrance", 1);
		command("say "+me->query("name")+"，听说魔教教主被关在杭州西湖湖底，你去把他杀了，我就让你入五岳剑派。\n");
		log_file("quest/xixing",sprintf("%8s%-10s华山任务时，去梅庄，华山：%4d，武当：%4d，福：%2d。\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/华山"), 
			me->query("job_time/武当"), me->query("kar")),me);
	}
	return 1;
}

string ask_zixia()
{
	mapping fam;
	object me;
  int time;
	
	me = this_player();
	fam = me->query("family");
 
 time= time()-me->query("quest/zixia/time");
 
	if (!fam || fam["family_name"] !="华山派")
		return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";
	
	
	if((int)me->query_skill("huashan-jianfa", 1) < 451 )
		return "我有意传授于你镇派绝技紫霞功，但你入门尚浅，现在未免为时过早。";

if( me->query_temp("hs/askzixia") || time<86400 )

        return  "我不是告诉你了吗，镇教之宝流落在外，你还不赶紧去找！" ;

	me->set_temp("hs/askzixia",1);
        return  "紫霞秘籍乃我华山至宝，前段时间不知道流落何处了。" ;
}

string ask_fail()
{
	object me,ling;
	me = this_player();
	ling = present("ling pai", me);
	if(! me->query_temp("hs/jobji"))
		return "你又没领过任务，何谓失败啊？";
	if( ling && ling->query_temp("hsjob") == me->query("id"))
		destruct(ling);
	me->delete_temp("hs/jobji");
	me->delete_temp("hs/have");
	me->delete_temp("hs/power");
	me->delete_temp("hs/robot");
	me->clear_condition("hs_job");
	me->apply_condition("job_busy", 3+random(4));
	me->add("combat_exp", -(40+random(30)));
	return "既然如此，也不能勉强，你就先退下吧。";
}

void destroying(object ling)
{
	if (ling) destruct(ling);
}
void die()
{
	object ob;
	if (!query_temp("living"))
	{
		ob = new("/d/huashan/npc/yuebuqun");
		ob->move("/d/huashan/zhengqi");
	}
	::die();
}


