// group teach
// by augx@sj 3/25/2002

#include <ansi.h>
inherit F_CLEAN_UP;

#define	WORK_TIME	60
#define	REST_TIME	60
#define MAX_SKILLS	35

int help(object me)
{
	write(@HELP
ָ���ʽ�� gteach [����] to [����id]
��������������ڰ��ɱ��ڼ��ܣ����ڵļ������ȴ����ߵĴ���ܸ�100����
HELP );
	return 1;
}

int main(object me, string arg)
{
	string skill;
	object ob;
	int delay;

	if( !arg || !sscanf(arg, "%s to %s",skill,arg) ) return help(me);
	if( !(ob = present(arg, environment(me))) )
		return notify_fail("û������ˡ�\n");
	if( userp(ob) )
		return notify_fail("�㲻�ܽ�����书��\n");
	if( !me->query("group/id")
	  || me->query("group/id") != ob->query("group/id")
	  || me->query("group/class") >= ob->query("group/class") )
		return notify_fail("��ֻ�ܽ���ͬ���ɣ��ҵȼ�����͵����书��\n");
	if( environment(me)->query("group1") != me->query("group/id") )
		return notify_fail("��ֻ���Լ��İ���н����书��\n");
	if( !me->query_skill(skill,1) )
		return notify_fail("�������������ܰ���\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
	if( ob->is_busy() || ob->is_fighting() )
		return notify_fail(ob->name()+"��æ���ء�\n");
	if( (me->query_skill(skill,1)+100) < ob->query_skill(skill,1) )
		return notify_fail(ob->name()+"������Ѿ��������㣬���޷��ٽ���"+ob->name()+"ʲô�ˡ�\n");
	if( ob->query_temp("gteach")>time() && !(wizardp(me) && me->query("env/test")) )
		return notify_fail(ob->name()+"�ո�ѧϰ�������ڸо��������ۡ�\n");
	if( (me->query("group/gteach")+WORK_TIME*60+REST_TIME*60) < time() )
		me->set("group/gteach",time());
	if( (me->query("group/gteach")+WORK_TIME*60) < time() )
		return notify_fail("����ڱ����书��ʱ�������ֻ�е�ͷ�����ͣ��������á�\n");
	if( sizeof(ob->query_skills()) > MAX_SKILLS )
		return notify_fail(ob->name()+"��ѧ���ܹ��࣬���Բ��㣬��Ҳ�޷�ѧϰ�µ�֪ʶ��\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	message_vision("$N��ʼ��������$n��"+to_chinese(skill)+"��......\n", me,ob);
	delay = 10 + random(10);
	if( wizardp(me) && me->query("env/test") ) delay = 2;
	me->start_busy(delay);
	ob->start_busy(delay);
	call_out("teach_finish",delay*2-1,me,ob,skill);

	return 1;
}

void teach_finish(object me,object ob,string skill)
{
	int i,improve;

	if(!me || !ob) return;
	i = ob->query_skill(skill,1) - me->query_skill(skill,1);
	improve = random(ob->query_int(1) + me->query_int(1)) * 150;

	if( i <= 0 ) {
		message_vision("$n������ϰ$N�����ڵļ��ܣ����ܾ����˲��١�\n", me,ob);
		ob->improve_skill(skill,improve);
	}
	else {
		message_vision("$n��$N�����д��书���ƺ������ջ�\n", me,ob);
		ob->improve_skill(skill,improve * (80-i*7/10) / 100 );
	}

	ob->set_temp("gteach", time()+random(30) );
}
