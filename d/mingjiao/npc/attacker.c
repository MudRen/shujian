inherit NPC;
int do_copy(object me);

string *sword_skill = ({ 
"taiji-jian","damo-jian","fumo-jian","jinshe-jianfa","qingmang-jian","yuxiao-jian",
"yunu-jianfa","songshan-jian","murong-jianfa","huashan-jianfa", "duanjia-jianfa",
"huifeng-jian","liangyi-jian","quanzhen-jianfa" }); 

string *blade_skill = ({ 
"cibei-dao","fanliangyi-dao","liuhe-daofa","murong-daofa","qingmang-jian","wenjia-daofa", 
"shandian-daofa","xiuluo-dao","xuanxu-daofa", "yanxing-daofa",}); 

string *staff_skill = ({ "wuchang-zhang","fengmo-zhang","tianshan-zhang","xinyuegong" }); 

string *club_skill = ({ "weituo-chu","zui-gun","weituo-gun","xinyuegong" }); 

string *whip_skill = ({ "piaomiao-bianfa","qingxu-bian" }); 

string *dodge_skill = ({ 
"shuishangpiao","suibo-zhuliu","yanling-shenfa","yufeng-xiang","tianlong-xiang",
"yunu-shenfa","zhaixingshu","xiaoyaoyou","zhongyuefeng","huashan-shenfa","tiyunzong" }); 

string *weapon_list = ({ "chui","sword","blade","whip","gun","sword","gangzhang","blade" }); 

string *first_name = ({ "�����","������","������","��������","ɽ��","̽��","��ʿ" }); 

void create()
{
        string s_sword,s_blade,s_club,s_whip,s_staff,s_dodge, weapon, name;        
        name = first_name[random(sizeof(first_name))];
        s_sword = sword_skill[random(sizeof(sword_skill))];
        s_blade = blade_skill[random(sizeof(blade_skill))];
        s_club  = club_skill[random(sizeof(club_skill))];
        s_whip  = whip_skill[random(sizeof(whip_skill))];
        s_staff = staff_skill[random(sizeof(staff_skill))];
        s_dodge = dodge_skill[random(sizeof(dodge_skill))];
        weapon = weapon_list[random(sizeof(weapon_list))];

        set_name(name, ({ "attacker"}));
        set("gender", "����");
        set("age", 20 + random(40));
        set("long", "��һ�һ�������ɷ��ģ����ʱ��ʱ����а�����Ц��\n");
        set("combat_exp", 20000);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 22);
        set("con", 24);
        set("dex", 25);
        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);
        set_skill("taizu-quan", 30);
        set_skill("xinyuegong", 30);
        set_skill("cuff", 30);
        set_skill("force", 30);
        set_skill("yinyun-ziqi", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("blade", 30);
        set_skill("hammer", 30);
        set_skill("club", 30);
        set_skill("staff", 30);
        set_skill("whip", 30);
        set_skill(s_sword, 30);
        set_skill(s_blade, 30);
        set_skill(s_club, 30);
        set_skill(s_whip, 30);
        set_skill(s_staff, 30);
        set_skill(s_dodge, 30);
        map_skill("force", "yinyun-ziqi");
        map_skill("sword", s_sword);
        map_skill("dodge", s_dodge);
        map_skill("parry", "taizu-quan");
        map_skill("hammer", "xinyuegong");
        map_skill("blade", s_blade);
        map_skill("club", s_club);
        map_skill("whip", s_whip);
        map_skill("staff", s_staff);
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");         
        setup();
        carry_object(BINGQI_D(weapon))->wield();
        carry_object(ARMOR_D("yexing-yi"))->wear();
        add_money("silver", random(10));
}	
		
void unconcious()
{    
        tell_room(environment(this_object()), this_object()->query("name")+"ת��������Ͳ����ˡ�\n", ({this_object()}));	
        destruct(this_object());        
}

int do_copy(object me)
{
        object ob, weapon;
        string my_id, type, type1;
        int i;
        ob = this_object();

        if(!me) ob->unconcious();
        my_id = me->query("id");
        weapon = ob->query_temp("weapon"); 

	i = me->query("max_pot") - 100;
	if ( me->query("combat_exp", 1) < 500000)
		i -= 10;

	i -= random(10);
	if ( me->query("combat_exp", 1) < 500000)
		ob->set("combat_exp", me->query("combat_exp")/5*4);
	else
		ob->set("combat_exp", me->query("combat_exp"));

	if(weapon) {
		type = weapon->query("skill_type");
		type1 = ob->query_skill_mapped(type);
		ob->set_skill(type, i);
		ob->set_skill(type1, i);
        }
        ob->set_skill("force", i);
        ob->set_skill("cuff", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill(ob->query_skill_mapped("dodge"), i);
        ob->set_skill("xinyuegong", i);  
        ob->set_skill("yinyun-ziqi", i);     
        ob->set_skill("taizu-quan", i); 
        ob->set("max_qi", me->query("max_qi")); 
        ob->set("max_jing", me->query("max_jing")); 
        ob->set("max_neili", me->query("max_neili"));
        ob->set("jiali", ob->query_skill("force")/4);
        ob->reincarnate(); 
        ob->set("eff_jing", me->query("eff_jing"));
        ob->set("jingli", me->query("jingli"));
        ob->set("neili", me->query("max_neili"));
        ob->set("qi", me->query("max_qi"));
        command("stare " + me->query("id"));
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        ob->set("victim", me->query("id"));
        return 1;
}

int checking(object me, object ob)
{
	if(!ob) return 0;
	if(!me || environment(me)!= environment(ob)) ob->unconcious();
	if(!ob) return 0;
	if(ob->is_fighting()){
		call_out("checking", 1, me, ob);
		return 1;
	}
	else if(!ob->is_killing(me->query("id")) ) {
		ob->kill_ob(me);
		call_out("checking", 1, me, ob);
		return 1;
	}
	else ob->unconcious();
	return 1;
}

int accept_fight(object victim)
{
	command("say ������������");
	kill_ob(victim);
	return 1;
}
