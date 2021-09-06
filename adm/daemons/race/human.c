// human.c
// From ES2
// Modified by Yu Jue@JY

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":		"$N»ÓÈ­¹¥»÷$nµÄ$l",
		"damage_type":	"ğöÉË",
	]),
	([	"action":		"$NÍù$nµÄ$lÒ»×¥",
		"damage_type":	"×¥ÉË",
	]),
	([	"action":		"$NÍù$nµÄ$lºİºİµØÌßÁËÒ»½Å",
		"damage_type":	"ğöÉË",
	]),
	([	"action":		"$NÌáÆğÈ­Í·Íù$nµÄ$l´·È¥",
		"damage_type":	"ğöÉË",
	]),
	([	"action":		"$N¶Ô×¼$nµÄ$lÓÃÁ¦»Ó³öÒ»È­",
		"damage_type":	"ğöÉË",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "Î»");
	set("gender", "ÄĞĞÔ");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"Í·²¿",	"¾±²¿",	"ĞØ¿Ú",	"ºóĞÄ",	"×ó¼ç",	"ÓÒ¼ç",	"×ó±Û",
		"ÓÒ±Û",	"×óÊÖ",	"ÓÒÊÖ",	"Ñü¼ä",	"Ğ¡¸¹",	"×óÍÈ",	"ÓÒÍÈ",
		"×ó½Å",	"ÓÒ½Å", "×ó¶ú", "ÓÒ¶ú", "×óÁ³", "ÓÒÁ³", "Ğ¡¸¹"
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
