// verify.c
// Modified by snowman@SJ 16/03/2000

/* �������ģ�д�˸���ѯ�书��������˱Ƚ�ϲ���п�ܵ�ͼ�Σ���λ�������
   PS: ��û���Ż��� ansi ��ʾ��OS�����ɫ�Ŀ�ܻ��������У�ȥ��code��ĸ�ansi color�����ˡ�
   
	�� verify xxx.yyy �� call yyy �ļ���� int help(object me)�����԰�������
	command ��help()��д��
   �����ټӵ��������ܵģ������ù��ڻ����˷������ã��������ɡ�
   ��̫��ȭ��help()�����ο���

int help(object me)
{
	write(WHT"\n̫��ȭ��"NOR"\n");
	write(@HELP
	̫��ȭ��Ϊ��ĩԪ���䵱�����������������ϵ���֮˵��������Ȼ��������
	��죬�Ծ��ƶ����ᷢ���ˣ���Ϊ����֮����ϳ���ѧ��ȭ��ʱ˫��Բת��
	ÿһ�ж�����̫��ʽ�������仯����΢���ʵ�ǿ�������ѧ�д���δ�е�
	����ء�����Ϊ�����鶥�������ذα����������Ρ�����׹�⡹ʮ�����֣�
	�������У���������������һ������·ȭ����Ҫּ��
	̫��ȭ����Ҫ�����ɷ��ɣ���չδչ�������ⲻ�ϣ����������Ϊ����һ����
	
	Ҫ��  �������ȼ� 100 ���ϣ�
		���� 500 ���ϣ�      
		���������״�ȭ�С�
HELP
	);
	return 1;
}

*/

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


mapping valid_type = ([
"unarmed":      "ȭ��",
"claw":	 "צ��","cuff":	 "ȭ��",
"finger":       "ָ��","strike":       "�ƹ�",
"hand":	 "�ֹ�","leg":	  "�ȹ�",
"sword":	"����","blade":	"����",  
"dagger":       "ذ��","brush":	"�ʷ�",	  
"spear":	"ǹ��","hook":	 "����",	  
"stick":	"����","staff":	"�ȷ�",	  
"club" :	"����","throwing":     "����",	  
"whip":	 "�޷�","axe":	  "����",
"hammer":       "����","force":	"�ڹ�",  
"dodge":	"�Ṧ","parry":	"�м�", 
	"arrow":"����", 
]);

string skill_level(string, int);
string skill_enables(object sk);

int sort_skill(string file)
{
	int i;
	if ( file[<2..<1] != ".c" ) return 0;
	if ( !sscanf(file, "%*s.c") )  return 0;
	if ( sscanf(file, "%*s_noshow.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}

int main(object me, string arg)
{
	mapping lrn;
	string exert, str, *file, pfm;
	object sk;
	int i, j = 0;

	seteuid(getuid());

	if(!arg) return notify_fail("ָ���ʽ : verify [�书����].[?|���⼼��]\n");
	
	sscanf(arg, "%s.%s", arg, str);
		
	if(!wizardp(me) && !me->query_skill(arg, 1)) 
		return notify_fail("��Ҫ���ʲô���ܣ�\n");
	
	if(file_size(SKILL_D(arg)+".c") < 1)
		return notify_fail("������Ҫ��Լ����ļ��Ѿ���ʧ����֪ͨ��ʦ��\n");
	
	if( stringp(str) ){
		// ��ʽ verify xxx.? �ǲ�ѯ��skill�İ�����
		// verify xxx.yyy �ǲ�ѯ yyy �İ�����
		if( str == "?" ){
			notify_fail("�Բ��𣬡�"+to_chinese(arg)+"��Ŀǰ��û����ϸ�İ���˵����\n");
			return SKILL_D(arg)->help(me);
		}
		else if( stringp(exert = SKILL_D(arg)->exert_function_file("")) && file_size(exert + str +".c") > 0){
			notify_fail("�Բ���"+to_chinese(arg)+"�ڹ�����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		else if( stringp(exert = SKILL_D(arg)->perform_action_file("")) && file_size(exert + str +".c") > 0){
			notify_fail("�Բ���"+to_chinese(arg)+"�⹦����ġ�"+str+"������û����ϸ��˵����\n");
			return (exert + str)->help(me);
		}
		return notify_fail("�Բ���"+to_chinese(arg)+"û�С�"+str+"������ܡ�\n");
	}
	
	lrn = me->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	if (strlen(strip(to_chinese(arg))) > 17) {
		str = sprintf("\n��%-24s����������������������������������������\n", HIW"��"+to_chinese(arg)+"���ܱ�"NOR);
		}
		else {
	str = sprintf("\n��%-24s��������������������������������������������\n", HIW"��"+to_chinese(arg)+"���ܱ�"NOR);}
	
	str = replace_string(str, "  ", "��");
	str += sprintf("��"HIY"�ȼ�"NOR"��  %s %3d/%6d         "HIY"���"NOR"��  %-15s%9s\n",skill_level(SKILL_D(arg)->type(), 
			me->query_skill(arg, 1)), me->query_skill(arg, 1), 
			(int)lrn[arg], to_chinese(SKILL_D(arg)->type()), "��"); 
	
	if(SKILL_D(arg)->type() != "martial"
	|| member_array(arg, keys(valid_type))!=-1) 
		return notify_fail(str+"����������������������������������������������������������������������\n");

	str += "��                                                                  ��\n";
	sk = load_object(SKILL_D(arg));
	
	exert = skill_enables(sk);
	if(exert != ""){
		str += exert;
		i++;
	}
	
	if( stringp(exert = SKILL_D(arg)->exert_function_file("")) ){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIY"�ڹ�����(exert + )"NOR"��                                              ��\n";
		for(i=0; i < j; i++){
			pfm = call_other(exert + file[i], "exert_name");
			str += sprintf("��      %-14s %-44s ��\n",YEL+replace_string(file[i], ".c", "")+NOR, 
				pfm?WHT"��"NOR + pfm + WHT"��"NOR:"");
		}
		j = 0;
	}
	
	if( stringp(exert = SKILL_D(arg)->perform_action_file(""))){
		file = get_dir(exert);
		if( sizeof(file) > 0){
			file  = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	
	if(j && j > 0){
		if( i )
			str = str + "����������������������������������������������������������������������\n";
		str += "��"HIY"�⹦����(perform + )"NOR"��                                            ��\n";
		for(i=0; i < j; i++){
			pfm = call_other(exert + file[i], "perform_name");
			str += sprintf("��      %-14s %-44s ��\n",WHT+replace_string(file[i], ".c", "")+NOR, 
				pfm?WHT"��"NOR + pfm + WHT"��"NOR:"");		  
		}
	}
	str += "����������������������������������������������������������������������\n";
	write(str);
	return 1;
}

string skill_enables(object sk)
{
	int i, j;
	string str, *skills;
	skills = keys(valid_type);
	
	for(i=0; i < sizeof(skills); i++) {
		if (sk->valid_enable(skills[i])) continue;
		skills[i] = 0;
	}
	
	skills -= ({ 0 });
	j = sizeof(skills);
	if( !j || j < 1)
		return "";
	str = "��"HIY"���⼼��"NOR"��                                                        ";
		
	for(i=0; i < j; i++) {
		if (i % 4 == 0) str += "��\n��        ";
		str += sprintf("%-14s ", HIC+valid_type[skills[i]]+"("+skills[i]+")"NOR);
		if ( i > j-2 ){
			switch(i%4){
				case 0: str +="                                           "; break;
				case 1: str +="                            "; break;
				case 2: str +="             "; break;
				default: break;
			}
		}
	}
	str += "��\n";
	return str;
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
			//grade = level / 7;
			//but now system the player combat speed is very fast.//by yeju.
			grade = level / 11;
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write("\nָ���ʽ : verify [�书����].[�������� | ?]\n");
	write(@HELP
���ָ����������ѯ����ܵĹ��ܺ����ݡ�

���⼼�ܱ�ʾ���� enable �ļ��ܣ��磺
	(�Ṧ���мܡ��������ȷ�) ��ʾ�����书���������Ṧ���мܣ��������ȷ��ȡ�

�ڹ�������ʾ������(exert)���ڹ���

�⹦������ʾ��ʹ��(perform)���⹦�����еȡ�

����ڹ����⹦�ľ����а������ܣ����� verify skill.pfm ����ʽ���鿴��
�磺    verify taiji-quan.dongjing  �鿴������
	verify yinyun-ziqi.yinyun   �鿴���ھ�
	verify taiji-quan.?	 �鿴̫��ȭ


Snowman@SJ 06/04/1999
Copyright 1997-2000 ShuJian MUD Wizard Group.
All rights reserved.
	
Visit our Homepage at - www.mymud.com 

HELP);

    return 1;
}
