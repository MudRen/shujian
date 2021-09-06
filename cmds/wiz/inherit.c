//inherit by Ciwei@SJ

#include <ansi.h>

int help(object me);

nosave string file;

int check(object ob)
{
	if (  (strsrch(file_name(ob),"/d") == 0
	|| strsrch(file_name(ob),"/kungfu/class") == 0
	|| strsrch(file_name(ob),"/clone") == 0 )
	&& inherits(file,ob)!=0 ) return 1;
	return 0;
}

int cloned(object ob)
{
	return strsrch(file_name(ob),"#")!=-1;
}

string *colors = ({NOR"",HIG"",HIR""});

int main(object me,string arg)
{
	object *all;
	string str,temp;
		
	if(!arg) return help(me);
	if(file_size(arg)==-1) return notify_fail("Ŀ�겻���ڡ�\n");
	if(file_size(arg)==-2) return notify_fail("Ŀ���Ǹ�Ŀ¼��\n");
	file = arg;
	all = objects( "check" );
	if(!sizeof(all)) return notify_fail("ʲô��û�з��֡�\n");
	str = "\n\t���ڼ̳�"+arg+"�������Ϣ��\n";
	str += sprintf("%-70s%-40s\n","���","������Ϣ");
	str += "\n";
	for(int i =0;i<sizeof(all);i++){
		str += colors[inherits(arg,all[i])];
		if(cloned(all[i])) {
			temp = "Ϊ����Ʒ";
			if(environment(all[i])) temp+= sprintf("��λ�ã�%O",environment(all[i]));
			else temp += "��";
		}
		else temp = "�Ǹ���Ʒ��";
		str += sprintf("%-70O%-40s\n",all[i],NOR+temp );
		str += NOR;
	}
	me->start_more(str);
	return 1;	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��inherit [�ĵ�]
	�������м̳и��ĵ��������
	
	��ɫ��ʾΪ��ҪUpdate�������
HELP
	);
	return 1;
}