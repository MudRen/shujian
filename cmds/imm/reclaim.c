// reclaim.c

int main(object me, string arg)
{
	write("������������� " + reclaim_objects() + " ��������\n");
	if (me->id("yuj") || me->id("linux") ||getuid(me)=="ciwei" ) {
		object ob, *obs = objects();
		int mem = sizeof(obs);

		while (mem--) {
			ob = obs[mem];
			if (!environment(ob)
			&& clonep(ob)
			&& !interactive(ob)
			&& !ob->query_temp("body_ob")
			&& !ob->query_temp("link_ob")) {
				reset_eval_cost();
				write(sprintf("%O", ob));
				destruct(ob);
				write(" �Ѿ��������\n");
				obs -= ({ 0 });
				mem = sizeof(obs);
			}
		}
	}
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : reclaim

�ô� : ���ڴ��е����ñ��������, �Լ����ڴ�����ġ�
HELP
	);
	return 1;
}
