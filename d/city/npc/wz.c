inherit NPC;
#include <ansi.h>

int ask_bagua();
int ask_liwu();
int ask_quanfa();
int ask_jiangli();


void create()
{
        set_name("巫师",({  "wizard", "wushi" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long", "这是一个闪电召唤出来的巫师，偶尔协助闪电做点事，大部分的时间都是无所事事。\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("shen_type", 1);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        setup();

        set("inquiry", ([
              "初出江湖":   (: ask_liwu    :),
     //         "奇门八卦":   (: ask_bagua   :),
     //         "新手武功":   (: ask_quanfa  :),
                "高手进阶":   (: ask_jiangli :),
                "贵宾专享":   (: ask_jiangli :),
            ]) );

        carry_object("/clone/misc/cloth")->wear();
}


int ask_bagua()
{      
       mapping myfam;    
       object me = this_player();
       myfam = (mapping)me->query("family");

       if(!myfam || myfam["family_name"] != "桃花岛")
        {   
           if( !me->query_skill("qimen-bagua") || me->query_skill("qimen-bagua",1) < 50 )         
             { 
               command("say 好吧，我可以教你一点奇门八卦的学问。");
               me->set_skill("qimen-bagua", 52);
               return 1;
              }
           else {
                command("say 你已经够八卦的了！我可教不了你什么东西。");  
                 return 1; 
                  }
         }
         else 
         {    command("kick "+me->query("id"));
              command("say 你不去找你师傅好好学习，想投机取巧啊？");
               return 1; }

}


int ask_quanfa()
{      
       
    object me = this_player(); 
   if( me->query("askwiz_cuff") ) 
       {
          command("say 我不是已经教过你了？");
          return 1;
       }


   if( me->query("combat_exp") < 150000  ) 
       {
          command("say 你的实战经验不足，还是抓紧时间去练功吧。");
          return 1;
       }
   if( me->query("combat_exp") > 150000  ) 
       {
          command("say 你的实战经验不足，还是抓紧时间去练功吧。");
          return 1;
       }

           
   me->set_skill("cuff", 1);
   me->set_skill("yeqiu-quan", 1);

     command("wink");
     command("fullskills "+me->query("id"));

     command("say 江湖行，大不易！我可以给你一点点武功上的指点，不过只有一次机会哦！");
     me->set("askwiz_cuff",1);
 
     tell_object(me, HIG"你得到了巫师的帮助，武功大有长进！\n"NOR);
    return 1;
        
}

int ask_liwu()
{
  
    object me = this_player(); 
   if( me->query("start_liwu") ) 
       {
          command("say 你不是已经领过了？");
          return 1;
       }


   if( me->query("combat_exp") < 1000000  ) 
       {
          command("say 你的实战经验不足，还是抓紧时间去练功吧。");
          return 1;
       }

   if( me->query("combat_exp") >= 1700000  ) 
       {
          command("say 你的功夫已经很不错了，还是自己勤奋练功吧。");
          return 1;
       }


     command("wink");
     command("fullskills "+me->query("id"));
     command("say 您的实战经验终于到1M了，真不容易呀！");

     command("say 感谢您的支持，希望你玩的开心，玩的长久！");
     me->set("start_liwu",1);

     me->add("SJ_Credit",500);
     me->add("balance", 1000000);


     tell_object(me, HIG"你得到了闪电的祝福，获得"+ HIR + chinese_number(500) + CYN +"个「"+HIG+"通宝"+CYN+"」！\n"NOR);
     tell_object(me, HIG"你得到了闪电的祝福，获得 " + MONEY_D->money_str(1000000) + "存款！\n"NOR);


     CHANNEL_D->do_channel(this_object(), "rumor", HIC"听说" + me->name(1) + "从会客室的巫师处获得了一份丰厚的礼物！\n"NOR);
    return 1;
}

int ask_jiangli()
{
  
    object me = this_player(); 

   if(!me->query("buyvip"))  {
          command("consider");
          return 1;
                             }

   if( me->query("combat_exp") < 5000000  ) 
       {
          command("say 你的实战经验不足5M，还是抓紧时间去练功吧。");
          return 1;
       }

   if( me->query("combat_exp") >= 75000000  ) 
       {
          command("say 你的功夫已经很不错了，还是自己勤奋练功吧。");
          return 1;
       }
   if( me->query("5m_jiangli") ) 
       {
          command("say 你不是已经领过了？");
          return 1;
       }
       
       
     command("fullskills "+me->query("id"));
     command("ah");
     command("say 恭喜你跻身江湖顶尖高手的行列！");
     command("say 这是您身为书剑荣誉玩家的独特奖励，谢谢您长久以来的支持和赞助！");
     me->set("5m_jiangli",1);
     me->add("SJ_Credit",2000);
     me->add("balance", 20000000);

     me->set("last_full",1);

     me->add("relife/gifts/now",  2);  
     me->add("relife/gifts/total",  2);  
     me->add("imbue_reward",10);


     tell_object(me, HIC"你得到了闪电的祝福，获得"+ HIR + chinese_number(2000) + HIC +"个「"+HIG+"书剑通宝"+HIC+"」， " + MONEY_D->money_str(20000000) + "存款！\n"NOR);
     tell_object(me, HBBLU"你得到了闪电的祝福，你获得两点可自由分配的参悟天赋点数，请使用addgift指令分配！\n"NOR);  
     tell_object(me, HBBLU"你获得十次额外的打造机会！\n"NOR);   
     me->add("ggs/left_time",1080000);


    tell_object(me, HBBLU"天赋系统开始生效！从下一次登陆开始，你将获得额外的攻防点数，实战中将会产生特殊的效果！\n"NOR);  
 
     CHANNEL_D->do_channel(this_object(), "rumor", HIC"听说" + me->name(1) + "从会客室的巫师处获得了一份贵宾专享的"HIR"高手进阶"HIC"礼物！\n"NOR);
     return 1;     

}

