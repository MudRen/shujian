//Yanqi 10/04/2k
// Lklv@SJ 2001.10.22

inherit NPC;
#include <ansi.h>

int do_clone(object me, object ob);

void create()
{
	set_name("��", ({ "du she","dushe", "she", "snake" }) );
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }));
	set("shen", -15000);
	set("attitude", "killer");
	set("age", 3+random(10));
	set("combat_exp", 9999999);
	set("shen_type", -1);
	set("max_qi",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("max_jing",9999);
	set("eff_jing",9999);
	set("jing",9999);
	set("max_jingli",9999);
	set("eff_jingli",9999);
	set("jingli",9999);
	set("neili",9999);
	set("jiali", 99);
	set("max_neili",9999);
        set("score", 10000);
	set("chat_chance", 10);
	set("chat_msg", ({
		"һ�����ڲݴ����̳�һ�š�\n",
		"һ������������������ȱ�������ȥ��\n",
		"һ�������������������˹�����\n",
		(: random_move :)
	}));

        call_out("dest",500+random(200));
        setup();
}

void kill_ob(object me)
{
        object ob = this_object();

        if (!me->query_temp("gb_snake/start")
             && ob->query_temp("name1")!=me->query("id")) {
		me->remove_killer(ob);
                remove_killer(me);
                message_vision("$N����$n��������$P��\n", me, ob);
                return;
        }
      	::kill_ob(me);
}

void init()
{
        object ob = this_player();
        object me = this_object();
        string name1;

	::init();

	name1 = ob->query("id");
	if (me->query_temp("name1")==name1
	 && ob->query_temp("gb_snake/start")
	 && !ob->query_temp("gb_snake/over")
	// && !ob->query("no_pk")
	// && ob->query_temp("user_type") != "worker"
	){
		message_vision("$nͻȻ���ֲݴ�����һ��$N��\n",me,ob);
		me->set_leader(ob);
		if (!me->query_temp("skillset")) do_clone(me, ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
		ob->start_busy(2+random(3));
	}
}

int do_clone(object me, object ob)
{
	int number,k_qi,k_neili,k_jing,k_jingli;

	switch (random(11)) {
		case 0: me->set("name","С����");break;
		case 1: me->set("name","�˻���");break;
		case 2: me->set("name","�۾���");break;
		case 3: me->set("name","����");break;
		case 4: me->set("name","�岽��");break;
		case 5: me->set("name","������");break;
		case 6: me->set("name","��β��");break;
		case 7: me->set("name","�Ľ���");break;
		case 8: me->set("name","����");break;
		case 9: me->set("name","������");break;
		case 10: me->set("name","Ұ������");break;
	}

	number = (int)ob->query("max_pot");
	number -= 100;

	k_qi = (int)ob->query("max_qi");
	k_jing = (int)ob->query("max_jing");
	k_jingli = (int)ob->query("eff_jingli");
	k_neili = (int)ob->query("max_neili");

	me->set("max_qi",k_qi*3/2);
	me->set("eff_qi",k_qi*3/2);
	me->set("qi",k_qi*3/2);
	me->set("max_jing",k_jing);
	me->set("eff_jing",k_jing);
	me->set("eff_jingli",k_jingli);
	me->set("max_jingli",k_jingli);
	me->set("jingli",k_jingli);
	me->set("jing",k_jing);
	me->set("max_neili",k_neili);
	me->set("neili",k_neili*2-1);
	me->set("neili",k_neili);
	me->set("jiali", 50);
	me->set("dex",ob->query("dex") + (int)ob->query_skill("dodge",1)/10);
	me->set("combat_exp",ob->query("combat_exp") + ob->query("combat_exp")/10);

	me->add_temp("apply/attack",  number);
	me->add_temp("apply/damage",  number);
	me->add_temp("apply/dodge", number);

	me->set_temp("skillset",1);
	remove_call_out("dest");
	call_out("dest", 500);
	return 1;
}

void dest()
{
	if (!living(this_object())) {
		call_out("dest", 20);
		return;
	}
	message_vision("$N˦��һ��β�ͣ�����ݴ����治���ˡ�\n",this_object());
	destruct(this_object());
}

void unconcious()
{
	object me,snake2,ob;

	me = this_object();
	ob = me->query_temp("last_damage_from");

	if(objectp(ob) && ob->query_temp("gb_snake/start")) {
		ob->set_temp("gb_snake/over",1);
		snake2 = new ("/clone/animal/snake2");
		snake2->move(ob);
		snake2->set("name",me->query("name"));
		snake2->set_temp("name1",me->query_temp("name1"));
		message_vision ("\n$N����һ�ţ������ˡ�$n����ץ��������\n",me,ob);
	}
	destruct(me);
}

void die()
{
	object me, ob;
	me = this_object();
	ob = me->query_temp("last_damage_from");
	if(objectp(ob) && ob->query_temp("gb_snake/start"))
		ob->set_temp("gb_snake/failed",1);
	::die();
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 5+random(5));
	return 0;
}
