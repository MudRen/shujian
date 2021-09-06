// Modify By LOOKLOVE@SJ 2000/1/8

#include <ansi.h>

inherit FIGHTER;

inherit F_UNIQUE;
inherit F_SAVE;

/*
string *skill = ({
	"longzhua-gong", "yizhi-chan", "jingang-quan",
	"qianye-shou",  "sanhua-zhang","xianglong-zhang",
	"yiyang-zhi", "tanzhi-shentong", "poyu-quan",
	"anran-zhang","luoying-zhang","hanbing-mianzhang",
	"nianhua-zhi", "qishang-quan","yiyang-zhi",
});

string *force = ({
	"yijin-jing",  "yijin-jing", "yijin-jing",
	"yijin-jing",  "yijin-jing","huntian-qigong",
	"qiantian-yiyang", "bihai-chaosheng","zixia-gong",
	"yunu-xinjing","bihai-chaosheng","shenghuo-shengong",
	"yijin-jing","jiuyang-shengong","qiantian-yiyang",
});

string *perform = ({
	"canyun",  "wofo", "fumo",
	"qianshou", "sanhua","paiyun",
	"sandie",  "shentong", "leidong",
	"xiaohun","pikong","xixue",
	"fuxue","qishang","sandie",
});

string *base = ({
	"claw",  "finger", "cuff",
	"hand",  "strike","strike",
	"finger",  "finger", "cuff",
	"strike","strike","strike",
	"finger","cuff","finger",
});

*/
void create()
{
	set_name("������ʿ", ({"xixia wushi", "wu shi", "wushi", "shi"}));
	set("title", "һƷ��");
	set("init",0);

	set("gender", "����");
	set("age", 20 + random(60));
	set("long", "��������һƷ�ôӽ������ؽ���Ƹ��һ�����ָ��֡�\n" );
	if( random(20) < 1 )
		set("double_attack",1);

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 10000);
	set("max_jing", 10000);
	//set("neili", 12000);
	//set("max_neili", 912000);
	//set("jiali", 10000);
	set("eff_jingli", 10000);
	set("combat_exp", 2000000);
	set("score", 20000);
	set("jiali",10);
	set("no_get",1);
	set("no_quest", 1);
	set_skill("wuxing-zhen",200);
	
        setup();
}

void init()
{
	object me,ob,cloth;
	int lvl;
	//string s_skill,s_force,s_perform,s_base;
	int index;
	object *lineup;

	::init();
	me = this_player();
	ob = this_object();

	if( query("init") == 0
	 && me->query_temp("smy_job")
	 && userp(me) ) {
	 	
	 	set("init", 1);
	 	
		if( me->query_temp("smy_job/lvl")){
			lvl = me->query_temp("smy_job/lvl");
		}
				
		else {
			if(!me->query_lineup()){
				lvl = me->query("max_pot");
			}
			else {
				lineup = me->query_lineup();
				lvl = 0;
				for(index=0;index<sizeof(lineup);index++){
					if( lineup[index]->query("max_pot") > lvl )
						lvl = lineup[index]->query("max_pot");
				}
			}
			lvl = lvl - 105 + random(5);
		}
		
		lvl += me->query_temp("smy_job/finish")*5;
		
		setparty(me->query_temp("smy_job/finish"),lvl,lvl*lvl*lvl/10*6/5 );

		set("ciwei_level",me->query_temp("smy_job/finish"));
				
		set_name("������ʿ", ({"xixia wushi","wu shi", "wushi", "shi"}));
		set("title", "һƷ��");		
		/*				
		index = random( sizeof( skill ) );

		s_skill = skill[ index ];
		s_force = force[ index ];
		s_perform = perform[ index ];
		s_base = base[ index ];

		set("gender", "����");
		set("age", 20 + random(60));

		set("combat_exp", lvl*lvl*lvl/10*6/5);
		set("meitude", "peaceful");
		set("str", 20 + random(5));
		set("int", 15 + random(5));
		set("con", 20 + random(5));
		set("dex", 20 + random(5));
		set("shen", 0);

		set("max_qi", 4500+lvl*lvl*lvl/20000*(1 + sizeof(lineup)));
		set("max_neili", 3000+lvl*lvl*lvl/15000*(1+sizeof(lineup)));
		set("max_jing", 3000);
		set("eff_jingli", 4000);
		set("neili",query("max_neili")*3/2);
		set("qi",query("max_qi"));
		set("jiali",lvl/ 5);

		set_skill(s_skill, lvl );
		set_skill(s_force, lvl );
		set_skill(s_base, lvl);
		set_skill("dodge", lvl);
		set_skill("force", lvl);
		set_skill("parry", lvl);
		set_skill("tiyunzong", lvl);
		set_skill("qimen-bagua", 200);
		set_skill("literate", 200);
		set_skill("poison", 200);
		map_skill("force", s_force);
		map_skill("dodge", "tiyunzong");
		map_skill("parry", s_skill);
		map_skill(s_base, s_skill);
		prepare_skill(s_base, s_skill);

		set("chat_chance_combat", 60);
		set("chat_msg_combat", ({
			(: perform_action, s_base + "." + s_perform :)
		}) );
		
		*/
		
		set("max_neili",query_skill("force")*8 + query("combat_exp")/1000);
		set("max_jingli",query_skill("force")*8);
		set("eff_jingli",query_skill("force")*8);

		copy_state();
		setup();
		reincarnate();
								
		cloth = new(ARMOR_D("cloth"));
		cloth->set("name",HIC"���ĳ���"NOR);
		cloth->move(ob);
		cloth->wear();
		add_money("silver", 20+random(30));
		
		if(me->query_temp("smy_job/finish")>4) add_money("gold", 1+random(3));
		
		set("neili",query("max_neili")* 2);
		
		call_out("check",1,ob,me);
		if(!me->query_lineup()) {
			ob->kill_ob(me);
		}
		else {
			lineup = me->query_lineup();
				for(index=0;index<sizeof(lineup);index++){
					if( present(lineup[index]->query("id"),environment(me) ))
						ob->kill_ob(lineup[index]);
				}
		}
	}
}

void check(object ob, object me)
{
	if( !ob ) return;
		
	checking(ob,me);
	
	command("lineup with xixia wushi 1");
	command("lineup with xixia wushi 2");
	command("lineup with xixia wushi 3");
	command("lineup with xixia wushi 4");
	command("lineup with xixia wushi 5");
	command("lineup form wuxing-zhen");
	command("lineup with xixia wushi 1");
	command("lineup with xixia wushi 2");
	command("lineup with xixia wushi 3");
	command("lineup with xixia wushi 4");
	command("lineup with xixia wushi 5");
					
	if( !me
	 || !me->query_temp("smy_job")
	 || me->query("qi")<1000
	 || environment(me)!=environment(ob)){
		tell_room(environment(ob), "������ʿ������������׼�����쳷��˵��ת����ȥ��\n");
		me->delete_temp("smy_job");
		me->apply_condition("job_busy",20+random(20));
		me->apply_condition("smy_job",0);
		destruct(ob);
		return;
	}
	call_out("check",1,ob,me);
}

void unconcious()
{
	object ob = this_object(),me;
	me = ob->query_temp("last_damage_from");
	if(!me || !objectp(me)){
		::unconcious();
		return;
	}
	if( userp(me)
	 && !me->query_temp("smy_job")
	 && !me->query_lineup()
	 && me->query("combat_exp") > ob->query("cobmat_exp")/2 ){
	 	
	 	me->add_condition("killer", 5);
	 	
		reincarnate();
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi")*6/5);
		set("eff_jing", query("max_jing"));
		set("jing", query("max_jing"));
		set("jingli", query("eff_jingli"));
		set("neili",query("max_neili")*3/2);
		return;
	}
	::unconcious();
	return;
}

void die()
{
	object me, ob;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

	if(!objectp(me)){
		::die();
		return;
	}
	if( userp(me)
	 && !me->query_temp("smy_job")
	 && !me->query_lineup()
	 && me->query("combat_exp") > ob->query("combat_exp")/2 ){
	 	me->add_condition("killer", 5);
		new(__DIR__"xixia-wushi")->move(environment(me));
	}
	::die();
}
