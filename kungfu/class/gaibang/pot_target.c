// By River@SJ 3/29/2002

#include <ansi.h>
inherit NPC;
int ask_food(string name);

void create()
{
	mapping name;
	int i;
        
	i = random(4);

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"]);
	set("gender", (i==0?"Ů��":"����"));
	set("age", random(20)+25);      
	set("str", 20+random(5));
	set("int", 20+random(5));  
	set("con", 20+random(5));     
	set("dex", 20+random(5));
	set("location", 1);
	set("combat_exp", 100000);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("no_quest", 1);
	set("max_qi",1200);
	set("max_jing",1200);
	set("neili",1000);
	set("eff_jingli", 1200);
	set("max_neili",1000);

	set_skill("force", 100); 
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", query("int")* 10);
	set("inquiry", ([
		"�������" :	(: ask_food , "�������":),
		"С�����" :	(: ask_food , "С�����":),
		"Сţ����" :	(: ask_food , "Сţ����":),
		"�����" :	(: ask_food , "�����":),
		"����" :	(: ask_food , "����":),
	]));

	setup();
	call_out("dest", 1200, this_object());
	carry_object(ARMOR_D("cloth"))->wear();
}

void dest(object ob)
{
	if (!ob) return;
	if (!environment(ob)) return;
	message_vision("$N����ͻȻ����ʲô�£�����ææ���߿��ˡ�\n", ob);
	destruct(ob);
}

int ask_food(string name)
{
	object me = this_player();
	object ob;
	string food_id;
	int i;

	if ( query_temp("food_name") != name 
	|| query_temp("target") != me
	|| !me->query_temp("potjob/job"))
		return 0;

	if ( me->query_temp("potjob/value/"+ query("id"))){
		command("say ����ʲô����һ�ڼۣ��Ҷ�˵�ˣ���Ҫ�����ˡ�");
		return 1;
	}

	food_id = query_temp("food_id");

	switch(random(3)){
		case 0: 
			command("en "+me->query("id"));
			random_move();
			break;
		case 1: 
			if (objectp(ob= present(food_id, this_object()))){
				ob->set_temp("job_id", me);
				command("give "+ food_id +" to "+me->query("id"));
				if ( ob->move(me)) {
					command("say �ţ���Ҫ�Ļ�������ȥ�ɡ�");
					me->set_temp("potjob/be_get/"+ob->name(), 1);
					if ( me->query_temp("potjob/pot_job_place/"+query("name")))
						me->delete_temp("potjob/pot_job_place/"+query("name"));
					dest(this_object());
				}
				else {
					command("say �����϶���̫���˰ɣ�");
					random_move();
				}
			}
			else tell_object(me, "�쳣���⣬����Wiz���棡\n");
			break;
		case 2: 
			i = 10 + random(10);
			command("say �ٺ٣�����Ҫ��ʾ��ʾ�ɣ���"+chinese_number(i)+"�����Ӱɡ�");
			me->set_temp("potjob/value/"+ query("id"), i*100);
			break;
	}
	return 1;
}

int accept_object(object me, object obj)
{
	object ob;
	string food_id;
	int i = me->query_temp("potjob/value/" + query("id"));
	
	if (i < 1)
		return 0;
	
	food_id = query_temp("food_id");
	
	if (! obj->query("money_id")) {
		command("say ����Ǯ����ʲô����Ҳ��Ҫ��");
		return 0;
	}

	if ( obj->value() >= i ){
		if (objectp(ob= present(food_id, this_object()))){
			ob->set_temp("job_id", me);
			command("give "+ food_id +" to "+me->query("id"));
			if ( ob->move(me)) {
				command("say �ţ���Ҫ����ȥ�ɡ�");
				me->set_temp("potjob/be_get/"+ob->name(), 1);
				if ( me->query_temp("potjob/pot_job_place/"+query("name")))
					me->delete_temp("potjob/pot_job_place/"+query("name"));
				call_out("dest", 1, this_object());
				return 1;
			}
			else {
				command("say �����϶���̫���˰ɣ�");
				random_move();
				return 0;
			}
		}
		else 
			return notify_fail("�쳣���⣬����Wiz���棡\n");
	}
	command("say ��򷢽л��Ӱ���");
	return 0;
}

void unconcious()
{
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

void kill_ob(object ob)
{
	object me = this_object();

	command("!!!");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

void accept_fight(object ob)
{
	command("peace "+ ob->query("id"));
	return;
}
