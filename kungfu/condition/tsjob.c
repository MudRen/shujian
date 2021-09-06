// By Darken@SJ
#include <ansi.h>

int update_condition(object me, int duration)
{
        int i;
        object enemy;

        if (!me->query_temp("tsjob/target") || duration < 1)
        {
                if (!me->query_temp("tsjob/killed"))
                {
                        tell_object(me, HBRED+HIW+"����׷����̩ɽ����ͽ�Ѿ��ӵ���ɽ���������ʧ���ˣ�\n"NOR);
                        me->clear_condition("tsjob");
                        me->apply_condition("tsjob_busy", 15+random(6));
                        me->delete_temp("tsjob");
                        return 1;
                }
                else
                {
                        tell_object(me, HBRED+HIW+"��ɹ�����������������ɽ��̩ɽ��ͽ��\n"NOR);
                       	if (me->query("combat_exp") > 1000000)
                        	TASK_D->job_reward(me, "ts_job", 0, 0);
                       	else
                       		TASK_D->job_reward(me, "ts_job", 1, 0);
                        me->clear_condition("tsjob");
                        me->apply_condition("tsjob_busy", 15+random(6));
                        me->delete_temp("tsjob");
                        return 1;
                }
        }
        if (!duration)
        	return 0;
        me->apply_condition("tsjob", duration - 1);
        if (me->query("combat_exp") > 1000000 && (duration == 29 || duration == 26))
        {
                tell_object(me, HBRED+HIW+"ͻȻ·�ԸZ��һ�ˣ��ƺ��ǽ�Ӧ��ͽ�ġ�\n"NOR);
                enemy = new("/d/taishan/npc/runner");
                i = me->query("max_pot")-100;
	        if (me->query("combat_exp") > 2000000)
	        {
		        enemy->add_temp("apply/defense", i);
		        enemy->add_temp("apply/attack", i);
	        }
	        enemy->set_skill("taishan-jianfa", i);
	        enemy->set_skill("sword", i);
	        enemy->set_skill("qingmang-jian", i);
	        enemy->set_skill("dodge", i);
	        enemy->set_skill("parry", i);
	        enemy->set_skill("taizu-quan", i);
	        enemy->set_skill("cuff", i);
	        enemy->set_skill("taiji-shengong", i);
	        enemy->set_skill("force", i);
	        TASK_D->copy_status(me, enemy, 1);
        	enemy->move(environment(me));
                me->add_busy(1);
                enemy->kill_ob(me);
                call_out("remove_runner", 60, enemy);
        }
        return 1;
}

void remove_runner(object runner)
{
        if (runner)
        	destruct(runner);
}
