// info command.
// by snowman@SJ 1998.

#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;

// #define TIME_TICK ((time()-945630720)*60)
mixed main(object me)
{
	object *ob;
	int i,ppl_cnt = 0, cnt = 0, wcnt = 0, f_cnt = 0, u_cnt = 0, i_cnt;

	ob = filter_array(objects(), (: userp :));

	i = sizeof(ob);
	while( i-- ) {
            if (wizardp(ob[i]) && ((int)ob[i]->query("env/invisibility")<5)) wcnt++;
		else if (interactive(ob[i])){
			 ppl_cnt++;
			 if(ob[i]->is_fighting()) f_cnt++;
			 if(!living(ob[i])) u_cnt++;
			 if(query_idle(ob[i]) > 120) i_cnt++;
			 }
		else cnt++;
	}

	write("\n"+MUD_NAME+"Ŀǰ���� "+wcnt+" λ��ʦ�� "+ppl_cnt+" λ��������У�"+cnt+" λ��Ҷ����С�
���У�
        ��ս�����У� "+f_cnt+" λ��
    ���Ի�˯�����У� "+u_cnt+" λ��
          �������У� "+i_cnt+" λ��
          
ϵͳ������"+query_load_average()+"��
���ڵ� time() �ǣ�" + time() + "��
���ڵ� Natured time() �ǣ�" + TIME_TICK + " " + localtime(TIME_TICK)[2] + ":" + localtime(TIME_TICK)[1]+"��
���ڵ� uptime() �ǣ�" + uptime() + "��
Natured ��ʱ���ǣ�" + NATURE_D->query_daytime() + "��\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : users

���ָ������г�Ŀǰ�����������

���ָ� who
HELP
	);
	return 1;
}
