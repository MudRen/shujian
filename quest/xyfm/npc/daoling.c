// 降妖伏魔 by hongba

#include <ansi.h>
inherit NPC;
#define MIRROR_SYS "/quest/xyfm/sys/mirror_sys"
string ask_job();

void create()
{
	set_name(HIG"章道灵"NOR, ({ "zhang daoling", "zhang", "daoling"}));
	set("title", HIY"末世天师"NOR);
        set("long", "他是道家的高人，道教正一、灵宝派的杰出不世传奇人物。\n");
	set("gender", "男性");
        set("attitude", "peaceful");
        set("shen_type",1); 
	set("age", 50);
	set("per", 23);
       set("kar", 23);
	set("pur", 23);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("max_qi",9000);
	set("qi", 9000);
	set("max_jing", 6000);
	set("jing",6000);
	set("eff_jingli", 9000);
	set("jingli", 9000);
	set("max_neili", 9000);
	set("neili", 9000);
	set("jiali", 200);
	set("combat_exp", 5000000);
	
	set_skill("dodge", 180);
       set_skill("cuff", 180);
       set_skill("parry", 180);     
	set("shen", 5000);
        set("inquiry",([
                "job" :  (: ask_job :),
                 "任务" : (:ask_job:),

 ]));

	
	setup();
	 carry_object("/d/wudang/obj/greenrobe")->wear();
	  carry_object("/clone/armor/shoes")->wear();
}

string ask_job()
{
   mapping fam;
    object me;
    object ob;
    me=this_player();
     fam= me->query("family");
if ( me->query_temp("xyfm_ask")) 
return "你怎么老问个没完呢！\n";
   if (me->query_condition("xyfm_job") >= 1)
       return "多谢好意，但请先休息下吧！\n";

   if ((int)me->query("combat_exp") < 1500000)
       return "您的好意老道心领，但您的修为太低，莫要儿戏视之！\n";
if ( !fam || fam["family_name"] != "武当派" && fam["family_name"] != "全真教"){
return "这位"+RANK_D->query_respect(me)+"与我道教素无来往，不知此话从何谈起？";
}



    if ( me->query_condition("job_busy"))
{
                    if (me->query("job_name")=="降妖伏魔")
{
                                   return "say 现在暂时还没有工作让你去做。";
                                               
 }
                  
           
           return "say 你正忙着别的事情呢。";
       
                                       
}

        
        command("say  时势混乱，战祸连年，滋生一大批怨孽野鬼，搅乱清平世界，你去帮我降伏它们！");
        command("say  怨孽之说虽自古有之，但终属怪力乱神，你要仔细调查一番才好，万事小心。");
me->set_temp("xyfm_ask",1);
return "如果准备好了的话，请输入(yes)，我送你进去。如果没准备好，请输入(no)。\n";
}
void init()
{
object me = this_player();
add_action("do_yes","yes");
add_action("do_no","no");
::init();
}
int do_no()
{
 object me = this_player();

 if ( me->query_temp("xyfm_ask")) {
me->delete_temp("xyfm_ask");
me->apply_condition("job_busy",5);
command("say  好吧，以后再说吧。");
return 1;
}
}
int do_yes()
{
 object me = this_player();
object memory;
object *team;
int i;
if(MIRROR_SYS->query_room_amount() >= 20)
	{
		tell_object(me,"镜像已经开启太多，欢迎下次参与。\n");
		return 1;
	}
        //删除旧的副本
        memory = me->query_temp("mirror/mirror_memory");
        if(objectp(memory))
        {
                memory->delete("user_id");
        }

if ( me->query_temp("xyfm_ask")) {
me->delete_temp("xyfm_ask");
me->set_temp("xyfm_start",1);
 MIRROR_SYS->mirror(me);
       	return 1;
       
        me->move("d/mirror/guangchang");


}
}
