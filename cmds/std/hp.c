#include <ansi.h>

inherit F_CLEAN_UP;

string status_color(int current, int max);

string conv(int i)
{
	if (i < 1000) return ""+i;
	return conv(i/1000)+sprintf(",%03d", i%1000);
}

int main(object me, string arg)
{
	object ob;
	int lmt, i;
	mapping my;

	if (!userp(me)) return 0;
	seteuid(getuid(me));

	if (!arg) ob = me;
        else if (!objectp(ob = present(arg, environment(me)))) {
                if (wizardp(me) ) {
                        if (!ob) ob = LOGIN_D->find_body(arg);
                        if (!ob) ob = find_living(arg);
                        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
                        if (wiz_level(me) < wiz_level(ob))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");
                }
        }

        if (!wizardp(me) && me!=ob) {
                if( !ob || environment(ob)!=environment(me) )
                        return notify_fail("��Ҫ�쿴˭��״̬��\n");
                if( userp(ob)
                  || !me->query("group/id")
                  || me->query("group/id") != ob->query("group/id")
                  || me->query("group/class") >= ob->query("group/class") )
                        return notify_fail("��ֻ�ܲ鿴ͬ���ɣ��ҵȼ�����͵�NPC��״̬��\n");
        }


	if (ob->is_corpse() || !ob->is_character())
		return notify_fail("�ǲ��ǻ���Ү��\n");

	my = ob->query_entire_dbase();

	if (userp(ob)){
		lmt = my["combat_exp"];
		for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
		lmt = i;
		my["max_pot"] = i+100;
	}

	if (!my["max_jing"]) my["max_jing"] = 1;
	if (!my["max_qi"]) my["max_qi"] = 1;
	write(sprintf("\n����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d%s(%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]+ob->query_temp("apply/jing")), my["jing"], my["eff_jing"]+ob->query_temp("apply/jing"),
		status_color(my["eff_jing"]+ob->query_temp("apply/jing"), my["max_jing"]), ((my["eff_jing"]+ob->query_temp("apply/jing")) * 100 / my["max_jing"]),
		status_color(my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli")), my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli"),
		status_color(my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli")), my["eff_jingli"]-my["max_jingli"]+(ob->query_skill("force")-ob->query_temp("apply/force"))*8+ob->query_temp("apply/jingli") ));
	write(sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d(+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]+ob->query_temp("apply/qi")), my["qi"], my["eff_qi"]+ob->query_temp("apply/qi"),
		status_color(my["eff_qi"]+ob->query_temp("apply/qi"), my["max_qi"]), ((my["eff_qi"]+ob->query_temp("apply/qi")) * 100 / my["max_qi"]),
		status_color(my["neili"], my["max_neili"]+ob->query_temp("apply/neili")), my["neili"], my["max_neili"]+ob->query_temp("apply/neili"),
		my["jiali"] ));

	write(sprintf("��%s����%s %-13s   " NOR " ���������ޡ�"HIC"%5d / %5d\n" NOR,
		my["shen"] < 0?"��":"��",
		my["shen"] < 0?HIR:HIC,
		conv((my["shen"] < 0?-1:1) * my["shen"]),
		(ob->query_skill("force")-ob->query_temp("apply/force"))*8 + my["combat_exp"]/1000 + ob->query_temp("apply/neili"),
		(ob->query_skill("force")-ob->query_temp("apply/force"))*10 + my["age"]*20 + my["combat_exp"]/1000 + ob->query_temp("apply/neili")));

	i = ob->max_food_capacity();
	if (!i) i = 1;
	write(sprintf("��ʳ�%s%7.2f%%	 " NOR "     ��Ǳ�ܡ�"HIY" %4d / %4d\n" NOR,
		status_color(my["food"], i),
		my["food"]*100.0/i, my["potential"], my["max_pot"] ));
	i = ob->max_water_capacity();
	if (!i) i = 1;
	write(sprintf("����ˮ��%s%7.2f%%	 " NOR "     �����顤"HIM" %s (%.2f%%)\n"NOR,
		status_color(my["water"], i),
		my["water"]*100.0/i,
		conv(ob->query("id") == "zhong shentong"?my["combat_exp"]/3*2:my["combat_exp"]),
		lmt > 0 ? (my["combat_exp"] - to_int((lmt-1)*(lmt-1)/10.0*(lmt-1)))*100.0/(to_int(lmt*lmt/10.0*lmt) - to_int((lmt-1)*(lmt-1)/10.0*(lmt-1))) : 100.0));
	return 1;
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 0;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� hp
	   hp <��������>		   (��ʦר��)

���ָ�������ʾ���ָ������ľ�, ��, ���״̬��ֵ��
��ʦ���Բ�ѯ�κ��˻� NPC ��״̬��ֵ��

���ָ�score

	Copyright 1997-1999 ShuJian MUD Wizard Group.
	All rights reserved.

	Visit our Homepage at - www.mymud.com

HELP
	);
	return 1;
}
