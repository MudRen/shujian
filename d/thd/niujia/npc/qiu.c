// qiu.c 丘处机
// Modified By action@SJ 2008/8/12
// Update By action@SJ 2009/2/21
//牛家村丘处机2010/07/27

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

//mixed qzjf_jianjue();

void create()
{
	set_name("丘处机", ({"qiu chuji", "qiu"}));
	set("long",
                "他就是江湖上人称‘长春子’的丘处机丘真人，他方面大耳，\n"
                "满面红光，剑目圆睁，双眉如刀，相貌威严，平生疾恶如仇。\n");
	set("title","全真七子之四");
	set("gender", "男性");
	set("age", 32);
	set("nickname",HIM"长春子"NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 50);
	set("int", 55);
	set("con", 50);
	set("dex", 50);

	      set("max_qi", 4800000);
        set("jing", 240000);
        set("max_jing", 240000);
        set("neili", 510000);
        set("max_neili", 510000);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set_skill("force", 350);
        set_skill("xiantian-gong", 350);
        set_skill("sword", 350);
        set_skill("quanzhen-jianfa",350);
        set_skill("dodge", 350);
        set_skill("jinyan-gong", 350);
        set_skill("parry", 350);
        set_skill("strike", 350);
        set_skill("haotian-zhang", 350);
        set_skill("literate", 200);
        set_skill("hand",350);
        set_skill("finger", 350);
        set_skill("taoism",200);
	      set_skill("medicine", 200);
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");
        set_skill("tiangang-beidouzhen", 140);
        
	      create_family("全真教", 2, "弟子");
	      set("inquiry", ([               
               // "剑诀" : (: qzjf_jianjue :),
                           
        ]));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sanqing" :),
               // (: perform_action, "sword.qixing" :),
                //(: perform_action, "strike.lianhuan" :),
               
        }));
        	setup();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	carry_object("/clone/weapon/sword")->wield();
	add_money("silver",50);
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();

	add_action("do_qingjiao", "qingjiao");

}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 100000) {
               command("say 我全真教乃是堂堂名门正派，对弟子要求极严。");
               command("say 在德行方面，" + RANK_D->query_respect(ob) +
                       "是否还做得不够？");
               return;
       }
       command("say 好吧，贫道就收下你了。");
       command("recruit " + ob->query("id"));
       ob->set("class","taoism");
}

mixed qzjf_jianjue()
{
	object me = this_player();
	object ob = this_object();
	int exp, time, night;
	mixed *local;
	night = 0;
	local = localtime(time() * 60);
	if (local[2] < 5 || local[2] >= 19) night = 1;

	if( me->query("family/family_name") != "全真教" )
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";

  if (!night) 
	  return "我现在无法看见天空中北斗七星，又如何指导你学习全真剑法的剑诀精髓。\n";

	if( me->query("quest/qzjf/jianjue") )
		return RANK_D->query_respect(me) + "，你的剑诀造诣已经不在本道之下了，又何故开此玩笑呢？";

	if( me->query_skill("quanzhen-jianfa", 1) < 300 )
		return RANK_D->query_respect(me) + "，你的剑法造诣不够，还无法领悟我派剑法的精要所在！";

	time = time() - me->query("qzjf/jianjue/time");
	if( me->query("qzjf/jianjue/time") && time < 86400 && !wizardp(me) )
		return "嗯？你不是刚来请教过我剑诀吗？还是再努力段时间吧！";

	exp = me->query("combat_exp") - me->query("qzjf/jianjue/exp");
	if( me->query("qzjf/jianjue/exp") && exp < 100000 && !wizardp(me) )
		return "嗯？你不是刚来请教过我剑诀吗？还是再努力段时间吧！";

	if( me->query_temp("marks/qzjf/qingjiao") )
		return RANK_D->query_respect(me) + "，我刚才不是已经回答你了吗？";

	message_vision(CYN"$N严肃的看着$n，慢慢说道：“我派的全真剑法讲究的是道家观测宇宙星斗北斗七星变换之道，取千变万化、无穷无尽之原理，\n"
	"如不是亲身体会估计很难领悟，近来你的武功已有所小成，如果你有信心，可以来向我请教一下。("HIY"qingjiao"CYN")”\n"NOR, ob, me);

	me->set_temp("marks/qzjf/qingjiao", 1);
	return 1;
}

int do_qingjiao()
{
	object me, ob, weapon, weapon1;

	me = this_player();
	ob = this_object();

	weapon1 = ob->query_temp("weapon");

	if( !me->query_temp("marks/qzjf/qingjiao") ) return notify_fail("什么？\n");

	if( me->is_busy() || me->is_fighting() ) return notify_fail("你正忙着呢。\n");

	if( ob->is_busy() || ob->is_fighting() ) return notify_fail(ob->name()+"正忙着呢。\n");

	if( me->query("qi") < me->query("max_qi")*9/10 )
		return notify_fail("你现在状态不佳，还是等会再请教吧！\n");

	if( me->query("eff_qi") < me->query("max_qi")/2 )
		return notify_fail("你现在重伤在身，还是等会再请教吧！\n");

	if( !weapon = present("qixing jian", me) ) {
		message_vision(CYN"$N对$n说：“请师傅对徒儿进行指点"+RANK_D->query_self(me)+"的全真剑法剑诀！”\n"NOR, me, ob);
		message_vision(CYN"$n说：“" + RANK_D->query_respect(me) + "还是先去找我师傅王重阳取来七星剑吧！”\n"NOR, me, ob);
		me->start_busy(1);
		return 1;
	} else {
		me->start_busy(1);
		message_vision(CYN"$N对着$n将长剑交给师傅说道：“请师傅指点"+RANK_D->query_self(me)+"的全真剑法剑诀！”\n"NOR, me, ob);
		me->delete_temp("marks/qzjf/qingjiao");
		me->set("qzjf/jianjue/time", time());
		me->set("qzjf/jianjue/exp", me->query("combat_exp"));

		if( weapon1 ) weapon1->unequip(ob); 
		weapon->move(ob);
		weapon->wield(ob);
		ob->set("jiali", 0);
		ob->set("neili", query("max_neili")*2 );
		ob->set("jingli", query("eff_jingli")*2 );
		message_vision(HIW"$n默念全真剑诀，“"HBRED+HIW"认星先从北斗来，由北往西再展开”。"NOR+HIW"”顿时剑气纵横，将$N攻个措手不及！"NOR, me, ob);
		ob->set_temp("qzjf/jianjue", 1);
		COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) {
			message_vision(HIW"$n默念全真剑诀，“"HBMAG+HIW"斗柄东指，天下皆春；斗柄南指，天下皆夏。"NOR+HIW"”右手猛的运剑回转，左手终南指法之「一阳指」随劲而起！"NOR, me, ob); 
			weapon->unequip(ob); 
			COMBAT_D->do_attack(ob, me, 0, 1);
			weapon->wield(ob);
		}
		if( me->query("qi") >= me->query("max_qi")*1/10 ) COMBAT_D->do_attack(ob, me, weapon, 1);
		if( me->query("qi") >= me->query("max_qi")*1/10 ) {
			message_vision(HIW"$n默念全真剑诀，“"HBBLU+HIW"斗柄西指，天下皆秋；斗柄北指，天下皆冬。"NOR+HIW"”紧接着"+weapon->name()+HIW"猛的回转再次刺出！"NOR, me, ob);
			COMBAT_D->do_attack(ob, me, weapon, 1);
		}
		ob->delete_temp("qzjf/jianjue");

		if( me->query("qi") < me->query("max_qi")*1/20 ) {
			message_vision(CYN"$n非常失望的对$N说到：“"+me->name()+"，你武功未成，还是等你打好基础再说！”\n"NOR, me, ob);
			weapon->unequip(ob); 
			destruct(weapon);
			if( weapon1 ) weapon1->wield(ob);
			me->start_busy(1);
			me->set_temp("marks/失败", 1);
			return 1;
		}
		weapon->unequip(ob); 
		weapon->move(me);
		message_vision(CYN"\n$n将七星剑交还给$N，愉快的说着：“"+me->name()+"，你自己慢慢琢磨下我所使用的剑诀吧！”\n"NOR, me, ob);
		if( weapon1 ) weapon1->wield(ob);
		message_vision(HIY"\n$N拼命地回忆着刚才的招数，开始认真思索着.........\n", me);
		if( random(me->query("kar")) > 25) {	// 随机福源
			message_vision(HIW"$N突然捕捉住交手瞬间的一幕，自言自语：“前后左右，全无定向，后发制人，先发制于人。”渐渐领悟出全真剑法的真谛。\n", me);
			tell_object(me, BYEL"恭喜你，你于" + NATURE_D->game_time() + "领悟了全真剑诀。\n"NOR);
			me->set("quest/qzjf/jianjue", 1);
		} else {
			message_vision(HIC"$N摇了摇头，道：“好像还是很困难的。”说罢，深深地叹了口气。\n", me);
			me->set_temp("marks/失败", 1);
		}
	}
	return 1;
}

