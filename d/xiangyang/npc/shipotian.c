//shipotianc

inherit NPC;
#include <ansi.h>
int ask_taixuan();


void greeting(object me);

void create()
{
        set_name("石破天", ({ "shi potian", "shi", "potian" }) );
        set("gender", "男性" );
        set("nickname",HIC"狗杂种"NOR);
        set("age", 16);
        set("long",
"一个面容清瘦的少年男子。\n"
"人人叫他狗杂种，他也不在意。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 25);
        set("shen_type", 1);
  set("no_get", 1);
  set("no_bark", 1);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand", 200);
        set_skill("cuff",200); 
        
        set_skill("taixuan-gong",200);
        map_skill("force","taixuan-gong");
        map_skill("hand","taixuan-gong");
        map_skill("dodge","taixuan-gong");
        
        map_skill("parry","taixuan-gong");
    prepare_skill("hand", "taixuan-gong");
        set("combat_exp", 1000000);
        set("max_qi", 30000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("eff_jingli",3000);
        set("qi",30000);
        set("jing",3000);
        set("jingli",3000);
        set("neili", 5000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "taixuan" :),
       (: perform_action, "hand.po" :),
       (: perform_action, "hand.xuan" :),
     }));

  set("inquiry", ([
    "太玄功": (: ask_taixuan :),
    "狗杂种" : "呵呵，这是我的外号。",
    "张三" : "呵呵，他是我结义兄长。",
    "李四" : "呵呵，他是我结义兄长。",
    "谢烟客" : "这老伯伯给了我几个很好玩的小泥人。",
    
        ]));
        setup();
        
        carry_object("/clone/armor/cloth.c")->wear();
} 

void init()
{
  object me;
        ::init();
  if (interactive(me = this_player()) ) {
           me->start_busy(1);
       call_out("greeting", 2, me);
  }       
}

void greeting(object me)
{
                int i,p;
  if(!me) return;

        if(me->query_condition("killer"))
        {
          command("fear "+me->query("id"));
    command("say 你是杀人犯，是坏人！");
   
          return;
        }

  

}


int ask_taixuan() 
{
        object me = this_player();
        object ob = this_object();
   
if(me->query("taixuan_pass"))
  {
          command("disapp "+me->query("id"));
          command("say 你好像已经学会太玄功了吧？");
          return 1;
  } 
    


 //武功学习之间需要间隔一小时，经验需要间隔10K
        if(me->query("taixuan/ask"+"time") && time()-me->query("taixuan/ask"+"time")<3600)
        {
          command("shake "+me->query("id"));
          command("say 这回你就别问了，问多了累。");
          command("say 洪八说要等一小时以后，还要涨10K经验哦。");
          return 1;
  }
   if(me->query("taixuan/ask"+"combat_exp") && me->query("combat_exp")-me->query("taixuan/ask"+"combat_exp")<10000)
        {
          command("look "+me->query("id"));
          command("say 以你当前的经验恐怕还是难以领悟，还是抓紧去练功去吧。");
command("say 洪八说要等一小时以后，还要涨10K经验哦。");
          return 1;
  }



if  (me->query_temp("taixuan/1"))
{
command("say 你不是已经去了么?");
return 1;
}


if(me->query("pur") > 27)
    {
   
    message_vision(HIC"\n$n微笑着对$N说道：「你可要仔细听了」,说罢对着$N轻声耳语几句。\n"NOR,me,ob); 
    me->set("taixuan/ask"+"time",time());
me->set("taixuan/ask",me->query("combat_exp"));
    
    tell_object(me,YEL"你拼命地竖起耳朵，仿佛只听见侠客岛什么的.........\n"NOR);
    me->start_busy(2);
me->set_temp("taixuan/1",1);
    me->set_temp("taixuan/ask",1);
          return 1;
          }
          else
         {  
          
         command("say 你问这个做什么?");
    return 1;
  }


}


