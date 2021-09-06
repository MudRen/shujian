// suxingh.c
// shilling 97.2
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 35);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"此人就是号称聪辩老人的苏星河，据说他能言善辩， \n"
"是一个武林中的智者，而他的武功也是无人能知。\n");

	set("combat_exp", 30000000);
	set("attitude", "peaceful");
	set("chat_chance", 1);

	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 15000);
	set("max_neili",8000);
	set("jiali", 200);

	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("blade", 280);
  set_skill("qingyun-shou", 250);
	set_skill("beiming-shengong", 280);
	set_skill("ruyi-dao", 280);
	set_skill("liuyang-zhang", 280);
	set_skill("zhemei-shou", 280);
	set_skill("literate", 200);
	set_skill("piaomiao-shenfa", 280);
	set_skill("hand", 280);
	set_skill("strike", 280);
	set_skill("art", 150);
	set_skill("medicine", 180);

	map_skill("strike", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "beiming-shengong");
	map_skill("hand", "zhemei-shou");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.wanshi" :),
                (: perform_action, "blade.ruyi" :),
           
	}) );

	create_family("逍遥派", 2, "弟子");
	set("title","逍遥派第二代大弟子");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}


void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 100) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"的北冥神功是否还应该有所提高啊？");
		return;
	}
if ((string)ob->query("gender")=="男性")
   {
		message_vision("苏星河垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
       ob->set("title", "逍遥派第三代弟子");
       return;}
   else
      {
		message_vision("我逍遥派从不收女流之辈?”\n",ob);
       return;}
 }

