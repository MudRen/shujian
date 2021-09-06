#include <ansi.h>
inherit F_CLEAN_UP;

nosave mapping get_chinese = ([
	"axe":"��",
	"brush":"��",
	"fork":"��",
	"hook":"��",
	"spear":"ǹ",	
	"whip":"��",
	"stick":"��",
	"sword":"��",
        "xiao":"��",
	"blade":"��",
	"dagger":"ذ��",
	"club":"��",
	"staff":"��",
	"hammer":"����",
	//"throwing":"����",
	"cap":"ͷ��",
	"glove":"����",
	"boot":"ѥ",
	"belt":"����",
	"mantle":"����",
	"coat":"����",
	"armor":"����",
	//"cloth":"�·�",
	//"finger":"��ָ",
	//"neck":"����",	
	//"wrists":"����",	
	//"hands":"ָ��",
	//"mineral":"��ʯ",
	//"jade":"��",
	//"silk":"˿",
	//"cloths":"��",
]);

int sort_skill2(string sk) 
{
	return (SKILL_D(sk)->type() == "knowledge" && SKILL_D(sk)->type2() == "worker");
}
int main(object me,string arg)
{
        object ob;
        mapping job;
	mapping skl, lrn, map;
        
	string *sname, *mapped, *allskills, str = "", str2 = "";
	int i, j, k;
	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) ob = LOGIN_D->find_body(arg);
		if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}	
	skl = ob->query_skills();
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});
	
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	allskills  = sort_array( keys(skl), (: strcmp :) );	
	
	sname  = filter_array( allskills, (: sort_skill2 :) );
	allskills -= sname;
	j = sizeof(sname);

	if( j > 0){
		str = HIW"��";
		str += (ob==me?"��":ob->name(1))+"�Ĵ��켼�ܱ�"NOR"��\n";	
		str += "��������������������������������������������������������������������������������������������\n";
		str += sprintf("%-90s", "���ܹ�"+chinese_number(j)+"���");
		for(i=0; i < j; i++) {
			if (i % 2 == 0) str += "��\n��";
			else str += "  ";
			str += sprintf("%s%-8s%-14s"HIC"��"NOR"%s %3d/%6d",
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				to_chinese(sname[i]), "(" + sname[i] + ")",
				"/cmds/skill/skills.c"->skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]],);
			if ( i > j-2 && i % 2 == 0)
				str +="                                             ";
		}
		str += "��\n��������������������������������������������������������������������������������������������\n";
	}
	else
		str += HIW+" "+(ob==me ? "��" : ob->name(1)) + "Ŀǰ��û��ѧ���κδ��켼�ܡ�\n"NOR;
	//
	write (str);		       
        job = ob->query("forging");
        if(!mapp(job)) job=([]);
        
        if(!arrayp(keys(job))) return 1;	
	k = sizeof(keys(job));	
	if (k<=0) str2 = HIW+" "+(ob==me ? "��" : ob->name(1))+"Ŀǰ�в�������κζ�����\n"+NOR;
	else {

		
		while(k--){
			str2 = sprintf(" %-14s",get_chinese[keys(job)[k]]+"("+capitalize(keys(job)[k])+")")+str2;
			if (k % 4 == 0) str2 = "\n��������������������������������������������������������\n" + str2;
		}
		str2 = HIW+"��"+(ob==me ? "��" : ob->name(1))+"�Ѿ�ѧ��Ĵ�����Ŀ�С�"+NOR
		 + str2
		 +"\n��������������������������������������������������������\n"; 
	}
	
	write (str2);	
        return 1;
}

int help(object me)
{
        string *p;
        string str = "\n";
        int i = sizeof(get_chinese);
	p= sort_array(keys(get_chinese), 1);
	while(i--){
			str = sprintf("%-14s",get_chinese[p[i]]+"("+capitalize(p[i])+")")+str;
			if (i % 4 == 0) str = "\n��������������������������������������������������������\n" + str;
	}
write(@HELP
ָ���ʽ : worker
���ָ�����������ʾĿǰ�Ĵ��켼�ܵȼ����Ѿ�ѧ��Ĵ�����Ŀ��
Ŀǰ���ŵĴ�����Ŀ�У�
HELP);
		write(str);
		write("��������������������������������������������������������\n");

    return 1;
}
