//by cool 98.6.1
// Modify By River@SJ 8/30/2001
// Validate By YUJ@SJ 2002-01-17

#include <ansi.h>
inherit NPC;

#include "skill.h";

string *color_title = ({"��ɱ��", "��ɷ��"});

void create()
{
	mapping name;
	int i;

	i = random(4);

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"] + ({ "killer" }));
	set("title", color_title[random(sizeof(color_title))]+(i?"":"Ů")+"ɱ��");
	set("gender", i?"����":"Ů��");
	set("long", "��������ɫ��װ����������һ��ڲ���ֻ¶��һ˫�۾����������䡣\n");
	set("age", random(20)+25);
	set("str", 18+random(5));
	set("int",20+random(5));
	set("con",20+random(5));
	set("dex",20+random(5));
	set("combat_exp", 100000);
	set("no_quest", 1);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("max_qi",1200);
	set("max_jing",1200);
	set("neili",1000);
	set("max_neili",1000);
	set("eff_jingli", 1200);
	set("score", 100);


	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", query("int")* 10);

	setup();
	//if (!random(3))
		//add_money("gold", random(3)+1);

	carry_object("/d/dali/obj/blackcloth")->wear();
}

#include "stealer1.h"
