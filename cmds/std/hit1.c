// fight.c

#include <ansi.h>
#include <pktime.h>

int main(object me, string arg)
{
	object obj,ob;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0)
		return notify_fail("����ڽ�ֹ���ˡ�\n");


	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if (me->query_temp("quit"))
		return notify_fail("�����˳���Ϸ�У��д�����ʧ�ܡ�\n");
		
	if( me->is_fighting(obj) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("�㲻��͵Ϯ��ʦ�ȼ�����ߵĶ��֡�\n");

	if (obj==me) return notify_fail("���Լ�������ô�벻����\n");

	if ( userp(me) && userp(obj) && obj->query("age") < 18 )
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
		
        if ( userp(me) && userp(obj) && me->query("combat_exp")<1000000)
 	
		return notify_fail("��Ŀǰ�����ڴ��׼��𡣡���\n");

	if (userp(me) && userp(obj)) {
		if(me->query("no_pk")) return notify_fail("���Ѿ�����ϴ�֣���λ������˵ȹ�����\n");
		if(obj->query("no_pk")) return notify_fail("�Է��Ѿ�����ϴ�֣��㻹�ǷŹ����ɡ�\n");
			if(objectp(ob = present("hu wan", me))) return notify_fail("�㻹�ǰ����ֻ���������˵�ɣ�\n");
	}



if (userp(obj) && userp(me) && obj->query("combat_exp")<1000000) 
                return notify_fail("�Բ����밮��С���ѡ�\n");
/*
if (userp(obj) && userp(me) && me->query("combat_exp")<  obj->query("combat_exp") * 2 /3 &&  !obj->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");
		
if (userp(obj) && userp(me) && me->query("combat_exp") > obj->query("combat_exp") * 3 / 2 &&  !obj->query_condition("killer")) 
                return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");
		
*/










// Add By River@SJ 2003.6.24
	if ( pktime_limit(me, obj))
		return 0;

/* add by cool for limit hit player to die */
	if ( userp(me) && userp(obj) &&
	   ( (obj->query("qi") < obj->query("max_qi")/2 )
	 || (obj->query("eff_qi") < obj->query("max_qi")/2 )) )
		return notify_fail("�Է��Ѿ��������������ٺ����д��ˡ�\n");

	if (!living(obj))
		return notify_fail(obj->name()+"�Ѿ��޷������ˣ�\n");

        if ( obj->query("no_ansuan") || obj->query("job_npc") || obj->query("id")=="hou junji")
		return notify_fail("Ҫɱ��ɱ����ʲô͵Ϯ��\n");

	if( userp(obj) ) {
		message_vision("\n$N����$n���һ����"+RANK_D->query_rude(obj)+"������һ�����ԣ�\n\n", me, obj);
		me->set_temp("hitting", 1);
		me->add_busy(1);
		if (userp(me))
{
 me->apply_condition("no_quit",20);
			obj->set_temp("other_kill/"+me->query("id"), 1);
						
			log_file("ANSUAN", 
                        sprintf("%-18s hit    %-18s",
                                me->name(1)+"("+capitalize(getuid(me))+")",
                                obj->name(1)+"("+capitalize(getuid(obj))+")"
                        	),
                        	this_object(),
                	);
		}
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n���һ����"+RANK_D->query_rude(obj)+"���У�\n\n", me, obj);
		me->fight_ob(obj);
		if (obj->accept_fight(me)) obj->fight_ob(me);
		else obj->kill_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}
/*
	if (obj && obj->query_temp("last_hit_by") == me && me->query_temp("hit_time") == time()) {
		if (me->add_temp("hit_count", 1) > 4) me->add("combat_exp", -1000);
		if (me->query("combat_exp") < 0) me->delete("combat_exp");
		log_file("punish", me->query("id") + " hit " + obj->query("id") + "�н��ˣ�\n");
	} else {
		me->set_temp("hit_time", time());
		me->delete_temp("hit_count");
	}
	if (obj) obj->set_temp("last_hit_by", me);
*/
	if (obj) COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 1);
	return 1;
}

void do_hit(object me, object obj)
{
	if (!me) return;
	me->delete_temp("hitting");
	if (!obj) return;
	if(objectp(present(obj, environment(me)))) {
		/*
		if (me->query_temp("kill_other/"+obj->query("id"))
		|| !obj->query_temp("kill_other/"+me->query("id"))
		&& !me->query_temp("other_kill/"+obj->query("id")))
			if (userp(me) && me->query("registered") < 3 && userp(obj) && obj->query("registered") > 2)
				me->unconcious();
		*/
		
		if(meisdummy(me,obj))
		{
			message_vision("$N��Ȼ�����Լ��������ף���ʱ�����ҡ�\n", me);
			me->set("qi", -1);
			return;
		}
						
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon"), 2);
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"), 1);
	}
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>

���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е� NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���

�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� hit �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
