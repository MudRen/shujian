// glist.c  �����б�
// by augx@sj 4/11/2002

#include <ansi.h>
inherit F_CLEAN_UP;
#include <mudlib.h>

int help(object me)
{
	write(@HELP
ָ���ʽ :
glist
�г����еİ��ɵ������

glist [����id]
�鿴�˰��ɵĳ�Ա��
HELP
	);
	return 1;
}

void remove_busy(object me)
{
	if (me) me->delete_temp("command_busy");
}

int list_member(string gid)
{
	mapping gmembers;
	string * sv, * sk;
	int i,j,k;

	if( !GROUP_D->site_now(gid) )
		return notify_fail( GROUP_D->get_last_error() );
	if( !(gmembers = GROUP_D->get_group(gid,2)) )
		return notify_fail("û��������ɣ�\n");

	sk = keys(gmembers);
	sv = values(gmembers);

	write("\n�� "+CHINESE_MUD_NAME+"("+INTERMUD_MUD_NAME+") "+GROUP_D->get_group_name(gid)+"��Ա��("+HIG"��ɫ��ʾ�������ߡ�"NOR+")\n");
	write("��������������������������������������������������������������������������������������������\n");

	j = sizeof(gmembers);
	for(i=0,k=1;i<j;i++) {
		if( k == 1 ) write("��");
		write( sprintf("  %-18s  ",(find_player(sk[i])?HIG:NOR)+sv[i]+"("+capitalize(sk[i])+")"+NOR) );
		k++;
		if( k > 4 ) {
			write("��\n");
			k = 1;
		}
	}

	if( k>1 && k<5 ) write( sprintf("%"+((5-k)*22+2)+"s\n","��") );
	write("��������������������������������������������������������������������������������������������\n");
	write(GROUP_D->get_group_name(gid)+"�����ܹ��г�Ա"+chinese_number(j)+"����\n");

	this_player()->set_temp("command_busy", 1);
	call_out("remove_busy", 3, this_player());
	return 1;
}

int main(object me, string arg)
{
	mapping * groups, mp;
	int i;

	if( me->query_temp("command_busy"))
		return notify_fail("����æ���ء�\n");

	if( arg ) return list_member(arg);

	write("\n�� "+CHINESE_MUD_NAME+"("+INTERMUD_MUD_NAME+") �������а�\n");
	write("�������ө������������ө��������ө����������������ө��������ө������ө������ө��������ө���������\n");
	write("��������  ��������  �����ɱ�ʶ��    ��  ��      ��������  ��ʵ  ������  ������ǰվ�㩦Ǩ��վ�㩧\n");
	write("�ĩ����ة������������ة��������ة����������������ة��������ة������ة������ة��������ة���������\n");

	groups = GROUP_D->get_sort_group();
	for(i=0;i<sizeof(groups);i++) {
		mp = GROUP_D->get_group(groups[i]["id"]);
		write( sprintf("��%-4i  %-12s  %-8s  %-16s  %2i(%3i)  %-6i  %-7i  %-8s  %-8s��\n",
			i+1,mp["name"],groups[i]["id"],mp["master1_name"]+"("+mp["master1"]+")",mp["members"],mp["max_members"],mp["power"],mp["score"],mp["site"],mp["site_next"]) );
	}

	write("������������������������������������������������������������������������������������������������\n");
	write("��ǰ�վ�㲻�Ǳ�վ�İ��ɵ�ͳ������ÿ���糿����һ�Ρ�\n");

	me->set_temp("command_busy", 1);
	call_out("remove_busy", 3, me);
	return 1;
}
