// NPC: /d/huashan/npc/feng.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18
// By KinGSo 增加独孤九剑 无招无式 2010

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_wuzhao();

void create()
{
	set_name("风清扬", ( {"feng qingyang","feng","qingyang"} ) );
	set("long", "他看起来神色抑郁，面如金纸。\n" );
	create_family("华山派", 12, "弟子");

	set("age", 91);
	set("gender", "男性");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("shen",150000);
	set("no_quest",1);

        set("con", 30);
        set("dex", 30);
        set("int", 40);
        set("str", 30);
	set("per", 24);
        set("max_jing", 6000);
        set("max_neili", 15000);
        set("max_qi", 7500);
        set("eff_jingli", 4000);
        set("neili", 15000);
        set("jiali", 100);
        set("combat_exp", 3000000);

        set_skill("sword",550);
        set_skill("force",200);
        set_skill("dodge",300);
	set_skill("poyu-quan", 280);
	set_skill("cuff", 280);
        set_skill("parry",300);
        set_skill("dugu-jiujian",550);
        set_skill("huashan-shenfa",300);
        set_skill("huashan-jianfa",200);
        set_skill("huashan-qigong",200);
        set_skill("zhengqi-jue",200);
        set_skill("hunyuan-zhang",300);
        set_skill("strike",300);

        map_skill("force","huashan-qigong");
        map_skill("sword","dugu-jiujian");
        map_skill("dodge","huashan-shenfa");
	map_skill("parry","dugu-jiujian");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	prepare_skill("strike", "hunyuan-zhang");

	set_temp("apply/damage", 40);
        set_temp("apply/dodge", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/armor", 40);
       set("inquiry", ([
       "无招无式"      : (: ask_wuzhao :),
			]));


	setup();

        carry_object(BINGQI_D("sword"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("fengset")) {
		command("say 你我恐怕今生无缘，这位" + RANK_D->query_respect(ob)+"还是请回吧。");
		command("wave " + ob->query("id"));
		return;
        }
        if (ob->query("shen") < 100000 ) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return;
        }
        if ((int)ob->query_skill("huashan-qigong",1) < 180)
        if ((int)ob->query_skill("zixia-gong",1) < 180){
                command("say 这位" + RANK_D->query_respect(ob)+
                        "，你的特殊内功等级过低，怕不能领悟我独孤九剑精髓。");
                return;
        }
        if ((int)ob->query_skill("huashan-shenfa",1) < 180){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "，你的华山身法等级过低，怕不能领悟我独孤九剑精髓。");
                return;
        }
        if ((int)ob->query_skill("huashan-jianfa",1) < 180){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "，你的华山剑法等级过低，怕不能领悟我独孤九剑精髓。");
                return;
        }
        command("say 好吧，我就收下你了,你可要为我们华山派争口气。");
        command("chat* 脸上浮现出一丝笑容，对着"+ob->query("name")+"笑道：我华山后继有人了。");
        command("chat* nomatch feng");
        command("recruit " + ob->query("id"));
        ob->set("title", HIW"华山派风清扬传人"NOR);
        ob->set("quest/huashan","剑宗");
if( ob->query_skill("zixia-gong",1) > ob->query("huashan-qigong",1)  ) ob->set_skill("huashan-qigong",ob->query_skill("zixia-gong",1)); 
if( !ob->query("quest/zixia/pass") ) ob->delete_skill("zixia-gong");
}

string ask_wuzhao()
{
    object me;
    mapping fam;
    int time;
    me=this_player();
   if ( mapp(fam=me->query("family"))
    && (string)fam["family_name"] != "华山派"){
    command("? "+me->query("id"));
    return "这位" + RANK_D->query_respect(me) + "从哪里听说的独孤九剑啊？\n";
    }
   
   if (me->query("quest/huashan")=="气宗")
       return "以气驭剑？简直就是胡扯！\n";

   if ((int)me->query("combat_exp") < 2700000)
       return "你的实战经验还不足，无法理解独孤九剑的『无招无式』！\n";

   if(me->query("quest/pass/dugu-jiujian/wuzhao", 1))
{
me->set("title",HIW"孤独·求败"NOR);
me->set_temp("title",HIW"孤独·求败"NOR);
      return"你不是已经领悟了无招无式？来消遣老头子我？\n";
}
        

   if(me->query("int") < 35)
		return"独孤九剑奥义需要极高的悟性，依我看" + RANK_D->query_respect(me) + "的资质似乎无法理解？\n";
		
   
   if(me->query("dex") < 32)
		return"独孤九剑奥义需要极高的灵动性，依我看" + RANK_D->query_respect(me) + "的资质似乎无法施展？\n";
		
   if ((int)me->query_skill("dugu-jiujian",1) < 450)
                return"这位" + RANK_D->query_respect(me)+"，你的独孤九剑等级过低，怕不能领悟我独孤九剑奥义。\n";


time=time() - me->query("quest/wuzhao/time");

if( time<=86400 )
	
	   return"独孤九剑，要旨是在一个‘悟’字，我不是已经告诉过你了吗？\n";
        
        command("say 独孤九剑，要旨是在一个‘悟’字，决不在死记硬记。");
        command("say 若是你通晓了这九剑的剑意，则无所施而不可，便是将全部变化尽数忘记，也不相干。");
        command("say 临敌之际，更是忘记得越干净彻底，越不受原来剑法的拘束。");
        command("say 剑上无招，敌人便无法可破，无招胜有招，乃剑法之极诣。。");
        command("addoil" + me->query("id"));
me->set("quest/wuzhao/time",time());
me->set_temp("quest/wuzhao/ask",1);        
		return HIG"活学活使，只是第一步。要做到出手无招，那才真是踏入了高手的境界。\n"NOR;

}









