// NPC: /d/meizhuang/npc/huangzhonggong.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("黑白子", ({ "heibai zi", "zi" }));
	set("nickname", HIW"梅庄二庄主"NOR);

	set("gender", "男性");
	set("age", 54);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long",
      "他就是梅庄四位庄主排行第二的黑白子。\n"
      "身穿一件干干净净的黑白相间的长袍。\n"
      "他已年愈五旬，身材高大，双眼神光内敛, 一望便知是一位内家的高手。\n");
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
	set_skill("xuantian-zhi", 180);
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("finger", 180);
	set_skill("tianmo-gong", 180);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("finger", "xuantian-zhi");
	map_skill("parry", "xuantian-zhi");
	prepare_skill("finger", "xuantian-zhi");

	set_temp("apply/damage", 40);
	set("chat_chance", 1);
	set("chat_msg", ({
		"黑白子喃喃道：“呕血谱”可是天下第一棋谱，如果我能……”\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}      

int accept_object(object who, object ob)
{
        object me;
       // mapping fam;
        me = this_object();
/*
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="日月神教"){
             command("thank "+ (string)who->query("id"));
             command("say 你与本派素无来往，不知为何送如此厚礼？");
             return 0;
        }
 */      
        if (!this_player()->query_temp("meizhuangguangling")){
             command("say 你还是先去找我大哥黄钟公去问问吧！");
             return 0;
        }
        
        //if (fam["generation"] == 3)
        if ((string)ob->query("id") == "ouxue pu"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say 你帮我办成了这件事，我很高兴，你去找我的三弟秃笔翁试试吧，或许他能给你一些提示！");
            who->set_temp("meizhuangouxuepu",1);
            who->delete_temp("meizhuangguangling");
              return 1;
            }
        command("? "+ (string)who->query("id"));
        return 0;
}

void destroying(object obj)
{
        if(! obj) return;
        destruct(obj);
}