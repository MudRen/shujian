inherit NPC;
#include <ansi.h>

string *skill = ({ 
	"riyue-bian","ranmu-daofa","xuantie-jianfa",
	"taiji-jian","dagou-bang","murong-daofa",
	"murong-jianfa","yuxiao-jian","huifeng-jian",
	"huashan-jianfa","xunlei-jian",
	"tenglong-bifa","songshan-jian","yanxing-daofa",
	"dugu-jiujian",
});

string *force = ({
	"yijin-jing","yijin-jing","yunu-xinjing",
	"yinyun-ziqi","huntian-qigong","shenyuan-gong",
	"shenyuan-gong","bihai-chaosheng","linji-zhuang",
	"zixia-gong","xuantian-wuji",
	"dulong-dafa","hanbing-zhenqi","linji-zhuang",
	"huashan-qigong",
});

string *perform = ({
	"chanrao","fenwo","haichao",
	"chan","chan","daoying",
	"lianhua","qimen","liaoyuan",
	"lianhuan","xunlei",
	"beauty","longfeng","huanying",
	"poqi",
});

string *base = ({
	"whip","blade","sword",
	"sword","stick","blade",
	"sword","sword","sword",
	"sword","blade",
	"whip","sword","blade",
	"sword",
}); 

string *weapon1 = ({
	"whip","blade","sword",
	"sword","zhubang","blade",
	"sword","xiao","sword",
	"sword","blade",
	"whip","sword","blade",
	"sword",
});

void create()
{
	set_name("ħ�̽�ͽ", ({ "jiaotu"}));

	set("init",0);
	set("gender", "����");
	set("age", 20 + random(60));
	set("long", "����һ��ħ�̽�ͽ��\n" );
	set("str", 30 + random(10));
	set("int", 30 + random(10));
	set("con", 30 + random(10));
	set("dex", 30 + random(10));
	set("max_qi",12000);
	set("eff_qi",12000);
	set("qi",12000);
	set("neili",18000);
	set("max_neili",9000);
	set("jingli",4000);
	set("max_jingli",4000);
	set("eff_jingli",4000);
	set("max_jing",4000);
	set("jing",4000);
	set("shen", -100000);
	set("no_get", 1);
	if (!random(10)) set("double_attack",1);

	setup();

	call_out("remove_ob",300,this_object());
}

void remove_ob(object ob)
{
	if(!ob) return;
	destruct(ob);
}

void init()
{
	object ob=this_object();
   	string s_skill,s_force,s_perform,s_base,s_weapon;
   	int lvl,index;

	::init();
	if (!query("dashi")) {
		destruct(ob);
		return;
	}
	if (!query("init")) {
		set("init",1);
		lvl=query("lvl");
		index = random(sizeof(skill));

		s_skill = skill[index];
		s_force = force[index];
		s_perform = perform[index];
		s_base = base[index];
		s_weapon = weapon1[index];
		set("combat_exp", lvl*lvl/10*lvl);
		set("attribude", "peaceful");
  
		set("max_qi",5000+lvl*lvl*lvl/15000);
		set("qi",query("max_qi"));
		set("max_jing", 3000);
		set("max_neili",5000+lvl*lvl*lvl/20000);
		set("eff_jingli",4000);
		set("jiali",100);

		set_skill(s_skill, lvl );
		set_skill(s_force, lvl );
		set_skill(s_base, lvl);
		set_skill("dodge", lvl);
		set_skill("force", lvl);
		set_skill("parry", lvl);
		set_skill("tiyunzong", lvl);
		set_skill("qimen-bagua",200);
		set_skill("poison",200);
		set_skill("buddhism",200);
		set_skill("cuff",lvl);
		set_skill("bangjue",200);
		set_skill("qiankun-danuoyi",200);
		set_skill("poyu-quan",lvl);
		set_skill("xingyi-zhang",lvl);
		set_skill("strike",lvl);

		map_skill("force", s_force);
		map_skill("dodge", "tiyunzong");
		map_skill("parry", s_skill);
		map_skill("cuff","poyu-quan");
		map_skill("strike","xingyi-zhang");
		map_skill(s_base, s_skill);
		prepare_skill("cuff", "poyu-quan");
		prepare_skill("strike", "xingyi-zhang");

		set("chat_chance_combat", 40);
		set("chat_msg_combat", ({
			(: perform_action, s_base + "." + s_perform :)
		}) );
		setup();
		reincarnate(); 
		carry_object(ARMOR_D("cloth"))->wear();
		carry_object(BINGQI_D(s_weapon))->wield();
		add_money("silver",10+random(20));
		set("neili",query("max_neili")*3/2);
	}
	kill_ob(query("dashi"));
	query("dashi")->kill_ob(ob);
}

void die()
{
	object ob1 = query("dashi"), me;
	
	if( !ob1 || !present(ob1)) {
		::die();
		return;
	}

	me = query_temp("last_damage_from");
	if (!objectp(me))
	{
		::die();
		return;
	}

	me->add_temp("sljob/killed",1);

	if (ob1->add("neili",-(ob1->query("max_qi")-ob1->query("eff_qi"))/2) >= 0) {
		ob1->set("eff_qi",ob1->query("max_qi"));
		ob1->set("qi",ob1->query("max_qi"));
	}
	::die();
}
