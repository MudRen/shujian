inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include "skill.h";


string *k_weapon = ({"sword","blade","staff","whip","gun",});
void create()
{
	string weapon;
	weapon = k_weapon[random(sizeof(k_weapon))];

	set_name("Ԫ��", ({ "yuan bing", "bing" }));
	set("gender", "����");
	set("long", "��������װ��˫Ŀ�����������룬����Ѳ�ӡ�\n");
	set("age", random(20)+25);
	set("str", 20+random(5));
	set("int",20+random(5));
	set("con",20+random(5));
	set("dex",20+random(5));
	set("combat_exp", 10000);
	set("no_quest",1);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("max_qi",1000);
	set("max_jing",1000);
	set("eff_jingli",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("score", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	setup();
	carry_object(ARMOR_D("armor"))->wear();
}

void init()
{
	object me=this_object(), ob=this_player();
	mapping killerskill1;
	int number,k_qi,k_neili,k_jing;
	string t_force,t_dodge;
	number = (int)ob->query("max_pot");
	number = number-100;

	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_neili = (int)ob->query("max_neili");

	::init();

	if(!userp(ob)) return;
	if(!ob->query_temp("gb_job2")
    	 && (file_name(environment(ob)))[0..14]=="/d/gb/liangcang"
         && userp(ob)){
    	command("say ʲô�ˣ��ż���\n");
    	message_vision("$N������������Ķ��ӡ�\n",ob);
		ob->move("/d/xiangyang/xuanwumen.c");
		ob->set("qi",100);
		ob->set("eff_qi",100);
		ob->unconcious();
	   	return;
	}

   	command("say �󵨣�����\n");

	killerskill1 = skill2[random(sizeof(skill2))];
	number = (int)(number*(9+random(1))/10);

 	/*set killer's skill*/
	t_force = k_force[random(sizeof(k_force))];
	t_dodge = k_dodge[random(sizeof(k_dodge))];

	me->set_skill("force",number);
	me->set_skill("dodge",number);
	me->set_skill("parry",number);
	me->set_skill(t_force,number);
	me->set_skill(t_dodge,number);
	me->set_skill(killerskill1["t_skill"],number);
	me->set_skill(killerskill1["b_skill"],number);
	me->map_skill("force",t_force);
	me->map_skill("dodge",t_dodge);
	me->map_skill("parry",killerskill1["t_skill"]);
	me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
	/* set killer's skill prepares */
	me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
	/* copy entire dbase values */
	me->set("max_qi",k_qi);
	me->set("eff_qi",k_qi);
	me->set("qi",k_qi);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("jing",k_jing);
	me->set("max_neili",k_neili);
	me->set("neili",k_neili);
	me->set("jiali",(int)(number*3/4)-random(40));
	me->set("combat_exp",ob->query("combat_exp"));
	me->set_temp("skill_set",1);
	me->kill_ob(ob);
	return;
}
