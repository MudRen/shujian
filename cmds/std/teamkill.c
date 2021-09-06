// teamkill.c

#include <ansi.h>
#include <pktime.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname;
	object *t;
	int i;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

//	if (userp(obj) && me->query("ת��id")) // add by Looklove for share id
//		return notify_fail(HIR"���id���ڽ��ֱ��˵�id��δcutת��ʱ��exp����ɱ��������ң�\n"NOR);

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0 && !obj->query_condition("killer"))
		return notify_fail("����ڽ�ֹɱ�ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if( me->query_condition("killer") > 180 && userp(obj))
		return notify_fail("���뵽�Լ�����ͨ���ţ��ֲ�������������\n");

	if (obj == me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	if (!me->is_team_leader())
		return notify_fail("ֻ�ж���������������ҡ�\n");

	if ( obj->query("job_npc") || obj->query("no_ansuan"))
		return notify_fail("Ҫɱ��ɱ���μ�ʲô���鰡��\n");
		
	if (userp(obj) && me->query("combat_exp")<1000000) //��������10M����PK����ֹ���׸����˼�JOB��
		me->set("qi", -1);
		return notify_fail("�Բ���,ֻ�д���1M�ſ������PK��\n");




if (userp(obj) && obj->query("combat_exp")<1000000) 
                return notify_fail("�Բ����밮��С���ѡ�\n");


if (userp(obj) && me->query("combat_exp")<  obj->query("combat_exp") * 2 /3 &&  !obj->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");
		
if (userp(obj) && me->query("combat_exp") > obj->query("combat_exp") * 3 / 2 &&  !obj->query_condition("killer")) 
                return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");
		

















// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, obj))
		return 0;

	if(meisdummy(me,obj))
	{
		return notify_fail("�����ף�һ������ȥ��\n");
	}
/*
	if (userp(obj) && userp(me)
	&& (!living(obj) && me->query("mud_age") < (time() - me->query("birthday"))/24
	|| me->query("mud_age") < (time() - me->query("birthday"))/48))
		return notify_fail("�����ף�һ������ȥ��\n");
*/
	if (me->query_temp("combat_yield"))
		return notify_fail("�����򲻻����أ���ôɱ��\n");

	t = me->query_team();
	if (arrayp(t))
		t -= ({ 0 });
	if(sizeof(t) < 2)
		return notify_fail("�����ڲ�û�вμ��κζ�������ֻ��һ���ˡ�(use kill)\n");

	for(i=0;i<sizeof(t);i++){
		if(environment(me) != environment(t[i]))
			return notify_fail("��Ա�����ڳ���(use kill)\n");

		if (obj == t[i])
			return notify_fail("����ڧô��\n");

		if (t[i]->query("combat_exp") > obj->query("combat_exp")/2*sizeof(t) && userp(obj))
			return notify_fail("������ɲ����Ըĵ������۹ѵĶ�ϰ��\n");
	}

	callname = RANK_D->query_rude(obj);
	message_vision("\n$N����$n�ȵ�����"
		+ callname + "�����ղ��������������ǻ��\n\n", me, obj);

	for(i=0;i<sizeof(t);i++) {
		if (userp(obj) && t[i]->query_condition("killer") > 180)
			continue;
		if (userp(obj) && userp(t[i])
		&& (!living(obj) && t[i]->query("mud_age") < (time() - t[i]->query("birthday"))/24
		|| t[i]->query("mud_age") < (time() - t[i]->query("birthday"))/48))
			continue;
                if (t[i]->query_temp("combat_yield"))
                        continue;
                if (userp(obj) && (t[i]->query("combat_exp")>obj->query("combat_exp")*3/2 || t[i]->query("combat_exp")<obj->query("combat_exp")*2/3) )
                        continue;
                if (t[i]->is_killing(obj->query("id")) && t[i]->is_fighting(obj) )
			continue;
		t[i]->set_temp("ttarget",obj->query("id"));
		t[i]->kill_ob(obj);
		if (userp(t[i]) && userp(obj) && strsrch(file_name(environment(t[i])), "/cmds/leitai/bwdh") != 0 )
			t[i]->add_busy(2);
		obj->kill_ob(t[i]);
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : teamkill <����>
 
���ָ������Ķ�����������һ�����

�������ָ��: team,fight,kill

HELP
    );
    return 1;
}
