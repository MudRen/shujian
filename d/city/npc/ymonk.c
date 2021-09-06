//  monk.c

#include <localtime.h>
inherit NPC;

mixed ask_redeem();

void create()
{
	set_name("С����", ({ "xiao heshang", "monk" }) );
	set("class", "bonze");
	set("gender", "����");
	set("age", 15);
	set("long",
		"�������ݳ��������յ�Сͽ�ܣ���������ش�ɨ��Ժ��\n");
	set("title", "������С����");
	set("combat_exp", 9000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
		"mud" :"����Ǹով����˿�籩���ķ�������ɵ�ȫ�£ͣգģ�",
		//"����" : (: ask_redeem :),
	]) );

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);

	set_skill("unarmed", 30);
	set_skill("sword", 40);
	set_skill("parry", 30);
	set_skill("dodge", 36);
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
}
/*
mixed ask_redeem()
{
	object me = this_player();
	mixed *local;
	int t;

	if (me->query("registered") < 3)
		return 0;

	local = localtime(time());
	t = local[LT_YEAR] * 8784 + local[LT_MON] * 744 + local[LT_MDAY] * 24 + local[LT_HOUR];

	if (!wizardp(me) && t < 2002 * 8784 + 6 * 744 + 8 * 24 + 9)	// 2002-07-08 09:00
		return "��Ҫ�ż�����Ϣ����Ϣһ�ᡣ";

	if (t >= 2002 * 8784 + 6 * 744 + 9 * 24 + 9)	// 2002-07-09 09:00
		return "�͵�����ټ��ɣ�";

	local = localtime(me->query("birthday"));
	t = local[LT_YEAR] * 8784 + local[LT_MON] * 744 + local[LT_MDAY] * 24 + local[LT_HOUR];

	if (t >= 2002 * 8784 + 6 * 744 + 7 * 24 + 1)	// 2002-07-07 01:00
		return "�����ӷ�ʩ��������̫���ˡ�";

	if (me->query("gift/count") >= 5)
		return "ʩ���Ĳ����Ѿ���ȡ���ˡ�";

	if (me->query("gift/time") + 120 > time())
		return "ʩ�����ȵ������Ŷӡ�";

	me->set("gift/time", time());
	t = me->add("gift/count", 1);

	{
		mapping skills, skls = ([]), skls2 = ([]);
		int sn, lvl;
		string skill;

		lvl = 666 + random(333);
		message_vision("$N�����"+chinese_number(lvl)+"�㾭��Ľ�����\n", me);
		me->add("combat_exp", lvl);
		log_file("static/REDEEM",
			sprintf("%s(%s)�� %d �λ�ò��� exp %d��\n",
				me->query("name"), me->query("id"), t, lvl
			), me
		);

		skills = me->query_skills();
		if (!(sn = sizeof(skills)))
			return "ʩ������û��ѧ���κμ��ܡ�";

		lvl = 0;
		foreach (skill, int val in skills) {
			if (SKILL_D(skill)->type() == "martial"
			|| SKILL_D(skill)->type2() == "worker") {
				skls2 += ([ skill : val ]);
				lvl += val;
			} else sn--;
		}

		if (!sn)
			return "ʩ������û��ѧ���κο��Բ����ļ��ܡ�";

		lvl /= sn;
		foreach (skill, int val in skls2) {
			if (val >= lvl) {
				skls += ([ skill : val ]);
			}
		}
		sn = random(sizeof(skls));
		skill = keys(skls)[sn];
		lvl = skls[skill];
		lvl *= lvl/2;
		lvl = lvl*2/3 + random(lvl/3);

		if (SKILL_D(skill)->type2() == "worker") {
			if (skls[skill] > 300)
				lvl /= 3;
			else if (skls[skill] > 200)
				lvl /= 2;
		}

		message_vision("$N�����"+chinese_number(lvl)+"�㡸"+to_chinese(skill)+"���Ľ�����\n", me);
		me->improve_skill(skill, lvl, 1);
		log_file("static/REDEEM",
			sprintf("%s(%s)��ò��� %s %d��\n",
				me->query("name"), me->query("id"), skill, lvl
			), me
		);
	}
	return 1;
}
*/