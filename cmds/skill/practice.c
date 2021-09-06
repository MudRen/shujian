// practice.c
// By lsxk@hsbbs 2008/3/14   �����츳Ӱ��Ч��

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object where = environment(me);
        string skillname, sname;
        int skill, skill_basic, cnt = 0;
        int improve;

        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if ( me->is_busy() )
                return notify_fail("��������æ���ء�\n");
	if ( me->is_exert() || me->is_perform() )
                return notify_fail("����ʹ����ĳ�����⼼���أ����ܷ������ã�\n");
        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if (where->query("sleep_room"))
                return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");

        sscanf(arg, "%s %d", arg, cnt);
//      if (!random(2)) return notify_fail("ʹ�� lian|practice skill ���� �ĸ�ʽ�᷽��һЩ��\n");
        if (arg == "parry")
                return notify_fail("�㲻��ͨ�������м�����ϰ��\n");
        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
        if( skill_basic/2 <= skill/3 )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

        notify_fail("�����ͨ��ѧϰ�������µ�һ�С�\n");
        if( (improve = SKILL_D(skillname)->practice_skill(me)) ) {
        	if(improve == 1) improve = skill_basic/5 +1;
        	//����ѧ�����
        	if(me->worker_skill("highest")>350) improve = improve*7/10;
		else if(me->worker_skill("highest")>220) improve = improve*8/10;
		if(me->worker_skill("limit")>600) improve = improve*8/10;
		////        	

        //�츳����ͯ������Ӱ��Ч���� by lsxk@hsbbs 2008/3/14
        if((int)me->query("relife/study/stzs",1) > 0){
            tell_object(me,HIG"��ֻ�����Լ��츳���ˣ���ϰ��������Զ���ڱ��ˣ�\n"NOR);
            improve += (int)me->query("relife/study/stzs",1) * improve * 2 / 100;
        }
                if (!random(3)) tell_room(environment(me),
                        me->name() +
                        "����ר����ϰ" +
                        to_chinese(skillname) + "��\n", ({ me }));
                write ("��" + ((cnt == 1)?"����":"����") + "��ϰ" + to_chinese(skillname));
                if (stringp(sname = SKILL_D(skillname)->query_skill_name(random(me->query_skill(skillname,1)))))
                        write ("�С�" + sname + "����һ��");
                write( "�������" + ((cnt == 1)?"����":"����") + "������\n");
                me->improve_skill(skillname,
                        improve,
                        skill_basic > skill? 0: 1);
                while (--cnt) {
                        if (SKILL_D(skillname)->practice_skill(me)) 
                                me->improve_skill(skillname,
                                        improve,
                                        skill_basic > skill? 0: 1);
                        else return 0;
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��practice|lian <��������> <����>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
�����ָ����������ʾ����������Ϊֹ��
TEXT
        );
        return 1;
}
