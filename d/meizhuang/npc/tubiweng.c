// NPC: /d/meizhuang/npc/tubiweng.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("秃笔翁", ({ "tubi weng", "weng" }));
	set("nickname", HIY"梅庄三庄主"NOR);
	set("gender", "男性");
	set("age", 47);
	set("no_quest", 1);
	set("no_bark", 1);
  set("long",
       "他就是梅庄四位庄主排行第三的秃笔翁。\n"
       "身穿一件干干净净的白色长袍。\n"
       "他已年愈五旬，身材矮小，顶上光光, 一看就知道是个极易动怒的人。\n");
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
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("brush", 180);
	set_skill("tianmo-gong", 180);
	set_skill("shigu-bifa", 180);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("brush", "shigu-bifa");
	map_skill("parry", "shigu-bifa");

	set_temp("apply/damage", 20);
	set("chat_chance", 1);
	set("chat_msg", ({
		"秃笔翁叹了口气道：加入我能够得到张旭的“率意帖”，我就……”\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
  carry_object(BINGQI_D("panguanbi"))->wield();
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
        if (!this_player()->query_temp("meizhuangouxuepu")){
             command("say 你还是先去找我二哥黑白子去问问吧！");
             return 0;
        }
        
       // if (fam["generation"] == 3)
        if ((string)ob->query("id") == "shuaiyi tie"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say 你帮我办成了这件事，我很高兴，你去找我的四弟丹青生试试吧，或许他能给你一些提示！");
            who->set_temp("meizhuangshuaiyitie",1);
            who->delete_temp("meizhuangouxuepu");
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