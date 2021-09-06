// bing.c ʿ��

#include <ansi.h>
inherit NPC;
#include "name.h";

void create()
{
    string name,m1,m2,m3,m4;
    int i;
    i=random(4);
m1=names[i][random(sizeof(names[i]))];	
m2=names[0][random(sizeof(names[0]))];
m3=names[1][random(sizeof(names[1]))];
m4=names[2][random(sizeof(names[2]))];

switch (random(3)){
	case 0:  
        name = m1+m2; 
 	break;
	case 1: 
        name = m1+m2+m3; 
	break;
	case 2:
        name = m1+m2+m3+m4 ;  
	break;
	} 
	set_name(name, ({ "shi bing", "bing" }));
	set("age", random(10)+20);
	set("gender", "����");
	set("long", "�������������ı����ˣ�����ެ�����ӵܱ���רְ�ʳ�������ΰ���\n");
	set("attitude", "peaceful");
        set("title",HIY"��ެ�ͻ�Ӫʿ��"NOR);

	set("str", 25);
	set("dex", 20);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("unique", 10);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		name+"�ȵ���������С������ò��ͷ��ˣ������������£�\n",
		name+"�е�����Χס���������������ˣ�\n",
	}));
	setup();
	carry_object(BINGQI_D("juchidao"))->wield();
	carry_object(ARMOR_D("pidun"))->wear();
	carry_object(ARMOR_D("pixue"))->wear();
	carry_object(ARMOR_D("pijia"))->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && living(this_object()) &&
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
}

int accept_fight(object me)
{
	command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	if (!is_killing(me->query("id")))
		me->add_condition("killer", 15);
	kill_ob(me);
	return 1;
}
