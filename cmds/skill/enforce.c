// enforce.c
// Modified by snowman@SJ 02/08/2000. ���� 200 ���ޡ�
// By Spiderii@ty ת�����jiali����200��������
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts;

        if( !arg || (arg!="none" && arg!="max" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("ָ���ʽ��enforce|jiali <ʹ�����������˵�>|none|max\n");

        if( !me->query_skill_mapped("force") )
                return notify_fail("������� enable һ���ڹ���\n");

	if ( me->query_temp("qkdny/hua"))
		return notify_fail("������ʹ�á������־�����ʱ�޷�������\n");

        if( me->query_condition("no_enforce") )
                return notify_fail("�㵤�ﱻ�ƣ���ʱ���ܼ�����\n");
                
        if( arg == "none" )
                me->delete("jiali");

        	if(arg=="max"){
        		pts = (int)me->query_skill("force") / 2;
           	if (pts > 200 && !me->query("relife/times"))
            		pts = 200;
        	me->set("jiali", pts);

        	}
         else
        {
                if( pts < 0 || pts > me->query_skill("force") / 2 || (pts > 200 && !me->query_temp("jiuyang/yijin")))
                        return notify_fail("��ֻ���� none ��ʾ���������������ֱ�ʾÿһ���ü��������������� 200��\n");
                me->set("jiali", pts);
        }

        if (pts)
                write("�������" + chinese_number(pts) + "��������˵С�\n");
        else
                write("�������ʹ�������˵С�\n");
        return 1;
}


int help (object me)
{
        write(@HELP
ָ���ʽ: enforce|jiali <ʹ�����������˵�>|none
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�

enforce none ���ʾ�㲻ʹ�������� 

See Also: enable
HELP
        );
        return 1;
}

