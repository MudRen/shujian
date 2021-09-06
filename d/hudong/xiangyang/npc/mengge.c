//定义任务刷新地点，方便检查标记。 By lsxk@hsbbs 2007/7/10
#define JOB_CHECK_PLACE "/d/xiangyang/cross2"

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#define HDJOB "/adm/daemons/hdjob.c"
#define HD_TEST 1
#define MAX_HDNUM 40
int ask_me1();
int check_player(object me,string arg);

void create()
{
    	set_name("蒙哥", ({ "meng ge", "meng", "ge" }));
    	set("title","蒙古元帅");
    	set("gender", "男性");
    	set("long", "这是此次负责进攻襄阳的蒙古元帅。\n");
    	set("age", 25);
    	set("str", 30);
    	set("int",20);
    	set("con",30);
    	set("dex",20);
    	set("combat_exp", 300000);
    	set("attitude", "friendly");
    	set("max_qi",2000);
    	set("max_jing",1000);
    	set("neili",2000);
    	set("max_neili",2000);
    	set("qi",2000);
    	set("jing",1000);
    	set("jingli",1000);
    	set("score", 100);
    	set("unique", 1);
        set("no_get", 1);
    	set("no_quest",1);

    	set_temp("special_die",1);
    	set_temp("xyjob/mg_attack",1);
    	set_temp("living", 1);

    	set_skill("force", 100);
    	set_skill("dodge", 100);
    	set_skill("parry", 100);
        set_skill("yijin-jing", 100);
        set_skill("shaolin-shenfa", 100);
        set_skill("blade", 100);
        set_skill("xiuluo-dao",100);
        set_skill("buddhism", 100);
        set_skill("literate", 100);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "xiuluo-dao");
        map_skill("blade", "xiuluo-dao");

// 限制人数
        set("sljob",3);
        set("xxjob",4);
        set("xsjob",2);
        set("gjob",1);
        set("job",6);

        set("inquiry", ([
 "攻打襄阳" : (: ask_me1 :),        
        ]) );

        setup();
        carry_object("/clone/weapon/blade")->wield();
        carry_object("/clone/armor/armor")->wear();
}
int ask_me1()
{
int i, a_exp = 0, d_exp= 0;
object ob =this_object();
object *obj;
      object me = this_player();
           if(!ob->query("hd_start")){ 

           command("say 我军正在做最后大战演练，不久就要攻打襄阳！");
             return 1; } 
     if(me->query_condition("killer")){
           command("say 你正被通缉中，太显眼，还是取消通缉后再来吧！");
             return 1;
         }
             if(base_name(environment(ob))!="/d/hudong/xiangyang/attack"){
            command("say 我出门在外，不清楚！");
            return 1; } 
             if(me->query("combat_exp") < 100000){
            message_vision("$N对$n说道：这位"+RANK_D->query_respect(me)+"，战场险恶，你还是回去好好锻炼吧！\n",ob,me);
           return 1; } 
             if(me->query_temp("互动任务/襄阳大战/ask_ok")==2){
             command("say 你已经在协助我蒙古先锋军夺取襄阳了，赶快做好准备吧！");
             return 1; } 
             if(me->query_temp("互动任务/襄阳大战/ask_ok")==1){
           command("say 看你的模样，莫不是宋人派过来的奸细？");
             return 1;         } 
            

             message_vision(CYN"\n$N哈哈大笑道："+RANK_D->query_respect(me)+"肯来帮忙，宋狗妄图阻止我军夺取襄阳的算盘就要落空了。\n"NOR, ob, me);
             message_vision(CYN"\n$N对$n说道：既然如此，"+RANK_D->query_respect(me)+"就赶快下去准备准备吧，我军马上就要攻城了。\n"NOR, ob, me);
             me->set_temp("互动任务/襄阳大战/ask_ok",2);
 me->set_temp("互动任务/襄阳大战/attack",1);

 me->set_temp("title",HIR"蒙古先锋"NOR);
                      return 1;
}
 int check_player(object me,string arg)
{
	if(userp(me) && me->query_temp(arg))
		return 1;
		else
		return 0;
}
