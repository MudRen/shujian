// ouyangke.c

#include <ansi.h>

//inherit F_MASTER;
inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("欧阳克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身飘逸的白色长衫，手摇折扇，风流儒雅。\n");
	set("title", HIG"欧阳世家少庄主"NOR);
        set("nickname",HIM"玉面蛇心"NOR);
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 29);
	set("con", 25);
	set("dex", 26);

	set("qi", 1700);
	set("max_qi", 1700);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 300000);

        set_skill("cuff",  180);
	set_skill("dodge", 120);
	set_skill("parry", 140);
	set_skill("force", 130);
	set_skill("staff", 100);
	set_skill("hamagong",200);
	set_skill("lingshe-zhangfa", 130);
        set_skill("lingshe-quanfa", 180);
  set_skill("poison", 180);
  set_skill("hamabu", 100);
  set_skill("hand", 120);
	set_skill("staff", 150);
	set_skill("jingmai-xue", 150);
  set_skill("literate", 150);

	map_skill("force", "hamagong");
	map_skill("dodge", "hamabu");
	map_skill("staff",  "lingshe-zhangfa");
        map_skill("parry", "lingshe-quanfa");
  map_skill("cuff", "lingshe-quanfa");
  prepare_skill("cuff", "lingshe-quanfa");

        create_family("欧阳世家", 2, "传人");

	set("inquiry", ([
		"欧阳峰" : "他是我叔父。",
		"化尸粉" : "我只有一份化尸粉，不能给你。不过你要是给我一具尸体，我可以给你做些。",
	]));

	set("chat_chance", 2);
	set("chat_msg", ({
		"欧阳克唱道：漂亮姑娘你请留步￣￣让我多看你一眼￣￣\n",
		"欧阳克色迷迷地看着街边的小姑娘。\n",
		"欧阳克把纸扇一展，转过身去，深情地吟道：红颜知己最难得￣\n",
	}) );

	set("master_ob",3);
	setup();
	carry_object("/clone/armor/changpao")->wear();
	add_money("gold",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	if ((string)ob->query("gender")=="女性")
	{
                if (ob->query("per") < 22)
                        return;

                if (ob->query("sex/欧阳克"))
                {
                        command("kiss " + ob->query("id"));
                        command("say 怎么样，要不要再来几次啊... 嘻嘻。");
                } else
        	switch(random(3))
        	{
        	case 0: command("rose "+(string)ob->query("id"));break;
        	case 1: command("kiss "+(string)ob->query("id"));break;
        	case 2: command("love "+(string)ob->query("id"));break;
        	}
     
	}
	else
                say("欧阳克叹了一口气说：这位"+RANK_D->query_respect(ob)+
                        "，你要是能给我弄一个女人来就好了。\n");
	return;
}
/*
void attempt_apprentice(object ob)
{
     if(ob->query_skill("hamagong",1) < 160 ||
      ob->query_skill("shexing-diaoshou",1) < 160 ||
        ob->query_skill("lingshe-zhangfa",1) < 160){
        command("say 瞧你这点功夫。");
        return 0;
        }
     command("say 看你还不赖吗，就手下你吧,听说找到我叔叔欧阳峰就能学到更高声的功夫。");
     command("recruit " + ob->query("id"));
          ob->set("title",HIW"白驼山欧阳世家家臣"NOR);
}
*/
int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		message_vision("欧阳克摆摆手说道：这位"+RANK_D->query_respect(ob)+
		"，我怎能欺负女孩子呢！\n", ob);
		return 0;
        }

        return ::accept_fight(ob);
}
 


