// wang.c 王重阳
//Modified By action@SJ 2009/2/21

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_qxbj();

void create()
{
	      object ob;
        set_name("王重阳", ({ "wang chongyang", "wang", "chongyang" }));
        set("long", @LONG
他就是全真教的开山祖师、首代掌教王重阳王
真人。他白须飘飘，宽袍缓袖，眉目清癯，颇
有些仙风道骨的味道。他本来一腔热血欲报效
国家力抗金兵，可惜朝廷腐败，于是便心灰意
冷，兼此时又从道德经中悟得了天地万物滋生
的大道，从而手创全真教。
LONG);
        set("title", "全真派开山祖师");
        set("nickname", HIW "中神通" NOR);
        set("age", 76);
        set("gender", "男性");
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);
        set("max_qi", 20000);
        set("max_jing", 50000);
        set("neili", 200000);
        set("jingli", 20000);
        set("max_neili", 200000);
        set("eff_jingli", 20000);
        set("jiali", 250);
        set("combat_exp", 30000000);
        set("score", 500000);

        set_skill("force", 500);      
        set_skill("xiantian-gong", 500);
        set_skill("dodge", 500);
        set_skill("jinyan-gong", 500);
        set_skill("parry", 500);
        set_skill("strike", 500);
        set_skill("haotian-zhang", 500);
        set_skill("sword", 500);
        set_skill("quanzhen-jianfa", 500);

        set_skill("taoism", 200);
        set_skill("literate", 380);
        set_skill("medicine", 200);
	      set_skill("tiangang-beidouzhen", 200);
	        
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "haotian-zhang");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 1, "掌教");

        set("inquiry", ([
                "全真教"     : "我全真教是天下道家玄门正宗。",
                "七星宝剑" : (: ask_qxbj :),
                "丘处机"     : "他是我二徒弟，你问他作甚。",
                "周伯通"     : "他是我师弟，现在又不知道跑哪里玩去了。",
                "一灯大师"     : "他原是大理段皇爷，可惜我那不争气的师弟惹的他出家了。",
                "黄药师"     : "他是桃花岛岛主呀。",
                "欧阳锋"     : "哼！哼！。",
                "洪七"     : "听说他了做了丐帮帮主了，真的假的呀，好久没见他了。",
        ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.lian" :),
                (: perform_action, "strike.sanqing" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.qixing" :),

        }));

        set_temp("apply/damage", 100);
        set_temp("apply/armor", 200);

        setup();
        if (clonep()) {
		ob = unew(BINGQI_D("sword/qixing-jian"));
		if (!ob) ob = unew(("clone/weapon/zhujian"));
		ob->move(this_object());
		ob->wield();
    carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
	}
}

void attempt_apprentice(object ob)
{
      if(ob->query_skill("xiantian-gong",1) < 180 ||
         ob->query_skill("taoism",1) < 150 ||
         ob->query_int() < 40 ||
         ob->query("shen")<300000){
        command("say 你的武功、道学心法、悟性、正神条件还不够，再回去练练吧。");
        return;
        }

     command("say 不错，以你资质定可传我衣钵！我就收下你这个徒弟了。");        
     command("say 好吧，贫道就收下你了。");
     command("recruit " + ob->query("id"));
     ob->set("title", HIW"全真教重阳真人亲传弟子"NOR);
     ob->set("class","taoism");
}

string ask_qxbj()
{
	object me=this_player() , weapon;

        if (me->query("family/master_name") != "丘处机" && me->query("family/master_name") != "王重阳")
		return "你并非我全真教丘处机弟子，不能将我派宝物赠送与你。";
        weapon = present("qixing jian", this_object());
	if (!objectp(weapon))
		return "七星剑已经被你师兄拿走了,现在不在我手里。";
	command("unwield qixing jian");
	command("give qixing jian to " + me->query("id"));
	return "这七星剑就给你了，你可要妥善保管好！";
}
