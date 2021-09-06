// ren.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
	set_name("任我行", ({ "ren woxing", "ren","woxing" }));
	set("nickname",HIR"魔教教主"NOR);
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀，
身材甚高，一头黑发，穿的是一袭青衫。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("no_get", 1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 20000);
	set("max_jing", 10000);
	set("eff_jingli",10000);
	set("neili", 80000);
	set("max_neili", 40000);
 	set("jiali", 200);
	set("combat_exp",7000000);
	set("score", 500000);

	set_skill("literate", 200);         // 读书识字
	set_skill("force",400);            // 基本内功
	set_skill("strike",400);           // 基本指法
	set_skill("dodge",400);            // 基本躲闪
	set_skill("parry",400);            // 基本招架
	set_skill("dagger",400);           // 基本刺法
	set_skill("sword",400);            // 基本剑法
	set_skill("blade",400);
	set_skill("club",400);
	set_skill("poison",180);
	set_skill("hand",400);
	set_skill("piaomiao-shenfa",400);  // 缥缈身法
	set_skill("huanmo-longtianwu",400);  // 幻魔胧天舞
	set_skill("qixian-wuxingjian",400);// 七弦无形剑
	set_skill("xixing-dafa",400);      // 吸星心法
	set_skill("wudang-quan",400);        // 太祖长拳
	set_skill("damo-jian",400);        // 达摩剑法
	set_skill("taiji-jian",400);       // 太极剑法
	set_skill("huifeng-jian",400);     // 回风拂柳剑
	set_skill("taishan-jianfa",400);    // 泰山剑法
	set_skill("hengshan-jianfa",400);    // 恒山剑法
	set_skill("hengshan-jianfa",400);   // 衡山剑法
	set_skill("huashan-jianfa",400);    // 华山剑法
	set_skill("songshan-jian",400);   // 嵩山剑法
	set_skill("tianmo-jian",400);
	set_skill("tianmo-zhang",400);
	set_skill("tianmo-shou",400);
	set_skill("tianmo-dao",400);
	set_skill("tianmo-gun",400);
	set_skill("tianmo-jue",200);
    set_skill("tianmo-gong",400);
	map_skill("force", "xixing-dafa");
	map_skill("sword", "qixian-wuxingjian");
	map_skill("strike", "huanmo-longtianwu");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("parry", "qixian-wuxingjian");
	prepare_skill("strike", "huanmo-longtianwu");
	set("quest/xixing/pass",1);
	set("chat_chance_combat", 80);
	  set("chat_msg_combat", ({
                (: perform_action, "sword.guangling" :),
                (: perform_action, "sword.music" :),
                (: exert_function, "xixing" :),
	}));

        set("inquiry", ([
                "比剑" :  (: ask_bijian :),
                "剑法" :  (: ask_bijian :),
                "黑木令" : "要拿黑木令？老夫想先看看你的剑法！\n",
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]) );

	create_family("日月神教", 7, "教主");
 	setup();
	carry_object("/clone/armor/changpao")->wear();
	carry_object("/clone/weapon/sword")->wield();
}

int ask_bijian()
{
	object weapon, me = this_player(), ob = this_object();

        if (!objectp(weapon = ob->query_temp("weapon")))
	{
		weapon = new("/clone/weapon/sword");
		weapon -> move(ob);
		command("wield sword");
	}
	if(!me->query_temp("quest/xxdf/start"))
	{
		message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n$n冷笑道：“江南四狗怎么不敢进来见我？！”\n", me, ob );
		return 1;
	}
	else {
	message_vision("$N躬身说道：“晚辈今日有幸拜见任老前辈，还望多加指教。”\n$n笑道：“不用客气，你来解我寂寞，可多谢你啦。”\n", me, ob );
	message_vision("$N道：“不敢。”\n$n点了点头，说道：“我只想瞧瞧你的剑法，并非真的过招，再说，我也未必能胜得了你。”\n\n", me, ob);
  command("笑傲江湖中老子剑法天下第一，找我比剑？找死！\n");
	command("enable sword damo-jian");
	say(HIR"\n任我行大喝一声：“少林派达摩剑法"NOR"「"HIR"达摩三绝剑"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第一招。\n");
	command("enable sword taiji-jian");
	say(HIR"\n任我行大喝一声：“武当太极剑法"NOR"「"HIG"三环套月"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第二招。\n");
	command("enable sword huifeng-jian");
	say(HIR"\n任我行大喝一声：“峨嵋派回风拂柳剑"NOR"「"HIW"燎原百击"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第三招。\n");
	command("enable sword songshan-jianfa");
	say(HIR"\n任我行大喝一声：“嵩山派嵩山剑法"NOR"「"HIM"龙吟凤翔"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第四招。\n");
	command("enable sword taishan-jianfa");
	say(HIR"\n任我行大喝一声：“泰山派泰山剑法"NOR"「"HIY"岱宗如何"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第五招。\n");
	command("enable sword huashan-jianfa");
	say(HIR"\n任我行大喝一声：“华山派华山剑法"NOR"「"MAG"夺命连环三仙剑"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第六招。\n");
	command("enable sword hengshan-jianfa");
	say(HIR"\n任我行大喝一声：“衡山派衡山剑法"NOR"「"CYN"衡山云雾回风十三式"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
		say("\n第七招。\n");
	command("enable sword hengshan-jianfa");
	
	say(HIR"\n任我行大喝一声：“恒山派恒山剑法"NOR"「"WHT"绵里藏针"NOR"」！”\n"NOR);
	COMBAT_D->do_attack(ob, me, query_temp("weapon"));
	if(present(me, environment()))
	{
  say(HBMAG"\n突然任我行发出一声巨吼，震的耳朵一阵阵发麻，一个不注意。。。。。\n\n"NOR);
	say("\n任我行叹了口气，说道：“还是没过八招。”\n");
	me->set_temp("renwoxing/bijian", 1);
	me->set("qi",-1);
	me->delete_temp("quest/xxdf/start");
	me->set_temp("quest/xxdf/startlass",1);
		return 1;
	         }
          }
         }
        }
       }
      }
     }
   }
  }
	return 1;
}

void attempt_apprentice(object ob)
{
	              mapping fam;
if ((int)ob->query("quest/xxdf/pass",1) < 1 || !ob->query("buyvip") || ob->query("relife/gifts/total")<=3 || ob->query_skill("qixian-wuxingjian",1) <= 300 || ob->query("expell"))
	{
		command("say 我是不轻易收徒的。");
		return;
	}
/*
                if (!(fam = this_player()->query("family")) || fam["family_name"] !="日月神教"){
             command("thank "+ (string)ob->query("id"));
             command("say 你与本派素无来往，我不会收你为徒的？");
             return 0;
        }
*/
	if ((int)ob->query_skill("xixing-dafa",1) < 200)
	{
		command("say 在吸星大法上，" + RANK_D->query_respect(ob) +
			"是否还应该多下点功夫？");
		return;
	}
{
			command("say 好吧，既然你我如此投缘，老夫就收下你了。");
                        command("老夫收得如此良徒，东方不败小儿你的报应来拉!");
			command("recruit " + ob->query("id"));
			message_vision(
HIG"\n$N拍着胸膛道：“任老先生，你一世英雄了得，何苦在这地牢之中和腐
土同朽？只须你答允收我为徒，在下言出如山，自当助你脱困。我想老
先生经过一番比剑，当年的豪情胜概，不免在心中又活了起来罢？外边
天地多么广阔，你老爷子出得黑牢，普天下的男女老幼，你要杀哪一个
便杀哪一个，无人敢与老爷子违抗，岂不痛快之极？”\n"NOR, ob);
ob->set("title",HIR"日月神教·任我行亲传弟子"NOR);
  }
}


void die()


{

	object me = query_temp("last_damage_from");


		if(me->query_temp("quest/wuzhao/over")&&!me->query("quest/pass/dugu-jiujian/wuzhao")){
			
message_vision(MAG"\n$N自从学得“独孤九剑”以来，从未遇到过如此强敌，对方招数变幻无方，无法攻其瑕隙,武功之强，已到了常人所不可思议的境界。\n"NOR,me,this_object());
	message_vision(MAG"$N一经$n的激发，“独孤九剑”中种种奥妙精微之处，发挥得淋漓尽致,对独孤九剑的精微奥妙已然彻悟。\n\n",me,this_object());
	me->add_temp("quest/wuzhao/over",1);		
	//东方加1，阿青加1，还有谁剑法更高明？任我行+1？
			
			}




	::die();


}

void unconcious()
{
	die();
}
            
