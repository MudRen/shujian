//xuemuh.c 薛慕华
// shilling 97.2

inherit NPC;
//inherit F_MASTER;

//void attempt_apprentice(object ob);
int ask_me();

void create()
{
	set_name("薛慕华", ({ "xue muhua", "xue" }));
	set("long", 
		"他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。\n");
	set("gender", "男性");
	set("title","逍遥派“函谷八友”");
	set("nickname","阎王敌薛神医");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("inquiry", ([
		"疗伤" : (:ask_me:),
	]) );

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 80000);

	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("medicine",220);
	set_skill("parry", 220);
	set_skill("hand", 220);
	set_skill("qingyun-shou", 150);
	set_skill("piaomiao-shenfa",180);
	set_skill("beiming-shengong", 180);
	set_skill("zhemei-shou", 180);
	set_skill("literate", 200);
	set_skill("art", 160);

	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "beiming-shengong");

	prepare_skill("hand","zhemei-shou");

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
 if ((string)ob->query("gender")=="男性")
{
            message_vision("薛慕华垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
        return;}

    else
{
                 message_vision("我逍遥派从不收女流之辈。\n",ob);
        return;}
 }

int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("family/family_name") != "逍遥派")
		return notify_fail("你不是我派弟子，我不可以为你疗伤。\n");
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?"+ob->query("id"));     
		command("say 你没有受任何伤啊？\n");
		return 1;
	}
	else
	{
		message_vision("薛慕华喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		remove_call_out("recover");
		call_out("recover",2,ob);
		return 1;
	}
}


int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("大约过了一盅茶的时份，薛慕华慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了,可以走啦。\n");
	return 1;
}
