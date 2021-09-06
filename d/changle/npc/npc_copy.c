// By River@SJ

inherit NPC;
#include <ansi.h>
#include "npc_skill.h"

int do_kill(object me);

void create()
{
	string weapon;
	mapping name, skills;
	int i, j;

	i = random(4);

	name = RNAME_D->get_random_name(i);
	skills = npc_skills[random(sizeof(npc_skills))];
	set_name(name["name"], name["id"]);
	set("gender", (i==0?"Ů��":"����"));
	set("age", 30 + random(40));
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 25);
	set("dex", 30);
	set("int", 25+random(5));
	set("con", 30);

	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("eff_jingli", 4000);
set("no_party_job",1);
	set_skill("literate", query("int") * 10);
	set("difficult", skills["difficult"]);
	set("team", skills["team"]);
	set("family_type", skills["family"]);

	for( j = 0; j < sizeof(keys(skills)); j ++){
		if ( keys(skills)[j] == "family") continue;
		if ( keys(skills)[j] == "difficult") continue;
		if ( keys(skills)[j] == "team") continue;
		set_skill(keys(skills)[j], 500);
		set_skill(values(skills)[j], 500);
		map_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "cuff")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "claw")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "finger")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "strike")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "leg")
			prepare_skill(keys(skills)[j], values(skills)[j]);
		if ( keys(skills)[j] == "hand")
			prepare_skill(keys(skills)[j], values(skills)[j]);

		switch (keys(skills)[j]) {
			case "family":	
			case "team":
			case "force":
			case "difficult":
			case "dodge":
			case "parry":
			case "hand":
			case "cuff":
			case "strike":
			case "claw":
			case "leg":
			case "finger":	continue;
			case "sword":	weapon = "sword";	break;
			case "blade":	weapon = "blade";	break;
			case "hook":	weapon = "hook";	break;
			case "dagger":	weapon = "dagger";	break;
			case "whip":	weapon = "whip";	break;
			case "brush":	weapon = "brush";	break;
			case "staff":	weapon = "gangzhang";	break;
			case "club":	weapon = "gun";		break;
			case "axe":	weapon = "axe";		break;
			case "hammer":	weapon = "falun";	break;
			case "stick":	weapon = "zhubang";	break;
			case "throwing":weapon = "shizi";	break;
			default :	weapon = "none";	break;
		}
	}

	if (! random(2))
		weapon = "none";

	setup();

	if ( weapon != "none")
		carry_object(BINGQI_D(weapon))->wield();

	carry_object(ARMOR_D("cloth"))->wear();
}
