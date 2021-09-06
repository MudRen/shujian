// /d/xiangyang/npc/lvwende.c
// by looklove 2000/8/23
// add 金盆洗手限制 cigarman 16/02/2008
#include <ansi.h>
inherit NPC;
#define HDJOB "/adm/daemons/hdjob.c"
#define HD_TEST 1
#define MAX_HDNUM 40
int ask_me1();
string ask_me();
void destroy(object ob)
{
        destruct(ob);
        return;
}
void create()
{
        set_name("吕文德", ({ "lv wende", "lv" }));
        set("title", "襄阳知府");
        set("gender", "男性");
        set("age", 40);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("long", "他是襄阳的现任知府，在襄阳率领大宋军民与蒙古鞑子对抗。\n");
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("eff_jingli", 1000);
        set("jiali", 30);
        set_skill("force", 70);
        set_skill("unarmed", 80);
        set_skill("strike", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("qingmang-jian", 80);        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        set("inquiry", ([
                "弃暗投明" : (: ask_me :),
                "协防襄阳" : (: ask_me1 :),
        ]));
        setup();
        carry_object(ARMOR_D("guanxue"))->wear();
        carry_object(ARMOR_D("changshan4"))->wear();
}

void kill_ob(object ob)
{
        command("say 大胆，竟敢杀朝廷命官！");
        return ;
}
int ask_me1()
{
          int i, a_exp = 0, d_exp= 0;
object ob =this_object();
object *obj;
      object me = this_player();

          if(!ob->query("hd_start")){
                command("say 据探子来报，目前蒙古大军还没来犯我大宋边关！");
                return 1; } 
          if(me->query_condition("killer")){
                command("say 朝廷正在通缉你呢，虽然我护城心切，但也不敢得罪朝廷！");
                return 1; } 
                if(base_name(environment(ob))!="/d/hudong/xiangyang/defend") {
                command("say 我出门在外，不清楚！");
                return 1; }             if(me->query("combat_exp") < 100000){
                message_vision("$N对$n说道：这位"+RANK_D->query_respect(me)+"，战场险恶，你还是回去好好锻炼吧！\n",ob,me);
                return 1; } 
                if(me->query_temp("互动任务/襄阳大战/ask_ok")==1){
                command("say 你已经在协助我军防守襄阳了，快去做好准备吧！");
                return 1; } 
                if(me->query_temp("互动任务/襄阳大战/ask_ok")==2){
                command("say 看你鬼鬼崇崇的模样，莫不是蒙古鞑子的奸细？");
                return 1; } 
                              



                 message_vision(CYN"\n$N哈哈大笑道："+RANK_D->query_respect(me)+"肯大义援手，蒙古鞑子妄想夺取襄阳的美梦要落空了。\n"NOR, ob, me);
                 message_vision(CYN"\n$N对$n说道：既然如此，"+RANK_D->query_respect(me)+"就赶快下去准备准备吧，蒙古鞑子随时都会攻城了。\n"NOR, ob, me);                 me->set_temp("互动任务/襄阳大战/ask_ok",1);
                 me->set_temp("互动任务/hdflag","襄阳大战");
me->set_temp("互动任务/襄阳大战/defend",1);

                 me->set_temp("title",HIY"大宋义士"NOR);
                                return 1;
}
int check_player(object me,string arg)
{
	if(userp(me) && me->query_temp(arg))
		return 1;
		else
		return 0;
}
