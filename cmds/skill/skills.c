// skills.c
// Modified by snowman@SJ 14/03/2000

#include <ansi.h>
#include <level.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({ LEVEL });

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,HIB "�����ž�" NOR,MAG "��֪һ��" NOR,HIM "��������" NOR,
	CYN "������" NOR,YEL "����С��" NOR,YEL "�ڻ��ͨ" NOR,HIY "�������" NOR,
	HIY "��Ȼ���" NOR,HIG "���д��" NOR,HIG "��ͬ����" NOR,HIC "������˫" NOR,
	HIC "������" NOR,HIW "�����ױ�" NOR,HIW "������ʥ" NOR,HIR "��ǰ����" NOR
});

string *valid_type = ({
"force", "parry",  "dodge", "unarmed","claw",
"cuff",  "finger", "strike","hand",   "leg",
"sword", "blade",  "dagger","brush",  "spear",
"hook",  "stick",  "staff", "club",   "throwing",
"whip",  "axe",    "hammer","bow","arrow",
});

string skill_level(string, int);

int sort_skill2(string sk) // add by augx@sj 8/27/2001
{
	return (SKILL_D(sk)->type() == "knowledge" && SKILL_D(sk)->type2() == "worker");
}

int sort_skill(string sk)
{
	return (SKILL_D(sk)->type() != "martial" && SKILL_D(sk)->type() != "array");
}

int sort_basic(string sk)
{
	return member_array(sk, valid_type)!=-1;
}

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, *allskills, str = "";
	int i, j;

	seteuid(getuid());

	if(!arg)
		ob = me;

	else if(arg == "?"){
		i = sizeof(skill_level_desc);
		while(i--) {
			str = "    " + skill_level_desc[i] + str;
                        if (i % 5 == 0) str = "\n" + str;
		}
		str = "\n\n���ܵ������ɵ͵�������Ϊ��"+str;
		i = sizeof(knowledge_level_desc);
		while(i--) {
			str = "    " + knowledge_level_desc[i] + str;
			if (i % 4 == 0) str = "\n" + str;
		}
		return notify_fail("֪ʶ�������ɵ͵�������Ϊ��"+str+"\n");
	}

	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) ob = LOGIN_D->find_body(arg);
		if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}

	if( ob!=me && !wizardp(me) ){
		if(environment(ob)!=environment(me))
			return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
		if( !ob->is_apprentice_of(me)
		 && !me->is_apprentice_of(ob)
		 && ob->query("winner") != me->query("id")
		 && me->query("marry/id") != ob->query("id")) {
		 	if( userp(ob)
		  	 || !me->query("group/id")
		  	 || me->query("group/id") != ob->query("group/id")
		  	 || me->query("group/class") >= ob->query("group/class") )
				return notify_fail("ֻ����ʦͽ��ϵ��ͬ��һ�����ɵ��˲��ܲ쿴���˵ļ��ܡ�\n");
		}
	}

	skl = ob->query_skills();

	if(!j = sizeof(skl)) {
		write( (ob==me ? "��" : ob->name(1)) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}

	allskills  = sort_array( keys(skl), (: strcmp :) );

	str = HIW"��";
	str += (ob==me?"��":ob->name(1))+"�ļ��ܱ�"NOR"���ܹ�"+chinese_number(j)+"���";
	str += "\n��������������������������������������������������������������������������������������������\n";
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	// add by augx@sj 8/27/2001
	sname  = filter_array( allskills, (: sort_skill2 :) );
	allskills -= sname;

	j = sizeof(sname);
	if( j > 0){
		str += sprintf("%-90s", "��"HIY"��ְҵ���� "+chinese_number(j)+" �֡�"NOR"��");
		for(i=0; i < j; i++) {
			if (i % 2 == 0) str += "��\n��";
			else str += "  ";
			str += sprintf("%s%-8s%-14s"HIC"��"NOR"%s %3d/%6d",
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				to_chinese(sname[i]), "(" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]],);
			if ( i > j-2 && i % 2 == 0)
				str +="                                             ";
		}
		str += "��\n��������������������������������������������������������������������������������������������\n";
	}
	//

	sname  = filter_array( allskills, (: sort_skill :) );
	allskills -= sname;

	j = sizeof(sname);
	if( j > 0){
		str += sprintf("%-90s", "��"HIY"������� "+chinese_number(j)+" �֡�"NOR"��");
		for(i=0; i < j; i++) {
			if (i % 2 == 0) str += "��\n��";
			else str += "  ";
			str += sprintf("%s%-8s%-14s"HIC"��"NOR"%s %3d/%6d",
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				to_chinese(sname[i]), "(" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]],);
			if ( i > j-2 && i % 2 == 0)
				str +="                                             ";
		}
		str += "��\n��������������������������������������������������������������������������������������������\n";
	}

	sname  = filter_array( allskills, (: sort_basic :) );
	allskills -= sname;

	j = sizeof(sname);
	if(j > 0){
		str += sprintf("%-90s", "��"HIY"���������� "+chinese_number(j)+" �֡�"NOR"��");
		for(i=0; i < j; i++) {
			if (i % 2 == 0) str += "��\n��";
			else str += "  ";
			str += sprintf("%s%-8s%-14s"HIC"��"NOR"%s %3d/%6d",
				(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
				to_chinese(sname[i]), "(" + sname[i] + ")",
				skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
				skl[sname[i]], (int)lrn[sname[i]]);
			if ( i > j-2 &&i % 2 == 0)
				str +="                                             ";
		}
		str += "��\n��������������������������������������������������������������������������������������������\n";
	}

	sname  = allskills;

	j = sizeof(sname);
	if(j > 0){
		str += sprintf("%-90s��\n", "��"HIY"�����⼼�� "+chinese_number(j)+" �֡�"NOR"��");
		for(i=0; i < j; i++) {
			if (strlen(strip(to_chinese(sname[i]), " (" + sname[i] + ")")) > 17) {
					str += sprintf("��  %s%s%-18s%-22s" HIC "�� "NOR"%s %3d/%7d %22s\n",
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			to_chinese(sname[i]), " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],"��");
			}
			else {
			str += sprintf("��  %s%s%-12s%-28s" HIC "�� "NOR"%s %3d/%7d %22s\n",
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			to_chinese(sname[i]), " (" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],"��");}
		}
		str += "��������������������������������������������������������������������������������������������\n";
	}


	write(str);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	switch(type) {
		case "knowledge":
			grade = level / 20;
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			//grade = level / 7; this is old SJ system
                		// but now system the player combat speed is very fast.
                        grade = level / 17;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write("\nָ���ʽ : skills [<ĳ��> | ?]\n");
	write(@HELP
���ָ����������ѯ��ѧ���ļ��ܡ�
��Ҳ���Բ�֪������ʦͽ��ϵ���Լ��Ŀ����ļ���״����
��� skills ? �����ʾĿǰ�ļ��ܵ�������

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

	Copyright 1997-1999 ShuJian MUD Wizard Group.
	All rights reserved.

	Visit our Homepage at - www.mymud.com

HELP);

    return 1;
}
