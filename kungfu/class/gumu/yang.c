// yang.c 杨过
// By River 98.8

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_sword();
int pfm_haichao();
int pfm_anran();
string ask_skill();
string ask_skill1();
string ask_skill2();
string ask_quest();

void create()
{
	set_name("杨过",({"yang guo","yang","guo"}));
	set("title",HIW"古墓侠侣"NOR);
	set("nickname",HIY"神雕大侠"NOR);
	set("long", "他就是名满天下的杨过。虽断一臂但仍遮不去一脸的英雄豪气。\n");
	set("age", 39);
	set("attitude", "friendly");
	set("gender", "男性");
	set("shen", 10000);
	set("per", 36);
	set("str", 40);
	set("int", 35);
	set("con", 40);
	set("dex", 35);

        set("max_qi", 10500);
        set("max_jing", 7000);
        set("neili", 18500);
        set("eff_jingli", 7500);
        set("max_neili", 18500);
        set("jiali", 150);
        set("combat_exp", 4800000);
        set("unique", 1);

        set_skill("sword",350);
        set_skill("qimen-bagua",120);
        set_skill("dodge",350);
        set_skill("strike",350);
        set_skill("force", 350);
        set_skill("hand", 350);
        set_skill("cuff", 350);
        set_skill("parry", 350);
        set_skill("yunu-jianfa", 350);
        set_skill("finger",140);
        set_skill("literate", 250);
        set_skill("xiantian-gong", 120);
        set_skill("hamagong",300);
        set_skill("medicine",120);
        set_skill("jingmai-xue", 80);
        set_skill("yunu-shenfa", 350);
        set_skill("xuantie-jianfa", 370);
        set_skill("anran-zhang", 380);
        set_skill("quanzhen-jianfa",360);
        set_skill("tianluo-diwang", 340);
        set_skill("yunu-xinjing",350);
        set_skill("jiuyin-zhengong",160);
        set_skill("meinu-quanfa",220);
        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-zhang");        
        map_skill("hand", "tianluo-diwang");
        map_skill("strike", "anran-zhang");        
        prepare_skill("strike","anran-zhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function, "xinjing" :),
		(: pfm_haichao :),
		(: perform_action, "strike.xiaohun":),
		(: pfm_anran :),
	}));

	create_family("古墓派",3,"男主人");

	set_temp("apply/damage", 70);
	set_temp("apply/dodge", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 70);

	if (random(3))
		set("env/玄铁剑法", "汹涌");

        set("inquiry", ([
		"古墓" : "那日华山与众英雄诀别后和龙儿隐居于此已有数年，不闻世事，能与\n"+
			"龙儿在此长伴一世，此身足矣！",
		"小龙女" : "龙儿乃我爱妻，你问她做甚？",
		"玄铁剑" : (: ask_sword :),
		"玄铁剑法" : (: ask_sword :),
                "武功"  : (: ask_skill :),
                "剑法"  : (: ask_skill1 :),
                "内功"  : (: ask_skill2 :),
                "古墓石刻"  : (: ask_quest :),

	]));

        setup();
	carry_object(BINGQI_D("sword/gangjian"));
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/pao1")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	if(!fam || fam["family_name"] != "古墓派"){
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}
	if(ob->query("gender") != "男性") {
		command("bow "+ ob->query("id"));
		command("say 我可只收男徒，你去找吾妻龙儿试试吧。");
		return;
	}       
	if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
		command("say 内功是古墓武功之基础。"); 
		command("say " + RANK_D->query_respect(ob)+"是否还应该先在内功上多下点功夫？");
		return;
	}   
	if((int)ob->query_int() < 32 ) {
		command("say 我的武功都要极高的悟性才能学会。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say "+RANK_D->query_respect(ob)+"的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	if((int)ob->query("shen") < 10000){
		command("say 我古墓弟子行走江湖中，一向行侠仗义。");
		command("say 这位" + RANK_D->query_respect(ob)+"正气不够，去做几件侠义的事后再来吧？");
		return;
	}
	command("say 嗯，看你还是个学武的料，我就收下你吧！");         
    command("chat 古墓武功重现江湖，"+ ob->name() +"可别让为师看走眼了！");
        command("chat* pat " + ob->query("id"));
	command("recruit " + ob->query("id"));
	ob->set("title",HIW"古墓派神雕侠侣传人"NOR);
}

string ask_sword()
{
	object ob=this_player();
	mapping fam = ob->query("family");

	if ( !fam || fam["family_name"] != "古墓派")
		return RANK_D->query_respect(ob) +"非我古墓传人，不知道此话怎讲？";

	if ( fam["generation"] != 4 )
		return RANK_D->query_respect(ob) +"非我神雕侠侣传人，还是等以后再说吧。";

	if ( ob->query("shen") < -100000)
		return RANK_D->query_respect(ob) +"邪气太重，想必独孤前辈也不愿他的剑法被用来做恶。";

	if ( ob->query("ygpass"))
		return "我不是已经告诉你玄铁剑法的运气之道了么？";

	if ( ob->query("gender")=="男性") {
		command("pat "+ ob->query("id"));
		command("say 当年我在襄阳城南，得遇神雕的相助，于独孤大侠墓前练成玄铁剑法。");
		ob->set("ygpass", 1);
		return "屏气具息，凝气守中，意守丹田，这就是在洪水中运气的诀窍，你好好去领悟一下吧。";
	}
	if ( ob->query("gender") == "女性"){
		if ((int)ob->query_str() < 35 )
			return "这位"+RANK_D->query_respect(ob) +"，玄铁剑法需要极高的膂力，你还是再努力一翻吧。";
		if ((int)ob->query_dex() < 35 )
			return "这位"+RANK_D->query_respect(ob) +"，在洪水中练习玄铁剑法需要极高的身法，你还是再努力一翻吧。";
		if ((int)ob->query_skill("sword", 1) < 200 )
			return "这位"+RANK_D->query_respect(ob) +"的基本剑法还需继续修炼，否则难以抵挡洪水的冲击。";
		if ((int)ob->query_int() < 35 )
			return "这位"+RANK_D->query_respect(ob) +"的悟性还不够高，难以理解我所要讲的口诀。";
		command("pat "+ ob->query("id"));
		command("say 当年我在襄阳城南，得遇神雕的相助，于独孤大侠墓前练成玄铁剑法。");
		ob->set("ygpass", 1);
		return "屏气具息，凝气守中，意守丹田，这就是在洪水中运气的诀窍，你好好去领悟一下吧。";
	}
}

int pfm_haichao()
{
	object me,weapon;
	me = this_object();
	weapon = present("gangjian",me);
	if( me->is_busy()) return 0;
	if( objectp(weapon)){
		set("jiali", 50);
		command("wield jian");
		command("perform haichao");
		if(random(10) > 5){
			set("jiali", 150);
			command("unwield jian");
		}
		return 1;
	}
	else {
		new(BINGQI_D("sword/gangjian"))->move(me);
		set("jiali", 50);
		command("wield jian");
		command("perform haichao");
		if(random(10) > 5){
			set("jiali", 150);
			command("unwield jian");
		}
		return 1;
	}
	return 1;
}

int pfm_anran()
{
	object me,weapon;
	me = this_object();
	weapon = me->query_temp("weapon");

	if(me->is_busy()) return 0;
	if( me->query("eff_qi") < 1 ) return 0;
	if( me->query("max_qi") / me->query("eff_qi") < 2 ) return 0;
	if(objectp(weapon)) weapon->unequip();
	this_object()->set("jiali", 150);
	command("perform anran");
	return 1;
}

string ask_skill()
{
	mapping fam;

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
		return "我与"+RANK_D->query_respect(this_player())+"素无瓜葛，不知此话从何谈起？";

	if( this_player()->query_temp("gumu_skill") )
		return RANK_D->query_respect(this_player()) + "，你可以向我请教‘剑法’或‘内功’方面的问题！";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "的剑法似乎还不够精进啊！";

	if( this_player()->query("gumu_given") >= 300 )
		return RANK_D->query_respect(this_player()) + "，你的武功已经不弱了，我已经没什么可以指教的了。";

	if( this_player()->query_skill("yunu-xinjing", 1) > this_player()->query("gumu_given") + 30 ) {
		this_player()->set_temp("gumu_skill", 1);
		return RANK_D->query_respect(this_player()) + "的内功大有精进，我就指点你几下吧，你可以请教我关于‘"HIY"剑法"CYN"’或‘"HIY"内功"CYN"’的疑问！";
	} else {
		return "我近期不是刚指教过你吗？武学的关键靠的还是自己努力练习啊！\n";
	}
}

string ask_skill1()
{
	object me, ob;
	int skill, pot;
	mapping fam;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
		return "我与"+RANK_D->query_respect(this_player())+"素无瓜葛，不知此话从何谈起？";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "的剑法似乎还不够精进啊！";

	if( !me->query_temp("gumu_skill") )
		return "当年我在襄阳城南，得遇神雕的相助，于独孤大侠墓前练成玄铁剑法！";

	if( (int)me->query_skill("yunu-xinjing", 1) > 300 ) 
		skill = 300 - (int)me->query("gumu_given");
	else skill = (int)me->query_skill("yunu-xinjing", 1) - (int)me->query("gumu_given");

	pot = skill * 10;
	pot += random(pot/2);

	skill /= 30;
	if( skill < 1 ) skill = 1;

	message_vision(HIB"$n微笑不语，将手中的剑从轻而响，从响而轻，忽寂然无声，忽轰轰之声，反复演练着。\n"NOR,me,ob);
	message_vision(HIW"$N照着$n所展示的方法练习，果然武功大有长进。\n"NOR,me,ob);

	me->delete_temp("gumu_skill");
	me->set("gumu_given", (int)me->query_skill("yunu-xinjing", 1));

	me->set_skill("xuantie-jianfa", me->query_skill("xuantie-jianfa", 1) + skill );
	me->set_skill("quanzhen-jianfa", me->query_skill("quanzhen-jianfa", 1) + skill );
	me->set_skill("yunu-jianfa", me->query_skill("yunu-jianfa", 1) + skill );
	me->set_skill("sword", me->query_skill("sword", 1) + skill );
	me->add("potential", pot );

	tell_object(me, HIC"你的「玄铁剑法」进步了！\n"NOR);
	tell_object(me, HIC"你的「全真剑法」进步了！\n"NOR);
	tell_object(me, HIC"你的「玉女素心剑」进步了！\n"NOR);
	tell_object(me, WHT"你的增加了" + chinese_number(pot) + "点潜能。\n"NOR);

	return RANK_D->query_respect(me) + "天资过人，真是个可造之才啊！哈哈哈！";
}

string ask_skill2()
{
	mapping fam;
	object me, ob;
	int skill, neili;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
		return "我与"+RANK_D->query_respect(this_player())+"素无瓜葛，不知此话从何谈起？";

	if( this_player()->query_skill("sword") < 150 )
		return RANK_D->query_respect(this_player()) + "的剑法似乎还不够精进啊！";

	if( !me->query_temp("gumu_skill") )
		return "屏气具息，凝气守中，意守丹田，这就是在洪水中运气的诀窍，你好好去领悟一下吧。";

	if( (int)me->query_skill("yunu-xinjing", 1) > 300 ) 
		skill = 300 - (int)me->query("gumu_given");
	else skill = (int)me->query_skill("yunu-xinjing", 1) - (int)me->query("gumu_given");

	neili = skill/2;
	neili += random(neili/4);

	skill = random(skill)/30;
	if( skill < 1 ) skill = 1;

	message_vision(HBYEL"$n屏气具息，凝气守中，意守丹田，周身真气聚集，正反运行玉女心经。\n"NOR,me,ob);
	message_vision(HIW"$N受了$n的启悟，心中疑团顿时解开，对内功的领悟又更进了一层。\n"NOR,me,ob);

	me->delete_temp("gumu_skill");
	me->set("gumu_given", (int)me->query_skill("yunu-xinjing", 1));

	me->set_skill("yunu-xinjing", me->query_skill("yunu-xinjing", 1) + skill );
	me->set_skill("force", me->query_skill("force", 1) + skill );
	tell_object(me, HIC"你的「玉女心经」进步了！\n"NOR);
	tell_object(me, HIC"你的「基本内功」进步了！\n"NOR);

	me->add("max_neili", neili );
	tell_object(me, WHT"你的内力修为增加了" + chinese_number(neili) + "点。\n"NOR);

	return RANK_D->query_respect(me) + "天资过人，真是个可造之才啊！哈哈哈！";
}


string ask_quest()
{
	mapping fam;
	object me, ob;
	int i, time;

	me = this_player();
	ob = this_object();

	if( !(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
		return "我与"+RANK_D->query_respect(this_player())+"素无瓜葛，不知此话从何谈起？";

   i = me->query("combat_exp") - 1000000;
   i /= 100000;

  time = time() - me->query("quest/gmsuper/time");

   if (me->query("quest/gmsuper/pass") || me->query_temp("quest/gmsuper/ask") ) {
            command("? " + me->query("id"));
	return "我不是已经告诉"+RANK_D->query_respect(this_player())+"你了？";
 
    }

   if ( me->query("quest/gmsuper/time") && time < 86400 ) {
            command("shake " + me->query("id"));
        return HIG"你过"+CHINESE_D->chinese_time(86400-time)+"后再来问吧。";

    }


        if ( me->query("quest/gmsuper/fail") >= i && !me->query("cw_exp"))
                return "我古墓武技尽悉刻于石室之内，" + RANK_D->query_respect(this_player()) + "武功不够精进，还需认真参详才是1。";   

	if( this_player()->query_skill("yunu-xinjing",1) < 550 )
		return "我古墓武技尽悉刻于石室之内，" + RANK_D->query_respect(this_player()) + "武功不够精进，还需认真参详才是2。";


	if( this_player()->query_skill("xuantie-jianfa",1) < 550 )
		return "我古墓武技尽悉刻于石室之内，" + RANK_D->query_respect(this_player()) + "武功不够精进，还需认真参详才是3。";

	if( this_player()->query_skill("yunu-jianfa",1) < 550 )
		return "我古墓武技尽悉刻于石室之内，" + RANK_D->query_respect(this_player()) + "武功不够精进，还需认真参详才是4。";

	if( this_player()->query("relife/gifts/total") < 5 )
		return "我古墓武技尽悉刻于石室之内，" + RANK_D->query_respect(this_player()) + "武功不够精进，还需认真参详才是5。";


   message_vision(HIM"杨过盯着$N看了半响，叹了一口气，又摇摇头，讲出一段古墓秘辛来。\n"NOR+
                           HIG"原来当年王重阳得知林朝英在活死人墓中逝世，心中伤痛实难自已，于是从密道进墓，凭吊自己这位江湖旧侣。\n"+ 
                                "巡视古墓时见到了林朝英所绘自己背立的画像，又见到两间石室所刻武功，但见玉女心经所述武功精微奥妙，\n"+
                                "因一时好胜，便将名震江湖的《九阴真经》要旨刻在全墓最隐秘的地下石室室顶，且留下了“重阳一生，不\n"+
                                "弱于人”的刻字。当日杨过与小龙女被李莫愁所迫，却是无意间发现了这天大的秘密。 \n"NOR, me);
                command("sneer ");     
                command("say 王重阳所留破除玉女心经之法，乃是参照《九阴真经》所载，焉知我古墓玉女心经参考九阴真经再上层楼，又岂是那么容易破得。 ");         
                command("say 我已将我与姑姑毕生所学尽数刻于王重阳遗刻之旁，古墓与全真孰强孰弱，一见便知分晓。");
                command("say 好叫后人得知，这古墓始终是王重阳输给祖师婆婆的。");


me->set_temp("quest/gmsuper/ask",1);
me->set("quest/gmsuper/time",time());
	return RANK_D->query_respect(me) + "天资过人，我古墓武学发扬光大，就全靠你了！哈哈哈！";

/*
这里是素材啦
if( random(15)==1 && random(me->query("kar")) > 28 && me->query("id")=="master")
{
    me->set("quest/gmsuper/pass",1);
  message_vision(HIM"杨过盯着$N看了半响，叹了一口气，又摇摇头，讲出一段古墓秘辛来密。 \n"NOR, me);
    log_file("quest/gmsuper",
            sprintf("%-18s失败%s次后，成功从杨过处得到石刻详情结拜，福：%d。\n",
                    me->name(1)+"("+capitalize(getuid(me))+")",
                    chinese_number(me->query("quest/gmsuper/fail")), 
                    me->query("kar"), 
            ), me    );
	return "杨过“哈哈哈”大笑了几声。";
}

else 
                me->add("quest/gmsuper/fail", 1);
	return "杨过“哈哈哈”大笑了几声。";

*/
}
