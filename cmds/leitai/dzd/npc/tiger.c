// /d/dzd/npc/tiger.c
inherit __DIR__"animal";

void create()
{
	set_name("�ϻ�",({"tiger","laohu"}));
	set("race","Ұ��");
	set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
	set("verbs",({"claw","bite"}));
	set("attitude","peaceful");
	set("age",5);
	set("combat_exp",3000000);
	set("long","����һֻ���͵��ϻ���\n");
	set("max_qi",8000);
	set("max_jing",3500);
	set("max_neili",7000);
	set("neili",7000);
	set("jiali",200);
	set("eff_jingli",4000);
	set("jingli",4000);
	set("str",100);
	set("con",100);
	set("dex",100);
	set("chat_chance", 10);
       set("chat_msg", ({
		(: random_move :),
		"�ϻ�ͻȻ���һ����������һ����\n",
		"�ϻ��������������β�͡�\n",
		}));
	set_temp("apply/attack",200);
	set_temp("apply/damage",200);
	set_temp("apply/armor",800);
	setup();
}


