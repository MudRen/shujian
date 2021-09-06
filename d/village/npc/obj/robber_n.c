// Created by ChinaNet@SD robber_n.c ������2
// 2004/2/10

//add exp By ChinaNet
//by 2004/4/28
//������˽��ԱTitle by server


#define NAME_D    "/inherit/misc/r_name"
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
string *second_title = ({ "��ʯ��˽����","��ʯ��˽Ա","��ʯ��˽����","��ʯ��˽��"});

void create()
{
   string s_sword,s_blade,s_club,s_whip,s_staff,s_dodge, weapon, title;
	mapping name;
	int i;
	
	i = random(3) + 1;

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

   set_name(name["name"], name["id"]);
   set("title", HIW+title+NOR);
	set("gender", (i==0?"Ů��":"����"));
	set("age", 20 + random(40));
	set("long", "���Ų��ս������ؽ�ʦ���ֽ��������˷����ڸ��زɹ���ʯ׼�����־��������\n");
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 40);
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
        set("chat_chance", 50);
        set("chat_msg", ({                                                                                                                      
             (: random_move :),           
        }));
	setup();
	carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("yexing-yi"))->wear();
	if (clonep())
		call_out("dest", 800);
}

void dest()
{
	destruct(this_object());
}

void kill_ob(object me)
{
	mapping skills;
	string *sk;
	object ob = this_object(); 
	int lv,exp,i,j,b_exp,p;
	
	if (me->query("id") != ob->query_temp("target")) 
	{
		me->remove_killer(ob);
		ob->remove_killer(me);
		tell_object(me, ob->query("name")+"����΢΢һЦ����Ȼ���塣�㲻�ɵ�ͣ�����֡�\n");
		return;
	}

	if (ob->query_temp("minejob/level") == "veryhard")
	{ 
           lv = ((int)me->query("max_pot") - 100) * 5/4;
           j = 2; 
	}
		
	else if (ob->query_temp("minejob/level") == "hard")
	{ 
		lv = ((int)me->query("max_pot") - 100) * 5/4;
		j = 2; 
	}
		
	else if (ob->query_temp("minejob/level") == "normal")
	{ 
		lv = ((int)me->query("max_pot") - 100) * 6/5;
		j = 5/3; 
	}
		
	else 
	{ 
		lv = ((int)me->query("max_pot") - 100) *7/6;
		j = 4/3; 
	}
		
	exp = me->query("combat_exp");
	b_exp = 300000;
	p = random(3)+1;
	
	if(!me) 
		return 0;

	if (exp < 500000)
	{
	     	ob->set("combat_exp",exp);
	     	lv = lv *(p+6)/10;
	}
	else 
	{
                ob->set("combat_exp",(exp+random(20000*(exp/b_exp)*p)));
	     	lv = lv *(p+8)/10;
	}     
	ob->set("qi",(int)me->query("max_qi") * j);
	ob->set("max_qi", (int)me->query("max_qi") * j);
	ob->set("eff_qi", (int)me->query("max_qi") * j);
	ob->set("jing",(int)me->query("max_jing") * j);
	ob->set("max_jing",(int)me->query("max_jing")* j);
	ob->set("eff_jing",(int)me->query("max_jing")* j);
	ob->set("neili",(int)me->query("max_neili") * j);
	ob->set("max_neili",(int)me->query("max_neili") * j);
	ob->set("jingli",(int)me->query("max_jingli") * j);
	ob->set("eff_jingli",(int)me->query("max_jingli") * j);
	if ( p == 3 && random (10) == 1 && exp > 1000000)
		ob->set("double_attack", 1);
	skills = ob->query_skills();
	if (mapp(skills))
	{
		sk = keys(skills);
		for (i=0;i<sizeof(sk);i++)
			ob->set_skill(sk[i] ,lv);
	}
	me->kill_ob(ob);
	::kill_ob(me);
}

void die()
{
	object me,ob,mine;
	int exp, i, j;

	ob = this_object();
	me = find_player(ob->query_temp("target"));
	if (me)
	{		
		me->set_temp("minejob/find",1);
		mine = present("kuang shi", ob);
		if ( mine ) 
		{
			i = me->query("minejob");
			j = me->query("minejob_failed");
			if( i >= j*10 && j < 500)
			{
				exp = mine->query("value") / 2000 ;//add exp By ChinaNet
				if( exp > 350 ) exp = 300 + random(50);
				if( exp < 100 ) exp = 50 + random(50);
				me->add("combat_exp",exp);
				tell_object(me,"\n�����˶����" + chinese_number(exp) + "�㾭�齱����\n");
			}
			mine->move(me);
			me->set_temp("minejob/killed",1);
			tell_object(me,"\n�����ֽ�" + mine->query("name") + "����������\n");
				log_file("job/minejob",sprintf("%s %s(%s)���ٵ���%s����Ŀ�ʯ��Npc:%s(%s)����ʯ��%s\n",
					ctime(time())[4..19],me->name(1),capitalize(me->query("id")),mine->query("level"), ob->query("name"),ob->query("id"),mine->query("name")));

		}
	}
	::die();
}

