// gsz.c 公孙止
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void kill_player(object me);
void die();
void kill_ob(object me);
int ask_jindaoheijian();
#define QUESTDIR "quest/jindaoheijian/"

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

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
        set("eff_jingli", 2000);
	set("jiali", 80);
	set("combat_exp", 1000000);
 
        set_skill("force", 150);      
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("guiyuan-tunafa", 150);
        set_skill("literate", 120); 
        set_skill("shuishangpiao", 150);
        set_skill("tiezhang-zhangfa", 150);
        set_skill("strike",150);
        set_skill("sword", 150);
	      set_skill("jindao-heijian", 150);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "liangyi-jian");
	      map_skill("sword", "jindao-heijian");
	      map_skill("blade", "jindao-heijian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "绝情丹": "丹药无多，而且也很难炼制，非万不得已。。。",
            "绝情谷": (: ask_gu :),
            "金刀黑剑": (: ask_jindaoheijian :)
        ]) );

	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"功夫还太弱，绝情谷中甚为危险，还是不要在此久留了。";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"既然对绝情谷甚有兴趣，就请随便看看吧。";
}

int ask_jindaoheijian() 
{
	object me = this_player();
	object ob = this_object();

   if(!me->query("quest/jindaoheijian/ask") && me->query("combat_exp")<= 2000000)
   {
     command("@@ "+me->query("id"));
     command("say 以你当前的经验恐怕还是难以领悟，还是抓紧去练功去吧。");
     return 1;
   } 
   
if(me->query("quest/jindaoheijian/pass"))
  {
	  command("disapp "+me->query("id"));
	  command("say 你不学已经学了金刀黑剑阴阳双刃了吗。");
	  return 1;
  } 
    
 //武功学习之间需要间隔一天，经验需要间隔500K

	if(me->query(QUESTDIR+"time") && time()-me->query(QUESTDIR+"time")<86400)
	{
	  command("shake "+me->query("id"));
	  command("say 今天先切磋到这里吧，明天吧。");
	  return 1;
  }
   if( me->query(QUESTDIR+"combat_exp") && me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000 && !me->query("cw_exp"))
{
	  command("look "+me->query("id"));
	  command("say 以你当前的经验恐怕还是难以领悟，还是抓紧去练功去吧。");
	  return 1;
  }
  
  if(me->query("quest/jindaoheijian/ask") > 0)
    {
    command("pat "+me->query("id"));
    message_vision(HIC"\n\n$n微笑着对$N说道：「可要看仔细了!」,双手耍起手中的金刀和黑剑!\n"NOR,me,ob); 
    me->set(QUESTDIR+"time",time());
    me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
    remove_call_out("thinking");
		call_out("thinking",5, me, ob);
    tell_object(me,YEL"你拼命地回忆公孙止金刀黑剑的走势，你开始认真思索着.........\n"NOR);
    me->start_busy(2);
	  return 1;
	  }
	  else
	 {  
	  command("? "+me->query("id"));
         command("say 你问这个做什么?");
    return 1;
  }
}

int thinking(object me, object ob)
{
	int p;
	if(!me) return 0;
	
  if(me->query_temp("jdhj_thinking")<(3+random(3)))
	{
		me->add_temp("jdhj_thinking",1);
    if(random(2)) tell_object(me,HIG"\n你努力地回忆刚才公孙止金刀和黑剑的走势,只觉得眼花缭乱...\n"NOR);
    else tell_object(me,HIY"\n突然间，你似乎抓到了什么，你努力地回忆刚才张公孙止招式，你似乎感觉到了其中的变化所在...\n"NOR);
	  tell_room(environment(me),HIC""+me->query("name")+"似乎在思索着什么，一服愁眉不展的样子。\n"NOR, ({}));
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp("jdhj_thinking");

        p=random(40);

         if(p > 30 && random(me->query("kar"))>25)
    {
       tell_object(me,HIG"\n你此时生怕将刚才的精妙招式忘了，当即跟着公孙止招式挥舞着手中刀和剑。\n"NOR);
       message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
       tell_object(me,HIR"你听了公孙止的指点,终于领悟了金刀黑剑的精华所在。\n"NOR);
       me->set("quest/jindaoheijian/pass",1);
       me->set("quest/jindaoheijian/ask",0);
       me->set_skill("jindao-heijian",1);
       message_vision(HIC"\n你的「金刀黑剑」进步了！”\n"NOR,me); 
	log_file("quest/jindaoheijian", sprintf("%s(%s) 失败%d次成功解开金刀黑剑阴阳双刃。富源：%d；经验：%d。", me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n你脑海里似乎抓住了什么，可是依然不是很明白。\n"NOR);
       message_vision(HIC"\n$N摇了摇头，道：“好像还是很困难的。”说罢，深深地叹了口气。\n"NOR,me); 
       command("poor "+me->query("id"));
       me->add(QUESTDIR+"fail",1);
	log_file("quest/jindaoheijian", sprintf("%s(%s) 解金刀黑剑阴阳双刃失败：%d次。富源：%d；经验：%d。", me->name(1),me->query("id"), me->query(QUESTDIR+"fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}
