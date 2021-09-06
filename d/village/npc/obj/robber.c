// Created by ChinaNet@SD robber.c ������2
// 2004/1/29


inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>

int do_kill(object me);

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

string *first_title = ({"���ϸ��¥","���»�","��ػ�","��͢","���","���ٻ�","�˰�"});
string *second_title = ({ "��ʯ�ɹ�����","��ʯ�ɹ�Ա","��ʯ��������","��ʯ����Ա"});

void create()
{
	string s_sword,s_blade,s_club,s_whip,s_staff,s_dodge, weapon,title;
	mapping name;
	int i;
	
        i = random(4) ;

	name = RNAME_D->get_random_name(i);
	title = first_title[random(sizeof(first_title))]; 
	title += second_title[random(sizeof(second_title))];
	s_sword = sword_skill[random(sizeof(sword_skill))];
	s_blade = blade_skill[random(sizeof(blade_skill))];
	s_club  = club_skill[random(sizeof(club_skill))];
	s_whip  = whip_skill[random(sizeof(whip_skill))];
	s_staff = staff_skill[random(sizeof(staff_skill))];
	s_dodge = dodge_skill[random(sizeof(dodge_skill))];
	weapon = weapon_list[random(sizeof(weapon_list))];

        set_name(name["name"], name["id"] + ({ "robber" }));
	set("title", HIW+title+NOR);
	set("gender", (i==0?"Ů��":"����"));
	set("age", 20 + random(40));
	set("long", "���˷����ڸ����Ѽ���ʯ����������������衣\n����¶�׹⣬����һ�����˵�ģ����\n");
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 30);
	set("dex", 30);
	set("int", 30);
	set("no_get","����˱���������\n");
	set("con", 30);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);

	set_skill("huagu-mianzhang", 500);
	set_skill("strike", 500);
	set_skill("xinyuegong", 500);
	set_skill("yinyun-ziqi", 200);
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
	set_skill(s_sword, 500);
	set_skill(s_blade, 500);
	set_skill(s_club, 500);
	set_skill(s_whip, 500);
	set_skill(s_staff, 500);
	set_skill(s_dodge, 500);
	map_skill("force", "yinyun-ziqi");
	map_skill("sword", s_sword);
	map_skill("dodge", s_dodge);
	map_skill("parry", "taizu-quan");
	map_skill("hammer", "xinyuegong");
	map_skill("blade", s_blade);
	map_skill("club", s_club);
	map_skill("whip", s_whip);
	map_skill("staff", s_staff);
	map_skill("strike", "huagu-mianzhang");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("cuff", "taizu-quan");
        set("chat_chance", 5);
        set("chat_msg", ({                                                                                                                      
             (: random_move :),           
        }));
	setup();
	carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("yexing-yi"))->wear();
	if (clonep())
		call_out("dest", 800);
}

void init()
{
	object ob;       

	::init();
	if( interactive(ob = this_player())){
		remove_call_out("settings");
		call_out("settings", 0, ob);
	}
}

void settings(object ob)
{
	object me = this_object();
	
	if (!ob 
	 || !present(ob) 
	 || me->query_temp("target") != ob->query("id"))
		return;

	if (ob->query("minejob/killer")){
		ob->add_busy(1);
		me->start_busy(1);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		remove_call_out("dest");
		call_out("dest",300);
		remove_call_out("do_kill");
		call_out("do_kill", 0, ob);
	}
}

int do_kill(object ob)
{
	mapping skills;
	string *sk;
	object me; 
	int lv,exp,i,j,b_exp,p;
//added by ChinaNet 2004/01/31 ǿ������
	me = this_object();
	
	if (me->query_temp("minejob/level") == "veryhard")
           { lv = (int)ob->query("max_pot") * 5/4;j = 2; }//���ڱ�̬ ��һ��
		
	else if (me->query_temp("minejob/level") == "hard")
		{ lv = (int)ob->query("max_pot") * 5/4;j = 2; }
		
	else if (me->query_temp("minejob/level") == "normal")
		{ lv = (int)ob->query("max_pot") * 6/5;j = 5/3; }
		
	else 
		{ lv = (int)ob->query("max_pot")*7/6;j = 4/3; }
		
	lv = lv-100;
	exp = ob->query("combat_exp");
	b_exp = 300000;
	p = random(3)+1;
	
	if(!ob) return 0;

	if (exp < 500000){
	     me->set("combat_exp",exp);
	     lv = lv *(p+6)/10;
	}
	else {
	     me->set("combat_exp",(exp+random(20000*(exp/b_exp)*p)));
	     lv = lv *(p+8)/10;
	}     
	me->set("qi",(int)ob->query("max_qi") * j);
	me->set("max_qi", (int)ob->query("max_qi") * j);
	me->set("eff_qi", (int)ob->query("max_qi") * j);
	me->set("jing",(int)ob->query("max_jing") * j);
	me->set("max_jing",(int)ob->query("max_jing")* j);
	me->set("eff_jing",(int)ob->query("max_jing")* j);
	me->set("neili",(int)ob->query("max_neili") * j);
	me->set("max_neili",(int)ob->query("max_neili") * j);
	me->set("jingli",(int)ob->query("max_jingli") * j);
	me->set("eff_jingli",(int)ob->query("max_jingli") * j);
	if ( p == 3 && random (10) == 1 && exp > 1000000)
	me->set("double_attack", 1);
	skills = me->query_skills();
	if (mapp(skills)){
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			skills[sk[i]] = lv;
	}
	message_vision(HIW"\n"+ob->name()+"����һ�����󺰣�" + RANK_D->query_rude(me)+ "��С�����ǲ�����͵�Ҷ����ˣ�\n\n"NOR,ob);
	message_vision(HIW""+me->name()+"������Ц��˵����" + RANK_D->query_rude(ob)+ "���Ҿ������㶫���ˣ����������ҺΣ������ɣ�\n\n"NOR,ob);
	me->kill_ob(ob);
	remove_call_out("checking");
	call_out("checking", 1, me, ob);     
}

void dest()
{
	destruct(this_object());
}

void kill_ob(object ob)
{
	if (ob->query("id") != query_temp("target")) {
		ob->remove_killer(this_object());
		this_object()->remove_killer(ob);
		tell_object(ob, this_object()->query("name")+"����΢΢һЦ����Ȼ���塣�㲻�ɵ�ͣ�����֡�\n");
		return;
	}
	::kill_ob(ob);
}

void die()
{
	object me,ob,mine;

	me = this_object();
	ob = find_player(me->query_temp("target"));
	if (ob)
	{		
		mine = present("kuang shi", me);
		if ( mine ) 
			{
				mine->move(ob);
				ob->set_temp("minejob/killed",1);
				tell_object(ob,"\n�����ֽ�"+mine->query("name")+"����������\n");
			}
	}
	::die();
}

int checking(object me, object ob)
{
	if(!me) return 0;
	if((!me->query("qi") >= me->query("max_qi")/2) && (me->query_temp("cure") < 2)){
		 me->add("qi",me->query("max_qi")/4);
		 me->add_temp("cure",1);
		 tell_room(environment(me), me->query("name")+"��������˿�������ɫ��ʱ������ࡣ\n", ({me})); 
	}

	if(ob->is_fighting(me)){
		 remove_call_out("checking");
		 call_out("checking", 1, me, ob);
		 return 1;
	}
	else if(!me->is_killing(ob->query("id"))){
		 me->kill_ob(ob);
		 remove_call_out("checking");
		 call_out("checking", 1, me, ob);
		 return 1;
	}
	return 1;
}
