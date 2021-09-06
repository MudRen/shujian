// NPC: /d/huashan/npc/mmr.c
// Date: Look 99/03/25
// Date: Yuj 2000-08-21
// Date: Looklove 2001-03-30

#include <ansi.h>

inherit NPC;

int do_clone(object, object);

string *k_force =({
	"qiantian-yiyang",
	"huntian-qigong",
	"yijin-jing",
	"bihai-chaosheng",
	"linji-zhuang",
	"yunu-xinjing",
	"xiantian-gong",
	"zixia-gong",
	"xuantian-wuji",
	"guiyuan-tunafa",
	"yinyun-ziqi",
	"shenghuo-shengong",
	"huagong-dafa",
	"shenyuan-gong"
});

string *k_dodge =({
	"piaoyi-shenfa",
	"suibo-zhuliu",
	"tianlong-xiang",
	"tiyunzong",
	"shaolin-shenfa",
	"yunu-shenfa",
	"kunlun-shenfa",
	"shuishangpiao",
	"yanling-shenfa",
	"zhaixingshu",
	"xiaoyaoyou",
	"anying-fuxiang"
});

mapping *skill2=({
/*cuff*/
	(["t_skill" :	"taiji-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"taizu-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"jingang-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"kongming-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"poyu-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"qishang-quan",
	"b_skill" :	"cuff"]),
	(["t_skill" :	"wenjia-quan",
	"b_skill" :	"cuff"]),
/*strike*/
	(["t_skill" :	"qingyan-zhang",
	"b_skill" :	"strike"]),
       (["t_skill" :	"hanbing-mianzhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"xingyi-zhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"sanhua-zhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"banruo-zhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"chousui-zhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"hunyuan-zhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"jinding-mianzhang",
	"b_skill" :	"strike"]),
	(["t_skill" :	"jinshe-zhangfa",
         "b_skill" :	"strike"]),
        (["t_skill" :	"luoying-zhang",
         "b_skill" :	"strike",]),
        (["t_skill" :	"kunlun-zhang",
         "b_skill" :	"strike"]),
        (["t_skill" :	"tiangang-zhang",
         "b_skill" :	"strike"]),
        (["t_skill" :	"sixiang-zhang",
         "b_skill" :	"strike"]),
        (["t_skill" :	"tiezhang-zhangfa",
         "b_skill" :	"strike"]),
        (["t_skill" :	"xianglong-zhang",
         "b_skill" :	"strike"]),
/*hand*/
        (["t_skill" :	"yingzhua-shou",
         "b_skill" :	"hand"]),
        (["t_skill" :	"suohou-shou",
         "b_skill" :	"hand"]),
        (["t_skill" :	"jieshou-jiushi",
         "b_skill" :	"hand"]),
        (["t_skill" :	"juehu-shou",
         "b_skill" :	"hand"]),
        (["t_skill" :	"lanhua-shou",
         "b_skill" :	"hand"]),
        (["t_skill" :	"qianye-shou",
         "b_skill" :	"hand"]),
/*leg*/
        (["t_skill" :	"ruying-suixingtui",
         "b_skill" :	"leg"]),
        (["t_skill" :	"xuanfeng-tui",
         "b_skill" :	"leg"]),
/*finger*/
        (["t_skill" :	"yizhi-chan",
         "b_skill" :	"finger"]),
        (["t_skill" :	"canhe-zhi",
         "b_skill" :	"finger"]),
        (["t_skill" :	"nianhua-zhi",
         "b_skill" :	"finger"]),
/*claw*/
        (["t_skill" :	"yingzhua-gong",
         "b_skill" :	"claw"]),
        (["t_skill" :	"jimie-zhua",
         "b_skill" :	"claw"]),
        (["t_skill" :	"longzhua-gong",
         "b_skill" :	"claw"])

});

void create()
{
	set_name("а��ħͷ", ({ "mo tou", "motou", "mo" }) );
	set("gender", "����");
	set("long", "��һ��������⣬һ�������ɷ��ģ��������������η��\n");
	set("shen", -15000);
	set("age", random(20)+25);
	set("str", 20+random(5));
	set("dex", 20+random(5));
	set("int", 30+random(5));
	set("con", 30+random(5));
	set("per", 10+random(10));
	set("combat_exp", 9999999);

	set("attitude", "peaceful");
	set("max_qi",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("max_jing",9999);
	set("eff_jing",9999);
	set("jing",9999);
	set("eff_jingli", 9999);
	set("neili", 9999);
	set("jiali", 50);
	set("max_neili",9999);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);

	setup();
	if (clonep()) {
		carry_object(ARMOR_D("armor/cloth"))->wear();
                switch (random(20)) {
			case 1:
				carry_object("/d/shaolin/obj/18muou");
				break;
			default:
				add_money("gold", 5+random(5));
		}
		call_out("dest", 300);
	}
}

void init()
{
	string name1;
	object ob = this_player();
	object me = this_object();

	::init();
	name1=ob->query("id");
	if (interactive(ob)
	&& !environment(ob)->query("no_fight")
	&& (query_temp("killer") == name1 )) {
		if (!query_temp("skillset")) {
			if (!ob->is_busy()) ob->add_busy(2);
			command("say ��ͺ¿�����ܣ���������������²��ɣ�����\n");
			remove_call_out("dest");
			call_out("dest", 120);
			set_leader(ob);
			do_clone(me, ob);
			command("slogan " + name1);
		} else {
			command("say ��ͺ¿�����ܣ���������������²��ɣ�\n");
			ob->add_busy(1);
			set_leader(ob);
			remove_call_out("dest");
			call_out("dest", 120);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
		}
	}
}

void kill_ob(object ob)
{
	if (!objectp(ob))
		return;
	if (ob->query("id") != query_temp("killer")) {
		ob->remove_killer(this_object());
		command("nonsense mo tou");
	} else
		::kill_ob(ob);
}

void fight_ob(object ob)
{
	if (ob->query("id") != query_temp("killer")) {
		ob->remove_killer(this_object());
		command("nonsense mo tou");
	} else
		::fight_ob(ob);
}

int do_clone(object me, object ob)
{
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;

	number = (int)ob->query("max_pot");
	number = number-100;
	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	killerskill1 = skill2[random(sizeof(skill2))];
	number -= (random(10)?1:-1) * random(number/10);

	if ( ob->query("combat_exp") > 500000 ) {
		me->set("jiali", 50+random(50));
		me->set("str", ob->query("str")*5/4);
		me->set("dex", ob->query("dex")*5/4);
		me->set("int", ob->query("int")*5/4);
		me->set("con", ob->query("con")*5/4);
		if ( random(10))
			me->set("double_attact", 1);
	}
	else{
		me->set("str", ob->query("str"));
		me->set("dex", ob->query("dex"));
		me->set("int", ob->query("int"));
		me->set("con", ob->query("con"));
		number -= random(10);
		me->set("jiali", 50);
	}

	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill("literate",number);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"], number);
	me->set_skill(killerskill1["b_skill"], number);

/* set killer's  skill maps */

	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);

/* set killer's skill prepares */

	me->prepare_skill(killerskill1["b_skill"], killerskill1["t_skill"]);

/* copy entire dbase values */

	me->set("max_qi", k_qi*6/5);
	me->set("eff_qi", k_qi*6/5);
	me->set("qi", k_qi*6/5);
	me->set("max_jing", k_jing*6/5);
	me->set("eff_jing", k_jing*6/5);
	me->set("eff_jingli", k_jing*6/5);
	me->set("jing", k_jing*6/5);
	me->set("max_neili", k_neili*6/5);
	me->set("neili", k_neili*6/5);
	me->set("combat_exp", ob->query("combat_exp"));

	me->set_temp("skillset",1);
	me->set_leader(ob);
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, ob);
	return 1;
}

void dest()
{
	object me = this_object();

	say(me->name()+ "���������̵ģ����ӻ����£��»��������£�\n");
	say(me->name()+ "�Ҵ��뿪��\n");
	destruct(me);
}
