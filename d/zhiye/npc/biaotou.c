// biaotou
// by augx@sj  9/18/2001

// Modified by mxzhao 2004/03/06 

#include <ansi.h>
#include <wanted.h>
inherit NPC;

#include "biaotou.h"

void create()
{	
	set_name("����ͷ",({ "zong biaotou" , "biaotou" }) );
	set("gender", "����" );
	set("age", 53);
	set("long", "��λ���������ھֵ�����ͷ����˵����ʱ����������е��֡�\n"
		"������Ȼ���ˣ����������ȴ棬�����Դ˿�������������ھ֡�\n");
		
		set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("no_quest", 1);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 2000000);
	
	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
//	set_skill("duanzao", 150);
	
	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);
	
	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		"����ͷ˵���������ھ��ر��ó�����ƽ�����......��\n",
	}) );
	
	// Modified by mxzhao 2004/03/06 
	/* 	
	set("inquiry", ([
	"����"		: (: ask_guard :),
	"guard"		: (: ask_guard :),
	"����1"		: (: ask_guard1 :),
	"guard1"	: (: ask_guard1 :),
	"����2"		: (: ask_guard2 :),
	"guard2"	: (: ask_guard2 :),
	"����3"		: (: ask_guard3 :),
	"guard3"	: (: ask_guard3 :),
	]));
	*/
	// End
	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("sword"))->wield();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say �Ϸ����ˣ����ɱɱ�����鲻Ҫ�����ҡ�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say �Ϸ����ˣ����ɱɱ�����鲻Ҫ�����ҡ�");
	return 0;
}

