// fengyun.c
// Modified by Lane@SJ 2005/4/14

#include <ansi.h>

int exert(object me)
{
	int improve;

	if( me->query("class") != "bonze" && me->query("family/generation") > 3)
		return notify_fail("�㲻�ǳ����ˣ��޷�����ټ�ʮ��ׯ�ġ����ơ��־���\n");
        
	if( (int)me->query_skill("linji-zhuang", 1) < 90 )
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if((int)me->query("neili") < 400 )
		return notify_fail("�������������\n");
        
	if( me->query_temp("ljz/fengyun") )
		return notify_fail("�����������ټ�ʮ��ׯ�ġ����ơ��־���\n");

	tell_object(me,MAG"�㰵�˷�����ׯ����˼����Ʈ��֮���л�����Ĭ���絴��֮Ѹ�ٽ���һ�ɵ���������ע��֫�ٺ�������������������ࡣ\n"NOR, me);
	tell_room(environment(me), MAG"ֻ��"+me->name()+"΢��˫�ۣ���������һȦ����˲Ϣ��һ���������������ָ�������\n"NOR,({ me }));
	improve = (int)me->query("dex") ;
	me->add_temp("apply/dexerity", improve);
	me->set_temp("ljz/fengyun", improve);  
	me->add("neili", - 150);    
	me->start_exert(1 , "�����ơ��־�");
	call_out("remove_effect", 1, me, (int)me->query_skill("dodge")/3 );
	return 1;
}

void remove_effect(object me,int count)
{
	int i;
	if(!me || !me->query_temp("ljz/fengyun")) return;
	if( count < 1){
		i = me->query_temp("ljz/fengyun");
		me->add_temp("apply/dexerity", -i);
		me->delete_temp("ljz/fengyun");
		if ( living(me) && ! me->is_ghost()) 
			tell_object(me, HIR"������й��Ѿã��Ծ����ĳ�����һЩ��\n"NOR);
		return;
	}
	call_out("remove_effect", 1, me,count - 1);
}

string exert_name(){ return MAG"�����־�"NOR; }

int help(object me)
{
        write(MAG"\n�ټ�ʮ��ׯ�������־�����"NOR"\n\n");
        write(@HELP
        Ҫ��  ��ǰ���� 400 ���ϣ�
                �ټ�ʮ��ׯ�ȼ� 90 ���ϣ�
                ���һ��׼��������ӡ�
HELP
        );
        return 1;
}
