// zhou.c 周伯通

#include <ansi.h>
inherit NPC;
// inherit F_MASTER;  不再收徒
int ask_jieyi();
int ask_xlv();

void create()
{
        set_name("周伯通", ({"zhou botong", "zhou"}));
        set("gender", "男性");
        set("age", 62);
        set("class", "taoist");
        set("nickname",HIY "老顽童" NOR);
        set("long", "他看上去须眉皆白，一副得道模样，然而眼神却透露出一股狡黠。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 31);
        set("int", 36);
        set("con", 32);
        set("dex", 29);
  
        set("qi", 200000);
        set("max_qi", 200000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("eff_jingli", 50000);
        set("jingli", 50000);
        set("neili", 500000);
        set("max_neili", 250000);
        set("jiali", 50);
        set("combat_exp", 10800000);

        set_skill("force", 450);
        set_skill("xiantian-gong", 450);
        set_skill("sword", 450);
        set_skill("quanzhen-jianfa",450);
        set_skill("dodge", 450);
        set_skill("jinyan-gong", 450);
        set_skill("parry", 450);
        set_skill("kongming-quan", 450);
        set_skill("strike", 450);
        set_skill("haotian-zhang", 450);
        set_skill("dafumo-quan", 400);
        set_skill("jiuyin-zhengong", 400);
        set_skill("jiuyin-shenfa", 400);
        set_skill("jiuyin-shenzhua", 450);
        set_skill("daode-jing", 450);
        set_skill("claw", 450);
        set_skill("cuff", 450);
        set_skill("literate", 200);
        set_skill("taoism", 200);
        set_skill("tiangang-beidouzhen", 200);
        set("double_attack",1);
        set("quest/jiebai/pass",1);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "kongming-quan");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "kongming-quan");
        prepare_skill("cuff", "kongming-quan");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.shuangjue" :),
                (: exert_function, "yiyang" :),
                (: exert_function, "wuqi" :),

        }));

        create_family("全真教", 1, "掌教");
        set("title", "全真教重阳真人师弟");

        set("book_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
                "九阴真经" : "嘿嘿嘿嘿...",
                "段皇爷" : "段... 段皇爷？人家是皇爷，我不认识！",
                "瑛姑"   : "你，你说啥？",
                "刘瑛"   : "嗯...嗯...嗯？",
//                "结拜": (: ask_jieyi :),
                "小龙女": (: ask_xlv :),

        ]));

        setup();

        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}
/*

void attempt_apprentice(object ob)
{
      if(ob->query_skill("xiantian-gong",1) < 200 ||
         ob->query_skill("taoism",1) < 200 ||
         ob->query("shen")<1000000){
        command("say 你的武功、道学心法、正神条件还不够，再回去练练吧。");
        return;
        }
        if(ob->query("int") >=26 ||
         ob->query("pur",1) < 26 ){
command("shake");        
command("say 你心地鬼的很，保不准你打什么主意呢，我可不敢收。");
        return;
        }



     command("say 看你资质不错！我就收下你这个徒弟了，你以后要天天陪我玩玩噢。");        
     command("say 好吧，贫道就收下你了。");
     command("recruit " + ob->query("id"));
     ob->set("title", HIC"老顽童周伯通亲传弟子"NOR);
     ob->set("class","taoism");
}
*/
int ask_jieyi()
{
	object ob=this_player();
	/*
	if (!ob->query("family/family_name")  == "全真教") {
		command("draw " + ob->query("id"));
		command("say 你是谁？");
	}
*/
	if (ob->query("quest/jiebai/pass")) {
		command("? " + ob->query("id"));
		command("say 咱们不是已经结拜过了吗？");
		return 1;
	}

	if(ob->query("quest/jiebai/time") && time()-ob->query("quest/jiebai/time")<86400)
	{
	  command("shake "+ob->query("id"));
	  command("say 今天你已经问过了，明天再说。");
	  return 1;
  }
	if(ob->query("quest/jiebai/combat_exp") && ob->query("combat_exp")-ob->query("quest/jiebai/combat_exp")<100000)
	{
	  command("look "+ob->query("id"));
	  command("say 以你当前的经验恐怕还是难以领悟，还是抓紧去练功去吧。");
	  return 1;
  }


	if ( ob->query("int") > 25) {
		command("shake");
		command("say 你这个人鬼灵精，保不准打着什么主意呢。");
		return 1;
	}
	if ( ob->query("shen") <= -1) {
		command("shake");
		command("say 我虽然天性随便，但师尊教诲不敢忘，于正邪之道还是要分清的。");
		return 1;
	}
	if ( ob->query("combat_exp") < 1000000) {
		command("shake "+ ob->query("id"));
		command("say 这位"+RANK_D->query_respect(ob)+"你的武艺实在太糟糕了，我可没兴趣和你结拜。");
		return 1;
	}
	if (random(ob->query("kar")) < 18 || random(ob->query_int(1)) < 25){
		command("shake");
		command("say 我现在没有空，要不你先陪我玩玩？");
		ob->add("quest/jiebai/fail", 1);
		ob->set("quest/jiebai/time",time());
    ob->set("quest/jiebai/combat_exp",ob->query("combat_exp"));
		log_file("quest/jiebai",
			sprintf("%-18s想与周伯通结拜，失败%s次。\n",
				ob->name(1)+"("+capitalize(getuid(ob))+")",
				chinese_number(ob->query("quest/jiebai/fail")) 
			), ob
		);
		return 1;
	}

	command("nod " + ob->query("id"));
	if (ob->query("gender") == "男性") {
		command("say 好吧，你我就结拜为兄弟吧。");
	}
	else if (ob->query("gender") == "女性") {
		if (ob->query("age") > 48)
			command("say 好吧，你我就结拜为姐弟吧。");
		else
			command("say 好吧，你我就结拜为兄妹吧。");
	}
	message_vision("周伯通与$N并肩而跪，朗声说道：“老顽童周伯通，今日与" + ob->name(1) +"义结金兰，日后有福共享，有难共当。\n"+
			"若是违此盟誓，教我武功全失，连小狗小猫也打不过。”\n", ob);
	log_file("quest/jiebai",
		sprintf("%-18s失败%s次后，成功与周伯通结拜，福：%d，悟：%d。\n",
			ob->name(1)+"("+capitalize(getuid(ob))+")",
			chinese_number(ob->query("quest/jiebai/fail")), 
			ob->query("kar"), 
			ob->query_int(1)
		), ob
	);
	ob->set("quest/jiebai/pass", 1);
	ob->set_skill("kongming-quan",15);
	return 1;
}



int accept_object(object me, object ob)
 {
    if( ob->query("id") == "yufeng zhen" && me->query("family/family_name")=="古墓派") {
       command("ah ");
       command("say 一定是龙姑娘让你来找我的吧。 ");
       command("say 当年我被金轮法王的毒蛛咬中，多亏这小小的金针解毒。 ");
       me->set_temp("marks/yufengzhen",1);
             call_out("destructing", 1, ob); 
                return 1; 
            }
  
    else {
       command("hmm ");
       command("say 你拿着这样的东西给我有什么用？ \n");

            return 0;
           }
    return 1;
 } 

int ask_xlv()
{
	object me=this_player();


	command("tsk ");
	command("say 龙姑娘和杨过两个小家伙可了不得，真是一对神仙眷侣。");
 
if( me->query_temp("marks/yufengzhen") && !me->query("gmhb") )
{
	message_vision(HIY"周伯通一听你问起小龙女的事情，不由得眉飞色舞。\n"+
			"周伯通给你讲起当年他和小龙女被金轮法王的毒蜘蛛困在山洞之中，小龙女\n"+
    	"学会左右互博，一手全真剑一手玉女剑打的金轮法王落荒而逃，说到精彩之处，\n"+
    	"不由得手舞足蹈，口沫四溅。\n"+
    "周伯通盯着你看了看，饶有兴趣的问道：“不知道龙姑娘有没有教你这门功夫？”\n"NOR, me);
    me->set_temp("marks/askzhou",1);
    me->delete_temp("marks/yufengzhen");
}
	return 1;

}
