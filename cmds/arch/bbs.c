//bbs.c 

#include <database.h>

int help(object me);

nosave object athor;

int main(object me,string arg)
{
	string db,sql;
	if(!arg) return help(me);
	if( sscanf(arg,"%s %s",db,sql)!=2 ) return help(me);
        BBS_D->add_Bbs_Up_Map(db,sql,this_object(),"back",1);
	athor = me;
	write("׼��ִ�С�����������\n");
	return 1;
}

void back(mixed ret)
{
	if(athor) tell_object(athor,"��Ҫ���SQL����Ѿ��ɹ���WEB��������ִ�С�\n");
	if(!sizeof(ret)) return;
	if(athor) tell_object(athor,sprintf("WEB���������صĽ���ǣ�%O",ret));
}


int help(object me)
{
	write(@HELP
	ָ���ʽ��bbs <dbname> <sql���>
	���ܿ�����Զ����MUD������WEB��������ִ��һ��SQL��䡣
HELP
	);
	return 1;	
}
