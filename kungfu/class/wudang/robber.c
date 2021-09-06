// Modify By River@SJ

inherit FIGHTER;
//inherit F_UNIQUE;
#include <ansi.h>

int do_kill(object me);
int do_kick(string target);
/*
string *sword_skill = ({
"taiji-jian","xuantie-jianfa","fumo-jian","jinshe-jianfa","qingmang-jian","yuxiao-jian",
"yunu-jianfa","songshan-jian","murong-jianfa","huashan-jianfa", "duanjia-jianfa",
"huifeng-jian","liangyi-jian","quanzhen-jianfa" });

string *blade_skill = ({
"cibei-dao","fanliangyi-dao","liuhe-daofa","murong-daofa","qingmang-jian","wenjia-daofa",
"shandian-daofa","xiuluo-dao","xuanxu-daofa", "yanxing-daofa",});

string *staff_skill = ({ "wuchang-zhang","fengmo-zhang","tianshan-zhang","xinyuegong" });

string *club_skill = ({ "weituo-chu","zui-gun","weituo-gun","xinyuegong" });

string *whip_skill = ({ "piaomiao-bianfa","riyue-bian" });

string *dodge_skill = ({
"shuishangpiao","suibo-zhuliu","yanling-shenfa","yufeng-xiang","tianlong-xiang",
"yunu-shenfa","zhaixingshu","xiaoyaoyou","zhongyuefeng","huashan-shenfa","tiyunzong" });

string *weapon_list = ({ "chui","sword","blade","whip","gun","sword","gangzhang","blade" });
*/

string *first_title = ({"����","����","����","��ԭ","����","����","�ӱ�","����"});
string *second_title = ({ "�ݿ�","կ��","���","ɽ��","����","����", "����"});

void create()
{
	string title;
	
	title = first_title[random(sizeof(first_title))];
	title += second_title[random(sizeof(second_title))];
/*	s_sword = sword_skill[random(sizeof(sword_skill))];
	s_blade = blade_skill[random(sizeof(blade_skill))];
	s_club  = club_skill[random(sizeof(club_skill))];
	s_whip  = whip_skill[random(sizeof(whip_skill))];
	s_staff = staff_skill[random(sizeof(staff_skill))];
	s_dodge = dodge_skill[random(sizeof(dodge_skill))];
	weapon = weapon_list[random(sizeof(weapon_list))];
*/
	set_name("������",({"wuming shi"}));
		
	set("long","��һ�һ�������ɷ��ģ����ʱ��ʱ����а�����Ц��\n");
	set("title", HIW+title+NOR);
	set("age", 20 + random(50));
	
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 25);
	set("dex", 30);
	set("int", 30);
	set("con", 30);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("no_heal",1);
	set("no_ansuan",1);
set("no_party_job",1);
        set("no_bark", 1);

/*	set_skill("huagu-mianzhang", 500);
	set_skill("strike", 500);
	set_skill("xinyuegong", 500);
	set_skill("taiji-shengong", 200);
	set_skill("sword", 500);
	set_skill("dodge", 500);
	set_skill("cuff", 500);
	set_skill("force", 500);
	set_skill("parry", 500);
	set_skill("blade", 500);
	set_skill("hammer", 500);
	set_skill("club", 500);
	set_skill("staff", 500);
	set_skill("whip", 500);
	set_skill("literate",500);
	set("env/no_protect", 1);
*/
/*	set_skill(s_sword, 500);
	set_skill(s_blade, 500);
	set_skill(s_club, 500);
	set_skill(s_whip, 500);
	set_skill(s_staff, 500);
	set_skill(s_dodge, 500);
	map_skill("force", "taiji-shengong");
	map_skill("sword", s_sword);
	map_skill("dodge", s_dodge);
	map_skill("parry", "taizuquan");
	map_skill("hammer", "xinyuegong");
	map_skill("blade", s_blade);
	map_skill("club", s_club);
	map_skill("whip", s_whip);
	map_skill("staff", s_staff);
	map_skill("strike", "huagu-mianzhang");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("cuff", "taizuquan");
*/
	setup();
/*	carry_object(BINGQI_D(weapon))->wield();*/
	carry_object(ARMOR_D("yexing-yi"))->wear();
	add_money("silver", random(10)+20);
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );
	if (clonep())
		call_out("dest", 800);
}
void init()
{
	object ob;
	::init();
	add_action("do_kick","kick");   
	if( interactive(ob = this_player())){
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}
////���ÿ�������fighter�ĺ���
int do_kill(object ob)
{
	object me = this_object();
	if(!ob) return 0;
	if (me->query_temp("kicked")) {  
		message_vision(HIR""+me->name()+"��$N˵����" + RANK_D->query_rude(ob) +"����׷���ᣬ��Ȼ�Ӳ�����"+RANK_D->query_self_rude(me) +"����ƴ�ˣ�\n\n"NOR,ob);
		me->delete_temp("kicked");
	} else if (me->query_temp("fight_failed")) {
		message_vision(HIR""+me->name()+"����$N˵�����ٺ٣��е��Ҹ�������"+RANK_D->query_self_rude(me) +"�������ˣ�\n\n"NOR,ob);
		me->delete_temp("fight_failed");
	} else 
		message_vision(HIR""+me->name()+"����$N����һ����Ц��˵������Ȼ�������" + RANK_D->query_rude(ob)+ "ײ���ˣ���Ҳ��ֻ�����������ˣ�\n\n"NOR,ob);
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
	::do_kill(ob);
}

int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	if(!ret) return 0;
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
        if(!living(ob) && living(me) && me->query("jing")>0 && me->query("jingli")>0 && me->query("qi")>0  ){
		remove_call_out("checking");
		ob->set_temp("wd/wd_job_lost",1);
		ob->set("qi",100);																			//��ֹ�����������
		ob->set("jing",100);
		ob->set("jingli",100);
		tell_room(environment(me), "\n"+me->query("name")+"��һ�������Ӳ������ˣ�ת��������Ͳ����ˡ�\n");
		destruct(me);
		 return 1;
	}
	if(!ob || environment(ob)!= environment(me)){
		remove_call_out("checking");
		 remove_call_out("do_lost");
		 call_out("do_lost",0);
		 return 1;
	}
}

void greeting(object ob)
{
	object me = this_object();

	if (!ob
	 || !present(ob)
	 || me->query_temp("target") != ob->query("id"))
		return;

	if (ob->query_temp("wd/wd_job")){
		if (environment(me)->query("no_fight")) {
			me->delete_temp("fight_failed");
			me->delete_temp("kicked");
			if (random(2)==0) {
				message_vision(HIR""+me->name()+"����$N�߹�������ɫ��Щ�쳣����æ������ͷ��\n"NOR,ob);
				tell_object(ob, HIR"���̲�ס��ݺ���(kick)����һ�һ�š�\n"NOR);
			} else {
				message_vision(HIR""+me->name()+"����$N����һ����Ц��˵����"+ RANK_D->query_rude(ob)+ "������ط�̫С�����ָ�"+ RANK_D->query_self_rude(me) +"������Ȼ��Ȼ���\n\n"NOR,ob);
				me->random_move();				
			}
			me->set_temp("fight_failed",1);
		} else {		
			ob->add_busy(1);
			me->start_busy(1);
			//remove_call_out("checking");
			//call_out("checking", 1, me, ob);
			remove_call_out("dest");
			call_out("dest", 600);
			remove_call_out("do_kill");
			call_out("do_kill", 0, ob);
		}
	}
}

int do_kick(string target)  
{
	object me = this_object();
	object ob = this_player();
	if (target && present(target, environment()) == me) {	
		if (!me->query_temp("fight_failed")) return 0;	
		message_vision(HIR"$N����"+me->name()+"һ���߹�ȥ��"+ RANK_D->query_rude(me) +"������������㣡"+me->name()+"���Ʋ������һ���������Ӵܡ�\n\n"NOR,ob);
		me->random_move();
		me->delete_temp("fight_failed");
		me->set_temp("kicked",1);
		return 1;
	} else {
		return 0;
	}
}

void dest()
{
	destruct(this_object());
}

void do_lost()
{
	object me,ob;
	me = this_object();
	ob = find_player(me->query_temp("target"));
	if(!ob) return;
	ob->set_temp("wd/wd_job_lost",1);
	tell_room(environment(me), "\n"+me->query("name")+"��һ�������Ӳ������ˣ�ת��������Ͳ����ˡ�\n");
	destruct(me);
}

void unconcious()
{
	object me,ob;
	object* obs;
	int i;

	me = this_object();
	ob = find_player(me->query_temp("target"));
	obs = deep_inventory(me);	
	obs = filter_array(obs,(:$1->query("imbued"):));
	i = sizeof(obs);
	while(i--)
	{
		obs[i]->move(environment(me));
		message_vision("$N����"+obs[i]->name()+"��\n",me);
	}
	if (!ob) {
		destruct(me);
		return;
	}
	if (!present(ob)) {
		ob->set_temp("wd/wd_job_lost2",1);
		ob->set_temp("wd/wd_job_lost2_man",this_player()->query("name")+"("+this_player()->query("id")+")");
		tell_room(environment(me), "\n"+me->query("name")+"��һ�������Ӳ������ˣ�ת��������Ͳ����ˡ�\n");
		destruct(me);
		return;
	}
	ob->set_temp("wd/wd_jobok",1);
	tell_room(environment(me), "\n"+me->query("name")+"��һ�������ã���ת��������Ͳ����ˡ�\n");	
	destruct(me);
}

void die()
{
	object me,ob;

	me = this_object();
	ob = find_player(me->query_temp("target"));
	if (!ob) {
		destruct(me);
		return;
	}
	if (!present(ob)) {
		ob->set_temp("wd/wd_job_lost2",1);
		ob->set_temp("wd/wd_job_lost2_man",this_player()->query("name")+"("+this_player()->query("id")+")");
		tell_room(environment(me), "\n"+me->query("name")+"��һ�������Ӳ������ˣ�ת��������Ͳ����ˡ�\n");
		destruct(me);
		return;
	}
	
	ob->set_temp("wd/wd_jobok",1);
	::die();
}
