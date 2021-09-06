// wizlink.c
// Creator Numa@SJ 2000.7 for wiz_gourp touch each other.

#include <ansi.h>
#define LINK_FILE "/log/wizlink"
#define WIZ_FILE  "/log/wiz_tell"
#define TITLE HIY"��ʦ��ϵϵͳ"NOR
#define TMP "����"
#define HELP_WIZLINK "\nwizlink��Ҫָ���÷���⣺\n\nwizlink			��ʾ�����档\nwizlink me		�޸ı�����Ϣ��\nwizlink -[option]	�ֱ���ʾ��ʦ��Ϣ�б�\nwizlink [ID] [����]	��ĳλ��ʦ��������\nwizlink note		�鿴�Լ��ı�����\nwizlink del note	ɾ���Լ������˵ĵı�����\n\noption �ֱ�Ϊ�� \n	phone		�绰�б�\n	bp		�����б�\n	mobile		�ֻ��б�\n	email		�����ʼ��б�\n	homepage	������Ҷ�б�\n\n\t\t"HIC"All Rights Reserved By Numa@SJ.2000\n\n"NOR

inherit F_CLEAN_UP;

string *line = ({
	"sex",
	"age",
        "phone",
        "bp",
        "mobile",
        "email",
        "location",
        "homepage",
        "myback"
});

string *line_info = ({
	"�����Ա�",
	"�������䣺",
        "���ĵ绰��",
        "���ĺ�����",
        "�����ֻ���",
        "���ĵ����ʼ���",
        "����סַ��",
        "������Ҷ��",
        "��ע��",
});

// ����
int tellme(object ob, string msg)
{
	if (ob)
		tell_object(ob,msg);
}

// wizard level
string wizard_lev(string name)
{
	string lev;
	
	lev = SECURITY_D->get_status(name);
	switch (lev) {
		case "(admin)" :
			return "Adm";
		case "(assist)" :
			return "Ass";
		case "(arch)" :
			return "Arc";
		case "(wizard)" :
			return "Wiz";
		case "(apprentice)" :
			return "App";
		case "(immortal)" :
			return "Imm";
		default :
			return "Ply";
	}
}

// wizard security
int wizard_sec(string me, string lev)
{
	string lev1;
	
	lev1 = wizard_lev(me);
	
	switch (lev1) {
		case "Adm" :
			return 1;
		case "Ass" :
			if (lev == "Adm")
				return 0;
			else
				return 1;
		case "Arc" :
			if (lev == "Adm" || lev == "Ass")
				return 0;
			else
				return 1;
		case "Wiz" :
			if (lev == "Adm" || lev == "Ass" || lev == "Arc")
				return 0;
			else
				return 1;
		case "App" :
			if (lev == "Adm" || lev == "Ass" || lev == "Arc" || lev == "Wiz")
				return 0;
			else
				return 1;
		case "Imm" :
			if (lev == "Adm" || lev == "Ass" || lev == "Arc" || lev == "Wiz" || lev == "Imm")
				return 0;
			else
				return 1;
		default :
			return 0;
	}
}

// �����ļ��ṹ
string *analyse_file(string filename)
{
	string *file = ({});
	
	if (file_size(filename) < 0)
		return file;
	file = explode(read_file(filename),"\n");
	if (!sizeof(file))
		return ({});
	return file;
}
// have me or not ?
int have_me(string *file, string myid)
{
	int i, j = -1;
	
	for (i=0;i<sizeof(file);i++) {
		if (strsrch(file[i],myid)>=0) {
			j = i;
			break;
		}
	}
	return j;
}

// ¼�룬�޸ı�����Ϣ
int correct_me(object me)
{
	string *file, *sfile = ({"id" + ":" + geteuid(me),"","","","","","","","",""});
	int j, tmp = 0;
	
	if ((file = analyse_file(LINK_FILE)) == ({}))
		write(HIR"\n��ӭ����һ��ʹ��"+TITLE+HIR"��\nĿǰ"+TITLE+HIR"���κμ�¼��\n"NOR);
	else {
		if ((j = have_me(file, geteuid(me))) == -1) {
			write(HIC"\nĿǰ"+TITLE+HIC"�ﻹû��������Ϣ����ӭ��¼���Լ�����Ϣ��\n"NOR);
			j = sizeof(file);
			write("��������¼��������Ϣ��\n");
		}
		else {
			write(HIW"\n"+me->name(1)+"�����ã�\n����"+TITLE+HIW"�ĵ�"+chinese_number(j+1)+"λ¼����Ϣ�ߡ��������޸��Լ�����Ϣ��\n");
			write("���������޸�������Ϣ��\n");
			tmp = 1;
		}

		if (tmp == 1) {
			sfile = explode(file[j],",");
       			write(sfile[1]+"\n");
       			if (j != 0)
       				file = file[0..j-1] + file[j+1..sizeof(file)];
       			else
       				file = file[1..sizeof(file)];
       		}
       		write_file(LINK_FILE,implode(file,"\n") + "\n",1);
		write(line_info[0]);
		input_to("get_my_info_2", file, sfile, tmp, 1);
		return 1;
	}
	write("��������¼��������Ϣ��\n");
	write(line_info[0]);
	input_to("get_my_info", sfile, 1);
	return 1;
}

// �����ַ���Ϣ
string filter_input(string msg, int t)
{
	if ( msg == "" )
		return TMP;
	if ( t == 9 ) {
		if (strlen(msg) >= 60) {
			write("���������Ϣ�������������60���ַ����ڡ�\n");
			write("���ı�ע��");
			return "ReEnter";
		}
	}
	else if (strlen(msg) >= 30) {
		write("���������Ϣ�������������30���ַ����ڡ�\n");
		write(line_info[t-1]);
		return "ReEnter";
	}
	switch (t) {
		case 6 :
			if (strsrch(msg, "@") < 2) {
				write("�����ʼ���ַ������ id@address �ĸ�ʽ��\n");
				write("���ĵ����ʼ���");
				return "ReEnter";
			}
		default :
			return msg;
	}
}

int get_my_info(string msg, string *sfile, int t)
{
	if ((msg = filter_input(msg, t)) == "ReEnter") {
	        input_to("get_my_info", sfile, t);
        	return 1;	
        }
        if (t == 9) {
                sfile[t] = line[t-1] + ":" + msg;
                write("\n������Ϣ¼����ϡ�\n");
                if (write_file(LINK_FILE,implode(sfile, ",") + "\n",1)) {
                	write("�洢��ϡ�\n");
                	return 1;
                }
                else {
                	write("�洢�����޷��洢��\n");
                	return 0;
                }
        }

        sfile[t] = line[t-1] + ":" + msg;
        write(line_info[t]);
        input_to("get_my_info", sfile, t+1);
        return 1;
}
	

int get_my_info_2(string msg, string *file, string *sfile, int tmp, int t)
{
	if ((msg = filter_input(msg, t)) == "ReEnter") {
	        input_to("get_my_info_2", file, sfile, tmp, t);
        	return 1;	
        }
        if (t == 9) {
                sfile[t] = line[t-1] + ":" + msg;
                write("\n������Ϣ¼����ϡ�\n");
//                write(sprintf("%O\n",sfile));
                if (write_file(LINK_FILE,implode(sfile, ",") + "\n")) {
                	write("�洢��ϡ�\n");
                	return 1;
                }
                else {
                	write("�洢�����޷��洢��\n");
                	return 0;
                }
        }

        sfile[t] = line[t-1] + ":" + msg;
        if (tmp == 1)
        	write("\n"+sfile[t+1]+"\n");
        write(line_info[t]);
        input_to("get_my_info_2", file, sfile, tmp, t+1);
        return 1;
}
		
	
// ��ʾ��ʦ��Ϣ
int introduce(object me, string name)
{
	string *file, *sfile, lev, msg = "\n";
	int j;

	lev = wizard_lev(name);	
	if ((file = analyse_file(LINK_FILE)) == ({}) ) {
		write(TITLE+"���������ϣ�\n");
		return 1;
	}
	if (lev == "Ply") {
		write(TITLE+"��"+name+"������ʦ��\n");
		return 1;
	}
	if (!wizard_sec(geteuid(me), lev)) {
		write(TITLE+"������Ŀǰ�ļ����޷��鿴"+name+"("+lev+")�����ϣ�\n");
		return 1;
	}
	if ((j = have_me(file, name)) == -1) {
		write(TITLE+"������"+name+"�����ϣ�����wizlinkָ��鿴��\n");
		return 1;
	}
	sfile = explode(file[j],",");
	msg += sprintf(HIC"�󩤩�"HIY"%|16s"HIC"��������������������������\n",capitalize(name)+"������Ϣ");
	msg += sprintf("��"WHT"  ��ʦ�ȼ���"HIG"%-30s"HIC"  ��\n",lev);
	msg += sprintf("��"WHT"  ��    ��"HIG"%-30s"HIC"  ��\n",sfile[1][4..strlen(sfile[1])]);
	msg += sprintf("��"WHT"  ��    �䣺"HIG"%-30s"HIC"  ��\n",sfile[2][4..strlen(sfile[2])]);
	msg += sprintf("��"WHT"  ��    ����"HIG"%-30s"HIC"  ��\n",sfile[3][6..strlen(sfile[3])]);
	msg += sprintf("��"WHT"  ��    ����"HIG"%-30s"HIC"  ��\n",sfile[4][3..strlen(sfile[4])]);
	msg += sprintf("��"WHT"  ��    ����"HIG"%-30s"HIC"  ��\n",sfile[5][7..strlen(sfile[5])]);
	msg += sprintf("��"WHT"  �����ʼ���"HIG"%-30s"HIC"  ��\n",sfile[6][6..strlen(sfile[6])]);
	msg += sprintf("��"WHT"  ��    ַ��"HIG"%-30s"HIC"  ��\n",sfile[7][9..strlen(sfile[7])]);
	msg += sprintf("��"WHT"  ������Ҷ��"HIG"%-30s"HIC"  ��\n",sfile[8][9..strlen(sfile[8])]);
	lev = sfile[9][7..strlen(sfile[9])];
	if (strlen(lev) > 30) {
		msg += sprintf("��"WHT"  ��    ע��"HIG"%-30s"HIC"  ��\n",lev[0..29]);
		msg += sprintf("��            "HIG"%-30s"HIC"  ��\n",lev[31..strlen(lev)]);
	}
	else
		msg += sprintf("��"WHT"  ��    ע��"HIG"%-30s"HIC"  ��\n",lev);
	msg += "�󩤩��������������������������������� SJ ������\n\n"NOR;
	tellme(me, msg);
	return 1;
}

// ��ʾ������
int main_page(object me)
{
	string *file, *sfile, msg = "\n", last_log;
	int i, j;

	if ((file = analyse_file(LINK_FILE)) == ({}) ) {
		write(TITLE+"�������κ����ϣ�\n");
		return 1;
	}
	j = sizeof(file);
	msg += HIC"\t\t\t��"+TITLE+HIC"��\n";
	msg += HIC"\t�󩤩�����������������������������������������\n";
	msg += sprintf("\t��"WHT"%|42s"HIC"��\n","Ŀǰ����"+chinese_number(j)+"λ��ʦ�ĸ�����Ϣ");
	msg += HIC"\t�󩤩�����������������������������������������\n";
	for (i=0;i<j;i++) {
		sfile = explode(file[i],",");
		if (i == j-1)
			last_log = sfile[0][3..strlen(sfile[0])];
		msg += sprintf("\t��"WHT"  %-2d��"HIG"%-8s %-10s %-10s ..."HIC"  ��\n", i+1, capitalize(sfile[0][3..strlen(sfile[0])]), sfile[1][0..9], sfile[2][0..9]);
	}
	msg += HIC"\t�󩤩�����������������������������������������\n";
	msg += sprintf("\t��"WHT"%|42s"HIC"��\n","���һλ��¼��Ϣ����"+capitalize(last_log));
	if ((file = analyse_file(WIZ_FILE)) != ({}) ) {
		j = 0;
		for (i=0;i<sizeof(file);i++) {
			if (strsrch(file[i],"to " + geteuid(me))>=0) {
				j += 1;
				continue;
			}
		}
		msg += sprintf("\t��"HIR"%|42s"HIC"��\n","����"+chinese_number(j)+"�ű���");
	}
	msg += HIC"\t�󩤩������������������������������� SJ ������\n";
	tellme(me, msg);
	return 1;
}
	
// ��ʾ�б���Ϣ
int list(object me, string pattern)
{
	string *file, *sfile, msg = "\n";
	int i, j, t;
	
	if ((file = analyse_file(LINK_FILE)) == ({}) ) {
		write(TITLE+"�������κ����ϣ�\n");
		return 1;
	}
	msg += sprintf(HIC"�󩤩�"HIY"%|16s"HIC"��������������������������\n",capitalize(pattern)+"���ҽ��");
	t = strlen(pattern) +1;
	for (i=0;i<sizeof(file);i++) {
		sfile = explode(file[i],",");
		for (j=0;j<sizeof(sfile);j++) {
			if (strsrch(sfile[j],pattern) >= 0) {
				if (wizard_sec(geteuid(me), wizard_lev(sfile[0][3..strlen(sfile[0])])))
					msg += sprintf("��"WHT"  %-8s��"HIG"%-30s"HIC"  ��\n", capitalize(sfile[0][3..strlen(sfile[0])]), sfile[j][t..strlen(sfile[j])]);
				break;
			}
		}
	}
	msg += "�󩤩��������������������������������� SJ ������\n\n"NOR;
	tellme(me, msg);
	return 1;
}	

// ֪ͨ��ʦ
int tell_other(object me, string id, string msg, int i)
{
	string *file, *sfile, lev, e_msg, output = "\n";
	int j, num = 0;
	
	if (i == 0) {
		if ((file = analyse_file(WIZ_FILE)) == ({}) ) {
			write(TITLE+"��û����ı�����\n");
			return 1;
		}
		if ((j = have_me(file, "to " + geteuid(me))) == -1) {
			write(TITLE+"��û����ı�����\n");
			return 1;
		}
		output += sprintf(HIC"�󩤩�"HIY"%|16s"HIC"������������������������������������������\n",capitalize(geteuid(me))+"���˱���");

		for (i=0;i<sizeof(file);i++) {
			if (strsrch(file[i], "to " + geteuid(me))>=0) {
				e_msg = file[j];
				sfile = explode(e_msg,"��");
				output += sprintf("��"WHT"  1. ���ԣ�%-8s   ���ڣ�%-30s"HIC"  ��\n", sfile[1][5..strlen(sfile[1])], sfile[2][3..strlen(sfile[2])]);
				if (strlen(sfile[3]) > 54) {
					output += sprintf("��"HIG"     %-54s"HIC" ��\n",sfile[3][0..53]);
					output += sprintf("��"HIG"     %-54s"HIC" ��\n",sfile[3][54..strlen(sfile[3])]);
				}
				else
					output += sprintf("��"HIG"     %-54s"HIC" ��\n",sfile[3]);
				output += "�󩤩�����������������������������������������������������������\n";
				num += 1;
				continue;
			}
		}
		output += sprintf("��"WHT"%|60s"HIC"��\n", "�����ڹ���"+chinese_number(num)+"�ű���");
		output += "�󩤩������������������������������������������������� SJ ������\n\n"NOR;
		tellme(me, output);
		return 1;
	}
	if (i == 2) {
		if ((file = analyse_file(WIZ_FILE)) == ({}) ) {
			write(TITLE+"��û���κα�����\n");
			return 1;
		}
		if ((j = have_me(file, "from " + geteuid(me))) == -1) {
			write(TITLE+"��û�������ı�����\n");
			return 1;
		}
		sfile = explode(file[j],"��");
     		if (j != 0)
       			file = file[0..j-1] + file[j+1..sizeof(file)];
       		else
       			file = file[1..sizeof(file)];
     		if (write_file(WIZ_FILE, implode(file,"\n")+"\n", 1)) {
       	        	write("������"+capitalize(sfile[0][3..strlen(sfile[0])])+"�ı����Ѿ�ɾ����\n");
               		return 1;
                }
       	        else {
               		write("������"+capitalize(sfile[0][3..strlen(sfile[0])])+"�ı����޷�ɾ����\n");
               		return 0;
                }
	}
		
	lev = wizard_lev(id);	

	if (lev == "Ply") {
		write(TITLE+"��"+id+"������ʦ��\n");
		return 1;
	}
	if ((file = analyse_file(WIZ_FILE)) == ({}) ) {
                if (write_file(WIZ_FILE,msg)) {
                	write("�洢��ϡ�\n");
                	return 1;
                }
                else {
                	write("�洢�����޷��洢��\n");
                	return 0;
                }
        }
	else {
		if ((j = have_me(file, "from " + geteuid(me))) == -1) {
	                if (write_file(WIZ_FILE,msg)) {
        	        	write("�洢��ϡ�\n");
                		return 1;
	                }
        	        else {
                		write("�洢�����޷��洢��\n");
                		return 0;
	                }
		}
		else {
       			if (j != 0)
       				file = file[0..j-1] + file[j+1..sizeof(file)];
       			else
       				file = file[1..sizeof(file)];
       			write_file(WIZ_FILE,implode(file,"\n"),1);
	                if (write_file(WIZ_FILE,msg)) {
        	        	write("�洢��ϡ�\n");
                		return 1;
	                }
        	        else {
                		write("�洢�����޷��洢��\n");
                		return 0;
	                }
		}
	}
}
	

int main(object me, string arg)
{
	string id, arg1;

	seteuid(geteuid(me));
	if ( !arg ) {
		main_page(me);
		return 1;
	}
	if ( sscanf(arg, "-%s", arg1) == 1 ) {
		if (arg1 == "phone"
		 || arg1 == "bp"
		 || arg1 == "mobile"
		 || arg1 == "email"
		 || arg1 == "location"
		 || arg1 == "homepage") {
			list(me, arg1);
			return 1;
		}
		else
			return notify_fail(HELP_WIZLINK);
	}
	if (arg == "note") {
		tell_other(me, id, arg1, 0);
		return 1;
	}
	if (arg == "del note") {
		tell_other(me, id, arg1, 2);
		return 1;
	}
	if (sscanf(arg, "%s %s", id, arg1) == 2) {
		if (strlen(arg1) >= 100)
			return notify_fail("�������ı���̫����\n");
		arg1 = "to "+id+"��from "+geteuid(me)+"��"+ctime(time())+"��"+arg1+"\n";
		tell_other(me, id, arg1, 1);
		return 1;
	}
	if (arg == "me") {
		correct_me(me);
		return 1;
	}
	introduce(me, arg);
	return 1;
}

int help()
{
	write(HELP_WIZLINK);
	return 1;
}