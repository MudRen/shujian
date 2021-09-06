// shentong.c ��ͨ
// Creat by Looklove 2001.10.11
// д���Ժ����˵��hs yun zixia���󣬲�����ԭ���ǲ�֪��zixia�ġ�
// �������ԭ����double_atteck ��river ȥ���ˣ��ҿ�û�ճ�zixia���ٺ١�
// ��ע������ȥ����лл��

#include <ansi.h>
inherit F_CLEAN_UP;

string exert_name(){ return HIW"��ͨ"NOR; }

int exert(object me, object target)
{
	int skill, eff, max;
	skill = me->query_skill("huntian-qigong",1);

	eff = me->query("eff_qi");
	max = me->query("max_qi");

	if( me->query_skill("medicine", 1) < 100 )
		return notify_fail("��ı��������𲻹���\n");

	if( skill < 150 )
		return notify_fail("��Ļ����������𲻹���\n");

	if( me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
		return notify_fail("����ڹ����ԡ�\n");

	if( !me->is_fighting() )
		return notify_fail("��ֻͨ����ս����ʹ�á�\n");

	if( me->query_temp("htqg/shentong") )
		return notify_fail("���Ѿ�������ͨ���ˡ�\n");

	message_vision(HIW"\n$N��ɫ���룬�������쳤Х����ʱȫ�������ĵ������۷��衣\n" NOR, me);

	if( max > eff ) {
		me->receive_curing("qi", max/10);
		me->add("neili", -350);
	}

	me->add("neili", skill*10);
	if( me->query("neili") > me->query("max_neili") * 2 )
		me->set("neili", me->query("max_neili")*2-1);

	me->add("max_neili", -1);
	me->set_temp("htqg/shentong", 1);
	call_out("remove_effect", 1, me, skill);
	me->start_busy(random(2));
	me->start_exert(1, "��ͨ");
	return 1;
}

void remove_effect(object me, int skill)
{
	if( ! me) return;
	if( me->query_temp("htqg/shentong") ) {
		if( me->is_fighting() ) {
			call_out("remove_effect", 1, me, skill);
			return;
		}
		if( me->query("neili") > me->query("max_neili") * 2 )
			me->set("neili", me->query("max_neili")*2-1);
		me->delete_temp("htqg/shentong");
		message_vision(HIW"$N��������������ϣ��ĵ��������µ�������ʧ�ˡ�\n"NOR, me);
	}
}

int help(object me)
{
        write(HIW"\n��������֮����ͨ����"NOR"\n");
        write(@HELP
        ��ͨΪ����������Ҫ����֮һ��ս����ͨ������ͨ���Դ����������ǰ������
        ������һ�������˹�Ч�����Զ�ʱ���ڻָ�����20����
        ע�⣺�˹������ή��1�����������
        Ҫ��
                ��ǰ����  500 ���ϣ�
                ���������ȼ� 150 �����ϣ�
                ��������ȼ� 100 �����ϣ�
                ս����ʹ�á�
HELP
        );
        return 1;
}
