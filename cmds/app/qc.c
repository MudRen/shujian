// qc.c
// qc.c QC�������
// Create by Looklove 2000.3.6
// Modified by Numa 2001.3.14
// Modified by snowman@SJ 17/03/2001
// Last Modified by Numa@SJ 2001.7.30 �����˲����ж�

#include <ansi.h>

#define QC_FILE  "/data/qc"
#define TEST_DIR "/root/test"
#define SJ_DIR   "/root/shujian"
#define TOP_LINE "�������Щ������������������������������������������Щ��������Щ������������������������Щ����Щ�����������\n"\
                 "��"HIR"���"HIC"��"HIY"                ��         ��             "HIC"��"HIY"�� �� ��"HIC"��"HIY"         ˵    ��       "HIC"��"HIY"״̬"HIC"��"HIY"  ʱ  ��  "HIC"��\n"\
                 "�������੤�����������������������������������������੤�������੤�����������������������੤���੤����������\n"
        
#define END_LINE "�������ة������������������������������������������ة��������ة������������������������ة����ة�����������\n"NOR

inherit F_CLEAN_UP;
inherit F_SAVE;

mapping *notes;
nosave string *qcer = ({"numa", "cocktail", "olives", "snowman"});
nosave string qc_listing = "";
nosave int modify = 0;
// ɾ�����ص�qc���뱣������
nosave int day = 15;

int help(object me);

void create()
{
        seteuid(getuid());
        restore();
}

string query_save_file()
{
        return QC_FILE;
}

string write_list(int i)
{
        string output = "";
        
        if (notes[i]["overrule"]!="") {
                if (strlen(notes[i]["overrule"]) > 20) {
                        output += sprintf("��"NOR"%|4d"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"HIR"��"HIY"��"NOR"%-20s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                i+1, notes[i]["filename"], notes[i]["poorman"], notes[i]["overrule"][0..19], (notes[i]["state"] == "����")?(HIR+notes[i]["state"]):(notes[i]["state"]), ctime(notes[i]["time"])[0..9]);
                        output += sprintf("��"NOR"%|4s"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"NOR"%-24s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                "","","",notes[i]["overrule"][20..43],"","");
                }
                else
                        output += sprintf("��"NOR"%|4d"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"HIR"��"HIY"��"NOR"%-20s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                        i+1, notes[i]["filename"], notes[i]["poorman"], notes[i]["overrule"], (notes[i]["state"] == "����")?(HIR+notes[i]["state"]):(notes[i]["state"]), ctime(notes[i]["time"])[0..9]);
        }
        else {
                if (strlen(notes[i]["reason"]) > 24) {
                        output += sprintf("��"NOR"%|4d"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"NOR"%-24s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                i+1,notes[i]["filename"],notes[i]["poorman"],notes[i]["reason"][0..23],notes[i]["state"],ctime(notes[i]["time"])[0..9]);
                        output += sprintf("��"NOR"%|4s"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"NOR"%-24s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                "","","",notes[i]["reason"][24..47],"","");
                }
                else
                        output += sprintf("��"NOR"%|4d"HIC"��"NOR"%-42s"HIC"��"HIG"%-8s"HIC"��"NOR"%-24s"HIC"��"NOR"%-4s"HIC"��"WHT"%-10s"HIC"��\n",
                                i+1,notes[i]["filename"],notes[i]["poorman"],notes[i]["reason"],notes[i]["state"],ctime(notes[i]["time"])[0..9]);
        }
        return output;
}       

int qcdetail(int i)
{
        int n;
        string msg, tmp;

        if( !(n = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
        if( i < 1 || i > n ) return notify_fail("û�д˱�š�\n");
        msg = sprintf("QC�б��� %d ��ϸ��Ϣ���£�\n", i);
        i -= 1;
        msg += sprintf("%16s : %s\n", "������", notes[i]["poorman"]);
        msg += sprintf("%16s : %s\n", "�ļ�����", notes[i]["filename"]);
        msg += sprintf("%16s : %s\n", "��������", notes[i]["reason"]);
        msg += sprintf("%16s : %s\n", "����ԭ��", notes[i]["overrule"]);
        tmp = notes[i]["state"];
        msg += sprintf("%16s : %s, �ȴ� %s QC\n", "Ŀǰ״̬", tmp, capitalize(qcer[atoi(tmp)]));
        msg += sprintf("%16s : %s\n", "����ʱ��", ctime(notes[i]["time"])[0..9]);
        write(msg);
        return 1;
}

int is_qcer(object me)
{
        string id = geteuid(me);
        int i;

        if (id == "yuj") return 3;
        for (i=0;i<sizeof(qcer);i++)
                if (id == qcer[i])
                        return i;
        return -1;
}

int file_in_qcing(string fn)
{
        int i, j;
        
        j = sizeof(notes);
        if (j > 0) {
                for (i=0;i<j;i++)
                        if (notes[i]["filename"] == fn)
                                return 1;
        }
        return 0;
}

int list_qc(object me)
{
        int i;
        string str;
        
        i = sizeof(notes);
        if ( i < 1 )
                return notify_fail("û�˷��� QC Ҫ��\n");
        
        if( modify == 0 ){
                str = HIG" �Ѿ������ QC �����б�����:\n"HIC;
                str += TOP_LINE;
                for (i = 0; i < sizeof(notes); i++) {
                        str += write_list(i);
                }
                str += END_LINE;
                qc_listing = str;
                modify = 1;
        }
        else str = qc_listing;
        me->start_more(str);
        return 1;
}

int find_id(object me, string id)
{
        int i;

        i = sizeof(notes);
        if ( i<1 )
                return notify_fail("û�˷��� QC Ҫ��\n");

        write(sprintf(HIG"���ҵ���"HIY" %s "HIG"����� QC �����б�����:\n"HIC,id));
        write(TOP_LINE);
        for (i = 0; i < sizeof(notes); i++)
                if ((notes[i]["poorman"])==id)
                        write(write_list(i));
        write(END_LINE);
        return 1;
}

void check_qc_list(object me)
{
        int i, t, j = 0;
        string str, sta = "";
        
        i = sizeof(notes);
        if ( i < 1 )
                return;
        t = is_qcer(me);
        if (t>0) sta = sprintf("%d",t);
        str = HIG"������Ҫ�� QC �����б����£�\n"HIC;
        str += TOP_LINE;
        for (i = 0; i < sizeof(notes); i++){
                if ((notes[i]["state"]) == sta ){
                        str += write_list(i);
                        j++;
                }
        }
        if( j <= 0 ) return;
        me->start_more(str + END_LINE);
}

int cp_mirror(int n)
{
        string src, *file;
        int i , j = 1;
        
        src = notes[n]["filename"];
        if (file_size(src) == -2 && src[<1] != '/') src += "/";
        if (src[<1] == '/') {
                file = get_dir(src, 0);
                i = sizeof(file);
                if (!i) return notify_fail("û�� "+src+" ���Ŀ¼���޷�����.\n");
                // log mirror
                for (; j<=i; j++)
                        log_file("mirror", sprintf("cp %s%s %s%s\n", TEST_DIR, src+file[j-1], SJ_DIR, src+file[j-1]) );
        }
        else log_file("mirror", sprintf("cp %s%s %s%s\n", TEST_DIR, src, SJ_DIR, src) );
        write("\n"+ src +" "+ j +" ���ļ� QC �ɹ���\n");
        return 1;
}

int ana_state(string id, int i)
{
        int j;
        
        if (id == "yuj") {
                notes[i-1]["state"] = "4";
                return 1;
        }
        for (j=0;j<sizeof(qcer);j++)
                if (id == qcer[j]) {
                        if (notes[i-1]["state"] == "" && !j) {
                                notes[i-1]["state"] = "1";
                                return 1;
                        }
                        if (notes[i-1]["state"] == sprintf("%d", j)) {
                                notes[i-1]["state"] = sprintf("%d", j+1);
                                return 1;
                        }
                }
        return 0;
}

int ana_antistate(int step, int i)
{
        notes[i-1]["state"] = sprintf("%d", step+1);
        notes[i-1]["overrule"] = "";
        modify = 0;
        if ( notes[i-1]["state"] == "4" )
                if (!cp_mirror(i-1))
                        return notify_fail("�����ļ��������顣\n");
        write("�� QC �������̣��㸺��Ĳ����Ѿ����Ϊ QC ��ϡ�\n");
        save();
        return 1;
}

int do_state(object me, int i)
{
        string id, *reason;

        id = geteuid(me);
        if( i > sizeof(notes) || i < 1)
                return notify_fail("û��������!\n");

        if (notes[i-1]["state"]== "����") {
                reason = explode(notes[i-1]["overrule"],">");
                if (reason[0] != capitalize(id))
                        return notify_fail(notes[i-1]["filename"]+"�Ѿ��� "HIG+ reason[0] +NOR" �����ˡ�\n");
                else
                        return ana_antistate(is_qcer(me), i);
        }

        if ( notes[i-1]["state"]== "4" )
                return notify_fail(notes[i-1]["state"]+"�Ѿ� QC �����!\n");

        if (ana_state(id, i) == 0)
                return notify_fail("�� QC ���������Ѿ����е� �� "HIG+ notes[i-1]["state"] +NOR" ������"HIY+capitalize(qcer[atoi(notes[i-1]["state"])])+NOR" ����QC��\n");
        modify = 0;
        if ( notes[i-1]["state"]== "4" )
                if (!cp_mirror(i-1))
                        return notify_fail("�����ļ��������顣\n");
        save();
        write("�� QC �������̣��㸺��Ĳ����Ѿ����Ϊ QC ��ϡ�\n");
        return 1;
}

int isdest(int i)
{
        int t = time() - 86400 * day;

        if (notes[i]["state"] == "4") return 1;
        if (notes[i]["state"] == "����"
         && t > notes[i]["time"])
                return 1;
        return 0;
}

void do_dest_note(int n)
{
        int i;

        if( !(i = sizeof(notes)) ) 
                return;
        if (n >= 0) {
                modify = 0;
                if( sizeof(notes) == 1 ) notes = ({});
                else if (n==0) notes = notes[1..<1];
                else if ((i-1)==n) notes = notes[0..<2];
                else notes = notes[0..n-1] + notes[n+1..<1];
                save();
                return;
        }
        while (i--) {
                if (isdest(i)) {
                        modify = 0;
                        write(notes[i]["poorman"]+"�� QC �����ѱ�ɾ����\n");
                        if (sizeof(notes) == 1) notes = ({});
                        else if (i==0) notes = notes[1..<1];
                        else if (i == sizeof(notes)-1) notes = notes[0..<2];
                        else notes = notes[0..i-1] + notes[i+1..<1];
                }
        }
        save();
}

int print_qcer()
{
        int i, n;
        
        n = sizeof(qcer);
        write(sprintf("���ڵ� QC С�����¹��� %d ����Ա��\n",n));
        for (i=0;i<n;i++)
                write(sprintf("    %-2d  %-10s ", i, qcer[i]));
        write("\n");
        return 1;
}

int main(object me, string arg)
{
        mapping note;
        string arg1, reason, filename, dir, *opt;
        int i, arg2;
        mixed *file;
        int opt_detail, opt_post, opt_qcer, opt_find, opt_correct, opt_delete, opt_dest,
               opt_listqc, opt_reject, opt_moreqc;

        restore();
        if (arg) {
                opt = explode(arg, " ");
                i = sizeof(opt);
                while( i-- ) {
                        switch(opt[i]) {
                                // wiz cmds
				case "-l": opt_detail = 1; break;
                                case "-b": opt_post = 1; break;
                                case "-u": opt_qcer = 1; break;
                                case "-f": opt_find = 1; break;
                                case "-c": opt_correct = 1; break;
                                case "-d": opt_delete = 1; break;
                                case "-p": opt_dest = 1; break;
                                // qcer cmds
                                case "-q": opt_listqc = 1; break;
                                case "-k": opt_reject = 1; break;
                                case "-m": opt_moreqc = 1; break;
                        }
                }
                if (!opt_reject && sscanf(arg, "%d", arg2) == 1 ) {
                        if (is_qcer(me)<0) return notify_fail(" �Բ����㲻�� QC С���Ա��\n");
                        if ( arg2<1 || arg2 > sizeof(notes) ) return notify_fail("û�д˱�š� \n");
                        if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
                        return do_state( me, arg2 );
                }

        }

	if (opt_detail)
		if (sscanf(arg, "-l %d", arg2) == 1)
			return qcdetail(arg2);

        if (opt_post) {
        if (sscanf(arg, "%s -b %s", filename, reason) == 2) {
                tell_object(me, HIY "�������һ��" HIY MUD_NAME HIY "CODE�����˸���������ʼ�� QC С�����뷢�����롭��\n" NOR);

                dir = resolve_path(me->query("cwd"), filename);
                if( file_size(dir)==-2 && dir[<1] != '/' ) dir += "/";
                file = get_dir(dir, -1);

                if( !sizeof(file) ) {
                        if (file_size(dir) == -2) return notify_fail("�����¼���ļ�·����\n");
                        else return notify_fail("û�����Ŀ¼�����ļ��������¼�顣\n");
                }

                if (strlen(reason) > 48) return notify_fail("�ļ�˵��̫�����뾡�����Ծ�����\n");
                if (strlen(reason) < 6) return notify_fail("�ļ�˵��̫�̣��벻Ҫ���־�����\n");
                
                note = allocate_mapping(6);
                note["poorman"] = capitalize(geteuid(me));
                note["filename"] = filename;
                note["reason"] = reason;
                note["overrule"] = "";
                note["state"] = "";
                note["time"] = time();

                if(!sizeof(notes))
                        notes = ({ note });
                else    notes += ({ note });
                
                save();
                modify = 0;
                tell_object(me, HIC "������ϡ������Ϣ�Ѿ����ӵ�֪ͨ�����\n");
                message("channel:wiz", HIY "��QC���롿����ʦ "HIG+note["poorman"]+HIY" ����QCС�������� CODE ���� QC ����������ʦʹ�� qc ����鿴��\n" NOR,users());
                return 1;
        }
                return help(me);
        }

        if (opt_qcer)
                return print_qcer();

        if (opt_find
         && sscanf(arg, "-f %s", arg1) == 1 )
                return find_id(me, capitalize(arg1));

        if (opt_correct) {
        if (sscanf(arg, "-c %d %s %s", arg2, filename, reason) == 3) {
                if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
                if( arg2 < 1 || arg2 > i ) return notify_fail("û�д˱�š� \n");
                note = notes[arg2-1];
                if (note["poorman"] != capitalize(geteuid(me)))
                        return notify_fail("�Բ����ⲻ������ QC ���롣\n");
                if (note["state"] != "")
                        return notify_fail("�Բ������� QC �����Ѿ����� QC ���У��޷����ġ�\n");

                dir = resolve_path(me->query("cwd"), filename);
                if( file_size(dir)==-2 && dir[<1] != '/' ) dir += "/";
                file = get_dir(dir, -1);

                if( !sizeof(file) ) {
                        if (file_size(dir) == -2) return notify_fail("�����¼���ļ�·����\n");
                        else return notify_fail("û�����Ŀ¼�����ļ��������¼�顣\n");
                }

                if (strlen(reason) > 48) return notify_fail("�ļ�˵��̫�����뾡�����Ծ�����\n");
                if (strlen(reason) < 6) return notify_fail("�ļ�˵��̫�̣��벻Ҫ���־�����\n");

                note["filename"] = filename;
                note["reason"] = reason;
                note["time"] = time();
                notes[arg2-1] = note;
                save();
                modify = 0;
                write(HIG "���� QC �����޸���ϡ�\n");
                return 1;
        }
                return help(me);
        }
        if (opt_delete) {
        if (sscanf(arg, "-d %d", arg2) == 1) {
                if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
                if( arg2 < 1 || arg2 > i ) return notify_fail("û�д˱�š� \n");
                if (notes[arg2-1]["poorman"] != capitalize(geteuid(me)))
                        return notify_fail("�Բ����ⲻ������ QC ���롣\n");
/*
                if (notes[arg2-1]["state"] != ""
                 && notes[arg2-1]["state"] != "����"
                 && notes[arg2-1]["state"] != HIR"����"NOR)
                        return notify_fail("�Բ������� QC �����Ѿ����� QC ���У��޷�ɾ����\n");
*/

                do_dest_note(arg2-1);
                write("���ĵ� "+ arg2 +"�� QC ����ɾ����ϡ�\n");
                return 1;
        }
                return help(me);
        }
        if (opt_dest) {
                if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
                do_dest_note(-1);
                write("QC �б�������ϡ�\n");
                return 1;
        }

        if (opt_listqc) {
                if (is_qcer(me)<0) return notify_fail(" �Բ����㲻�� QC С���Ա��\n");         
                check_qc_list(me);
                return 1;
        }
        if (opt_reject) {
        if (sscanf(arg, "%d -k %s", arg2, arg1) == 2 ) {
                if (is_qcer(me)<0) return notify_fail(" �Բ����㲻�� QC С���Ա��\n");
                if( !(i = sizeof(notes)) ) return notify_fail("û�˷���QC���롣\n");
                if( arg2 < 1 || arg2 > i ) return notify_fail("û�д˱�š� \n");
                if (strlen(arg1) > 44) return notify_fail("��������̫���£����������Ծ����ĺ�ϰ�ߡ�\n");
                if (strlen(arg1) < 6) return notify_fail("��������̫�򵥣�ϣ���㲻����Ϊ���ɲ���֡�\n");
                if ( notes[arg2-1]["overrule"]!= "" ) {
                        write(notes[arg2-1]["filename"]+"�Ѿ���������!\n");
                        return 1;
                }
                notes[arg2-1]["overrule"] = ""+ capitalize(geteuid(me))+">"+ arg1;
                notes[arg2-1]["state"] = "����";
                write(sprintf("���ԡ�%s�������ɲ�����%s��QC���롣\n",arg1,notes[arg2-1]["poorman"]));
                save();
                modify = 0;
                return 1;
        }
                return help(me);
        }
        if (opt_moreqc) {
        if (sscanf(arg, "-m %d", arg2) == 1) {
                if (is_qcer(me)<0) return notify_fail(" �Բ����㲻�� QC С���Ա��\n");
                if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� QC ���롣\n");
                if( arg2 < 1 || arg2 > i ) return notify_fail("û�д˱�š� \n");
                write(HIY"�ļ���"+notes[arg2-1]["filename"]+"\n\n"NOR);
                if (file_size(notes[arg2-1]["filename"]) != -2) me->start_more(read_file(notes[arg2-1]["filename"]));
                else write("��ΪĿ¼�������в鿴��\n");
                return 1;
        }
                return help(me);
        }

        return list_qc(me);
}

int help(object me)
{
write(@HELP
ָ���ʽ :

qc                      ��ʾ QC �ļ��б�
qc -l <���>            ��ʾ QC �ļ���ϸ������Ϣ��
qc <�ļ�> -b <ԭ��>     ���� QC ���롣
qc -c <�ļ�> <ԭ��>     �޸��Լ��Ѿ������� QC ���롣
qc -d <���>            ɾ���Լ��Ѿ������� QC ���롣
qc <���> -k <ԭ��>     �Դ˱�ŵ����뷢�� QC ������Ϣ��
qc -f <id>              ���Ҵ���ʦ�����ѷ��� QC ���롣
qc -p                   ɾ���Ѿ�ͨ���� QC
qc <���>               ͨ���˱�ŵ� QC ��
qc -q                   �鿴�Լ���Ҫ QC ����Ŀ��
qc -m <���>            �鿴��Ҫ QC ���ļ���
qc -u                   �鿴 QC С��������

������ʦ��CODE����Ժ󣬷���QC�����ָ�
        qc <filename> -b <reason> ����QC���롣
        qc -c <�ļ�> <ԭ��> �޸��Լ��Ѿ������� QC ���롣
        qc -d <���> ɾ���Լ��Ѿ������� QC ���롣
	qc -l <���> ��ʾ QC �ļ���ϸ������Ϣ��
        qc -f <id> ��ѯĳһwiz�����QC���롣

ע�⣺ �㷢������ʱ��filename������·��(������Ŀ¼)���ļ���
       ���ڻ�ȡȨ�����в�����Ϻ������ύ QC ���롣

QCС�������ָ�������QC���ȣ�
        qc <���> �����̱��QC״̬��

        qc <���> -k <����ԭ��>
        ����һ��QC���󣬲���˵������ԭ��

        qc -q                   �鿴�Լ���Ҫ QC ����Ŀ��
        qc -m <���>             �鿴��Ҫ QC ���ļ���
        qc -p
        QC�������ļ�������һ��QC�ļ����±��ʱ������ɾ�������Ѿ���׼�����롣
HELP
    );
    return 1;
}

