// snake.c ؤ����Ӽ���ѱ������
// Looklove 2000/10/23
//���˵��
//snake
//	owner	����
//player
//	snake/succesee	��¼ѱ�߳ɹ�
//	snake/failure	��¼ѱ��ʧ�ܴ���
//	snake/friendly	��¼�ߵ����ƶ�
//	snake/aggress	��¼�ߵ��ײ�
//snake�����չ���������aggress�����ȣ���friendly�ɷ���

inherit NPC;

#include <ansi.h>

int do_clone(object me, object ob);

void create()
{
	set_name("��", ({ "snake","she" }) );
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("shen", -15000);
	set("attitude", "killer");
	set("age", 1+random(3));
	set("combat_exp", 9999999);
	set("no_get",1);
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
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("unarmed",300);

	setup();
	
}

void kill_ob(object me)
{
	object snake = this_object();
	
	me->remove_killer(snake);
	remove_killer(me);
	message_vision(HIW"$n�ݵ�����ݴԲ����ˡ�\n"NOR,me,snake);
	destruct(snake);
}

void init()
{
	object me,snake;

	me = this_player();
	snake = this_object();

	if (me->query("snake/success") 
	    && !me->query("snake/failure") 
	    && !snake->query_temp("skillset") 
	    && snake->query("owner")==me->query("id"))
	{
		do_clone(snake, me);
       		if (random(me->query("snake/aggress"))>random(me->query("snake/friendly"))) {
			message_vision(BLU"$nͻȻ���Դ󷢣�����$N���־���һ�ڡ�\n"NOR,me,snake);
       			message_vision(HIR"$N����Ѫ˳����������������\n"NOR,me);
			me->apply_condition("snake_poison",4+me->query_condition("snake_poison"));
		}
		else message_vision(HIM"$n�����Ƶض���$Nҡ��ҡβ�͡�\n"NOR,me,snake);
		snake->set_leader(me);
       		message_vision("$N���߾�����$Nһ���ж���\n",me);
	}
	if (!living(snake)) {
		remove_call_out("dest");
		call_out("dest",1);
	}
} 

int do_clone(object snake, object me)
{
	int number,k_qi,k_neili,k_jing,k_jingli,jiali,friendly,aggress;
	
	snake->set("name",me->query("name")+"����");
	snake->set_temp("owner",me->query("id"));
	
	number = (int)me->query("max_pot") /10;
	k_qi = (int)me->query("max_qi");
	k_jing = (int)me->query("max_jing");
	k_jingli = (int)me->query("eff_jingli");
	k_neili = (int)me->query("max_neili");
	jiali = (int)me->query_skill("force",1);
	friendly = (int)me->query("snake/friendly",1);
	aggress = (int)me->query("snake/aggress",1);
	
	
	snake->set_skill("force",number*10-100);
	snake->set_skill("dodge",number*10-100);
	snake->set_skill("parry",number*10-100);
	snake->set_skill("unarmed",number*10-100);
	
	snake->set("max_qi",k_qi);
	snake->set("eff_qi",k_qi);
	snake->set("qi",k_qi);
	snake->set("max_jing",k_jing);
	snake->set("eff_jing",k_jing);
	snake->set("eff_jingli",k_jingli);
	snake->set("max_jingli",k_jingli);
	snake->set("jingli",k_jingli);
	snake->set("jing",k_jing);
	snake->set("max_neili",k_neili);
	snake->set("neili",k_neili*2-1);
	snake->set("neili",k_neili);
	snake->set("jiali", jiali);
	snake->set("combat_exp",me->query("combat_exp"));

	snake->add_temp("apply/attack",  (int)(number*aggress/friendly));
	snake->set_temp("apply/dodge", (int)(number*aggress/friendly));
	
	snake->set_temp("skillset",1);
	return 1;
}

void dest()
{
	object owner,snake;
	string who;
	
	snake = this_object();
	
	if (!living(snake))
	{
		remove_call_out("dest");
		call_out("dest", 10);
		return;
	}

	who = snake->query_temp("owner");
	if (who) {
		owner=find_player(who);
		if (!owner) owner = find_living(who);

		if (owner) owner->delete_temp("snake");
	}

	message_vision(HIW"$NŤ��Ťβ�ͣ���֪��ô�Ͳ����ˡ�\n"NOR,snake);
	destruct(snake);
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",victim->query_condition("snake_poison") + 6+random(5));
	return 1;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
