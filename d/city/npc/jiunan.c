#include <job_mul.h>
#include <ansi.h>
#include <get_place.h>
inherit NPC;
int check(object ob);
string ask_job();
string ask_fail();
void create()
{
set_name("九难师太", ({ "jiunan shitai", "jiunan" ,"shitai"}));
set("long",@LONG
她就是崇祯皇帝亲生女儿长平公主，名叫朱媺娖，因为排行第九故小名阿九。
李自成攻破紫禁城，崇祯怕其受辱，挥剑砍杀之，一失手软断其一臂，阿九
侥幸存活。中年出家，法号“九难”练就绝世神功，誓为父兄报仇，江湖人
称独臂神尼。
LONG
	);
	set("title", HIG "独臂神尼" NOR);
        set("gender", "女性");
        set("class", "bonze");
        set("age", 45);
        set("per", 24);
        set("str", 31);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1200000);
        set("shen_type", 1);
        set("no_get","她对你来说太重了。\n");
set("no_quest",1);
set("no_bark",1);
        set_skill("sword", 160);
        set_skill("force", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("strike", 160);
set("chat_chance", 30);
set("chat_msg", ({
(: random_move :)
  }) );

set("inquiry", ([
               "劫囚车":        (: ask_job :),
		"job" :		(: ask_job :),
                "失败" :	(: ask_fail :),
		"shibai":	(: ask_fail :),

]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}
string ask_job()
{
	object target, *living , me = this_player() , ob , beauty;
	int i,j;
	string str;
if( me->query("combat_exp") < 100000 )
		return "你的实战经验太少了，派你去我可实在不大放心！";
if( !(wizardp(me) && me->query("env/test")) && me->query("jn/qiuche") && ((time()-(int)me->query("jn/qiuche_time"))<(12*60)) )
		return "我不是叫你到"+me->query("jn/qiuche_place")+"去劫囚车了么？";
if( !(wizardp(me) && me->query("env/test")))
	if( me->query_condition("job_busy") || me->query_condition("jn_job")) {
		if ( me->query("job_name") == "劫囚车") {
		    command("shake "+(string)me->query("id"));
		    return "你先歇歇吧！";
		}
		else
		    return "你还是先休息休息吧。";
	}
me->delete("jn/qiuche_busy");

	if(me->query("shen") < 0 && !wizardp(me)){
		return "我看你面目可疑，是不是鞑子的奸细？";
	}
	if(me->query_temp("quest/busy")) //added by tangfeng 与quest冲突
		return "现在我这里没有给你的任务，你还是先处理好你其他事情再说吧。";

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if(check(living[j]) ){
			target = living[j];
			str = environment(target)->query("short");
			if( str == "武僧堂"
			 || str == HIR"心禅堂"NOR
			 || str == "金刚伏魔圈"
			 || str == HIB"戒律院"NOR) continue;
			if( get_place(base_name(environment(target)))!="" )
				break;
		}
	}


	if( !target )
		return "我最近没听说有什么反清志士要被问斩，你过一会儿再来吧。";

me->apply_condition("job_busy", 40);
	me->apply_condition("jn_job", 40);
	me->set("jn/times", uptime());
	me->set("jn/qiuche",1);
	me->set("jn/qiuche_time",time());
	me->set("jn/qiuche_place",get_place(base_name(environment(target)))+environment(target)->query("short"));

	beauty = new("/quest/jqc/qc");
        beauty->set("guard", me->query("id"));

	beauty->set("long", beauty->query("long")+
		"看来就是九难师太要求"+me->query("name")+"("+capitalize(me->query("id"))+")要劫的囚车。\n");
	beauty->move(environment(target));
	

if(wizardp(me)) tell_object(me, base_name(environment(target))+"\n");
		command("nod");
	command("whisper " + me->query("id")+ " 听说最近"+me->query("jn/qiuche_place")+GRN"附近要路过一辆囚车，上面押解着一名即将问斩的反清志士。");

	return "你帮我劫下它，千万小心。";
}
string ask_fail()
{
	object me = this_player();
	int i;

	if( !me->query("jn/qiuche") )
		return "你根本就没任务，失败什么呀？";

	command("ok "+me->query("id"));

	me->delete("jn/qiuche");
	me->delete("jn/qiuche_time");
	me->delete("jn/qiuche_ob");
	me->delete("jn/qiuche_super");
me->delete_temp("jn/jie");
me->delete_temp("jn/bb");
me->delete("jn/time");
		
	i = 40 - me->query_condition("jn_job");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);

	me->apply_condition("jn_job", 10);

me->apply_condition("jn_job",40);
		me->delete("jn/qiuche_place");
	return "没关系，你有心就行了，下次帮我吧。";
}
void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("九难师太对你摇了摇头，一双明眸甚是清澈。\n", ob);
        message_vision("你心想，我怎能对这位老师太动手？未免太龌龊了。\n", ob);
}

void unconcious()
{
        say( "九难师太口宣佛号，瞬间又恢复了精神。\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
}

void die()
{
        unconcious();
}












int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 
	 || userp(ob)
	 
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("outdoors") == "昆仑翠谷"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/xueshan/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}



