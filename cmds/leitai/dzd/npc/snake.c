// /d/dzd/npc/snake.c

inherit __DIR__"animal";

void create()
{
	set_name("����",({"snake","she","dushe"}));
	set("race","Ұ��");
	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs",({"bite"}));
	set("attitude","peaceful");
	set("age",3);
	set("combat_exp",3000000);
	set("long","����һֻ���о޶����ߡ�\n");
	set("max_qi",5000);
	set("max_jing",3500);
	set("max_neili",7000);
	set("neili",7000);
	set("eff_jingli",4000);
	set("jingli",4000);
	set("jiali",200);
	set("str",100);
	set("con",100);
	set("dex",100);
	set("chat_chance", 10);
       set("chat_msg", ({
		(: random_move :),
		"����Զ����������Ŀ�ⶢ���㡣\n",
		"��������İ������̳�һ�š�\n",
       }));
	set_temp("apply/attack",200);
	set_temp("apply/damage",200);
	set_temp("apply/armor",800);
	setup();
}

int hit_ob(object me, object victim, int damage)
{
 	victim->apply_condition("snake_poison",
		victim->query_condition("snake_poison") + 6);
       return 0;
}
	