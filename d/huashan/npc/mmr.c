// NPC: /d/huashan/npc/mmr.c
// Date: Look 99/03/25

inherit NPC;
#include <ansi.h>
#include "skill.h"
#include "mmr.h"
string ask_leave();
//a
void create()
{
	set_name("������", ({ "mengmian ren", "ren" }) );
	set("gender", "����");
	set("long","��һ��������⪬һ�������ɷ��ģ��������������η��\n");
	set("shen", -15000);
	set("attitude", "killer");
	set("age", random(20)+25);
	set("str", 30+random(5));
	set("int", 25+random(6));
	set("con", 30+random(5));     
	set("dex", 30+random(5));
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
set("no_party_job",1);
	set("chat_chance", 20);
	set("chat_msg", ({                                                                                                                      
		(: random_move :),           
	}));

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("literate", query("int") * 10);
	set_skill("cuff", 300);

        set("inquiry", ([
		"����" : (: ask_leave :), //add by caiji
	]));

//        if (random(10) < 3)
//        add_money("gold", 1);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

//caiji��river��������
string ask_leave()
{
        object me;
        me = this_object();
        if(environment(me)->query("no_fight")){
        	 random_move();
        }
        return "����������ְɣ�\n";

}

void heart_beat()
{
	object me = this_object();

	::heart_beat();

	if (!me) return;
	if (!environment(me)) return;
	if ( environment(me)->query("no_fight")) 
		random_move();

	if ( me->is_fighting()
	 && me->query("cure") < me->query("max_cure")
	 && me->query("eff_qi") < me->query("max_qi")/5*4
	 && me->query("combat_exp") > 2500000){
		me->receive_curing("qi", me->query("max_qi")/5);
		me->receive_curing("jing", me->query("max_jing"));

		me->set("jing", me->query("max_jing"));
		me->add("qi", me->query("max_qi")/5);
		me->add("cure", 1);
	}
}
