// steal.c
//by pishou 97/6
// Modify by snowman@SJ 23/02/2000
// modify npc stealer.
// Modified by snowman@SJ 29/12/2000

#include <ansi.h>
#include <pktime.h>

int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        int sp, dp;
        int cost = 2000 / (me->query_skill("stealing", 1) + 40 );

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ֹ���ԡ�\n");

        if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0)
                return notify_fail("����ڽ�ֹ���ԡ�\n");

        if( me->query_temp("stealing") )
                return notify_fail("���Ѿ����һ��������ˣ�\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
                notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

        victim = present(who, environment(me));
        if( !victim || victim==me)
        	return notify_fail("�������ԵĶ��������\n");

        if ( userp(victim) && me->query("age") < 15 && userp(me))
                return notify_fail("СС��;�Ҫ�������֣�����ѧ��ðɡ�\n");

        if ( userp(victim) && victim->query("age") < 18 && userp(me))
                return notify_fail("�Է����Ϻ���ûʲ����ˮ��\n");

        if ( userp(me) && me->query("qi") < me->query("eff_qi")/2 )
                return notify_fail("��ҡҡ�ڰڵĻ���͵�������Ȳ����Լ�����Ѫ�ɡ�\n");

        if( !wizardp(me) && wizardp(victim) )
                return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");

//	if (userp(me) && me->query("registered") < victim->query("registered"))
//                return notify_fail("�����û�����͵��ʽ�û����ϵĶ�����\n");

	if ( userp(me) && userp(victim) && me->query("no_pk"))
		return notify_fail("���Ѿ�����ϴ���ˣ��Ͳ�Ҫ͵���˶����ˡ�\n");

	if ( userp(me) && userp(victim) && victim->query("no_pk"))
		return notify_fail(victim->name()+"�Ѿ�����ϴ���ˣ��Ͳ�Ҫ͵���Ķ����ˡ�\n");



 if (userp(victim) && me->query("combat_exp")<  victim->query("combat_exp") * 2 /3 &&  !victim->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ��±���ץ�����������\n");
            
 if (userp(victim) && me->query("combat_exp") > victim->query("combat_exp") * 3 / 2 &&  !victim->query_condition("killer"))  
                return notify_fail("����СϺ�����ϻ���ʲô��ˮ����\n");
        



	if (pktime_limit(me, victim))
		return 0;

	if ( victim->query("job_npc") || victim->query("no_quest"))
		return notify_fail(victim->name()+"������ûʲô��ˮ������͵�ˡ�\n");

	if( !victim->is_character() || victim->is_corpse() || victim->is_container() )
                return notify_fail(victim->name()+"��Ķ����õ���͵������þ����ˡ�\n");

        if ((cost > me->query("jing")) || (cost > me->query("jingli")))
                return notify_fail("��̫����, ��ЪϢһ�¡�\n");

        if( me->is_busy()) return notify_fail("����æ���ء�\n");

        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "���Ͽ�����û��ʲôֵǮ�Ķ�����͵��\n");
                ob = inv[random(sizeof(inv))];
        }

        if(ob->query("invisible") && !wizardp(me)) return 0;
	if ( ob->query("unique") && userp(me))
                return notify_fail("Ӵ��"+ob->name()+"�ⶫ���Է��õý��أ��϶�͵����Ү��\n");

        if ( ob->query("no_steal") && userp(me))
                return notify_fail("Ӵ��"+ob->name()+"�ⶫ���Է����úܽ����㻹�Ǳ����ˡ�\n");
	if(userp(me))
        	sp = (int)me->query_skill("stealing", 1) * 10 + (int)me->query("kar") * 5
              		- (int)me->query("thief") * 20;
        else sp = (int)me->query_skill("stealing", 1) * 10 + (int)me->query("kar") * 10;

        sp = sp * me->query("jing") / me->query("max_jing");
        sp = sp * (1 + me->query("jingli")) / (1 + me->query("eff_jingli"));
        if( sp < 1 ) sp = 1;

        if( me->is_fighting() )
                sp /= 2;

        dp = 300 * victim->query("jing") / (1+victim->query("max_jing"));
        dp = dp * (1 + victim->query("jingli")) / (1 + victim->query("eff_jingli"));
        dp = dp * 2 + (int)ob->weight()/25;

        if( victim->is_fighting() ) dp *= 10;


        me->receive_damage("jing", cost);
        me->receive_damage("jingli", cost);

        write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");

        me->set_temp("stealing", 1);
	if (userp(me) && userp(victim))
	{
		victim->set_temp("other_kill/"+me->query("id"), 1);
 me->apply_condition("no_quit",20);
		log_file("ANSUAN", 
                        sprintf("%-18s steal  %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                victim->name(1)+"("+capitalize(getuid(victim))+")"
                        ),
                        this_object(),
                );
	}
        if( userp(me) ){
        	me->start_busy(3);
        	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);
	}

	else call_out( "compelete_steal", 1, me, victim, ob, sp, dp);

        return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
        if (!me) return;

        me->delete_temp("stealing");

        if (!living(me) || !ob) return;

        if ( !victim || environment(victim) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
                return;
        }
        if( ob->query("equipped") ){
        	tell_object(me, "��ѽ��"+victim->name()+"����ʹ��"+ob->name()+"�أ����͵���ˡ�\n");
                return;
        }
        if( !living(victim) || (random(sp+dp) > dp) ) {
        	if (!wizardp(me) && ob->query("embedded")){
                	tell_object(me," ��Ҳ̫������,���˼ҳ�������Ķ���ҲҪ͵?\n");
                        return;
                }
                if( ob->query("no_get") || !ob->move(me) ) {
                        tell_object(me, "������һ" + ob->query("unit") + ob->name()+"�����Ƕ������̫���ˣ����ò�������\n");
                        return;
                }
                tell_object(me, HIW "�����ˣ�\n\n" NOR);
                tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");

                if( living(victim) && !userp(victim) ) {
 			me->improve_skill("stealing", random(me->query_int()+me->query_skill("stealing",1)));
                	me->add("potential", 1+random(me->query_skill("stealing")/5));
                	if (me->query("potential") > me->query("max_pot"))
                        	me->set("potential", me->query("max_pot"));
                	me->add("combat_exp", (int)((victim->query("combat_exp") + 1000) / (me->query("combat_exp") + 1000) * 3));
                }
		if( !userp(me) )
			me->improve_skill("stealing", random(me->query("int"))*3);

                if( random(sp) < dp/2 && userp(me))
                        message("vision", "�㿴��" + me->name() + "�������ش�"
                                + victim->name() + "����͵����һ" + ob->query("unit")
                                + ob->name() + "��\n", environment(me), ({ me, victim }) );
                if( !userp(me) ){
                	me->set_temp("steal", 1);
                	if(me->query("stealer_no_hold")){
                		log_file("quest/npc_steal",
                			sprintf("%s steal %s from %s��\n",
		                		me->name()+"("+geteuid(me)+")",
		                		ob->name(),
		                		victim->name()+"("+victim->query("id")+")"
		                	), victim
		                );
                		destruct(ob);
                	}
                }
        }

        else {
                if( random(sp) > dp/2 ) {
                        tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n���ã�û�б����֡�\n");
                        return;
                }

                me->add("steal_f", 1);
                tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
                message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n$N�ȵ�������ʲô����\n\n", victim, me);
                me->improve_skill("stealing", 1, 1);
                // Lklv add no_pk check
                if( userp(victim) && !me->query("no_pk") ){
                	if( me->query("steal_f") > random(me->query_skill("stealing", 1)) ){
                		me->fight_ob(victim);
                		me->set_skill("stealing", me->query_skill("stealing", 1) -1 );
                                if( me->query_skill("stealing", 1) < 1 ) me->delete_skill("stealing");
                		me->add("steal_f", -(1+random(5)));
                		message_vision("$N�����Լ���ʧ���ˣ����ɵ����߳�ŭ����\n", me);
                	}
                	else me->fight_ob(victim);
                	victim->fight_ob(me);
                }
                else victim->kill_ob(me);
                if(userp(me)) me->start_busy(3);

                if ( me->query("no_pk") )
                        me->add_busy(2+random(2));

                else me->set_temp("steal", -1);
                me->add("thief", 1);
        }
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, ������ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
