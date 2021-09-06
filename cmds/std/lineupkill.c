// lineupkill.c

#include <ansi.h>
#include <pktime.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname;
	object *lineup;
	int i;

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0 && !obj->query_condition("killer"))
		return notify_fail("����ڽ�ֹɱ�ˡ�\n");

	if( me->query_condition("killer") && userp(obj))
		return notify_fail("���뵽�Լ�����ͨ���ţ��ֲ�������������\n");

	if(obj==me)
		return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	if(! me->is_lineup_leader())
		return notify_fail("ֻ���󷨵������߲��������ҡ�\n");
		
		if (userp(obj) && me->query("combat_exp")<1000000) //��������10M����PK����ֹ���׸����˼�JOB��
			me->set("qi", -1);
				return notify_fail("�Բ���,ֻ�д���1.2M�ſ�������PK��\n");




if (userp(obj) && obj->query("combat_exp")<1000000) 
                return notify_fail("�Բ����밮��С���ѡ�\n");


if (userp(obj) && me->query("combat_exp")<  obj->query("combat_exp") * 2 /3 &&  !obj->query_condition("killer") ) 
                return notify_fail("�˼ұ���ǿ��ô�࣬��Ͳ����˼ұ�����\n");
		
if (userp(obj) && me->query("combat_exp") > obj->query("combat_exp") * 3 / 2 &&  !obj->query_condition("killer")) 
                return notify_fail("����˼�ǿ��ô�࣬����СϺ��Ҳֵ���㶯�֣�\n");











	if ( pktime_limit(me, obj))
		return 0;

	if ( obj->query("job_npc") || obj->query("no_ansuan"))
		return notify_fail("Ҫɱ��ɱ����ʲô�󰡣�\n");

	callname = RANK_D->query_rude(obj);
	lineup = me->query_lineup();
	if(sizeof(lineup) <=1)
		return notify_fail("�����ڲ�û�вμ��κ��󷨻���ֻ��һ���ˡ�(use kill)\n");
	    
	if( obj->query_lineup_leader() == me )
		return notify_fail("���Լ����������Ҳɱ����û�и��\n");

	if( userp(me) && obj->query("no_pk") && !obj->query_condition("killer") )
		return notify_fail(obj->name()+"�Ѿ�����ϴ�֣����ǲ�Ҫ���뽭�������ɣ�\n");

	message_vision("\n$N����$n�ȵ�����"+ callname + "�����ղ��������������ǻ��\n\n", me, obj);

	for(i=0;i<sizeof(lineup);i++){
                if(lineup[i]) {
			lineup[i]->set_temp("lineuptarget",obj->query("id"));
			lineup[i]->kill_ob(obj);
			obj->kill_ob(lineup[i]);
			lineup[i]->add_busy(1);
		}
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : lineupkill <����>
 
���ָ�����������������һ�����

HELP
    );
    return 1;
}
