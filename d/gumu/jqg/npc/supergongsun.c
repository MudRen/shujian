// supergongsun.c 公孙止
// By  2009/2/20
#include <ansi.h>
inherit NPC;
int power_condition(object me,object ob,int p);
int start_condition(object ob);
void kill_player(object me);
void unconcious();
void die();
void kill_ob(object me);

void create()
{
	set_name("公孙止", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","面目英俊，透出轩轩高举之概，只是面色蜡黄，容颜枯槁。\n");
        set("title",HIW"绝情谷谷主"NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
        set("per", 20);
        set("unique", 1);

	set("max_qi", 50000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
  set("eff_jingli", 2000);
	set("jiali", 80);
	set("combat_exp", 10000000);
 
        set_skill("force", 450);      
        set_skill("dodge", 450);
        set_skill("parry", 450);
        set_skill("guiyuan-tunafa", 450);
        set_skill("literate", 120); 
        set_skill("shuishangpiao", 450);
        set_skill("tiezhang-zhangfa", 450);
        set_skill("strike",450);
        set_skill("sword", 450);
	      set_skill("jindao-heijian", 450);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "liangyi-jian");
	      map_skill("sword", "jindao-heijian");
	      map_skill("blade", "jindao-heijian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "绝情丹": "丹药无多，而且也很难炼制，非万不得已。。。",
        ]) );

	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/cloth")->wear();
}
 
void init()
{
	object me = this_player();
	object ob = this_object();
if(me->query_temp("quest/jindaoheijian/zhuigsz"))
  {
	  command("fear "+me->query("id"));
	  command("say 你！你！居然知道我在这里的！看来我只能让你永远消失了在这个世界了。");
	  me->set_temp("quest/jindaoheijian/qqchi",1);
    power_condition(me,this_object(),300+random(100));
	  me->set("kill_id",ob->query("id"));
		call_out("do_kill", 1, me, ob);
  	
  } 
}

int do_kill(object me, object ob)
{
	this_object()->kill_ob(me);
	me->kill_ob(this_object());
	this_object()->start_busy(0);
	this_object()->set("quest/try_fight",1);
  this_object()->set("quest/try_fight_id",me->query("id"));
	call_out("kill_ob", 1, me, ob);
 	return 1;
}

void kill_player(object me)
{
	object ob=this_object();
  if(!me) return;
  if(environment(me)!=environment(this_object())) return;
  if(me->query_temp("quest/jindaoheijian/zhuigsz"))
  {
     if (!present("sword",ob))
	             carry_object(BINGQI_D("sword"))->wield();
	      else command("wield sword");
    return;
  }  	
}

void kill_ob(object me)
{       
	 command("sneer " + me->query("id"));
	 	::kill_ob(me);

}

int power_condition(object me,object ob,int p)
{
	  int i;
    if(environment(me)!=environment(ob)) return 0;
    if (!present("sword",ob))
	    carry_object(BINGQI_D("sword"))->wield();
	    carry_object(BINGQI_D("blade"))->wield();
	  i=me->query("max_pot");
	  if(p<150) p=150;
	  if(i<p) i=p;
	  i=i-100;	  
	  ob->set_skill("force", i+random(50));
	  ob->set_skill("dodge", i+random(50));
	  ob->set_skill("parry", i+random(50));
	  ob->set_skill("blade", i+random(50));
	  ob->set_skill("strike",i+random(50)); 
	  ob->set_skill("sword",i+random(50));
	  ob->set_skill("jindao-heijian",i+random(50));
	  ob->set_skill("guiyuan-tunafa",i+random(50));
	  ob->set_skill("tiezhang-zhangfa",i+random(50));
	  ob->set_skill("shuishangpiao",i+random(50));
	  i=me->query("combat_exp");
	  ob->set("combat_exp",i);
	  i=me->query("neili");	  
	  if(i<12000) i=12000;
	  ob->set("neili", i);	  
	  i=me->query("max_neili");	  
	  if(i<6000) i=6000;
	  ob->set("max_neili", i);	  
  	i=me->query("max_qi");	  
	  ob->set("max_qi", i*(1+random(2)));	  
 	  ob->set("eff_qi", ob->query("max_qi"));	
 	  ob->set("qi", ob->query("max_qi"));	
    return 1;
}

int start_condition(object ob)
{
	set_skill("force", 450);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("sword", 450);
	set_skill("blade",450); 
	set_skill("strike",450); 
	set_skill("jindao-heijian",450); 
	set_skill("guiyuan-tunafa",450); 
	map_skill("force","guiyuan-tunafa");
	map_skill("blade","jindao-heijian");
	map_skill("sword","jindao-heijian");
	map_skill("dodge","shuishangpiao");
	set("combat_exp", 8000000);
	set("max_qi", 30000);
	set("max_jing", 10000);
	set("eff_jingli",10000);
	set("max_neili", 21000);
	set("qi",30000);
	set("jing",10000);
	set("jingli",10000);	
	set("neili", 42000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat",({ 
		(: perform_action, "sword.daojian" :), 

	}));
  return 1;
}



void unconcious()
{
  say( "公孙止伸手在怀里摸了一阵，摸出一粒药丸来塞在嘴里，片刻之间就又恢复了精神。\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	object ob=this_object();
	object me = this_player();
	if(ob->query("quest/try_fight")) {
	  command("sign");
	  if(ob->query("quest/try_fight_id")) {
      remove_call_out("kill_player");
      ob->remove_all_killer();
      start_condition(ob);
	  	me=find_player(ob->query("quest/try_fight_id"));
	    ob->delete("quest/try_fight");	 
	    ob->delete("quest/try_fight_id");
	  	if(!me) return;
      me->remove_all_killer();  
      if(environment(me)!=environment(this_object())) return;
       if(me->query_temp("quest/jindaoheijian/zhuigsz")&& me->query_temp("quest/jindaoheijian/qqchi"))
   {     	
     message_vision(HIR"\n公孙止痛哭流涕的哀求你的原谅。\n"NOR,me);   

     message_vision(HIC"\n你又询问了一些当年的情况，公孙止当即简单说起了当年发生在公孙止和裘千尺身上的经历。\n"+
                       "可是裘千尺却随意辱骂我，严密管束，百分之百是个泼辣的悍妻,我也是没有办法。 裘千尺是\n"+
                       "“铁掌水上飘”裘千仞的妹妹，因与哥哥闹意见出走而到了绝情谷，下嫁了公孙止但她看不起\n"+       
        	             "丈夫，他武功是她所指点，一切成就都是拜她所赐。长久惧内的公孙止见了温柔婉顺的侍婢柔\n"+ 
        	             "儿，马上爱上，要带着她远走高飞。裘千尺识破计谋，所采取的对付他们的方法至为歹毒她把\n"+ 
        	             "两人抛入情花丛中，然后把绝情丹尽数浸在砒霜水中只留一粒<实际上留了三粒，她为自己和\n"+ 
        	             "孩子留了后手>，让公孙止选择救自己还是救情人。结果，公孙止杀了柔儿，救了自己，但柔\n"+ 
        	             "儿的死激励了他去反叛，他骗得裘千尺服下迷药。然后把她手足筋络挑断，抛入深穴之中。凶\n"+ 
        	             "悍的裘千尺过于自信，终于栽在她看不起的丈夫手中。你听完公孙止的描述，又开始同情公孙\n"+ 
                       "止悲惨的历史。。悲哀啊！算了！也觉得世事无常，我就给你学习金刀黑剑机会，如果你是有\n"+ 
                       "缘人就和可以学习。\n"NOR,me);
        	 message_vision(HIG"\n多谢这位大侠不杀之恩，如果您想学习金刀黑剑阴阳双刃，就可以随时来绝情谷向我请教！\n"NOR,me);   
        	 me->set("quest/jindaoheijian/ask",1);
        	 me->delete_temp("quest/jindaoheijian/zhuigsz");
        	 me->set_temp("quest/jindao-heijian/qqchi",0);
        	 me->move("/d/gumu/jqg/dating");
        	                         	      }
     ob->unconcious();       
                                    }
	    else  {
	    command("why");
	    ::die();
            }
  }
}
