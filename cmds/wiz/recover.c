// snowman.
// yuj.

#include <ansi.h>
inherit F_CLEAN_UP;

void do_recover(object ob, int j)
{
	int i;
	mapping skills, learned;
	string *sk;

	if (j < 1 || j > 5) return;
	while(j--) {
		skills = ob->query_skills();
		if (mapp(skills)) {
			sk = keys(skills);
			ob->improve_skill(sk[0], 1, 1);
			learned = ob->query_learned();
			learned[sk[0]]--;
			foreach (string skill in sk) {
				i = (skills[skill]+1)*(skills[skill]+1);
				if ((learned[skill]+=i/2) > i) {
					skills[skill]++;
					learned[skill] -= i;
				}
			}
		}
		i = ob->query("death_lost_exp");
		ob->add("combat_exp", i);
		ob->add("shen", ob->query("shen")/9);
		i = ob->query("potential");
		i += i/3;
		if (i > ob->query("max_pot")) i = ob->query("max_pot");
		ob->set("potential", i);
		i = ob->query("death_count") - 1;
		if (i < 0) i = 0;
		ob->set("death_count", i);
		if (i < ob->query("death_times")) ob->set("death_times", i);
	}
	ob->reincarnate();
}

int main(object me, string arg)
{
	int i, j = 1;
	string obj, reason;
	object ob;
	mapping note;

	if( !arg )
		return notify_fail("recover <ĳ��> [����] because [ԭ��]��\n");

	if( sscanf(arg, "%s %d because %s", obj, i, reason)==3 ) j = i;
	else obj = arg;

	if( !reason )
		return notify_fail("recover <ĳ��> [����] because [ԭ��]��\n");

	ob = find_player(obj);
	if( !ob )  ob = find_living(obj);
	if( !ob )  ob = present(obj, environment(me));
	if( !ob ) return notify_fail("�Ҳ���������\n");

	if( !userp(ob) )
		return notify_fail("�Է�ֻ�Ǹ�NPC��������ôС������ɣ�\n");

	if( (wiz_level(me) < wiz_level("(wizard)")) && me!=ob )
		return notify_fail("��û�лָ�" + ob->name() + "������ʧ��Ȩ����\n");

	message_vision(HIR "\n$N����"+chinese_number(j)+"��"BLU"���"HIR"����$n���������У���$p�������ֻأ���\n\n"NOR,me,ob);

	tell_object(ob, HIW"��е�����к��������ֱ�������֮�磬�ָ��˲�����ʧ��\n"NOR);
	
	note = (["title":"�������ָ����ָ����"+ob->name(1) + "("+ capitalize(ob->query("id"))+")������ʧ�Ĺ���",
			"author":me->query("name") + "(" + getuid(me) + ")",
			"time":0,
			"msg":0,
			]);	
			
	"/clone/board/wizto_b"->done_post(me,note,"�������ָ���" + ob->name(1) + "(" + capitalize(ob->query("id"))
		+ ")��Ϊ��"+reason+"���ָ�"+chinese_number(j)+"��������ʧ��\n");
		
	if( ob!=me && !wizardp(ob) )
		log_file("static/RECOVER",
			sprintf("%s(%s) recovered %s(%s) %d times because %s\n", me->name(1),
				me->query("id"), ob->name(1), ob->query("id"), j, reason
			), me, ({ ob->query("id") })
		);
	do_recover(ob, j);
	ob->set("last_death", "������ʦ�ָ�");
	ob->delete("last_killer_id");
	ob->delete("last_death_time");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : recover <ĳ��> [����]

������ɻָ�������ʧ�����ã�

HELP
    );
    return 1;
}
