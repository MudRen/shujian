// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if (me->query_temp("mark/literate")) {
		me->delete_temp("mark/literate");
		return 1;
	}

	if( (me->query("family/family_name") =="ÉÙÁÖÅÉ"
	|| me->query("family/family_name") =="¶ëáÒÅÉ"
	|| me->query("family/family_name") =="ÌìÁúËÂ")
	&& me->query("class") == "bonze"
	&& me->query_skill("literate", 1) < 100)
		return 1;

	return notify_fail("Äã±ØĞëÈ¥Ñ§ÌÃÑ§Ï°¶ÁÊéĞ´×Ö¡£\n");
}
