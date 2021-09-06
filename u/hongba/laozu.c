// laozu.c 血刀老祖
// by iceland
// by emnil

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/d/suzhou/npc/lchj.h";
#define QUESTSD "quest/雪山/shendao"
string ask_xuedao();
string ask_zijindao();
string ask_jiasha();
string ask_diyun();
string ask_jidao();
void create()
{
	object weapon , armor;

	set_name("血刀老祖", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
	set("long",@LONG
他身材高瘦，眼窝深陷，一双眼睛射出凶狠的光芒，令人不敢直视。他在江湖
中以残忍好色而著称，曾凭一手血刀经的功夫斗败无数中原的武林豪杰。
LONG
	);
	set("title", HIR "大轮寺血刀门掌门" NOR);
	set("gender", "男性");
	set("class", "huanxi");
	set("no_bark",1);
	set("age", 65);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 39);
	set("int", 30);
	set("con", 35);
	set("dex", 35);
	set("max_qi", 11500);
	set("max_jing", 8000);
	set("eff_jingli", 8000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 250);
	set("combat_exp", 4200000);
	set("score", 50000);
	set("unique", 1);

	set_skill("huanxi-chan", 200);
	set_skill("literate", 250);
	set_skill("force", 380);
	set_skill("longxiang-boruo", 380);
	set_skill("dodge", 340);
	set_skill("yuxue-dunxing", 340);
	set_skill("claw", 350);
	set_skill("tianwang-zhua", 320);
	set_skill("hand", 350);
	set_skill("dashou-yin", 320);
	set_skill("blade", 350);
	set_skill("xuedao-jing", 380);
	set_skill("parry", 340 );

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "xuedao-jing");
	map_skill("claw", "tianwang-zhua");
	map_skill("blade", "xuedao-jing");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("大轮寺", 10, "弟子");
	set("class", "huanxi");

	set("env/jixue",10);
	set_temp("xs/shield",1);
	set_temp("xs/longxiang",1);

	set("chat_chance", 2);
	set("chat_msg", ({
	       CYN"血刀老祖抬起头，若有所思的自言自语：“月亮快圆了，得下山杀个人祭祭刀了。”\n"NOR,
	       CYN"血刀老祖恨恨的说：“什么时候再入中原，再闹个天翻地覆！”\n"NOR,
	       CYN"血刀老祖咬牙切齿，眼露凶光地说：“下次来个斩草除根，一个活口也不留！”\n"NOR,
	       CYN"血刀老祖自言自语道：“年纪大了，体力可一点也不含糊。”言下甚为得意。\n"NOR,
	       CYN"血刀老祖自言自语道：“血刀和十三龙象袈裟可是好东西呀，一定要藏好。\n"NOR,
	}) );

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "blade.jixue" :),
		(: perform_action, "blade.shendao" :),
	}));

	set("inquiry", ([
		"血刀":		(: ask_xuedao :),
		"xuedao":	(: ask_xuedao :),
		"紫金刀": 	(: ask_zijindao :),
		"zijin dao":	(: ask_zijindao :),
		"十三龙象袈裟":	(: ask_jiasha :),
		"jiasha":	(: ask_jiasha :),
		"工作":		"爷爷我没空，你去我那徒弟宝象那里问问吧。",
		"job" :		"爷爷我没空，你去我那徒弟宝象那里问问吧。",
		"美女":		"我最喜欢美女啦，你要是能弄几个来孝敬爷爷，嘿嘿...",
		"girl":		"我最喜欢美女啦，你要是能弄几个来孝敬爷爷，嘿嘿...",
		"beauty":	"我最喜欢美女啦，你要是能弄几个来孝敬爷爷，嘿嘿...",
// add quest by tangfeng
		"狄云" : (: ask_diyun :),
		"神照经" : random(2)?"听说是铁骨墨萼梅念笙的内功心法。":"我记得在武馆之内就刻有神照经内功心法。",
		"万震山" : "梅念笙老的弟子。",
		"言达平" : "梅念笙老的弟子。",
		"戚长发" : "梅念笙老的弟子。",
		"梅念笙" : "铁骨墨萼梅念笙，可惜死得冤枉啊。",
		"落花流水":"你说的什么南四奇？哼，除了花老头，其他的都已经被我杀了！",
		"花铁干":"“中平枪花铁干”，这是个无耻的懦夫！",
		"刘乘风":"“柔云剑刘乘风”，哈哈，已经已经被我杀了！",
		"陆天抒":"“仁义陆大刀”，哈哈，已经被我杀了！",
		"水岱":"“冷月剑水岱”，哈哈，已经被我杀了！",
		"水笙":"这小妞早的倒是标志，可惜跑丢了，估计也困死在这雪谷了！",
"祭刀" : (: ask_jidao :),
       ]));

	setup();
	if (clonep()){
		weapon = unew(BINGQI_D("zijin-dao"));
		if(!weapon) weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());
		weapon->wield();
		set_temp("apply/damage",180);

		weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());
		weapon=new(BINGQI_D("xinyuedao"));
		weapon->move(this_object());

		armor=new("/d/xueshan/npc/obj/longxiang-jiasha");
		armor->move(this_object());
		armor->wear();
		set_temp("apply/armor",300);
	}
	add_money("gold",3);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "大轮寺") {
		command("say"+ RANK_D->query_respect(ob) + "不是本寺弟子，在这里捣什么乱？！");
		return;
	}

	if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
		command("say 我大轮寺各种武功均和内功相辅相成。");
		command("say"+ RANK_D->query_respect(ob) + "再熬几个通宵，多多钻研钻研本门的心法吧。");
		return;
	}

	if( (string)ob->query("gender") == "无性" ) {
		command("say"+ RANK_D->query_respect(ob)+ "身体残缺，如何随我修炼？\n");
		return;
	}
	if ((int)ob->query("shen") > -100000) {
		command("hmm");
		command("say 我血刀老祖声名远扬，那些所谓的江湖大侠哪个不是望风而逃？");
		command("say 以你现在的资历，如果收你为徒，恐怕会被人耻笑。");
		return;
	}
	command("say 老祖我就喜欢你这样的年轻人。好，就收你为我弟子吧。");
	command("recruit " + ob->query("id"));

	ob->set("title", HIR"大轮寺血刀老祖亲传弟子" NOR);
}

void reset()
{
	object me = this_object(), ob;

	if (clonep() && (ob = unew(BINGQI_D("xuedao")))) {
		ob->move(me);
		command("wield xue dao");
	}
	if (clonep() && (ob = unew(BINGQI_D("zijin-dao")))) {
		ob->move(me);
		command("wield zijin dao");
	}
	if (clonep() && (ob = unew(ARMOR_D("lx_cloth")))) {
		ob->move(me);
		command("wear shisan longxiang");
	}
}

string ask_xuedao()
{
	object me=this_player() , weapon;
	int i;

	if ((string)me->query("family/family_name") != "大轮寺")
		i = 3;
	else
		i = 1;

	if(me->query_temp("xs/xs_job") >= 1*i) {
		weapon = present("xue dao", this_object());
		if(!objectp(weapon))
			return "血刀现在不在我手里。";

		command("unwield xue dao");
		command("give xue dao to "+me->query("id"));
		me->delete_temp("xs/xs_job");
		return "好，这把血刀你拿去吧，记着多杀几个人来祭刀啊！";
	}
	return "你想要这把刀？你想要就说嘛，虽然你很有诚意地看着我，但还是要说话呀，\n"+
		"你说了我肯定会给你的，不可能你说了我不给你，而你不说我偏要给你吧。";
}

string ask_zijindao()
{
	object me=this_player() , weapon;

	if ((string)me->query("family/family_name") != "大轮寺")
		return "你非我寺中人，这把刀怎么能给你呢！";

	if ((int)me->query("job_time/雪山") < 50 )
		return "心动不如行动，拿点实际成绩来给我看嘛。";

	weapon = present("zijin dao", this_object());
	if (!objectp(weapon))
		return "紫金刀现在不在我手里。";

	command("unwield zijin dao");
	command("give zijin dao to "+me->query("id"));

	return "好，这把紫金刀你拿去吧，记住不要给外人呀！";
}

string ask_jiasha()
{
	object me=this_player() , armor;
	int i;

	if ( me->query("family/family_name") != "大轮寺")
		i = 5;
	else
		i = 1;

	if(me->query_temp("xs/xs_job") >= i) {
		armor = present("shisan longxiang", this_object());
		if(!objectp(armor))
			return "十三龙象袈裟现在不在我手里。";

		command("remove shisan longxiang");
		command("give shisan longxiang to "+me->query("id"));
		me->delete_temp("xs/xs_job");
		return "好，这件十三龙象袈裟你拿去吧，记着多给我找几个姑娘啊！";
	}
	return "心动不如行动，拿点实际成绩来给我看嘛。";
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}
string ask_diyun()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"还是自己小心通缉吧！";
	}
	if(me->query(QUESTDIR1+"over" ))
	{
	   command("claw "+me->query("id"));
	   return "那个癞痢头狄小子怎么突然这么厉害了？";
	}
	if(!me->query(QUESTDIR1+"start" ))
	{
	   command("say");
	   return "被我打到雪谷深沟去了，估计早就饿死了。";
	}
	if(!me->query_temp(QUESTDIR1+"askbaoxiang" ))
	{
	   command("say");
	   command("claw "+me->query("id"));
	   return "哪个狄云？你找谁？";
	}
	if(me->query_temp(QUESTDIR1+"asklaozu"))
	{
	   command("en");
	   return "那个癞痢头我也到处找不到他，应该饿死了！";
	}
	command("smash");
	message_vision(HIY"$N神色自傲地看着$n。\n", ob,me);
	command("noshame");
	me->set_temp(QUESTDIR1+"asklaozu",1);
	return "他竟然和我作对，只能自讨苦吃，被我打到雪谷深沟去了，估计早就饿死了。";
}
string ask_jidao()
{

object me,ob;
	me = this_player();
	ob = this_object();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return ""+RANK_D->query_respect(me) +"还是自己小心通缉吧！";
	}
if( me->query("family/master_name") != "血刀老祖" )
{
return " 你是哪里来的？到这里讨野火吃，当心爷爷的【神刀穿心】！";
}
if( me->query("quest/雪山/shendao/jidao") )
{
return " 你比我都强了，还问我，是不是羞辱你爷爷？";
}

if(!me->query("quest/连城诀/武功/shenzhao"))
{
command("consider");
return " 我发现狄云那小子将血刀经和神照经配合的出神入化，"+RANK_D->query_respect(me) +"你学全神照经了吗？";
}
if(me->query(QUESTSD+"shendao_fail")>=3 && me->query("registered")<3)
{
return " 嘿嘿，我就知道你领悟不了！";
}

if(me->query(QUESTSD+"time") && time()-me->query(QUESTSD+"time")<86400)
{
return " 今天先问到这里，明天吧！";
}
if(me->query(QUESTSD+"combat_exp") && me->query("combat_exp")-me->query(QUESTSD+"combat_exp")<50000)
{
return " 以你当前的经验恐怕还是难以领悟，还是抓紧去练功去吧！";
}

me->set(QUESTSD+"time",time());
me->set(QUESTSD+"combat_exp",me->query("combat_exp"));
if(random(me->query("kar")) < 22 && random(10)==6)
{ 
 
message_vision(HIR"$N神秘兮兮地看着$n。\n", ob,me);
me->set_temp("quest/雪山/shendao/jidao/asklaozu",1); 
command( "say 我发现狄云那小子将血刀经和神照经配合使用，简直出神入化。");
command( "say 但若是我那祭刀......");
message_vision(HIR"$N说到这里突然意识到什么，就此打住不说了。\n", ob,me);
log_file("quest/xueshan/shendao", sprintf("%8s(%8s) 失败%d次学到血刀经绝技。|经验：%d。\n", me->name(1),me->query("id"), me->query(QUESTSD+"shendao_fail"),me->query("combat_exp")) );
return " 不行，虽然你是我徒弟，我也不能告诉你！";

 
}
else
{
me->add(QUESTSD+"shendao_fail",1);
 log_file("quest/xueshan/shendao", sprintf("%s(%s) 血刀经绝技失败%d次。|经验：%d。\n", me->name(1),me->query("id"),me->query(QUESTSD+"shendao_fail"), me->query("combat_exp")) );
command("? "+me->query("id"));
return " 月圆了，是该祭刀了，既然你问起来，就用你的血来祭我这把刀吧。";

}
}
