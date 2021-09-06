// NPC: /d/meizhuang/npc/shilingwei.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;
string ask_quest();

void create()
{
	object key;
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("nickname", GRN"梅庄四庄主"NOR);

	set("gender", "男性");
	set("age", 46);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long",
      "他就是梅庄四位庄主排行第四的丹青生。\n"
      "身穿一件干干净净的青色长袍。\n"
      "他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("jingli", 4000);
	set("max_jingli", 4000);
	set("max_neili", 5000);
	set("neili", 8000);
	set("combat_exp", 2200000);
	set("attitude", "peaceful");

	set_skill("unarmed", 180);
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("sword", 180);
	set_skill("tianmo-gong", 180);
	set_skill("pomopima-jian", 180);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("sword", "pomopima-jian");
	map_skill("parry", "pomopima-jian");
	
	set("inquiry", ([
         "秘密" : (: ask_quest :),
        ]));
	
	set("chat_chance", 1);
	set("chat_msg", ({
		"丹青生轻声说道：如果谁能将“溪山行旅图”，带来给我就告诉他一个大秘密……”\n",
	}));

        if (clonep()){
           key = unew(("d/meizhuang/obj/hongyu-yaoshi"));
           if(!key)key=new(("d/meizhuang/obj/hongyu-yaoshi"));
           key->move(this_object());
           carry_object(ARMOR_D("cloth"))->wear();
           carry_object(BINGQI_D("changjian"))->wield();
     }
	setup();

}  

string ask_quest()
{
	object me=this_player();
  object who=this_object();
  object ob = present("hongyu yaoshi", this_object());
	
	if(me->query("quest/xxdf/pass"))
		return "你不是已经成功学会吸星大法了吗，你还要去里面干嘛？\n";
		
	if(me->query_temp("quest/xxdf/start"))
		return "我不是叫你去酒室那边去试试了吗，还不快去！\n";
		
		if(!me->query_temp("quest/xxdf/startmz"))
		return "你是谁？问我这个干什么！\n";
		
		if (present("hongyu yaoshi", me))
		return "咦？红色钥匙不是在你身上么？";
		
	me->delete_temp("startmz");
	if (present("hongyu yaoshi",this_object())) {
			ob->set("owner", me);
			ob->move(me);
      me->set_temp("quest/xxdf/start",1);
      call_out("die",60);
      return("这把红玉钥匙给你，你去酒室那边去试试运气吧！！");
	}
else {
      call_out("die",60);
      message_vision("\n只见丹青生将一粒鹤顶红塞入口中！」\n", me);
       return("完蛋了，钥匙不见了，大哥肯定不会饶了我的，我不活啦，说罢：将鹤顶红塞入口中！");
}
}

int accept_object(object who, object ob)
{
        object me;
        me = this_object();
     
        if (!this_player()->query_temp("meizhuangshuaiyitie")){
             command("say 你还是先去找我三哥秃笔翁去问问吧！");
             return 0;
        }
        
        if ((string)ob->query("id") == "xinglv tu"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say 你帮我办成了这件事，我很高兴，那我就告诉你一个秘密吧！");
            who->set_temp("quest/xxdf/startmz",1);
            who->delete_temp("meizhuangshuaiyitie");
              return 1;
            }
        command("? "+ (string)who->query("id"));
        return 0;
}

void unconcious()
 {
         remove_all_killer();
         remove_all_enemy();
         say("丹青生一声高呼：杀掉我你就不要想再得到这秘密了！。\n");
        reincarnate();
         set("eff_qi", query("max_qi"));
         set("qi", query("max_qi"));
         set("eff_jing", query("max_jing"));
         set("jing", query("max_jing"));
         set("jingli", query("eff_jingli"));
         clear_conditions_by_type("poison");
}

 void die()
{
::die();
}
