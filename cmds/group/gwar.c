// gwar.c  ����ս��״��
// by augx@sj 3/18/2002

#include <ansi.h>
inherit F_CLEAN_UP;
#include <mudlib.h>
#include <group.h>

int help(object me)
{
	write(@HELP
ָ���ʽ :
gwar
�г�����ս��״����

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	int i,j,k;
	mapping gtmp;
	mapping showed;
	string tid;
	string * sk;
	mapping * sv;

	if( me->is_busy() ) return notify_fail("����æ���ء�\n");

	write("\n�� "+CHINESE_MUD_NAME+"("+INTERMUD_MUD_NAME+") ����ս��״����\n");
	write("�������������������������ө������������ө������������ө������������ө������������ө�������������\n");
	write("��    ��  ս  ��  ��    �� ���˰���һ �� ���˰��ɶ� �� ���˰����� �� ���˰����� �� ���˰����� ��\n");
	write("�ĩ����������������������ة������������ة������������ة������������ة������������ة�������������\n");

	gtmp = GROUP_D->get_groups(1);
	sk = keys(gtmp);
	sv = values(gtmp);
	showed = ([ ]);
	j = sizeof(sk);
	for(i=k=0;i<j;i++) {
		if( sv[i]["war"]<3 || !undefinedp(showed[sk[i]]) ) continue;
		tid = sv[i]["target"];
		showed[tid] = 1;

		if(k) write("�ĩ���������������������������������������������������������������������������������������������\n");
		k++;

		write(sprintf("��%12s%-10s  %-12s  %-12s  %-12s  %-12s  %-12s��\n",GROUP_D->get_group_name(sk[i]),"("+sk[i]+")",
			GROUP_D->get_group_name(sv[i]["friend1"]),
			GROUP_D->get_group_name(sv[i]["friend2"]),
			GROUP_D->get_group_name(sv[i]["friend3"]),
			GROUP_D->get_group_name(sv[i]["friend4"]),
			GROUP_D->get_group_name(sv[i]["friend5"]) ));

		write(sprintf("��        %7s        ��ʣ��ʱ�䡿��%3d����  ��ʵ������%7d:%-7d  ��ս������%4d:%-4d��\n",
			(sv[i]["war"]==3)?"PREPARE":"   VS  ",
			to_int(((sv[i]["time"] + ((sv[i]["war"]==3)?WAR_PREPARE:WAR_TIME) *60) - time()) / 60),
			sv[i]["league_power"],gtmp[tid]["league_power"],
			sv[i]["war_score"],gtmp[tid]["war_score"] ));

		write(sprintf("��%12s%-10s  %-12s  %-12s  %-12s  %-12s  %-12s��\n",GROUP_D->get_group_name(tid),"("+tid+")",
			GROUP_D->get_group_name(gtmp[tid]["friend1"]),
			GROUP_D->get_group_name(gtmp[tid]["friend2"]),
			GROUP_D->get_group_name(gtmp[tid]["friend3"]),
			GROUP_D->get_group_name(gtmp[tid]["friend4"]),
			GROUP_D->get_group_name(gtmp[tid]["friend5"]) ));
	}

	write("������������������������������������������������������������������������������������������������\n");

	me->start_busy(1);
	return 1;
}
