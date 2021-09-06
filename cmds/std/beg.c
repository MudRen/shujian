// beg.c

#include <ansi.h>

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;
	int cost;
      
	if (!(myfam = me->query("family")) 
	|| (myfam["family_name"] != "ؤ��") )
		return notify_fail("ֻ����ؤ�������֣�\n");

	if( environment(me)->query("no_beg") || environment(me)->query("no_fight"))
		return notify_fail("���ﲻ����л��������ַ��ĵط���\n");

	if( me->query_temp("begging") )
		return notify_fail("���Ѿ������˼������ˣ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");

	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��Ҫ��˭���֣�\n");

	cost = 2000 / (me->query_skill("begging", 1) + 20 );
	if ((cost > me->query("jingli")) || (cost > me->query("jing")))
		return notify_fail("��̫����, ��ЪϢһ�¡�\n");

	if ((vtfam = victim->query("family"))
	&& (vtfam["family_name"] == "ؤ��")) 
		return notify_fail("�㲻������ؤ���֣�\n");

	if (!wizardp(me) && wizardp(victim))
		return notify_fail("��Ҳ�������ʦ���֡�\n");

//	if (userp(me) && me->query("registered") < victim->query("registered"))
//		return notify_fail("�����û���������ʽ�û����֡�\n");

	if (userp(me) && userp(victim) && me->query("no_pk"))
		return notify_fail("���Ѿ�����ϴ���ˣ����ǲ�Ҫ�����ˡ�\n");

	if (userp(me) && userp(victim) && victim->query("no_pk"))
		return notify_fail(victim->name()+"�Ѿ�����ϴ���ˣ����ǲ�Ҫ�����ˡ�\n");

	if ( userp(me) && userp(victim) && victim->query("env/no_beg"))
		return notify_fail(victim->name()+ "����������ʩ���κζ�����\n");

	if( me->is_busy())
		return notify_fail("����æ���أ�\n");

	if( me->is_fighting() )
		return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�\n");

	if( victim->is_fighting() ) 
		return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲô�������Ȥ�Ķ�����\n");
		ob = inv[random(sizeof(inv))];
	}

	if (ob->query("no_get") || ob->query("equipped") || ob->query("no_drop") || ob->query("unique") && userp(me))
		return notify_fail("�������˵�����һ�϶�������㡣\n");

	if (!wizardp(me) && ob->query("embedded"))
		return notify_fail("������Ǹ��������������أ�\n");

	sp = (int)me->query_skill("begging", 1) * 10 + (int)me->query("kar") * 5
		- (int)me->query("begger") * 2;
	sp = sp * me->query("jing") / me->query("max_jing");
	sp = sp * me->query("jingli") / (me->query("eff_jingli")+1);
	if( sp < 1 ) sp = 1;
	dp = 300 * victim->query("jing") / victim->query("max_jing");
	dp = dp * (1 + victim->query("jingli")) /(1 +  victim->query("eff_jingli"));

	if (userp(me)) {
		me->add("jing", -cost);
		me->add("jingli", -cost);
	}

	tell_object(me, "��װ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
			+ ob->query("unit") + ob->name() +"...\n\n");
	tell_object(victim, me->name() + "�����Ͱ͵����������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����" 
			+ ob->query("unit") + ob->name() + "�� ...��\n\n");
	message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������" 
		+ victim->name() + "�߹�ȥ�����˫�֣�˵����"
		+ RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim }) );

	me->set_temp("begging", 1);
	me->start_busy(3);
	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;
	object where;

	if (!me) return;
	where = environment(me);
	me->delete_temp("begging");

	if (!living(me)) return;
	if( !victim || environment(victim) != where ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
		return;
	}
	if( !ob || environment(ob) != victim ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵĶ����Ѿ����������ˡ�\n");
		return;
	}

	if( living(victim) && (random(sp+dp) > dp) && ob->query("imbued") < 3) 
	{
		if ( ob->query("money_id") )
		{

			amount = ob->query_amount();
			if( amount < 5 )
			{
				tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�\n");
				return;
			}

			ob->set_amount(amount - amount/5);
	
			ob1=new("/clone/money/" + ob->query("money_id"));
			ob1->set_amount(amount/5);
			ob1->move(me);

		}
		else if( !ob->move(me) ) {
			ob->move(where);
			tell_object(me, "���ֵ�һ" + ob->query("unit") + ob->name() 
				+ "�����Ƕ������̫���ˣ����ö��ڵ��¡�\n");
			return;}

		tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����������һ" 
				+ ob->query("unit") + ob->name() + "��\n");
		tell_object(victim, "�㿴��" +  me->name() +"�Ŀ�������̾�˿���������"
				+ gender_pronoun(me->query("gender"))+"һ"
				+ ob->query("unit") + ob->name() + "��\n");

		if (!userp(me) || random(sp) < dp/2)
			message("vision", "�㿴��" + victim->name() + "����" + me->name() + "������м��ҡҡͷ��"
				+ "����"+gender_pronoun(me->query("gender"))+"һ" + ob->query("unit")
				+ ob->name() + "��\n", environment(me), ({ me, victim }) );
		  me->start_busy(6);

		if( me->query("combat_exp") > 2 * victim->query("combat_exp") )
		  {
		    tell_object(me, "�������˶���, ̫û�����˰ɡ�\n");
		    return;}

		if (!userp(victim)) {
		me->improve_skill("begging", random(me->query("int")));
		me->add("potential", (int)(me->query("int") / 20 ));
		me->add("combat_exp", (int)(1 + me->query_skill("begging", 1) / 100 ));
		}
	} 
	else 
	{
		if (!userp(me) || random(sp) > dp/2) {
			message_vision("$n�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�\n", me, victim);
			if (userp(me))
				me->add("begger", 1);
			return;
		}

		tell_object(me, victim->name() + "Ť��ͷȥ������������\n");

		tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
		message("vision", victim->name() + "Ť��ͷȥ����" + me->name() + "������\n", 
			environment(me), ({ me, victim }) );

		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : beg <ĳ��> from <ĳ��>

HELP
    );
    return 1;
}

