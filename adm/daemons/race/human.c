// human.c
// From ES2
// Modified by Yu Jue@JY

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":		"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":		"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":		"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":		"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":		"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�", "���", "�Ҷ�", "����", "����", "С��"
	}) );
}

void setup_human(object ob)
{
	mapping my;
	int qi_age;

	my = ob->query_entire_dbase();

	ob->set_temp("default_actions", __FILE__);
	
	if( undefinedp(my["age"]) ) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);
	if (undefinedp(my["pur"])) my["pur"] = 10 + random(21);

	if( userp(ob) || undefinedp(my["max_jing"]) ) {
		my["max_jing"] = (my["con"] + my["int"]) * 8 - 100;
		if( my["age"] <= 70 ) my["max_jing"] = 100 + (my["con"] + my["int"]) * 8 - (my["age"] - 50) * 10;
		if( my["age"] <= 50 ) my["max_jing"] = 100 + (my["con"] + my["int"]) * 8;
		if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["con"] + my["int"]) * (my["age"] - 14) / 2;
		if( my["age"] <= 14 ) my["max_jing"] = 100;
	}
	if( userp(ob) || undefinedp(my["eff_jingli"]) ) {
		my["eff_jingli"] = (my["con"] + my["dex"]) * 8 - 100;
		if( my["age"] <= 70 ) my["eff_jingli"] = 100 + (my["con"] + my["dex"]) * 8 - (my["age"] - 50) * 10;
		if( my["age"] <= 50 ) my["eff_jingli"] = 100 + (my["con"] + my["dex"]) * 8;
		if( my["age"] <= 30 ) my["eff_jingli"] = 100 + (my["con"] + my["dex"]) * (my["age"] - 14) / 2;
		if( my["age"] <= 14 ) my["eff_jingli"] = 100;
	}

	if (undefinedp(my["jingli"])) my["jingli"] = my["eff_jingli"];
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		my["max_qi"] = (my["con"] + my["str"]) * 8 - 100;
		if( my["age"] <= 70 ) my["max_qi"] = 100 + (my["con"] + my["str"]) * 8 - (my["age"] - 50) * 10;
		if( my["age"] <= 50 ) my["max_qi"] = 100 + (my["con"] + my["str"]) * 8;
		if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["con"] + my["str"]) * (my["age"] - 14) / 2;
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		if((qi_age=(int)ob->query_skill("literate")) > 30)
			my["max_qi"] += (qi_age-30) * ((int)ob->query_skill("force", 1)/10) / 2;
	}

	if (userp(ob)) catch("/feature/sadjust"->skill_adjust(ob));

	ob->set_default_object(__FILE__);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
